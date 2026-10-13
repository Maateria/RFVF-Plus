Route110_TrickHousePuzzle2_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (Route110_TrickHousePuzzle2_OnResume), ON_TRANSITION (Route110_TrickHousePuzzle2_OnTransition)
Route110_TrickHousePuzzle2_EventScript_ItemWaveMail:: @ item ball, works (FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_WAVE_MAIL)
	finditem ITEM_WAVE_MAIL
	end
Route110_TrickHousePuzzle2_EventScript_ItemHarborMail:: @ item ball, works (FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_HARBOR_MAIL)
	finditem ITEM_HARBOR_MAIL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHousePuzzle2/scripts.inc
Route110_TrickHousePuzzle2_EventScript_Ted::    @ trainer #1 (13,10) TRAINER_TED, Emerald NORMAL sight 1
Route110_TrickHousePuzzle2_EventScript_Paul::   @ trainer #2 (10,17) TRAINER_PAUL, Emerald NORMAL sight 4
Route110_TrickHousePuzzle2_EventScript_Georgia:: @ trainer #3 (11,9) TRAINER_GEORGIA, Emerald NORMAL sight 2
Route110_TrickHousePuzzle2_EventScript_Scroll:: @ sign (14,14)
	end
@ hoenn_import: left out: trigger (11,12) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle2_EventScript_Button1; trigger (0,4) VAR_TEMP_2==0 -> Route110_TrickHousePuzzle2_EventScript_Button2; trigger (14,5) VAR_TEMP_3==0 -> Route110_TrickHousePuzzle2_EventScript_Button3; trigger (7,11) VAR_TEMP_4==0 -> Route110_TrickHousePuzzle2_EventScript_Button4
