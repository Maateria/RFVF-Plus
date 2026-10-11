.equ LOCALID_BIRCHS_LAB_AIDE, 1
.equ LOCALID_BIRCHS_LAB_BIRCH, 2
.equ LOCALID_BIRCHS_LAB_RIVAL, 3

LittlerootTown_ProfessorBirchsLab_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (LittlerootTown_ProfessorBirchsLab_OnTransition), ON_WARP_INTO_MAP_TABLE (LittlerootTown_ProfessorBirchsLab_OnWarp), ON_FRAME_TABLE (LittlerootTown_ProfessorBirchsLab_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/LittlerootTown_ProfessorBirchsLab/scripts.inc
LittlerootTown_ProfessorBirchsLab_EventScript_Aide:: @ NPC #1 (9,8)
LittlerootTown_ProfessorBirchsLab_EventScript_Birch:: @ NPC #2 (6,4)
LittlerootTown_ProfessorBirchsLab_EventScript_Rival:: @ NPC #3 (7,4)
LittlerootTown_ProfessorBirchsLab_EventScript_Machine:: @ sign (10,7)
LittlerootTown_ProfessorBirchsLab_EventScript_Book:: @ sign (7,1)
LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf:: @ sign (1,1)
LittlerootTown_ProfessorBirchsLab_EventScript_PC:: @ sign (4,1)
	end
