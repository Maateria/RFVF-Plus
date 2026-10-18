@ johto_import: generated from PokemonHnS data/maps/Route43_hns; scripted maps get their own file later
Route43_MapScripts::
	.byte 0

Route43_EventScript_Item5::                     @ item ball (FLAG_ITEM_ROUTE43_MAX_ETHER)
	finditem ITEM_MAX_ETHER
	end

@ silent until scripted (PokemonHnS data/maps/Route43_hns/scripts.inc)
Route43_EventScript_Spencer::                   @ CAMPER_HNS #1 (14,40), trainer TRAINER_SPENCER_HNS
Route43_EventScript_Tiffany::                   @ PICNICKER_HNS #2 (10,24), trainer TRAINER_TIFFANY_HNS
Route43_EventScript_Ben::                       @ FAT_MAN_HNS #3 (16,16), trainer TRAINER_BEN_HNS
Route43_EventScript_Marvin::                    @ FISHERMAN_HNS #4 (7,15), trainer TRAINER_MARVIN_HNS
Route43_EventScript_Ron::                       @ SUPER_NERD_HNS #6 (25,24), trainer TRAINER_RON_HNS
Route43_EventScript_Brent::                     @ SUPER_NERD_HNS #7 (23,20), trainer TRAINER_BRENT_HNS
Route43_EventScript_Sign1::                     @ sign (17,3)
Route43_EventScript_Sign2::                     @ sign (21,39)
	end
