.equ LOCALID_WINSTRATE_HOUSE_VIVI, 1
.equ LOCALID_WINSTRATE_HOUSE_VICTOR, 2
.equ LOCALID_WINSTRATE_HOUSE_VICTORIA, 3
.equ LOCALID_WINSTRATE_HOUSE_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route111_WinstrateFamilysHouse/scripts.inc
Route111_WinstrateFamilysHouse_EventScript_Vivi:: @ NPC #1 (7,5)
Route111_WinstrateFamilysHouse_EventScript_Victor:: @ NPC #2 (4,5)
Route111_WinstrateFamilysHouse_EventScript_Victoria:: @ NPC #3 (7,4)
Route111_WinstrateFamilysHouse_EventScript_Vicky:: @ NPC #4 (4,4)
	end
