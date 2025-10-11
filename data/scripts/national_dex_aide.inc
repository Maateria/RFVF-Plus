PokemonCenter_1F_OnLoad::
# 4 "data/scripts/national_dex_aide.pory"
	callnative ShouldSpawnSoftlockClerk
# 5 "data/scripts/national_dex_aide.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, PokemonCenter_1F_OnLoad_2
# 5 "data/scripts/national_dex_aide.pory"
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenter_1F_OnLoad_2
PokemonCenter_1F_OnLoad_1:
# 9 "data/scripts/national_dex_aide.pory"
	goto_if_set FLAG_SYS_NATIONAL_DEX, PokemonCenter_1F_OnLoad_7
# 9 "data/scripts/national_dex_aide.pory"
	goto_if_unset FLAG_SYS_RECEIVED_EXTENDED_DEX, PokemonCenter_1F_OnLoad_7
# 15 "data/scripts/national_dex_aide.pory"
	callnative HasNationalMonToVarResult
# 16 "data/scripts/national_dex_aide.pory"
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenter_1F_OnLoad_12
# 22 "data/scripts/national_dex_aide.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 23 "data/scripts/national_dex_aide.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne PokemonCenter_1F_OnLoad_15
# 34 "data/scripts/national_dex_aide.pory"
	release
	end

PokemonCenter_1F_OnLoad_2:
# 7 "data/scripts/national_dex_aide.pory"
	setflag FLAG_TEMP_8
	goto PokemonCenter_1F_OnLoad_1

PokemonCenter_1F_OnLoad_7:
# 11 "data/scripts/national_dex_aide.pory"
	setvar VAR_TEMP_0, 1
# 12 "data/scripts/national_dex_aide.pory"
	release
	end

PokemonCenter_1F_OnLoad_12:
# 18 "data/scripts/national_dex_aide.pory"
	setvar VAR_TEMP_0, 1
# 19 "data/scripts/national_dex_aide.pory"
	release
	end

PokemonCenter_1F_OnLoad_15:
# 25 "data/scripts/national_dex_aide.pory"
	callnative CoordsOfPMCExitWarpTo80068007
# 26 "data/scripts/national_dex_aide.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 27 "data/scripts/national_dex_aide.pory"
	compare VAR_0x8008, VAR_0x8006
	goto_if_eq PokemonCenter_1F_OnLoad_19
PokemonCenter_1F_OnLoad_17:
# 31 "data/scripts/national_dex_aide.pory"
	release
	end

PokemonCenter_1F_OnLoad_18:
	goto PokemonCenter_1F_OnLoad_17

PokemonCenter_1F_OnLoad_19:
# 27 "data/scripts/national_dex_aide.pory"
	compare VAR_0x8009, VAR_0x8007
	goto_if_eq PokemonCenter_1F_OnLoad_18
	goto PokemonCenter_1F_OnLoad_17


NationalDexAideEvent::
# 39 "data/scripts/national_dex_aide.pory"
	callnative HasNationalMonToVarResult
# 40 "data/scripts/national_dex_aide.pory"
	compare VAR_RESULT, 0
	goto_if_eq NationalDexAideEvent_2
# 46 "data/scripts/national_dex_aide.pory"
	goto_if_set FLAG_SYS_NATIONAL_DEX, NationalDexAideEvent_5
# 46 "data/scripts/national_dex_aide.pory"
	goto_if_unset FLAG_SYS_RECEIVED_EXTENDED_DEX, NationalDexAideEvent_5
# 52 "data/scripts/national_dex_aide.pory"
	callnative HideWarpArrowSprite
# 53 "data/scripts/national_dex_aide.pory"
	lockall
# 54 "data/scripts/national_dex_aide.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 55 "data/scripts/national_dex_aide.pory"
	waitmovement 0
# 56 "data/scripts/national_dex_aide.pory"
	playse SE_PIN
# 57 "data/scripts/national_dex_aide.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 58 "data/scripts/national_dex_aide.pory"
	waitmovement 0
# 59 "data/scripts/national_dex_aide.pory"
	delay 60
# 60 "data/scripts/national_dex_aide.pory"
	applymovement OBJ_EVENT_ID_PLAYER, NationalDexAideEvent_Movement_BackStep
# 61 "data/scripts/national_dex_aide.pory"
	waitmovement 0
# 62 "data/scripts/national_dex_aide.pory"
	playse SE_EXIT
# 63 "data/scripts/national_dex_aide.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 64 "data/scripts/national_dex_aide.pory"
	addvar VAR_0x8009, 1
# 65 "data/scripts/national_dex_aide.pory"
	setobjectxyperm 2, VAR_0x8008, VAR_0x8009
# 66 "data/scripts/national_dex_aide.pory"
	addobject 2
# 67 "data/scripts/national_dex_aide.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
# 68 "data/scripts/national_dex_aide.pory"
	waitmovement 0
