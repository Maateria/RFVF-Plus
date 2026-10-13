.equ LOCALID_SOOTOPOLIS_NURSE, 1

SootopolisCity_PokemonCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (SootopolisCity_PokemonCenter_1F_OnTransition), ON_RESUME (CableClub_OnResume)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SootopolisCity_PokemonCenter_1F/scripts.inc
SootopolisCity_PokemonCenter_1F_EventScript_Nurse:: @ NPC #1 (7,2)
SootopolisCity_PokemonCenter_1F_EventScript_Gentleman:: @ NPC #2 (12,4)
SootopolisCity_PokemonCenter_1F_EventScript_Woman:: @ NPC #3 (4,7)
SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor:: @ NPC #4 (2,3)
	end
