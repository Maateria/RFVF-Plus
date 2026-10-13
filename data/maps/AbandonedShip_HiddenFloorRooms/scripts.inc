AbandonedShip_HiddenFloorRooms_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (AbandonedShip_HiddenFloorRooms_OnFrame)
AbandonedShip_HiddenFloorRooms_EventScript_ItemLuxuryBall:: @ item ball, works (FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_6_LUXURY_BALL)
	finditem ITEM_LUXURY_BALL
	end
AbandonedShip_HiddenFloorRooms_EventScript_ItemScanner:: @ item ball, works (FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER)
	finditem ITEM_SCANNER
	end
AbandonedShip_HiddenFloorRooms_EventScript_ItemTMRainDance:: @ item ball, works (FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_1_TM_RAIN_DANCE)
	finditem ITEM_TM18_RAIN_DANCE
	end
AbandonedShip_HiddenFloorRooms_EventScript_ItemWaterStone:: @ item ball, works (FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_3_WATER_STONE)
	finditem ITEM_WATER_STONE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/AbandonedShip_HiddenFloorRooms/scripts.inc
AbandonedShip_HiddenFloorRooms_EventScript_Trash:: @ sign (8,5)
	end
