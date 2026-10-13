.equ LOCALID_ROUTE112_CABLE_CAR_ATTENDANT, 1

Route112_CableCarStation_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route112_CableCarStation_OnTransition), ON_FRAME_TABLE (Route112_CableCarStation_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route112_CableCarStation/scripts.inc
Route112_CableCarStation_EventScript_Attendant:: @ NPC #1 (6,6)
	end
