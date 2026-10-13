Route110_TrickHousePuzzle1_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (Route110_TrickHousePuzzle1_OnLoad)
Route110_TrickHousePuzzle1_EventScript_ItemOrangeMail:: @ item ball, works (FLAG_ITEM_TRICK_HOUSE_PUZZLE_1_ORANGE_MAIL)
	finditem ITEM_ORANGE_MAIL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHousePuzzle1/scripts.inc
Route110_TrickHousePuzzle1_EventScript_Sally::  @ trainer #1 (14,20) TRAINER_SALLY, Emerald NORMAL sight 6
Route110_TrickHousePuzzle1_EventScript_Eddie::  @ trainer #2 (14,8) TRAINER_EDDIE, Emerald NORMAL sight 2
Route110_TrickHousePuzzle1_EventScript_Robin::  @ trainer #3 (2,15) TRAINER_ROBIN, Emerald NORMAL sight 2
Route110_TrickHousePuzzle1_EventScript_Scroll:: @ sign (3,16)
	end
