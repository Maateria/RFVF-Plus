#!/usr/bin/env python3
"""Import Hoenn maps from a local pret/pokeemerald clone into RFVF+ (pokefirered engine).

Usage (Git Bash, from the repo root; several maps = one batch sharing their tilesets):
    uv run --no-project --with pillow python tools/hoenn_import/hoenn_import.py LilycoveCity
    uv run --no-project --with pillow python tools/hoenn_import/hoenn_import.py --group gMapGroup_IndoorLilycove \
        LilycoveCity_CoveLilyMotel_1F LilycoveCity_CoveLilyMotel_2F ... [--emerald ../pokeemerald] [--render /tmp/png]

What it writes (re-running is safe: entries are replaced, never duplicated):
  - the tilesets of the maps, each converted once per run: Emerald gTileset_X -> gTileset_HoennY in
    data/tilesets/<kind>/hoenn_y/, Y = the suffix of Emerald's gMetatiles_Y (gTileset_Building -> HoennInsideBuilding)
    (tiles.png, palettes/*.pal, metatiles.bin, metatile_attributes.bin; anim/ is left alone)
  - data/layouts/<Layout>/{map.bin,border.bin} + layouts.json (a layout shared by several maps is written once; an
    Emerald LAYOUT_X that this repo already uses for a non-Hoenn layout becomes LAYOUT_HOENN_X / Hoenn_<Name>)
  - data/maps/<Map>/map.json, Emerald's map name and MAP_ id. Objects: those a NEW Emerald game shows (flag not set
    by EventScript_ResetAllMapFlags nor hidden by the map's own script, see HIDDEN_BY_MAP_SCRIPT), minus item balls,
    objects on a warp and still objects that cut the way to a warp; gfx from NPC_GFX / VAR_GFX; script = Emerald's
    label when data/maps/<Map>/scripts.inc defines it, else 0x0. Warps keep Emerald's destination when it is a map
    of this batch or one this tool already imported (or MAP_DYNAMIC), else they warp onto themselves.
    No connections / signs / triggers. A map that already exists keeps its objects, signs and triggers (hand edits
    survive): only its header, layout and warps are regenerated, unless --reset-events.
  - data/maps/<Map>/scripts.inc (only if missing), data/event_scripts.s, data/maps/map_groups.json (--group is
    created at the end of group_order if missing), src/data/tilesets/{headers,graphics,metatiles}.h,
    tileset_rules.mk, include/constants/metatile_labels.h
Nothing is written before the whole batch is validated, a map / layout of this repo that this tool did not
make is never replaced (Emerald and Kanto share names: SafariZone_North, LAYOUT_POKEMON_CENTER_1F...), and a tileset
whose metatile count changed since this tool wrote it (metatiles added in Porymap) is not overwritten.
Not handled here: tileset animations (src/tileset_anims.c: a primary gets .callback = InitTilesetAnim_HoennY, to
write by hand; a secondary gets NULL) and door graphics (src/field_door.c sDoorGraphics_Hoenn), see the report.

Engine differences handled:
  - FRLG primary = 640 tiles / 640 metatiles / 7 palettes (Emerald: 512 / 512 / 6); an Emerald primary is copied
    as is (ids unchanged). An Emerald secondary using palette slot 6 (a primary slot in FRLG) gets it moved to a
    free slot 10-12 (WARNING printed: door palettes naming slot 6 must follow); PALETTE_SWAPS moves others.
  - FRLG secondary = 384 metatiles / 376 tiles (VRAM tiles 1016-1023 are the door animation buffer). A secondary
    that fits keeps every metatile (FRLG id = Emerald id + 128) and only the tiles they use, re-based at 640. One
    that does not fit is PRUNED: it keeps only the metatiles used by the maps imported with it plus those Emerald
    names in metatile_labels.h (scripts and C code set them at runtime; door labels excepted), numbered append-only in
    <tileset dir>/emerald_ids.json (FRLG metatile 640 + i = Emerald metatiles[i], FRLG tile 640 + i = Emerald
    tiles[i]); a later batch using the same tileset adds its metatiles at the end, so maps imported before stay valid.
  - metatile_attributes u16 -> u32: behaviors are mapped by NAME (the values differ between the engines),
    and FRLG's terrain (surf, Cut) and encounter type, which FRLG reads from the attributes, are filled in.
At the end every map is rendered from the Emerald files (Emerald rules) and from the converted files
(FRLG rules): both must match pixel for pixel. This self-test reads the written files, so it runs after writing:
if it fails, revert the import with git.
"""
import argparse
import json
import math
import re
import shutil
import struct
from collections import Counter, defaultdict
from pathlib import Path
from types import SimpleNamespace

from PIL import Image

