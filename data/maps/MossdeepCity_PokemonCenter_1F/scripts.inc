.equ LOCALID_MOSSDEEP_NURSE, 1

MossdeepCity_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MossdeepCity_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MossdeepCity_PokemonCenter_1F/scripts.inc
MossdeepCity_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
MossdeepCity_PokemonCenter_1F_EventScript_Woman:: @ NPC #2 (8,4)
MossdeepCity_PokemonCenter_1F_EventScript_Girl:: @ NPC #3 (3,5)
	end
