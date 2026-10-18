@ johto_import: generated from PokemonHnS data/maps/TinTower_3F_hns; scripted maps get their own file later
TinTower_3F_MapScripts::
	.byte 0

TinTower_3F_EventScript_Item1::                 @ item ball (FLAG_ITEM_TIN_TOWER_3F_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end

@ silent until scripted (PokemonHnS data/maps/TinTower_3F_hns/scripts.inc)
TinTower_3F_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (17,3)
	end
