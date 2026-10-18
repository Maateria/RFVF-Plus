@ johto_import: generated from PokemonHnS data/maps/CherrygroveCity_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

CherrygroveCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherrygroveCity_PokemonCenter_OnTransition
	.byte 0

CherrygroveCity_PokemonCenter_OnTransition:
	setrespawn SPAWN_CHERRYGROVE_CITY
	end

CherrygroveCity_PokemonCenter_EventScript_Nurse:: @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/CherrygroveCity_PokemonCenter_hns/scripts.inc)
CherrygroveCity_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
CherrygroveCity_PokemonCenter_EventScript_Lass:: @ LASS_HNS #3 (2,7)
CherrygroveCity_PokemonCenter_EventScript_Fisher:: @ FISHERMAN_HNS #4 (12,5)
CherrygroveCity_PokemonCenter_EventScript_Gentleman:: @ GENTLEMAN_HNS #5 (14,6)
CherrygroveCity_PokemonCenter_EventScript_WallClock:: @ sign (3,1)
CherrygroveCity_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
