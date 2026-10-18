@ johto_import: generated from PokemonHnS data/maps/TinTower_7F_hns; scripted maps get their own file later
TinTower_7F_MapScripts::
	.byte 0

TinTower_7F_EventScript_Item1::                 @ item ball (FLAG_ITEM_TIN_TOWER_7F_MAX_REVIVE)
	finditem ITEM_MAX_REVIVE
	end

@ silent until scripted (PokemonHnS data/maps/TinTower_7F_hns/scripts.inc)
TinTower_7F_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (16,3)
	end
