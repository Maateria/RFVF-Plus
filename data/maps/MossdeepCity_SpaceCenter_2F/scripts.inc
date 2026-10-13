.equ LOCALID_SPACE_CENTER_2F_RICH_BOY, 1
.equ LOCALID_SPACE_CENTER_2F_GENTLEMAN, 2
.equ LOCALID_SPACE_CENTER_2F_SCIENTIST, 3

MossdeepCity_SpaceCenter_2F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MossdeepCity_SpaceCenter_2F_OnTransition), ON_FRAME_TABLE (MossdeepCity_SpaceCenter_2F_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MossdeepCity_SpaceCenter_2F/scripts.inc
MossdeepCity_SpaceCenter_2F_EventScript_RichBoy:: @ NPC #1 (6,2)
MossdeepCity_SpaceCenter_2F_EventScript_Gentleman:: @ NPC #2 (11,8)
MossdeepCity_SpaceCenter_2F_EventScript_Scientist:: @ NPC #3 (5,6)
	end
