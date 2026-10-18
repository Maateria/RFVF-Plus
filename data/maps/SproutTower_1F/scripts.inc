@ johto_import: generated from PokemonHnS data/maps/SproutTower_1F_hns; scripted maps get their own file later
SproutTower_1F_MapScripts::
	.byte 0

SproutTower_1F_EventScript_Item6::              @ item ball (FLAG_ITEM_SPROUT_TOWER_PARALYZE_HEAL)
	finditem ITEM_PARALYZE_HEAL
	end

@ silent until scripted (PokemonHnS data/maps/SproutTower_1F_hns/scripts.inc)
SproutTower_1F_EventScript_Teacher::            @ LASS_HNS #1 (15,9)
SproutTower_1F_EventScript_Sage2::              @ SAGE_HNS #2 (10,4)
SproutTower_1F_EventScript_Sage1::              @ SAGE_HNS #3 (6,8)
SproutTower_1F_EventScript_SageChow::           @ SAGE_HNS #4 (1,2), trainer TRAINER_CHOW_HNS
SproutTower_1F_EventScript_Granny::             @ OLD_WOMAN_HNS #5 (16,4)
SproutTower_1F_EventScript_Statue::             @ sign (12,16)
	end
