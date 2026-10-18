@ johto_import: generated from PokemonHnS data/maps/GoldenrodCity_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

GoldenrodCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition:
	setrespawn SPAWN_GOLDENROD_CITY
	end

GoldenrodCity_PokemonCenter_EventScript_Nurse:: @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/GoldenrodCity_PokemonCenter_hns/scripts.inc)
GoldenrodCity_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (6,2)
GoldenrodCity_PokemonCenter_EventScript_Lass::  @ LASS_HNS #3 (15,9)
GoldenrodCity_PokemonCenter_EventScript_GbaKid1:: @ GAMEBOY_KID_HNS #4 (2,7)
GoldenrodCity_PokemonCenter_EventScript_Granny:: @ OLD_WOMAN_HNS #5 (5,8)
GoldenrodCity_PokemonCenter_EventScript_GbaKid2:: @ GAMEBOY_KID_HNS #6 (3,7)
GoldenrodCity_PokemonCenter_EventScript_LinkNpc:: @ LINK_RECEPTIONIST_HNS #7 (14,5)
GoldenrodCity_PokemonCenter_EventScript_LinkExplainerNpc:: @ LINK_RECEPTIONIST_HNS #9 (16,6)
GoldenrodCity_PokemonCenter_EventScript_WallClock:: @ sign (1,1)
GoldenrodCity_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (1,-1)
	end
