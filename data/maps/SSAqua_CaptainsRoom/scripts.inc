@ johto_import: generated from PokemonHnS data/maps/SSAqua_CaptainsRoom_hns; scripted maps get their own file later
.equ LOCALID_SSAQUA_CAPTAINS_ROOM_CAPTAIN, 1

SSAqua_CaptainsRoom_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/SSAqua_CaptainsRoom_hns/scripts.inc)
SSAqua_CaptainsRoom_EventScript_Captain::       @ CAPTAIN_HNS #1 (5,2)
	end
