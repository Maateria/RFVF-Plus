.equ LOCALID_SAFARI_EXIT_ATTENDANT, 1

HoennSafariZone_South_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (HoennSafariZone_South_OnTransition), ON_FRAME_TABLE (HoennSafariZone_South_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SafariZone_South/scripts.inc
HoennSafariZone_South_EventScript_ExitAttendant:: @ NPC #1 (31,34)
HoennSafariZone_South_EventScript_Boy::         @ NPC #2 (26,28)
HoennSafariZone_South_EventScript_Man::         @ NPC #3 (16,6)
HoennSafariZone_South_EventScript_Youngster::   @ NPC #4 (15,31)
	end
