ShoalCave_LowTideInnerRoom_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (ShoalCave_LowTideInnerRoom_OnLoad), ON_TRANSITION (ShoalCave_LowTideInnerRoom_OnTransition)
ShoalCave_LowTideInnerRoom_EventScript_ItemRareCandy:: @ item ball, works (FLAG_ITEM_SHOAL_CAVE_INNER_ROOM_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/ShoalCave_LowTideInnerRoom/scripts.inc
ShoalCave_LowTideInnerRoom_EventScript_ShoalSalt1:: @ sign (31,8)
ShoalCave_LowTideInnerRoom_EventScript_ShoalSalt2:: @ sign (14,26)
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell1:: @ sign (41,20)
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell2:: @ sign (41,10)
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell3:: @ sign (6,9)
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell4:: @ sign (16,13)
	end
