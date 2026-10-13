Route110_TrickHousePuzzle3_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (Route110_TrickHousePuzzle3_OnResume), ON_TRANSITION (Route110_TrickHousePuzzle3_OnTransition)
Route110_TrickHousePuzzle3_EventScript_ItemWoodMail:: @ item ball, works (FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_WOOD_MAIL)
	finditem ITEM_WOOD_MAIL
	end
Route110_TrickHousePuzzle3_EventScript_ItemShadowMail:: @ item ball, works (FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_SHADOW_MAIL)
	finditem ITEM_SHADOW_MAIL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHousePuzzle3/scripts.inc
Route110_TrickHousePuzzle3_EventScript_Justin:: @ trainer #1 (7,19) TRAINER_JUSTIN, Emerald NORMAL sight 2
Route110_TrickHousePuzzle3_EventScript_Martha:: @ trainer #2 (4,4) TRAINER_MARTHA, Emerald NORMAL sight 1
Route110_TrickHousePuzzle3_EventScript_Alan::   @ trainer #3 (10,10) TRAINER_ALAN, Emerald NORMAL sight 1
Route110_TrickHousePuzzle3_EventScript_Scroll:: @ sign (0,14)
	end
@ hoenn_import: left out: trigger (4,14) VAR_TEMP_1==0 -> Route110_TrickHousePuzzle3_EventScript_Button1; trigger (3,11) VAR_TEMP_2==0 -> Route110_TrickHousePuzzle3_EventScript_Button2; trigger (12,5) VAR_TEMP_3==0 -> Route110_TrickHousePuzzle3_EventScript_Button3; trigger (8,2) VAR_TEMP_4==0 -> Route110_TrickHousePuzzle3_EventScript_Button4
