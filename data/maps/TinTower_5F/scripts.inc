@ johto_import: generated from PokemonHnS data/maps/TinTower_5F_hns; scripted maps get their own file later
TinTower_5F_MapScripts::
	.byte 0

TinTower_5F_EventScript_Item1::                 @ item ball (FLAG_ITEM_TIN_TOWER_5F_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end

TinTower_5F_EventScript_Item3::                 @ item ball (FLAG_ITEM_TIN_TOWER_5F_CARBOS)
	finditem ITEM_CARBOS
	end

