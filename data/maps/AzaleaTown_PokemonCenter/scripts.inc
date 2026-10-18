@ johto_import: generated from PokemonHnS data/maps/AzaleaTown_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

AzaleaTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_PokemonCenter_OnTransition
	.byte 0

AzaleaTown_PokemonCenter_OnTransition:
	setrespawn SPAWN_AZALEA_TOWN
	end

AzaleaTown_PokemonCenter_EventScript_Nurse::    @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/AzaleaTown_PokemonCenter_hns/scripts.inc)
AzaleaTown_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
AzaleaTown_PokemonCenter_EventScript_PokefanF:: @ WOMAN_3_HNS #3 (3,6)
AzaleaTown_PokemonCenter_EventScript_Fisher::   @ FISHERMAN_HNS #4 (13,3)
AzaleaTown_PokemonCenter_EventScript_Gentleman:: @ GENTLEMAN_HNS #5 (12,5)
AzaleaTown_PokemonCenter_EventScript_WallClock:: @ sign (3,1)
AzaleaTown_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
