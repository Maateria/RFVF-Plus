.equ LOCALID_VERDANTURF_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (VerdanturfTown_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/VerdanturfTown_PokemonCenter_1F/scripts.inc
VerdanturfTown_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman:: @ NPC #2 (4,5)
VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM:: @ NPC #3 (12,2)
VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor:: @ NPC #4 (10,6)
	end
