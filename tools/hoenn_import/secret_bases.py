# /// script
# requires-python = ">=3.9"
# dependencies = ["pillow"]
# ///
"""Emerald's secret bases, the map side (the code is in src/secret_base.c). Run from the repo root:
    uv run tools/hoenn_import/secret_bases.py [--dry-run] [--emerald ..\\pokeemerald]
Re-running it gives the same files ("nothing to do"). It writes:
  1. the secret base behaviors of the Hoenn tilesets import_map.py wrote before metatile_behaviors.h had them (they
     got MB_NORMAL then, NO_COUNTERPART): General's entrances (trees, red/yellow/blue caves), Fallarbor's brown cave,
     Fortree's shrub, the Trainer Hill's mats, the walls of the Battle Pyramid and General, the Hoenn bedroom's
     decoration spots. Only the behavior bits change (terrain, encounters and layers stay).
  2. Emerald's entrances (secret_base bg events, SECRET_BASE_* ids) on the Hoenn maps here, checked against the
     behavior of the metatile they stand on.
  3. the 24 SecretBase_* maps (+ the METATILE_HoennSecretBase_* labels) (group gMapGroup_SecretBases, Emerald's order: MAP_NUM matters to secret_base.c),
     their layouts and tilesets: gTileset_HoennSecretBase (Emerald's primary, copied) and the 6
     gTileset_HoennSecretBase<Variant> secondaries sharing gMetatiles_HoennSecretBaseSecondary as in Emerald (tiles
     re-based at 640, metatiles at + 128, palette slot 6 -> 10). Every map must render like Emerald's pixel for pixel.
Exit codes: 0 done / nothing to do, 1 refused (nothing written)."""
import argparse
import json
import re
import sys
from pathlib import Path
from types import SimpleNamespace

import hoenn_import as hi

VARIANTS = ("RedCave", "BrownCave", "BlueCave", "YellowCave", "Tree", "Shrub")  # Emerald's map order in each set
MAPS = ["SecretBase_%s%d" % (v, n) for n in range(1, 5) for v in VARIANTS]
GROUP = "gMapGroup_SecretBases"
PRIMARY_DIR = "data/tilesets/primary/hoenn_secret_base"
SECONDARY_DIR = "data/tilesets/secondary/hoenn_secret_base"
PAL_TO = 10  # Emerald's secondary palette slot 6 is a primary slot here (hoenn_import.Tileset does the same)
# (Emerald tileset folder, a folder made of it here): those holding secret base behaviors (import_map.py; the Trainer
# Hill's floors: work/hoenn_scripts/trainer_hill_data.py, natural ids)
OLD_TILESETS = [("primary/general", "primary/hoenn_general"), ("secondary/fallarbor", "secondary/hoenn_fallarbor"),
                ("secondary/fortree", "secondary/hoenn_fortree"),
                ("secondary/battle_pyramid", "secondary/hoenn_battle_pyramid"),
                ("secondary/trainer_hill", "secondary/hoenn_trainer_hill"),
                ("secondary/trainer_hill", "secondary/hoenn_trainer_hill_floors"),
                ("secondary/brendans_mays_house", "secondary/hoenn_brendans_mays_house")]
SECRET = re.compile(r"MB_(SECRET_BASE_\w+|HOLDS_\w+_DECORATION|PLAYER_ROOM_PC_ON)$")
SPOT = re.compile(r"MB_SECRET_BASE_SPOT_\w+$")


def snake(name):
    return re.sub(r"(?<!^)(?=[A-Z])", "_", name).lower()


