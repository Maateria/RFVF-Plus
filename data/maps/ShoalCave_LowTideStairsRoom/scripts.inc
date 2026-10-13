ShoalCave_LowTideStairsRoom_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (ShoalCave_LowTideStairsRoom_OnLoad)
ShoalCave_LowTideStairsRoom_EventScript_ItemIceHeal:: @ item ball, works (FLAG_ITEM_SHOAL_CAVE_STAIRS_ROOM_ICE_HEAL)
	finditem ITEM_ICE_HEAL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/ShoalCave_LowTideStairsRoom/scripts.inc
ShoalCave_LowTideStairsRoom_EventScript_ShoalSalt3:: @ sign (11,11)
	end
