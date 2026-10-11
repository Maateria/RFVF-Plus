.equ LOCALID_PETALBURG_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (PetalburgCity_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/PetalburgCity_PokemonCenter_1F/scripts.inc
PetalburgCity_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
PetalburgCity_PokemonCenter_1F_EventScript_FatMan:: @ NPC #3 (2,3)
PetalburgCity_PokemonCenter_1F_EventScript_Youngster:: @ NPC #4 (9,6)
PetalburgCity_PokemonCenter_1F_EventScript_Woman:: @ NPC #5 (5,4)
	end
