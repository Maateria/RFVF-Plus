AbandonedShip_Rooms_1F_MapScripts::
	.byte 0
AbandonedShip_Rooms_1F_EventScript_ItemHarborMail:: @ item ball, works (FLAG_ITEM_ABANDONED_SHIP_ROOMS_1F_HARBOR_MAIL)
	finditem ITEM_HARBOR_MAIL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/AbandonedShip_Rooms_1F/scripts.inc
AbandonedShip_Rooms_1F_EventScript_Gentleman::  @ NPC #1 (12,5)
AbandonedShip_Rooms_1F_EventScript_Thalia::     @ trainer #3 (10,11) TRAINER_THALIA_1, Emerald NORMAL sight 4
AbandonedShip_Rooms_1F_EventScript_Demetrius::  @ trainer #4 (10,16) TRAINER_DEMETRIUS, Emerald NORMAL sight 4
	end
