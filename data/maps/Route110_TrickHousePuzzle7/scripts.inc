Route110_TrickHousePuzzle7_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (Route110_TrickHousePuzzle7_OnResume), ON_TRANSITION (Route110_TrickHousePuzzle7_OnTransition), ON_LOAD (Route110_TrickHousePuzzle7_OnLoad), ON_FRAME_TABLE (Route110_TrickHousePuzzle7_OnFrame)
Route110_TrickHousePuzzle7_EventScript_ItemTropicMail:: @ item ball, works (FLAG_ITEM_TRICK_HOUSE_PUZZLE_7_TROPIC_MAIL)
	finditem ITEM_TROPIC_MAIL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHousePuzzle7/scripts.inc
Route110_TrickHousePuzzle7_EventScript_Joshua:: @ trainer #1 (9,20) TRAINER_JOSHUA, Emerald NORMAL sight 1
Route110_TrickHousePuzzle7_EventScript_Alexis:: @ trainer #2 (10,2) TRAINER_ALEXIS, Emerald NORMAL sight 1
Route110_TrickHousePuzzle7_EventScript_Patricia:: @ trainer #3 (8,17) TRAINER_PATRICIA, Emerald NORMAL sight 1
Route110_TrickHousePuzzle7_EventScript_Alvaro:: @ trainer #5 (9,2) TRAINER_ALVARO, Emerald NORMAL sight 1
Route110_TrickHousePuzzle7_EventScript_Mariela:: @ trainer #6 (8,13) TRAINER_MARIELA, Emerald NORMAL sight 1
Route110_TrickHousePuzzle7_EventScript_Everett:: @ trainer #7 (9,12) TRAINER_EVERETT, Emerald NORMAL sight 1
Route110_TrickHousePuzzle7_EventScript_Scroll:: @ sign (6,17)
	end
@ hoenn_import: left out: trigger (8,19) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle7_EventScript_YellowButton; trigger (0,14) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle7_EventScript_BlueButton; trigger (6,6) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle7_EventScript_GreenButton; trigger (9,7) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle7_EventScript_PurpleButton
