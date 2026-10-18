@ johto_import: generated from PokemonHnS data/maps/Route32_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

Route32_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition
	.byte 0

Route32_PokemonCenter_OnTransition:
	setrespawn SPAWN_ROUTE_32
	end

Route32_PokemonCenter_EventScript_Nurse::       @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/Route32_PokemonCenter_hns/scripts.inc)
Route32_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
Route32_PokemonCenter_EventScript_FishingGuru:: @ FISHERMAN_HNS #3 (2,5)
Route32_PokemonCenter_EventScript_Lass::        @ LASS_HNS #4 (11,5)
Route32_PokemonCenter_EventScript_WallClock::   @ sign (3,1)
Route32_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
