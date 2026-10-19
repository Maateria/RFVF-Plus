HoennSafariZone_Southwest_MapScripts::
	.byte 0
HoennSafariZone_Southwest_EventScript_ItemMaxRevive:: @ item ball, works (FLAG_ITEM_HOENN_SAFARI_ZONE_SOUTH_WEST_MAX_REVIVE)
	finditem ITEM_MAX_REVIVE
	end
HoennSafariZone_Southwest_EventScript_Woman::
	msgbox HoennSafariZone_Southwest_Text_Woman, MSGBOX_NPC
	end

HoennSafariZone_Southwest_EventScript_RestHouseSign::
	msgbox HoennSafariZone_Southwest_Text_RestHouseSign, MSGBOX_SIGN
	end
