@ johto_import: generated from PokemonHnS data/maps/Route31_hns; scripted maps get their own file later
Route31_MapScripts::
	.byte 0

Route31_EventScript_Item5::                     @ item ball (FLAG_ITEM_ROUTE_31_POKEBALL)
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_Item6::                     @ item ball (FLAG_ITEM_ROUTE_31_ANTIDOE)
	finditem ITEM_ANTIDOTE
	end

@ silent until scripted (PokemonHnS data/maps/Route31_hns/scripts.inc)
Route31_EventScript_Bugcatcher_Wade::           @ BUG_CATCHER_HNS #1 (23,17), trainer TRAINER_WADE_HNS
Route31_EventScript_Youngster::                 @ YOUNGSTER_HNS #2 (50,13)
Route31_EventScript_SleepyMan::                 @ FAT_MAN_HNS #3 (18,11)
Route31_EventScript_Boy::                       @ BOY_2_HNS #4 (9,9)
Route31_EventScript_Sign::                      @ sign (8,8)
Route31_EventScript_DarkCaveSign::              @ sign (50,10)
	end
