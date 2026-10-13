.equ LOCALID_MARINE_CAVE_KYOGRE, 1

MarineCave_End_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (MarineCave_End_OnResume), ON_TRANSITION (MarineCave_End_OnTransition)
@ hoenn_import: left out: trigger (9,26) VAR_TEMP_1==1 -> MarineCave_End_EventScript_Kyogre
