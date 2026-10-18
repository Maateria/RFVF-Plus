@ johto_import: generated from PokemonHnS data/maps/MahoganyTown_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

MahoganyTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition:
	setrespawn SPAWN_MAHOGANY_TOWN
	end

MahoganyTown_PokemonCenter_EventScript_Nurse::  @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/MahoganyTown_PokemonCenter_hns/scripts.inc)
MahoganyTown_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
MahoganyTown_PokemonCenter_EventScript_Hiker::  @ HIKER_HNS #3 (13,3)
MahoganyTown_PokemonCenter_EventScript_Boy::    @ BOY_2_HNS #4 (4,4)
MahoganyTown_PokemonCenter_EventScript_Girl::   @ WOMAN_2_HNS #5 (5,4)
MahoganyTown_PokemonCenter_EventScript_WallClock:: @ sign (3,1)
MahoganyTown_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
