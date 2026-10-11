.equ LOCALID_OLDALE_MART_EMPLOYEE, 2
.equ LOCALID_FOOTPRINTS_MAN, 3

OldaleTown_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (OldaleTown_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/OldaleTown/scripts.inc
OldaleTown_EventScript_Girl::                   @ NPC #1 (16,11)
OldaleTown_EventScript_MartEmployee::           @ NPC #2 (13,7)
OldaleTown_EventScript_FootprintsMan::          @ NPC #3 (8,9)
OldaleTown_EventScript_TownSign::               @ sign (11,9)
	end
@ hoenn_import: left out: trigger (0,10) VAR_OLDALE_TOWN_STATE==0 -> OldaleTown_EventScript_BlockedPath; trigger (8,19) VAR_OLDALE_RIVAL_STATE==1 -> OldaleTown_EventScript_RivalTrigger1; trigger (9,19) VAR_OLDALE_RIVAL_STATE==1 -> OldaleTown_EventScript_RivalTrigger2; trigger (10,19) VAR_OLDALE_RIVAL_STATE==1 -> OldaleTown_EventScript_RivalTrigger3
