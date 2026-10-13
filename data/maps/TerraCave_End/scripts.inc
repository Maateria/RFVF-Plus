.equ LOCALID_TERRA_CAVE_GROUDON, 1

TerraCave_End_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (TerraCave_End_OnResume), ON_TRANSITION (TerraCave_End_OnTransition)
@ hoenn_import: left out: trigger (17,26) VAR_TEMP_1==1 -> TerraCave_End_EventScript_Groudon
