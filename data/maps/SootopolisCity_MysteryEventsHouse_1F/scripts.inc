.equ LOCALID_MYSTERY_EVENTS_OLD_MAN, 1

SootopolisCity_MysteryEventsHouse_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (SootopolisCity_MysteryEventsHouse_1F_OnTransition), ON_FRAME_TABLE (SootopolisCity_MysteryEventsHouse_1F_OnFrame)
@ No e-Reader trainer ever visits: Emerald's own text then
SootopolisCity_MysteryEventsHouse_1F_EventScript_OldMan::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_NPC
	end