def fix_old_attributes(em, beh):
    """1: the behavior bits of the metatiles whose Emerald behavior is a secret base one."""
    n = 0
    for em_dir, fr_dir in OLD_TILESETS:
        dst = hi.REPO / "data/tilesets" / fr_dir
        em_attrs = hi.read_ints(em / "data/tilesets" / em_dir / "metatile_attributes.bin", "H")
        attrs = hi.read_ints(dst / "metatile_attributes.bin", "I")
        ids = dst / hi.IDS_FILE  # a pruned secondary: FRLG metatile 640 + i = Emerald metatiles[i]
        order = [None if m is None else m - hi.EM["metatiles"] for m in json.loads(hi.read(ids))["metatiles"]] \
            if hi.exists(ids) else list(range(len(attrs)))
        for i, m in enumerate(order):
            if m is None or m >= len(em_attrs):
                continue
            name = beh.em_names[em_attrs[m] & 0xFF]
            if SECRET.match(name):
                new = attrs[i] & ~0x1FF | beh.fr_values[name]
                n += new != attrs[i]
                attrs[i] = new
        hi.write_ints(dst / "metatile_attributes.bin", "I", attrs)
    return n


def layout_of(repo_layouts, layout_id):
    return next(l for l in repo_layouts if l.get("id") == layout_id)


def behavior_at(layout, x, y, beh):
    """This repo's behavior name at (x, y) of a layout (its tilesets' files, the planned ones included)."""
    block = hi.read_ints(hi.REPO / layout["blockdata_filepath"], "H")[y * layout["width"] + x] & 0x3FF
    ts, i = (layout["primary_tileset"], block) if block < hi.FR["metatiles"] else \
        (layout["secondary_tileset"], block - hi.FR["metatiles"])
    value = hi.read_ints(hi.repo_tileset_dir(ts) / "metatile_attributes.bin", "I")[i] & 0x1FF
    return next((n for n, v in beh.fr_values.items() if v == value), hex(value))


def add_entrances(em, beh, repo_layouts):
    """2: Emerald's secret_base bg events on the maps here."""
    added = 0
    for path in sorted((em / "data/maps").glob("*/map.json")):
        em_map = json.loads(hi.read(path))
        events = [e for e in em_map.get("bg_events") or [] if e["type"] == "secret_base"]
        if not events:
            continue
        name = hi.rename(em_map["name"])
        dst = hi.REPO / "data/maps" / name / "map.json"
        if not hi.exists(dst):
            hi.refuse("%s has secret bases in Emerald but is not here" % name)
            continue
        here = json.loads(hi.read(dst))
        layout = layout_of(repo_layouts, here["layout"])
        have = {(e["x"], e["y"]) for e in here.get("bg_events") or [] if e["type"] == "secret_base"}
        for e in events:
            b = behavior_at(layout, e["x"], e["y"], beh)  # the entrance itself (the player faces it, northward)
            if not SPOT.match(b):
                hi.refuse("%s %d,%d (%s): the entrance is %s here" % (name, e["x"], e["y"], e["secret_base_id"], b))
            if (e["x"], e["y"]) not in have:
                here.setdefault("bg_events", []).append(
                    {"type": "secret_base", "x": e["x"], "y": e["y"], "elevation": e["elevation"],
                     "secret_base_id": e["secret_base_id"]})
                added += 1
        hi.write_json(dst, here)
    return added


def em_secondary(em, variant):
    """Emerald's gTileset_SecretBase<variant> as hoenn_import.render reads a tileset."""
    d = em / "data/tilesets/secondary/secret_base"
    return (hi.load_tiles(hi.read_bytes(d / snake(variant) / "tiles.png")), hi.load_pals(d / snake(variant)),
            hi.read_ints(d / "metatiles.bin", "H"), hi.read_ints(d / "metatile_attributes.bin", "H"))


def decoration_objects(name, em_objects):
    """Emerald's decoration objects of a base (hidden at 0-1,0-6 until a doll or cushion is placed), owner left out."""
    out = [o for o in em_objects if o["flag"].startswith("FLAG_DECORATION_")]
    if [(o["graphics_id"], o["flag"]) for o in out] != [("OBJ_EVENT_GFX_VAR_%X" % i, "FLAG_DECORATION_%d" % (i + 1))
                                                         for i in range(14)] \
            or len(em_objects) != 15 or any(o["script"] != "0x0" for o in out):
        hi.refuse("%s: Emerald's objects changed" % name)
    return out


