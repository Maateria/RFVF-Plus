.equ LOCALID_DEWFORD_HALL_EXPERT_M, 4
.equ LOCALID_DEWFORD_HALL_TWIN, 5
.equ LOCALID_DEWFORD_HALL_SCHOOL_KID_M, 7
.equ LOCALID_DEWFORD_HALL_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/DewfordTown_Hall/scripts.inc
DewfordTown_Hall_EventScript_Girl::             @ NPC #1 (4,6)
DewfordTown_Hall_EventScript_Woman::            @ NPC #2 (1,5)
DewfordTown_Hall_EventScript_Man::              @ NPC #3 (5,4)
DewfordTown_Hall_EventScript_ExpertM::          @ NPC #4 (9,3)
DewfordTown_Hall_EventScript_Twin::             @ NPC #5 (5,2)
DewfordTown_Hall_EventScript_LittleBoy::        @ NPC #6 (14,7)
DewfordTown_Hall_EventScript_SchoolKidM::       @ NPC #7 (12,3)
DewfordTown_Hall_EventScript_PsychicM::         @ NPC #8 (15,3)
DewfordTown_Hall_EventScript_SludgeBombMan::    @ NPC #9 (8,6)
DewfordTown_Hall_EventScript_Bookshelf::        @ sign (0,1)
DewfordTown_Hall_EventScript_Painting::         @ sign (7,1)
	end
