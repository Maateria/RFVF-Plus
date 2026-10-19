HoennSafariZone_North_MapScripts::
	.byte 0
HoennSafariZone_North_EventScript_ItemCalcium:: @ item ball, works (FLAG_ITEM_HOENN_SAFARI_ZONE_NORTH_CALCIUM)
	finditem ITEM_CALCIUM
	end
HoennSafariZone_North_EventScript_Fisherman::
	msgbox HoennSafariZone_North_Text_Fisherman, MSGBOX_NPC
	end

HoennSafariZone_North_EventScript_Man::
	msgbox HoennSafariZone_North_Text_Man, MSGBOX_NPC
	end