REPO = Path(__file__).resolve().parents[2]
EM = {"tiles": 512, "metatiles": 512, "pals": 6}  # pokeemerald include/fieldmap.h
FR = {"tiles": 640, "metatiles": 640, "pals": 7}  # this repo's include/fieldmap.h
TOTAL = 1024
SEC_MAX = TOTAL - FR["metatiles"]  # metatiles a FRLG secondary can hold
SEC_MAX_TILES = SEC_MAX - 8  # its tiles: the door animations overwrite the last 8 (src/field_door.c DOOR_TILE_START)
TERRAIN_NORMAL, TERRAIN_GRASS, TERRAIN_WATER, TERRAIN_WATERFALL = 0, 1, 2, 3
ENC_NONE, ENC_LAND, ENC_WATER = 0, 1, 2
IDS_FILE = "emerald_ids.json"
# Emerald secondary palette slot -> FRLG slot, on top of the slot 6 move. FRLG's buy menu loads its frame palette into
# BG slot 11 (src/shop.c BuyMenuDecompressBgGraphics; Emerald's uses 12), so no palette a clerk's map view shows may
# sit there. Shop: Emerald 11 shows from Lilycove 3F's right clerk, 8 from every Mart, 10 from no item seller.
PALETTE_SWAPS = {"gTileset_Shop": {10: 11, 11: 10}}

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
    # Interactive furniture: same flavor text idea (FRLG data/scripts/flavor_text.inc)
    "MB_PICTURE_BOOK_SHELF": "MB_BOOKSHELF",
    "MB_POKEMON_CENTER_BOOKSHELF": "MB_BOOKSHELF",  # "Pokémon magazines" (RHH pairs it with MB_POKEMART_SHELF)
    "MB_SHOP_SHELF": "MB_POKEMART_SHELF",
    "MB_TRASH_CAN": "MB_TRASH_BIN",
    "MB_BLUEPRINT": "MB_BLUEPRINTS",
    "MB_CABLE_BOX_RESULTS_1": "MB_BATTLE_RECORDS",
    "MB_CABLE_BOX_RESULTS_2": "MB_BATTLE_RECORDS",
    "MB_WIRELESS_BOX_RESULTS": "MB_CABLE_CLUB_WIRELESS_MONITOR",
}

# Emerald OBJ_EVENT_GFX -> closest existing gfx of this repo (sprites compared side by side, in-game palettes;
# a walking NPC needs a 9-frame sprite, which is checked).
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
    "OBJ_EVENT_GFX_ARTIST": "OBJ_EVENT_GFX_PAINTER",
    "OBJ_EVENT_GFX_BEAUTY": "OBJ_EVENT_GFX_BEAUTY",
    "OBJ_EVENT_GFX_BLACK_BELT": "OBJ_EVENT_GFX_BLACKBELT",
    "OBJ_EVENT_GFX_BOY_1": "OBJ_EVENT_GFX_BOY",
    "OBJ_EVENT_GFX_BOY_2": "OBJ_EVENT_GFX_MAN",
    "OBJ_EVENT_GFX_BOY_3": "OBJ_EVENT_GFX_TEACHY_TV_HOST",
    "OBJ_EVENT_GFX_CAMPER": "OBJ_EVENT_GFX_CAMPER",
    "OBJ_EVENT_GFX_CONTEST_JUDGE": "OBJ_EVENT_GFX_OLD_MAN_2",
    "OBJ_EVENT_GFX_COOK": "OBJ_EVENT_GFX_CHEF",
    "OBJ_EVENT_GFX_FISHERMAN": "OBJ_EVENT_GFX_FISHER",
    "OBJ_EVENT_GFX_GAMEBOY_KID": "OBJ_EVENT_GFX_GBA_KID",
    "OBJ_EVENT_GFX_GIRL_2": "OBJ_EVENT_GFX_LASS",
    "OBJ_EVENT_GFX_GIRL_3": "OBJ_EVENT_GFX_BATTLE_GIRL",
    "OBJ_EVENT_GFX_LASS": "OBJ_EVENT_GFX_LASS",
    "OBJ_EVENT_GFX_LINK_RECEPTIONIST": "OBJ_EVENT_GFX_UNION_ROOM_RECEPTIONIST",
    "OBJ_EVENT_GFX_LITTLE_GIRL": "OBJ_EVENT_GFX_LITTLE_GIRL",
    "OBJ_EVENT_GFX_MANIAC": "OBJ_EVENT_GFX_SUPER_NERD",
    "OBJ_EVENT_GFX_MAN_3": "OBJ_EVENT_GFX_ROCKER",
    "OBJ_EVENT_GFX_MAN_4": "OBJ_EVENT_GFX_TEACHY_TV_HOST",
    "OBJ_EVENT_GFX_NINJA_BOY": "OBJ_EVENT_GFX_LITTLE_BOY",
    "OBJ_EVENT_GFX_NURSE": "OBJ_EVENT_GFX_NURSE",
    "OBJ_EVENT_GFX_POKEFAN_F": "OBJ_EVENT_GFX_WOMAN_3",
    "OBJ_EVENT_GFX_POKEFAN_M": "OBJ_EVENT_GFX_FAT_MAN",
    "OBJ_EVENT_GFX_PSYCHIC_M": "OBJ_EVENT_GFX_PSYCHIC_M",
    "OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M": "OBJ_EVENT_GFX_COOLTRAINER_M",
    "OBJ_EVENT_GFX_SCOTT": "OBJ_EVENT_GFX_SCOTT",
    "OBJ_EVENT_GFX_TEALA": "OBJ_EVENT_GFX_CABLE_CLUB_RECEPTIONIST",
    "OBJ_EVENT_GFX_TWIN": "OBJ_EVENT_GFX_TWIN",
    "OBJ_EVENT_GFX_WOMAN_1": "OBJ_EVENT_GFX_WOMAN_1",
    "OBJ_EVENT_GFX_WOMAN_4": "OBJ_EVENT_GFX_AROMA_LADY",
    "OBJ_EVENT_GFX_WOMAN_5": "OBJ_EVENT_GFX_WOMAN_2",
    "OBJ_EVENT_GFX_YOUNGSTER": "OBJ_EVENT_GFX_YOUNGSTER",
    # Pokemon without a sprite here: closest existing Pokemon, placeholders
    "OBJ_EVENT_GFX_AZUMARILL": "OBJ_EVENT_GFX_NIDORAN_F",
    "OBJ_EVENT_GFX_KECLEON": "OBJ_EVENT_GFX_BULBASAUR",
}
PLACEHOLDER_GFX = {"OBJ_EVENT_GFX_AZUMARILL", "OBJ_EVENT_GFX_KECLEON"}

# OBJ_EVENT_GFX_VAR_x: the Emerald gfx that map's script gives a new player.
VAR_GFX = {
    # SetLilycoveLadyGfx: Quiz (WOMAN_4) / Favor (WOMAN_2) / Contest (GIRL_2) lady, picked by trainer id: Quiz kept
    ("LilycoveCity_PokemonCenter_1F", "OBJ_EVENT_GFX_VAR_0"): "OBJ_EVENT_GFX_WOMAN_4",
}
# Flags NOT set at new game whose object the map's own script still hides from a new player.
HIDDEN_BY_MAP_SCRIPT = {
    "FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN": "CableClub_OnTransition hides him (no Wonder Card / Eon Ticket)",
    "FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN": "OnTransition hides her (no POKENEWS_LILYCOVE)",
    "FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON": "shown only with the Contest Lady (VAR_0 = Quiz Lady)",
}
FALLBACK_MUSIC = "MUS_VERMILLION"


def read(path):
    with open(path, encoding="utf-8", newline="") as f:
        return f.read()


def write(path, text):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8", newline="") as f:
        f.write(text)


def write_json(path, data):
    write(path, json.dumps(data, indent=2, ensure_ascii=False) + "\n")


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

    def fr_name(self, em_name):
        return BEHAVIOR_OVERRIDES.get(em_name, em_name if em_name in self.fr_values else "MB_NORMAL")

    def convert(self, em_attr):
        """Emerald u16 attribute -> FRLG u32 attribute (see sMetatileAttrMasks in src/fieldmap.c)."""
        assert not em_attr & 0x0F00, "unknown Emerald attribute bits"
        em_name = self.em_names[em_attr & 0xFF]
        fr_name = self.fr_name(em_name)
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
    def __init__(self, em, symbol, behaviors, used):
        """Reads, checks and converts Emerald's tileset `symbol`; `used` = its metatile ids in the maps of the batch.
        write() is the only part that touches the repo."""
        header = re.search(r"const struct Tileset %s =\s*\{(.*?)\};" % symbol, read(em / "src/data/tilesets/headers.h"), re.S)
        assert header, "%s not found in pokeemerald src/data/tilesets/headers.h" % symbol
        fields = dict(re.findall(r"\.(\w+)\s*=\s*(\w+)", header.group(1)))
        sources = "".join(read(em / p) for p in ("src/data/tilesets/graphics.h", "src/graphics.c",
                                                 "src/data/tilesets/metatiles.h"))
        dirs = set()
        for field in ("tiles", "palettes", "metatiles", "metatileAttributes"):
            m = re.search(r'\b%s\[\](?:\[16\])?\s*=\s*\{?\s*INCBIN_U\d+\("(data/tilesets/[^"]+?)/(?:palettes/)?[^/"]+"'
                          % fields[field], sources)
            assert m, "%s of %s not found in pokeemerald src/" % (fields[field], symbol)
            dirs.add(m.group(1))
        assert len(dirs) == 1, "%s: files spread over %s" % (symbol, dirs)
        self.src = em / dirs.pop()
        self.em_name = symbol.replace("gTileset_", "")  # Emerald labels: METATILE_<em_name>_*
        suffix = fields["metatiles"].replace("gMetatiles_", "")
        self.name = "Hoenn" + suffix
        self.secondary = fields["isSecondary"] == "TRUE"
        self.kind = "secondary" if self.secondary else "primary"
        self.em_callback = fields["callback"]
        self.dir = "data/tilesets/%s/hoenn_%s" % (self.kind, re.sub(r"(?<!^)(?=[A-Z])", "_", suffix).lower())
        other = "primary" if self.secondary else "secondary"
        assert not (REPO / self.dir.replace(self.kind, other, 1)).exists(), \
            "%s already exists as a %s tileset of this repo: pick another target name" % (self.dir, other)
        self.em_meta = read_ints(self.src / "metatiles.bin", "H")
        self.em_attrs = read_ints(self.src / "metatile_attributes.bin", "H")
        assert len(self.em_meta) == 8 * len(self.em_attrs)
        self.png = png = Image.open(self.src / "tiles.png")
        assert png.mode == "P" and png.width % 8 == 0 and png.height % 8 == 0
        png_tiles = png.width // 8 * (png.height // 8)
        self.pal_map, self.pruned = {}, False
        if not self.secondary:
            assert len(self.em_attrs) <= EM["metatiles"]
            assert all((e & 0x3FF) < EM["tiles"] and e >> 12 < EM["pals"] for e in self.em_meta), \
                "Emerald primary references secondary tiles or palettes"
            self.metas = list(range(len(self.em_attrs)))
            self.num_tiles = png_tiles
            self.meta = self.em_meta
        else:
            entries = lambda m: self.em_meta[(m - EM["metatiles"]) * 8:(m - EM["metatiles"]) * 8 + 8]
            sec_tiles = lambda metas: sorted({e & 0x3FF for m in metas for e in entries(m) if e & 0x3FF >= EM["tiles"]})
            every = range(EM["metatiles"], EM["metatiles"] + len(self.em_attrs))
            self.ids_path = REPO / self.dir / IDS_FILE
            self.pruned = self.ids_path.exists() or len(every) > SEC_MAX or len(sec_tiles(every)) > SEC_MAX_TILES
            if self.pruned:  # append-only numbering, shared with the maps imported before
                ids = json.loads(read(self.ids_path)) if self.ids_path.exists() else {"metatiles": [], "tiles": []}
                # + the labelled metatiles, which scripts / C code set at runtime; a door label only feeds the door
                # animation table, so that door comes with the first map placing it (and gets its table entry then)
                doors = set(re.findall(r"METATILE_\w+", read(em / "src/field_door.c")))
                used = set(used) | {v for n, v in em_labels(em, self.em_name)
                                    if "METATILE_%s_%s" % (self.em_name, n) not in doors}
                assert used <= set(every), "%s: maps use metatiles it does not have" % symbol
                self.metas = ids["metatiles"] + sorted(used - set(ids["metatiles"]))
                self.tiles = ids["tiles"] + [t for t in sec_tiles(self.metas) if t not in ids["tiles"]]
            else:
                self.metas = list(every)
                self.tiles = sec_tiles(every)
            assert len(self.metas) <= SEC_MAX, "%s: %d metatiles for a FRLG secondary" % (symbol, len(self.metas))
            assert len(self.tiles) <= SEC_MAX_TILES, "%s: %d tiles for a FRLG secondary" % (symbol, len(self.tiles))
            assert not self.tiles or max(self.tiles) - EM["tiles"] < png_tiles, "%s: tile out of tiles.png" % symbol
            tile_map = {t: FR["tiles"] + i for i, t in enumerate(self.tiles)}
            pals = {e >> 12 for e in self.em_meta}  # every metatile: the slot must not move when a later batch adds some
            assert max(pals) <= 12
            if 6 in pals:  # Emerald secondary slot 6 is loaded from the primary in FRLG
                free = [s for s in (10, 11, 12) if s not in pals]
                assert free, "secondary uses palette 6 and slots 10-12: no free FRLG slot"
                self.pal_map[6] = free[0]
            self.pal_map.update(PALETTE_SWAPS.get(symbol, {}))
            self.meta = [tile_map.get(e & 0x3FF, e & 0x3FF) | e & 0x0C00 | self.pal_map.get(e >> 12, e >> 12) << 12
                         for m in self.metas for e in entries(m)]
            self.num_tiles = len(self.tiles)
        # ponytail: only the count is checked (hand-ADDED metatiles would be dropped, or in a pruned set get their id
        # reused); in-place edits are reverted, which git diff shows. Store hashes of the written files if that bites.
        written = len(ids["metatiles"]) if self.pruned else len(self.metas)
        on_disk = REPO / self.dir / "metatiles.bin"
        assert not on_disk.exists() or on_disk.stat().st_size == 16 * written, \
            "%s/metatiles.bin holds %d metatiles, hoenn_import wrote %d: edited by hand (Porymap)? Not overwritten " \
            "(restore it with git, or move the hand-made metatiles to a tileset of your own)" \
            % (self.dir, on_disk.stat().st_size // 16, written)
        self.index = {m: i for i, m in enumerate(self.metas)}
        base = EM["metatiles"] if self.secondary else 0
        self.attrs = [behaviors.convert(self.em_attrs[m - base]) for m in self.metas]

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
            out = Image.new("P", (128, math.ceil(len(self.tiles) / 16) * 8), 0)
            out.putpalette((self.png.getpalette() + [0] * 48)[:48])
            for i, t in enumerate(self.tiles):
                x, y = (t - EM["tiles"]) % per_row * 8, (t - EM["tiles"]) // per_row * 8
                out.paste(self.png.crop((x, y, x + 8, y + 8)), (i % 16 * 8, i // 16 * 8))
            out.save(dst / "tiles.png", bits=4)
        write_ints(dst / "metatiles.bin", "H", self.meta)
        write_ints(dst / "metatile_attributes.bin", "I", self.attrs)
        if self.pruned:
            write(self.ids_path, '{\n  "_": "tools/hoenn_import: FRLG metatile (tile) 640 + i = Emerald metatiles[i] '
                                 '(tiles[i]); append-only, never reorder",\n  "metatiles": %s,\n  "tiles": %s\n}\n'
                                 % (json.dumps(self.metas), json.dumps(self.tiles)))

    def remap_metatile(self, m):
        """Emerald metatile id -> FRLG id (primary: unchanged; secondary: 640 + its position, = id + 128 unpruned)."""
        assert m in self.index, "gTileset_%s has no Emerald metatile 0x%03X" % (self.em_name, m)
        return self.index[m] + (FR["metatiles"] if self.secondary else 0)


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


# ---------------------------------------------------------------- objects / warps

def new_game_flags(em):
    """Flags a new Emerald game sets (src/new_game.c runs EventScript_ResetAllMapFlags; its only call,
    EventScript_ResetAllBerries, sets none)."""
    body = read(em / "data/scripts/new_game.inc").split("EventScript_ResetAllMapFlags::", 1)[1]
    body = body[:re.search(r"^\tend$", body, re.M).start()]
    return set(re.findall(r"setflag (FLAG_\w+)", body))


def sprite_frames(gfx):
    """Frames of this repo's sprite `gfx` (walking needs 9)."""
    path = REPO / "src/data/object_events"
    info = re.search(r"\[%s\]\s*=\s*&(\w+)" % gfx, read(path / "object_event_graphics_info_pointers.h")).group(1)
    images = re.search(r"%s = \{.*?\.images = (\w+)" % info, read(path / "object_event_graphics_info.h"), re.S).group(1)
    return table(read(path / "object_event_pic_tables.h"), images + "[]").count("overworld_frame(")


def walkable_from(blocks, width, start, blocked):
    """Tiles the player reaches on foot from `start`: collision bits clear, FRLG elevation rules
    (IsElevationMismatchAt / ObjectEventUpdateElevation), never entering `blocked`."""
    height = len(blocks) // width
    elevation = lambda x, y: blocks[y * width + x] >> 12
    seen, todo = set(), [(start, elevation(*start))]
    while todo:
        (x, y), z = state = todo.pop()
        if state in seen:
            continue
        seen.add(state)
        for nx, ny in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
            if not (0 <= nx < width and 0 <= ny < height) or (nx, ny) in blocked:
                continue
            e = elevation(nx, ny)
            if blocks[ny * width + nx] & 0x0C00 or (z and e not in (0, 15) and e != z):
                continue
            todo.append(((nx, ny), z if 15 in (e, elevation(x, y)) else e))
    return {pos for pos, _ in seen}


def reached_warps(m, blocked):
    """Warps of map `m` the player reaches from warp 0: by stepping on them, or facing north into a warp door."""
    if not m.em_map["warp_events"]:
        return set()
    tiles = walkable_from(m.blocks, m.width, (m.em_map["warp_events"][0]["x"], m.em_map["warp_events"][0]["y"]), blocked)
    return {i for i, w in enumerate(m.em_map["warp_events"]) if (w["x"], w["y"]) in tiles
            or (m.warp_behaviors[i][0] == "MB_ANIMATED_DOOR" and (w["x"], w["y"] + 1) in tiles)}


def convert_objects(m, new_game, labels):
    """Emerald object_events -> this repo's, plus the dropped ones with their reason."""
    movement_types = read(REPO / "include/constants/event_object_movement.h")
    warps = {(w["x"], w["y"]) for w in m.em_map["warp_events"]}
    kept, dropped = [], []
    for o in m.em_map["object_events"]:
        assert o.get("type", "object") == "object", "clone objects are not handled"
        where = "%s (%d,%d)" % (o["graphics_id"], o["x"], o["y"])
        flag = o["flag"]
        reason = ("item ball" if o["graphics_id"] == "OBJ_EVENT_GFX_ITEM_BALL"
                  else "%s set at new game" % flag if flag in new_game
                  else "%s: %s" % (flag, HIDDEN_BY_MAP_SCRIPT[flag]) if flag in HIDDEN_BY_MAP_SCRIPT
                  else "stands on a warp" if (o["x"], o["y"]) in warps else None)
        if reason:
            dropped.append("%s: %s" % (where, reason))
            continue
        em_gfx = VAR_GFX.get((m.name, o["graphics_id"]), o["graphics_id"])
        assert em_gfx in NPC_GFX, "%s on %s: add it to NPC_GFX (or VAR_GFX)" % (o["graphics_id"], m.name)
        assert "#define %s " % o["movement_type"] in movement_types, o["movement_type"]
        moving = "WANDER" in o["movement_type"] or "WALK" in o["movement_type"]
        assert not moving or sprite_frames(NPC_GFX[em_gfx]) >= 9, \
            "%s walks: %s has no walking frames" % (where, NPC_GFX[em_gfx])
        kept.append((o, em_gfx, moving))
    # a still object must not cut the way to a warp (moving ones step aside)
    base, obstacles, objects = reached_warps(m, set()), set(), []
    for o, em_gfx, moving in kept:
        pos = (o["x"], o["y"])
        lost = sorted(base - reached_warps(m, obstacles | {pos})) if not moving else []
        if lost:
            dropped.append("%s (%d,%d): blocks the way to warp %s" % (o["graphics_id"], o["x"], o["y"], lost))
            continue
        if not moving:
            obstacles.add(pos)
        objects.append({
            "type": "object",
            "graphics_id": NPC_GFX[em_gfx],
            "x": o["x"],
            "y": o["y"],
            "elevation": o["elevation"],
            "movement_type": o["movement_type"],
            "movement_range_x": o["movement_range_x"],
            "movement_range_y": o["movement_range_y"],
            "trainer_type": "TRAINER_TYPE_NONE",
            "trainer_sight_or_berry_tree_id": "0",
            "script": o["script"] if o["script"] in labels else "0x0",
            "flag": "0",
            "in_connection": False,
        })
        m.gfx_used[o["graphics_id"], em_gfx, NPC_GFX[em_gfx]] += 1
    return objects, dropped


def convert_map_json(m, layout_id, warp_counts, new_game, existing):
    labels = set()
    scripts = REPO / "data/maps" / m.name / "scripts.inc"
    if scripts.exists():
        labels = set(re.findall(r"^(\w+)::", read(scripts), re.M))
    if existing:  # hand edits survive a re-run
        objects, dropped = existing["object_events"], []
    else:
        objects, dropped = convert_objects(m, new_game, labels)
    warps = []
    for i, w in enumerate(m.em_map["warp_events"]):
        dest, dest_id = w["dest_map"], w["dest_warp_id"]
        if dest == "MAP_DYNAMIC":
            assert dest_id == "WARP_ID_DYNAMIC", dest_id
        elif dest in warp_counts:
            assert 0 <= int(dest_id) < warp_counts[dest], "%s warp %d: %s has no warp %s" % (m.name, i, dest, dest_id)
        else:  # map not imported (yet): warps onto itself
            dest, dest_id = m.em_map["id"], str(i)
        warps.append({"x": w["x"], "y": w["y"], "elevation": w["elevation"], "dest_map": dest, "dest_warp_id": dest_id})
    music = m.em_map["music"] if defined(m.em_map["music"]) else FALLBACK_MUSIC
    for key in ("region_map_section", "weather", "map_type", "battle_scene"):
        assert defined(m.em_map[key]), "%s %s does not exist in this repo" % (key, m.em_map[key])
    out = {
        "id": m.em_map["id"],
        "name": m.name,
        "layout": layout_id,
        "music": music,
        "region_map_section": m.em_map["region_map_section"],
        "requires_flash": m.em_map["requires_flash"],
        "weather": m.em_map["weather"],
        "map_type": m.em_map["map_type"],
        "allow_cycling": m.em_map["allow_cycling"],
        "allow_escaping": m.em_map["allow_escaping"],
        "allow_running": m.em_map["allow_running"],
        "show_map_name": m.em_map["show_map_name"],
        "floor_number": m.em_map.get("floor_number", 0),
        "battle_scene": m.em_map["battle_scene"],
        "connections": 0,  # like the other connection-less maps of this repo
        "object_events": objects,
        "warp_events": warps,
        "coord_events": existing["coord_events"] if existing else [],
        "bg_events": existing["bg_events"] if existing else [],
        "level_scaling": "0",  # read by this repo's mapjson; trainer-only
    }
    return out, dropped


# ---------------------------------------------------------------- repo registration

def defined(name):
    return any(re.search(r"#define\s+%s\b" % name, read(p)) for p in (REPO / "include/constants").glob("*.h"))


def append_once(path, marker, block):
    text = read(path)
    if marker not in text:
        write(path, text + ("" if text.endswith("\n") else "\n") + "\n" + block)


def register_tileset(ts):
    t, d = ts.name, ts.dir
    callback = "InitTilesetAnim_" + t if not ts.secondary and ts.em_callback != "NULL" else "NULL"
    append_once(REPO / "src/data/tilesets/headers.h", "gTileset_%s =" % t,
                "const struct Tileset gTileset_%s = \n{\n\t.isCompressed = TRUE,\n\t.isSecondary = %s,\n"
                "\t.tiles = gTilesetTiles_%s,\n\t.palettes = gTilesetPalettes_%s,\n\t.metatiles = gMetatiles_%s,\n"
                "\t.metatileAttributes = gMetatileAttributes_%s,\n\t.callback = %s\n};\n"
                % (t, "TRUE" if ts.secondary else "FALSE", t, t, t, t, callback))
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


def em_labels(em, em_name):
    """Emerald's METATILE_<em_name>_X labels: [(X, Emerald metatile id)]."""
    return [(n, int(v, 16)) for n, v in re.findall(r"#define METATILE_%s_(\w+)\s+(0x[0-9A-Fa-f]+)" % em_name,
                                                   read(em / "include/constants/metatile_labels.h"))]


def register_labels(em, ts):
    """METATILE_<Emerald set>_X -> METATILE_<FRLG set>_X, for the metatiles the tileset has here."""
    labels = [(n, ts.remap_metatile(v)) for n, v in em_labels(em, ts.em_name) if v in ts.index]
    path = REPO / "include/constants/metatile_labels.h"
    text = re.sub(r"// gTileset_%s\n(#define .*\n)*\n" % ts.name, "", read(path))
    if labels:
        width = max(len("METATILE_%s_%s" % (ts.name, n)) for n, _ in labels) + 2
        section = "// gTileset_%s\n%s\n" % (ts.name, "".join(
            "#define %s0x%03X\n" % (("METATILE_%s_%s" % (ts.name, n)).ljust(width), v) for n, v in labels))
        after = [m for m in re.finditer(r"^// gTileset_(\w+)\n", text, re.M) if m.group(1) > ts.name]
        pos = after[0].start() if after else text.index("// Other")
        text = text[:pos] + section + text[pos:]
    write(path, text)


def plan_layout(em_layout, repo_layouts):
    """This repo's layout entry for an Emerald layout: Emerald's id, or LAYOUT_HOENN_* when the id is a Kanto one."""
    ours = lambda l: l["primary_tileset"].startswith("gTileset_Hoenn")
    lid, name = em_layout["id"], em_layout["name"]
    folder = Path(em_layout["blockdata_filepath"]).parent.name
    renamed = any(l.get("id") == lid and not ours(l) for l in repo_layouts)
    if renamed:
        lid, name, folder = "LAYOUT_HOENN_" + lid[len("LAYOUT_"):], "Hoenn_" + name, "Hoenn_" + folder
    for l in repo_layouts:  # only a layout this tool made may be replaced
        if l.get("id") == lid or l.get("blockdata_filepath", "").startswith("data/layouts/%s/" % folder):
            assert ours(l) and l["id"] == lid, "%s (%s) already exists in this repo: not replaced" \
                                              % (l.get("id"), l.get("blockdata_filepath"))
    return renamed, {
        "id": lid,
        "name": name,
        "width": em_layout["width"],
        "height": em_layout["height"],
        "border_width": 2,
        "border_height": 2,
        "primary_tileset": None,  # filled by the caller
        "secondary_tileset": None,
        "border_filepath": "data/layouts/%s/border.bin" % folder,
        "blockdata_filepath": "data/layouts/%s/map.bin" % folder,
    }


def register_maps(maps, layouts, group):
    path = REPO / "data/layouts/layouts.json"
    data = json.loads(read(path))
    for layout in layouts:
        ids = [l.get("id") for l in data["layouts"]]
        if layout["id"] in ids:  # replace in place: LAYOUT_* ids are positions, saves store them
            data["layouts"][ids.index(layout["id"])] = layout
        else:
            data["layouts"].append(layout)
    write_json(path, data)
    path = REPO / "data/maps/map_groups.json"
    groups = json.loads(read(path))
    if group not in groups:
        groups["group_order"].append(group)
        groups[group] = []
    for m in maps:
        if not any(m.name in groups[g] for g in groups["group_order"]):
            groups[group].append(m.name)
    write_json(path, groups)
    includes = ""
    for m in maps:
        scripts = REPO / "data/maps" / m.name / "scripts.inc"
        if not scripts.exists():
            write(scripts, "%s_MapScripts::\n\t.byte 0\n" % m.name)
        include = '\t.include "data/maps/%s/scripts.inc"\n' % m.name
        if include not in read(REPO / "data/event_scripts.s"):
            includes += include
    if includes:
        append_once(REPO / "data/event_scripts.s", includes, includes)


# ---------------------------------------------------------------- main

def main():
    if not __debug__:
        raise SystemExit("hoenn_import's safety checks are asserts: run it without python -O / PYTHONOPTIMIZE")
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("maps", nargs="+", help="Emerald map names, e.g. LilycoveCity (kept as the target names)")
    parser.add_argument("--emerald", type=Path, default=REPO.parent / "pokeemerald", help="pret/pokeemerald clone")
    parser.add_argument("--group", default="gMapGroup_TownsAndRoutes", help="map group new maps are appended to")
    parser.add_argument("--reset-events", action="store_true",
                        help="regenerate the objects of maps that already exist (drops their hand edits)")
    parser.add_argument("--render", type=Path, help="also save each rendered map as <dir>/<Map>.png")
    args = parser.parse_args()
    em = args.emerald.resolve()
    em_layouts = {l["id"]: l for l in json.loads(read(em / "data/layouts/layouts.json"))["layouts"] if "id" in l}
    repo_layouts = json.loads(read(REPO / "data/layouts/layouts.json"))["layouts"]
    behaviors = Behaviors(em)
    new_game = new_game_flags(em)

    maps = []
    for name in dict.fromkeys(args.maps):
        em_map = json.loads(read(em / "data/maps" / name / "map.json"))
        layout = em_layouts[em_map["layout"]]
        blocks = read_ints(em / layout["blockdata_filepath"], "H")
        assert len(blocks) == layout["width"] * layout["height"]
        border = read_ints(em / layout["border_filepath"], "H")
        assert len(border) == 4
        maps.append(SimpleNamespace(name=name, em_map=em_map, layout=layout, blocks=blocks, border=border,
                                    width=layout["width"], gfx_used=Counter()))

    # tilesets: each converted once, with the metatiles of every map of the batch that uses it
    used = defaultdict(set)
    for m in maps:
        for block in m.blocks + m.border:
            mid = block & 0x3FF
            used[m.layout["secondary_tileset"] if mid >= EM["metatiles"] else m.layout["primary_tileset"]].add(mid)
    tilesets = {}
    for m in maps:
        for key in ("primary_tileset", "secondary_tileset"):
            if m.layout[key] not in tilesets:
                tilesets[m.layout[key]] = Tileset(em, m.layout[key], behaviors, used[m.layout[key]])
        m.primary, m.secondary = tilesets[m.layout["primary_tileset"]], tilesets[m.layout["secondary_tileset"]]
        assert not m.primary.secondary and m.secondary.secondary
        remap = lambda b: b & ~0x3FF | (m.primary.remap_metatile(b & 0x3FF) if b & 0x3FF < EM["metatiles"]
                                        else m.secondary.remap_metatile(b & 0x3FF))  # collision/elevation untouched
        m.new_blocks, m.new_border = [remap(b) for b in m.blocks], [remap(b) for b in m.border]
        m.warp_behaviors = []
        for w in m.em_map["warp_events"]:
            mid = m.blocks[w["y"] * m.width + w["x"]] & 0x3FF
            ts = m.primary if mid < EM["metatiles"] else m.secondary
            em_beh = behaviors.em_names[ts.em_attrs[mid - (EM["metatiles"] if ts.secondary else 0)] & 0xFF]
            m.warp_behaviors.append((em_beh, behaviors.fr_name(em_beh), mid, ts.remap_metatile(mid)))

    # layouts (shared ones once) and the maps this tool owns, to wire warps and refuse foreign maps
    layouts = {}
    for m in maps:
        if m.layout["id"] not in layouts:
            renamed, layout = plan_layout(m.layout, repo_layouts)
            layout["primary_tileset"], layout["secondary_tileset"] = "gTileset_" + m.primary.name, "gTileset_" + m.secondary.name
            layouts[m.layout["id"]] = (renamed, layout)
        m.renamed, m.new_layout = layouts[m.layout["id"]]
    repo_layout_ids = {l["id"]: l for l in repo_layouts if "id" in l}
    warp_counts, map_folders = {}, {}
    for path in (REPO / "data/maps").glob("*/map.json"):
        mj = json.loads(read(path))
        map_folders[mj["id"]] = path.parent.name
        if repo_layout_ids.get(mj.get("layout"), {}).get("primary_tileset", "").startswith("gTileset_Hoenn"):
            warp_counts[mj["id"]] = len(mj["warp_events"])
    for m in maps:
        assert map_folders.get(m.em_map["id"], m.name) == m.name, \
            "%s is already data/maps/%s" % (m.em_map["id"], map_folders[m.em_map["id"]])
        warp_counts[m.em_map["id"]] = len(m.em_map["warp_events"])
    for m in maps:
        path = REPO / "data/maps" / m.name / "map.json"
        existing = json.loads(read(path)) if path.exists() else None
        assert not existing or existing["layout"] == m.new_layout["id"], \
            "data/maps/%s already exists in this repo: not replaced" % m.name
        m.kept_events = existing is not None and not args.reset_events
        m.map_json, m.dropped = convert_map_json(m, m.new_layout["id"], warp_counts, new_game,
                                                 existing if m.kept_events else None)

    # everything is checked: write
    for ts in tilesets.values():
        ts.write()
    for m in maps:
        write_ints(REPO / m.new_layout["blockdata_filepath"], "H", m.new_blocks)
        write_ints(REPO / m.new_layout["border_filepath"], "H", m.new_border)
        write_json(REPO / "data/maps" / m.name / "map.json", m.map_json)
    for ts in tilesets.values():
        register_tileset(ts)
        register_labels(em, ts)
    register_maps(maps, [layout for _, layout in layouts.values()], args.group)

    for m in maps:
        before = render(m.blocks, m.width, m.primary.src, m.secondary.src, "emerald")
        after = render(read_ints(REPO / m.new_layout["blockdata_filepath"], "H"), m.width,
                       REPO / m.primary.dir, REPO / m.secondary.dir, "frlg")
        assert before.tobytes() == after.tobytes(), "%s does not render like the Emerald one" % m.name
        if args.render:
            args.render.mkdir(parents=True, exist_ok=True)
            after.save(args.render / (m.name + ".png"))
    report(maps, tilesets, behaviors)


def report(maps, tilesets, behaviors):
    print("Tilesets:")
    for ts in tilesets.values():
        print("  gTileset_%-26s %-9s %3d metatiles %3d tiles  %s%s" % (
            ts.name, ts.kind, len(ts.metas), ts.num_tiles, ts.dir,
            "  PRUNED, ids in " + IDS_FILE if ts.pruned else ""))
        for old, new in ts.pal_map.items():
            print("WARNING: Emerald palette %d of gTileset_%s is slot %d here (door/anim palettes naming slot %d "
                  "must follow)" % (old, ts.name, new, old))
        if ts.secondary and ts.em_callback != "NULL":
            print("WARNING: Emerald %s is not ported (.callback = NULL); its tiles are renumbered here" % ts.em_callback)
        if not ts.secondary and ts.em_callback != "NULL":
            print("NOTE: gTileset_%s.callback = InitTilesetAnim_%s (src/tileset_anims.c, port of Emerald %s)"
                  % (ts.name, ts.name, ts.em_callback))
    print("Behaviors (Emerald -> FRLG: metatiles):")
    for (e, f), n in sorted(behaviors.used.items()):
        lost = " <- no FRLG equivalent" if f == "MB_NORMAL" and e != "MB_NORMAL" else ""
        print("  %-38s -> %-30s %3d%s" % (e, f, n, lost))
    for m in maps:
        j = m.map_json
        print("%s  %s%s  %s  %dx%d  %s + %s" % (
            j["id"], j["layout"], " (Emerald %s)" % m.layout["id"] if m.renamed else "", j["music"],
            m.width, len(m.blocks) // m.width, m.new_layout["primary_tileset"], m.new_layout["secondary_tileset"]))
        if m.kept_events:
            print("  objects / signs / triggers: those of the existing map.json (--reset-events regenerates them)")
        for o in j["object_events"]:
            print("  NPC  (%2d,%2d) %-38s %-26s %s" % (o["x"], o["y"], o["graphics_id"], o["movement_type"][14:],
                                                    o["script"]))
        for d in m.dropped:
            print("  DROP " + d)
        for i, (w, (em_beh, fr_beh, em_mt, fr_mt)) in enumerate(zip(j["warp_events"], m.warp_behaviors)):
            print("  WARP %d (%2d,%2d) %-20s mt 0x%03X (Emerald 0x%03X) -> %s #%s" % (
                i, w["x"], w["y"], fr_beh, fr_mt, em_mt, w["dest_map"], w["dest_warp_id"]))
    gfx = Counter()
    for m in maps:
        gfx.update(m.gfx_used)
    if gfx:
        print("Sprites (Emerald -> here: objects):")
        for (em_gfx, var_gfx, fr_gfx), n in sorted(gfx.items()):
            print("  %-36s -> %-40s %2d%s" % (em_gfx if em_gfx == var_gfx else "%s=%s" % (em_gfx, var_gfx), fr_gfx, n,
                                             "  placeholder" if var_gfx in PLACEHOLDER_GFX else ""))
    print("Render check: every converted map is pixel-identical to Emerald's.")


if __name__ == "__main__":
    main()
