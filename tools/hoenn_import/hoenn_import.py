#!/usr/bin/env python3
"""Import Hoenn maps from a local pret/pokeemerald clone into RFVF+ (pokefirered engine).

The library of tools/hoenn_import/import_map.py, which imports one Emerald town or route with all its interiors, or one
dungeon with all its floors (dungeon_units), the usual way. Emerald names this repo already uses are renamed
(hoenn_decisions.RENAMES, rename(): Victory Road's maps are HoennVictoryRoad_* here); any other clash (a map, MAP_ or
LAYOUT_ name, a script label, an item flag, an encounter table) is refused. Its own command line imports the maps it is
given (names here), all in one map group, and checks sprites:
    uv run --no-project --with pillow python tools/hoenn_import/hoenn_import.py [--group G] [--dry-run] Map1 Map2...
        [--emerald ../pokeemerald] [--render DIR]
    uv run --no-project --with pillow python tools/hoenn_import/hoenn_import.py --check-gfx
        (after placing objects in Porymap: Hoenn layouts draw NPCs with Emerald's palettes, see check_gfx)

A run first writes every file in memory (PENDING), then checks that plan: every new map and every connection strip must
render like Emerald's pixel for pixel (blocks painted here, e.g. in Porymap, excepted), every older map whose tileset
grows must render as it does now; files that already exist may only gain lines (a few generated parts excepted); the
files to write must be clean in git. Every reason to refuse is collected (REFUSALS): one of them and nothing is written
(exit 1). Then the files are written and read back; an error restores every one of them (exit 3). Re-running gives the
same files: "nothing to do". What is already here (maps, connections, encounters, labels, tilesets that need nothing
new) is never rewritten, so hand edits stay.

What a run writes:
  - the tilesets of the maps, each converted once per run: Emerald gTileset_X -> gTileset_HoennY in
    data/tilesets/<kind>/hoenn_y/, Y = the suffix of Emerald's gMetatiles_Y (gTileset_Building -> HoennInsideBuilding)
    (tiles.png, palettes/*.pal, metatiles.bin, metatile_attributes.bin; anim/ is left alone)
  - data/layouts/<Layout>/{map.bin,border.bin} + layouts.json for a new layout (a layout shared by several maps is
    written once; an Emerald LAYOUT_X that this repo already uses for a non-Hoenn layout becomes LAYOUT_HOENN_X /
    Hoenn_<Name>). hoenn_decisions.START_LAYOUT can give a map another Emerald layout than its map.json names.
  - data/maps/<Map>/map.json for a NEW map (a map already here is never regenerated: only its placeholder warps and
    missing connections are filled in, see relink()). Emerald's name, MAP_ id, header (music by value, the battle
    scenes this repo lacks through BATTLE_SCENES), connections to the maps that exist here. Objects: those the decided
    post-League state shows (hoenn_decisions: POST_LEAGUE, HIDDEN_BY_MAP_SCRIPT; a flag Emerald's story toggles needs a
    decision), minus berry trees and decorations (sprites hoenn_sprites.py does not import), buried trainers, objects
    on a warp and still objects that cut the way to a warp. Emerald's OBJ_EVENT_GFX_X becomes OBJ_EVENT_GFX_HOENN_X (a
    VAR id goes through VAR_GFX first; MOVED_BY_MAP_SCRIPT gives some their post-League place). Trainers become silent
    NPCs (TRAINER_TYPE_NONE: a stub script would crash CheckTrainer). Cut trees, breakable rocks and boulders
    (FIELD_MOVE_SCRIPTS) keep their script and Emerald's flag. Item balls and hidden items work as in Emerald: Emerald's
    flag, item (a TM / HM by its move) and label, the ball's `finditem` script generated. Signs are placed (SIGN_MOVES
    for the ones outside the map, one with no script is left out); weather coord events are placed; a trigger only once
    its script exists here. Every NPC and sign runs Emerald's label: the script that exists here, else a stub.
  - include/constants/flags.h: an Emerald flag (item ball, hidden item, obstacle) not defined here takes the first free
    FLAG_0x line of FLAG_RANGES (design 1.4a, append-only).
  - data/maps/<Map>/scripts.inc when missing: the LOCALID_ .equ of the map's objects, the item ball scripts, the stubs
    of its labels, and what is left to script; Emerald labels of other maps are stubbed in data/scripts/hoenn_stubs.inc.
  - src/data/wild_encounters.h: Emerald's encounters of the new maps (tables above gWildMonHeaders, headers above
    its terminator).
  - a town's heal location: SPAWN_<TOWN> (include/constants/heal_locations.h, src/data/heal_locations.h).
  - data/event_scripts.s, data/maps/map_groups.json (a group is created at the end of group_order if missing),
    src/data/tilesets/{headers,graphics,metatiles}.h, tileset_rules.mk, include/constants/metatile_labels.h (the
    missing labels), include/constants/{map_groups,layouts}.h (as tools/mapjson makes them: tracked in git)
A map / layout of this repo that this tool did not make is never replaced (Emerald and Kanto share names:
SafariZone_North, LAYOUT_POKEMON_CENTER_1F...). A tileset this run adds nothing to is left as it is (Porymap edits
included); one that must grow is refused if its files are no longer what this tool wrote.
Not handled here: tileset animations (src/tileset_anims.c: a primary gets .callback = InitTilesetAnim_HoennY, to
write by hand; a secondary gets NULL) and door graphics (src/field_door.c sDoorGraphics_Hoenn), see the report.

Engine differences handled:
  - FRLG primary = 640 tiles / 640 metatiles / 7 palettes (Emerald: 512 / 512 / 6); an Emerald primary is copied
    as is (ids unchanged). An Emerald secondary using palette slot 6 (a primary slot in FRLG) gets it moved to a
    free slot 10-12 (WARNING printed: door palettes naming slot 6 must follow); PALETTE_SWAPS moves others.
  - FRLG secondary = 384 metatiles / 376 tiles (VRAM tiles 1016-1023 are the door animation buffer). A secondary
    that fits keeps every metatile (FRLG id = Emerald id + 128) and only the tiles they use, re-based at 640 (an
    animated range stays whole: ANIMATED_TILES). One that does not fit (Mauville, Slateport, Mossdeep, Lavaridge, Cave)
    gets natural ids (natural_plan, design 1.8): Emerald metatile 512 + i keeps slot 640 + i if i < 384, a later one
    takes a dead slot, and only what Emerald's layouts, strips and labels need is kept; hoenn_decisions.SIBLINGS
    splits the too big ones into gTileset_Hoenn<Name>2. Written whole on first use, they never change, whatever the
    order of imports. The secondaries this repo held PRUNED before (LEGACY_PRUNED: GenericBuilding, Facility,
    BattleFrontier) keep their compact append-only ids (+ the labels of metatile_labels.h, scripts and C code set them;
    door labels excepted); one that must grow takes at once all that import_map's maps need from it. Their ids, and the
    natural ones, are in <tileset dir>/emerald_ids.json (FRLG metatile 640 + i = Emerald metatiles[i], null = empty
    slot; FRLG tile 640 + i = Emerald tiles[i]).
  - Underwater maps and Lavaridge Gym B1F need the engine work of step 3 (ENGINE_STEP3): refused without it. Dive and
    emerge connections are copied as Emerald has them (the report says they need Dive). The report lists the maps of
    the unit that cannot be reached from Lilycove (ways(): a door a script opens, a water door, a script dive spot).
  - metatile_attributes u16 -> u32: behaviors are mapped by NAME (the values differ between the engines), through
    BEHAVIOR_OVERRIDES (same meaning), DEGRADED and NO_COUNTERPART (both listed in the report); any other Emerald
    behavior is refused. FRLG's terrain (surf, Cut) and encounter type, which FRLG reads from the attributes, are
    filled in. A tile that can start a warp in Emerald must be able to here (dead-warp check).
"""
import argparse
import io
import json
import math
import re
import struct
import subprocess
import sys
from collections import Counter, defaultdict
from functools import lru_cache
from pathlib import Path, PurePosixPath
from types import SimpleNamespace

from PIL import Image

from hoenn_decisions import (CLOSED_WARPS, DUNGEON_GROUP, DUNGEON_UNIT_OF, HIDDEN_BY_MAP_SCRIPT, MOVED_BY_MAP_SCRIPT,
                             PALETTE_SWAPS, POST_LEAGUE, RENAMES, SIBLINGS, SIGN_MOVES, START_LAYOUT, VAR_GFX)
from hoenn_sprites import skipped

REPO = Path(__file__).resolve().parents[2]
EM = {"tiles": 512, "metatiles": 512, "pals": 6}  # pokeemerald include/fieldmap.h
FR = {"tiles": 640, "metatiles": 640, "pals": 7}  # this repo's include/fieldmap.h
TOTAL = 1024
SEC_MAX = TOTAL - FR["metatiles"]  # metatiles a FRLG secondary can hold
SEC_MAX_TILES = SEC_MAX - 8  # its tiles: the door animations overwrite the last 8 (src/field_door.c DOOR_TILE_START)
TERRAIN_NORMAL, TERRAIN_GRASS, TERRAIN_WATER, TERRAIN_WATERFALL = 0, 1, 2, 3
ENC_NONE, ENC_LAND, ENC_WATER = 0, 1, 2
IDS_FILE = "emerald_ids.json"
# Secondaries this tool pruned before natural ids (design 1.8): compact ids, append-only, in IDS_FILE
LEGACY_PRUNED = {"gTileset_GenericBuilding", "gTileset_Facility", "gTileset_BattleFrontier"}
# Emerald's secondary tile animations (pokeemerald src/tileset_anims.c): (first tile - 512, tiles). Compaction keeps a
# range whole and contiguous once a kept metatile shows one of its tiles, so the animation can be ported later.
ANIMATED_TILES = {
    "gTileset_Rustboro": ((128, 32), (448, 4)), "gTileset_Dewford": ((170, 6),), "gTileset_Slateport": ((224, 4),),
    "gTileset_Mauville": ((96, 32), (128, 32)), "gTileset_Lavaridge": ((288, 8), (160, 4)),
    "gTileset_EverGrande": ((224, 32),), "gTileset_Pacifidlog": ((464, 30), (496, 8)),
    "gTileset_Sootopolis": ((240, 96),), "gTileset_Underwater": ((496, 4),),
    "gTileset_SootopolisGym": ((496, 12), (464, 20)), "gTileset_Cave": ((416, 4),),
    "gTileset_EliteFour": ((480, 4), (504, 1)), "gTileset_MauvilleGym": ((144, 16),), "gTileset_BikeShop": ((496, 9),),
    "gTileset_BattlePyramid": ((151, 8), (135, 8)), "gTileset_BattleFrontierOutsideWest": ((218, 6),),
    "gTileset_BattleFrontierOutsideEast": ((218, 6),)}
HOENN_PRIMARIES = {"gTileset_HoennGeneral", "gTileset_HoennInsideBuilding"}  # = IsHoennMapLayout(), src/fieldmap.c
DIRECTIONS = ("up", "down", "left", "right")  # connections drawn as strips
DIVE = ("dive", "emerge")  # connections too (Emerald's, copied as they are): the Dive field move takes them
# Defined by the engine work underwater maps and Lavaridge Gym B1F need (step 3: the B1F geysers, Hoenn dive / emerge,
# the region map guard): without it those maps are refused
ENGINE_STEP3 = "MB_LAVARIDGE_GYM_B1F_WARP"
MAP_OFFSET = 7  # blocks of a neighbour map drawn around the current one (fieldmap.c, both engines)
OUTDOOR = "gMapGroup_TownsAndRoutes"
DUNGEONS = "gMapGroup_Dungeons"  # Emerald's: its maps join DUNGEON_GROUP here
# Never imported: Emerald indoor-group maps nothing reaches (survey), and the Battle Frontier's Artisan Cave, filed
# with the dungeons (SpecialArea scope; FRLG-Plus has its own ArtisanCave_*)
NEVER = {"LilycoveCity_UnusedMart", "Route104_Prototype", "Route104_PrototypePrettyPetalFlowerShop", "ArtisanCave_B1F",
         "ArtisanCave_1F"}
STUBS = REPO / "data/scripts/hoenn_stubs.inc"
FLAGS_H = REPO / "include/constants/flags.h"
# FLAG_0x placeholders an Emerald flag may take (design 1.4a): unused and never cleared. 0x4FF stays (it anchors
# TRAINER_FLAGS_START). 319 flags: Hoenn's 279 item ball and hidden item flags fit.
FLAG_RANGES = ((0x0EB, 0x153), (0x206, 0x229), (0x356, 0x359), (0x35C, 0x3CF), (0x4C1, 0x4E7), (0x4EC, 0x4FE))
ENCOUNTERS = REPO / "src/data/wild_encounters.h"
ENCOUNTER_TYPES = (("land_mons", "LandMons", "landMonsInfo"), ("water_mons", "WaterMons", "waterMonsInfo"),
                   ("rock_smash_mons", "RockSmashMons", "rockSmashMonsInfo"),
                   ("fishing_mons", "FishingMons", "fishingMonsInfo"))
HEAL_CONSTANTS, HEAL_DATA = REPO / "include/constants/heal_locations.h", REPO / "src/data/heal_locations.h"
HEAL_TABLES = ("sSpawnPoints", "sWhiteoutRespawnHealCenterMapIdxs", "sWhiteoutRespawnHealerNpcIds")
# Emerald warp destinations that are Kanto maps here (same targets as ViridianCity_PokemonCenter_2F's warps)
WARP_ALIASES = {"MAP_UNION_ROOM": "MAP_UNION_ROOM", "MAP_TRADE_CENTER": "MAP_TRADE_CENTER"}
# Emerald battle backgrounds this repo lacks (include/constants/map_types.h): the Elite Four's -> Kanto's, the team
# hideouts' -> the normal one (DEGRADED, listed)
BATTLE_SCENES = {"MAP_BATTLE_SCENE_SIDNEY": "MAP_BATTLE_SCENE_BRUNO", "MAP_BATTLE_SCENE_PHOEBE": "MAP_BATTLE_SCENE_AGATHA",
                 "MAP_BATTLE_SCENE_GLACIA": "MAP_BATTLE_SCENE_LORELEI", "MAP_BATTLE_SCENE_DRAKE": "MAP_BATTLE_SCENE_LANCE",
                 "MAP_BATTLE_SCENE_AQUA": "MAP_BATTLE_SCENE_NORMAL", "MAP_BATTLE_SCENE_MAGMA": "MAP_BATTLE_SCENE_NORMAL"}
# Emerald map sections whose name here is another place: MAPSEC_ALTERING_CAVE is FRLG's Sevii cave (0xB7), Emerald's
# value 0xD2 is MAPSEC_ALTERING_CAVE_E (include/constants/region_map_sections.h)
MAPSECS = {"MAPSEC_ALTERING_CAVE": "MAPSEC_ALTERING_CAVE_E"}

