Route110_TrickHousePuzzle8_MapScripts::
	.byte 0
Route110_TrickHousePuzzle8_EventScript_ItemBeadMail:: @ item ball, works (FLAG_ITEM_TRICK_HOUSE_PUZZLE_8_BEAD_MAIL)
	finditem ITEM_BEAD_MAIL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHousePuzzle8/scripts.inc
Route110_TrickHousePuzzle8_EventScript_Vincent:: @ trainer #1 (1,10) TRAINER_VINCENT, Emerald NORMAL sight 1
Route110_TrickHousePuzzle8_EventScript_Leroy::  @ trainer #2 (4,2) TRAINER_LEROY, Emerald NORMAL sight 1
Route110_TrickHousePuzzle8_EventScript_Keira::  @ trainer #3 (8,17) TRAINER_KEIRA, Emerald NORMAL sight 1
Route110_TrickHousePuzzle8_EventScript_Scroll:: @ sign (3,21)
	end
