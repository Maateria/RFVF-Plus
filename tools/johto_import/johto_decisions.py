"""Decisions of the Johto import (tools/johto_import/johto_import.py): what PokemonHnS has that this repo does not, and
what replaces it. Change a decision here, then run the import again: it regenerates every Johto file."""

# HnS map group -> map group here. The Johto maps keep HnS's order inside each group (map numbers are saved: never
# reorder a group once released, append only).
GROUPS = {
    "gMapGroup_TownsAndRoutes_Hns": "gMapGroup_JohtoTownsAndRoutes",
    "gMapGroup_IndoorNewBark_Hns": "gMapGroup_JohtoIndoorNewBark",
    "gMapGroup_IndoorCherrygrove_Hns": "gMapGroup_JohtoIndoorCherrygrove",
    "gMapGroup_IndoorViolet_Hns": "gMapGroup_JohtoIndoorViolet",
    "gMapGroup_IndoorAzalea_Hns": "gMapGroup_JohtoIndoorAzalea",
    "gMapGroup_IndoorGoldenrod_Hns": "gMapGroup_JohtoIndoorGoldenrod",
    "gMapGroup_IndoorEcruteak_Hns": "gMapGroup_JohtoIndoorEcruteak",
    "gMapGroup_IndoorOlivine_Hns": "gMapGroup_JohtoIndoorOlivine",
    "gMapGroup_IndoorCianwood_Hns": "gMapGroup_JohtoIndoorCianwood",
    "gMapGroup_IndoorMahogany_Hns": "gMapGroup_JohtoIndoorMahogany",
    "gMapGroup_IndoorBlackthorn_Hns": "gMapGroup_JohtoIndoorBlackthorn",
    "gMapGroup_IndoorJohtoRoutes_Hns": "gMapGroup_JohtoIndoorRoutes",
    "gMapGroup_IndoorKantoRoutes_Hns": "gMapGroup_JohtoIndoorRoutes",  # HnS files the houses of Routes 26-28 there
    "gMapGroup_Dungeons_Hns": "gMapGroup_JohtoDungeons",
    "gMapGroup_SpecialArea_Hns": "gMapGroup_JohtoSpecialArea",
}
# Johto = the maps of GROUPS the player reaches from START (warps, connections, script warps), never going through
# OUTSIDE: HnS's Kanto, its Hoenn and Alola extras, its test maps. The Kanto border is Kanto's own maps here (BORDER).
START = "NewBarkTown_hns"
OUTSIDE = (
    r"(Pallet|Viridian|Pewter|Cerulean|Vermilion|Lavender|Celadon|Saffron|Fuchsia|Cinnabar)(Town|City|Island)?(_.*)?_hns",
    r"IndigoPlateau.*_hns", r"Route([1-9]|1\d|2[0-5])(_.*)?_hns", r"VictoryRoadKanto_.*", r"ViridianForest_hns",
    r"MtMoon_.*", r"RockTunnel_.*", r"CeruleanCave_.*", r"DiglettsCave_.*", r"SeafoamIslands_.*",
    r"TrainerHill_.*", r"Gate_Route40_TrainerHill_Courtyard_hns", r"BattleFrontier_.*", r"(Slateport|Verdanturf|Fallarbor)Town_.*",
    r"SlateportCity_.*", r"Contest.*", r"UnusedContest.*", r"LilycoveCity_.*", r"SouthernIsland_.*", r"FarawayIsland_.*",
    r"BirthIsland_.*", r"TestMap\d_hns", r"Trees_hns", r"Saffron_Temp_hns", r"TradeCenter_hns", r"BattleColosseum_.*",
    r"FuchsiaCity_.*", r"SafariZone\d_hns", r"SafariZoneIndoor_hns", r"UnionRoom_hns", r"SnowsweptCavern_hns",
    r".*Alola.*", r".*Sinjoh.*",
)

# Names here: HnS's without "_hns" (map, MAP_, LAYOUT_ and folder names); one this repo already uses for a map that is not
# Johto's gets the prefix "Johto" (RocketHideout_B1F -> JohtoRocketHideout_B1F). Tilesets: gTileset_X_Hns ->
# gTileset_JohtoX, folder data/tilesets/<kind>/johto_<x>. RENAMES fixes a few HnS spellings (map name and layout folder).
RENAMES = {"Mahoganytown_hns": "MahoganyTown"}

