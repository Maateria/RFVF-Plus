@ johto_import: generated from PokemonHnS data/maps/MtSilver_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

MtSilver_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_PokemonCenter_OnTransition
	.byte 0

MtSilver_PokemonCenter_OnTransition:
	setrespawn SPAWN_MT_SILVER
	end

MtSilver_PokemonCenter_EventScript_Nurse::      @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/MtSilver_PokemonCenter_hns/scripts.inc)
MtSilver_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
MtSilver_PokemonCenter_EventScript_Meara::      @ SCIENTIST_F_HNS #3 (12,5)
MtSilver_PokemonCenter_EventScript_WallClock::  @ sign (3,1)
MtSilver_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
