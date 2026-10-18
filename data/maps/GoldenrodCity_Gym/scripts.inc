@ johto_import: generated from PokemonHnS data/maps/GoldenrodCity_Gym_hns; scripted maps get their own file later
.equ LOCALID_GOLDENROD_CITY_GYM_BRIDGET, 6

GoldenrodCity_Gym_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/GoldenrodCity_Gym_hns/scripts.inc)
GoldenrodCity_Gym_EventScript_Gym_Guy::         @ GYM_GUY_HNS #1 (10,20)
GoldenrodCity_Gym_EventScript_Carrie::          @ WOMAN_1_HNS #2 (7,7), trainer TRAINER_CARRIE_HNS
GoldenrodCity_Gym_EventScript_Victoria::        @ WOMAN_2_HNS #3 (15,18), trainer TRAINER_VICTORIA_HNS
GoldenrodCity_Gym_EventScript_Whitney::         @ WHITNEY_HNS #4 (15,8), trainer TRAINER_WHITNEY_1_HNS
GoldenrodCity_Gym_EventScript_Samantha::        @ BEAUTY_HNS #5 (26,10), trainer TRAINER_SAMANTHA_HNS
GoldenrodCity_Gym_EventScript_Bridget::         @ GIRL_1_HNS #6 (16,11), trainer TRAINER_BRIDGET_HNS
GoldenrodCity_Gym_EventScript_Statue::          @ sign (11,20)
	end
