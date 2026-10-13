AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0
AbandonedShip_CaptainsOffice_EventScript_ItemStorageKey:: @ item ball, works (FLAG_ITEM_ABANDONED_SHIP_CAPTAINS_OFFICE_STORAGE_KEY)
	finditem ITEM_STORAGE_KEY
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/AbandonedShip_CaptainsOffice/scripts.inc
AbandonedShip_CaptainsOffice_EventScript_CaptSternAide:: @ NPC #1 (3,4)
	end
