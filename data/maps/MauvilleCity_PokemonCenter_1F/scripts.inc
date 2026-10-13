.equ LOCALID_MAUVILLE_NURSE, 1

MauvilleCity_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MauvilleCity_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MauvilleCity_PokemonCenter_1F/scripts.inc
MauvilleCity_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan:: @ NPC #2 (2,3)
MauvilleCity_PokemonCenter_1F_EventScript_Woman1:: @ NPC #3 (8,6)
MauvilleCity_PokemonCenter_1F_EventScript_Woman2:: @ NPC #4 (11,4)
MauvilleCity_PokemonCenter_1F_EventScript_Youngster:: @ NPC #5 (2,8)
	end
