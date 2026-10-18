@ johto_import: generated from PokemonHnS data/maps/OlivineCity_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

OlivineCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition:
	setrespawn SPAWN_OLIVINE_CITY
	end

OlivineCity_PokemonCenter_EventScript_Nurse::   @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/OlivineCity_PokemonCenter_hns/scripts.inc)
OlivineCity_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
OlivineCity_PokemonCenter_EventScript_Fisher::  @ FAT_MAN_HNS #3 (2,6)
OlivineCity_PokemonCenter_EventScript_Teacher:: @ LASS_HNS #4 (12,5)
OlivineCity_PokemonCenter_EventScript_WallClock:: @ sign (3,1)
OlivineCity_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
