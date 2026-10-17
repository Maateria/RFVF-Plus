MirageTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EventScript_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, EventScript_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_3F_SetHoleWarp
	.byte 0
@ Emerald's cracked floor

MirageTower_3F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MIRAGE_TOWER_2F
	end

