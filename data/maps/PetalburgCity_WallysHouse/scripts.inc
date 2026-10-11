.equ LOCALID_WALLYS_HOUSE_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (PetalburgCity_WallysHouse_OnFrame), ON_WARP_INTO_MAP_TABLE (PetalburgCity_WallysHouse_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/PetalburgCity_WallysHouse/scripts.inc
PetalburgCity_WallysHouse_EventScript_WallysDad:: @ NPC #1 (3,4)
PetalburgCity_WallysHouse_EventScript_WallysMom:: @ NPC #2 (7,5)
	end
