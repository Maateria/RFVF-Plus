HoennSafariZone_Northeast_MapScripts::
	.byte 0
HoennSafariZone_Northeast_EventScript_ItemNugget:: @ item ball, works (FLAG_ITEM_HOENN_SAFARI_ZONE_NORTH_EAST_NUGGET)
	finditem ITEM_NUGGET
	end
HoennSafariZone_Northeast_EventScript_Boy::
	msgbox HoennSafariZone_Northeast_Text_Boy, MSGBOX_NPC
	end

HoennSafariZone_Northeast_EventScript_Girl::
	msgbox HoennSafariZone_Northeast_Text_Girl, MSGBOX_NPC
	end

HoennSafariZone_Northeast_EventScript_Woman::
	msgbox HoennSafariZone_Northeast_Text_Woman, MSGBOX_NPC
	end
