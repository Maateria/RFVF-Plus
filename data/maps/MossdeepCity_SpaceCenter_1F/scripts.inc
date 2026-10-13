.equ LOCALID_SPACE_CENTER_1F_SCIENTIST_1, 1
.equ LOCALID_SPACE_CENTER_1F_SCIENTIST_2, 2
.equ LOCALID_SPACE_CENTER_1F_SAILOR, 3
.equ LOCALID_SPACE_CENTER_1F_OLD_MAN, 4
.equ LOCALID_SPACE_CENTER_1F_WOMAN, 5

MossdeepCity_SpaceCenter_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (MossdeepCity_SpaceCenter_1F_OnLoad), ON_TRANSITION (MossdeepCity_SpaceCenter_1F_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MossdeepCity_SpaceCenter_1F/scripts.inc
MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter:: @ NPC #1 (7,2)
MossdeepCity_SpaceCenter_1F_EventScript_Scientist:: @ NPC #2 (2,2)
MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan:: @ NPC #3 (6,6)
MossdeepCity_SpaceCenter_1F_EventScript_OldMan:: @ NPC #4 (10,2)
MossdeepCity_SpaceCenter_1F_EventScript_Woman:: @ NPC #5 (14,7)
	end
