@ johto_import: generated from PokemonHnS data/maps/VioletCity_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

VioletCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_PokemonCenter_OnTransition
	.byte 0

VioletCity_PokemonCenter_OnTransition:
	setrespawn SPAWN_VIOLET_CITY
	end

VioletCity_PokemonCenter_EventScript_Nurse::    @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/VioletCity_PokemonCenter_hns/scripts.inc)
VioletCity_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
VioletCity_PokemonCenter_EventScript_Gentleman:: @ GENTLEMAN_HNS #3 (12,5)
VioletCity_PokemonCenter_EventScript_Man::      @ WORKER_M_HNS #4 (3,6)
VioletCity_PokemonCenter_EventScript_VioletCity_PokemonCenter_EVentScript_Kid:: @ GAMEBOY_KID_HNS #5 (12,2)
VioletCity_PokemonCenter_EventScript_VioletCity_PokemonCenter_Text_BookshelfWoman:: @ BEAUTY_HNS #6 (2,2)
VioletCity_PokemonCenter_EventScript_WallClock:: @ sign (3,1)
VioletCity_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
