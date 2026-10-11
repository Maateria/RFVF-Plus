Route121_SafariZoneEntrance_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (Route121_SafariZoneEntrance_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route121_SafariZoneEntrance/scripts.inc
Route121_SafariZoneEntrance_EventScript_WelcomeAttendant:: @ NPC #1 (17,9)
Route121_SafariZoneEntrance_EventScript_InfoAttendant:: @ NPC #2 (10,2)
Route121_SafariZoneEntrance_EventScript_TrainerTipSign:: @ sign (15,1)
	end
@ hoenn_import: left out: trigger (8,4) VAR_TEMP_1==0 -> Route121_SafariZoneEntrance_EventScript_EntranceCounterTrigger