# Emerald behavior name -> FRLG behavior name with the same meaning, where the name differs.
BEHAVIOR_OVERRIDES = {
    "MB_ANIMATED_DOOR": "MB_WARP_DOOR",
    "MB_NON_ANIMATED_DOOR": "MB_CAVE_DOOR",
    "MB_INTERIOR_DEEP_WATER": "MB_DEEP_WATER",
    # Interactive furniture: same flavor text idea (FRLG data/scripts/flavor_text.inc)
    "MB_PICTURE_BOOK_SHELF": "MB_BOOKSHELF",
    "MB_POKEMON_CENTER_BOOKSHELF": "MB_BOOKSHELF",  # "Pokémon magazines" (RHH pairs it with MB_POKEMART_SHELF)
    "MB_SHOP_SHELF": "MB_POKEMART_SHELF",
    "MB_TRASH_CAN": "MB_TRASH_BIN",
    "MB_BLUEPRINT": "MB_BLUEPRINTS",
    "MB_CABLE_BOX_RESULTS_1": "MB_BATTLE_RECORDS",
    "MB_CABLE_BOX_RESULTS_2": "MB_BATTLE_RECORDS",
    "MB_WIRELESS_BOX_RESULTS": "MB_CABLE_CLUB_WIRELESS_MONITOR",
    "MB_NO_RUNNING": "MB_RUNNING_DISALLOWED",  # same value and meaning
    "MB_NO_SURFACING": "MB_UNDERWATER_BLOCKED_ABOVE",  # same value and meaning: a diver cannot emerge there
}
# Underwater floor: Emerald flags it surfable (a diver swims there), FRLG moves a diver by collision and elevation only.
# Its encounters are Emerald's water ones (seaweed).
UNDERWATER = {"MB_UNDERWATER_BLOCKED_ABOVE", "MB_SEAWEED", "MB_SEAWEED_NO_SURFACING"}
# Emerald behavior -> the nearest FRLG one: it loses part of its effect (listed in the report).
DEGRADED = {
    "MB_DEEP_SAND": "MB_SAND",  # no sinking
    "MB_SOOTOPOLIS_DEEP_WATER": "MB_DEEP_WATER",
    "MB_MOSSDEEP_GYM_WARP": "MB_REGULAR_WARP",  # warp pad (DoTeleportWarp)
    "MB_AQUA_HIDEOUT_WARP": "MB_REGULAR_WARP",
    "MB_LAVARIDGE_GYM_1F_WARP": "MB_LAVARIDGE_1F_WARP",
    "MB_MT_PYRE_HOLE": "MB_FALL_WARP",
    "MB_SHOAL_CAVE_ENTRANCE": "MB_SOUTH_ARROW_WARP",
    "MB_DEEP_SOUTH_WARP": "MB_CAVE_DOOR",  # the player arrives facing north
    "MB_STAIRS_OUTSIDE_ABANDONED_SHIP": "MB_NORTH_ARROW_WARP",
    # A surfing player does trigger a MB_CAVE_DOOR warp, but FRLG then lands him ON FOOT on elevation-1
    # water (MB_CAVE_DOOR is not surfable: overworld.c GetAdjustedInitialTransitionFlags) = soft-lock.
    # So water doors are plain sea until the engine gets a real water door. They are the ways in and out of the
    # underwater dungeons and Aqua Hideout: all sea, none of those is reached (no trap).
    "MB_WATER_DOOR": "MB_OCEAN_WATER",
    "MB_WATER_SOUTH_ARROW_WARP": "MB_OCEAN_WATER",
}
WATER_DOORS = {"MB_WATER_DOOR", "MB_WATER_SOUTH_ARROW_WARP"}
# Emerald behaviors with no counterpart here: MB_NORMAL (listed in the report, with this reason). MB_SECRET_BASE_*
# too. A warp tile among them is refused by the dead-warp check.
NO_COUNTERPART = dict(
    {b: "Acro Bike rail" for b in ("MB_HORIZONTAL_RAIL", "MB_VERTICAL_RAIL", "MB_ISOLATED_HORIZONTAL_RAIL",
                                   "MB_ISOLATED_VERTICAL_RAIL")},
    **{b: "bridge" for b in ("MB_BRIDGE_OVER_OCEAN", "MB_BRIDGE_OVER_POND_LOW", "MB_BRIDGE_OVER_POND_MED",
                             "MB_BRIDGE_OVER_POND_HIGH", "MB_BRIDGE_OVER_POND_MED_EDGE_1",
                             "MB_BRIDGE_OVER_POND_MED_EDGE_2", "MB_BRIDGE_OVER_POND_HIGH_EDGE_1",
                             "MB_BRIDGE_OVER_POND_HIGH_EDGE_2", "MB_FORTREE_BRIDGE", "MB_BIKE_BRIDGE_OVER_BARRIER",
                             "MB_REFLECTION_UNDER_BRIDGE")},
    **{b: "Pacifidlog log" for b in ("MB_PACIFIDLOG_HORIZONTAL_LOG_LEFT", "MB_PACIFIDLOG_HORIZONTAL_LOG_RIGHT",
                                     "MB_PACIFIDLOG_VERTICAL_LOG_TOP", "MB_PACIFIDLOG_VERTICAL_LOG_BOTTOM")},
    **{b: "diagonal jump, no effect in Emerald either" for b in ("MB_JUMP_NORTHEAST", "MB_JUMP_NORTHWEST",
                                                                 "MB_JUMP_SOUTHEAST", "MB_JUMP_SOUTHWEST")},
    MB_MUDDY_SLOPE="muddy slope", MB_BUMPY_SLOPE="bumpy slope", MB_VASE="vase", MB_BERRY_TREE_SOIL="berry soil",
    MB_IMPASSABLE_SOUTH_AND_NORTH="one-way wall", MB_IMPASSABLE_WEST_AND_EAST="one-way wall",
    MB_HOLDS_LARGE_DECORATION="secret base", MB_HOLDS_SMALL_DECORATION="secret base",
    MB_TRICK_HOUSE_PUZZLE_DOOR="Trick House door, a script warps", MB_LONG_GRASS_SOUTH_EDGE="grass edge",
    MB_CRACKED_FLOOR="cracked floor", MB_CRACKED_FLOOR_HOLE="cracked floor", MB_ROULETTE="game corner",
    MB_SLOT_MACHINE="game corner", MB_CLOSED_SOOTOPOLIS_DOOR="closed door", MB_SKY_PILLAR_CLOSED_DOOR="closed door",
    MB_PETALBURG_GYM_DOOR="gym door, a script opens it", MB_POKEBLOCK_FEEDER="Safari feeder",
    MB_PLAYER_ROOM_PC_ON="bedroom PC", MB_RUNNING_SHOES_INSTRUCTION="tutorial sign", MB_TRAINER_HILL_TIMER="Trainer Hill",
    MB_BATTLE_PYRAMID_WARP="Battle Pyramid", MB_UNUSED_SOOTOPOLIS_DEEP_WATER="unused water, not surfable in Emerald",
    MB_UNUSED_SOOTOPOLIS_DEEP_WATER_2="unused water, not surfable in Emerald",
    MB_LAVARIDGE_GYM_B1F_WARP="Lavaridge Gym B1F geyser (engine E3)",
)
# Scripts of the field-move obstacles (cut tree, breakable rock, boulder), shared and named as in pokeemerald
# (data/scripts/field_moves.inc). Their objects keep Emerald's flag (FLAG_TEMP_11-1F): `removeobject VAR_LAST_TALKED`
# sets it, else the obstacle comes back on the next step.
FIELD_MOVE_SCRIPTS = {"EventScript_CutTree", "EventScript_RockSmash", "EventScript_StrengthBoulder"}
# Emerald scripts shared by many maps -> this repo's script that does the same.
COMMON_SCRIPTS = dict({s: s for s in FIELD_MOVE_SCRIPTS},
                      Common_EventScript_ShowPokemonCenterSign="EventScript_PokecenterSign",
                      Common_EventScript_ShowPokemartSign="EventScript_PokemartSign")


# ---------------------------------------------------------------- files: the plan lives in memory until it is checked

PENDING = {}  # Path -> bytes: every file this run writes
_CONSTANTS = [0]  # bumped when the plan writes include/constants: defined() reads the headers again


def read_bytes(path):
    path = Path(path)
    return PENDING[path] if path in PENDING else path.read_bytes()


def exists(path):
    path = Path(path)
    return path in PENDING or path.exists()


def put(path, data):
    path = Path(path)
    PENDING[path] = data
    if "include/constants" in path.as_posix():
        _CONSTANTS[0] += 1


def read(path):
    return read_bytes(path).decode("utf-8")


def write(path, text):
    """Plan `path` with `text`, keeping the line endings of the file it replaces."""
    if exists(path) and b"\r\n" in read_bytes(path):
        text = text.replace("\r\n", "\n").replace("\n", "\r\n")
    put(path, text.encode("utf-8"))


def write_json(path, data):
    write(path, json.dumps(data, indent=2, ensure_ascii=False) + "\n")


def copy(src, dst):
    put(dst, read_bytes(src))


