GraniteCave_B1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (CaveHole_CheckFallDownHole), ON_TRANSITION (CaveHole_FixCrackedGround), ON_RESUME (GraniteCave_B1F_SetHoleWarp)
GraniteCave_B1F_EventScript_ItemPokeBall::      @ item ball, works (FLAG_ITEM_GRANITE_CAVE_B1F_POKE_BALL)
	finditem ITEM_POKE_BALL
	end