# 69 "data/scripts/national_dex_aide.pory"
	textcolor 0
# 70 "data/scripts/national_dex_aide.pory"
	msgbox NationalDexAideEvent_Text_0
# 71 "data/scripts/national_dex_aide.pory"
	closemessage
# 72 "data/scripts/national_dex_aide.pory"
	textcolor 3
# 73 "data/scripts/national_dex_aide.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 74 "data/scripts/national_dex_aide.pory"
	waitmovement 0
# 75 "data/scripts/national_dex_aide.pory"
	msgbox NationalDexAideEvent_Text_1
# 76 "data/scripts/national_dex_aide.pory"
	closemessage
# 77 "data/scripts/national_dex_aide.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
# 78 "data/scripts/national_dex_aide.pory"
	waitmovement 0
# 79 "data/scripts/national_dex_aide.pory"
	textcolor 0
# 80 "data/scripts/national_dex_aide.pory"
	msgbox NationalDexAideEvent_Text_2
# 81 "data/scripts/national_dex_aide.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
# 82 "data/scripts/national_dex_aide.pory"
	waitmovement 0
# 83 "data/scripts/national_dex_aide.pory"
	msgbox NationalDexAideEvent_Text_3
# 84 "data/scripts/national_dex_aide.pory"
	closemessage
# 85 "data/scripts/national_dex_aide.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
# 86 "data/scripts/national_dex_aide.pory"
	waitmovement 0
# 87 "data/scripts/national_dex_aide.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 88 "data/scripts/national_dex_aide.pory"
	textcolor 3
# 89 "data/scripts/national_dex_aide.pory"
	message PalletTown_ProfessorOaksLab_Text_PlayersPokedexWasUpgraded
# 90 "data/scripts/national_dex_aide.pory"
	waitmessage
# 91 "data/scripts/national_dex_aide.pory"
	waitfanfare
# 92 "data/scripts/national_dex_aide.pory"
	closemessage
# 93 "data/scripts/national_dex_aide.pory"
	textcolor 0
# 94 "data/scripts/national_dex_aide.pory"
	special EnableNationalPokedex
# 95 "data/scripts/national_dex_aide.pory"
	msgbox NationalDexAideEvent_Text_4
# 96 "data/scripts/national_dex_aide.pory"
	closemessage
# 97 "data/scripts/national_dex_aide.pory"
	delay 20
# 98 "data/scripts/national_dex_aide.pory"
	playse SE_EXIT
# 99 "data/scripts/national_dex_aide.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
# 100 "data/scripts/national_dex_aide.pory"
	waitmovement 0
# 101 "data/scripts/national_dex_aide.pory"
	delay 5
# 102 "data/scripts/national_dex_aide.pory"
	removeobject 2
# 103 "data/scripts/national_dex_aide.pory"
	setvar VAR_TEMP_0, 1
# 104 "data/scripts/national_dex_aide.pory"
	releaseall
	end

NationalDexAideEvent_2:
# 42 "data/scripts/national_dex_aide.pory"
	setvar VAR_TEMP_0, 1
# 43 "data/scripts/national_dex_aide.pory"
	release
	end

NationalDexAideEvent_5:
# 48 "data/scripts/national_dex_aide.pory"
	setvar VAR_TEMP_0, 1
# 49 "data/scripts/national_dex_aide.pory"
	release
	end


# 106 "data/scripts/national_dex_aide.pory"
NationalDexAideEvent_Movement_BackStep:
# 107 "data/scripts/national_dex_aide.pory"
	lock_facing_direction
# 108 "data/scripts/national_dex_aide.pory"
	walk_up
# 109 "data/scripts/national_dex_aide.pory"
	unlock_facing_direction
	step_end

NationalDexAideEvent_Text_0:
# 70 "data/scripts/national_dex_aide.pory"
	.string "{PLAYER}! Hi!\nI've been looking for you!\pRemember me?\nI'm one of PROF. OAK'S AIDES.\pPROF. OAK has improved the\nPOKéDEX again and I'm supposed\lto upgrade yours.\pCan I see your POKéDEX?$"

NationalDexAideEvent_Text_1:
# 75 "data/scripts/national_dex_aide.pory"
	.string "The AIDE took your POKéDEX\nunit.$"

NationalDexAideEvent_Text_2:
# 80 "data/scripts/national_dex_aide.pory"
	.string "… … …  … … …\p… … …  … … …$"

NationalDexAideEvent_Text_3:
# 83 "data/scripts/national_dex_aide.pory"
	.string "…And that's done!\pNow this unit can record data on\na lot more POKéMON.\pHere you go!$"

NationalDexAideEvent_Text_4:
# 95 "data/scripts/national_dex_aide.pory"
	.string "Keep catching POKéMON to fill up\nyour improved POKéDEX!\pI better get back to the LAB.\nSee you, {PLAYER}!$"
