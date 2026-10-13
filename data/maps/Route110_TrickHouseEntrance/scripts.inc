Route110_TrickHouseEntrance_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route110_TrickHouseEntrance_OnTransition), ON_FRAME_TABLE (Route110_TrickHouseEntrance_OnFrame), ON_WARP_INTO_MAP_TABLE (Route110_TrickHouseEntrance_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHouseEntrance/scripts.inc
Route110_TrickHouseEntrance_EventScript_Door::  @ sign (5,1)
	end
@ hoenn_import: left out: trigger (4,7) VAR_TRICK_HOUSE_BEING_WATCHED_STATE==0 -> Route110_TrickHouseEntrance_EventScript_TrickMasterHiding; trigger (5,6) VAR_TRICK_HOUSE_BEING_WATCHED_STATE==0 -> Route110_TrickHouseEntrance_EventScript_TrickMasterHiding; trigger (6,6) VAR_TRICK_HOUSE_BEING_WATCHED_STATE==0 -> Route110_TrickHouseEntrance_EventScript_TrickMasterHiding; trigger (7,7) VAR_TRICK_HOUSE_BEING_WATCHED_STATE==0 -> Route110_TrickHouseEntrance_EventScript_TrickMasterHiding
