.equ LOCALID_LITTLEROOT_TWIN, 1

LittlerootTown_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (LittlerootTown_OnTransition), ON_FRAME_TABLE (LittlerootTown_OnFrame), ON_WARP_INTO_MAP_TABLE (LittlerootTown_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/LittlerootTown/scripts.inc
LittlerootTown_EventScript_Twin::               @ NPC #1 (16,10)
LittlerootTown_EventScript_FatMan::             @ NPC #2 (12,13)
LittlerootTown_EventScript_Boy::                @ NPC #3 (14,17)
LittlerootTown_EventScript_TownSign::           @ sign (15,13)
LittlerootTown_EventScript_BirchsLabSign::      @ sign (6,17)
LittlerootTown_EventScript_BrendansHouseSign::  @ sign (7,8)
LittlerootTown_EventScript_MaysHouseSign::      @ sign (12,8)
	end
@ hoenn_import: left out: trigger (10,1) VAR_LITTLEROOT_TOWN_STATE==0 -> LittlerootTown_EventScript_NeedPokemonTriggerLeft; trigger (11,1) VAR_LITTLEROOT_TOWN_STATE==0 -> LittlerootTown_EventScript_NeedPokemonTriggerRight; trigger (11,1) VAR_LITTLEROOT_TOWN_STATE==1 -> LittlerootTown_EventScript_GoSaveBirchTrigger; trigger (8,9) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger4; trigger (9,9) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger5; trigger (10,9) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger2; trigger (11,9) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger3; trigger (10,2) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger0; trigger (11,2) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger1
