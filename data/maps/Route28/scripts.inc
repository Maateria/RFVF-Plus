@ johto_import: generated from PokemonHnS data/maps/Route28_hns; scripted maps get their own file later
Route28_MapScripts::
	.byte 0

Route28_EventScript_Item1::                     @ item ball (FLAG_ITEM_ROUTE28_TM_FLAMETHROWER)
	finditem ITEM_TM35_FLAMETHROWER
	end

@ silent until scripted (PokemonHnS data/maps/Route28_hns/scripts.inc)
Route28_EventScript_Sign::                      @ sign (56,14)
	end
