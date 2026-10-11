.equ LOCALID_OLDALE_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (OldaleTown_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/OldaleTown_PokemonCenter_1F/scripts.inc
OldaleTown_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
OldaleTown_PokemonCenter_1F_EventScript_Gentleman:: @ NPC #2 (4,4)
OldaleTown_PokemonCenter_1F_EventScript_Boy::   @ NPC #3 (10,6)
OldaleTown_PokemonCenter_1F_EventScript_Girl::  @ NPC #4 (3,7)
	end
