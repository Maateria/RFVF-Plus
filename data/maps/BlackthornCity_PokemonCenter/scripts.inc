@ johto_import: generated from PokemonHnS data/maps/BlackthornCity_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

BlackthornCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition:
	setrespawn SPAWN_BLACKTHORN_CITY
	end

BlackthornCity_PokemonCenter_EventScript_Nurse:: @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/BlackthornCity_PokemonCenter_hns/scripts.inc)
BlackthornCity_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
BlackthornCity_PokemonCenter_EventScript_Gent:: @ GENTLEMAN_HNS #3 (12,5)
BlackthornCity_PokemonCenter_EventScript_Twin:: @ TWIN_HNS #4 (2,6)
BlackthornCity_PokemonCenter_EventScript_WallClock:: @ sign (3,1)
BlackthornCity_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
