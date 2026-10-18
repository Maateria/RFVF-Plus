@ johto_import: generated from PokemonHnS data/maps/SproutTower_2F_hns; scripted maps get their own file later
SproutTower_2F_MapScripts::
	.byte 0

SproutTower_2F_EventScript_Item3::              @ item ball (FLAG_ITEM_SPROUT_TOWER_X_DEFEND)
	finditem ITEM_X_DEFEND
	end

@ silent until scripted (PokemonHnS data/maps/SproutTower_2F_hns/scripts.inc)
SproutTower_2F_EventScript_SageEdmond::         @ SAGE_HNS #1 (3,14), trainer TRAINER_EDMOND_HNS
SproutTower_2F_EventScript_SageNico::           @ SAGE_HNS #2 (14,2), trainer TRAINER_NICO_HNS
SproutTower_2F_EventScript_Statue::             @ sign (12,16)
	end
