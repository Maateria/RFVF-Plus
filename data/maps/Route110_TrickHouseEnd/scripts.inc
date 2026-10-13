.equ LOCALID_TRICK_MASTER_END, 1

Route110_TrickHouseEnd_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (Route110_TrickHouseEnd_OnResume), ON_TRANSITION (Route110_TrickHouseEnd_OnTransition), ON_FRAME_TABLE (Route110_TrickHouseEnd_OnFrame), ON_WARP_INTO_MAP_TABLE (Route110_TrickHouseEnd_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHouseEnd/scripts.inc
Route110_TrickHouseEnd_EventScript_TrickMaster:: @ NPC #1 (4,5)
	end
@ hoenn_import: left out: trigger (2,2) VAR_TEMP_2==0 -> Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger
