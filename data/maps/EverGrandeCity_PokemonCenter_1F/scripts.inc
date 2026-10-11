.equ LOCALID_EVER_GRANDE_NURSE, 1

EverGrandeCity_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (EverGrandeCity_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/EverGrandeCity_PokemonCenter_1F/scripts.inc
EverGrandeCity_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
EverGrandeCity_PokemonCenter_1F_EventScript_Woman:: @ NPC #2 (5,5)
EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM:: @ NPC #3 (10,7)
	end
