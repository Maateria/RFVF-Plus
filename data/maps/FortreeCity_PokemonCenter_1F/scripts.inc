.equ LOCALID_FORTREE_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (FortreeCity_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/FortreeCity_PokemonCenter_1F/scripts.inc
FortreeCity_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
FortreeCity_PokemonCenter_1F_EventScript_Gentleman:: @ NPC #2 (4,7)
FortreeCity_PokemonCenter_1F_EventScript_Man::  @ NPC #3 (8,5)
FortreeCity_PokemonCenter_1F_EventScript_Boy::  @ NPC #4 (2,3)
	end
