AbandonedShip_Corridors_B1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (AbandonedShip_Corridors_B1F_OnResume), ON_LOAD (AbandonedShip_Corridors_B1F_OnLoad)
AbandonedShip_Corridors_B1F_EventScript_TuberM::
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/AbandonedShip_Corridors_B1F/scripts.inc
AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor:: @ sign (11,4)
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan::
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end
