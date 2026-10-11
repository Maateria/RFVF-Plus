.equ LOCALID_FALLARBOR_NURSE, 1

FallarborTown_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (FallarborTown_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/FallarborTown_PokemonCenter_1F/scripts.inc
FallarborTown_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
FallarborTown_PokemonCenter_1F_EventScript_Girl:: @ NPC #2 (10,6)
FallarborTown_PokemonCenter_1F_EventScript_ExpertM:: @ NPC #3 (2,3)
	end
