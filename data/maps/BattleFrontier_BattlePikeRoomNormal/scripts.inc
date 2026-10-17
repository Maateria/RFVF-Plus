.equ LOCALID_PIKE_ROOM_NPC_1, 1
.equ LOCALID_PIKE_ROOM_NPC_2, 2

BattleFrontier_BattlePikeRoomNormal_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (BattleFrontier_BattlePikeRoom_OnResume), ON_TRANSITION (BattleFrontier_BattlePikeRoom_OnTransition), ON_FRAME_TABLE (BattleFrontier_BattlePikeRoomNormal_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattlePikeRoom_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.inc
BattleFrontier_BattlePikeRoomNormal_EventScript_NPC:: @ NPC #1 (4,4)
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon:: @ NPC #2 (3,4)
	end
@ hoenn_import: left out: trigger (4,3) VAR_TEMP_1==0 -> BattleFrontier_BattlePikeRoomNormal_EventScript_Exit; trigger (3,6) VAR_TEMP_2==0 -> BattleFrontier_BattlePikeRoomNormal_EventScript_SetEnteredRoom; trigger (3,7) VAR_TEMP_3==1 -> BattleFrontier_BattlePikeRoomNormal_EventScript_NoTurningBack; trigger (4,6) VAR_TEMP_2==0 -> BattleFrontier_BattlePikeRoomNormal_EventScript_SetEnteredRoom; trigger (5,6) VAR_TEMP_2==0 -> BattleFrontier_BattlePikeRoomNormal_EventScript_SetEnteredRoom; trigger (4,7) VAR_TEMP_3==1 -> BattleFrontier_BattlePikeRoomNormal_EventScript_NoTurningBack; trigger (5,7) VAR_TEMP_3==1 -> BattleFrontier_BattlePikeRoomNormal_EventScript_NoTurningBack
