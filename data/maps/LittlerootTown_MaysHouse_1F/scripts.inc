.equ LOCALID_RIVALS_HOUSE_1F_MOM, 1

LittlerootTown_MaysHouse_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (LittlerootTown_MaysHouse_1F_OnLoad), ON_TRANSITION (LittlerootTown_MaysHouse_1F_OnTransition), ON_FRAME_TABLE (LittlerootTown_MaysHouse_1F_OnFrame)
@ hoenn_import: left out: trigger (2,8) VAR_LITTLEROOT_INTRO_STATE==4 -> LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom; trigger (1,3) VAR_LITTLEROOT_RIVAL_STATE==2 -> LittlerootTown_MaysHouse_1F_EventScript_MeetRival0; trigger (2,4) VAR_LITTLEROOT_RIVAL_STATE==2 -> LittlerootTown_MaysHouse_1F_EventScript_MeetRival1; trigger (3,3) VAR_LITTLEROOT_RIVAL_STATE==2 -> LittlerootTown_MaysHouse_1F_EventScript_MeetRival2
