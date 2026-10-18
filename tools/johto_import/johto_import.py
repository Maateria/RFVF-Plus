#!/usr/bin/env python3
"""Import Johto from a local PokemonHnS clone (github.com/PokemonHnS-Development/pokehns-expansion, ../pokehns) into RFVF+.

Usage, from the repo root (Git Bash or PowerShell), after tools/johto_import/johto_sprites.py and johto_music.py:
    uv run --no-project --with pillow python tools/johto_import/johto_import.py [--hns ../pokehns] [--dry-run]
        [--no-render] [--render DIR]
Credits: Pokemon Heart and Soul (HnS team) and the authors of its maps, tilesets and sprites (CREDITS_JOHTO.md).

One run makes every Johto file again from HnS and tools/johto_import/johto_decisions.py (edit the decisions, not the
outputs): the maps, their layouts and tilesets, the script stubs, the wild encounters, the item flags, the Pokemon
Centers' heal locations, the door table. Johto = the maps of johto_decisions.GROUPS the player reaches from New Bark Town
(warps, connections, script warps) without going through HnS's Kanto and extras (johto_decisions.OUTSIDE).

Like tools/hoenn_import, "complete except scripts": NPCs and signs are placed silent (stub labels in each map's
scripts.inc), trainers are silent NPCs, story objects (a flag HnS's story toggles) come later with their scripts. Item
balls, hidden items and field-move obstacles work (their flags: extended event flags, allocated append-only in
johto_flags.json: SAVED, never renumber), Pokemon Center nurses heal and set the respawn point.

HnS is pokeemerald-expansion built for FRLG-sized tilesets: its Johto tilesets have FRLG's sizes (primary 640 tiles,
640 metatiles, palettes 0-6; secondary 384) and are copied as they are, palettes 00-15 only (no day/night here: its
night and light palettes are left out). Metatile attributes are u16 Emerald-style: converted to this repo's u32 by
behavior NAME (tools/hoenn_import Behaviors, with BEHAVIORS below). A render check compares every map drawn here with
HnS's (the same pixels, as layers and palettes must match).

Generated shared parts sit between "BEGIN/END johto_import" comment lines; the rest of those files is left alone.
"""
import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "hoenn_import"))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import hoenn_import as hi  # noqa: E402  the file plan (PENDING), refusals, behaviors, render
from hoenn_import import REPO, read, read_bytes, write, put, exists, copy, read_ints, write_ints, refuse  # noqa: E402
import johto_decisions as jd  # noqa: E402

MARK = "johto_import"
FLAGS_JSON = REPO / "tools/johto_import/johto_flags.json"
FIRST_FLAG = 0x100  # Johto's flags: EXT_EVENT_FLAGS_START + 0x100.. (0x00-0xFF: Hoenn's events)
MAX_FLAG = 0x7FF
GFX = "OBJ_EVENT_GFX_JOHTO_"
TEMP_FLAG = re.compile(r"FLAG_TEMP_\w+$")
# HnS behaviors (MB_HEADBUTT_TREE, MB_SIDEWAYS_STAIRS_*, MB_TALL_GRASS_IMPASSABLE_NORTH) are this repo's under the same
# names (include/constants/metatile_behaviors.h). Same meaning under another name here:
SAME_MEANING = {
    "MB_CAVE_IMPASSABLE_NORTH": "MB_IMPASSABLE_NORTH",  # its encounters: FRLG keeps them in the attribute, not the behavior
    "MB_BOOKSHELF_GREEN": "MB_BOOKSHELF",  # FRLG's flavor texts
    "MB_SHOP_SHELF_DEPARTMENT": "MB_POKEMART_SHELF",
    "MB_SHOP_SHELF_DEPARTMENT_FORWARD": "MB_POKEMART_SHELF",
}
# HnS behaviors with no use on a map here (furniture of Emerald systems, HnS leftovers): MB_NORMAL, listed
BEHAVIORS_NO_COUNTERPART = {
    "MB_CAVE_IMPASSABLE_NORTH_UNUSED": "", "MB_UNUSED_BRIDGE": "unused in HnS's engine too",
    "MB_UNUSED_88": "unused", "MB_UNUSED_9E": "unused", "MB_UNUSED_6F": "unused", "MB_UNUSED_CE": "unused",
    "MB_UNUSED_D9": "unused", "MB_UNUSED_DA": "unused", "MB_UNUSED_DC": "unused", "MB_UNUSED_DD": "unused",
    "MB_UNUSED_DF": "unused", "MB_UNUSED_04": "unused", "MB_BOOKSHELF_GREEN": "furniture (no text yet)",
    "MB_SHOP_SHELF_DEPARTMENT": "furniture (no text yet)", "MB_SHOP_SHELF_DEPARTMENT_FORWARD": "furniture (no text yet)",
    "MB_FOOTPRINTS": "desert footprints",
}
# HnS behaviors that hoenn_import's tables do not have: the nearest one here (listed)
BEHAVIORS_DEGRADED = {
    "MB_WATER_NORTH_ARROW_WARP": "MB_OCEAN_WATER",  # like MB_WATER_SOUTH_ARROW_WARP (hoenn_import.DEGRADED): sea
}


# ---------------------------------------------------------------- HnS, read once

def hns_name_here(hname):
    return re.sub(r"_[hH]ns$", "", hname)


def labels_of(text):
    """{label: body} of an assembly script file (bodies up to the next label)."""
    parts = re.split(r"^(\w+)::?[ \t]*(?:@.*)?$", text, flags=re.M)
    return dict(zip(parts[1::2], parts[2::2]))


class HnS:
    def __init__(self, root):
        self.root = root
        self.groups = json.loads(read(root / "data/maps/map_groups.json"))
        self.group_of = {m: g for g in self.groups["group_order"] for m in self.groups[g] if g != "group_order"}
        self.maps = {m: json.loads(read(root / "data/maps" / m / "map.json")) for m in self.group_of}
        self.by_id = {j["id"]: m for m, j in self.maps.items()}
        self.layouts = {l["id"]: l for l in json.loads(read(root / "data/layouts/layouts.json"))["layouts"] if "id" in l}
        self.scripts = {m: read(root / "data/maps" / m / "scripts.inc") if exists(root / "data/maps" / m / "scripts.inc")
                        else "" for m in self.maps}
        self.bodies = {}
        for m, text in self.scripts.items():
            self.bodies.update(labels_of(text))
        for p in sorted((root / "data/scripts").glob("*.inc")):
            self.bodies.update(labels_of(read(p)))
        self.behaviors = hi.Behaviors(root)  # HnS's enum and sTileBitAttributes have Emerald's format
        self.species = set(re.findall(r"#define SPECIES_(\w+)\s", read(root / "include/constants/species.h")))
        self.heal = json.loads(read(root / "src/data/heal_locations.json"))["heal_locations"]

    def found_item(self, label):
        m = re.match(r"\s*finditem\s+(ITEM_\w+)\s*\n\s*end\b", self.bodies.get(label, ""))
        return m.group(1) if m else None

    def script_warps(self, hname):
        return set(re.findall(r"\bwarp\w*\s+(MAP_\w+)", self.scripts[hname]))


def select(hns):
    """Johto's maps: HnS names in HnS's group order, and why the others of GROUPS are left out."""
    outside = re.compile("|".join("(?:%s)$" % p for p in jd.OUTSIDE))
    pool = {m for g in jd.GROUPS for m in hns.groups[g]}
    seen, todo = set(), [jd.START]
    while todo:
        m = todo.pop()
        if m in seen or m not in pool or outside.match(m):
            continue
        seen.add(m)
        j = hns.maps[m]
        dests = {w["dest_map"] for w in j.get("warp_events") or []} | {c["map"] for c in j.get("connections") or []}
        dests |= hns.script_warps(m)
        todo += [hns.by_id[d] for d in dests if d in hns.by_id]
    order = [m for g in jd.GROUPS for m in hns.groups[g] if m in seen]
    unreached = sorted(m for m in pool - seen if not outside.match(m))
    return order, unreached