def import_bases(em, beh, repo_layouts, groups):
    """3: tilesets, layouts, maps, registrations."""
    src_p, src_s = em / "data/tilesets/primary/secret_base", em / "data/tilesets/secondary/secret_base"
    prim, sec = hi.REPO / PRIMARY_DIR, hi.REPO / SECONDARY_DIR
    # primary: copied (its 2 metatiles; the decorations' tiles are its 512 tiles)
    for i in range(16):
        hi.copy(src_p / ("palettes/%02d.pal" % i), prim / ("palettes/%02d.pal" % i))
    hi.copy(src_p / "tiles.png", prim / "tiles.png")
    hi.copy(src_p / "metatiles.bin", prim / "metatiles.bin")
    hi.write_ints(prim / "metatile_attributes.bin", "I",
                  [beh.convert(a) for a in hi.read_ints(src_p / "metatile_attributes.bin", "H")])
    # secondaries: one metatiles.bin for the 6 (Emerald's gMetatiles_SecretBaseSecondary), tiles re-based at 640
    em_meta = hi.read_ints(src_s / "metatiles.bin", "H")
    if any(e >> 12 in (PAL_TO, 13, 14, 15) for e in em_meta):
        hi.refuse("Emerald's secret base secondary uses palette slot %d or 13+" % PAL_TO, fatal=True)
    num_tiles = {}
    for v in VARIANTS:
        png = hi.open_png(src_s / snake(v) / "tiles.png")
        num_tiles[v] = png.width // 8 * (png.height // 8)
        hi.copy(src_s / snake(v) / "tiles.png", sec / snake(v) / "tiles.png")
        for i in range(16):
            hi.copy(src_s / snake(v) / ("palettes/%02d.pal" % i), sec / snake(v) / ("palettes/%02d.pal" % i))
        hi.copy(src_s / snake(v) / "palettes/06.pal", sec / snake(v) / ("palettes/%02d.pal" % PAL_TO))
    if max(e & 0x3FF for e in em_meta) >= hi.EM["tiles"] + min(num_tiles.values()):
        hi.refuse("Emerald's secret base metatiles use tiles beyond a variant's tiles.png", fatal=True)
    hi.write_ints(sec / "metatiles.bin", "H",
                  [(e + (hi.FR["tiles"] - hi.EM["tiles"] if e & 0x3FF >= hi.EM["tiles"] else 0)) & 0xFFF |
                   (PAL_TO if e >> 12 == 6 else e >> 12) << 12 for e in em_meta])
    hi.write_ints(sec / "metatile_attributes.bin", "I",
                  [beh.convert(a) for a in hi.read_ints(src_s / "metatile_attributes.bin", "H")])
    n_prim = len(hi.read_ints(src_p / "metatile_attributes.bin", "H"))
    n_sec = len(em_meta) // 8
    # registrations (hoenn_import.register_tileset's formats)
    t = "HoennSecretBase"
    hi.append_once(hi.REPO / "src/data/tilesets/headers.h", "gTileset_%s =" % t, "".join(
        "const struct Tileset gTileset_%s = \n{\n\t.isCompressed = TRUE,\n\t.isSecondary = %s,\n\t.tiles = "
        "gTilesetTiles_%s,\n\t.palettes = gTilesetPalettes_%s,\n\t.metatiles = gMetatiles_%s,\n\t.metatileAttributes = "
        "gMetatileAttributes_%s,\n\t.callback = NULL\n};\n\n" % (name, secondary, name, name, meta, meta)
        for name, secondary, meta in [(t, "FALSE", t)] + [(t + v, "TRUE", t + "Secondary") for v in VARIANTS]))
    hi.append_once(hi.REPO / "src/data/tilesets/graphics.h", "gTilesetTiles_%s[]" % t, "".join(
        'const u32 gTilesetTiles_%s[] = INCBIN_U32("%s/tiles.4bpp.lz");\n\nconst u16 gTilesetPalettes_%s[][16] =\n{\n%s};'
        '\n\n' % (name, d, name, "".join('\tINCBIN_U16("%s/palettes/%02d.gbapal"),\n' % (d, i) for i in range(16)))
        for name, d in [(t, PRIMARY_DIR)] + [(t + v, SECONDARY_DIR + "/" + snake(v)) for v in VARIANTS]))
    hi.append_once(hi.REPO / "src/data/tilesets/metatiles.h", "gMetatiles_%s[]" % t, "".join(
        'const u16 gMetatiles_%s[] = INCBIN_U16("%s/metatiles.bin");\nconst u32 gMetatileAttributes_%s[] = '
        'INCBIN_U32("%s/metatile_attributes.bin");\n' % (name, d, name, d)
        for name, d in ((t, PRIMARY_DIR), (t + "Secondary", SECONDARY_DIR))))
    hi.append_once(hi.REPO / "tileset_rules.mk", "$(TILESETGFXDIR)/primary/hoenn_secret_base/tiles.4bpp", "".join(
        "$(TILESETGFXDIR)/%s/tiles.4bpp: %%.4bpp: %%.png\n\t$(GFX) $< $@ -num_tiles %d -Wnum_tiles\n\n"
        % (d.replace("data/tilesets/", ""), n) for d, n in
        [(PRIMARY_DIR, hi.EM["tiles"])] + [(SECONDARY_DIR + "/" + snake(v), num_tiles[v]) for v in VARIANTS]))
    hi.register_labels(em, SimpleNamespace(  # METATILE_HoennSecretBase_X = Emerald's METATILE_SecretBase_X + 128
        name=t, em_name="SecretBase", index=range(hi.EM["metatiles"], hi.EM["metatiles"] + n_sec),
        remap_metatile=lambda m: m + hi.FR["metatiles"] - hi.EM["metatiles"]))
    # layouts and maps
    em_layouts = json.loads(hi.read(em / "data/layouts/layouts.json"))["layouts"]
    remap = lambda b: b + hi.FR["metatiles"] - hi.EM["metatiles"] if b & 0x3FF >= hi.EM["metatiles"] else b
    new_layouts = []
    for name in MAPS:
        em_map = json.loads(hi.read(em / "data/maps" / name / "map.json"))
        el = layout_of(em_layouts, em_map["layout"])
        folder = Path(el["blockdata_filepath"]).parent.name
        blocks = hi.read_ints(em / el["blockdata_filepath"], "H")
        for b in blocks + hi.read_ints(em / el["border_filepath"], "H"):
            m = b & 0x3FF
            if not (m < n_prim or hi.EM["metatiles"] <= m < hi.EM["metatiles"] + n_sec):
                hi.refuse("%s: metatile 0x%03X is in neither tileset" % (name, m))
        hi.write_ints(hi.REPO / "data/layouts" / folder / "map.bin", "H", [remap(b) for b in blocks])
        hi.write_ints(hi.REPO / "data/layouts" / folder / "border.bin", "H",
                      [remap(b) for b in hi.read_ints(em / el["border_filepath"], "H")])
        variant = el["secondary_tileset"].replace("gTileset_SecretBase", "")
        layout = dict(el, primary_tileset="gTileset_" + t, secondary_tileset="gTileset_" + t + variant,
                      border_width=2, border_height=2)
        if not any(l.get("id") == layout["id"] for l in repo_layouts):
            new_layouts.append(layout)
        warps = [dict(w, dest_map="MAP_DYNAMIC", dest_warp_id="WARP_ID_SECRET_BASE") for w in em_map["warp_events"]]
        if len(warps) != 1 or em_map["warp_events"][0]["dest_warp_id"] != "WARP_ID_SECRET_BASE":
            hi.refuse("%s: Emerald's warps changed" % name)
        hi.write_json(hi.REPO / "data/maps" / name / "map.json", {
            "id": em_map["id"], "name": name, "layout": el["id"], "music": em_map["music"],
            "region_map_section": em_map["region_map_section"], "requires_flash": False, "weather": "WEATHER_NONE",
            "map_type": "MAP_TYPE_SECRET_BASE", "allow_cycling": False, "allow_escaping": False, "allow_running": True,
            "show_map_name": True, "floor_number": 0, "battle_scene": "MAP_BATTLE_SCENE_NORMAL", "connections": 0,
            # Emerald's 14 decoration objects (dolls, cushions: OBJ_EVENT_GFX_VAR_0-D, FLAG_DECORATION_1-14), without
            # the owner (other players' bases: none)
            "object_events": decoration_objects(name, em_map["object_events"]), "warp_events": warps,
            "coord_events": [], "bg_events": [],
            "shared_scripts_map": "SecretBase", "level_scaling": "0"})
        # pixel check against Emerald
        hi._TILESETS[(Path("em_" + variant), "emerald")] = em_secondary(em, variant)
        hi._TILESETS[(Path("fr_" + variant), "frlg")] = (
            hi.load_tiles(hi.read_bytes(sec / snake(variant) / "tiles.png")), hi.load_pals(sec / snake(variant)),
            hi.read_ints(sec / "metatiles.bin", "H"), hi.read_ints(sec / "metatile_attributes.bin", "I"))
        a = hi.render(blocks, el["width"], src_p, Path("em_" + variant), "emerald")
        b = hi.render(hi.read_ints(hi.REPO / "data/layouts" / folder / "map.bin", "H"), el["width"], prim,
                      Path("fr_" + variant), "frlg")
        if a.tobytes() != b.tobytes():
            hi.refuse("%s does not render like Emerald's" % name)
    if new_layouts:  # appended: saved mapLayoutIds must not move
        data = json.loads(hi.read(hi.REPO / "data/layouts/layouts.json"))
        data["layouts"] += new_layouts
        hi.write_json(hi.REPO / "data/layouts/layouts.json", data)
    if GROUP not in groups:
        groups["group_order"].append(GROUP)
        groups[GROUP] = MAPS
        hi.write_json(hi.REPO / "data/maps/map_groups.json", groups)
    elif groups[GROUP] != MAPS:
        hi.refuse("%s is not Emerald's 24 secret bases in order" % GROUP)


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--emerald", type=Path, default=hi.REPO.parent / "pokeemerald")
    args = parser.parse_args()
    em = args.emerald
    beh = hi.Behaviors(em)
    missing = sorted(n for n in beh.em_names if SECRET.match(n) and n not in beh.fr_values)
    if missing:
        print("not in include/constants/metatile_behaviors.h: %s" % " ".join(missing))
        return 1
    repo_layouts = json.loads(hi.read(hi.REPO / "data/layouts/layouts.json"))["layouts"]
    groups = json.loads(hi.read(hi.REPO / "data/maps/map_groups.json"))
    try:
        fixed = fix_old_attributes(em, beh)
        added = add_entrances(em, beh, repo_layouts)
        import_bases(em, beh, repo_layouts, groups)
    except hi.Refused:
        pass
    if hi.REFUSALS:
        print("REFUSED, nothing written:\n  " + "\n  ".join(hi.REFUSALS))
        return 1
    todo = hi.changes()
    print("%d metatile behaviors fixed, %d entrances added, %d files to write" % (fixed, added, len(todo)))
    for p in sorted(todo):
        print("  " + p.relative_to(hi.REPO).as_posix())
    if not args.dry_run:
        for p, data in todo.items():
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_bytes(data)
    return 0


if __name__ == "__main__":
    sys.exit(main())
