.equ LOCALID_PYRAMID_TOP_ATTENDANT, 1
.equ LOCALID_BRANDON, 2

BattleFrontier_BattlePyramidTop_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (BattleFrontier_BattlePyramidTop_OnResume), ON_FRAME_TABLE (BattleFrontier_BattlePyramidTop_OnFrame), ON_TRANSITION (BattleFrontier_BattlePyramidTop_OnTransition), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattlePyramidTop_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattlePyramidTop/scripts.inc
BattleFrontier_BattlePyramidTop_EventScript_Attendant:: @ NPC #1 (17,11)
	end
@ hoenn_import: left out: trigger (17,9) VAR_TEMP_2==0 -> BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon
