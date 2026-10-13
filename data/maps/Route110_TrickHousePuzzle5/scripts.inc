.equ LOCALID_MECHADOLL_1, 1
.equ LOCALID_MECHADOLL_2, 2
.equ LOCALID_MECHADOLL_3, 3
.equ LOCALID_MECHADOLL_4, 4
.equ LOCALID_MECHADOLL_5, 5

Route110_TrickHousePuzzle5_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route110_TrickHousePuzzle5_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHousePuzzle5/scripts.inc
Route110_TrickHousePuzzle5_EventScript_Mechadoll1:: @ NPC #1 (6,17)
Route110_TrickHousePuzzle5_EventScript_Mechadoll2:: @ NPC #2 (0,7)
Route110_TrickHousePuzzle5_EventScript_Mechadoll3:: @ NPC #3 (14,10)
Route110_TrickHousePuzzle5_EventScript_Mechadoll4:: @ NPC #4 (14,19)
Route110_TrickHousePuzzle5_EventScript_Mechadoll5:: @ NPC #5 (10,4)
Route110_TrickHousePuzzle5_EventScript_Scroll:: @ sign (11,21)
	end
@ hoenn_import: left out: trigger (5,17) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger0; trigger (4,17) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger1; trigger (3,17) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger2; trigger (2,17) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger3; trigger (1,7) VAR_TEMP_2==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger0; trigger (2,7) VAR_TEMP_2==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger1; trigger (13,10) VAR_TEMP_3==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger0; trigger (12,10) VAR_TEMP_3==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger1; trigger (11,10) VAR_TEMP_3==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger2; trigger (13,19) VAR_TEMP_4==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger0; trigger (12,19) VAR_TEMP_4==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger1; trigger (11,4) VAR_TEMP_5==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll5Trigger0; trigger (1,17) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll1Trigger4; trigger (3,7) VAR_TEMP_2==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger2; trigger (4,7) VAR_TEMP_2==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger3; trigger (5,7) VAR_TEMP_2==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger4; trigger (6,7) VAR_TEMP_2==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll2Trigger5; trigger (10,10) VAR_TEMP_3==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger3; trigger (9,10) VAR_TEMP_3==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll3Trigger4; trigger (11,19) VAR_TEMP_4==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger2; trigger (10,19) VAR_TEMP_4==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger3; trigger (9,19) VAR_TEMP_4==0 -> Route110_TrickHousePuzzle5_EventScript_Mechadoll4Trigger4
