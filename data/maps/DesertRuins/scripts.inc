DesertRuins_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertRuins_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, DesertRuins_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, DesertRuins_OnResume
	.byte 0
DesertRuins_OnResume:
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, DesertRuins_EventScript_TryRemoveRegirock
	end

DesertRuins_OnLoad:
	call_if_unset FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_HideRegiEntrance
	end

DesertRuins_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_HoennCave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_HoennCave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_HoennCave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_HoennCave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_HoennCave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_HoennCave_SealedChamberBraille_Mid, TRUE
	return

DesertRuins_OnTransition:
	call_if_set FLAG_CAUGHT_REGIROCK, DesertRuins_EventScript_HideRegirock
	call_if_set FLAG_DEFEATED_REGIROCK, DesertRuins_EventScript_HideRegirock
	end

DesertRuins_EventScript_TryRemoveRegirock::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

DesertRuins_EventScript_HideRegirock::
	setflag FLAG_TEMP_1
	return

DesertRuins_EventScript_Regirock::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIROCK, 40
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DesertRuins_EventScript_DefeatedRegirock
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DesertRuins_EventScript_RanFromRegirock
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DesertRuins_EventScript_RanFromRegirock
	setflag FLAG_CAUGHT_REGIROCK
	release
	end

DesertRuins_EventScript_DefeatedRegirock::
	setflag FLAG_DEFEATED_REGIROCK
	goto Common_EventScript_RemoveStaticPokemon
	end

DesertRuins_EventScript_RanFromRegirock::
	setflag FLAG_DEFEATED_REGIROCK
	setvar VAR_0x8004, SPECIES_REGIROCK
	goto Common_EventScript_LegendaryFlewAway
	end

DesertRuins_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_BigHoleInWall
	braillemsgbox DesertRuins_Braille_UseRockSmash
	releaseall
	end

DesertRuins_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

DesertRuins_EventScript_CaveEntranceSide::
	lockall
	braillemsgbox DesertRuins_Braille_UseRockSmash
	releaseall
	end

