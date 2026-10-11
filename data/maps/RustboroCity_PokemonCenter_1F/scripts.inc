.equ LOCALID_RUSTBORO_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (RustboroCity_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/RustboroCity_PokemonCenter_1F/scripts.inc
RustboroCity_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
RustboroCity_PokemonCenter_1F_EventScript_Man:: @ NPC #2 (11,2)
RustboroCity_PokemonCenter_1F_EventScript_Boy:: @ NPC #3 (3,4)
RustboroCity_PokemonCenter_1F_EventScript_Girl:: @ NPC #4 (10,6)
	end