# ---------------------------------------------------------------- names here

class JMap:
    def __init__(self, hns, hname, here_names, here_ids):
        self.hname, self.json = hname, hns.maps[hname]
        base = jd.RENAMES.get(hname, hns_name_here(hname))
        self.name = base if base not in here_names else "Johto" + base
        hid = re.sub(r"_HNS$", "", self.json["id"]) if hname not in jd.RENAMES else "MAP_" + hi.snake(base)
        self.id = hid if hid not in here_ids else "MAP_JOHTO_" + hid[4:]
        self.group = jd.GROUPS[hns.group_of[hname]]
        self.hlayout = hns.layouts[self.json["layout"]]
        self.objects, self.warps, self.bg, self.coord = [], [], [], []
        self.dropped, self.stubs, self.scripts, self.localids, self.map_scripts = [], [], [], [], []


def taken_names():
    """Map names and MAP_ ids of this repo that are not Johto's (what a Johto map must not take)."""
    groups = json.loads(read(REPO / "data/maps/map_groups.json"))
    johto = {m for g in jd.GROUPS.values() for m in groups.get(g, [])}
    names = {p.parent.name for p in (REPO / "data/maps").glob("*/map.json")} - johto
    ids = {json.loads(read(REPO / "data/maps" / n / "map.json"))["id"] for n in names}
    return names, ids


# ---------------------------------------------------------------- tilesets

