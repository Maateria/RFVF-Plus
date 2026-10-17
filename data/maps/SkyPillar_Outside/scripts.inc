SkyPillar_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_OnLoad
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (SkyPillar_Outside_OnTransition), ON_FRAME_TABLE (SkyPillar_Outside_OnFrame)

@ Emerald opens the door once Wallace has gone up (FLAG_WALLACE_GOES_TO_SKY_PILLAR): Hoenn is post-League here
SkyPillar_Outside_OnLoad:
	setmetatile 14, 4, METATILE_HoennPacifidlog_SkyPillar_DoorOpen_Top, FALSE
	setmetatile 14, 5, METATILE_HoennPacifidlog_SkyPillar_DoorOpen_Bottom, FALSE
	end

