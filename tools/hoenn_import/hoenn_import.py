#!/usr/bin/env python3
"""Import a Hoenn map from a local pret/pokeemerald clone into RFVF+ (pokefirered engine).

Usage (Git Bash, from the repo root):
    uv run --no-project --with pillow python tools/hoenn_import/hoenn_import.py LilycoveCity
    uv run --no-project --with pillow python tools/hoenn_import/hoenn_import.py LilycoveCity \
        --emerald ../pokeemerald --group gMapGroup_TownsAndRoutes --render /tmp/lilycove.png

What it writes (re-running is safe: entries are replaced, never duplicated):
  - both tilesets of the map: Emerald gTileset_X -> gTileset_HoennX in data/tilesets/<kind>/hoenn_x/
    (tiles.png, palettes/*.pal, metatiles.bin, metatile_attributes.bin; anim/ is left alone)
  - data/layouts/<Map>/{map.bin,border.bin} and its data/layouts/layouts.json entry
  - data/maps/<Map>/map.json: NPCs without script (story objects = objects with a flag are dropped),
    every warp sends back onto itself, no connections / signs / triggers
  - data/maps/<Map>/scripts.inc (only if missing), data/event_scripts.s, data/maps/map_groups.json,
    src/data/tilesets/{headers,graphics,metatiles}.h, tileset_rules.mk, include/constants/metatile_labels.h
Nothing is written before the whole import is validated, and a map / layout of this repo that this tool did not
make is never replaced (Emerald and Kanto share names: SafariZone_North, LAYOUT_POKEMON_CENTER_1F...).
Not handled here: tileset animations (src/tileset_anims.c: the secondary gets .callback = NULL, an animated Emerald
secondary needs a hand port using the renumbered tiles / palette below) and door graphics (src/field_door.c:
sDoorGraphics_Hoenn, only read on maps whose primary is gTileset_HoennGeneral).

Engine differences handled:
  - FRLG primary = 640 tiles / 640 metatiles / 7 palettes (Emerald: 512 / 512 / 6). Emerald secondary
    metatile ids are shifted by +128; secondary tiles are compacted to the ones used and re-based at 640.
    An Emerald secondary using palette slot 6 (a primary slot in FRLG) gets it moved to a free slot 10-12.
  - metatile_attributes u16 -> u32: behaviors are mapped by NAME (the values differ between the engines),
    and FRLG's terrain (surf, Cut) and encounter type, which FRLG reads from the attributes, are filled in.
At the end the map is rendered from the Emerald files (Emerald rules) and from the converted files
(FRLG rules): both must match pixel for pixel.
"""
import argparse
import json
import math
import re
import shutil
import struct
from collections import Counter
from pathlib import Path

from PIL import Image

REPO = Path(__file__).resolve().parents[2]
EM = {"tiles": 512, "metatiles": 512, "pals": 6}  # pokeemerald include/fieldmap.h
FR = {"tiles": 640, "metatiles": 640, "pals": 7}  # this repo's include/fieldmap.h
TOTAL = 1024
TERRAIN_NORMAL, TERRAIN_GRASS, TERRAIN_WATER, TERRAIN_WATERFALL = 0, 1, 2, 3
ENC_NONE, ENC_LAND, ENC_WATER = 0, 1, 2

# Emerald behavior name -> FRLG behavior name, where the name differs or the meaning has to change.
# Any other behavior keeps its name, or becomes MB_NORMAL (printed in the report) when FRLG lacks it.
BEHAVIOR_OVERRIDES = {
    "MB_ANIMATED_DOOR": "MB_WARP_DOOR",
    "MB_NON_ANIMATED_DOOR": "MB_CAVE_DOOR",
    "MB_INTERIOR_DEEP_WATER": "MB_DEEP_WATER",
    # A surfing player does trigger a MB_CAVE_DOOR warp, but FRLG then lands him ON FOOT on elevation-1
    # water (MB_CAVE_DOOR is not surfable: overworld.c GetAdjustedInitialTransitionFlags) = soft-lock.
    # So the water door is plain sea until the engine gets a real water door.
    "MB_WATER_DOOR": "MB_OCEAN_WATER",
}

# Emerald OBJ_EVENT_GFX -> closest existing gfx of this repo (sprites compared side by side).
NPC_GFX = {
    "OBJ_EVENT_GFX_SAILOR": "OBJ_EVENT_GFX_SAILOR",
    "OBJ_EVENT_GFX_GIRL_1": "OBJ_EVENT_GFX_LASS",
    "OBJ_EVENT_GFX_MAN_1": "OBJ_EVENT_GFX_BALDING_MAN",
    "OBJ_EVENT_GFX_RICH_BOY": "OBJ_EVENT_GFX_BOY",
    "OBJ_EVENT_GFX_MAN_2": "OBJ_EVENT_GFX_MAN",
    "OBJ_EVENT_GFX_WOMAN_2": "OBJ_EVENT_GFX_WOMAN_2",
    "OBJ_EVENT_GFX_EXPERT_M": "OBJ_EVENT_GFX_OLD_MAN_1",
    "OBJ_EVENT_GFX_EXPERT_F": "OBJ_EVENT_GFX_OLD_WOMAN",
    "OBJ_EVENT_GFX_GENTLEMAN": "OBJ_EVENT_GFX_GENTLEMAN",
    "OBJ_EVENT_GFX_SCHOOL_KID_M": "OBJ_EVENT_GFX_GBA_KID",
    "OBJ_EVENT_GFX_WOMAN_3": "OBJ_EVENT_GFX_WOMAN_3",
    "OBJ_EVENT_GFX_FAT_MAN": "OBJ_EVENT_GFX_FAT_MAN",
}
FALLBACK_MUSIC = "MUS_VERMILLION"


def read(path):
    with open(path, encoding="utf-8", newline="") as f:
        return f.read()


def write(path, text):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8", newline="") as f:
        f.write(text)


def read_ints(path, fmt):
    data = Path(path).read_bytes()
    return list(struct.unpack("<%d%s" % (len(data) // struct.calcsize(fmt), fmt), data))


def write_ints(path, fmt, values):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(struct.pack("<%d%s" % (len(values), fmt), *values))


def table(src, start):
    """Body of the C initializer that follows `start` in `src`."""
    body = src[src.index(start):]
    return body[:body.index("};")]


# ---------------------------------------------------------------- behaviors / attributes

class Behaviors:
    def __init__(self, em):
        enum = table(read(em / "include/constants/metatile_behaviors.h"), "enum {")
        assert "=" not in enum, "Emerald behavior enum now has explicit values, update the parser"
        self.em_names = re.findall(r"^\s*(MB_\w+),", enum, re.M)  # index = value
        bits = re.findall(r"\[(MB_\w+)\]\s*=\s*([^\n]+)", table(read(em / "src/metatile_behavior.c"), "sTileBitAttributes"))
        self.em_encounter = {n for n, v in bits if "TILE_FLAG_HAS_ENCOUNTERS" in v}
        self.em_surfable = {n for n, v in bits if "TILE_FLAG_SURFABLE" in v}
        self.fr_values = {n: int(v, 16) for n, v in re.findall(r"#define (MB_\w+) (0x[0-9A-Fa-f]+)",
                                                             read(REPO / "include/constants/metatile_behaviors.h"))}
        self.fr_surfable = set(re.findall(r"\[(MB_\w+)\]\s*=\s*TRUE",
                                          table(read(REPO / "src/metatile_behavior.c"), "sBehaviorSurfable")))
        self.used = Counter()  # (emerald name, frlg name) -> metatile count

    def convert(self, em_attr):
        """Emerald u16 attribute -> FRLG u32 attribute (see sMetatileAttrMasks in src/fieldmap.c)."""
        assert not em_attr & 0x0F00, "unknown Emerald attribute bits"
        em_name = self.em_names[em_attr & 0xFF]
        fr_name = BEHAVIOR_OVERRIDES.get(em_name, em_name if em_name in self.fr_values else "MB_NORMAL")
        self.used[em_name, fr_name] += 1
        surfable = fr_name in self.fr_surfable
        assert surfable or em_name not in self.em_surfable, \
            "%s is surfable in Emerald, %s is not here: map it in BEHAVIOR_OVERRIDES" % (em_name, fr_name)
        if fr_name == "MB_WATERFALL":
            terrain = TERRAIN_WATERFALL
        elif surfable:
            terrain = TERRAIN_WATER
        elif fr_name in ("MB_TALL_GRASS", "MB_LONG_GRASS"):
            terrain = TERRAIN_GRASS
        else:
            terrain = TERRAIN_NORMAL
        encounter = ENC_WATER if surfable else ENC_LAND if em_name in self.em_encounter else ENC_NONE
        layer = em_attr >> 12  # NORMAL/COVERED/SPLIT: same values and DrawMetatile logic in both engines
        assert layer <= 2
        return self.fr_values[fr_name] | terrain << 9 | encounter << 24 | layer << 29


# ---------------------------------------------------------------- tilesets

class Tileset:
    def __init__(self, em, em_symbol, behaviors):
        """Reads, checks and converts the Emerald tileset; write() is the only part that touches the repo."""
        self.em_name = em_symbol.replace("gTileset_", "")
        m = re.search(r'gMetatiles_%s\[\]\s*=\s*INCBIN_U16\("(data/tilesets/(primary|secondary)/(\w+))/metatiles\.bin"\)'
                      % self.em_name, read(em / "src/data/tilesets/metatiles.h"))
        assert m, "%s not found in pokeemerald src/data/tilesets/metatiles.h" % em_symbol
        self.src = em / m.group(1)
        self.kind = m.group(2)
        self.secondary = self.kind == "secondary"
        self.name = "Hoenn" + self.em_name
        self.dir = "data/tilesets/%s/hoenn_%s" % (self.kind, m.group(3))
        other = "primary" if self.secondary else "secondary"
        assert not (REPO / self.dir.replace(self.kind, other, 1)).exists(), \
            "%s already exists as a %s tileset of this repo: pick another target name" % (self.dir, other)
        self.em_meta = read_ints(self.src / "metatiles.bin", "H")
        self.em_attrs = read_ints(self.src / "metatile_attributes.bin", "H")
        assert len(self.em_meta) == 8 * len(self.em_attrs)
        self.attrs = [behaviors.convert(a) for a in self.em_attrs]
        self.png = png = Image.open(self.src / "tiles.png")
        assert png.mode == "P" and png.width % 8 == 0 and png.height % 8 == 0
        png_tiles = png.width // 8 * (png.height // 8)
        self.pal_map = {}
        if not self.secondary:
            assert len(self.em_attrs) <= EM["metatiles"]
            assert all((e & 0x3FF) < EM["tiles"] and e >> 12 < EM["pals"] for e in self.em_meta), \
                "Emerald primary references secondary tiles or palettes"
            self.num_tiles = png_tiles
            self.meta = self.em_meta
        else:
            assert len(self.em_attrs) <= TOTAL - FR["metatiles"], "too many metatiles for a FRLG secondary"
            self.used = sorted({(e & 0x3FF) - EM["tiles"] for e in self.em_meta if (e & 0x3FF) >= EM["tiles"]})
            assert self.used[-1] < png_tiles and len(self.used) <= TOTAL - FR["tiles"], "too many tiles for a FRLG secondary"
            tile_map = {EM["tiles"] + t: FR["tiles"] + i for i, t in enumerate(self.used)}
            pals = {e >> 12 for e in self.em_meta}
            assert max(pals) <= 12
            if 6 in pals:  # Emerald secondary slot 6 is loaded from the primary in FRLG
                free = [s for s in (10, 11, 12) if s not in pals]
                assert free, "secondary uses palette 6 and slots 10-12: no free FRLG slot"
                self.pal_map[6] = free[0]
            self.meta = [tile_map.get(e & 0x3FF, e & 0x3FF) | e & 0x0C00 | self.pal_map.get(e >> 12, e >> 12) << 12
                         for e in self.em_meta]
            self.num_tiles = len(self.used)

    def write(self):
        dst = REPO / self.dir
        (dst / "palettes").mkdir(parents=True, exist_ok=True)
        for i in range(16):
            shutil.copyfile(self.src / ("palettes/%02d.pal" % i), dst / ("palettes/%02d.pal" % i))
        for old, new in self.pal_map.items():
            shutil.copyfile(self.src / ("palettes/%02d.pal" % old), dst / ("palettes/%02d.pal" % new))
        if not self.secondary:
            shutil.copyfile(self.src / "tiles.png", dst / "tiles.png")
        else:
            per_row = self.png.width // 8
            out = Image.new("P", (128, math.ceil(len(self.used) / 16) * 8), 0)
            out.putpalette((self.png.getpalette() + [0] * 48)[:48])
            for i, t in enumerate(self.used):
                x, y = t % per_row * 8, t // per_row * 8
                out.paste(self.png.crop((x, y, x + 8, y + 8)), (i % 16 * 8, i // 16 * 8))
            out.save(dst / "tiles.png", bits=4)
        write_ints(dst / "metatiles.bin", "H", self.meta)
        write_ints(dst / "metatile_attributes.bin", "I", self.attrs)

    def remap_metatile(self, m):
        """Emerald metatile id -> FRLG id (primary ids unchanged, secondary ids + 128)."""
        if self.secondary:
            assert EM["metatiles"] <= m < EM["metatiles"] + len(self.em_attrs), hex(m)
            return m - EM["metatiles"] + FR["metatiles"]
        assert m < len(self.em_attrs), hex(m)
        return m


# ---------------------------------------------------------------- render check

def load_tiles(png):
    img = Image.open(png)
    return [img.crop((x, y, x + 8, y + 8)).tobytes()
            for y in range(0, img.height, 8) for x in range(0, img.width, 8)]


def load_pals(directory):
    pals = []
    for i in range(16):
        v = read(directory / ("palettes/%02d.pal" % i)).split()
        assert v[0] == "JASC-PAL"
        pals.append([tuple(map(int, v[3 + 3 * c:6 + 3 * c])) + (255,) for c in range(int(v[2]))])
    return pals


def render(blocks, width, primary_dir, secondary_dir, engine):
    """Draw a map.bin like DrawMetatile (field_camera.c) does: BG3, then BG2, then BG1."""
    lim = EM if engine == "emerald" else FR
    fmt = "H" if engine == "emerald" else "I"
    layer_of = (lambda a: a >> 12) if engine == "emerald" else (lambda a: a >> 29 & 3)
    tiles = [load_tiles(d / "tiles.png") for d in (primary_dir, secondary_dir)]
    pals = [load_pals(d) for d in (primary_dir, secondary_dir)]
    meta = [read_ints(d / "metatiles.bin", "H") for d in (primary_dir, secondary_dir)]
    attrs = [read_ints(d / "metatile_attributes.bin", fmt) for d in (primary_dir, secondary_dir)]
    cache = {}

    def tile_img(e):
        if e not in cache:
            t, p = e & 0x3FF, e >> 12
            data = tiles[0][t] if t < lim["tiles"] else tiles[1][t - lim["tiles"]]
            pal = pals[0][p] if p < lim["pals"] else pals[1][p]
            img = Image.new("RGBA", (8, 8))
            img.putdata([pal[c] if c else (0, 0, 0, 0) for c in data])
            if e & 0x400:
                img = img.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
            if e & 0x800:
                img = img.transpose(Image.Transpose.FLIP_TOP_BOTTOM)
            cache[e] = img
        return cache[e]

    out = Image.new("RGBA", (width * 16, len(blocks) // width * 16), (0, 0, 0, 255))
    for i, block in enumerate(blocks):
        m = block & 0x3FF
        ts, idx = (0, m) if m < lim["metatiles"] else (1, m - lim["metatiles"])
        entries, layer = meta[ts][idx * 8:idx * 8 + 8], layer_of(attrs[ts][idx])
        bottom, top, empty = entries[:4], entries[4:], [0] * 4
        for quad in {0: ([0x3014] * 4, bottom, top), 1: (bottom, top, empty), 2: (bottom, empty, top)}[layer]:
            for k, e in enumerate(quad):
                out.alpha_composite(tile_img(e), (i % width * 16 + k % 2 * 8, i // width * 16 + k // 2 * 8))
    return out


# ---------------------------------------------------------------- repo registration

def defined(name):
    return any(re.search(r"#define\s+%s\b" % name, read(p)) for p in (REPO / "include/constants").glob("*.h"))


def append_once(path, marker, block):
    text = read(path)
    if marker not in text:
        write(path, text + ("" if text.endswith("\n") else "\n") + "\n" + block)


def register_tileset(ts, anim_callback):
    t, d = ts.name, ts.dir
    append_once(REPO / "src/data/tilesets/headers.h", "gTileset_%s =" % t,
                "const struct Tileset gTileset_%s = \n{\n\t.isCompressed = TRUE,\n\t.isSecondary = %s,\n"
                "\t.tiles = gTilesetTiles_%s,\n\t.palettes = gTilesetPalettes_%s,\n\t.metatiles = gMetatiles_%s,\n"
                "\t.metatileAttributes = gMetatileAttributes_%s,\n\t.callback = %s\n};\n"
                % (t, "TRUE" if ts.secondary else "FALSE", t, t, t, t, anim_callback))
    append_once(REPO / "src/data/tilesets/graphics.h", "gTilesetTiles_%s[]" % t,
                'const u32 gTilesetTiles_%s[] = INCBIN_U32("%s/tiles.4bpp.lz");\n\n'
                "const u16 gTilesetPalettes_%s[][16] =\n{\n%s};\n"
                % (t, d, t, "".join('\tINCBIN_U16("%s/palettes/%02d.gbapal"),\n' % (d, i) for i in range(16))))
    append_once(REPO / "src/data/tilesets/metatiles.h", "gMetatiles_%s[]" % t,
                'const u16 gMetatiles_%s[] = INCBIN_U16("%s/metatiles.bin");\n'
                'const u32 gMetatileAttributes_%s[] = INCBIN_U32("%s/metatile_attributes.bin");\n' % (t, d, t, d))
    rules = REPO / "tileset_rules.mk"
    target = "$(TILESETGFXDIR)/%s/tiles.4bpp: %%.4bpp: %%.png\n" % d.replace("data/tilesets/", "")
    text = read(rules)
    if target in text:
        text = re.sub(re.escape(target) + r"(\t\$\(GFX\) \$< \$@ -num_tiles )\d+",
                      lambda m: target + m.group(1) + str(ts.num_tiles), text)
        write(rules, text)
    else:
        append_once(rules, target, target + "\t$(GFX) $< $@ -num_tiles %d -Wnum_tiles\n" % ts.num_tiles)


def register_labels(em, ts):
    labels = [(n, ts.remap_metatile(int(v, 16)) if ts.secondary else int(v, 16))
              for n, v in re.findall(r"#define METATILE_%s_(\w+)\s+(0x[0-9A-Fa-f]+)" % ts.em_name,
                                     read(em / "include/constants/metatile_labels.h"))]
    if not labels:
        return
    path = REPO / "include/constants/metatile_labels.h"
    text = re.sub(r"// gTileset_%s\n(#define .*\n)*\n" % ts.name, "", read(path))
    width = max(len("METATILE_%s_%s" % (ts.name, n)) for n, _ in labels) + 2
    section = "// gTileset_%s\n%s\n" % (ts.name, "".join(
        "#define %s0x%03X\n" % (("METATILE_%s_%s" % (ts.name, n)).ljust(width), v) for n, v in labels))
    after = [m for m in re.finditer(r"^// gTileset_(\w+)\n", text, re.M) if m.group(1) > ts.name]
    pos = after[0].start() if after else text.index("// Other")
    write(path, text[:pos] + section + text[pos:])


def check_not_taken(map_name, layout_id, primary):
    """Only a map / layout made by this tool (laid on its Hoenn primary) may be replaced."""
    for l in json.loads(read(REPO / "data/layouts/layouts.json"))["layouts"]:
        if l.get("id") == layout_id or l.get("blockdata_filepath", "").startswith("data/layouts/%s/" % map_name):
            assert l["primary_tileset"] == primary, \
                "%s (%s) already exists in this repo: not replaced" % (l["id"], l["blockdata_filepath"])
    path = REPO / "data/maps" / map_name / "map.json"
    assert not path.exists() or json.loads(read(path))["layout"] == layout_id, \
        "data/maps/%s already exists in this repo: not replaced" % map_name


def register_map(map_name, layout, group):
    path = REPO / "data/layouts/layouts.json"
    data = json.loads(read(path))
    ids = [l.get("id") for l in data["layouts"]]
    if layout["id"] in ids:  # replace in place: LAYOUT_* ids are positions, saves store them
        data["layouts"][ids.index(layout["id"])] = layout
    else:
        data["layouts"].append(layout)
    write(path, json.dumps(data, indent=2, ensure_ascii=False) + "\n")
    path = REPO / "data/maps/map_groups.json"
    groups = json.loads(read(path))
    if not any(map_name in groups[g] for g in groups["group_order"]):
        groups[group].append(map_name)
        write(path, json.dumps(groups, indent=2, ensure_ascii=False) + "\n")
    scripts = REPO / "data/maps" / map_name / "scripts.inc"
    if not scripts.exists():
        write(scripts, "%s_MapScripts::\n\t.byte 0\n" % map_name)
    include = '\t.include "data/maps/%s/scripts.inc"\n' % map_name
    append_once(REPO / "data/event_scripts.s", include, include)


# ---------------------------------------------------------------- map

def convert_map_json(em_map, map_id):
    movement_types = read(REPO / "include/constants/event_object_movement.h")
    objects, dropped = [], []
    for o in em_map["object_events"]:
        assert o.get("type", "object") == "object", "clone objects are not handled"
        if o["flag"] != "0":  # story NPCs and items: they only make sense with their scripts
            dropped.append("%s (%d,%d) %s" % (o["graphics_id"], o["x"], o["y"], o["flag"]))
            continue
        assert o["graphics_id"] in NPC_GFX, "add %s to NPC_GFX" % o["graphics_id"]
        assert "#define %s " % o["movement_type"] in movement_types, o["movement_type"]
        objects.append({
            "type": "object",
            "graphics_id": NPC_GFX[o["graphics_id"]],
            "x": o["x"],
            "y": o["y"],
            "elevation": o["elevation"],
            "movement_type": o["movement_type"],
            "movement_range_x": o["movement_range_x"],
            "movement_range_y": o["movement_range_y"],
            "trainer_type": "TRAINER_TYPE_NONE",
            "trainer_sight_or_berry_tree_id": "0",
            "script": "0x0",
            "flag": "0",
            "in_connection": False,
        })
    music = em_map["music"] if defined(em_map["music"]) else FALLBACK_MUSIC
    for key in ("region_map_section", "weather", "map_type", "battle_scene"):
        assert defined(em_map[key]), "%s %s does not exist in this repo" % (key, em_map[key])
    out = {
        "id": map_id,
        "name": em_map["name"],
        "layout": em_map["layout"],
        "music": music,
        "region_map_section": em_map["region_map_section"],
        "requires_flash": em_map["requires_flash"],
        "weather": em_map["weather"],
        "map_type": em_map["map_type"],
        "allow_cycling": em_map["allow_cycling"],
        "allow_escaping": em_map["allow_escaping"],
        "allow_running": em_map["allow_running"],
        "show_map_name": em_map["show_map_name"],
        "floor_number": 0,
        "battle_scene": em_map["battle_scene"],
        "connections": 0,  # like the other connection-less maps of gMapGroup_TownsAndRoutes
        "object_events": objects,
        "warp_events": [{"x": w["x"], "y": w["y"], "elevation": w["elevation"],
                         "dest_map": map_id, "dest_warp_id": str(i)}
                        for i, w in enumerate(em_map["warp_events"])],
        "coord_events": [],
        "bg_events": [],
        "level_scaling": "0",  # read by this repo's mapjson; trainer-only
    }
    return out, dropped


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("map", help="Emerald map name, e.g. LilycoveCity (kept as the target name)")
    parser.add_argument("--emerald", type=Path, default=REPO.parent / "pokeemerald", help="pret/pokeemerald clone")
    parser.add_argument("--group", default="gMapGroup_TownsAndRoutes", help="map group the new map is appended to")
    parser.add_argument("--render", type=Path, help="also save the rendered map PNG here")
    args = parser.parse_args()
    em = args.emerald.resolve()

    em_map = json.loads(read(em / "data/maps" / args.map / "map.json"))
    em_layout = next(l for l in json.loads(read(em / "data/layouts/layouts.json"))["layouts"]
                     if l.get("id") == em_map["layout"])
    behaviors = Behaviors(em)
    primary = Tileset(em, em_layout["primary_tileset"], behaviors)
    secondary = Tileset(em, em_layout["secondary_tileset"], behaviors)
    assert not primary.secondary and secondary.secondary
    check_not_taken(args.map, em_layout["id"], "gTileset_" + primary.name)

    def remap(block):
        m = block & 0x3FF
        new = primary.remap_metatile(m) if m < EM["metatiles"] else secondary.remap_metatile(m)
        assert new < TOTAL
        return block & ~0x3FF | new  # collision (bits 10-11) and elevation (bits 12-15) untouched

    blocks = read_ints(em / em_layout["blockdata_filepath"], "H")
    assert len(blocks) == em_layout["width"] * em_layout["height"]
    border = read_ints(em / em_layout["border_filepath"], "H")
    assert len(border) == 4
    new_blocks, new_border = [remap(b) for b in blocks], [remap(b) for b in border]
    map_json, dropped = convert_map_json(em_map, em_map["id"])

    # everything is checked: write
    primary.write()
    secondary.write()
    layout_dir = REPO / "data/layouts" / args.map
    write_ints(layout_dir / "map.bin", "H", new_blocks)
    write_ints(layout_dir / "border.bin", "H", new_border)
    write(REPO / "data/maps" / args.map / "map.json", json.dumps(map_json, indent=2, ensure_ascii=False) + "\n")

    register_tileset(primary, "InitTilesetAnim_" + primary.name)
    register_tileset(secondary, "NULL")
    register_labels(em, primary)
    register_labels(em, secondary)
    register_map(args.map, {
        "id": em_layout["id"],
        "name": em_layout["name"],
        "width": em_layout["width"],
        "height": em_layout["height"],
        "border_width": 2,
        "border_height": 2,
        "primary_tileset": "gTileset_" + primary.name,
        "secondary_tileset": "gTileset_" + secondary.name,
        "border_filepath": "data/layouts/%s/border.bin" % args.map,
        "blockdata_filepath": "data/layouts/%s/map.bin" % args.map,
    }, args.group)

    before = render(blocks, em_layout["width"], primary.src, secondary.src, "emerald")
    after = render(read_ints(layout_dir / "map.bin", "H"), em_layout["width"],
                   REPO / primary.dir, REPO / secondary.dir, "frlg")
    assert before.tobytes() == after.tobytes(), "converted map does not render like the Emerald one"
    if args.render:
        after.save(args.render)

    print("Tilesets: gTileset_%s (%d tiles, %d metatiles), gTileset_%s (%d tiles, %d metatiles)"
          % (primary.name, primary.num_tiles, len(primary.em_attrs),
             secondary.name, secondary.num_tiles, len(secondary.em_attrs)))
    for old, new in secondary.pal_map.items():
        print("WARNING: Emerald palette %d of gTileset_%s is slot %d here (hand-ported door/anim palettes)"
              % (old, secondary.name, new))
    if "void TilesetAnim_%s(" % secondary.em_name in read(em / "src/tileset_anims.c"):
        print("WARNING: Emerald TilesetAnim_%s is not ported (.callback = NULL); its tiles are renumbered here"
              % secondary.em_name)
    print("Behaviors (Emerald -> FRLG: metatiles):")
    for (e, f), n in sorted(behaviors.used.items()):
        lost = " <- no FRLG equivalent" if f == "MB_NORMAL" and e != "MB_NORMAL" else ""
        print("  %-38s -> %-22s %3d%s" % (e, f, n, lost))
    print("NPCs kept: %d, dropped: %s" % (len(map_json["object_events"]), "; ".join(dropped) or "none"))
    print("Music: %s; warps: %d (each one warps onto itself)" % (map_json["music"], len(map_json["warp_events"])))
    print("Render check: converted map is pixel-identical to Emerald's.")


if __name__ == "__main__":
    main()
