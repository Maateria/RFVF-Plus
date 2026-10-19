AbandonedShip_Rooms2_B1F_MapScripts::
	.byte 0
AbandonedShip_Rooms2_B1F_EventScript_ItemDiveBall:: @ item ball, works (FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_B1F_DIVE_BALL)
	finditem ITEM_DIVE_BALL
	end
AbandonedShip_Rooms2_B1F_EventScript_Camper::
	msgbox AbandonedShip_Rooms2_B1F_Text_PerfectPlaceToGoExploring, MSGBOX_NPC
	end
