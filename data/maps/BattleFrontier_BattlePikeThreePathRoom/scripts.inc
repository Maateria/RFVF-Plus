.equ LOCALID_PIKE_HINT_GIVER, 2

BattleFrontier_BattlePikeThreePathRoom_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (BattleFrontier_BattlePikeRoom_OnResume), ON_FRAME_TABLE (BattleFrontier_BattlePikeThreePathRoom_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattlePikeThreePathRoom_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattlePikeThreePathRoom/scripts.inc
BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant:: @ NPC #1 (4,10)
BattleFrontier_BattlePikeThreePathRoom_EventScript_HintGiver:: @ NPC #2 (8,5)
	end
@ hoenn_import: left out: trigger (2,3) VAR_TEMP_1==0 -> BattleFrontier_BattlePikeThreePathRoom_EventScript_LeftRoomWarp; trigger (6,3) VAR_TEMP_1==0 -> BattleFrontier_BattlePikeThreePathRoom_EventScript_CenterRoomWarp; trigger (10,3) VAR_TEMP_1==0 -> BattleFrontier_BattlePikeThreePathRoom_EventScript_RightRoomWarp; trigger (5,10) VAR_TEMP_3==1 -> BattleFrontier_BattlePikeThreePathRoom_EventScript_NoTurningBack; trigger (6,10) VAR_TEMP_3==1 -> BattleFrontier_BattlePikeThreePathRoom_EventScript_NoTurningBack; trigger (6,9) VAR_TEMP_2==0 -> BattleFrontier_BattlePikeThreePathRoom_EventScript_SetEnteredRoom; trigger (5,9) VAR_TEMP_2==0 -> BattleFrontier_BattlePikeThreePathRoom_EventScript_SetEnteredRoom; trigger (7,9) VAR_TEMP_2==0 -> BattleFrontier_BattlePikeThreePathRoom_EventScript_SetEnteredRoom; trigger (7,10) VAR_TEMP_3==1 -> BattleFrontier_BattlePikeThreePathRoom_EventScript_NoTurningBack
