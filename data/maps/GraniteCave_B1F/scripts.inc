GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EventScript_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, EventScript_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0
@ Emerald's cracked floor

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

GraniteCave_B1F_EventScript_ItemPokeBall::      @ item ball, works (FLAG_ITEM_GRANITE_CAVE_B1F_POKE_BALL)
	finditem ITEM_POKE_BALL
	end
