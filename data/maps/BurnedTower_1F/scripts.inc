@ johto_import: generated from PokemonHnS data/maps/BurnedTower_1F_hns; scripted maps get their own file later
BurnedTower_1F_MapScripts::
	.byte 0

BurnedTower_1F_EventScript_Item3::              @ item ball (FLAG_ITEM_BURNED_TOWER_1F_HP_UP)
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item4::              @ item ball (FLAG_ITEM_BURNED_TOWER_1F_ETHER)
	finditem ITEM_ETHER
	end

@ silent until scripted (PokemonHnS data/maps/BurnedTower_1F_hns/scripts.inc)
BurnedTower_1F_EventScript_Nard::               @ FIREBREATHER_HNS #1 (14,4), trainer TRAINER_NARD_HNS
BurnedTower_1F_EventScript_Richardo::           @ BURGLAR_HNS #2 (3,15), trainer TRAINER_RICHARDO_HNS
BurnedTower_1F_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (11,22)
	end
