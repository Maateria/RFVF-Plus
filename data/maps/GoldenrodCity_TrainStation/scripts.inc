@ johto_import: generated from PokemonHnS data/maps/GoldenrodCity_TrainStation_hns; scripted maps get their own file later
.equ LOCALID_GOLDENROD_CITY_TRAIN_STATION_ATTENDANT, 1
.equ LOCALID_GOLDENROD_CITY_TRAIN_STATION_TRAIN, 7

GoldenrodCity_TrainStation_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/GoldenrodCity_TrainStation_hns/scripts.inc)
GoldenrodCity_TrainStation_EventScript_Attendant:: @ OFFICER_HNS #1 (16,20)
GoldenrodCity_TrainStation_EventScript_Gent::   @ GENTLEMAN_HNS #2 (20,23)
GoldenrodCity_TrainStation_EventScript_Boy::    @ LITTLE_BOY_HNS #8 (10,22)
GoldenrodCity_TrainStation_EventScript_Psychic:: @ PSYCHIC_M_HNS #9 (11,22)
	end
