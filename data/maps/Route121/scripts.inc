Route121_MapScripts::
	.byte 0
Route121_EventScript_ItemCarbos::               @ item ball, works (FLAG_ITEM_ROUTE_121_CARBOS)
	finditem ITEM_CARBOS
	end
Route121_EventScript_ItemRevive::               @ item ball, works (FLAG_ITEM_ROUTE_121_REVIVE)
	finditem ITEM_REVIVE
	end
Route121_EventScript_ItemZinc::                 @ item ball, works (FLAG_ITEM_ROUTE_121_ZINC)
	finditem ITEM_ZINC
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route121/scripts.inc
Route121_EventScript_Woman::                    @ NPC #1 (29,14)
Route121_EventScript_Kate::                     @ trainer #2 (39,9) TRAINER_KATE_AND_JOY, Emerald NORMAL sight 1
Route121_EventScript_Joy::                      @ trainer #3 (40,9) TRAINER_KATE_AND_JOY, Emerald NORMAL sight 1
Route121_EventScript_Vanessa::                  @ trainer #6 (63,5) TRAINER_VANESSA, Emerald NORMAL sight 4
Route121_EventScript_Walter::                   @ trainer #7 (55,8) TRAINER_WALTER_1, Emerald NORMAL sight 3
Route121_EventScript_Tammy::                    @ trainer #8 (11,11) TRAINER_TAMMY, Emerald NORMAL sight 4
Route121_EventScript_Jessica::                  @ trainer #9 (22,5) TRAINER_JESSICA_1, Emerald NORMAL sight 4
Route121_EventScript_Cale::                     @ trainer #12 (11,6) TRAINER_CALE, Emerald NORMAL sight 3
Route121_EventScript_Myles::                    @ trainer #13 (59,8) TRAINER_MYLES, Emerald NORMAL sight 4
Route121_EventScript_Pat::                      @ trainer #14 (59,13) TRAINER_PAT, Emerald NORMAL sight 4
Route121_EventScript_Marcel::                   @ trainer #15 (65,9) TRAINER_MARCEL, Emerald NORMAL sight 6
Route121_EventScript_Cristin::                  @ trainer #16 (72,9) TRAINER_CRISTIN_1, Emerald NORMAL sight 6
Route121_EventScript_MtPyrePierSign::           @ sign (32,14)
Route121_EventScript_SafariZoneSign::           @ sign (39,6)
	end
@ hoenn_import: left out: trigger (25,5) VAR_ROUTE121_STATE==0 -> Route121_EventScript_AquaGruntsMoveOut; trigger (25,6) VAR_ROUTE121_STATE==0 -> Route121_EventScript_AquaGruntsMoveOut; trigger (25,7) VAR_ROUTE121_STATE==0 -> Route121_EventScript_AquaGruntsMoveOut; trigger (25,8) VAR_ROUTE121_STATE==0 -> Route121_EventScript_AquaGruntsMoveOut
