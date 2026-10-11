Route102_MapScripts::
	.byte 0
Route102_EventScript_ItemPotion::               @ item ball, works (FLAG_ITEM_ROUTE_102_POTION)
	finditem ITEM_POTION
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route102/scripts.inc
Route102_EventScript_LittleBoy::                @ NPC #1 (18,11)
Route102_EventScript_Calvin::                   @ trainer #2 (33,14) TRAINER_CALVIN_1, Emerald NORMAL sight 3
Route102_EventScript_Rick::                     @ trainer #3 (25,15) TRAINER_RICK, Emerald NORMAL sight 2
Route102_EventScript_Tiana::                    @ trainer #4 (8,7) TRAINER_TIANA, Emerald NORMAL sight 3
Route102_EventScript_Boy::                      @ NPC #5 (37,4)
Route102_EventScript_Allen::                    @ trainer #7 (19,4) TRAINER_ALLEN, Emerald NORMAL sight 3
Route102_EventScript_RouteSignPetalburg::       @ sign (17,2)
Route102_EventScript_RouteSignOldale::          @ sign (40,9)
	end
