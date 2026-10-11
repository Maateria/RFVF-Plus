.equ LOCALID_DEWFORD_NURSE, 1

DewfordTown_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (DewfordTown_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/DewfordTown_PokemonCenter_1F/scripts.inc
DewfordTown_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
DewfordTown_PokemonCenter_1F_EventScript_PokefanF:: @ NPC #2 (10,6)
DewfordTown_PokemonCenter_1F_EventScript_Man::  @ NPC #3 (5,5)
	end
