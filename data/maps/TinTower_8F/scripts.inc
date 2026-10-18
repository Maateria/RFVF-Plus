@ johto_import: generated from PokemonHnS data/maps/TinTower_8F_hns; scripted maps get their own file later
TinTower_8F_MapScripts::
	.byte 0

TinTower_8F_EventScript_Item1::                 @ item ball (FLAG_ITEM_TIN_TOWER_8F_FULL_RESTORE)
	finditem ITEM_FULL_RESTORE
	end

@ silent until scripted (PokemonHnS data/maps/TinTower_8F_hns/scripts.inc)
TinTower_8F_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (14,3)
	end
