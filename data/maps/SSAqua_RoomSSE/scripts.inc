@ johto_import: generated from PokemonHnS data/maps/SSAqua_RoomSSE_hns; scripted maps get their own file later
.equ LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, 1

SSAqua_RoomSSE_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/SSAqua_RoomSSE_hns/scripts.inc)
SSAqua_RoomSSE_EventScript_Grandpa::            @ GENTLEMAN_HNS #1 (1,4)
	end
