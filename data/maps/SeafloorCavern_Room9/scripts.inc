SeafloorCavern_Room9_MapScripts::
	.byte 0
SeafloorCavern_Room9_EventScript_ItemTMEarthquake:: @ item ball, works (FLAG_ITEM_SEAFLOOR_CAVERN_ROOM_9_TM_EARTHQUAKE)
	finditem ITEM_TM26_EARTHQUAKE
	end
@ hoenn_import: left out: trigger (17,42) VAR_SEAFLOOR_CAVERN_STATE==0 -> SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre
