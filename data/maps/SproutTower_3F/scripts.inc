@ johto_import: generated from PokemonHnS data/maps/SproutTower_3F_hns; scripted maps get their own file later
SproutTower_3F_MapScripts::
	.byte 0

SproutTower_3F_EventScript_Item5::              @ item ball (FLAG_ITEM_SPROUT_TOWER_ESCAPE_ROPE)
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_Item6::              @ item ball (FLAG_ITEM_SPROUT_TOWER_POTION)
	finditem ITEM_POTION
	end

@ silent until scripted (PokemonHnS data/maps/SproutTower_3F_hns/scripts.inc)
SproutTower_3F_EventScript_SageNeal::           @ SAGE_HNS #1 (14,13), trainer TRAINER_NEAL_HNS
SproutTower_3F_EventScript_SageJin::            @ SAGE_HNS #2 (8,14), trainer TRAINER_JIN_HNS
SproutTower_3F_EventScript_SageTroy::           @ SAGE_HNS #3 (11,11), trainer TRAINER_TROY_HNS
SproutTower_3F_EventScript_SageLi::             @ SAGE_ELDER_HNS #4 (11,3), trainer TRAINER_LI_HNS
SproutTower_3F_EventScript_Painting::           @ sign (11,1)
SproutTower_3F_EventScript_Statue::             @ sign (17,17)
	end
