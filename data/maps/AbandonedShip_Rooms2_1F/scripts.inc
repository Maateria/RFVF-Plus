AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0
AbandonedShip_Rooms2_1F_EventScript_ItemRevive:: @ item ball, works (FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_REVIVE)
	finditem ITEM_REVIVE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/AbandonedShip_Rooms2_1F/scripts.inc
AbandonedShip_Rooms2_1F_EventScript_Dan::       @ trainer #1 (7,13) TRAINER_KIRA_AND_DAN_1, Emerald NORMAL sight 1
AbandonedShip_Rooms2_1F_EventScript_Kira::      @ trainer #2 (6,13) TRAINER_KIRA_AND_DAN_1, Emerald NORMAL sight 1
AbandonedShip_Rooms2_1F_EventScript_Garrison::  @ trainer #4 (3,2) TRAINER_GARRISON, Emerald NORMAL sight 3
AbandonedShip_Rooms2_1F_EventScript_Jani::      @ trainer #5 (7,2) TRAINER_JANI, Emerald NORMAL sight 3
	end
