@ johto_import: generated from PokemonHnS data/maps/EcruteakCity_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

EcruteakCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition:
	setrespawn SPAWN_ECRUTEAK_CITY
	end

EcruteakCity_PokemonCenter_EventScript_Nurse::  @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/EcruteakCity_PokemonCenter_hns/scripts.inc)
EcruteakCity_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
EcruteakCity_PokemonCenter_EventScript_Nerd::   @ SUPER_NERD_HNS #3 (14,6)
EcruteakCity_PokemonCenter_EventScript_Hiker::  @ HIKER_HNS #4 (11,5)
EcruteakCity_PokemonCenter_EventScript_Woman::  @ WOMAN_2_HNS #5 (2,5)
EcruteakCity_PokemonCenter_EventScript_WallClock:: @ sign (3,1)
EcruteakCity_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
