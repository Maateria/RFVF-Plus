@ johto_import: generated from PokemonHnS data/maps/TinTower_9F_hns; scripted maps get their own file later
TinTower_9F_MapScripts::
	.byte 0

TinTower_9F_EventScript_Item2::                 @ item ball (FLAG_ITEM_TIN_TOWER_8F_MAX_ELIXIR)
	finditem ITEM_MAX_ELIXIR
	end

TinTower_9F_EventScript_Item3::                 @ item ball (FLAG_ITEM_TIN_TOWER_8F_BIG_NUGGET)
	finditem ITEM_NUGGET
	end

@ silent until scripted (PokemonHnS data/maps/TinTower_9F_hns/scripts.inc)
TinTower_9F_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (16,3)
	end