def read_ints(path, fmt):
    data = read_bytes(path)
    return list(struct.unpack("<%d%s" % (len(data) // struct.calcsize(fmt), fmt), data))


def write_ints(path, fmt, values):
    put(path, struct.pack("<%d%s" % (len(values), fmt), *values))


def open_png(path):
    return Image.open(io.BytesIO(read_bytes(path)))


def save_png(img, path):
    """Plan a 4bpp PNG, unless the file holds these pixels already (PNG bytes depend on the Pillow / zlib version)."""
    if exists(path):
        old = open_png(path)
        if (old.mode, old.size, old.tobytes(), old.getpalette()[:48]) == (img.mode, img.size, img.tobytes(),
                                                                           img.getpalette()[:48]):
            return
    buf = io.BytesIO()
    img.save(buf, format="PNG", bits=4)
    put(path, buf.getvalue())


def changes():
    """The planned files that differ from the disk."""
    return {p: d for p, d in PENDING.items() if not p.exists() or p.read_bytes() != d}


def commit(files):
    """Write `files`, then read them back: the written bytes must be the planned ones, an older file must only have
    gained lines. On any error, every file gets back its bytes (a created one is deleted, so are the folders made for
    it) and the error goes on."""
    originals = {p: p.read_bytes() if p.exists() else None for p in files}
    new_dirs = set()
    try:
        for p, data in files.items():
            new_dirs |= {d for d in (p.parent, *p.parent.parents) if not d.exists()}
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_bytes(data)
        bad = [p for p, data in files.items() if p.read_bytes() != data]
        bad += [p for p, old in originals.items() if old is not None and not additive(p, old, p.read_bytes())]
        if bad:
            raise OSError("post-check failed for %s" % ", ".join(p.relative_to(REPO).as_posix() for p in bad))
    except BaseException:
        for p, data in originals.items():
            try:
                if data is None:
                    p.unlink(missing_ok=True)
                elif p.read_bytes() != data:
                    p.write_bytes(data)
            except OSError as e:
                print("ROLLBACK FAILED for %s: %s" % (p, e))
        for d in sorted(new_dirs, key=lambda d: len(d.parts), reverse=True):
            try:
                d.rmdir()
            except OSError:
                pass
        raise


# ---------------------------------------------------------------- refusals: all of them are listed, then exit 1

REFUSALS = []


class Refused(Exception):
    """A refusal the plan cannot go past."""


def refuse(msg, fatal=False):
    if msg not in REFUSALS:
        REFUSALS.append(msg)
    if fatal:
        raise Refused(msg)


def table(src, start):
    """Body of the C initializer that follows `start` in `src`."""
    body = src[src.index(start):]
    return body[:body.index("};")]


# ---------------------------------------------------------------- what is read from pokeemerald

def new_game_flags(em):
    """Flags a new Emerald game sets (src/new_game.c runs EventScript_ResetAllMapFlags; its only call,
    EventScript_ResetAllBerries, sets none)."""
    body = read(em / "data/scripts/new_game.inc").split("EventScript_ResetAllMapFlags::", 1)[1]
    body = body[:re.search(r"^\tend$", body, re.M).start()]
    return set(re.findall(r"setflag (FLAG_\w+)", body))


def warp_behaviors(root):
    """Behaviors that can start a warp in the engine at `root`: those that IsWarpMetatileBehavior,
    IsArrowWarpMetatileBehavior and TryDoorWarp (src/field_control_avatar.c) test, read from the
    MetatileBehavior_Is* bodies (a stub returning FALSE tests none)."""
    control, source = read(root / "src/field_control_avatar.c"), read(root / "src/metatile_behavior.c")
    tests = set()
    for fn in ("IsWarpMetatileBehavior", "IsArrowWarpMetatileBehavior", "TryDoorWarp"):
        tests |= set(re.findall(r"MetatileBehavior_(Is\w+)",
                                re.search(r"\b%s\([^)]*\)\s*\{(.*?)\n\}" % fn, control, re.S).group(1)))
    names = set()
    for fn in tests:
        body = re.search(r"\bMetatileBehavior_%s\([^)]*\)\s*\{(.*?)\n\}" % fn, source, re.S)
        assert body, "%s/src/metatile_behavior.c: MetatileBehavior_%s not found" % (root, fn)
        names |= set(re.findall(r"\bMB_\w+", body.group(1)))
    return names


def snake(name):
    """VictoryRoad -> VICTORY_ROAD."""
    return re.sub(r"(?<!^)(?=[A-Z])", "_", name).upper()


def rename(text):
    """Emerald `text` (a name, JSON, scripts) with hoenn_decisions.RENAMES applied: the names of those maps, of their
    layouts and script labels (file paths stay), their MAP_, LAYOUT_ and item flag constants."""
    for old, new in RENAMES.items():
        text = re.sub(r"(?<![/\w])%s_" % old, new + "_", text)
        text = re.sub(r"\b(MAP|LAYOUT|FLAG_ITEM|FLAG_HIDDEN_ITEM)_%s_" % snake(old), r"\1_%s_" % snake(new), text)
    return text


class Emerald:
    """pokeemerald's maps, layouts, scripts and constants, parsed once, under their names here (rename())."""

    def __init__(self, root):
        self.root = root
        text = read(root / "data/maps/map_groups.json")
        self.groups, raw = json.loads(rename(text)), json.loads(text)
        self.folder = {rename(n): n for g in raw["group_order"] for n in raw[g]}  # name here -> Emerald's
        self.maps = {n: json.loads(rename(read(root / "data/maps" / f / "map.json"))) for n, f in self.folder.items()}
        self.layouts = {l["id"]: l for l in json.loads(rename(read(root / "data/layouts/layouts.json")))["layouts"]
                        if "id" in l}
        self.behaviors = Behaviors(root)
        self.new_game = new_game_flags(root)
        self.flag_ops, self.bodies = defaultdict(Counter), {}
        for p in sorted([*(root / "data/maps").glob("*/scripts.inc"), *(root / "data/scripts").glob("*.inc")]):
            text = rename(read(p))
            if p.name != "new_game.inc":
                for op, flag in re.findall(r"\b(setflag|clearflag)\s+(FLAG_\w+)", text):
                    self.flag_ops[flag][op] += 1
            parts = re.split(r"^(\w+)::", text, flags=re.M)
            self.bodies.update(zip(parts[1::2], parts[2::2]))
        songs = lambda p: {n: int(v, 0) for n, v in re.findall(r"#define\s+(MUS_\w+)\s+(\d+|0x[0-9A-Fa-f]+)\b", read(p))}
        self.songs, self.songs_here = songs(root / "include/constants/songs.h"), defaultdict(list)
        for n, v in songs(REPO / "include/constants/songs.h").items():
            self.songs_here[v].append(n)
        self.warp_triggers, self.warp_triggers_here = warp_behaviors(root), warp_behaviors(REPO)

    def music(self, name):
        """This repo's constant for Emerald's song `name`: the one with the same value (Emerald's songs 350-483 are
        kept here; the names FRLG's own tracks took became MUS_RS_*), None if there is none."""
        here = self.songs_here.get(self.songs.get(name), [])
        return name if name in here else here[0] if here else None

    def story_flag(self, flag):
        """True if Emerald's story toggles `flag`, an object's visibility: a decision must give its post-League state
        (a flag set at new game that something clears, or a clear one that something sets)."""
        ops = self.flag_ops.get(flag, {})
        return bool(ops.get("clearflag" if flag in self.new_game else "setflag"))

    def trainer_id(self, label):
        m = re.search(r"\btrainerbattle\w*\s+(TRAINER_\w+)", self.bodies.get(label, ""))
        return m.group(1) if m else None

    def found_item(self, label):
        """ITEM_X if Emerald's script `label` is an item ball's (data/scripts/item_ball_scripts.inc: `finditem ITEM_X`,
        `end`), else None (Steven's Beldum, the rivals' and Birch's balls run a story script)."""
        m = re.match(r"\s*finditem (ITEM_\w+)\s*\n\s*end\b", self.bodies.get(label, ""))
        return m.group(1) if m else None

    def map_scripts(self, name):
        """[(type, label)] of the Emerald map's script table (ON_TRANSITION, ON_FRAME_TABLE...)."""
        return re.findall(r"map_script\s+MAP_SCRIPT_(\w+),\s*(\w+)",
                          self.bodies.get(name + "_MapScripts", "").split(".byte 0")[0])

    def layout_of(self, name):
        return self.layouts[START_LAYOUT.get(name, self.maps[name]["layout"])]


@lru_cache(maxsize=None)
def em_tileset(em, symbol):
    """(header fields, source folder) of Emerald's tileset `symbol`."""
    header = re.search(r"const struct Tileset %s =\s*\{(.*?)\};" % symbol, read(em / "src/data/tilesets/headers.h"), re.S)
    if not header:
        refuse("%s not found in pokeemerald src/data/tilesets/headers.h" % symbol, fatal=True)
    fields = dict(re.findall(r"\.(\w+)\s*=\s*(\w+)", header.group(1)))
    sources = "".join(read(em / p) for p in ("src/data/tilesets/graphics.h", "src/graphics.c",
                                             "src/data/tilesets/metatiles.h"))
    dirs = set()
    for field in ("tiles", "palettes", "metatiles", "metatileAttributes"):
        m = re.search(r'\b%s\[\](?:\[16\])?\s*=\s*\{?\s*INCBIN_U\d+\("(data/tilesets/[^"]+?)/(?:palettes/)?[^/"]+"'
                      % fields[field], sources)
        if not m:
            refuse("%s of %s not found in pokeemerald src/" % (fields[field], symbol), fatal=True)
        dirs.add(m.group(1))
    if len(dirs) != 1:
        refuse("%s: files spread over %s" % (symbol, dirs), fatal=True)
    return fields, em / dirs.pop()


def repo_tileset_dir(symbol):
    """This repo's folder of the tileset `symbol` (planned registrations included)."""
    header = re.search(r"\b%s =\s*\{(.*?)\};" % symbol, read(REPO / "src/data/tilesets/headers.h"), re.S)
    metatiles = re.search(r"\.metatiles\s*=\s*(\w+)", header.group(1)).group(1)
    return REPO / re.search(r'\b%s\[\]\s*=\s*INCBIN_U16\("([^"]+)/metatiles.bin"' % metatiles,
                            read(REPO / "src/data/tilesets/metatiles.h")).group(1)


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
        """(this repo's behavior for Emerald's `em_name`, None or how it is degraded); an unknown one is refused."""
        if em_name in BEHAVIOR_OVERRIDES:
            return BEHAVIOR_OVERRIDES[em_name], None
        if em_name in DEGRADED:
            return DEGRADED[em_name], "DEGRADED"
        if em_name in self.fr_values:
            return em_name, None
        why = NO_COUNTERPART.get(em_name) or ("secret base" if em_name.startswith("MB_SECRET_BASE_") else None)
        if not why:
            refuse("unknown Emerald behavior %s: map it in hoenn_import.py (BEHAVIOR_OVERRIDES, DEGRADED or "
                   "NO_COUNTERPART)" % em_name)
        return "MB_NORMAL", "no counterpart here: %s" % (why or "UNKNOWN")

    def convert(self, em_attr):
        """Emerald u16 attribute -> FRLG u32 attribute (see sMetatileAttrMasks in src/fieldmap.c)."""
        if em_attr & 0x0F00 or em_attr >> 12 > 2 or em_attr & 0xFF >= len(self.em_names):
            refuse("unknown Emerald metatile attribute 0x%04X" % em_attr)
            return 0
        em_name = self.em_names[em_attr & 0xFF]
        fr_name = self.fr_name(em_name)[0]
        self.used[em_name, fr_name] += 1
        surfable, underwater = fr_name in self.fr_surfable, fr_name in UNDERWATER
        if not surfable and not underwater and em_name in self.em_surfable:
            refuse("%s is surfable in Emerald, %s is not here: map it in BEHAVIOR_OVERRIDES / DEGRADED" % (em_name, fr_name))
        if fr_name == "MB_WATERFALL":
            terrain = TERRAIN_WATERFALL
        elif surfable:
            terrain = TERRAIN_WATER
        elif fr_name in ("MB_TALL_GRASS", "MB_LONG_GRASS", "MB_ASHGRASS"):  # what Emerald's Cut mows (IsPokeGrass,
            terrain = TERRAIN_GRASS                                           # IsAshGrass); FRLG's Cut reads the terrain
        else:
            terrain = TERRAIN_NORMAL
        encounter = ENC_WATER if surfable or underwater and em_name in self.em_encounter else \
            ENC_LAND if em_name in self.em_encounter else ENC_NONE
        layer = em_attr >> 12  # NORMAL/COVERED/SPLIT: same values and DrawMetatile logic in both engines
        return self.fr_values[fr_name] | terrain << 9 | encounter << 24 | layer << 29


# ---------------------------------------------------------------- tilesets

def sibling_of(symbol, layout_id):
    """Which FRLG tileset holds Emerald's secondary `symbol` for the Emerald layout `layout_id`: 0 for
    gTileset_Hoenn<Name>, k for gTileset_Hoenn<Name><k + 1> (hoenn_decisions.SIBLINGS)."""
    return next((k + 1 for k, s in enumerate(SIBLINGS.get(symbol, ())) if layout_id in s), 0)


def dungeon_units(groups):
    """Emerald's dungeons as import_map units: {unit: its maps, in Emerald's order}. A map's unit is its name up to the
    first "_" (GraniteCave_B1F: GraniteCave), an underwater one's is in hoenn_decisions.DUNGEON_UNIT_OF."""
    units = defaultdict(list)
    for m in groups[DUNGEONS]:
        if m not in NEVER:
            units[DUNGEON_UNIT_OF.get(m, m.split("_")[0])].append(m)
    return dict(units)


def closure(groups, unit):
    """What import_map.py imports for `unit`, in Emerald's order: {map: its group here}. A town or route: it and the
    maps of its Emerald indoor group; a dungeon unit: its maps, all in DUNGEON_GROUP."""
    if unit not in groups[OUTDOOR]:
        return {m: DUNGEON_GROUP for m in dungeon_units(groups)[unit]}
    group = "gMapGroup_Indoor" + re.sub(r"(Town|City)$", "", unit)
    return dict({unit: OUTDOOR}, **{m: group for m in groups.get(group, []) if m not in NEVER})


@lru_cache(maxsize=None)
def em_layout_blocks(ctx, layout_id):
    """(map.bin, border.bin) of Emerald's layout `layout_id`."""
    layout = ctx.layouts[layout_id]
    return read_ints(ctx.root / layout["blockdata_filepath"], "H"), read_ints(ctx.root / layout["border_filepath"], "H")


def secondary_ids(blocks):
    return {b & 0x3FF for b in blocks if b & 0x3FF >= EM["metatiles"]}


def with_anims(symbol, tiles, png_tiles):
    """Sorted Emerald tiles: `tiles` plus the rest of every animated range (ANIMATED_TILES) one of them is in."""
    out = set(tiles)
    for first, count in ANIMATED_TILES.get(symbol, ()):
        span = set(range(EM["tiles"] + first, EM["tiles"] + min(first + count, png_tiles)))
        if span & out:
            out |= span
    return sorted(out)


@lru_cache(maxsize=None)
def scope_needs(ctx, symbol):
    """Secondary metatiles of `symbol` that the maps import_map.py imports (the 57 units) need from its first FRLG
    tileset: a pruned one gets them all with the first import that grows it, whatever the order of imports."""
    layouts = {ctx.layout_of(m)["id"] for u in ctx.groups[OUTDOOR] for m in closure(ctx.groups, u)}
    return {m for lid in layouts if ctx.layouts[lid]["secondary_tileset"] == symbol and not sibling_of(symbol, lid)
            for m in secondary_ids(sum(em_layout_blocks(ctx, lid), []))}


def em_count(ctx, symbol):
    """Metatiles of Emerald's tileset `symbol`."""
    return len(read_bytes(em_tileset(ctx.root, symbol)[1] / "metatile_attributes.bin")) // 2


@lru_cache(maxsize=None)
def strips_shown(ctx):
    """[(tileset, sibling) of a map, (tileset, sibling) of its neighbour, the Emerald secondary metatiles of the
    neighbour that the map shows through their connection strip and its own Emerald tileset can draw)]."""
    by_id = {mj["id"]: name for name, mj in ctx.maps.items()}
    out = []
    for name, mj in ctx.maps.items():
        layout = ctx.layout_of(name)
        sym = layout["secondary_tileset"]
        for c in mj.get("connections") or []:
            if c["direction"] in DIRECTIONS and c["map"] in by_id:
                nl = ctx.layout_of(by_id[c["map"]])
                v = SimpleNamespace(width=layout["width"], height=layout["height"],
                                    em_counts=[EM["metatiles"], em_count(ctx, sym)])
                blocks = em_layout_blocks(ctx, nl["id"])[0]
                n = SimpleNamespace(width=nl["width"], height=nl["height"], em_blocks=blocks, fr_blocks=blocks, edited=())
                out.append(((sym, sibling_of(sym, layout["id"])),
                            (nl["secondary_tileset"], sibling_of(nl["secondary_tileset"], nl["id"])),
                            secondary_ids(strip(v, n, c)[0])))
    return out


@lru_cache(maxsize=None)
def tileset_needs(ctx, symbol):
    """For each FRLG tileset Emerald's secondary `symbol` becomes (sibling_of), the Emerald metatiles it holds: what its
    Emerald layouts use (blocks, border), what their maps show of their neighbours (connection strips, cells Emerald
    can draw) and the labelled metatiles (scripts and C code set them)."""
    need = [set() for _ in range(len(SIBLINGS.get(symbol, ())) + 1)]
    for lid, layout in ctx.layouts.items():
        if layout["secondary_tileset"] == symbol:
            need[sibling_of(symbol, lid)] |= secondary_ids(sum(em_layout_blocks(ctx, lid), []))
    for (sym, k), _, shown in strips_shown(ctx):
        if sym == symbol:
            need[k] |= shown
    own = {v for _, v in em_labels(ctx.root, symbol[len("gTileset_"):])}
    return [{m for m in s | own if EM["metatiles"] <= m < EM["metatiles"] + em_count(ctx, symbol)} for s in need]


@lru_cache(maxsize=None)
def natural_plan(ctx, symbol):
    """Natural ids (design 1.8) of Emerald's secondary `symbol`, for each FRLG tileset it becomes: [the Emerald
    metatile of slot 640 + i, None if empty], holding tileset_needs(). Metatile 512 + i sits in slot i if i < 384,
    else in a dead slot: the lowest one that no tileset needing the metatile uses for itself (nor one whose strip shows
    it) and that holds no door of another Hoenn tileset, so siblings share ids. A metatile a strip shows from another
    tileset's dead slot takes that slot (Route111 sees Route112's 0x3B8). Emerald's data alone fixes it: the order of
    imports never changes it."""
    em_name = symbol[len("gTileset_"):]
    need = tileset_needs(ctx, symbol)
    align, avoid = {}, defaultdict(set)  # metatile -> the dead slot it must take / the slots it must not take
    for (sym, k), (other, ok), shown in strips_shown(ctx):
        for m in shown:
            if m - EM["metatiles"] < SEC_MAX or sym == other:
                continue
            if sym == symbol:  # ponytail: recursion, a loop if two tilesets ever showed each other's dead slots
                plan = natural_plan(ctx, other)[ok]
                align[m] = plan.index(m) if m in plan else None
            elif other == symbol:
                avoid[m] |= {i - EM["metatiles"] for i in tileset_needs(ctx, sym)[k]}
    labels = re.findall(r"#define (METATILE_\w+)\s+(0x[0-9A-Fa-f]+)",
                        read(ctx.root / "include/constants/metatile_labels.h"))
    doors = set(re.findall(r"METATILE_\w+", read(ctx.root / "src/field_door.c")))
    door_slots = {int(v, 16) - EM["metatiles"] for n, v in labels
                  if n in doors and not n.startswith("METATILE_%s_" % em_name)}
    first = 1 if symbol in LEGACY_PRUNED else 0  # the first tileset of a legacy one keeps its compact ids
    slot, taken = {}, [set() for _ in need]
    for m in sorted(set().union(*need[first:]), key=lambda m: (m not in align, m)):
        if m - EM["metatiles"] < SEC_MAX:
            continue
        users = [k for k in range(first, len(need)) if m in need[k]]
        free = [d for d in ([align[m]] if m in align else range(SEC_MAX)) if d is not None and d not in door_slots and
                d not in avoid[m] and all(EM["metatiles"] + d not in need[k] and d not in taken[k] for k in users)]
        if not free:
            refuse("gTileset_%s: no dead slot left for its metatile 0x%03X (design 1.8): give it a sibling in "
                   "hoenn_decisions.SIBLINGS" % (em_name, m))
            continue
        slot[m] = free[0]
        for k in users:
            taken[k].add(free[0])
    plans = []
    for s in need:
        out = [None] * SEC_MAX
        for m in s:
            if m in slot or m - EM["metatiles"] < SEC_MAX:
                out[slot.get(m, m - EM["metatiles"])] = m
        while out and out[-1] is None:
            out.pop()
        plans.append(out)
    return plans


class Tileset:
    def __init__(self, ctx, symbol, sibling, used):
        """Reads, checks and converts Emerald's tileset `symbol` into its FRLG tileset number `sibling` (sibling_of);
        `used` = its metatile ids in the maps of the batch. write() plans the files."""
        em, behaviors = ctx.root, ctx.behaviors
        fields, self.src = em_tileset(em, symbol)
        self.em_name = symbol.replace("gTileset_", "")  # Emerald labels: METATILE_<em_name>_*
        suffix = fields["metatiles"].replace("gMetatiles_", "") + ("%d" % (sibling + 1) if sibling else "")
        self.name = "Hoenn" + suffix
        self.secondary = fields["isSecondary"] == "TRUE"
        self.kind = "secondary" if self.secondary else "primary"
        self.em_callback = fields["callback"]
        self.dir = "data/tilesets/%s/hoenn_%s" % (self.kind, snake(suffix).lower())
        other = "primary" if self.secondary else "secondary"
        if exists(REPO / self.dir.replace(self.kind, other, 1)):
            refuse("%s already exists as a %s tileset of this repo: pick another target name" % (self.dir, other),
                   fatal=True)
        self.em_meta = read_ints(self.src / "metatiles.bin", "H")
        self.em_attrs = read_ints(self.src / "metatile_attributes.bin", "H")
        self.png = png = open_png(self.src / "tiles.png")
        if len(self.em_meta) != 8 * len(self.em_attrs) or png.mode != "P" or png.width % 8 or png.height % 8:
            refuse("%s: unexpected Emerald tileset files in %s" % (symbol, self.src), fatal=True)
        png_tiles = png.width // 8 * (png.height // 8)
        self.pal_map, self.pruned, self.legacy, self.junk = {}, False, False, []
        self.new = not exists(REPO / self.dir / "metatiles.bin")
        if not self.secondary:
            if len(self.em_attrs) > EM["metatiles"] or not all((e & 0x3FF) < EM["tiles"] and e >> 12 < EM["pals"]
                                                               for e in self.em_meta):
                refuse("Emerald primary %s references secondary tiles or palettes" % symbol, fatal=True)
            self.metas = list(range(len(self.em_attrs)))
            self.num_tiles = png_tiles
            self.meta = self.em_meta
        else:
            # Emerald junk: entries naming a tile beyond tiles.png, VRAM garbage in game (Petalburg 0x24A-0x24B, palette
            # 14, under opaque tiles; MauvilleGym 0x268-0x274, on no map) -> tile 0. render() draws them magenta on the
            # Emerald side, so the render check fails if one ever shows on a map.
            beyond = lambda e: e & 0x3FF >= EM["tiles"] + png_tiles
            self.junk = sorted({EM["metatiles"] + i // 8 for i, e in enumerate(self.em_meta) if beyond(e)})
            self.em_meta = [0 if beyond(e) else e for e in self.em_meta]
            entries = lambda m: [0] * 8 if m is None else self.em_meta[(m - EM["metatiles"]) * 8:][:8]  # None: empty
            sec_tiles = lambda metas: sorted({e & 0x3FF for m in metas for e in entries(m) if e & 0x3FF >= EM["tiles"]})
            every = range(EM["metatiles"], EM["metatiles"] + len(self.em_attrs))
            self.ids_path = REPO / self.dir / IDS_FILE
            whole = with_anims(symbol, sec_tiles(every), png_tiles)
            self.legacy = symbol in LEGACY_PRUNED and not sibling
            self.pruned = self.legacy or symbol in SIBLINGS or len(every) > SEC_MAX or len(whole) > SEC_MAX_TILES
            if self.legacy:  # append-only compact numbering, shared with the maps imported before
                ids = json.loads(read(self.ids_path)) if exists(self.ids_path) else {"metatiles": [], "tiles": []}
                # + the labelled metatiles, which scripts / C code set at runtime; a door label only feeds the door
                # animation table, so that door comes with the first map placing it (and gets its table entry then)
                doors = set(re.findall(r"METATILE_\w+", read(em / "src/field_door.c")))
                used = set(used) | {v for n, v in em_labels(em, self.em_name)
                                    if "METATILE_%s_%s" % (self.em_name, n) not in doors}
                if not used <= set(ids["metatiles"]):  # it grows: by all that import_map's maps need, whatever the order
                    used |= scope_needs(ctx, symbol)
                if not used <= set(every):
                    refuse("%s: maps use metatiles it does not have" % symbol, fatal=True)
                self.metas = ids["metatiles"] + sorted(used - set(ids["metatiles"]))
                self.tiles = ids["tiles"] + [t for t in sec_tiles(self.metas) if t not in ids["tiles"]]
                known = len(ids["metatiles"])  # what this tool wrote before
            elif self.pruned:  # natural ids, written whole once (design 1.8)
                self.metas = natural_plan(ctx, symbol)[sibling]
                self.tiles = with_anims(symbol, sec_tiles(self.metas), png_tiles)
                old = json.loads(read(self.ids_path)) if exists(self.ids_path) else {}
                if not self.new and (old.get("metatiles"), old.get("tiles")) != (self.metas, self.tiles):
                    refuse("%s/%s is not the natural-id plan this import makes (design 1.8): not overwritten"
                           % (self.dir, IDS_FILE))
            else:
                self.metas = list(every)
                self.tiles = whole
            if len(self.tiles) > SEC_MAX_TILES or len(self.metas) > SEC_MAX:  # fatal: the renders would only repeat it
                refuse("gTileset_%s would hold %d metatiles / %d tiles here (max %d / %d): give it a sibling in "
                       "hoenn_decisions.SIBLINGS (design 1.8)" % (self.name, self.count(), len(self.tiles), SEC_MAX,
                                                                  SEC_MAX_TILES), fatal=True)
            tile_map = {t: FR["tiles"] + i for i, t in enumerate(self.tiles)}
            pals = {e >> 12 for e in self.em_meta}  # every metatile: the slot must not move when a later batch adds some
            if max(pals) > 12:
                refuse("%s uses palette slot %d" % (symbol, max(pals)))
            if 6 in pals:  # Emerald secondary slot 6 is loaded from the primary in FRLG
                free = [s for s in (10, 11, 12) if s not in pals]
                if not free:
                    refuse("%s uses palette 6 and slots 10-12: no free FRLG slot" % symbol)
                self.pal_map[6] = free[0] if free else 6
            self.pal_map.update(PALETTE_SWAPS.get(symbol, {}))
            self.meta = [tile_map.get(e & 0x3FF, e & 0x3FF) | e & 0x0C00 | self.pal_map.get(e >> 12, e >> 12) << 12
                         for m in self.metas for e in entries(m)]
            self.num_tiles = len(self.tiles)
        self.index = {m: i for i, m in enumerate(self.metas) if m is not None}
        base = EM["metatiles"] if self.secondary else 0
        self.attrs = [0 if m is None else behaviors.convert(self.em_attrs[m - base]) for m in self.metas]
        # Metatiles this run adds: only a legacy pruned secondary grows. A tileset here that gets nothing new is left as
        # it is (write(): Porymap edits stay); one that grows must still hold what this tool wrote (append-only ids).
        if not self.legacy:
            known = 0 if self.new else len(self.metas)
        self.grows = len(self.metas) - known
        if self.grows and not self.new:
            old_meta = read_ints(REPO / self.dir / "metatiles.bin", "H")
            old_attrs = read_ints(REPO / self.dir / "metatile_attributes.bin", "I")
            if old_meta != self.meta[:len(old_meta)] or old_attrs != self.attrs[:len(old_attrs)] \
                    or len(old_meta) != 8 * len(old_attrs) or len(old_attrs) != known:
                refuse("%s: metatiles.bin / metatile_attributes.bin are not what hoenn_import wrote (edited in "
                       "Porymap?) and this import must add metatiles to them: not overwritten. Restore them with git, "
                       "or move hand-made metatiles to a tileset of your own" % self.dir)

    def write(self):
        if not self.new and not self.grows:
            return
        dst = REPO / self.dir
        for i in range(16):
            copy(self.src / ("palettes/%02d.pal" % i), dst / ("palettes/%02d.pal" % i))
        for old, new in self.pal_map.items():
            copy(self.src / ("palettes/%02d.pal" % old), dst / ("palettes/%02d.pal" % new))
        if not self.secondary:
            copy(self.src / "tiles.png", dst / "tiles.png")
        else:
            per_row = self.png.width // 8
            # never empty: a pruned secondary whose metatiles only use primary tiles still needs an image (gbagfx)
            out = Image.new("P", (128, max(1, math.ceil(len(self.tiles) / 16)) * 8), 0)
            out.putpalette((self.png.getpalette() + [0] * 48)[:48])
            for i, t in enumerate(self.tiles):
                x, y = (t - EM["tiles"]) % per_row * 8, (t - EM["tiles"]) // per_row * 8
                out.paste(self.png.crop((x, y, x + 8, y + 8)), (i % 16 * 8, i // 16 * 8))
            save_png(out, dst / "tiles.png")
        write_ints(dst / "metatiles.bin", "H", self.meta)
        write_ints(dst / "metatile_attributes.bin", "I", self.attrs)
        if self.pruned:
            write(self.ids_path, '{\n  "_": "tools/hoenn_import: FRLG metatile (tile) 640 + i = Emerald metatiles[i] '
                                 '(tiles[i]); %s",\n  "metatiles": %s,\n  "tiles": %s\n}\n'
                                 % ("append-only, never reorder" if self.legacy else
                                    "null = empty; natural ids, design 1.8: never edit",
                                    json.dumps(self.metas), json.dumps(self.tiles)))

    def count(self):
        """Metatiles it holds (a natural-id one has empty slots)."""
        return sum(m is not None for m in self.metas)

    def remap_metatile(self, m):
        """Emerald metatile id -> FRLG id (primary: unchanged; secondary: 640 + its position, = id + 128 unpruned)."""
        if m not in self.index:
            refuse("gTileset_%s has no Emerald metatile 0x%03X" % (self.em_name, m))
            return 0
        return self.index[m] + (FR["metatiles"] if self.secondary else 0)


# ---------------------------------------------------------------- render check

def load_tiles(data):
    img = Image.open(io.BytesIO(data))
    return [img.crop((x, y, x + 8, y + 8)).tobytes()
            for y in range(0, img.height, 8) for x in range(0, img.width, 8)]


def load_pals(directory):
    pals = []
    for i in range(16):
        v = read(directory / ("palettes/%02d.pal" % i)).split()
        assert v[0] == "JASC-PAL"
        pals.append([tuple(map(int, v[3 + 3 * c:6 + 3 * c])) + (255,) for c in range(int(v[2]))])
    return pals


_TILESETS = {}  # (folder, engine) -> its tiles, palettes, metatiles, attributes; cleared when the checks start


def tileset_data(directory, engine):
    key = (Path(directory), engine)
    if key not in _TILESETS:
        planned = dict(PENDING)
        if engine == "before":  # the files as they are on disk: the plan set aside meanwhile
            PENDING.clear()
        try:
            _TILESETS[key] = (load_tiles(read_bytes(key[0] / "tiles.png")), load_pals(key[0]),
                              read_ints(key[0] / "metatiles.bin", "H"),
                              read_ints(key[0] / "metatile_attributes.bin", "H" if engine == "emerald" else "I"))
        finally:
            PENDING.update(planned)
    return _TILESETS[key]


def render(blocks, width, primary_dir, secondary_dir, engine):
    """Draw a map.bin like DrawMetatile (field_camera.c) does: BG3, then BG2, then BG1. A metatile the tileset lacks
    is magenta. engine: "emerald", "frlg" (this repo, the planned files included) or "before" (this repo's files as
    they are on disk)."""
    lim = EM if engine == "emerald" else FR
    layer_of = (lambda a: a >> 12) if engine == "emerald" else (lambda a: a >> 29 & 3)
    tiles, pals, meta, attrs = zip(*(tileset_data(d, engine) for d in (primary_dir, secondary_dir)))
    cache = {}

    def tile_img(e):
        if e not in cache:
            t, p = e & 0x3FF, e >> 12
            ts, i = (0, t) if t < lim["tiles"] else (1, t - lim["tiles"])
            img = Image.new("RGBA", (8, 8), (255, 0, 255, 255))  # beyond tiles.png (Emerald junk): must not show
            if i < len(tiles[ts]):
                pal = pals[0][p] if p < lim["pals"] else pals[1][p]
                img.putdata([pal[c] if c else (0, 0, 0, 0) for c in tiles[ts][i]])
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
        x, y = i % width * 16, i // width * 16
        if idx >= len(attrs[ts]):
            out.paste((255, 0, 255, 255), (x, y, x + 16, y + 16))
            continue
        entries, layer = meta[ts][idx * 8:idx * 8 + 8], layer_of(attrs[ts][idx])
        bottom, top, empty = entries[:4], entries[4:], [0] * 4
        for quad in {0: ([0x3014] * 4, bottom, top), 1: (bottom, top, empty), 2: (bottom, empty, top)}[layer]:
            for k, e in enumerate(quad):
                out.alpha_composite(tile_img(e), (x + k % 2 * 8, y + k // 2 * 8))
    return out


# ---------------------------------------------------------------- objects / events / warps

def hoenn_info(gfx):
    """Graphics info of this repo's OBJ_EVENT_GFX_HOENN_ id `gfx` (a pokeemerald sprite, made for the Emerald NPC
    palettes Hoenn layouts load), None for any other id."""
    if not gfx.startswith("OBJ_EVENT_GFX_HOENN_"):
        return None
    pointers = read(REPO / "src/data/object_events/object_event_graphics_info_pointers.h")
    m = re.search(r"\[%s\]\s*=\s*&(\w+)" % gfx, table(pointers, "gObjectEventGraphicsInfoPointers"))
    return m.group(1) if m else None


def npc_gfx(em_gfx):
    """This repo's id of Emerald's OBJ_EVENT_GFX_X: OBJ_EVENT_GFX_HOENN_X once tools/hoenn_import/hoenn_sprites.py
    imported it (it skips the player avatar states, link avatars, berry trees, secret base decorations), else None."""
    gfx = em_gfx.replace("OBJ_EVENT_GFX_", "OBJ_EVENT_GFX_HOENN_", 1)
    return gfx if hoenn_info(gfx) else None


def hoenn_map_gfx(map_name, gfx):
    """The Hoenn id an object of the Hoenn map `map_name` shows: its own, or for a VAR id the one VAR_GFX gives (the
    map's script sets the var). None: a Kanto sprite, drawn with the wrong (Emerald) NPC palettes there."""
    em_gfx = VAR_GFX.get((map_name, gfx))
    return npc_gfx(em_gfx) if em_gfx else gfx if hoenn_info(gfx) else None


def hoenn_gfx_problem(map_name, gfx):
    """Why an object showing `gfx` on the Hoenn map `map_name` is wrong, None if it is fine."""
    shown = hoenn_map_gfx(map_name, gfx)
    if not shown:
        return "not a pokeemerald sprite (Hoenn maps use Emerald's NPC palettes): use an OBJ_EVENT_GFX_HOENN_ id"
    path = REPO / "src/data/object_events"
    inanimate, anims = re.search(r"%s = \{.*?\.inanimate = (\w+),.*?\.anims = (\w+)," % hoenn_info(shown),
                                 read(path / "object_event_graphics_info.h"), re.S).groups()
    entries = re.findall(r"\bsAnim_\w+", table(read(path / "object_event_anims.h"), anims + "[]").split("{", 1)[1])
    if inanimate != "TRUE" and len(entries) < 4:
        return "%s lacks the 4 facing anims the engine starts (pokeemerald never places it on a map)" % anims
    return None


def check_gfx():
    """Objects of every map.json (Porymap edits too) drawn with the wrong NPC palettes: anything but an
    OBJ_EVENT_GFX_HOENN_ id (or a VAR id VAR_GFX resolves to one) on a Hoenn layout, an OBJ_EVENT_GFX_HOENN_ id
    elsewhere. Porymap previews both with the right colors. Also a Hoenn sprite that cannot face every way."""
    layouts = {l["id"]: l for l in json.loads(read(REPO / "data/layouts/layouts.json"))["layouts"] if "id" in l}
    bad = []
    for path in sorted((REPO / "data/maps").glob("*/map.json")):
        mj = json.loads(read(path))
        hoenn = layouts[mj["layout"]]["primary_tileset"] in HOENN_PRIMARIES
        for o in mj["object_events"]:
            gfx = o.get("graphics_id", "")
            problem = hoenn_gfx_problem(path.parent.name, gfx) if hoenn else \
                gfx.startswith("OBJ_EVENT_GFX_HOENN_") and "a pokeemerald sprite on a non-Hoenn layout"
            if problem:
                bad.append("%s (%d,%d): %s: %s" % (path.parent.name, o["x"], o["y"], gfx, problem))
    return bad


def sprite_frames(info):
    """Frames of this repo's graphics info `info` (walking needs 9)."""
    path = REPO / "src/data/object_events"
    images = re.search(r"%s = \{.*?\.images = (\w+)" % info, read(path / "object_event_graphics_info.h"), re.S).group(1)
    return len(re.findall(r"\b(?:overworld_frame|obj_frame_tiles)\(", table(read(path / "object_event_pic_tables.h"),
                                                                       images + "[]")))


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


def inside(m, x, y):
    return 0 <= x < m.width and 0 <= y < m.height


def reached_warps(m, blocked):
    """Warps of map `m` the player reaches from its first warp: by stepping on them, or facing north into a door.
    A warp outside the map is only an arrival point."""
    warps = [(i, w) for i, w in enumerate(m.em_map["warp_events"]) if inside(m, w["x"], w["y"])]
    if not warps:
        return set()
    tiles = walkable_from(m.blocks, m.width, (warps[0][1]["x"], warps[0][1]["y"]), blocked)
    return {i for i, w in warps if (w["x"], w["y"]) in tiles
            or (m.warp_behaviors[i][0] == "MB_ANIMATED_DOOR" and (w["x"], w["y"] + 1) in tiles)}


def repo_labels():
    """Script labels this repo defines -> the map whose scripts.inc defines it, None for data/scripts and data/*.s (a
    map may use one of another map: the Museum's bird sculpture)."""
    files = [*(REPO / "data/maps").glob("*/scripts.inc"), *(REPO / "data/scripts").glob("*.inc"), *(REPO / "data").glob("*.s")]
    return {l: p.parent.name if p.parent.parent.name == "maps" else None for p in files
            for l in re.findall(r"^(\w+)::", read(p), re.M)}


def map_script(map_name, label, labels):
    """This repo's script for Emerald's `label` on `map_name`, None if there is none yet: Emerald's label once a
    data/maps/*/scripts.inc defines it (Common_X: <Map>_X first, a map's own version), else COMMON_SCRIPTS."""
    local = re.sub(r"^Common_", map_name + "_", label)
    return next((l for l in (local, label) if l in labels), COMMON_SCRIPTS.get(label))


def script_label(ctx, m, label, comment):
    """The script of an NPC or sign: map_script(), else Emerald's label (Common_X: <Map>_X) as a silent stub, in the
    map's new scripts.inc when the label is its own, else in data/scripts/hoenn_stubs.inc."""
    if label in ("0x0", "0", ""):
        return "0x0"
    found = map_script(m.name, label, ctx.labels)
    if found:
        return found
    local = re.sub(r"^Common_", m.name + "_", label)
    ctx.labels[local] = m.name
    if m.new_scripts and local.startswith(m.name + "_"):
        m.stubs.append((local, comment))
    else:
        ctx.shared_stubs[local].append("%s %s" % (m.name, comment))
    return local


_DEFINES = [None, set()]


def defined(name):
    """True if include/constants defines `name` (the planned headers included)."""
    if _DEFINES[0] != _CONSTANTS[0]:
        _DEFINES[:] = [_CONSTANTS[0], {n for p in (REPO / "include/constants").glob("*.h")
                                       for n in re.findall(r"#define\s+(\w+)", read(p))}]
    return name in _DEFINES[1]


def flag_here(ctx, flag, where):
    """Emerald's `flag` here: its definition if there is one, else it takes the first free FLAG_0x line of FLAG_RANGES
    in flags.h (design 1.4a: nothing moves, so the flags of saves keep their meaning). Listed in ctx.allocated. A flag
    defined here but not by this tool (Kanto's) is refused: the two objects would share it."""
    if flag in ("0", 0):  # no flag
        return
    text = read(FLAGS_H)
    if defined(flag):
        value = re.search(r"^#define %s\s+0x([0-9A-F]{3})\b" % flag, text, re.M)
        if not flag.startswith("FLAG_TEMP_") and not (value and any(lo <= int(value.group(1), 16) <= hi
                                                                    for lo, hi in FLAG_RANGES)):
            refuse("%s (%s) is already a flag of this repo: rename its map (hoenn_decisions.RENAMES)" % (flag, where))
        return
    for m in re.finditer(r"^#define FLAG_0x([0-9A-F]{3})[ \t]+0x\1\b", text, re.M):
        value = int(m.group(1), 16)
        if any(lo <= value <= hi for lo, hi in FLAG_RANGES):
            write(FLAGS_H, text[:m.start()] + "#define %-40s 0x%03X" % (flag, value) + text[m.end():])
            ctx.allocated.append("  %s = 0x%03X  %s" % (flag, value, where))
            return
    refuse("no free flag left for %s (%s): the FLAG_0x lines of design 1.4a are all taken" % (flag, where))


def item_here(item):
    """This repo's constant for Emerald's ITEM_X: the same name, or the TM / HM of the same move
    (ITEM_TM_FOCUS_PUNCH -> ITEM_TM01_FOCUS_PUNCH, include/constants/items.h); None if there is none."""
    if defined(item):
        return item
    tm = re.fullmatch(r"ITEM_(TM|HM)_(\w+)", item)
    return next((n for n in sorted(_DEFINES[1]) if re.fullmatch(r"ITEM_%s\d\d_%s" % tm.groups(), n)), None) if tm else None


def item_ball(ctx, m, o, item):
    """The script of an item ball placed on map `m`: this repo's for Emerald's label, else that label in the map's new
    scripts.inc (m.scripts, before the stubs) with the same body as Emerald's: `finditem` of this repo's `item`."""
    script = map_script(m.name, o["script"], ctx.labels)
    if script:
        return script
    if not m.new_scripts:
        refuse("%s: item ball (%d,%d): %s is not defined and the map's scripts.inc already exists: add it there"
               % (m.name, o["x"], o["y"], o["script"]))
    ctx.labels[o["script"]] = m.name
    m.scripts.append((o["script"], "item ball, works (%s)" % o["flag"], "\tfinditem %s\n\tend\n" % item))
    return o["script"]


def hidden_item(ctx, m, b):
    """This repo's bg_event for an Emerald hidden item: this repo's item, Emerald's flag (flag_here; the event stores
    the absolute flag, engine E1), found by facing it as in Emerald (underfoot false). None if the item is missing."""
    item = item_here(b["item"])
    if not item:
        refuse("%s: hidden item (%d,%d): %s does not exist here" % (m.name, b["x"], b["y"], b["item"]))
        return None
    flag_here(ctx, b["flag"], "%s hidden item (%d,%d)" % (m.name, b["x"], b["y"]))
    return dict(b, item=item, quantity=1, underfoot=False)


def hidden_reason(ctx, flag):
    """Why the decided post-League state hides an object with `flag`; None: it is shown."""
    if flag in ("0", 0):
        return None
    if flag in POST_LEAGUE:
        shown, why = POST_LEAGUE[flag]
        return None if shown else "%s: %s" % (flag, why)
    if flag in HIDDEN_BY_MAP_SCRIPT:
        return "%s: %s" % (flag, HIDDEN_BY_MAP_SCRIPT[flag])
    if ctx.story_flag(flag):
        refuse("missing decision: %s, an object flag Emerald's story toggles: give its post-League state in "
               "hoenn_decisions.POST_LEAGUE (or HIDDEN_BY_MAP_SCRIPT)" % flag)
        return "%s: no decision" % flag
    return "%s set at new game" % flag if flag in ctx.new_game else None


def convert_objects(ctx, m):
    """Emerald object_events -> this repo's; fills m.dropped, m.stubs, m.localids."""
    warps = {(w["x"], w["y"]) for w in m.em_map["warp_events"]}
    kept = []
    for o in m.em_map["object_events"]:
        where = "%s (%d,%d)" % (o.get("graphics_id"), o.get("x", -1), o.get("y", -1))
        if o.get("type", "object") != "object":
            refuse("%s %s: clone objects are not handled" % (m.name, where))
            continue
        moved = MOVED_BY_MAP_SCRIPT.get((m.name, o.get("local_id")))
        if moved:  # where Emerald's map script puts it after the League
            o = dict(o, x=moved[0], y=moved[1], movement_type=moved[2])
        # an item ball works at import (`finditem`); a ball that runs a story script is an NPC (Steven's Beldum)
        em_item = ctx.found_item(o["script"]) if o["graphics_id"] == "OBJ_EVENT_GFX_ITEM_BALL" else None
        item, field_move = em_item and item_here(em_item), o["script"] in FIELD_MOVE_SCRIPTS
        reason = None
        if em_item:
            if not item:
                refuse("%s %s: item ball of %s, which does not exist here" % (m.name, where, em_item))
                reason = "unknown item"
        elif o["trainer_type"] == "TRAINER_TYPE_BURIED":
            reason = "buried trainer (only its script shows it)"
        elif skipped(o["graphics_id"].replace("OBJ_EVENT_GFX_", "", 1)):
            reason = "sprite not imported (berry tree, decoration: hoenn_sprites.skipped)"
        elif not field_move:
            reason = hidden_reason(ctx, o["flag"])
        if not reason and (o["x"], o["y"]) in warps:
            reason = "stands on a warp"
        if reason:
            m.dropped.append("%s: %s" % (where, reason))
            continue
        em_gfx = VAR_GFX.get((m.name, o["graphics_id"]), o["graphics_id"])
        gfx = npc_gfx(em_gfx)
        if not gfx:
            refuse("%s on %s: %s not imported (tools/hoenn_import/hoenn_sprites.py skipped() it); a VAR id needs a "
                   "decision in hoenn_decisions.VAR_GFX" % (o["graphics_id"], m.name, em_gfx))
            continue
        movement = o["movement_type"]
        if not defined(movement):
            slow = movement.replace("WALK_SLOWLY_IN_PLACE", "WALK_IN_PLACE")
            if slow != movement and defined(slow):
                m.dropped.append("%s: %s -> %s (DEGRADED: no slow version here)" % (where, movement, slow))
                movement = slow
            else:
                refuse("%s %s: unknown movement type %s" % (m.name, where, movement))
        moving = "WANDER" in movement or "WALK" in movement
        if moving and sprite_frames(hoenn_info(gfx)) < 9:
            refuse("%s %s walks: %s has no walking frames" % (m.name, where, gfx))
        kept.append((o, em_gfx, gfx, movement, moving or field_move or bool(item), item, field_move or bool(item)))
    # a still object must not cut the way to a warp (moving ones step aside, a field move clears an obstacle)
    base, obstacles, objects = reached_warps(m, set()), set(), []
    for o, em_gfx, gfx, movement, passable, item, keep_flag in kept:
        pos = (o["x"], o["y"])
        lost = sorted(base - reached_warps(m, obstacles | {pos})) if not passable else []
        if lost:
            m.dropped.append("%s (%d,%d): blocks the way to warp %s" % (o["graphics_id"], o["x"], o["y"], lost))
            continue
        if not passable:
            obstacles.add(pos)
        n = len(objects) + 1  # its local id
        if o["trainer_type"] != "TRAINER_TYPE_NONE":
            comment = "trainer #%d (%d,%d) %s, Emerald %s sight %s" % (
                n, o["x"], o["y"], ctx.trainer_id(o["script"]) or "no trainerbattle", o["trainer_type"][13:],
                o["trainer_sight_or_berry_tree_id"])
        else:
            comment = "NPC #%d (%d,%d)" % (n, o["x"], o["y"])
        if keep_flag:  # removeobject sets it: an item ball or obstacle stays gone (a permanent Emerald flag is allocated)
            flag_here(ctx, o["flag"], "%s (%d,%d) %s" % (m.name, o["x"], o["y"], "item ball" if item else o["script"]))
        if item:
            script = item_ball(ctx, m, o, item)
        else:
            script = map_script(m.name, o["script"], ctx.labels) if keep_flag else script_label(ctx, m, o["script"], comment)
        if o.get("local_id"):
            if defined(o["local_id"]):
                m.dropped.append("%s: %s is a constant here, no .equ" % (where, o["local_id"]))
            else:
                m.localids.append((o["local_id"], n))
        objects.append({
            "type": "object",
            "graphics_id": gfx,
            "x": o["x"],
            "y": o["y"],
            "elevation": o["elevation"],
            "movement_type": movement,
            "movement_range_x": o["movement_range_x"],
            "movement_range_y": o["movement_range_y"],
            "trainer_type": "TRAINER_TYPE_NONE",
            "trainer_sight_or_berry_tree_id": "0",
            "script": script or "0x0",
            "flag": o["flag"] if keep_flag else "0",
            "in_connection": False,
        })
        m.gfx_used[o["graphics_id"], em_gfx, gfx] += 1
    for o in objects:
        problem = hoenn_gfx_problem(m.name, o["graphics_id"])
        if problem:
            refuse("%s (%d,%d): %s: %s" % (m.name, o["x"], o["y"], o["graphics_id"], problem))
    return objects


def convert_events(ctx, m):
    """Emerald signs, hidden items, weather events and triggers -> this repo's bg_events and coord_events."""
    bg, coord = [], []
    for b in m.em_map["bg_events"]:
        if b["type"] == "sign":
            x, y = SIGN_MOVES.get((m.name, b["x"], b["y"]), (b["x"], b["y"]))
            if not inside(m, x, y) and b["script"] in ("0x0", "0", ""):
                m.dropped.append("sign (%d,%d): outside the map, no script (left over in Emerald)" % (x, y))
                continue
            if not inside(m, x, y):
                refuse("%s: sign (%d,%d) lies outside the map: give it a place in hoenn_decisions.SIGN_MOVES"
                       % (m.name, x, y))
                continue
            bg.append(dict(b, x=x, y=y, script=script_label(ctx, m, b["script"], "sign (%d,%d)" % (x, y))))
            continue
        if b["type"] == "hidden_item":
            event = hidden_item(ctx, m, b)  # None: refused
            if event:
                bg.append(event)
        else:
            m.dropped.append("%s (%d,%d): no secret bases" % (b["type"], b["x"], b["y"]))
    for c in m.em_map.get("coord_events") or []:
        if c["type"] == "weather":
            if defined(c["weather"]):
                coord.append(dict(c))
            else:
                refuse("%s: weather event (%d,%d): %s is not defined here" % (m.name, c["x"], c["y"], c["weather"]))
            continue
        script = map_script(m.name, c["script"], ctx.labels)
        if script and defined(c["var"]):
            coord.append(dict(c, script=script))
        else:
            m.left_out.append("trigger (%d,%d) %s==%s -> %s" % (c["x"], c["y"], c["var"], c["var_value"], c["script"]))
            m.dropped.append("trigger (%d,%d) %s: not placed until scripted" % (c["x"], c["y"], c["script"]))
    return bg, coord


def resolve_warp(w, here):
    """(dest map, dest warp id) of an Emerald warp here, None if its destination does not exist here (yet)."""
    dest, dest_id = w["dest_map"], w["dest_warp_id"]
    if dest == "MAP_DYNAMIC":
        return dest, dest_id
    if dest in WARP_ALIASES:
        return WARP_ALIASES[dest], dest_id
    if dest not in here:
        return None
    if not 0 <= int(dest_id) < here[dest]:
        refuse("a warp to %s #%s: that map has %d warps" % (dest, dest_id, here[dest]))
    return dest, dest_id


def connections(em_map, here):
    """Emerald's connections of a map that lead to maps existing here (Emerald lists both sides with matching offsets),
    dive and emerge ones included."""
    return [{"direction": c["direction"], "offset": c["offset"], "map": c["map"]}
            for c in em_map.get("connections") or [] if c["direction"] in DIRECTIONS + DIVE and c["map"] in here]


def convert_header(ctx, m):
    j = m.em_map
    music = ctx.music(j["music"])
    if not music:
        refuse("%s: music %s has no track with its value here" % (m.name, j["music"]))
    if j["map_type"] == "MAP_TYPE_UNDERWATER" and not defined(ENGINE_STEP3):
        refuse("%s: an underwater map needs the engine work of step 3 (Hoenn dive and emerge, region map guard), "
               "missing here: %s is not in include/constants/metatile_behaviors.h" % (m.name, ENGINE_STEP3))
    scene = j["battle_scene"] if defined(j["battle_scene"]) else BATTLE_SCENES.get(j["battle_scene"], j["battle_scene"])
    if scene == "MAP_BATTLE_SCENE_NORMAL" != j["battle_scene"]:
        m.dropped.append("battle scene %s -> %s (DEGRADED: no such background here)" % (j["battle_scene"], scene))
    mapsec = MAPSECS.get(j["region_map_section"], j["region_map_section"])
    for value in (mapsec, j["weather"], j["map_type"], scene):
        if not defined(value):
            refuse("%s: %s does not exist in this repo" % (m.name, value))
    return {
        "id": j["id"],
        "name": m.name,
        "layout": m.new_layout["id"],
        "music": music or j["music"],
        "region_map_section": mapsec,
        "requires_flash": j["requires_flash"],
        "weather": j["weather"],
        "map_type": j["map_type"],
        "allow_cycling": j["allow_cycling"],
        "allow_escaping": j["allow_escaping"],
        "allow_running": j["allow_running"],
        "show_map_name": j["show_map_name"],
        "floor_number": j.get("floor_number", 0),
        "battle_scene": scene,
    }


def convert_map_json(ctx, m, here):
    out = convert_header(ctx, m)
    objects = convert_objects(ctx, m)
    bg, coord = convert_events(ctx, m)
    warps = []
    for i, w in enumerate(m.em_map["warp_events"]):
        dest = None if (m.name, i) in CLOSED_WARPS else resolve_warp(w, here)
        if not dest:  # map not imported (yet): warps onto itself, relink() points it once the map is here
            dest = m.em_map["id"], str(i)
            m.placeholders.append("%s warp %d -> %s #%s%s" % (m.name, i, w["dest_map"], w["dest_warp_id"],
                                  "  CLOSED: " + CLOSED_WARPS[(m.name, i)] if (m.name, i) in CLOSED_WARPS else ""))
        warps.append({"x": w["x"], "y": w["y"], "elevation": w["elevation"], "dest_map": dest[0], "dest_warp_id": dest[1]})
    out.update(connections=connections(m.em_map, here) or 0,  # 0: like the other connection-less maps of this repo
               object_events=objects, warp_events=warps, coord_events=coord, bg_events=bg,
               level_scaling="0")  # read by this repo's mapjson; trainer-only
    return out


def stub_scripts(ctx, m):
    """The new scripts.inc of map `m`: LOCALIDs, the map script table, the stubs of its labels, what is left out."""
    text = "".join(".equ %s, %d\n" % lid for lid in m.localids) + ("\n" if m.localids else "")
    text += "%s_MapScripts::\n\t.byte 0\n" % m.name
    em_scripts = ctx.map_scripts(m.name)
    if em_scripts:
        text += "@ hoenn_import: Emerald map scripts not ported: %s\n" % ", ".join("%s (%s)" % s for s in em_scripts)
    text += "".join(("%s::" % label).ljust(47) + " @ %s\n%s" % (comment, body) for label, comment, body in m.scripts)
    if m.stubs:
        text += ("@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/%s/scripts.inc\n"
                 % ctx.folder[m.name])
        text += "".join(("%s::" % label).ljust(47) + " @ %s\n" % comment for label, comment in m.stubs) + "\tend\n"
    if m.left_out:
        text += "@ hoenn_import: left out: %s\n" % "; ".join(m.left_out)
    return text


def write_shared_stubs(ctx):
    """Stubs of Emerald labels another map owns (PlayersHouse_1F_EventScript_Mom...) in data/scripts/hoenn_stubs.inc."""
    if not ctx.shared_stubs:
        return
    text = read(STUBS) if exists(STUBS) else (
        "@ hoenn_import: silent stubs of the Emerald scripts that Hoenn maps run and no scripts.inc defines yet.\n"
        "@ Script one in its map's scripts.inc (or in data/scripts/), then delete its stub here.\n")
    for label, users in ctx.shared_stubs.items():
        text += "\n%s @ %s\n\tend\n" % (("%s::" % label).ljust(47), "; ".join(users))
    write(STUBS, text)
    include = '\t.include "data/scripts/hoenn_stubs.inc"\n'
    append_once(REPO / "data/event_scripts.s", include, include)


# ---------------------------------------------------------------- repo registration

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
    num_tiles = max(1, ts.num_tiles)  # gbagfx refuses 0
    text = read(rules)
    if target in text:
        if ts.grows:  # a tileset that gets nothing new keeps its rule (hand edits)
            write(rules, re.sub(re.escape(target) + r"(\t\$\(GFX\) \$< \$@ -num_tiles )\d+",
                                lambda m: target + m.group(1) + str(num_tiles), text))
    else:
        append_once(rules, target, target + "\t$(GFX) $< $@ -num_tiles %d -Wnum_tiles\n" % num_tiles)


def em_labels(em, em_name):
    """Emerald's METATILE_<em_name>_X labels: [(X, Emerald metatile id)]."""
    return [(n, int(v, 16)) for n, v in re.findall(r"#define METATILE_%s_(\w+)\s+(0x[0-9A-Fa-f]+)" % em_name,
                                                   read(em / "include/constants/metatile_labels.h"))]


def register_labels(em, ts):
    """METATILE_<Emerald set>_X -> METATILE_<FRLG set>_X for the metatiles the tileset has here: the missing ones end
    its section (made if needed); the lines already there, hand-made ones too, stay."""
    labels = [(n, ts.remap_metatile(v)) for n, v in em_labels(em, ts.em_name) if v in ts.index]
    path = REPO / "include/constants/metatile_labels.h"
    text = read(path)
    width = max([len("METATILE_%s_%s" % (ts.name, n)) for n, _ in labels], default=0) + 2
    lines = "".join("#define %s0x%03X\n" % (("METATILE_%s_%s" % (ts.name, n)).ljust(width), v) for n, v in labels
                    if not re.search(r"#define METATILE_%s_%s\b" % (ts.name, n), text))
    if not lines:
        return
    section = re.search(r"^// gTileset_%s\r?\n(?:#define .*\n)*" % ts.name, text, re.M)
    if section:
        pos = section.end()
    else:
        after = [m for m in re.finditer(r"^// gTileset_(\w+)\r?\n", text, re.M) if m.group(1) > ts.name]
        pos = after[0].start() if after else text.index("// Other")
        lines = "// gTileset_%s\n%s\n" % (ts.name, lines)
    write(path, text[:pos] + lines + text[pos:])


def write_map_constants():
    """include/constants/map_groups.h and layouts.h exactly as tools/mapjson makes them from the planned JSON files.
    They are tracked in git: committed with the import, no build compiles with stale ones (make takes the copies a
    fresh build mirror gets after the JSON files for up to date)."""
    groups = json.loads(read(REPO / "data/maps/map_groups.json"))
    text = ("#ifndef GUARD_CONSTANTS_MAP_GROUPS_H\n#define GUARD_CONSTANTS_MAP_GROUPS_H\n\n"
            "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n//\n\n")
    for g, group in enumerate(groups["group_order"]):
        ids = [json.loads(read(REPO / "data/maps" / name / "map.json"))["id"] for name in groups[group]]
        width = max(map(len, ids), default=0)
        text += "// %s\n%s\n" % (group, "".join("#define %s (%d | (%d << 8))\n" % (i.ljust(width), n, g)
                                               for n, i in enumerate(ids)))
    write(REPO / "include/constants/map_groups.h", text + "#define MAP_GROUPS_COUNT %d\n\n"
          "#endif // GUARD_CONSTANTS_MAP_GROUPS_H\n" % len(groups["group_order"]))
    layouts = json.loads(read(REPO / "data/layouts/layouts.json"))["layouts"]
    write(REPO / "include/constants/layouts.h", "#ifndef GUARD_CONSTANTS_LAYOUTS_H\n#define GUARD_CONSTANTS_LAYOUTS_H\n\n"
          "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from data/layouts/layouts.json\n//\n\n%s\n"
          "#endif // GUARD_CONSTANTS_LAYOUTS_H\n" % "".join("#define %s %d\n" % (l["id"], i)
                                                           for i, l in enumerate(layouts, 1) if l))


def plan_layout(em_layout, repo_layouts):
    """This repo's layout entry for an Emerald layout: Emerald's id, or LAYOUT_HOENN_* when the id is a Kanto one."""
    ours = lambda l: l["primary_tileset"].startswith("gTileset_Hoenn")
    lid, name = em_layout["id"], em_layout["name"]
    folder = rename(Path(em_layout["blockdata_filepath"]).parent.name)
    renamed = any(l.get("id") == lid and not ours(l) for l in repo_layouts)
    if renamed:
        lid, name, folder = "LAYOUT_HOENN_" + lid[len("LAYOUT_"):], "Hoenn_" + name, "Hoenn_" + folder
    for l in repo_layouts:  # only a layout this tool made may be reused
        if l.get("id") == lid or l.get("blockdata_filepath", "").startswith("data/layouts/%s/" % folder):
            if not (ours(l) and l["id"] == lid):
                refuse("%s (%s) already exists in this repo: not replaced" % (l.get("id"), l.get("blockdata_filepath")))
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


# ---------------------------------------------------------------- plan

def hoenn_maps(ctx):
    """{MAP_ id: folder} of this repo's maps imported from Emerald (an Emerald map name on a Hoenn layout)."""
    layouts = {l["id"]: l for l in json.loads(read(REPO / "data/layouts/layouts.json"))["layouts"] if "id" in l}
    out = {}
    for p in (REPO / "data/maps").glob("*/map.json"):
        if p.parent.name in ctx.maps:
            mj = json.loads(read(p))
            if layouts.get(mj.get("layout"), {}).get("primary_tileset") in HOENN_PRIMARIES:
                out[mj["id"]] = p.parent.name
    return out


def plan(ctx, names, group_of):
    """Plan the import of the Emerald maps `names` (group_of[name]: the map group a new one joins) in PENDING."""
    em = ctx.root
    repo_layouts = json.loads(read(REPO / "data/layouts/layouts.json"))["layouts"]
    existing = hoenn_maps(ctx)
    groups = json.loads(read(REPO / "data/maps/map_groups.json"))
    # a folder no group lists is what an undone import left (git checkout keeps untracked files): the same files are
    # planned over it, and a different one is refused as uncommitted (check_files)
    folders = {name for g in groups["group_order"] for name in groups[g]}
    ctx.labels, ctx.shared_stubs, ctx.allocated = repo_labels(), defaultdict(list), []
    maps = []
    for name in dict.fromkeys(names):
        if name not in ctx.maps:
            refuse("%s is not an Emerald map" % name, fatal=True)
        em_map = ctx.maps[name]
        layout = ctx.layout_of(name)
        blocks, border = read_ints(em / layout["blockdata_filepath"], "H"), read_ints(em / layout["border_filepath"], "H")
        if len(blocks) != layout["width"] * layout["height"] or len(border) != 4:
            refuse("%s: unexpected Emerald layout files" % name, fatal=True)
        m = SimpleNamespace(name=name, em_map=em_map, layout=layout, blocks=blocks, border=border, width=layout["width"],
                            height=layout["height"], group=group_of[name], exists=existing.get(em_map["id"]) == name,
                            gfx_used=Counter(), dropped=[], scripts=[], stubs=[], localids=[], left_out=[],
                            placeholders=[], differences=[], map_json=None)
        if not m.exists and name in folders:
            refuse("data/maps/%s already exists and is not the Hoenn map this tool makes: not replaced" % name)
        if not m.exists and defined(em_map["id"]):
            refuse("%s: %s is already a map of this repo: rename it (hoenn_decisions.RENAMES)" % (name, em_map["id"]))
        for e in em_map["object_events"] + em_map["bg_events"] + (em_map.get("coord_events") or []):
            owner = ctx.labels.get(e.get("script"))  # the map defining it: not an Emerald one (Kanto) = a clash
            if not m.exists and owner not in (None, name) and owner not in ctx.maps:
                refuse("%s: its script %s is %s's here: rename it (hoenn_decisions.RENAMES)" % (name, e["script"], owner))
        group = groups.get(m.group)
        if not m.exists and group and m.group != "gMapGroup_TownsAndRoutes" and any(n not in ctx.maps for n in group):
            refuse("%s holds maps that are not Emerald's: %s does not go there" % (m.group, name))
        m.new_scripts = not exists(REPO / "data/maps" / name / "scripts.inc")
        maps.append(m)

    # tilesets: each converted once, with the metatiles of every map of the batch that uses it
    used = defaultdict(set)
    for m in maps:
        m.keys = ((m.layout["primary_tileset"], 0),
                  (m.layout["secondary_tileset"], sibling_of(m.layout["secondary_tileset"], m.layout["id"])))
        for block in m.blocks + m.border:
            used[m.keys[block & 0x3FF >= EM["metatiles"]]].add(block & 0x3FF)
    tilesets = {}
    for m in maps:
        for key in m.keys:
            if key not in tilesets:
                tilesets[key] = Tileset(ctx, *key, used[key])
        m.primary, m.secondary = (tilesets[key] for key in m.keys)
        if m.primary.secondary or not m.secondary.secondary:
            refuse("%s: primary / secondary tilesets swapped" % m.name, fatal=True)
        remap = lambda b: b & ~0x3FF | (m.primary.remap_metatile(b & 0x3FF) if b & 0x3FF < EM["metatiles"]
                                        else m.secondary.remap_metatile(b & 0x3FF))  # collision/elevation untouched
        m.new_blocks, m.new_border = [remap(b) for b in m.blocks], [remap(b) for b in m.border]
        m.warp_behaviors, dead = [], defaultdict(list)
        for i, w in enumerate(m.em_map["warp_events"]):
            if not inside(m, w["x"], w["y"]):
                m.warp_behaviors.append((None, None, None, None))  # outside the map: an arrival point only
                continue
            mid = m.blocks[w["y"] * m.width + w["x"]] & 0x3FF
            ts = m.primary if mid < EM["metatiles"] else m.secondary
            em_beh = ctx.behaviors.em_names[ts.em_attrs[mid - (EM["metatiles"] if ts.secondary else 0)] & 0xFF]
            fr_beh = ctx.behaviors.fr_name(em_beh)[0]
            m.warp_behaviors.append((em_beh, fr_beh, mid, ts.remap_metatile(mid)))
            # a water door turned into sea (DEGRADED) is a listed degrade, not a dead warp
            if not m.exists and em_beh in ctx.warp_triggers - WATER_DOORS and fr_beh not in ctx.warp_triggers_here:
                dead[em_beh, fr_beh].append(str(i))
        for (em_beh, fr_beh), warps in dead.items():
            refuse(("%s warps %s, Lavaridge Gym B1F geysers (the only way out), need the engine work of step 3 (E3), "
                    "missing here: %s is not in include/constants/metatile_behaviors.h" % (m.name, " ".join(warps),
                                                                                           ENGINE_STEP3))
                   if em_beh == ENGINE_STEP3 and not defined(em_beh) else "dead warp: %s warps %s are %s in Emerald, "
                   "%s here cannot warp" % (m.name, " ".join(warps), em_beh, fr_beh))

    # layouts (shared ones once; one already here is reused, never rewritten)
    layouts, repo_ids = {}, {l.get("id"): l for l in repo_layouts}
    for m in maps:
        if m.layout["id"] not in layouts:
            renamed, layout = plan_layout(m.layout, repo_layouts)
            layout["primary_tileset"], layout["secondary_tileset"] = "gTileset_" + m.primary.name, "gTileset_" + m.secondary.name
            layouts[m.layout["id"]] = (renamed, layout)
        m.renamed, m.new_layout = layouts[m.layout["id"]]
        known = repo_ids.get(m.new_layout["id"])
        if known:
            if known != m.new_layout:
                m.differences.append("layouts.json entry %s differs from Emerald's" % known["id"])
            elif read_ints(REPO / known["blockdata_filepath"], "H") != m.new_blocks:
                m.differences.append("%s differs from Emerald's layout" % known["blockdata_filepath"])

    # the maps here a warp or connection may lead to: Emerald maps imported before, and this batch
    here = {map_id: len(json.loads(read(REPO / "data/maps" / folder / "map.json"))["warp_events"])
            for map_id, folder in existing.items()}
    here.update({m.em_map["id"]: len(m.em_map["warp_events"]) for m in maps})
    for m in maps:
        if m.exists:  # never regenerated: its header is compared only
            old = json.loads(read(REPO / "data/maps" / m.name / "map.json"))
            m.differences += ["%s is %s here, %s from Emerald" % (k, old.get(k), v)
                              for k, v in convert_header(ctx, m).items() if old.get(k) != v]
        else:
            m.map_json = convert_map_json(ctx, m, here)

    # everything planned in memory
    for ts in tilesets.values():
        ts.write()
        register_tileset(ts)
        register_labels(em, ts)
    data = json.loads(read(REPO / "data/layouts/layouts.json"))
    for _, layout in layouts.values():
        if layout["id"] not in repo_ids:
            data["layouts"].append(layout)
            m = next(m for m in maps if m.new_layout is layout)
            write_ints(REPO / layout["blockdata_filepath"], "H", m.new_blocks)
            write_ints(REPO / layout["border_filepath"], "H", m.new_border)
    write_json(REPO / "data/layouts/layouts.json", data)
    for m in maps:
        if m.exists:
            continue
        if m.group not in groups:
            groups["group_order"].append(m.group)
            groups[m.group] = []
        groups[m.group].append(m.name)
        write_json(REPO / "data/maps" / m.name / "map.json", m.map_json)
        if m.new_scripts:
            write(REPO / "data/maps" / m.name / "scripts.inc", stub_scripts(ctx, m))
        include = '\t.include "data/maps/%s/scripts.inc"\n' % m.name
        append_once(REPO / "data/event_scripts.s", include, include)
    for g in {m.group for m in maps if not m.exists}:
        if len(groups[g]) > 128:
            refuse("%s would hold %d maps: a warp stores the map number as an s8 (struct WarpData), 128 maps at most"
                   % (g, len(groups[g])))
    write_json(REPO / "data/maps/map_groups.json", groups)
    write_map_constants()
    write_shared_stubs(ctx)
    batch = SimpleNamespace(maps=maps, tilesets=tilesets, here=here, relinks=[], strips=[], extras=[], rendered=None,
                            folders=dict(existing, **{m.em_map["id"]: m.name for m in maps}))
    relink(ctx, batch, existing)
    for m in maps:
        if m.map_json:
            batch.strips += [(m.em_map["id"], c) for c in m.map_json["connections"] or [] if c["direction"] in DIRECTIONS]
    if ctx.allocated:
        batch.extras += ["Flags allocated in %s (Emerald's names):" % FLAGS_H.relative_to(REPO).as_posix()] + ctx.allocated
    batch.extras += plan_encounters(ctx, batch) + plan_heal_location(ctx, batch)
    return batch


def plan_encounters(ctx, batch):
    """Emerald's wild encounters (pokeemerald src/data/wild_encounters.json) of the new maps of this batch, added to
    src/data/wild_encounters.h: their tables above gWildMonHeaders, their headers above its terminator entry. FireRed
    and LeafGreen get the same tables. The entries already here are never touched (hand edits stay). Returns report
    lines."""
    groups = json.loads(rename(read(ctx.root / "src/data/wild_encounters.json")))["wild_encounter_groups"]
    entries = next(g for g in groups if g["label"] == "gWildMonHeaders")["encounters"]
    new = {m.em_map["id"] for m in batch.maps if m.map_json}
    text = read(ENCOUNTERS)
    term = re.search(r"^(?:[ \t]*//.*\n)*[ \t]*\{\s*\.mapGroup = MAP_GROUP\(UNDEFINED\)", text, re.M)
    if not term:
        refuse("%s has no terminator entry (MAP_GROUP(UNDEFINED)): apply the engine fix that restores it first"
               % ENCOUNTERS.relative_to(REPO).as_posix())
        return []
    tables, headers, added, seen = [], [], [], set()
    for e in entries:
        if e["map"] not in new or e["map"] in seen or "MAP_GROUP(%s)" % e["map"][4:] in text:
            continue  # not new, already here, or a second entry of the map (Altering Cave's): the engine reads the first
        seen.add(e["map"])
        fields, kinds = "", []
        for key, suffix, field in ENCOUNTER_TYPES:
            info, label = e.get(key), "%s_%s" % (e["base_label"], suffix)
            if info:
                if re.search(r"\b%s\[\]" % label, text):
                    refuse("%s: %s is already defined in %s" % (batch.folders[e["map"]], label, ENCOUNTERS.name))
                kinds.append(key[:-5].replace("_", " "))
                for mon in info["mons"]:
                    if not defined(mon["species"]):
                        refuse("%s: wild %s does not exist here" % (batch.folders[e["map"]], mon["species"]))
                tables.append("const struct WildPokemon %s[] =\n{\n%s};\n\nconst struct WildPokemonInfo %sInfo = { %d, %s };\n\n"
                              % (label, "".join("    { %d, %d, %s },\n" % (mon["min_level"], mon["max_level"],
                                                                        mon["species"]) for mon in info["mons"]),
                                 label, info["encounter_rate"], label))
            fields += "".join("        .%s_%s = %s,\n" % (field, v, "&%sInfo" % label if info else "NULL")
                              for v in ("FR", "LG"))
        headers.append("    {\n        .mapGroup = MAP_GROUP(%s),\n        .mapNum = MAP_NUM(%s),\n%s    },\n"
                       % (e["map"][4:], e["map"][4:], fields))
        added.append("%s (%s)" % (batch.folders[e["map"]], ", ".join(kinds)))
    if headers:
        text = text[:term.start()] + "".join(headers) + text[term.start():]
        at = text.index("const struct WildPokemonHeader gWildMonHeaders[]")
        write(ENCOUNTERS, text[:at] + "".join(tables) + text[at:])
    return ["Wild encounters added to %s: %s" % (ENCOUNTERS.relative_to(REPO).as_posix(), ", ".join(added) or "none")]


def plan_heal_location(ctx, batch):
    """SPAWN_<TOWN> for each Emerald heal location whose Pokemon Center 1F this batch imports: the constant appended to
    include/constants/heal_locations.h, a row in the 3 tables of src/data/heal_locations.h (Emerald's position from
    pokeemerald src/data/heal_locations.json, the PC 1F, its nurse's local id). `setrespawn` stays script work."""
    new = {m.em_map["id"]: m for m in batch.maps if m.map_json}
    lines = []
    for h in json.loads(read(ctx.root / "src/data/heal_locations.json"))["heal_locations"]:
        town = h["id"][len("HEAL_LOCATION_"):]
        spawn, pc = "SPAWN_" + town, new.get("MAP_%s_POKEMON_CENTER_1F" % town) or new.get("MAP_%s_1F" % town)
        if not pc or h["map"] not in batch.folders or defined(spawn):
            continue
        nurse = next((i + 1 for i, o in enumerate(pc.map_json["object_events"])
                      if o["graphics_id"] == "OBJ_EVENT_GFX_HOENN_NURSE"), None)
        if not nurse:
            lines.append("Heal location %s left out: %s has no nurse" % (spawn, pc.name))
            continue
        text = read(HEAL_CONSTANTS)
        spawns = list(re.finditer(r"^#define SPAWN_\w+ (\d+)\r?\n", text, re.M))
        value = max(int(s.group(1)) for s in spawns) + 1
        write(HEAL_CONSTANTS, text[:spawns[-1].end()] + "#define %s %d\n" % (spawn, value) + text[spawns[-1].end():])
        rows = ("{MAP_GROUP(%s), MAP_NUM(%s), %d, %d}" % (h["map"][4:], h["map"][4:], h["x"], h["y"]),
                "{MAP_GROUP(%s), MAP_NUM(%s)}" % (pc.em_map["id"][4:], pc.em_map["id"][4:]), str(nurse))
        text = read(HEAL_DATA)
        for name, row in zip(HEAL_TABLES, rows):
            end = text.index("};", text.index(name))
            text = text[:end] + "    [%s - 1] = %s,\n" % (spawn, row) + text[end:]
        write(HEAL_DATA, text)
        lines.append("Heal location %s = %d: %s (%d,%d), whiteout in %s, nurse local id %d (setrespawn in its "
                     "scripts.inc is script work)" % (spawn, value, batch.folders[h["map"]], h["x"], h["y"], pc.name, nurse))
    return lines


def relink(ctx, batch, existing):
    """Maps imported before get what the new maps of this batch make possible, and nothing else: a placeholder warp
    (one onto itself; Porymap 4 writes its id as a number) whose Emerald destination is a new map is pointed there,
    Emerald's connections toward a new map are added. A connection removed here (Porymap) toward an older map stays
    removed."""
    new = {m.em_map["id"] for m in batch.maps if not m.exists}
    for map_id, folder in sorted(existing.items(), key=lambda e: e[1]):
        if map_id in new:
            continue
        path = REPO / "data/maps" / folder / "map.json"
        mj, em_map = json.loads(read(path)), ctx.maps[folder]
        changed = False
        for i, (w, em_w) in enumerate(zip(mj["warp_events"], em_map["warp_events"])):
            if ((w["dest_map"], str(w["dest_warp_id"])) != (mj["id"], str(i)) or em_w["dest_map"] not in new
                    or (folder, i) in CLOSED_WARPS):
                continue
            dest = resolve_warp(em_w, batch.here)
            if dest and dest != (mj["id"], str(i)):
                w["dest_map"], w["dest_warp_id"] = dest
                batch.relinks.append("%s warp %d -> %s #%s" % (folder, i, dest[0], dest[1]))
                changed = True
        have = {(c["direction"], c["map"]) for c in mj.get("connections") or []}
        for c in connections(em_map, batch.here):
            if c["map"] in new and (c["direction"], c["map"]) not in have:
                mj["connections"] = (mj.get("connections") or []) + [c]
                batch.relinks.append("%s: connection %s -> %s (offset %d)%s" % (
                    folder, c["direction"], c["map"], c["offset"], "  needs Dive in game" if c["direction"] in DIVE else ""))
                if c["direction"] in DIRECTIONS:
                    batch.strips.append((map_id, c))
                changed = True
        if changed:
            write_json(path, mj)


# ---------------------------------------------------------------- checks

def view(ctx, folder, layouts):
    """A map of this repo as both engines draw it: Emerald's blocks and tileset folders, and this repo's. `edited`:
    the cells whose block is not the conversion of Emerald's (painted here, e.g. in Porymap; all if resized)."""
    mj = json.loads(read(REPO / "data/maps" / folder / "map.json"))
    layout, em_layout = layouts[mj["layout"]], ctx.layout_of(folder)
    em_dirs = [em_tileset(ctx.root, em_layout[k])[1] for k in ("primary_tileset", "secondary_tileset")]
    v = SimpleNamespace(
        name=folder, width=layout["width"], height=layout["height"],
        em_blocks=read_ints(ctx.root / em_layout["blockdata_filepath"], "H"), em_dirs=em_dirs,
        em_counts=[len(read_bytes(d / "metatile_attributes.bin")) // 2 for d in em_dirs],
        fr_blocks=read_ints(REPO / layout["blockdata_filepath"], "H"),
        fr_dirs=[repo_tileset_dir(layout[k]) for k in ("primary_tileset", "secondary_tileset")])
    ids = v.fr_dirs[1] / IDS_FILE  # Tileset.remap_metatile: secondary id = 640 + its place (pruned: in IDS_FILE)
    order = json.loads(read(ids))["metatiles"] if exists(ids) else range(EM["metatiles"], TOTAL)
    to_fr = {m: FR["metatiles"] + i for i, m in enumerate(order) if m is not None}
    conv = lambda b: b if b & 0x3FF < EM["metatiles"] else b & ~0x3FF | to_fr.get(b & 0x3FF, 0x3FF)
    v.edited = {i for i, (e, f) in enumerate(zip(v.em_blocks, v.fr_blocks)) if conv(e) != f} \
        if (v.width, v.height) == (em_layout["width"], em_layout["height"]) else set(range(len(v.fr_blocks)))
    return v


def same_render(em_blocks, fr_blocks, width, v, png, ref="emerald"):
    """True if both engines draw these blocks alike with the tilesets of the map `v` (ref "before": this repo's
    tilesets as they are on disk, before this run, instead of Emerald's)."""
    before = render(em_blocks, width, *(v.em_dirs if ref == "emerald" else v.fr_dirs), ref)
    after = render(fr_blocks, width, *v.fr_dirs, "frlg")
    if png:
        png.parent.mkdir(parents=True, exist_ok=True)
        after.save(png)
    return before.tobytes() == after.tobytes()


def strip(v, n, c):
    """Emerald and FRLG blocks of the neighbour `n` that standing in `v` shows through the connection `c`
    (fieldmap.c Fill*Connection: MAP_OFFSET blocks around `v`), to draw with v's tilesets, and the strip's width.
    A cell whose id v's Emerald tileset lacks is left out (Emerald draws garbage there), so is a cell painted here
    (n.edited: Emerald has nothing to compare it with): metatile 0 on both sides."""
    o = c["offset"]
    if c["direction"] in ("up", "down"):
        xs = range(max(0, -MAP_OFFSET - o), min(n.width, v.width + MAP_OFFSET - o))
        ys = range(max(0, n.height - MAP_OFFSET), n.height) if c["direction"] == "up" else range(min(MAP_OFFSET, n.height))
    else:
        ys = range(max(0, -MAP_OFFSET - o), min(n.height, v.height + MAP_OFFSET - o))
        xs = range(max(0, n.width - MAP_OFFSET), n.width) if c["direction"] == "left" else range(min(MAP_OFFSET, n.width))
    em_blocks, fr_blocks = [], []
    for y in ys:
        for x in xs:
            i = y * n.width + x
            e, f = (0, 0) if i in n.edited else (n.em_blocks[i], n.fr_blocks[i])
            mid = e & 0x3FF
            drawable = mid < v.em_counts[0] if mid < EM["metatiles"] else mid - EM["metatiles"] < v.em_counts[1]
            em_blocks.append(e if drawable else 0)
            fr_blocks.append(f if drawable else 0)
    return em_blocks, fr_blocks, len(xs)


def check_renders(ctx, batch, render_dir):
    """Pixel checks: every new map and every connection strip both ways render like Emerald's, every older map whose
    tileset grows renders as it does now (its blocks may be painted here: Emerald is no reference for them)."""
    _TILESETS.clear()
    layouts = {l["id"]: l for l in json.loads(read(REPO / "data/layouts/layouts.json"))["layouts"] if "id" in l}
    png = lambda name: render_dir / (name + ".png") if render_dir else None
    changed = changes()
    grown = {REPO / ts.dir for ts in batch.tilesets.values() if any(p.parent == REPO / ts.dir for p in changed)}
    new = {m.name for m in batch.maps if not m.exists}
    batch.rendered = []
    for folder in sorted(batch.folders.values()):
        if folder not in new and not grown:
            continue
        v = view(ctx, folder, layouts)
        if folder not in new and not grown & set(v.fr_dirs):
            continue
        batch.rendered.append(folder)
        if folder in new and not same_render(v.em_blocks, v.fr_blocks, v.width, v, png(folder)):
            refuse("%s does not render like the Emerald one" % folder)
        if folder not in new and not same_render(v.fr_blocks, v.fr_blocks, v.width, v, png(folder), "before"):
            refuse("%s would no longer render as it does now (its grown tileset changed)" % folder)
    for map_id, c in batch.strips:
        v, n = view(ctx, batch.folders[map_id], layouts), view(ctx, batch.folders[c["map"]], layouts)
        em_blocks, fr_blocks, width = strip(v, n, c)
        if width and not same_render(em_blocks, fr_blocks, width, v, png("%s_%s_%s" % (v.name, c["direction"], n.name))):
            refuse("connection strip %s -> %s (%s) does not render like Emerald's (tileset ids differ: design F11)"
                   % (v.name, n.name, c["direction"]))


def kept_lines(text):
    """The lines of a text file that an import must keep: not those of -num_tiles rules or FLAG_0x placeholders;
    JSON's trailing commas ignored."""
    return [line.rstrip().rstrip(",") for line in text.splitlines()
            if "-num_tiles" not in line and not line.startswith("#define FLAG_0x")]


def additive(path, old, new):
    """True if `new` only adds to `old`, the bytes of a file that existed before the run."""
    if new == old:
        return True
    rel = path.relative_to(REPO).as_posix()
    if rel in ("include/constants/map_groups.h", "include/constants/layouts.h"):  # made from the checked JSON files
        return True
    if rel.startswith("data/maps/") and path.name == "map.json":  # relink(): placeholder warps, connections
        o, n = json.loads(old), json.loads(new)
        oc, nc = o.get("connections") or [], n.get("connections") or []
        if nc[:len(oc)] != oc or len(o["warp_events"]) != len(n["warp_events"]):
            return False
        for i, (a, b) in enumerate(zip(o["warp_events"], n["warp_events"])):
            if a != b and ((a["dest_map"], str(a["dest_warp_id"])) != (o["id"], str(i)) or
                           {k: v for k, v in a.items() if not k.startswith("dest")} !=
                           {k: v for k, v in b.items() if not k.startswith("dest")}):
                return False
        rest = lambda j: {k: v for k, v in j.items() if k not in ("connections", "warp_events")}
        return rest(o) == rest(n)
    if rel.startswith("data/tilesets/") and path.suffix == ".bin":  # metatiles / attributes: appended
        return new.startswith(old)
    if rel.startswith("data/tilesets/") and path.suffix == ".png":  # tiles appended (the last row's blank padding
        o = load_tiles(old)                                          # may get tiles)
        while o and not any(o[-1]):
            o.pop()
        return load_tiles(new)[:len(o)] == o
    if path.name == IDS_FILE:
        o, n = json.loads(old), json.loads(new)
        return all(n[k][:len(o[k])] == o[k] for k in ("metatiles", "tiles"))
    if path.suffix in (".bin", ".pal", ".png"):
        return False
    it = iter(kept_lines(new.decode("utf-8")))
    return all(line in it for line in kept_lines(old.decode("utf-8")))


def git(*args):
    """Git for Windows on this repo (devkitPro's MSYS2 git sees every CRLF file as modified), else the git on the
    PATH; returncode 1 if it cannot start."""
    exe = Path("C:/Program Files/Git/cmd/git.exe")
    try:
        return subprocess.run([str(exe) if exe.exists() else "git", "-C", str(REPO), "-c", "core.autocrlf=true", *args],
                              capture_output=True, text=True)
    except OSError as e:
        return SimpleNamespace(returncode=1, stderr=str(e), stdout="")


def check_files(files):
    """Older files only gain lines; the files to write are clean in git (hand edits are never overwritten)."""
    for p, data in files.items():
        if p.exists() and not additive(p, p.read_bytes(), data):
            refuse("%s: the import would change existing lines (only additions are allowed)" % p.relative_to(REPO).as_posix())
    rel = [p.relative_to(REPO).as_posix() for p in files if p.exists()]
    dirty = []
    for i in range(0, len(rel), 200):
        r = git("status", "--porcelain", "--untracked-files=all", "--", *rel[i:i + 200])
        if r.returncode:
            refuse("cannot check that the files to write are clean: git status failed (%s)" % r.stderr.strip())
            return
        dirty += [line[3:] for line in r.stdout.splitlines()]
    if dirty:
        refuse("files to write have uncommitted changes (commit, restore or delete them first): %s" % ", ".join(dirty))


# ---------------------------------------------------------------- report

def ways(ctx, batch):
    """{(map, map it leads to, by Dive)} of the MAP_ ids here, planned files included: connections (both ways, Dive
    for dive and emerge ones) and the warps whose tile can start a warp here (not a wall a script opens, nor a water door
    turned into sea), Dive for the engine's fixed dive spots (src/overworld.c sHoennDiveWarps), and a MAP_DYNAMIC exit
    back to every map that leads in (SetupWarp sets it on the way in). The link rooms every Pokemon Center shares are no
    way through."""
    layouts = {l["id"]: l for l in json.loads(read(REPO / "data/layouts/layouts.json"))["layouts"] if "id" in l}
    triggers = {ctx.behaviors.fr_values[n] for n in ctx.warp_triggers_here if n in ctx.behaviors.fr_values}
    out, dynamic = set(), set()
    for map_id, folder in batch.folders.items():
        mj, v = json.loads(read(REPO / "data/maps" / folder / "map.json")), view(ctx, folder, layouts)
        for c in mj.get("connections") or []:
            out |= {(map_id, c["map"], c["direction"] in DIVE), (c["map"], map_id, c["direction"] in DIVE)}
        attrs = [tileset_data(d, "frlg")[3] for d in v.fr_dirs]
        for w in mj["warp_events"]:
            if w["dest_map"] in WARP_ALIASES or not inside(v, w["x"], w["y"]):
                continue
            mt = v.fr_blocks[w["y"] * v.width + w["x"]] & 0x3FF
            ts, i = (0, mt) if mt < FR["metatiles"] else (1, mt - FR["metatiles"])
            if i < len(attrs[ts]) and attrs[ts][i] & 0x1FF in triggers:
                if w["dest_map"] == "MAP_DYNAMIC":
                    dynamic.add(map_id)
                else:
                    out.add((map_id, w["dest_map"], False))
    src = read(REPO / "src/overworld.c")
    if "sHoennDiveWarps[]" in src:
        table = src[src.index("sHoennDiveWarps[]"):]
        rows = re.findall(r"\{\s*(MAP_\w+),\s*-?\d+,\s*-?\d+,\s*(MAP_\w+),", table[:table.index("};")])
        out |= {(a, b, True) for a, b in rows if a in batch.folders and b in batch.folders}
    return out | {(b, a, d) for a, b, d in out if b in dynamic}


def reachable(edges, start="MAP_LILYCOVE_CITY"):
    """The maps `edges` ({(map, map it leads to)}) lead to from `start`."""
    nxt = defaultdict(set)
    for a, b in edges:
        nxt[a].add(b)
    seen, todo = set(), [start]
    while todo:
        cur = todo.pop()
        if cur not in seen:
            seen.add(cur)
            todo += nxt[cur] - seen
    return seen


def report(ctx, batch, unit=None):
    print("Tilesets:")
    for ts in batch.tilesets.values():
        state = "new" if ts.new else "+%d metatiles" % ts.grows if ts.grows else "unchanged"
        room = "/%d" % SEC_MAX if ts.secondary else "    "  # a secondary's room: a pruned one fills up import by import
        print("  gTileset_%-26s %-9s %3d%s metatiles %3d tiles  %-14s %s%s" % (
            ts.name, ts.kind, ts.count(), room, ts.num_tiles, state, ts.dir,
            "  %s, ids in %s" % ("PRUNED" if ts.legacy else "natural ids", IDS_FILE) if ts.pruned else ""))
        if ts.junk:
            print("NOTE: Emerald metatiles %s name tiles beyond tiles.png: drawn with tile 0 here"
                  % " ".join("0x%03X" % m for m in ts.junk))
        for old, new in ts.pal_map.items():
            print("WARNING: Emerald palette %d of gTileset_%s is slot %d here (door/anim palettes naming slot %d "
                  "must follow)" % (old, ts.name, new, old))
        if ts.secondary and ts.em_callback != "NULL":
            print("WARNING: Emerald %s is not ported (.callback = NULL); its tiles are renumbered here" % ts.em_callback)
        if not ts.secondary and ts.em_callback != "NULL":
            print("NOTE: gTileset_%s.callback = InitTilesetAnim_%s (src/tileset_anims.c, port of Emerald %s)"
                  % (ts.name, ts.name, ts.em_callback))
    print("Behaviors (Emerald -> here: metatiles of these tilesets):")
    for (e, f), n in sorted(ctx.behaviors.used.items()):
        note = ctx.behaviors.fr_name(e)[1]
        print("  %-38s -> %-30s %3d%s" % (e, f, n, "  " + note if note else ""))
    for m in batch.maps:
        j = m.map_json
        if not j:
            print("%s  already here: not regenerated" % m.em_map["id"])
        else:
            print("%s  %s%s  %s  %dx%d  %s + %s  %s" % (
                j["id"], j["layout"], " (Emerald %s)" % m.layout["id"] if m.renamed else "", j["music"],
                m.width, m.height, m.new_layout["primary_tileset"], m.new_layout["secondary_tileset"], m.group))
        for d in m.differences:
            print("  DIFFERS (not written): " + d)
        if not j:
            continue
        for c in j["connections"] or []:
            print("  CONN %-6s -> %s (offset %d)%s" % (c["direction"], c["map"], c["offset"],
                                                       "  needs Dive in game" if c["direction"] in DIVE else ""))
        for o in j["object_events"]:
            print("  NPC  (%2d,%2d) %-38s %-26s %s" % (o["x"], o["y"], o["graphics_id"], o["movement_type"][14:],
                                                    o["script"]))
        for e in j["bg_events"] + j["coord_events"]:
            print("  %-4s (%2d,%2d) %s" % (e["type"][:4].upper(), e["x"], e["y"], e.get("script") or e.get("flag")
                                           or e.get("weather")))
        for d in m.dropped:
            print("  DROP " + d)
        for i, (w, (em_beh, fr_beh, em_mt, fr_mt)) in enumerate(zip(j["warp_events"], m.warp_behaviors)):
            print("  WARP %d (%2d,%2d) %-20s %s -> %s #%s%s" % (
                i, w["x"], w["y"], fr_beh or "outside the map", "mt 0x%03X (Emerald 0x%03X)" % (fr_mt, em_mt)
                if em_mt is not None else "", w["dest_map"], w["dest_warp_id"],
                "  (placeholder)" if (w["dest_map"], w["dest_warp_id"]) == (j["id"], str(i)) else ""))
        if m.new_scripts:
            print("  new scripts.inc: %d stubs, %d LOCALIDs" % (len(m.stubs), len(m.localids)))
    gfx = Counter()
    for m in batch.maps:
        gfx.update(m.gfx_used)
    if gfx:
        print("Sprites (Emerald -> here: objects):")
        for (em_gfx, var_gfx, fr_gfx), n in sorted(gfx.items()):
            print("  %-36s -> %-40s %2d" % (em_gfx if em_gfx == var_gfx else "%s=%s" % (em_gfx, var_gfx), fr_gfx, n))
    if ctx.shared_stubs:
        print("Stubs in %s: %s" % (STUBS.relative_to(REPO).as_posix(), ", ".join(ctx.shared_stubs)))
    print("Re-linked in maps already here:" if batch.relinks else "Re-linked in maps already here: nothing")
    for r in batch.relinks:
        print("  " + r)
    placeholders = [p for m in batch.maps for p in m.placeholders]
    if placeholders:
        print("Warps left onto themselves until their map is imported:")
        for p in placeholders:
            print("  " + p)
    for line in batch.extras:
        print(line)
    if batch.rendered is not None:
        print("Render check: %d maps and %d connection strips compared with Emerald's" % (len(batch.rendered),
                                                                                         len(batch.strips)))
    if unit:  # a town or route: its map; a dungeon: each of its maps
        ids = {m: ctx.maps[m]["id"] for m in ([unit] if unit in ctx.maps else closure(ctx.groups, unit))}
        edges = ways(ctx, batch)
        walk, dive = reachable({(a, b) for a, b, d in edges if not d}), reachable({(a, b) for a, b, d in edges})
        back = reachable({(b, a) for a, b, d in edges})
        for what, maps in (("can be reached", [m for m, i in ids.items() if i in walk]),
                           ("can be reached with Dive only", [m for m, i in ids.items() if i in dive - walk]),
                           ("can NOT be reached yet", [m for m, i in ids.items() if i not in dive])):
            if maps:
                print("%s %s from LilycoveCity (connections and warps)" % (" ".join(maps), what))
        trapped = [m for m, i in ids.items() if i in dive - back]
        if trapped:
            print("WARNING: no way back to LilycoveCity from %s (soft-lock?)" % " ".join(trapped))


# ---------------------------------------------------------------- run

def run(names, group_of, em, render_dir=None, dry_run=False, unit=None):
    """Import the Emerald maps `names` (group_of: map -> group of a new map). Returns the exit code."""
    if not __debug__:
        raise SystemExit("hoenn_import's checks use asserts: run it without python -O / PYTHONOPTIMIZE")
    em = Path(em).resolve()
    if not (em / "data/maps/map_groups.json").exists():
        print("pokeemerald not found at %s (--emerald DIR)" % em)
        return 2
    sys.stdout.reconfigure(errors="backslashreplace")  # a console without UTF-8 must not stop the report
    PENDING.clear()
    REFUSALS.clear()
    ctx = Emerald(em)
    batch, files = None, {}
    try:
        batch = plan(ctx, names, group_of)
        check_renders(ctx, batch, render_dir)
        files = changes()
        check_files(files)
        # files of this import already on disk but not in git (left by an undone import, see plan()): the planned ones
        # (same bytes) and the scripts.inc a new map keeps (m.new_scripts). Written and listed too, so that committing
        # the listed files commits the whole import
        untracked = {REPO / f for f in git("ls-files", "--others", "--exclude-standard", "-z").stdout.split("\0") if f}
        mine = set(PENDING) | {REPO / "data/maps" / m.name / "scripts.inc" for m in batch.maps if not m.exists}
        files.update({p: read_bytes(p) for p in untracked & mine})
    except Refused:
        pass
    if batch:
        report(ctx, batch, unit)
    if REFUSALS:
        print("REFUSED, nothing written:")
        for r in REFUSALS:
            print("  - " + r)
        return 1
    if not files:
        print("Nothing to do: everything is already here.")
        return 0
    print("Files %s:" % ("that would be written (--dry-run: nothing written)" if dry_run else "written"))
    for p in sorted(files):
        print("  %s %s" % ("M" if p.exists() else "A", p.relative_to(REPO).as_posix()))
    if dry_run:
        return 0
    try:
        commit(files)
    except Exception as e:
        print("ERROR while writing (%s: %s): every file was restored" % (type(e).__name__, e))
        return 3
    print("Done. Build with .\\fast_build.cmd, check the maps in game, then commit every file above.")
    r = git("ls-files")
    if not r.returncode:
        rel = lambda p: p.relative_to(REPO).as_posix()
        tracked = set(r.stdout.splitlines())
        tracked_dirs = {str(d) for f in tracked for d in PurePosixPath(f).parents}
        # the planned files git does not track (new, or left by an undone run), by their topmost untracked folder
        tops = sorted({next((str(d) for d in reversed(PurePosixPath(rel(p)).parents)
                             if str(d) not in tracked_dirs), rel(p)) for p in PENDING if rel(p) not in tracked})
        print("To undo this import before committing it (these commands touch only its files):")
        for command, paths in (("git restore --", [rel(p) for p in sorted(files) if rel(p) in tracked]),
                               ("git clean -fdq --", tops)):
            if paths:
                print("  %s %s" % (command, " ".join(paths)))
    return 0


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("maps", nargs="*", help="Emerald map names, e.g. LilycoveCity (kept as the target names)")
    parser.add_argument("--check-gfx", action="store_true",
                        help="only check the sprites of every map.json against its layout's NPC palettes (exit 1 if bad)")
    parser.add_argument("--emerald", type=Path, default=REPO.parent / "pokeemerald", help="pret/pokeemerald clone")
    parser.add_argument("--group", default="gMapGroup_TownsAndRoutes", help="map group new maps are appended to")
    parser.add_argument("--dry-run", action="store_true", help="plan and check everything, write nothing")
    parser.add_argument("--render", type=Path, help="also save each rendered map and connection strip in this folder")
    args = parser.parse_args()
    if args.check_gfx:
        bad = check_gfx()
        print("\n".join(bad) or "check-gfx: every object shows the sprite its layout's NPC palettes are made for")
        raise SystemExit(1 if bad else 0)
    if not args.maps:
        parser.error("no map given")
    raise SystemExit(run(args.maps, {m: args.group for m in args.maps}, args.emerald, args.render, args.dry_run))


if __name__ == "__main__":
    main()
