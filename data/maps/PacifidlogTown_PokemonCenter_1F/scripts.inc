.equ LOCALID_PACIFIDLOG_NURSE, 1

PacifidlogTown_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (PacifidlogTown_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/PacifidlogTown_PokemonCenter_1F/scripts.inc
PacifidlogTown_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
PacifidlogTown_PokemonCenter_1F_EventScript_OldMan:: @ NPC #2 (10,6)
PacifidlogTown_PokemonCenter_1F_EventScript_Girl:: @ NPC #3 (2,2)
PacifidlogTown_PokemonCenter_1F_EventScript_Woman:: @ NPC #4 (4,5)
PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor:: @ NPC #5 (12,8)
	end
