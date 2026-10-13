.equ LOCALID_LAVARIDGE_NURSE, 1

LavaridgeTown_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (LavaridgeTown_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/LavaridgeTown_PokemonCenter_1F/scripts.inc
LavaridgeTown_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
LavaridgeTown_PokemonCenter_1F_EventScript_Youngster:: @ NPC #2 (11,8)
LavaridgeTown_PokemonCenter_1F_EventScript_Woman:: @ NPC #3 (10,6)
LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman:: @ NPC #4 (1,3)
	end
