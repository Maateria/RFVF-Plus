.equ LOCALID_MT_CHIMNEY_CABLE_CAR_ATTENDANT, 1

MtChimney_CableCarStation_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MtChimney_CableCarStation_OnTransition), ON_FRAME_TABLE (MtChimney_CableCarStation_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MtChimney_CableCarStation/scripts.inc
MtChimney_CableCarStation_EventScript_Attendant:: @ NPC #1 (6,6)
	end
