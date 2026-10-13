GraniteCave_1F_MapScripts::
	.byte 0
GraniteCave_1F_EventScript_ItemEscapeRope::     @ item ball, works (FLAG_ITEM_GRANITE_CAVE_1F_ESCAPE_ROPE)
	finditem ITEM_ESCAPE_ROPE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/GraniteCave_1F/scripts.inc
GraniteCave_1F_EventScript_Hiker::              @ NPC #1 (36,9)
	end
