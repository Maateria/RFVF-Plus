Route110_TrickHousePuzzle6_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route110_TrickHousePuzzle6_OnTransition), ON_WARP_INTO_MAP_TABLE (Route110_TrickHousePuzzle6_OnWarp)
Route110_TrickHousePuzzle6_EventScript_ItemGlitterMail:: @ item ball, works (FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL)
	finditem ITEM_GLITTER_MAIL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_TrickHousePuzzle6/scripts.inc
Route110_TrickHousePuzzle6_EventScript_Sophia:: @ trainer #1 (7,9) TRAINER_SOPHIA, Emerald NORMAL sight 1
Route110_TrickHousePuzzle6_EventScript_Benny::  @ trainer #2 (11,10) TRAINER_BENNY, Emerald NORMAL sight 3
Route110_TrickHousePuzzle6_EventScript_Sebastian:: @ trainer #3 (4,5) TRAINER_SEBASTIAN, Emerald NORMAL sight 1
Route110_TrickHousePuzzle6_EventScript_Scroll:: @ sign (0,10)
	end
