.equ LOCALID_MARINE_CAVE_KYOGRE, 1

MarineCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_End_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_End_OnResume
	.byte 0
@ hoenn_import: left out: trigger (9,26) VAR_TEMP_1==1 -> MarineCave_End_EventScript_Kyogre

MarineCave_End_OnResume:
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, MarineCave_End_EventScript_TryRemoveKyogre
	end

MarineCave_End_EventScript_TryRemoveKyogre::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MARINE_CAVE_KYOGRE
	return

MarineCave_End_OnTransition:
	call_if_set FLAG_CAUGHT_KYOGRE, MarineCave_End_EventScript_HideKyogre
	call_if_set FLAG_DEFEATED_KYOGRE, MarineCave_End_EventScript_HideKyogre
	goto_if_set FLAG_TEMP_1, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 1
	end

MarineCave_End_EventScript_HideKyogre::
	setflag FLAG_TEMP_1
	return

@ Emerald's; the weather ends back on the route, a new one comes (src/hoenn_dungeons.c)
MarineCave_End_EventScript_Kyogre::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_MARINE_CAVE_KYOGRE, MarineCave_End_Movement_KyogreApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_MARINE_CAVE_KYOGRE
	setwildbattle SPECIES_KYOGRE, 70
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	setvar VAR_TEMP_1, 0
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MarineCave_End_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MarineCave_End_EventScript_RanFromKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MarineCave_End_EventScript_RanFromKyogre
	setflag FLAG_CAUGHT_KYOGRE
	releaseall
	end

MarineCave_End_EventScript_DefeatedKyogre::
	setflag FLAG_DEFEATED_KYOGRE
	goto Common_EventScript_RemoveStaticPokemon
	end

MarineCave_End_EventScript_RanFromKyogre::
	setflag FLAG_DEFEATED_KYOGRE
	setvar VAR_0x8004, SPECIES_KYOGRE
	goto Common_EventScript_LegendaryFlewAway
	end

MarineCave_End_Movement_KyogreApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end
