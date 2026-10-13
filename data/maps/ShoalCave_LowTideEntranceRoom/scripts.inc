ShoalCave_LowTideEntranceRoom_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (ShoalCave_LowTideEntranceRoom_OnTransition)
ShoalCave_LowTideEntranceRoom_EventScript_ItemBigPearl:: @ item ball, works (FLAG_ITEM_SHOAL_CAVE_ENTRANCE_BIG_PEARL)
	finditem ITEM_BIG_PEARL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/ShoalCave_LowTideEntranceRoom/scripts.inc
ShoalCave_LowTideEntranceRoom_EventScript_ShellBellExpert:: @ NPC #2 (18,15)
	end
