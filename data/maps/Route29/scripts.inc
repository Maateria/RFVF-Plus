@ johto_import: generated from PokemonHnS data/maps/Route29_hns; scripted maps get their own file later
Route29_MapScripts::
	.byte 0

Route29_EventScript_Item8::                     @ item ball (FLAG_ITEM_ROUTE_29_POTION)
	finditem ITEM_POTION
	end

@ silent until scripted (PokemonHnS data/maps/Route29_hns/scripts.inc)
Route29_EventScript_OldMan::                    @ OLD_MAN_2_HNS #1 (61,16)
Route29_EventScript_Youngster::                 @ YOUNGSTER_HNS #2 (35,22)
Route29_EventScript_Boy::                       @ BOY_2_HNS #3 (11,12)
Route29_EventScript_Tuscany::                   @ FAT_MAN_HNS #4 (25,12)
Route29_EventScript_Girl::                      @ WOMAN_1_HNS #5 (6,22)
Route29_EventScript_Lass::                      @ LASS_HNS #7 (37,14)
Route29_EventScript_Sign::                      @ sign (64,15)
	end