# HnS map section -> this repo's (include/constants/region_map_sections.h: the 39 Johto sections 0xD6-0xFC, plan of
# lieux_johto.txt). A place without its own section takes the one of the town or route it belongs to.
MAPSECS = {
    "MAPSEC_ROUTE_28": "MAPSEC_MT_SILVER",
    "MAPSEC_ROUTE_41": "MAPSEC_WHIRL_ISLANDS",
    "MAPSEC_ROUTE_43": "MAPSEC_LAKE_OF_RAGE",
    "MAPSEC_ROUTE_46": "MAPSEC_ROUTE_29",
    "MAPSEC_ROUTE_48": "MAPSEC_SAFARI_ZONE_GATE",
    "MAPSEC_SPROUT_TOWER": "MAPSEC_VIOLET_CITY",
    "MAPSEC_SLOWPOKE_WELL": "MAPSEC_AZALEA_TOWN",
    "MAPSEC_BURNED_TOWER": "MAPSEC_ECRUTEAK_CITY",
    "MAPSEC_BELLCHIME_TRAIL": "MAPSEC_ECRUTEAK_CITY",
    "MAPSEC_OLIVINE_LIGHTHOUSE": "MAPSEC_OLIVINE_CITY",
    "MAPSEC_SS_AQUA": "MAPSEC_OLIVINE_CITY",
    "MAPSEC_DRAGONS_DEN": "MAPSEC_BLACKTHORN_CITY",
    "MAPSEC_TOHJO_FALLS": "MAPSEC_ROUTE_27",
    "MAPSEC_MT_MORTAR": "MAPSEC_ROUTE_42",
    "MAPSEC_CLIFF_CAVE": "MAPSEC_ROUTE_47",
    "MAPSEC_EMBEDDED_TOWER": "MAPSEC_ROUTE_47",
    "MAPSEC_ROCKET_HIDEOUT_HNS": "MAPSEC_MAHOGANY_TOWN",
    "MAPSEC_VICTORY_ROAD_HNS": "MAPSEC_ROUTE_26",  # the Pokemon League Reception Gate
}

# Weather HnS has and this repo does not
WEATHERS = {"WEATHER_LEAVES": "WEATHER_NONE"}

# Movement types HnS has and this repo does not: the nearest one (listed in the report)
MOVEMENTS = {"MOVEMENT_TYPE_TOWER_BEAM": "MOVEMENT_TYPE_NONE"}

# Wild Pokemon this repo does not have -> the nearest one it has (its pre-evolution; Mantyke has none: its evolution)
SPECIES = {
    "SPECIES_AMBIPOM": "SPECIES_AIPOM",
    "SPECIES_ANNIHILAPE": "SPECIES_PRIMEAPE",
    "SPECIES_DUDUNSPARCE_THREE_SEGMENT": "SPECIES_DUNSPARCE",
    "SPECIES_DUDUNSPARCE": "SPECIES_DUNSPARCE",
    "SPECIES_MAMOSWINE": "SPECIES_PILOSWINE",
    "SPECIES_MANTYKE": "SPECIES_MANTINE",
    "SPECIES_MISMAGIUS": "SPECIES_MISDREAVUS",
    "SPECIES_WEAVILE": "SPECIES_SNEASEL",
    "SPECIES_HONCHKROW": "SPECIES_MURKROW",
    "SPECIES_WYRDEER": "SPECIES_STANTLER",
    "SPECIES_FARIGIRAF": "SPECIES_GIRAFARIG",
}

# Items HnS places (item balls, hidden items) that this repo does not have -> the nearest one it has. A TM / HM that
# exists here under its number needs nothing (ITEM_TM_THIEF -> ITEM_TM46_THIEF). None: the item is left out (a story
# item that comes with its script).
ITEMS = {
    "ITEM_BIG_NUGGET": "ITEM_NUGGET",
    "ITEM_CHOICE_SPECS": "ITEM_CHOICE_BAND",
    "ITEM_DAWN_STONE": "ITEM_MOON_STONE",
    "ITEM_DUBIOUS_DISC": "ITEM_UP_GRADE",
    "ITEM_EXPERT_BELT": "ITEM_BLACK_BELT",
    "ITEM_FULL_INCENSE": "ITEM_LAX_INCENSE",
    "ITEM_PURE_INCENSE": "ITEM_CLEANSE_TAG",
    "ITEM_WAVE_INCENSE": "ITEM_SEA_INCENSE",
    "ITEM_IRON_BALL": "ITEM_MACHO_BRACE",
    "ITEM_LAGGING_TAIL": "ITEM_MACHO_BRACE",
    "ITEM_LIFE_ORB": "ITEM_SHELL_BELL",
    "ITEM_MODEST_MINT": "ITEM_PP_UP",
    "ITEM_REAPER_CLOTH": "ITEM_SPELL_TAG",
    "ITEM_DESTINY_KNOT": "ITEM_MENTAL_HERB",
    "ITEM_TM_CHARGE_BEAM": "ITEM_TM34_SHOCK_WAVE",
    "ITEM_TM_FALSE_SWIPE": "ITEM_TM46_THIEF",
    "ITEM_TM_PLUCK": "ITEM_TM40_AERIAL_ACE",
    "ITEM_TM_STEALTH_ROCK": "ITEM_TM39_ROCK_TOMB",
    "ITEM_TM_EMBARGO": "ITEM_TM41_TORMENT",
    "ITEM_TM_PAYBACK": "ITEM_TM12_TAUNT",
    "ITEM_TM_DRAIN_PUNCH": "ITEM_TM31_BRICK_BREAK",
    "ITEM_TM_SHADOW_CLAW": "ITEM_TM30_SHADOW_BALL",
    "ITEM_TM_SWAGGER": "ITEM_TM45_ATTRACT",
    "ITEM_EXP_SHARE_SMALL": "ITEM_EXP_SHARE",
    "ITEM_PROTECTOR": "ITEM_HARD_STONE",
    "ITEM_GS_BALL": None,
    "ITEM_AZURE_FLUTE": None,
}

