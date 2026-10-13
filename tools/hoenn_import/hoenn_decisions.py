"""Per-map decisions for importing Hoenn from pret/pokeemerald (plain data, no logic).

Scope: the 57 units of Emerald's gMapGroup_TownsAndRoutes and their interiors (closure rule: design spec 1.3), and the
28 dungeon units of its gMapGroup_Dungeons (hoenn_import.dungeon_units).
RFVF+ players reach Hoenn by ferry after the Hall of Fame, so the tables describe what a player finds after the HoF in
a normal Emerald playthrough (user decision D1); "RFVF+:" marks a choice made for RFVF+ instead.
Every object flag of the scope is decided exactly once, in POST_LEAGUE or HIDDEN_BY_MAP_SCRIPT, except item balls'
FLAG_ITEM_* and field-move obstacles' FLAG_TEMP_* (they keep their flag, spec 1.4 / 1.4a). Objects with flag 0 are
always placed. Reasons cite the pokeemerald script that sets or clears the flag. Map names are the names here (RENAMES).
"""

# Emerald names that this repo already uses, -> the names here. A map name prefix renames those maps everywhere: their
# folders, MAP_ and LAYOUT_ constants, layout folders and names, script labels and item flags, and every Emerald warp to
# them (VictoryRoad_1F -> HoennVictoryRoad_1F, MAP_HOENN_VICTORY_ROAD_1F; Kanto has VictoryRoad_1F and
# FLAG_HIDDEN_ITEM_VICTORY_ROAD_1F_ULTRA_BALL). Any other clash is refused.
RENAMES = {"VictoryRoad": "HoennVictoryRoad"}
# The map group of the dungeons here: FRLG already has a gMapGroup_Dungeons (126 maps).
DUNGEON_GROUP = "gMapGroup_HoennDungeons"
# Dungeon units (import_map.py): a map's unit is its name up to the first "_" (GraniteCave_B1F: GraniteCave), except
# these underwater maps, which go with the place they lead to. Underwater_SootopolisCity is Sootopolis's only way in:
# a unit of its own, like the Underwater_Route units.
DUNGEON_UNIT_OF = {
    "Underwater_SootopolisCity": "Underwater_SootopolisCity",
    "Underwater_SeafloorCavern": "SeafloorCavern",
    "Underwater_Route134": "SealedChamber",
    "Underwater_SealedChamber": "SealedChamber",
    "Underwater_MarineCave": "MarineCave",
}

# Emerald secondary palette slot -> FRLG slot, on top of the slot 6 move. FRLG's buy menu loads its frame palette into
# BG slot 11 (src/shop.c BuyMenuDecompressBgGraphics; Emerald's uses 12), so no palette a clerk's map view shows may
# sit there. Shop: Emerald 11 shows from Lilycove 3F's right clerk, 8 from every Mart, 10 from no item seller.
PALETTE_SWAPS = {"gTileset_Shop": {10: 11, 11: 10}}

