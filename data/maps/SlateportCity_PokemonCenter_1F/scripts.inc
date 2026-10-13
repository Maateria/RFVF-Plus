.equ LOCALID_SLATEPORT_NURSE, 1

SlateportCity_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (SlateportCity_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SlateportCity_PokemonCenter_1F/scripts.inc
SlateportCity_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
SlateportCity_PokemonCenter_1F_EventScript_Sailor:: @ NPC #2 (2,3)
SlateportCity_PokemonCenter_1F_EventScript_Woman:: @ NPC #3 (10,7)
	end