# Warps whose HnS destination is not Johto: (HnS map, warp index) -> (destination here, warp id there). Any other
# warp to a map that is not imported leads onto itself (listed in the report as closed).
WARPS = {
    ("ReceptionGate_hns", 4): ("MAP_ROUTE22", "2"),  # Kanto's Route 22, at its west end's gate building
    ("SSAqua_1F_hns", 0): ("MAP_OLIVINE_CITY_PORT_INSIDE", "0"),  # HnS points at warp #1 of a map that has one
}
# The Kanto border (the user's choice, 2026-10-18: two gates). Kanto stays FRLG's: Route 22's gate building leads to
# Route 23 and the League. Johto's gate is HnS's Reception Gate, at Route 22's west end (FRLG's Route 18 gate building,
# pasted there by hand, entered walking west, Route 22 warp 2): its exits east = Route 22, south = Route 26 North, west
# = Route 28; its north hall (to Victory Road in HnS) is walled up (BLOCK_PATCHES). On the world map, Mt. Silver, the
# gate, Route 22 and Viridian are one line (tools/worldmap JOHTO_DOWN). Both sides of Route 26 North and FRLG's Route 22
# are cliffs and their tilesets differ, so no map connection. Kanto warps whose destination the import sets:
# (map here, warp index) -> (map, warp id).
KANTO_WARPS = {
    ("Route22", 2): ("MAP_RECEPTION_GATE", "4"),
}
# Blocks changed in an HnS map: HnS map -> {(x, y): block value}. The Reception Gate's north hall (to Victory Road in
# HnS) goes: the side halls' wall and floor run on across it. Its side exits stay HnS's: mats at the bottom of the side
# halls, south arrow warps (left by walking down, as the mats show)
BLOCK_PATCHES = {
    "ReceptionGate_hns": {
        **{(x, y): 0x0408 for x in range(8, 14) for y in range(5)},  # nothing
        **{(x, 5): 0x0684 for x in range(8, 14)},                     # wall
        **{(x, 6): 0x068C for x in range(8, 14)},
        **{(x, 7): 0x32B7 for x in range(8, 14)},                     # floor under the wall
    },
}
CONNECTIONS = {}  # (HnS map, direction) -> (map here, offset): connections to Kanto maps (none)

# HnS heal locations without a respawn map (Fly spots): the Pokemon Center a whiteout there leads to
RESPAWNS = {
    "HEAL_LOCATION_MT_SILVER_HNS": "MtSilver_PokemonCenter_hns",
    "HEAL_LOCATION_LAKE_OF_RAGE_HNS": "MahoganyTown_PokemonCenter_hns",
    "HEAL_LOCATION_SAFARI_ZONE_GATE_HNS": "SafariZoneGate_PokemonCenter_hns",
    "HEAL_LOCATION_ROUTE_32_HNS": "Route32_PokemonCenter_hns",
}
HEAL_LEFT_OUT = {"HEAL_LOCATION_ROUTE26NORTH_HNS"}  # no Pokemon Center near, not a Fly destination of the world map

# Object rules (johto_import.convert_objects): an object whose flag one of these is never shown here
NIGHT_FLAGS = {"FLAG_NIGHT_POKEMON"}            # no day/night: the day's Pokemon only
# HnS's decorative Pokemon (the user, 2026-10-18: the other regions have none) are left out: a Pokemon object with no
# story flag whose script is none or only its cry and one line, unless it stands next to a person (its trainer's) or is
# listed here: (HnS map, species) of Gold/Silver/HeartGold/SoulSilver's own Pokemon NPCs and of the Day-Care
POKEMON_KEPT = {
    ("Route39_hns", "MILTANK"),                                   # Moomoo Farm's pasture
    ("VioletCity_House2_hns", "PIDGEY"),                          # the nickname house's bird
    ("GoldenrodCity_DepartmentStoreBasement_hns", "MACHOKE"),     # the warehouse workers
    ("GoldenrodCity_RadioTower_4F_hns", "MEOWTH"),                # Mary's
    ("BlackthornCity_House1_hns", "DRATINI"),                     # the dragon speech house's
    ("Route34_DayCare_hns", "DITTO"),                             # the Day-Care
    ("Route34_DayCare_hns", "EEVEE"),
}
LEFT_OUT_GFX = {"OBJ_EVENT_GFX_SMALL_LIGHT_HNS",  # night lights (no day/night)
                "OBJ_EVENT_GFX_BERRY_TREE"}       # no berry trees here
# Field-move obstacles HnS places as objects: their script here (the flag HnS gives them is kept)
OBSTACLE_SCRIPTS = {"EventScript_CutTree": "EventScript_CutTree",
                    "EventScript_RockSmash": "EventScript_RockSmash",
                    "EventScript_StrengthBoulder": "EventScript_StrengthBoulder",
                    "EventScript_Whirlpool": "EventScript_Whirlpool"}
