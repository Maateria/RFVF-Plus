.equ LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 4
.equ LOCALID_SLATEPORT_HARBOR_SS_TIDAL, 5

SlateportCity_Harbor_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (SlateportCity_Harbor_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SlateportCity_Harbor/scripts.inc
SlateportCity_Harbor_EventScript_FerryAttendant:: @ NPC #1 (8,10)
SlateportCity_Harbor_EventScript_Sailor::       @ NPC #2 (4,12)
SlateportCity_Harbor_EventScript_FatMan::       @ NPC #3 (1,12)
SlateportCity_Harbor_EventScript_CaptStern::    @ NPC #4 (6,13)
	end
@ hoenn_import: left out: trigger (8,11) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger0; trigger (8,12) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger1; trigger (8,13) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger2; trigger (8,14) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger3
