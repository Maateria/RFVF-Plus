@ johto_import: generated from PokemonHnS data/maps/TinTower_6F_hns; scripted maps get their own file later
TinTower_6F_MapScripts::
	.byte 0

TinTower_6F_EventScript_Item1::                 @ item ball (FLAG_ITEM_TIN_TOWER_5F_MAX_POTION)
	finditem ITEM_MAX_POTION
	end

