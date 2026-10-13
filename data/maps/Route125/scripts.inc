Route125_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route125_OnTransition), ON_LOAD (Route125_OnLoad), ON_FRAME_TABLE (Route125_OnFrame)
Route125_EventScript_ItemBigPearl::             @ item ball, works (FLAG_ITEM_ROUTE_125_BIG_PEARL)
	finditem ITEM_BIG_PEARL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route125/scripts.inc
Route125_EventScript_Nolen::                    @ trainer #1 (7,31) TRAINER_NOLEN, Emerald NORMAL sight 2
Route125_EventScript_Stan::                     @ trainer #2 (45,9) TRAINER_STAN, Emerald NORMAL sight 2
Route125_EventScript_Tanya::                    @ trainer #3 (38,24) TRAINER_TANYA, Emerald NORMAL sight 3
Route125_EventScript_Sharon::                   @ trainer #4 (30,28) TRAINER_SHARON, Emerald NORMAL sight 3
Route125_EventScript_Ernest::                   @ trainer #5 (21,30) TRAINER_ERNEST_1, Emerald NORMAL sight 2
Route125_EventScript_Kim::                      @ trainer #6 (17,19) TRAINER_KIM_AND_IRIS, Emerald NORMAL sight 1
Route125_EventScript_Iris::                     @ trainer #7 (18,19) TRAINER_KIM_AND_IRIS, Emerald NORMAL sight 1
Route125_EventScript_Presley::                  @ trainer #8 (43,19) TRAINER_PRESLEY, Emerald NORMAL sight 3
Route125_EventScript_Auron::                    @ trainer #9 (48,19) TRAINER_AURON, Emerald NORMAL sight 3
	end