class JTileset:
    def __init__(self, hns, symbol):
        self.hsymbol = symbol
        fields, self.src = hi.em_tileset(hns.root, symbol)
        self.secondary = fields["isSecondary"] == "TRUE"
        self.kind = "secondary" if self.secondary else "primary"
        base = re.sub(r"_Hns$", "", symbol[len("gTileset_"):]).replace("_", "")
        self.name = base if base.startswith("Johto") else "Johto" + base
        self.symbol = "gTileset_" + self.name
        self.dir = "data/tilesets/%s/%s" % (self.kind, hi.snake(self.name).lower())
        self.hcallback = fields.get("callback", "NULL")
        self.meta = read_ints(self.src / "metatiles.bin", "H")
        self.hattrs = read_ints(self.src / "metatile_attributes.bin", "H")
        png = hi.open_png(self.src / "tiles.png")
        if png.mode != "P" or png.width % 8 or png.height % 8 or len(self.meta) != 8 * len(self.hattrs):
            refuse("%s: unexpected tileset files in %s" % (symbol, self.src), fatal=True)
        self.png_tiles = png.width // 8 * (png.height // 8)
        limit_mt, limit_t = (hi.SEC_MAX, hi.TOTAL - hi.FR["tiles"]) if self.secondary else (hi.FR["metatiles"], hi.FR["tiles"])
        if len(self.hattrs) > limit_mt:
            refuse("%s has %d metatiles (max %d)" % (symbol, len(self.hattrs), limit_mt))
        base_tile = hi.FR["tiles"] if self.secondary else 0
        used = {e & 0x3FF for e in self.meta}
        top = max(used) if used else 0
        self.num_tiles = self.png_tiles
        # metatiles naming a tile its sheet does not have (HnS leftovers: VRAM garbage in game): fine if no map shows one
        beyond = lambda t: t >= hi.TOTAL or (base_tile <= t >= base_tile + self.png_tiles if self.secondary
                                              else hi.FR["tiles"] > t >= self.png_tiles)
        self.junk = {i // 8 for i, e in enumerate(self.meta) if beyond(e & 0x3FF)}
        if self.png_tiles > limit_t:  # Mahogany Gym's sheet is longer than a secondary: its metatiles stop before
            self.num_tiles = limit_t
        self.door_tiles = sorted(t for t in used if self.secondary and t >= hi.TOTAL - 8)
        self.layer3 = [i for i, a in enumerate(self.hattrs) if a >> 12 == 3]
        self.attrs = None

    def convert(self, behaviors, placed, report):
        """This repo's u32 attributes; `placed` = metatile indexes of this tileset a Johto map shows."""
        for i in sorted(self.junk & placed):  # copied as they are: the same VRAM leftovers as in HnS
            report["notes"].append("%s metatile %d (on a map) names a tile beyond its tiles.png, as in HnS"
                                   % (self.name, i))
        out = []
        for i, a in enumerate(self.hattrs):
            clean = a & 0x30FF  # bits 8-11 are unused in HnS's format (HnS's engine reads behavior & 0xFF)
            bad = a >> 12 == 3 or a & 0xFF >= len(behaviors.em_names)
            if a >> 12 == 3:  # no such layer type: drawn as NORMAL (HnS's DrawMetatile has no case for it either)
                clean &= 0x00FF
            if clean & 0xFF >= len(behaviors.em_names):  # no such behavior: HnS leftovers
                clean &= 0x3000
            if bad and i in placed:
                refuse("%s metatile %d (on a map): attribute 0x%04X is not a valid one" % (self.hsymbol, i, a))
            out.append(behaviors.convert(clean))
        self.attrs = out

    def write(self):
        dst = REPO / self.dir
        copy(self.src / "tiles.png", dst / "tiles.png")
        for i in range(16):
            src = self.src / ("palettes/%02d.pal" % i)
            if exists(src):
                copy(src, dst / ("palettes/%02d.pal" % i))
            else:
                hi.write(dst / ("palettes/%02d.pal" % i), "JASC-PAL\r\n0100\r\n16\r\n" + "0 0 0\r\n" * 16)
        write_ints(dst / "metatiles.bin", "H", self.meta)
        write_ints(dst / "metatile_attributes.bin", "I", self.attrs)

    def callback(self, anims_here):
        return self.hcallback if self.hcallback in anims_here else "NULL"


def anims_here():
    """InitTilesetAnim_ functions src/tileset_anims.c defines itself."""
    return set(re.findall(r"^void (InitTilesetAnim_\w+)\(void\)", read(REPO / "src/tileset_anims.c"), re.M))


def plan_anims(ctx, tilesets):
    """src/data/tilesets/johto_anims.h (included at the end of src/tileset_anims.c): PokemonHnS's tile animations of the
    Johto tilesets (its src/tileset_anims.c: each InitTilesetAnim_ a Johto tileset names, with the functions and frames
    it uses), frame paths moved to this repo's folders, HnS's sSecondaryTilesetBaseTile = NUM_TILES_IN_PRIMARY (FRLG
    sizes). Returns the InitTilesetAnim_ names it defines."""
    text = read(ctx.hns.root / "src/tileset_anims.c")
    items = {}
    for m in re.finditer(r"^(?:static )?const u16 (\w+)\[\] = INCBIN_U16\([^;]*;\n", text, re.M):
        items[m.group(1)] = m.group(0)
    for m in re.finditer(r"^(?:static )?const u16 \*const (\w+)\[\] = \{.*?^\};\n", text, re.M | re.S):
        items[m.group(1)] = m.group(0)
    for m in re.finditer(r"^((?:static )?void (\w+)\([^)]*\))\n\{.*?^\}\n", text, re.M | re.S):
        items[m.group(2)] = m.group(0)
    # this repo's own helpers (AppendTilesetAnimToBuffer...) are used as they are
    here_defs = set(re.findall(r"^(?:static )?(?:const )?\w+ \**(?:const )?(\w+)(?:\[\]|\()", read(REPO / "src/tileset_anims.c"), re.M))
    needed = sorted({ts.hcallback for ts in tilesets.values()} & set(items))
    clash = [n for n in needed if n in here_defs]
    if clash:
        refuse("tile animations: %s already exist in src/tileset_anims.c" % ", ".join(clash))
    order, todo = [], list(needed)
    while todo:
        name = todo.pop(0)
        if name in order or name in here_defs:
            continue
        order.append(name)
        todo += [n for n in re.findall(r"\b(\w+)\b", items[name]) if n in items and n != name and n not in order]
    frames = [n for n in order if "INCBIN_U16" in items[n]]
    body = "".join(items[n] for n in sorted(frames)) + "\n"
    body += "".join(items[n] + "\n" for n in order if n not in frames and not items[n].startswith(("static void", "void")))
    body += "".join(re.match(r"(static void \w+\([^)]*\))", items[n]).group(1) + ";\n" for n in order
                    if items[n].startswith("static void"))
    body += "\n" + "".join(items[n] + "\n" for n in order if items[n].startswith(("static void", "void")))
    for ts in tilesets.values():
        body = body.replace(ts.src.relative_to(ctx.hns.root).as_posix() + "/", ts.dir + "/")
    # frames of a tileset that is not Johto's (Blackthorn Gym's lava is Emerald's Lavaridge lava): copied under johto_anim/
    for path in sorted(set(re.findall(r'INCBIN_U16\("(data/tilesets/(?!primary/johto_|secondary/johto_)[^"]+)\.4bpp"\)', body))):
        here = "data/tilesets/johto_anim/" + path[len("data/tilesets/"):]
        copy(ctx.hns.root / (path + ".png"), REPO / (here + ".png"))
        body = body.replace('"%s.4bpp"' % path, '"%s.4bpp"' % here)
    body = body.replace("sSecondaryTilesetBaseTile", "NUM_TILES_IN_PRIMARY")
    hi.write(REPO / "src/data/tilesets/johto_anims.h",
             "// Generated by tools/johto_import (plan_anims): PokemonHnS's tile animations of Johto's tilesets. Do not edit.\n"
             '#include "fieldmap.h"\n\n' + body)
    inits = [n for n in order if n.startswith("InitTilesetAnim_")]
    block(REPO / "include/tileset_anims.h", "//", "".join("void %s(void);\n" % n for n in inits),
          before=r"^#endif")
    hi.append_once(REPO / "src/tileset_anims.c", '"data/tilesets/johto_anims.h"',
                   "// Generated: PokemonHnS's tile animations of the Johto tilesets (tools/johto_import plan_anims)\n"
                   '#include "data/tilesets/johto_anims.h"\n')
    return set(inits)


# ---------------------------------------------------------------- behaviors

class Behaviors(hi.Behaviors):
    """hoenn_import's conversion by name, with this point's engine behaviors and HnS's leftovers."""

    def __init__(self, root):
        super().__init__(root)
        # HnS puts MB_UNUSED_6F (surfable in its table, as in Emerald's) on walls of buildings: never water here
        self.em_surfable -= set(BEHAVIORS_NO_COUNTERPART)

    def fr_name(self, name):
        if name in self.fr_values and name not in hi.BEHAVIOR_OVERRIDES and name not in hi.DEGRADED:
            return name, None
        if name in SAME_MEANING:
            return SAME_MEANING[name], None
        if name in BEHAVIORS_NO_COUNTERPART:
            return "MB_NORMAL", "no counterpart here: %s" % (BEHAVIORS_NO_COUNTERPART[name] or "unused")
        if name in BEHAVIORS_DEGRADED:
            return BEHAVIORS_DEGRADED[name], "DEGRADED"
        return super().fr_name(name)


# ---------------------------------------------------------------- flags (saved: append-only)

class Flags:
    def __init__(self):
        self.table = json.loads(read(FLAGS_JSON)) if exists(FLAGS_JSON) else {}
        self.used = set()

    def get(self, hflag, where):
        """This repo's flag for HnS's `hflag` (an item ball's, a hidden item's, an obstacle's): a FLAG_TEMP_ stays, any
        other gets an extended event flag (johto_flags.json keeps its number)."""
        if hflag in ("0", 0, None):
            return "0"
        if TEMP_FLAG.match(hflag):
            return hflag
        name = hflag if not hi.defined(hflag) or hflag in self.table else "FLAG_JOHTO_" + hflag[len("FLAG_"):]
        if name not in self.table:
            if hi.defined(name) and name not in self.table:
                refuse("%s (%s): already a flag of this repo" % (name, where))
            free = FIRST_FLAG + len(self.table)
            if free > MAX_FLAG:
                refuse("no Johto flag left for %s" % name)
            self.table[name] = free
        self.used.add(name)
        return name

    def write(self):
        hi.write(FLAGS_JSON, json.dumps(dict(sorted(self.table.items(), key=lambda kv: kv[1])), indent=1) + "\n")
        lines = "".join("#define %-48s (EXT_EVENT_FLAGS_START + 0x%03X)\n" % (n, v)
                        for n, v in sorted(self.table.items(), key=lambda kv: kv[1]))
        block(REPO / "include/constants/flags.h", "//", "// Johto's item balls, hidden items and obstacles "
              "(johto_flags.json: saved, never renumber)\n" + lines,
              before=r"^#endif // GUARD_CONSTANTS_FLAGS_H")


# ---------------------------------------------------------------- shared files: generated blocks

def block(path, comment, body, before=None, after=None):
    """`body` between "BEGIN/END johto_import" comment lines in `path`: replaces the block, else it goes before the
    first line matching the regex `before` (or after the last one matching `after`, or at the end)."""
    text = read(path).replace("\r\n", "\n")
    begin, end = "%s BEGIN %s\n" % (comment, MARK), "%s END %s\n" % (comment, MARK)
    content = begin + body + ("" if body.endswith("\n") else "\n") + end
    if begin in text:
        a = text.index(begin)
        b = text.index(end, a) + len(end)
        text = text[:a] + content + text[b:]
    elif before and re.search(before, text, re.M):
        pos = re.search(before, text, re.M).start()
        text = text[:pos] + content + text[pos:]
    elif after:
        pos = list(re.finditer(after, text, re.M))[-1].end()
        text = text[:pos] + content + text[pos:]
    else:
        text = text + ("" if text.endswith("\n") else "\n") + content
    hi.write(path, text)


# ---------------------------------------------------------------- objects, events, warps

def item_here(hitem, where, report):
    """This repo's item for HnS's `hitem` (johto_decisions.ITEMS, a TM / HM by its move), None to leave it out."""
    if hitem in jd.ITEMS:
        sub = jd.ITEMS[hitem]
        report["items"][(hitem, sub)] += 1
        if sub and not hi.defined(sub):
            refuse("johto_decisions.ITEMS: %s does not exist here" % sub)
        return sub
    here = hi.item_here(hitem)
    if not here:
        refuse("%s: item %s does not exist here: give it a substitute in johto_decisions.ITEMS" % (where, hitem))
    return here


def sprite_here(hgfx):
    """This repo's graphics id for HnS's `hgfx`: a Pokemon this repo has a sprite of keeps it, any other is the one
    johto_sprites.py imported (OBJ_EVENT_GFX_JOHTO_X); None if missing."""
    mon = re.fullmatch(r"OBJ_EVENT_GFX_MON_BASE\s*\+\s*SPECIES_(\w+)", hgfx)
    if mon:
        for cand in ("OBJ_EVENT_GFX_" + mon.group(1), "OBJ_EVENT_GFX_HOENN_" + mon.group(1), GFX + "MON_" + mon.group(1)):
            if hi.defined(cand):
                return cand
        return None
    gfx = GFX + re.sub(r"_HNS$", "", hgfx[len("OBJ_EVENT_GFX_"):])
    if hi.defined(gfx):
        return gfx
    return hgfx if hi.defined(hgfx) and not hgfx.endswith("_HNS") else None


def needed_sprites(hns, maps):
    """HnS graphics ids the kept objects of `maps` show (for johto_sprites.py)."""
    out = set()
    for m in maps:
        for o in hns.maps[m.hname]["object_events"]:
            if keep_reason(hns, o, m.hname)[0] is not None:
                out.add(o["graphics_id"])
    return out


CRY_ONLY = re.compile(r"\s*lock\s+faceplayer\s+(?:waitse\s+)?playmoncry\s+SPECIES_\w+,\s*CRY_MODE_NORMAL\s+"
                      r"msgbox\s+\w+,\s*MSGBOX_DEFAULT\s+waitmoncry\s+release\s+end\s*$")


def pokemon_of(hns, gfx):
    """The species an HnS object sprite is (its follower sprite, or a Pokemon's own graphics), else None."""
    m = re.search(r"SPECIES_(\w+)", gfx)
    name = m.group(1) if m else re.sub(r"^(?:SWIMMING|NO_TAIL)_|_HNS$", "", gfx[len("OBJ_EVENT_GFX_"):])
    return name if m or name in hns.species else None


def decorative(hns, o, hname):
    """An HnS decorative Pokemon (johto_decisions.POKEMON_KEPT): no story flag, a script that is none or its cry and one
    line, no person next to it, not kept by name."""
    species, script = pokemon_of(hns, o["graphics_id"]), o.get("script", "0x0")
    if not species or (hname, species) in jd.POKEMON_KEPT:
        return False
    if script not in ("0x0", "0", "NULL", "") and not CRY_ONLY.match(hns.bodies.get(script, "")):
        return False
    for p in hns.maps[hname]["object_events"]:
        s = p.get("script", "0x0")
        if (max(abs(p["x"] - o["x"]), abs(p["y"] - o["y"])) == 1 and not pokemon_of(hns, p["graphics_id"])
                and s not in ("0x0", "0", "NULL", "") and not hns.found_item(s) and s not in jd.OBSTACLE_SCRIPTS):
            return False  # its trainer's
    return True


def keep_reason(hns, o, hname):
    """(kind, why): kind None = left out (why), else "item", "obstacle", "npc"."""
    gfx, flag, script = o["graphics_id"], str(o.get("flag", "0")), o.get("script", "0x0")
    if o.get("type", "object") != "object":
        return None, "not an object (clone)"
    if flag in jd.NIGHT_FLAGS:
        return None, "night only (%s)" % flag
    if gfx in jd.LEFT_OUT_GFX:
        return None, "sprite left out (%s)" % gfx
    if re.match(r"OBJ_EVENT_GFX_VAR_", gfx):
        return None, "its map script picks the sprite (story)"
    if hns.found_item(script):
        return "item", None
    if script in jd.OBSTACLE_SCRIPTS:
        return "obstacle", None
    if flag not in ("0", "FLAG_NONE"):
        return None, "story object (%s): comes with its script" % flag
    if decorative(hns, o, hname):
        return None, "decorative Pokemon (the other regions have none)"
    return "npc", None


def stub_label(m, hlabel):
    """The label here of HnS's script `hlabel` run by an NPC or sign of map `m`: <Map>_EventScript_<what>."""
    what = hlabel.split("_EventScript_", 1)[1] if "_EventScript_" in hlabel else hlabel
    return "%s_EventScript_%s" % (m.name, what)


def convert_objects(ctx, m, flags, report):
    hns = ctx.hns
    warps = {(w["x"], w["y"]) for w in m.json.get("warp_events") or []}
    kept = []
    for o in m.json["object_events"]:
        where = "%s (%d,%d) %s" % (m.name, o["x"], o["y"], o["graphics_id"])
        kind, why = keep_reason(hns, o, m.hname)
        if kind and (o["x"], o["y"]) in warps:
            kind, why = None, "stands on a warp"
        if not kind:
            m.dropped.append("%s: %s" % (where, why))
            continue
        gfx = sprite_here(o["graphics_id"])
        if not gfx:
            refuse("%s: no sprite here for %s: run tools/johto_import/johto_sprites.py" % (where, o["graphics_id"]))
            continue
        movement = o["movement_type"]
        if not hi.defined(movement):
            if movement in jd.MOVEMENTS:
                report["degraded"][("movement", movement, jd.MOVEMENTS[movement])] += 1
                movement = jd.MOVEMENTS[movement]
            else:
                refuse("%s: unknown movement type %s: give it one in johto_decisions.MOVEMENTS" % (where, movement))
        kept.append((o, kind, gfx, movement))
    # a still NPC must not cut the way to a warp (HnS's scripts move some of them): it is left out
    blocks, width = ctx.blocks[m.hname], m.hlayout["width"]
    still = lambda o, kind, mv: kind == "npc" and not re.search(r"WANDER|WALK(?!_IN_PLACE)|JOG|RUN", mv)
    base = reached_warps(m, blocks, width, set())
    obstacles, objects = set(), []
    for o, kind, gfx, movement in kept:
        pos = (o["x"], o["y"])
        if still(o, kind, movement):
            lost = sorted(base - reached_warps(m, blocks, width, obstacles | {pos}))
            if lost:
                m.dropped.append("%s (%d,%d) %s: blocks the way to warp %s" % (m.name, *pos, o["graphics_id"], lost))
                continue
            obstacles.add(pos)
        n = len(objects) + 1
        script, flag = "0x0", "0"
        hscript = o.get("script", "0x0")
        if kind == "item":
            hitem = hns.found_item(hscript)
            item = item_here(hitem, "%s item ball (%d,%d)" % (m.name, *pos), report)
            if not item:
                m.dropped.append("%s (%d,%d): item %s left out (johto_decisions.ITEMS)" % (m.name, *pos, hitem))
                continue
            flag = flags.get(o["flag"], "%s item ball" % m.name)
            script = "%s_EventScript_Item%d" % (m.name, n)
            m.scripts.append((script, "item ball (%s)" % flag, "\tfinditem %s\n\tend\n" % item))
        elif kind == "obstacle":
            script = jd.OBSTACLE_SCRIPTS[hscript]
            flag = flags.get(o["flag"], "%s %s" % (m.name, hscript))
        elif o["graphics_id"] == "OBJ_EVENT_GFX_NURSE_HNS" and m.name in ctx.pokemon_centers:
            script = "%s_EventScript_Nurse" % m.name
            m.scripts.append((script, "Pokemon Center nurse",
                              "\tlock\n\tfaceplayer\n\tcall EventScript_PkmnCenterNurse\n\trelease\n\tend\n"))
            ctx.nurses[m.name] = n
        elif hscript not in ("0x0", "0", "NULL", ""):
            script = stub_label(m, hscript)
            trainer = re.search(r"\btrainerbattle\w*\s+(TRAINER_\w+)", hns.bodies.get(hscript, ""))
            comment = "%s #%d (%d,%d)%s" % (o["graphics_id"].replace("OBJ_EVENT_GFX_", ""), n, *pos,
                                             ", trainer %s" % trainer.group(1) if trainer else
                                             ", trainer" if o.get("trainer_type", "TRAINER_TYPE_NONE") != "TRAINER_TYPE_NONE" else "")
            if script not in [s for s, _ in m.stubs]:
                m.stubs.append((script, comment))
        if o.get("local_id") and not hi.defined(o["local_id"]):
            m.localids.append((o["local_id"], n))
        objects.append({
            "type": "object", "graphics_id": gfx, "x": o["x"], "y": o["y"], "elevation": o["elevation"],
            "movement_type": movement, "movement_range_x": o["movement_range_x"],
            "movement_range_y": o["movement_range_y"], "trainer_type": "TRAINER_TYPE_NONE",
            "trainer_sight_or_berry_tree_id": "0", "script": script, "flag": flag, "in_connection": False,
        })
        report["gfx"][gfx] += 1
    return objects


def reached_warps(m, blocks, width, blocked):
    warps = [(i, w) for i, w in enumerate(m.json.get("warp_events") or [])
             if 0 <= w["x"] < width and 0 <= w["y"] < len(blocks) // width]
    if not warps:
        return set()
    tiles = hi.walkable_from(blocks, width, (warps[0][1]["x"], warps[0][1]["y"]), blocked)
    return {i for i, w in warps if (w["x"], w["y"]) in tiles or (w["x"], w["y"] + 1) in tiles}


def convert_events(ctx, m, flags, report):
    bg = []
    for b in m.json.get("bg_events") or []:
        if b["type"] == "sign":
            hlabel = b.get("script", "0x0")
            if hlabel in ("0x0", "0", "NULL", ""):
                m.dropped.append("sign (%d,%d): no script" % (b["x"], b["y"]))
                continue
            label = stub_label(m, hlabel)
            if label not in [s for s, _ in m.stubs]:
                m.stubs.append((label, "sign (%d,%d)" % (b["x"], b["y"])))
            bg.append({"type": "sign", "x": b["x"], "y": b["y"], "elevation": b["elevation"],
                       "player_facing_dir": b.get("player_facing_dir", "BG_EVENT_PLAYER_FACING_ANY"), "script": label})
        elif b["type"] == "hidden_item":
            item = item_here(b["item"], "%s hidden item (%d,%d)" % (m.name, b["x"], b["y"]), report)
            if not item:
                m.dropped.append("hidden item (%d,%d) %s left out (johto_decisions.ITEMS)" % (b["x"], b["y"], b["item"]))
                continue
            bg.append({"type": "hidden_item", "x": b["x"], "y": b["y"], "elevation": b["elevation"], "item": item,
                       "flag": flags.get(b["flag"], "%s hidden item" % m.name), "quantity": 1, "underfoot": False})
        else:
            m.dropped.append("%s (%d,%d): not handled" % (b["type"], b["x"], b["y"]))
    for c in m.json.get("coord_events") or []:
        m.dropped.append("trigger (%d,%d) %s==%s -> %s: placed with its script" % (
            c["x"], c["y"], c.get("var"), c.get("var_value"), c.get("script")))
    return bg


def convert_warps(ctx, m, report):
    out = []
    for i, w in enumerate(m.json.get("warp_events") or []):
        dest = jd.WARPS.get((m.hname, i))
        if not dest:
            target = ctx.by_hid.get(w["dest_map"])
            if w["dest_map"] == "MAP_DYNAMIC":
                dest = ("MAP_DYNAMIC", str(w["dest_warp_id"]))
            elif target:
                dest = (target.id, str(w["dest_warp_id"]))
                nwarps = len(target.json.get("warp_events") or [])
                if not 0 <= int(w["dest_warp_id"]) < nwarps:
                    refuse("%s warp %d -> %s #%s: that map has %d warps" % (m.name, i, target.name, w["dest_warp_id"], nwarps))
        if not dest:
            dest = (m.id, str(i))
            report["closed"].append("%s warp %d (%d,%d) -> %s #%s" % (m.name, i, w["x"], w["y"], w["dest_map"], w["dest_warp_id"]))
        out.append({"x": w["x"], "y": w["y"], "elevation": w["elevation"], "dest_map": dest[0], "dest_warp_id": dest[1]})
    return out


def convert_connections(ctx, m):
    out = []
    for c in m.json.get("connections") or []:
        kanto = jd.CONNECTIONS.get((m.hname, c["direction"]))
        target = ctx.by_hid.get(c["map"])
        if target:
            out.append({"direction": c["direction"], "offset": c["offset"], "map": target.id})
        elif kanto and kanto[1] is not None:
            out.append({"direction": c["direction"], "offset": kanto[1], "map": kanto[0]})
    return out or 0


def convert_header(ctx, m, report):
    j = m.json
    music = j["music"]
    if not hi.defined(music):
        refuse("%s: music %s is not defined here: run tools/johto_import/johto_music.py" % (m.name, music))
    mapsec = jd.MAPSECS.get(j["region_map_section"], j["region_map_section"])
    weather = jd.WEATHERS.get(j["weather"], j["weather"])
    if weather != j["weather"]:
        report["degraded"][("weather", j["weather"], weather)] += 1
    for value in (mapsec, weather, j["map_type"], j["battle_scene"]):
        if not hi.defined(value):
            refuse("%s: %s does not exist in this repo" % (m.name, value))
    return {
        "id": m.id, "name": m.name, "layout": ctx.layout_ids[j["layout"]], "music": music,
        "region_map_section": mapsec, "requires_flash": j["requires_flash"], "weather": weather,
        "map_type": j["map_type"], "allow_cycling": j["allow_cycling"], "allow_escaping": j["allow_escaping"],
        "allow_running": j["allow_running"], "show_map_name": j["show_map_name"], "floor_number": 0,
        "battle_scene": j["battle_scene"],
    }


def scripts_inc(m):
    text = "@ %s: generated from PokemonHnS data/maps/%s; scripted maps get their own file later\n" % (MARK, m.hname)
    text += "".join(".equ %s, %d\n" % lid for lid in m.localids) + ("\n" if m.localids else "")
    text += "%s_MapScripts::\n%s\t.byte 0\n\n" % (m.name, "".join("\tmap_script %s\n" % s for s, _ in m.map_scripts))
    text += "".join("%s:\n%s\n" % (label, body) for label, body in (b for _, b in m.map_scripts))
    text += "".join(("%s::" % label).ljust(47) + " @ %s\n%s\n" % (comment, body) for label, comment, body in m.scripts)
    if m.stubs:
        text += "@ silent until scripted (PokemonHnS data/maps/%s/scripts.inc)\n" % m.hname
        text += "".join(("%s::" % label).ljust(47) + " @ %s\n" % comment for label, comment in m.stubs) + "\tend\n"
    return text


# ---------------------------------------------------------------- wild encounters

def plan_encounters(ctx, report):
    """HnS's Day tables of the Johto maps; a species only its Night table has takes a slot (merge_night)."""
    groups = json.loads(read(ctx.hns.root / "src/data/wild_encounters.json"))["wild_encounter_groups"]
    entries = next(g for g in groups if g["label"] == "gWildMonHeaders")["encounters"]
    by_map = defaultdict(dict)
    for e in entries:
        if e["map"] in ctx.by_hid:
            by_map[e["map"]][e["base_label"].rsplit("_", 1)[-1]] = e
    tables, headers = [], []
    for hid, m in ctx.by_hid.items():
        if hid not in by_map:
            continue
        day, night = by_map[hid].get("Day"), by_map[hid].get("Night")
        if not day:
            day, night = night, None
        fields = ""
        for key, suffix, field in hi.ENCOUNTER_TYPES:
            info = day.get(key)
            label = "g%s_%s" % (m.name, suffix)
            if info:
                mons = [dict(x) for x in info["mons"]]
                if night and night.get(key):
                    merge_night(mons, night[key]["mons"], "%s %s" % (m.name, key), report)
                for x in mons:
                    if x["species"] in jd.SPECIES:
                        report["species"][(x["species"], jd.SPECIES[x["species"]])] += 1
                        x["species"] = jd.SPECIES[x["species"]]
                    if not hi.defined(x["species"]):
                        refuse("%s: wild %s does not exist here: give it a substitute in johto_decisions.SPECIES"
                               % (m.name, x["species"]))
                tables.append("const struct WildPokemon %s[] =\n{\n%s};\n\nconst struct WildPokemonInfo %sInfo = { %d, %s };\n\n"
                              % (label, "".join("    { %d, %d, %s },\n" % (x["min_level"], x["max_level"], x["species"])
                                                for x in mons), label, info["encounter_rate"], label))
            fields += "".join("        .%s_%s = %s,\n" % (field, v, "&%sInfo" % label if info else "NULL") for v in ("FR", "LG"))
        headers.append("    {\n        .mapGroup = MAP_GROUP(%s),\n        .mapNum = MAP_NUM(%s),\n%s    },\n"
                       % (m.id[4:], m.id[4:], fields))
    block(hi.ENCOUNTERS, "//", "".join(tables), before=r"^const struct WildPokemonHeader gWildMonHeaders\[\]")
    text = read(hi.ENCOUNTERS)
    term = re.search(r"^(?:[ \t]*//.*\n)*[ \t]*\{\s*\.mapGroup = MAP_GROUP\(UNDEFINED\)", text.replace("\r\n", "\n"), re.M)
    hdr_begin = "    // BEGIN %s headers\n" % MARK
    hdr_end = "    // END %s headers\n" % MARK
    t = text.replace("\r\n", "\n")
    if hdr_begin in t:
        a, b = t.index(hdr_begin), t.index(hdr_end) + len(hdr_end)
        t = t[:a] + hdr_begin + "".join(headers) + hdr_end + t[b:]
    else:
        t = t[:term.start()] + hdr_begin + "".join(headers) + hdr_end + t[term.start():]
    hi.write(hi.ENCOUNTERS, t)
    report["encounters"] = len(headers)


def merge_night(mons, night, where, report):
    """A species of the night table that the day table lacks takes the slot it has at night, unless that slot's day
    species would vanish: then the latest slot whose day species another slot keeps."""
    have = Counter(x["species"] for x in mons)
    for i, n in enumerate(night):
        s = n["species"]
        if s in have or i >= len(mons):
            continue
        slot = i if have[mons[i]["species"]] > 1 else next(
            (k for k in range(len(mons) - 1, -1, -1) if have[mons[k]["species"]] > 1), None)
        if slot is None:
            report["night_lost"].append("%s: %s (no slot to spare)" % (where, s))
            continue
        have[mons[slot]["species"]] -= 1
        report["night"].append("%s: %s replaces %s in slot %d" % (where, s, mons[slot]["species"], slot))
        mons[slot] = dict(mons[slot], species=s)
        have[s] += 1


# ---------------------------------------------------------------- heal locations (Pokemon Centers, Fly)

def plan_heal_locations(ctx, report):
    consts, rows = [], [[], [], []]
    text = read(hi.HEAL_CONSTANTS)
    plain = re.sub(r"// BEGIN %s.*?// END %s\n" % (MARK, MARK), "", text.replace("\r\n", "\n"), flags=re.S)
    first = max(int(v) for v in re.findall(r"^#define SPAWN_\w+ (\d+)", plain, re.M)) + 1
    for h in ctx.heal:
        town = re.sub(r"_HNS$", "", h["id"][len("HEAL_LOCATION_"):])
        spawn = "SPAWN_" + town
        if re.search(r"^#define %s\b" % spawn, plain, re.M):
            refuse("%s already exists here" % spawn)
        m, pc = ctx.by_hid[h["map"]], ctx.by_hid[h["respawn_map"]]
        value = first + len(consts)
        consts.append("#define %s %d\n" % (spawn, value))
        rows[0].append("    [%s - 1] = {MAP_GROUP(%s), MAP_NUM(%s), %d, %d},\n" % (spawn, m.id[4:], m.id[4:], h["x"], h["y"]))
        rows[1].append("    [%s - 1] = {MAP_GROUP(%s), MAP_NUM(%s)},\n" % (spawn, pc.id[4:], pc.id[4:]))
        rows[2].append("    [%s - 1] = %d,\n" % (spawn, ctx.nurses.get(pc.name, 0)))
        report["heal"].append("%s = %d: %s (%d,%d), whiteout in %s (nurse #%d)" % (
            spawn, value, m.name, h["x"], h["y"], pc.name, ctx.nurses.get(pc.name, 0)))
    block(hi.HEAL_CONSTANTS, "//", "".join(consts), after=r"^#define SPAWN_\w+ \d+\n")
    data = read(hi.HEAL_DATA).replace("\r\n", "\n")
    for name, lines in zip(hi.HEAL_TABLES, rows):
        begin, end = "    // BEGIN %s %s\n" % (MARK, name), "    // END %s %s\n" % (MARK, name)
        if begin in data:
            a, b = data.index(begin), data.index(end) + len(end)
            data = data[:a] + begin + "".join(lines) + end + data[b:]
        else:
            close = data.index("};", data.index(name))
            data = data[:close] + begin + "".join(lines) + end + data[close:]
    hi.write(hi.HEAL_DATA, data)


# ---------------------------------------------------------------- door animations

def plan_doors(ctx, report):
    """src/data/johto_doors.h: PokemonHnS's door animations of the Johto tilesets (its sDoorAnimGraphicsTable, IS_HNS
    part): metatile id, tileset (Johto towns share door ids: src/field_door.c matches both), sound, graphics copied to
    graphics/door_anims/johto/, palette slots unchanged (the tilesets are HnS's)."""
    text = read(ctx.hns.root / "src/field_door.c")
    part = text[text.index("sDoorAnimGraphicsTable[]"):]
    part = part[part.index("#elif IS_HNS"):part.index("#endif", part.index("#elif IS_HNS"))]
    files = dict(re.findall(r'static const u8 (sDoorAnimTiles_\w+)\[\] = INCBIN_U8\("([^"]+)"\);', text))
    pals = dict(re.findall(r"static const u8 (sDoorAnimPalettes_\w+)\[\] = \{([^}]*)\};", text))
    labels = {n: int(v, 16) for n, v in re.findall(r"#define (METATILE_\w+)\s+(0x[0-9A-Fa-f]+)",
                                                    read(ctx.hns.root / "include/constants/metatile_labels.h"))}
    here = lambda s: "%s_Johto%s" % (s.split("_", 1)[0], re.sub(r"^Johto", "", s.split("_", 1)[1]))
    rows, used_tiles, used_pals, seen = [], {}, {}, set()
    for label, ts, sound, size, tiles, palettes in re.findall(
            r"\{\s*(METATILE_\w+|0x[0-9A-Fa-f]+)\s*,\s*&(gTileset_\w+)\s*,\s*(DOOR_SOUND_\w+)\s*,\s*(\d)\s*,\s*(\w+)\s*,\s*(\w+)\s*\}",
            part):
        if ts not in ctx.tilesets:
            continue
        mid = labels[label] if label in labels else int(label, 16)
        if (mid, ts) in seen:  # the first entry wins, as HnS's lookup does
            continue
        seen.add((mid, ts))
        if size != "1" or sound not in ("DOOR_SOUND_NORMAL", "DOOR_SOUND_SLIDING"):
            report["notes"].append("door 0x%03X of %s (%s, size %s): not animated here" % (mid, ctx.tilesets[ts].name, tiles, size))
            continue
        png = "graphics/door_anims/johto/%s.png" % Path(files[tiles]).stem
        if png not in used_tiles.values():
            copy(ctx.hns.root / Path(files[tiles]).with_suffix(".png"), REPO / png)
        used_tiles[here(tiles)] = png
        used_pals[here(palettes)] = pals[palettes].strip()
        # HnS's size 1 on its FRLG-sized layouts = one metatile (3 frames of 16x16), not Emerald's 16x32
        rows.append("    {0x%03X, %-19s DOOR_SIZE_1x1, %s, %s}, // %s\n" % (mid, sound + ",", here(tiles), here(palettes), label))
        ctx.door_tilesets.append(ctx.tilesets[ts].symbol)
    hi.write(REPO / "src/data/johto_doors.h", "".join([
        "// Generated by tools/johto_import (plan_doors): PokemonHnS's door animations of Johto's tilesets. Do not edit.\n\n",
        "".join("extern const struct Tileset %s;\n" % s for s in sorted(set(ctx.door_tilesets))), "\n",
        "".join('static const u8 %s[] = INCBIN_U8("%s");\n' % (n, p[:-4] + ".4bpp") for n, p in sorted(used_tiles.items())), "\n",
        "".join("static const u8 %s[] = {%s};\n" % (n, v) for n, v in sorted(used_pals.items())), "\n",
        "// Matched on metatile id AND tileset (sDoorTilesets_Johto): Johto towns use one id for different doors\n",
        "static const struct DoorGraphics sDoorGraphics_Johto[] = {\n", "".join(rows), "    {}\n};\n\n",
        "static const struct Tileset *const sDoorTilesets_Johto[] = {\n",
        "".join("    &%s,\n" % s for s in ctx.door_tilesets), "};\n"]))
    report["doors"] = len(rows)


# ---------------------------------------------------------------- the Kanto border

def plan_kanto_border(ctx, report):
    """The Kanto warps johto_decisions.KANTO_WARPS points into Johto (their map.json, only those destinations)."""
    for (name, i), (dest, dest_id) in sorted(jd.KANTO_WARPS.items()):
        path = REPO / "data/maps" / name / "map.json"
        mj = json.loads(read(path))
        w = mj["warp_events"][i]
        if (w["dest_map"], str(w["dest_warp_id"])) != (dest, dest_id):
            report["notes"].append("Kanto: %s warp %d -> %s #%s (was %s #%s)" % (name, i, dest, dest_id, w["dest_map"],
                                                                             w["dest_warp_id"]))
            w["dest_map"], w["dest_warp_id"] = dest, dest_id
            hi.write_json(path, mj)


# ---------------------------------------------------------------- the run

def plan(ctx, report):
    hns = ctx.hns
    flags = Flags()
    # layouts and tilesets
    repo_layouts = json.loads(read(REPO / "data/layouts/layouts.json"))
    ours_before = {l["id"] for l in repo_layouts["layouts"] if l and l.get("primary_tileset", "").startswith("gTileset_Johto")}
    taken_layouts = {l["id"] for l in repo_layouts["layouts"] if l and l["id"] not in ours_before}
    taken_dirs = {Path(l["blockdata_filepath"]).parent.name for l in repo_layouts["layouts"] if l and l["id"] not in ours_before}
    tilesets, placed = {}, defaultdict(set)
    ctx.layout_ids, layouts_out = {}, []
    for m in ctx.maps:
        hl = m.hlayout
        blocks = read_ints(hns.root / hl["blockdata_filepath"], "H")
        for (x, y), v in jd.BLOCK_PATCHES.get(m.hname, {}).items():
            blocks[y * hl["width"] + x] = v
        border = read_ints(hns.root / hl["border_filepath"], "H")
        ctx.blocks[m.hname] = blocks
        if len(blocks) != hl["width"] * hl["height"] or len(border) != 4:
            refuse("%s: layout sizes (%d blocks, border %d)" % (m.name, len(blocks), len(border)))
        if (hl["width"] + 15) * (hl["height"] + 14) > 0x2800:
            refuse("%s: %dx%d is too big for this engine's map buffer" % (m.name, hl["width"], hl["height"]))
        for sym in (hl["primary_tileset"], hl["secondary_tileset"]):
            if sym not in tilesets:
                tilesets[sym] = JTileset(hns, sym)
        for b in blocks + border:
            mt = b & 0x3FF
            if mt < hi.FR["metatiles"]:
                placed[hl["primary_tileset"]].add(mt)
            else:
                placed[hl["secondary_tileset"]].add(mt - hi.FR["metatiles"])
        if hl["id"] in ctx.layout_ids:
            continue
        lid = re.sub(r"_HNS$", "", hl["id"])
        hfolder = Path(hl["blockdata_filepath"]).parent.name
        folder = jd.RENAMES.get(hfolder, re.sub(r"_[hH]ns$", "", hfolder))
        if lid in taken_layouts or folder in taken_dirs:
            lid, folder = "LAYOUT_JOHTO_" + lid[len("LAYOUT_"):], "Johto_" + folder
        ctx.layout_ids[hl["id"]] = lid
        write_ints(REPO / "data/layouts" / folder / "map.bin", "H", blocks)
        write_ints(REPO / "data/layouts" / folder / "border.bin", "H", border)
        layouts_out.append({"id": lid, "name": folder + "_Layout", "width": hl["width"], "height": hl["height"],
                            "border_width": 2, "border_height": 2,
                            "primary_tileset": None, "secondary_tileset": None,  # after the names are settled
                            "_hprimary_tileset": hl["primary_tileset"], "_hsecondary_tileset": hl["secondary_tileset"],
                            "border_filepath": "data/layouts/%s/border.bin" % folder,
                            "blockdata_filepath": "data/layouts/%s/map.bin" % folder})
    # two HnS tilesets with one name here (BikeShop_Hns and JohtoBikeShop_Hns): the one HnS did not call Johto* gets "2"
    seen = {}
    for sym in sorted(tilesets, key=lambda s: not s.startswith("gTileset_Johto")):
        ts = tilesets[sym]
        if ts.name in seen:
            ts.name += "2"
            ts.symbol, ts.dir = "gTileset_" + ts.name, ts.dir + "2"
        seen[ts.name] = sym
    for l in layouts_out:
        for key in ("primary_tileset", "secondary_tileset"):
            l[key] = tilesets[l["_h" + key]].symbol
        del l["_hprimary_tileset"], l["_hsecondary_tileset"]
    repo_layouts["layouts"] = [l for l in repo_layouts["layouts"] if not l or l["id"] not in ours_before] + layouts_out
    hi.write_json(REPO / "data/layouts/layouts.json", repo_layouts)
    behaviors = ctx.behaviors = Behaviors(hns.root)
    anims = anims_here() | plan_anims(ctx, tilesets)
    for sym, ts in tilesets.items():
        ts.convert(behaviors, placed[sym], report)
        ts.write()
        if ts.door_tiles and ts.secondary:
            report["notes"].append("%s uses tiles %s, which door animations overwrite" % (ts.name, ts.door_tiles))
        if ts.hcallback != "NULL" and ts.callback(anims) == "NULL":
            report["anims"].append("%s: %s not ported yet" % (ts.name, ts.hcallback))
        elif ts.hcallback != "NULL":
            src = ts.src / "anim"
            for p in sorted(src.rglob("*.png")) if src.exists() else []:
                copy(p, REPO / ts.dir / "anim" / p.relative_to(src))
    report["behaviors"] = behaviors.used
    register_tilesets(tilesets.values(), anims)
    ctx.tilesets = tilesets
    # maps
    for m in ctx.maps:
        m.objects = convert_objects(ctx, m, flags, report)
    for m in ctx.maps:
        m.bg = convert_events(ctx, m, flags, report)
        m.warps = convert_warps(ctx, m, report)
        out = convert_header(ctx, m, report)
        if m.name in ctx.pokemon_centers:
            spawn = ctx.pokemon_centers[m.name]
            label = "%s_OnTransition" % m.name
            m.map_scripts.append(("MAP_SCRIPT_ON_TRANSITION, %s" % label, (label, "\tsetrespawn %s\n\tend\n" % spawn)))
        out.update(connections=convert_connections(ctx, m), object_events=m.objects, warp_events=m.warps,
                   coord_events=[], bg_events=m.bg, level_scaling="0")
        hi.write_json(REPO / "data/maps" / m.name / "map.json", out)
        path = REPO / "data/maps" / m.name / "scripts.inc"
        if exists(path) and not read(path).startswith("@ %s:" % MARK):
            report["kept_scripts"].append(m.name)
        else:
            hi.write(path, scripts_inc(m))
        report["dropped"] += ["%s: %s" % (m.name, d) if not d.startswith(m.name) else d for d in m.dropped]
    hi.write(REPO / "data/scripts/johto_maps.inc", "@ %s: the Johto maps' scripts\n" % MARK +
             "".join('\t.include "data/maps/%s/scripts.inc"\n' % m.name for m in ctx.maps))
    hi.append_once(REPO / "data/event_scripts.s", '"data/scripts/johto_maps.inc"', '\t.include "data/scripts/johto_maps.inc"\n')
    # map groups
    groups = json.loads(read(REPO / "data/maps/map_groups.json"))
    for g in jd.GROUPS.values():
        groups[g] = [m.name for m in ctx.maps if m.group == g]
        if g not in groups["group_order"]:
            groups["group_order"].append(g)
    hi.write_json(REPO / "data/maps/map_groups.json", groups)
    hi.write_map_constants()
    flags.write()
    plan_encounters(ctx, report)
    plan_heal_locations(ctx, report)
    plan_doors(ctx, report)
    plan_kanto_border(ctx, report)


def register_tilesets(tilesets, anims):
    headers, graphics, metatiles, rules = [], [], [], []
    for ts in sorted(tilesets, key=lambda t: (t.secondary, t.name)):
        t, d = ts.name, ts.dir
        headers.append("const struct Tileset gTileset_%s =\n{\n\t.isCompressed = TRUE,\n\t.isSecondary = %s,\n"
                       "\t.tiles = gTilesetTiles_%s,\n\t.palettes = gTilesetPalettes_%s,\n\t.metatiles = gMetatiles_%s,\n"
                       "\t.metatileAttributes = gMetatileAttributes_%s,\n\t.callback = %s\n};\n\n"
                       % (t, "TRUE" if ts.secondary else "FALSE", t, t, t, t, ts.callback(anims)))
        graphics.append('const u32 gTilesetTiles_%s[] = INCBIN_U32("%s/tiles.4bpp.lz");\n\n'
                        "const u16 gTilesetPalettes_%s[][16] =\n{\n%s};\n\n"
                        % (t, d, t, "".join('\tINCBIN_U16("%s/palettes/%02d.gbapal"),\n' % (d, i) for i in range(16))))
        metatiles.append('const u16 gMetatiles_%s[] = INCBIN_U16("%s/metatiles.bin");\n'
                         'const u32 gMetatileAttributes_%s[] = INCBIN_U32("%s/metatile_attributes.bin");\n\n' % (t, d, t, d))
        rules.append("$(TILESETGFXDIR)/%s/tiles.4bpp: %%.4bpp: %%.png\n\t$(GFX) $< $@ -num_tiles %d -Wnum_tiles\n\n"
                     % (d.replace("data/tilesets/", ""), ts.num_tiles))
    block(REPO / "src/data/tilesets/headers.h", "//", "".join(headers))
    block(REPO / "src/data/tilesets/graphics.h", "//", "".join(graphics))
    block(REPO / "src/data/tilesets/metatiles.h", "//", "".join(metatiles))
    block(REPO / "tileset_rules.mk", "#", "".join(rules))


def check_renders(ctx, render_dir):
    """Every Johto map drawn here (the planned files) must be HnS's, pixel for pixel."""
    bad = 0
    hi._TILESETS.clear()
    for m in ctx.maps:
        hl = m.hlayout
        a = hi.render(ctx.blocks[m.hname], hl["width"], ctx.tilesets[hl["primary_tileset"]].src,
                      ctx.tilesets[hl["secondary_tileset"]].src, "hns")
        b = hi.render(ctx.blocks[m.hname], hl["width"], REPO / ctx.tilesets[hl["primary_tileset"]].dir,
                      REPO / ctx.tilesets[hl["secondary_tileset"]].dir, "frlg")
        if a.tobytes() != b.tobytes():
            bad += 1
            refuse("%s: drawn here differently from HnS (render check)" % m.name)
        if render_dir:
            render_dir.mkdir(parents=True, exist_ok=True)
            b.save(render_dir / ("%s.png" % m.name))
    return bad


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--hns", type=Path, default=REPO.parent / "pokehns", help="PokemonHnS clone")
    ap.add_argument("--dry-run", action="store_true", help="plan and check everything, write nothing")
    ap.add_argument("--no-render", action="store_true", help="skip the render check (faster)")
    ap.add_argument("--render", type=Path, help="also save each Johto map as drawn here")
    args = ap.parse_args()
    if not (args.hns / "data/maps/NewBarkTown_hns/map.json").exists():
        print("PokemonHnS not found at %s (--hns DIR)" % args.hns.resolve())
        return 2
    ctx = argparse.Namespace(hns=HnS(args.hns), blocks={}, nurses={}, door_tilesets=[])
    order, unreached = select(ctx.hns)
    names, ids = taken_names()
    ctx.maps = [JMap(ctx.hns, h, names, ids) for h in order]
    ctx.by_hid = {m.json["id"]: m for m in ctx.maps}
    hid_of = {m.hname: m.json["id"] for m in ctx.maps}
    ctx.heal = [dict(h, respawn_map=h.get("respawn_map") or hid_of.get(jd.RESPAWNS.get(h["id"])))
                for h in ctx.hns.heal if h["map"] in ctx.by_hid and "PLAYERS_HOUSE" not in h["id"]
                and h["id"] not in jd.HEAL_LEFT_OUT]
    missing = [h["id"] for h in ctx.heal if h["respawn_map"] not in ctx.by_hid]
    if missing:
        refuse("heal locations without a Pokemon Center: %s (johto_decisions.RESPAWNS)" % ", ".join(missing))
    ctx.heal = [h for h in ctx.heal if h["respawn_map"] in ctx.by_hid]
    ctx.pokemon_centers = {}  # Pokemon Center map -> the spawn its map script sets (a town's first, as listed in HnS)
    for h in ctx.heal:
        ctx.pokemon_centers.setdefault(ctx.by_hid[h["respawn_map"]].name,
                                       "SPAWN_" + re.sub(r"_HNS$", "", h["id"][len("HEAL_LOCATION_"):]))
    report = defaultdict(list, items=Counter(), species=Counter(), degraded=Counter(), gfx=Counter())
    try:
        plan(ctx, report)
        if not args.no_render:
            check_renders(ctx, args.render)
    except hi.Refused:
        pass
    print("Johto: %d maps (%d unreached left out: %s)" % (len(ctx.maps), len(unreached), " ".join(unreached)))
    for title, key in (("Closed warps (lead onto themselves)", "closed"), ("Heal locations", "heal"),
                       ("Night Pokemon in the day tables", "night"), ("Night Pokemon left out", "night_lost"),
                       ("Animations not ported", "anims"), ("Notes", "notes"), ("Scripts kept (not generated)", "kept_scripts")):
        if report[key]:
            print("%s:\n  %s" % (title, "\n  ".join(report[key])))
    for title, key in (("Items replaced", "items"), ("Species replaced", "species"), ("Degraded", "degraded")):
        if report[key]:
            print("%s: %s" % (title, ", ".join("%s x%d" % ("->".join(map(str, k)), n) for k, n in sorted(report[key].items()))))
    lost = sorted({(e, f, ctx.behaviors.fr_name(e)[1]) for (e, f) in report["behaviors"]} - {(e, f, None) for e, f in
                                                                                              report["behaviors"]})
    if lost:
        print("Behaviors not kept as they are:\n  %s" % "\n  ".join("%s -> %s (%s)" % x for x in lost))
    print("%d objects left out (see --verbose in the file johto_report.txt)" % len(report["dropped"]))
    hi.write(REPO / "tools/johto_import/johto_report.txt", "\n".join(report["dropped"]) + "\n")
    if hi.REFUSALS:
        print("REFUSED, nothing written:\n  " + "\n  ".join(hi.REFUSALS))
        return 1
    changed = hi.changes()
    if args.dry_run:
        print("dry run: %d files would change" % len(changed))
        return 0
    for p, data in changed.items():
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_bytes(data)
    print("%d files written. Then: .\\fast_build.cmd" % len(changed))
    return 0


if __name__ == "__main__":
    sys.exit(main())
