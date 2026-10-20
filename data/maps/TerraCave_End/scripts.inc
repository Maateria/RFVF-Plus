.equ LOCALID_TERRA_CAVE_GROUDON, 1

TerraCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_End_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_End_OnResume
	.byte 0
@ hoenn_import: left out: trigger (17,26) VAR_TEMP_1==1 -> TerraCave_End_EventScript_Groudon

TerraCave_End_OnResume:
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, TerraCave_End_EventScript_TryRemoveGroudon
	end

TerraCave_End_EventScript_TryRemoveGroudon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_TERRA_CAVE_GROUDON
	return

TerraCave_End_OnTransition:
	call_if_set FLAG_CAUGHT_GROUDON, TerraCave_End_EventScript_HideGroudon
	call_if_set FLAG_DEFEATED_GROUDON, TerraCave_End_EventScript_HideGroudon
	goto_if_set FLAG_TEMP_1, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 1
	end

TerraCave_End_EventScript_HideGroudon::
	setflag FLAG_TEMP_1
	return

@ Emerald's; the weather ends back on the route, a new one comes (src/hoenn_dungeons.c)
TerraCave_End_EventScript_Groudon::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_TERRA_CAVE_GROUDON, TerraCave_End_Movement_GroudonApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_TERRA_CAVE_GROUDON
	setwildbattle SPECIES_GROUDON, 70
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	setvar VAR_TEMP_1, 0
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TerraCave_End_EventScript_DefeatedGroudon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TerraCave_End_EventScript_RanFromGroudon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TerraCave_End_EventScript_RanFromGroudon
	setflag FLAG_CAUGHT_GROUDON
	releaseall
	end

TerraCave_End_EventScript_DefeatedGroudon::
	setflag FLAG_DEFEATED_GROUDON
	goto Common_EventScript_RemoveStaticPokemon
	end

TerraCave_End_EventScript_RanFromGroudon::
	setflag FLAG_DEFEATED_GROUDON
	setvar VAR_0x8004, SPECIES_GROUDON
	goto Common_EventScript_LegendaryFlewAway
	end

TerraCave_End_Movement_GroudonApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end
