HoennSafariZone_Northwest_MapScripts::
	.byte 0
HoennSafariZone_Northwest_EventScript_ItemTMSolarBeam:: @ item ball, works (FLAG_ITEM_HOENN_SAFARI_ZONE_NORTH_WEST_TM_SOLAR_BEAM)
	finditem ITEM_TM22_SOLAR_BEAM
	end
HoennSafariZone_Northwest_EventScript_Man::
	msgbox HoennSafariZone_Northwest_Text_Man, MSGBOX_NPC
	end
