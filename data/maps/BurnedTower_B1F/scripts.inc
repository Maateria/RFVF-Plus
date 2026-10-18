@ johto_import: generated from PokemonHnS data/maps/BurnedTower_B1F_hns; scripted maps get their own file later
BurnedTower_B1F_MapScripts::
	.byte 0

BurnedTower_B1F_EventScript_Item1::             @ item ball (FLAG_ITEM_BURNED_TOWER_B1F_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end

BurnedTower_B1F_EventScript_Item2::             @ item ball (FLAG_ITEM_BURNED_TOWER_B1F_TM_TAUNT)
	finditem ITEM_TM12_TAUNT
	end

