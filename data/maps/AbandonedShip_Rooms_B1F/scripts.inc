AbandonedShip_Rooms_B1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (AbandonedShip_Rooms_B1F_OnResume)
AbandonedShip_Rooms_B1F_EventScript_ItemEscapeRope:: @ item ball, works (FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_ESCAPE_ROPE)
	finditem ITEM_ESCAPE_ROPE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/AbandonedShip_Rooms_B1F/scripts.inc
AbandonedShip_Rooms_B1F_EventScript_FatMan::    @ NPC #1 (25,6)
	end
