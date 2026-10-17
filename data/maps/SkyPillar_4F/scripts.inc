SkyPillar_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EventScript_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, EventScript_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_4F_SetHoleWarp
	.byte 0
@ Emerald's cracked floor (the Sky Pillar keeps its cracked floors: no VAR_SKY_PILLAR_STATE clean layout)

SkyPillar_4F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_3F
	end

