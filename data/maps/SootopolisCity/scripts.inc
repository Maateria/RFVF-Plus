.equ LOCALID_SOOTOPOLIS_EXPERT, 1
.equ LOCALID_KIRI, 2
.equ LOCALID_SOOTOPOLIS_NINJA_BOY, 3
.equ LOCALID_SOOTOPOLIS_BOY_1, 4
.equ LOCALID_SOOTOPOLIS_WOMAN_1, 6

SootopolisCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (SootopolisCity_OnLoad), ON_TRANSITION (SootopolisCity_OnTransition), ON_RESUME (SootopolisCity_OnResume), ON_FRAME_TABLE (SootopolisCity_OnFrame), ON_WARP_INTO_MAP_TABLE (SootopolisCity_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SootopolisCity/scripts.inc
SootopolisCity_EventScript_CaveOfOriginExpert:: @ NPC #1 (31,18)
SootopolisCity_EventScript_Kiri::               @ NPC #2 (9,43)
SootopolisCity_EventScript_NinjaBoy::           @ NPC #3 (51,14)
SootopolisCity_EventScript_Boy1::               @ NPC #4 (43,26)
SootopolisCity_EventScript_Man::                @ NPC #5 (26,4)
SootopolisCity_EventScript_Woman1::             @ NPC #6 (49,34)
SootopolisCity_EventScript_GymSign::            @ sign (33,34)
SootopolisCity_EventScript_CitySign::           @ sign (41,37)
	end
