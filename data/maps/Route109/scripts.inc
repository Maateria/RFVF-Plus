Route109_MapScripts::
	.byte 0
Route109_EventScript_ItemPPUp::                 @ item ball, works (FLAG_ITEM_ROUTE_109_PP_UP)
	finditem ITEM_PP_UP
	end
Route109_EventScript_ItemPotion::               @ item ball, works (FLAG_ITEM_ROUTE_109_POTION)
	finditem ITEM_POTION
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route109/scripts.inc
Route109_EventScript_David::                    @ trainer #1 (12,36) TRAINER_DAVID, Emerald NORMAL sight 5
Route109_EventScript_Alice::                    @ trainer #2 (25,39) TRAINER_ALICE, Emerald NORMAL sight 5
Route109_EventScript_Huey::                     @ trainer #3 (15,17) TRAINER_HUEY, Emerald NORMAL sight 1
Route109_EventScript_Edmond::                   @ trainer #4 (24,13) TRAINER_EDMOND, Emerald NORMAL sight 6
Route109_EventScript_Ricky::                    @ trainer #5 (19,10) TRAINER_RICKY_1, Emerald NORMAL sight 3
Route109_EventScript_Lola::                     @ trainer #6 (22,7) TRAINER_LOLA_1, Emerald NORMAL sight 4
Route109_EventScript_SeashoreHouseGirl::        @ NPC #7 (11,6)
Route109_EventScript_Gwen::                     @ trainer #9 (29,32) TRAINER_GWEN, Emerald NORMAL sight 3
Route109_EventScript_Austina::                  @ trainer #10 (28,31) TRAINER_AUSTINA, Emerald NORMAL sight 3
Route109_EventScript_Carter::                   @ trainer #11 (21,56) TRAINER_CARTER, Emerald NORMAL sight 3
Route109_EventScript_SandCastleBoy::            @ NPC #12 (24,18)
Route109_EventScript_SoftSandGirl::             @ NPC #13 (25,18)
Route109_EventScript_Woman::                    @ NPC #14 (30,32)
Route109_EventScript_Mel::                      @ trainer #15 (8,41) TRAINER_MEL_AND_PAUL, Emerald NORMAL sight 1
Route109_EventScript_Paul::                     @ trainer #16 (9,41) TRAINER_MEL_AND_PAUL, Emerald NORMAL sight 1
Route109_EventScript_OldMan::                   @ NPC #17 (33,6)
Route109_EventScript_Zigzagoon::                @ NPC #18 (32,6)
Route109_EventScript_Hailey::                   @ trainer #19 (17,13) TRAINER_HAILEY, Emerald NORMAL sight 6
Route109_EventScript_Chandler::                 @ trainer #20 (27,7) TRAINER_CHANDLER, Emerald NORMAL sight 4
Route109_EventScript_Elijah::                   @ trainer #22 (17,56) TRAINER_ELIJAH, Emerald NORMAL sight 3
Route109_EventScript_SeashoreHouseSign::        @ sign (15,5)
Route109_EventScript_TrainerTipsSign::          @ sign (29,10)
	end
