LilycoveCity_PokemonCenter_2F_MapScripts::
	.byte 0

@ The link rooms stay closed (their barriers are never opened): the three attendants only apologize.
LilycoveCity_PokemonCenter_2F_EventScript_UnionRoomAttendant::
LilycoveCity_PokemonCenter_2F_EventScript_WirelessClubAttendant::
LilycoveCity_PokemonCenter_2F_EventScript_DirectCornerAttendant::
	msgbox LilycoveCity_PokemonCenter_2F_Text_ServiceUnavailable, MSGBOX_NPC
	end