# OBJ_EVENT_GFX_VAR_x: the Emerald gfx that map's script gives, for every VAR object still shown after the decisions
# below (rivals: POST_LEAGUE; bedroom decorations: HIDDEN_BY_MAP_SCRIPT).
VAR_GFX = {
    # SetLilycoveLadyGfx: Quiz (WOMAN_4) / Favor (WOMAN_2) / Contest (GIRL_2) lady, picked by trainer id: Quiz kept
    ("LilycoveCity_PokemonCenter_1F", "OBJ_EVENT_GFX_VAR_0"): "OBJ_EVENT_GFX_WOMAN_4",
    # SetMauvilleOldManObjEventGfx: one of five old men, picked by trainer id: the Bard (its default) kept
    ("MauvilleCity_PokemonCenter_1F", "OBJ_EVENT_GFX_VAR_0"): "OBJ_EVENT_GFX_BARD",
    # Battle Tent rooms (only the tent scripts lead there): VAR_1 = the player's stand-in (*_SetPlayerGfxMale),
    # VAR_0 = the opponent tower_setopponent picks; facility class 0, the Hiker, stands in
    ("SlateportCity_BattleTentBattleRoom", "OBJ_EVENT_GFX_VAR_0"): "OBJ_EVENT_GFX_HIKER",
    ("SlateportCity_BattleTentBattleRoom", "OBJ_EVENT_GFX_VAR_1"): "OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL",
    ("FallarborTown_BattleTentBattleRoom", "OBJ_EVENT_GFX_VAR_0"): "OBJ_EVENT_GFX_HIKER",
    ("FallarborTown_BattleTentBattleRoom", "OBJ_EVENT_GFX_VAR_1"): "OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL",
    ("VerdanturfTown_BattleTentBattleRoom", "OBJ_EVENT_GFX_VAR_0"): "OBJ_EVENT_GFX_HIKER",
    ("VerdanturfTown_BattleTentBattleRoom", "OBJ_EVENT_GFX_VAR_1"): "OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL",
    # SetEReaderTrainerGfxId: the visiting e-Reader trainer; with none, facility class 0 (Hiker)
    ("SootopolisCity_MysteryEventsHouse_B1F", "OBJ_EVENT_GFX_VAR_0"): "OBJ_EVENT_GFX_HIKER",
    # no script sets it (same room as the Mystery Events B1F): the same stand-in
    ("MossdeepCity_GameCorner_B1F", "OBJ_EVENT_GFX_VAR_0"): "OBJ_EVENT_GFX_HIKER",
    # the rival after the HoF (AddRivalObject sets VAR_OBJ_GFX_ID_0 by the player's gender): May until a script picks it
    ("LittlerootTown_ProfessorBirchsLab", "OBJ_EVENT_GFX_VAR_0"): "OBJ_EVENT_GFX_RIVAL_MAY_NORMAL",
}
# Flags NOT set at new game whose object the map's own script still hides on load after the HoF.
HIDDEN_BY_MAP_SCRIPT = {
    "FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN": "CableClub_OnTransition hides him (no Wonder Card / Eon Ticket)",
    "FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN": "OnTransition hides her (no POKENEWS_LILYCOVE)",
    "FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON": "shown only with the Contest Lady (VAR_0 = Quiz Lady)",
    # LittlerootTown_BrendansHouse_2F_OnTransition (and Mays): SecretBase_EventScript_SetDecorationFlags hides every bedroom
    # decoration, then only the player's own come back (none in RFVF+)
    "FLAG_DECORATION_1": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_2": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_3": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_4": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_5": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_6": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_7": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_8": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_9": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_10": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_11": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
    "FLAG_DECORATION_12": "SecretBase_EventScript_SetDecorationFlags (bedroom decoration)",
}
# Objects the map's own script moves on load after the HoF: (map, Emerald local_id) -> (x, y, movement type).
# Not moved: Norman stays at the back of his Gym (PetalburgCity_Gym_EventScript_CheckNormanForRematch leaves him there
# for good once his rematch is ready); Sootopolis's Expert already stands at (31,18) in map.json.
MOVED_BY_MAP_SCRIPT = {
    # Route114_FossilManiacsTunnel_OnTransition (FLAG_SYS_GAME_CLEAR): he steps aside from the Desert Underpass
    ("Route114_FossilManiacsTunnel", "LOCALID_FOSSIL_MANIAC"): (6, 5, "MOVEMENT_TYPE_FACE_DOWN"),
    # Route119_WeatherInstitute_2F_OnTransition (FLAG_SYS_GAME_CLEAR): ..._EventScript_SetScientistPosGameClear
    ("Route119_WeatherInstitute_2F", "LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST"): (2, 2, "MOVEMENT_TYPE_FACE_UP"),
    # MtPyre_Summit_OnTransition (VAR_MT_PYRE_STATE 2, set by SootopolisCity_EventScript_MaxieArchieLeave): Archie
    # stands beside Maxie, who keeps map.json's (23,6)
    ("MtPyre_Summit", "LOCALID_MT_PYRE_SUMMIT_ARCHIE"): (22, 6, "MOVEMENT_TYPE_FACE_UP"),
}
# RFVF+ players reach Hoenn by ferry after the Hall of Fame: they find Emerald's post-League state (Team Aqua gone,
# Game Freak team and the late Fan Club members there). Object flag -> True = shown (flag dropped), False = left out;
# with the reason. The rival (May / Brendan) and Scott are left out everywhere (RFVF+, as in Lilycove).
POST_LEAGUE = {
    "FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS": (True, "Game Freak team, there after the League"),
    "FLAG_HIDE_FANCLUB_OLD_LADY": (True, "Fan Club member, there after the League"),
    "FLAG_HIDE_FANCLUB_BOY": (True, "Fan Club member, there after the League"),
    "FLAG_HIDE_FANCLUB_LITTLE_BOY": (True, "Fan Club member, there after the League"),
    "FLAG_HIDE_FANCLUB_LADY": (True, "Fan Club member, there after the League"),
    "FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS": (False, "Team Aqua has left Lilycove"),
    "FLAG_HIDE_LILYCOVE_CITY_RIVAL": (False, "rival battle not ported"),
    "FLAG_HIDE_LILYCOVE_MOTEL_SCOTT": (False, "Scott left out (RFVF+ choice)"),
    # LilycoveCity, other flags (the imported Lilycove maps keep their objects, spec 1.6)
    "FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR": (True, "only LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings removes him (contest painting)"),
    "FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1": (False, "contest paintings only: LilycoveCity_ContestLobby_EventScript_ShowPatron1"),
    "FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2": (False, "contest paintings only: LilycoveCity_ContestLobby_EventScript_ShowPatron2"),
    "FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3": (False, "contest paintings only: LilycoveCity_ContestLobby_EventScript_ShowPatron3"),
    "FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4": (False, "contest paintings only: LilycoveCity_ContestLobby_EventScript_ShowPatron4"),
    "FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS": (False, "contest paintings only: LilycoveCity_ContestLobby_EventScript_ShowTourists"),
    "FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_1": (False, "cutscene only: addobject in LilycoveCity_ContestLobby_EventScript_ContestArtist"),
    "FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2": (False, "cutscene only: addobject in LilycoveCity_ContestLobby_EventScript_LinkContestArtist"),
    "FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER": (False, "after a contest only (LilycoveCity_ContestLobby_EventScript_ShowContestReporter); LilycoveCity_OnTransition hides him"),
    "FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT": (True, "LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster: there unless POKENEWS_BLENDMASTER"),
    "FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER": (False, "only with POKENEWS_BLENDMASTER (LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster)"),
    "FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER": (False, "LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer: needs link battle records"),
    "FLAG_HIDE_LILYCOVE_HARBOR_FERRY_ATTENDANT": (True, "no script sets it"),
    "FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL": (True, "the ferry is docked: cleared by the HoF (EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags)"),
    "FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR": (False, "cutscene only: addobject in LilycoveCity_Harbor_EventScript_GetEventTicketSailor"),
    "FLAG_HIDE_LILYCOVE_HARBOR_EVENT_TICKET_TAKER": (False, "cutscene only: addobject in LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime"),
    # PetalburgCity
    "FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM": (False, "set by PetalburgCity_Gym_EventScript_BeginWallyTutorial, never cleared"),
    "FLAG_HIDE_PETALBURG_CITY_WALLY": (False, "catching lesson only: set by PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial"),
    "FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD": (False, "set by PetalburgCity_EventScript_WalkToWallyHouse"),
    "FLAG_HIDE_PETALBURG_CITY_SCOTT": (False, "cutscene only: addobject in PetalburgCity_EventScript_Scott0"),
    "FLAG_HIDE_PETALBURG_GYM_NORMAN": (True, "no script sets it"),
    "FLAG_HIDE_PETALBURG_GYM_GREETER": (False, "set by EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF"),
    "FLAG_HIDE_PETALBURG_GYM_WALLY": (False, "catching lesson only: removed by PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial"),
    "FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD": (False, "cutscene only: addobject in PetalburgCity_Gym_EventScript_NormanBattle"),
    # SlateportCity
    "FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA": (False, "set by SlateportCity_SternsShipyard_1F_EventScript_Dock"),
    "FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY": (False, "Stern's interview only: removed by SlateportCity_EventScript_CaptStern"),
    "FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN": (False, "removed by SlateportCity_EventScript_CaptStern (he moves to the Harbor)"),
    "FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN": (True, "cleared by Route111_EventScript_GiveSecretPower"),
    "FLAG_HIDE_SLATEPORT_CITY_SCOTT": (False, "cutscene only: addobject in SlateportCity_EventScript_ScottScene"),
    "FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY": (False, "set by the HoF (EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags)"),
    "FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS": (False, "set by SlateportCity_OceanicMuseum_2F_EventScript_CaptStern"),
    "FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION": (True, "cleared by MauvilleCity_OnTransition"),
    "FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT": (False, "set by SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited"),
    "FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN": (False, "removed by SlateportCity_OceanicMuseum_2F_EventScript_CaptStern"),
    "FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE": (False, "cutscene only: SlateportCity_OceanicMuseum_2F_EventScript_CaptStern"),
    "FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1": (False, "cutscene only: SlateportCity_OceanicMuseum_2F_EventScript_CaptStern"),
    "FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2": (False, "cutscene only: SlateportCity_OceanicMuseum_2F_EventScript_CaptStern"),
    "FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS": (True, "cleared by MossdeepCity_Gym_EventScript_TateAndLizaDefeated"),
    "FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN": (True, "cleared by SlateportCity_EventScript_CaptStern, never set again"),
    "FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL": (True, "the ferry is docked: cleared by the HoF and SlateportCity_Harbor_EventScript_ShowSSTidal"),
    "FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT": (False, "submarine theft only: removed by SlateportCity_Harbor_EventScript_AquaEscapeScene"),
    "FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE": (False, "submarine theft only: removed by SlateportCity_Harbor_EventScript_AquaEscapeScene"),
    "FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW": (False, "submarine theft only: removed by SlateportCity_Harbor_EventScript_AquaEscapeScene"),
    # MauvilleCity: New Mauville done (optional; until then Wattson waits outside his Gym)
    "FLAG_HIDE_MAUVILLE_CITY_WALLY": (False, "removed by MauvilleCity_EventScript_DefeatedWally"),
    "FLAG_HIDE_MAUVILLE_CITY_WALLYS_UNCLE": (False, "removed by MauvilleCity_EventScript_DefeatedWally"),
    "FLAG_HIDE_MAUVILLE_CITY_WATTSON": (False, "RFVF+ (user): Wattson stays in his Gym; New Mauville is NOT done, its quest is left to the script phase"),
    "FLAG_HIDE_MAUVILLE_CITY_SCOTT": (False, "cutscene only: addobject in MauvilleCity_EventScript_ScottApproachPlayerNorth"),
    "FLAG_HIDE_MAUVILLE_GYM_WATTSON": (True, "RFVF+ (user): Wattson in his Gym although New Mauville is NOT done (Emerald would send him outside)"),
    # RustboroCity
    "FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1": (False, "Devon Goods theft only: set by RustboroCity_EventScript_ReturnGoods"),
    "FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT": (False, "cutscene only: RustboroCity_EventScript_StolenGoodsScene"),
    "FLAG_HIDE_RUSTBORO_CITY_RIVAL": (False, "set by Route104_MrBrineysHouse_EventScript_HideRustboroRival"),
    "FLAG_HIDE_RUSTBORO_CITY_SCIENTIST": (False, "Match Call lesson only: set by RustboroCity_EventScript_MatchCallTutorial"),
    "FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE": (True, "back from Route 116: cleared by Route116_EventScript_GiveRepeatBall"),
    "FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT": (False, "set by RustboroCity_DevonCorp_3F_EventScript_MeetPresident"),
    # FortreeCity
    "FLAG_HIDE_FORTREE_CITY_KECLEON": (False, "invisible wall before the Gym: FortreeCity_EventScript_UseDevonScope removes it (Badge 6)"),
    "FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL": (True, "home: away only between FortreeCity_House4_EventScript_Boy and MossdeepCity_House2_EventScript_Wingull"),
    # MossdeepCity
    "FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA": (False, "Space Center raid only: set by MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha"),
    "FLAG_HIDE_MOSSDEEP_CITY_SCOTT": (False, "removed by MossdeepCity_EventScript_Scott, set by MossdeepCity_StevensHouse_EventScript_StevenGivesDive"),
    "FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL": (False, "the mail Wingull is home in Fortree (FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL)"),
    "FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN": (False, "set by SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre"),
    "FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL": (True, "cleared by EverGrandeCity_HallOfFame_EventScript_ShowStevensHouseBeldum; story ball (gives Beldum), silent like an NPC, not an item ball"),
    "FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY": (True, "Steven's letter: cleared by the HoF (EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags)"),
    "FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA": (False, "set by MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha"),
    "FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE": (False, "set by MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha"),
    "FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN": (False, "set by MossdeepCity_Gym_EventScript_TateAndLizaDefeated"),
    "FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN": (False, "removed by MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha"),
    "FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA": (False, "set by MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha"),
    # SootopolisCity (VAR_SOOTOPOLIS_CITY_STATE 6 after Juan: normal layout)
    "FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS": (False, "weather crisis only: set by SootopolisCity_Gym_1F_EventScript_JuanDefeated"),
    "FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1": (True, "cleared by SootopolisCity_Gym_1F_EventScript_JuanDefeated"),
    "FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN": (False, "set by SootopolisCity_Gym_1F_EventScript_JuanDefeated"),
    "FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON": (False, "removed by SootopolisCity_EventScript_RayquazaSceneFromDive"),
    "FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE": (False, "removed by SootopolisCity_EventScript_RayquazaSceneFromDive"),
    "FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA": (False, "cutscene only: addobject in SootopolisCity_EventScript_RayquazaSceneFromDive"),
    "FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE": (False, "set by SootopolisCity_EventScript_MaxieArchieLeave"),
    "FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE": (False, "set by SootopolisCity_EventScript_MaxieArchieLeave"),
    "FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE": (False, "set by SootopolisCity_Gym_1F_EventScript_JuanDefeated"),
    # EverGrandeCity
    "FLAG_HIDE_CHAMPIONS_ROOM_RIVAL": (False, "cutscene only: addobject in EverGrandeCity_ChampionsRoom_EventScript_Defeated"),
    "FLAG_HIDE_CHAMPIONS_ROOM_BIRCH": (False, "cutscene only: addobject in EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF"),
    "FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT": (False, "removed by EverGrandeCity_PokemonCenter_1F_EventScript_Scott; EverGrandeCity_SidneysRoom_OnTransition hides him"),
    # LittlerootTown. RFVF+: the player is from Kanto, so both houses are the rivals' families' homes: each keeps the
    # rival's mother and sibling (shown there for a player of the other gender) and loses the player's Mom.
    "FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN": (True, "cleared by LittlerootTown_EventScript_GoInsideWithMom"),
    "FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE": (False, "removed by LittlerootTown_EventScript_SetReceivedRunningShoes"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK": (False, "moving truck: set by LittlerootTown_EventScript_StepOffTruckMale"),
    "FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK": (False, "moving truck: set by LittlerootTown_EventScript_StepOffTruckFemale"),
    "FLAG_HIDE_LITTLEROOT_TOWN_RIVAL": (False, "National Dex scene only: set by LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BIRCH": (False, "National Dex scene only: set by LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM": (False, "RFVF+ rivals' home: the girl's state (InsideOfTruck_EventScript_SetIntroFlagsFemale)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM": (True, "RFVF+ rivals' home: set only for a boy (InsideOfTruck_EventScript_SetIntroFlagsMale)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING": (True, "RFVF+ rivals' home: set only for a boy (InsideOfTruck_EventScript_SetIntroFlagsMale)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM": (False, "RFVF+ rivals' home: the boy's state (InsideOfTruck_EventScript_SetIntroFlagsMale)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM": (True, "RFVF+ rivals' home: set only for a girl (InsideOfTruck_EventScript_SetIntroFlagsFemale)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING": (True, "RFVF+ rivals' home: set only for a girl (InsideOfTruck_EventScript_SetIntroFlagsFemale)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1": (False, "movers: set by PlayersHouse_2F_EventScript_WallClock"),
    "FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2": (False, "movers: set by PlayersHouse_2F_EventScript_WallClock"),
    "FLAG_HIDE_PLAYERS_HOUSE_DAD": (False, "S.S. Ticket scene only: EverGrandeCity_HallOfFame_EventScript_ReadyReceiveSSTicketEvent, then PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV removes him"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN": (False, "cutscene only: LittlerootTown_BrendansHouse_1F_EventScript_MeetRival"),
    "FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY": (False, "cutscene only: LittlerootTown_MaysHouse_1F_EventScript_MeetRival"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM": (False, "set by the HoF (EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM": (False, "set by the HoF (EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_BEDROOM_MOM": (False, "never shown: only EventScript_ResetAllMapFlags touches it"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL": (False, "rival's ball: set by LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan"),
    "FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL": (False, "rival's ball: set by LittlerootTown_MaysHouse_2F_EventScript_MeetMay"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL": (False, "doll (LilycoveCity_EventScript_DefeatedBrendan): decoration sprites are not imported"),
    "FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL": (False, "doll (LilycoveCity_EventScript_DefeatedMay): decoration sprites are not imported"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH": (True, "after the HoF ProfBirch_EventScript_UpdateLocation keeps him in his lab (ProfBirch_EventScript_MoveToLab)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL": (True, "RFVF+ (user): in the lab after the HoF, as Emerald adds them (LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject)"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL": (False, "all Hoenn Pokemon caught only: LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE": (False, "all Hoenn Pokemon caught only: LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters"),
    "FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA": (False, "all Hoenn Pokemon caught only: LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters"),
    # OldaleTown
    "FLAG_HIDE_OLDALE_TOWN_RIVAL": (False, "set by LittlerootTown_EventScript_MoveRivalFromOldale"),
    # DewfordTown. Mr. Briney: EventScript_HideMrBriney (PetalburgCity_Gym_EventScript_NormanBattle) hides him everywhere
    "FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN": (False, "set by EventScript_HideMrBriney (Norman's Badge)"),
    "FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN": (False, "set by EventScript_HideMrBriney (Norman's Badge)"),
    "FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN": (True, "cleared by PetalburgCity_Gym_EventScript_NormanBattle"),
    # LavaridgeTown
    "FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_ON_BIKE": (False, "cutscene only: addobject in LavaridgeTown_EventScript_RivalExit"),
    "FLAG_HIDE_LAVARIDGE_TOWN_RIVAL": (False, "Go-Goggles scene only: removed by LavaridgeTown_EventScript_RivalExit"),
    # FallarborTown
    "FLAG_HIDE_FALLARBOR_AZURILL": (True, "no script sets it"),
    "FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT": (False, "set by MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene"),
    "FLAG_HIDE_FALLARBOR_POKEMON_CENTER_LANETTE": (False, "she went home (Route 114): removed by FallarborTown_PokemonCenter_1F_EventScript_LanetteExited"),
    "FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO": (True, "cleared by MtChimney_EventScript_Maxie"),
    # VerdanturfTown (Rusturf Tunnel opened)
    "FLAG_HIDE_VERDANTURF_TOWN_SCOTT": (False, "set by FieryPath_EventScript_MoveScottToFallarbor"),
    "FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY": (False, "set by LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated"),
    "FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND": (True, "cleared by RusturfTunnel_EventScript_SetRusturfTunnelOpen"),
    "FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA": (True, "cleared by RusturfTunnel_EventScript_SetRusturfTunnelOpen"),
    "FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE": (True, "cleared by MauvilleCity_EventScript_DefeatedWally, never set again"),
    # Route101
    "FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE": (False, "set by Route101_EventScript_BirchsBag"),
    "FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG": (False, "set by Route101_EventScript_BirchsBag"),
    "FLAG_HIDE_ROUTE_101_ZIGZAGOON": (False, "removed by Route101_EventScript_BirchsBag"),
    "FLAG_HIDE_ROUTE_101_BIRCH": (False, "after the HoF Birch stays in his lab (ProfBirch_EventScript_UpdateLocation)"),
    "FLAG_HIDE_ROUTE_101_BOY": (True, "cleared by LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival"),
    # Route103
    "FLAG_HIDE_ROUTE_103_RIVAL": (False, "removed by Route103_EventScript_RivalEnd"),
    "FLAG_HIDE_ROUTE_103_BIRCH": (False, "after the HoF Birch stays in his lab (ProfBirch_EventScript_UpdateLocation)"),
    # Route104 (Mr. Briney's cottage stays empty: EventScript_HideMrBriney)
    "FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT": (False, "set by EventScript_HideMrBriney (Norman's Badge)"),
    "FLAG_HIDE_ROUTE_104_MR_BRINEY": (False, "set by EventScript_HideMrBriney (Norman's Badge)"),
    "FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST": (True, "Route104_EventScript_ShowOrHideWhiteHerbFlorist: Badge 3 and FLAG_MET_PRETTY_PETAL_SHOP_OWNER"),
    "FLAG_HIDE_ROUTE_104_RIVAL": (False, "set by Route104_MrBrineysHouse_EventScript_SailToDewford"),
    "FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY": (False, "set by EventScript_HideMrBriney (Norman's Badge)"),
    "FLAG_HIDE_BRINEYS_HOUSE_PEEKO": (False, "set by EventScript_HideMrBriney (Norman's Badge)"),
    # Route109
    "FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT": (False, "set by EventScript_HideMrBriney (Norman's Badge)"),
    "FLAG_HIDE_ROUTE_109_MR_BRINEY": (False, "set by EventScript_HideMrBriney (Norman's Badge)"),
    # Route110
    "FLAG_HIDE_ROUTE_110_TEAM_AQUA": (False, "set by SlateportCity_OceanicMuseum_2F_EventScript_CaptStern"),
    "FLAG_HIDE_ROUTE_110_RIVAL": (False, "removed by Route110_EventScript_RivalExit"),
    "FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE": (False, "cutscene only: addobject in Route110_EventScript_RivalExit"),
    "FLAG_HIDE_ROUTE_110_BIRCH": (False, "cutscene only: addobject in Route110_EventScript_BirchScene"),
    "FLAG_HIDE_TRICK_HOUSE_ENTRANCE_MAN": (False, "hiding: Route110_TrickHouseEntrance_OnWarp adds him per puzzle state"),
    "FLAG_HIDE_TRICK_HOUSE_END_MAN": (True, "Route110_TrickHouseEnd_OnWarp adds him on every arrival (Route110_TrickHouseEnd_EventScript_SetTrickMasterPos)"),
    # Route111
    "FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE": (False, "removed by Route111_EventScript_BattleWinstrates (the family is at home)"),
    "FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE": (False, "cutscene only: Route111_EventScript_BattleWinstrates"),
    "FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE": (False, "cutscene only: Route111_EventScript_BattleWinstrates"),
    "FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE": (False, "cutscene only: Route111_EventScript_BattleWinstrates"),
    "FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1": (True, "their first spot; GabbyAndTy_EventScript_UpdateLocation moves them after each battle"),
    "FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2": (False, "a later spot (GabbyAndTy_EventScript_UpdateLocation)"),
    "FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3": (False, "a later spot (GabbyAndTy_EventScript_UpdateLocation)"),
    "FLAG_HIDE_ROUTE_111_SECRET_POWER_MAN": (False, "removed by Route111_EventScript_GiveSecretPower"),
    "FLAG_HIDE_ROUTE_111_DESERT_FOSSIL": (False, "never shown: only EventScript_ResetAllMapFlags touches it"),
    "FLAG_HIDE_ROUTE_111_PLAYER_DESCENT": (False, "cutscene only: addobject in Route111_EventScript_MirageTowerDisappear"),
    "FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY": (False, "set by MauvilleCity_House1_EventScript_RockSmashDude"),
    # Route112
    "FLAG_HIDE_ROUTE_112_TEAM_MAGMA": (False, "set by MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene"),
    # Route114
    "FLAG_HIDE_LANETTES_HOUSE_LANETTE": (True, "cleared by FallarborTown_PokemonCenter_1F_EventScript_LanetteExited"),
    # Route116
    "FLAG_HIDE_ROUTE_116_MR_BRINEY": (False, "set by RusturfTunnel_EventScript_Grunt (Peeko rescued)"),
    "FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE": (False, "removed by Route116_EventScript_GiveRepeatBall"),
    "FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND": (False, "set by RustboroCity_DevonCorp_3F_EventScript_MeetPresident"),
    "FLAG_HIDE_ROUTE_116_DROPPED_GLASSES_MAN": (True, "no script sets it"),
    # Route118
    "FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1": (False, "a later spot (GabbyAndTy_EventScript_UpdateLocation)"),
    "FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2": (False, "a later spot (GabbyAndTy_EventScript_UpdateLocation)"),
    "FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3": (False, "a later spot (GabbyAndTy_EventScript_UpdateLocation)"),
    "FLAG_HIDE_ROUTE_118_STEVEN": (False, "removed by Route118_EventScript_StevenTrigger"),
    # Route119
    "FLAG_HIDE_ROUTE_119_RIVAL": (False, "cutscene only: addobject in Route119_EventScript_RivalEncounter"),
    "FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE": (False, "cutscene only: addobject in Route119_EventScript_RivalEncounter"),
    "FLAG_HIDE_ROUTE_119_SCOTT": (False, "cutscene only: addobject in Route119_EventScript_RivalExitScottArrive"),
    "FLAG_HIDE_ROUTE_119_TEAM_AQUA": (False, "set by Route119_WeatherInstitute_2F_EventScript_ShellyDefeated"),
    "FLAG_HIDE_ROUTE_119_KECLEON_1": (False, "invisible wall only its Devon Scope script (Route119_EventScript_Kecleon1) removes: until scripted"),
    "FLAG_HIDE_ROUTE_119_KECLEON_2": (False, "invisible wall only its Devon Scope script (Route119_EventScript_Kecleon2) removes: until scripted"),
    "FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS": (True, "cleared by Route119_EventScript_MoveInstituteWorkersDownstairs"),
    "FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS": (False, "set by Route119_EventScript_MoveInstituteWorkersDownstairs"),
    "FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M": (False, "cutscene only: addobject in Route119_WeatherInstitute_2F_EventScript_ShellyDefeated"),
    # Route120
    "FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1": (False, "a later spot (GabbyAndTy_EventScript_UpdateLocation)"),
    "FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2": (False, "a later spot (GabbyAndTy_EventScript_UpdateLocation)"),
    "FLAG_HIDE_ROUTE_120_KECLEON_BRIDGE": (False, "removed by Route120_EventScript_RemoveBridgeKecleon (Steven's Devon Scope scene)"),
    "FLAG_HIDE_ROUTE_120_KECLEON_BRIDGE_SHADOW": (False, "removed by Route120_EventScript_RemoveBridgeKecleon (Steven's Devon Scope scene)"),
    "FLAG_HIDE_ROUTE_120_STEVEN": (False, "removed by Route120_EventScript_StevenGiveDeconScope"),
    "FLAG_HIDE_ROUTE_120_KECLEON_1": (False, "invisible wall only its Devon Scope script (Route120_EventScript_Kecleon1) removes: until scripted"),
    "FLAG_HIDE_ROUTE_120_KECLEON_2": (False, "invisible wall only its Devon Scope script (Route120_EventScript_Kecleon2) removes: until scripted"),
    "FLAG_HIDE_ROUTE_120_KECLEON_3": (False, "invisible wall only its Devon Scope script (Route120_EventScript_Kecleon3) removes: until scripted"),
    "FLAG_HIDE_ROUTE_120_KECLEON_4": (False, "invisible wall only its Devon Scope script (Route120_EventScript_Kecleon4) removes: until scripted"),
    "FLAG_HIDE_ROUTE_120_KECLEON_5": (False, "invisible wall only its Devon Scope script (Route120_EventScript_Kecleon5) removes: until scripted"),
    # Route121
    "FLAG_HIDE_ROUTE_121_TEAM_AQUA_GRUNTS": (False, "removed by Route121_EventScript_AquaGruntsMoveOut"),
    # Route128
    "FLAG_HIDE_ROUTE_128_STEVEN": (False, "cutscene only: addobject in Route128_EventScript_KyogreAwakenedScene"),
    "FLAG_HIDE_ROUTE_128_ARCHIE": (False, "removed by Route128_EventScript_KyogreAwakenedScene"),
    "FLAG_HIDE_ROUTE_128_MAXIE": (False, "removed by Route128_EventScript_KyogreAwakenedScene"),
    # Dungeons. Team Aqua and Magma are gone, Steven and Wallace left; the legendaries not caught in a normal
    # playthrough wait where Emerald puts them after the HoF (silent until scripted, like every NPC)
    "FLAG_HIDE_PETALBURG_WOODS_AQUA_GRUNT": (False, "removed by PetalburgWoods_EventScript_DevonResearcherPostBattle"),
    "FLAG_HIDE_PETALBURG_WOODS_DEVON_EMPLOYEE": (False, "removed by PetalburgWoods_EventScript_RemoveDevonResearcher"),
    "FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT": (False, "removed by RusturfTunnel_EventScript_Grunt (Peeko rescued)"),
    "FLAG_HIDE_RUSTURF_TUNNEL_PEEKO": (False, "removed by RusturfTunnel_EventScript_Grunt (Peeko rescued)"),
    "FLAG_HIDE_RUSTURF_TUNNEL_BRINEY": (False, "removed by RusturfTunnel_EventScript_Grunt (Peeko rescued)"),
    "FLAG_HIDE_RUSTURF_TUNNEL_WANDA": (False, "tunnel opened (as in Verdanturf): removed by RusturfTunnel_EventScript_SetRusturfTunnelOpen"),
    "FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND": (False, "tunnel opened (as in Verdanturf): removed by RusturfTunnel_EventScript_SetRusturfTunnelOpen"),
    "FLAG_HIDE_GRANITE_CAVE_STEVEN": (False, "letter delivered: removed by GraniteCave_StevensRoom_EventScript_Steven"),
    "FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA": (False, "removed by MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene"),
    "FLAG_HIDE_METEOR_FALLS_TEAM_AQUA": (False, "cutscene only: MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene"),
    "FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO": (False, "set by MtChimney_EventScript_Maxie (he is home in Fallarbor)"),
    "FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA": (False, "set by MtChimney_EventScript_Maxie"),
    "FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA": (False, "set by MtChimney_EventScript_Maxie"),
    "FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY": (True, "cleared by MtChimney_EventScript_Maxie"),
    "FLAG_HIDE_MT_CHIMNEY_TRAINERS": (True, "cleared by LavaridgeTown_EventScript_ShowMtChimneyTrainers"),
    "FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD": (False, "set by MtPyre_Summit_EventScript_TeamAquaExits"),
    "FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS": (False, "set by MagmaHideout_4F_EventScript_Maxie"),
    "FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON": (False, "cutscene only: MagmaHideout_4F_EventScript_Maxie"),
    "FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_ASLEEP": (False, "Groudon awakened: removed by MagmaHideout_4F_EventScript_Maxie"),
    "FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1": (True, "a Voltorb posing as an item ball until battled (NewMauville_Inside_EventScript_Voltorb1)"),
    "FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2": (True, "a Voltorb posing as an item ball until battled (NewMauville_Inside_EventScript_Voltorb2)"),
    "FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3": (True, "a Voltorb posing as an item ball until battled (NewMauville_Inside_EventScript_Voltorb3)"),
    "FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA": (False, "set by MtPyre_Summit_EventScript_TeamAquaExits"),
    "FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE": (True, "cleared by SootopolisCity_EventScript_MaxieArchieLeave: waits to return the orbs (MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs)"),
    "FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE": (True, "cleared by SootopolisCity_EventScript_MaxieArchieLeave: waits to return the orbs (MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs)"),
    "FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE": (False, "set by SlateportCity_Harbor_EventScript_AquaEscapeScene"),
    "FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE": (False, "set by SlateportCity_Harbor_EventScript_AquaEscapeScene"),
    "FLAG_HIDE_AQUA_HIDEOUT_GRUNTS": (False, "set by MossdeepCity_Gym_EventScript_TateAndLizaDefeated"),
    "FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1": (True, "an Electrode posing as an item ball until battled (AquaHideout_B1F_EventScript_Electrode1)"),
    "FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2": (True, "an Electrode posing as an item ball until battled (AquaHideout_B1F_EventScript_Electrode2)"),
    "FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW": (False, "removed by AquaHideout_B2F_EventScript_SubmarineEscape"),
    "FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE": (False, "set by Underwater_SeafloorCavern_EventScript_HideSubmarine (Kyogre awakened)"),
    "FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT": (False, "set by MossdeepCity_StevensHouse_EventScript_StevenGivesDive"),
    "FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS": (False, "set by SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre"),
    "FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE": (False, "cutscene only: SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre"),
    "FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE": (False, "cutscene only: SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre"),
    "FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE": (False, "cutscene only: SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre"),
    "FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS": (False, "cutscene only: SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre"),
    "FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_ASLEEP": (False, "Kyogre awakened: removed by SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre"),
    "FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE": (False, "removed by CaveOfOrigin_B1F_EventScript_AtSkyPillar"),
    "FLAG_HIDE_SKY_PILLAR_WALLACE": (False, "crisis only: removed by SkyPillar_Outside_EventScript_WallaceScene"),
    "FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA": (False, "removed by SkyPillar_Top_EventScript_AwakenRayquaza (it flew to Sootopolis)"),
    "FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL": (True, "back after the crisis until caught: SkyPillar_Top_EventScript_ShowRayquaza"),
    "FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY": (False, "set by the HoF (EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags)"),
    "FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY": (True, "waits for a rematch: cleared by the HoF (EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags)"),
    "FLAG_HIDE_REGIROCK": (True, "in its chamber until caught (DesertRuins_EventScript_ShowRegirock)"),
    "FLAG_HIDE_REGICE": (True, "in its chamber until caught (IslandCave_EventScript_ShowRegice)"),
    "FLAG_HIDE_REGISTEEL": (True, "in its chamber until caught (AncientTomb_EventScript_ShowRegisteel)"),
    "FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL": (True, "no fossil taken: the tower still stands on Route 111 (its map.json layout)"),
    "FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL": (True, "no fossil taken: the tower still stands on Route 111 (its map.json layout)"),
    "FLAG_HIDE_DESERT_UNDERPASS_FOSSIL": (False, "no Mirage Tower fossil taken: only Route111_EventScript_MirageTowerDisappear clears it"),
    "FLAG_HIDE_MARINE_CAVE_KYOGRE": (True, "there after the HoF until caught (MarineCave_End_EventScript_ShowKyogre)"),
    "FLAG_HIDE_TERRA_CAVE_GROUDON": (True, "there after the HoF until caught (TerraCave_End_EventScript_ShowGroudon)"),
}
# Emerald signs no tile can read: (map, x, y) -> where RFVF+ puts them. Lilycove Dept Store 1F's floor list lies below
# the 18x8 map: it goes on the button panel left of the elevator door (read facing north, as in Emerald).
SIGN_MOVES = {("LilycoveCity_DepartmentStore_1F", 0, 8): (1, 1)}
# Maps whose own script switches the layout unconditionally on every transition: map -> the layout it really shows.
# Conditional switches keep map.json's layout: Route130 (LAYOUT_ROUTE130_MIRAGE_ISLAND only while
# IsMirageIslandPresent), Route111 (LAYOUT_ROUTE111_NO_MIRAGE_TOWER: SetMirageTowerVisibility, random until the fossil
# is taken), SootopolisCity (LEGENDS_BATTLE: weather crisis only), SootopolisCity_MysteryEventsHouse_1F
# (STAIRS_UNBLOCKED: an e-Reader trainer visits), LittlerootTown_ProfessorBirchsLab (WITH_TABLE: every Hoenn Pokemon
# caught, Johto starters). Dungeons: the Sky Pillar keeps its cracked floors (map.json; the CLEAN layouts are for
# VAR_SKY_PILLAR_STATE < 2, before the Sootopolis crisis), Shoal Cave its low tide (the high tide layouts only by
# UpdateShoalTideFlag, a clock), the Mirage Tower has no other layout.
# Warps left onto themselves although Emerald's destination is here: rooms the player could enter but never leave
# without their scripts. (map, warp index) -> reason, in the report.
CLOSED_WARPS = {
    # RFVF+: the Elite Four halls lead one way (Hall5's floor back to the 1F is no warp tile), Sidney's room closes
    # behind the player (EverGrandeCity_SidneysRoom_OnFrame) and opens its way on once he is beaten: the League door
    # stays shut until the Elite Four are scripted
    ("EverGrandeCity_PokemonLeague_1F", 2): "Elite Four not scripted: its halls and rooms have no way back",
    ("EverGrandeCity_PokemonLeague_1F", 3): "Elite Four not scripted: its halls and rooms have no way back",
}
START_LAYOUT = {"Route131": "LAYOUT_ROUTE131_SKY_PILLAR"}  # Route131_OnTransition: Route131_EventScript_SetLayout
# Emerald secondary tilesets one FRLG secondary cannot hold (384 metatiles, 376 tiles): the Emerald layouts of each extra
# sibling, gTileset_Hoenn<Name>2, 3... (design 1.8); every other layout keeps gTileset_Hoenn<Name>. Siblings share the
# natural ids, and every connection strip between two siblings only shows metatiles below 384 (the render check
# compares every strip). Alternate layouts go with their map: LAYOUT_ROUTE111_NO_MIRAGE_TOWER with Route111.
SIBLINGS = {
    "gTileset_Mauville": [{"LAYOUT_ROUTE110", "LAYOUT_ROUTE111", "LAYOUT_ROUTE111_NO_MIRAGE_TOWER"}],
    "gTileset_Slateport": [{"LAYOUT_ROUTE108", "LAYOUT_ROUTE109"}],
    # HoennGenericBuilding, pruned before natural ids, holds the houses of the first 30 units (371/384). The houses
    # none of them uses, those of MossdeepCity, Route110, Route124, SootopolisCity and VerdanturfTown, come here
    # whatever the import order (MossdeepCity's LAYOUT_HOUSE1 and the other shared ones are already there).
    "gTileset_GenericBuilding": [{
        "LAYOUT_MOSSDEEP_CITY_GAME_CORNER_B1F", "LAYOUT_MOSSDEEP_CITY_STEVENS_HOUSE", "LAYOUT_ROUTE110_TRICK_HOUSE_CORRIDOR",
        "LAYOUT_ROUTE110_TRICK_HOUSE_END", "LAYOUT_ROUTE110_TRICK_HOUSE_ENTRANCE",
        "LAYOUT_ROUTE124_DIVING_TREASURE_HUNTERS_HOUSE", "LAYOUT_SOOTOPOLIS_CITY_HOUSE1", "LAYOUT_SOOTOPOLIS_CITY_HOUSE2",
        "LAYOUT_SOOTOPOLIS_CITY_HOUSE3", "LAYOUT_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE",
        "LAYOUT_VERDANTURF_TOWN_WANDAS_HOUSE"}],
    # HoennFacility, pruned before natural ids, holds what the towns and routes need (266/384); with the dungeons it
    # would need 431. Their Facility layouts come here, so HoennFacility never grows again.
    "gTileset_Facility": [{
        "LAYOUT_MT_PYRE_1F", "LAYOUT_MT_PYRE_2F", "LAYOUT_MT_PYRE_3F", "LAYOUT_MT_PYRE_4F", "LAYOUT_MT_PYRE_5F",
        "LAYOUT_MT_PYRE_6F", "LAYOUT_MT_PYRE_EXTERIOR", "LAYOUT_MT_PYRE_SUMMIT", "LAYOUT_AQUA_HIDEOUT_1F",
        "LAYOUT_AQUA_HIDEOUT_B1F", "LAYOUT_AQUA_HIDEOUT_B2F", "LAYOUT_AQUA_HIDEOUT_UNUSED_RUBY_MAP1",
        "LAYOUT_AQUA_HIDEOUT_UNUSED_RUBY_MAP2", "LAYOUT_AQUA_HIDEOUT_UNUSED_RUBY_MAP3", "LAYOUT_NEW_MAUVILLE_ENTRANCE",
        "LAYOUT_ABANDONED_SHIP_DECK", "LAYOUT_ABANDONED_SHIP_CAPTAINS_OFFICE"}],
}
