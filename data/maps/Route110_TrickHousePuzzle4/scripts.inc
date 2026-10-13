Route110_TrickHousePuzzle4_MapScripts::
	.byte 0
Route110_TrickHousePuzzle4_EventScript_ItemMechMail:: @ item ball, works (FLAG_ITEM_TRICK_HOUSE_PUZZLE_4_MECH_MAIL)
	finditem ITEM_MECH_MAIL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHousePuzzle4/scripts.inc
Route110_TrickHousePuzzle4_EventScript_Cora::   @ trainer #1 (2,2) TRAINER_CORA, Emerald NORMAL sight 1
Route110_TrickHousePuzzle4_EventScript_Paula::  @ trainer #2 (14,7) TRAINER_PAULA, Emerald NORMAL sight 2
Route110_TrickHousePuzzle4_EventScript_Yuji::   @ trainer #3 (2,14) TRAINER_YUJI, Emerald NORMAL sight 2
Route110_TrickHousePuzzle4_EventScript_Scroll:: @ sign (14,13)
	end
