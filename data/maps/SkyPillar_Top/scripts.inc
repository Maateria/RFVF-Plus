SkyPillar_Top_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_WARP_INTO_MAP_TABLE (SkyPillar_Top_OnWarp)
@ Emerald's state after the story (VAR_SKY_PILLAR_STATE 2+): Rayquaza is back at the top
SkyPillar_Top_OnResume:
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, SkyPillar_Top_EventScript_TryRemoveRayquaza
	end

SkyPillar_Top_OnTransition:
	call_if_set FLAG_CAUGHT_RAYQUAZA, SkyPillar_Top_EventScript_HideRayquaza
	call_if_set FLAG_DEFEATED_RAYQUAZA, SkyPillar_Top_EventScript_HideRayquaza
	end

SkyPillar_Top_EventScript_TryRemoveRayquaza::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_EventScript_HideRayquaza::
	setflag FLAG_TEMP_1
	return

SkyPillar_Top_EventScript_Rayquaza::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lockall
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAYQUAZA, 70
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SkyPillar_Top_EventScript_DefeatedRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SkyPillar_Top_EventScript_RanFromRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SkyPillar_Top_EventScript_RanFromRayquaza
	setflag FLAG_CAUGHT_RAYQUAZA
	release
	end

SkyPillar_Top_EventScript_DefeatedRayquaza::
	setflag FLAG_DEFEATED_RAYQUAZA
	goto Common_EventScript_RemoveStaticPokemon
	end

SkyPillar_Top_EventScript_RanFromRayquaza::
	setflag FLAG_DEFEATED_RAYQUAZA
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto Common_EventScript_LegendaryFlewAway
	end

@ hoenn_import: left out: trigger (14,9) VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE==0 -> SkyPillar_Top_EventScript_AwakenRayquaza
