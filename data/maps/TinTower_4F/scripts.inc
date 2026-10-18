@ johto_import: generated from PokemonHnS data/maps/TinTower_4F_hns; scripted maps get their own file later
TinTower_4F_MapScripts::
	.byte 0

TinTower_4F_EventScript_Item1::                 @ item ball (FLAG_ITEM_TIN_TOWER_4F_MAX_POTION)
	finditem ITEM_MAX_POTION
	end

TinTower_4F_EventScript_Item2::                 @ item ball (FLAG_ITEM_TIN_TOWER_4F_ESCAPE_ROPE)
	finditem ITEM_ESCAPE_ROPE
	end

TinTower_4F_EventScript_Item3::                 @ item ball (FLAG_ITEM_TIN_TOWER_4F_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end

@ silent until scripted (PokemonHnS data/maps/TinTower_4F_hns/scripts.inc)
TinTower_4F_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (11,3)
	end
