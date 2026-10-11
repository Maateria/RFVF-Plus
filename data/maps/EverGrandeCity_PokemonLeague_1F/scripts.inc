.equ LOCALID_LEAGUE_NURSE, 1
.equ LOCALID_LEAGUE_GUARD_1, 3
.equ LOCALID_LEAGUE_GUARD_2, 4

EverGrandeCity_PokemonLeague_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (EverGrandeCity_PokemonLeague_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/EverGrandeCity_PokemonLeague_1F/scripts.inc
EverGrandeCity_PokemonLeague_1F_EventScript_Nurse:: @ NPC #1 (3,2)
EverGrandeCity_PokemonLeague_1F_EventScript_Clerk:: @ NPC #2 (16,2)
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard:: @ NPC #3 (8,2)
	end
