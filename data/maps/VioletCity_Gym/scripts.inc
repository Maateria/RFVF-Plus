@ johto_import: generated from PokemonHnS data/maps/VioletCity_Gym_hns; scripted maps get their own file later
VioletCity_Gym_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/VioletCity_Gym_hns/scripts.inc)
VioletCity_Gym_EventScript_Abe::                @ ROCKER_HNS #1 (12,9), trainer TRAINER_ABE_HNS
VioletCity_Gym_EventScript_Rod::                @ ROCKER_HNS #2 (6,13), trainer TRAINER_ROD_HNS
VioletCity_Gym_EventScript_GymGuy::             @ GYM_GUY_HNS #3 (11,17)
VioletCity_Gym_EventScript_Statue::             @ sign (6,17)
	end
