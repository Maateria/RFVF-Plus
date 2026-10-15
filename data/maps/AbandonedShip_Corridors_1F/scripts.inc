AbandonedShip_Corridors_1F_MapScripts::
	.byte 0
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/AbandonedShip_Corridors_1F/scripts.inc
AbandonedShip_Corridors_1F_EventScript_Youngster:: @ NPC #1 (17,7)
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end
