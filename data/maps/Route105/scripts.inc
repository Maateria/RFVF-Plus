Route105_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (Route105_OnLoad), ON_TRANSITION (Route105_OnTransition), ON_FRAME_TABLE (Route105_OnFrame)
Route105_EventScript_ItemIron::                 @ item ball, works (FLAG_ITEM_ROUTE_105_IRON)
	finditem ITEM_IRON
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route105/scripts.inc
Route105_EventScript_Luis::                     @ trainer #1 (19,60) TRAINER_LUIS, Emerald NORMAL sight 6
Route105_EventScript_Dominik::                  @ trainer #2 (27,36) TRAINER_DOMINIK, Emerald NORMAL sight 3
Route105_EventScript_Beverly::                  @ trainer #3 (8,45) TRAINER_BEVERLY, Emerald NORMAL sight 3
Route105_EventScript_Imani::                    @ trainer #4 (19,9) TRAINER_IMANI, Emerald NORMAL sight 3
Route105_EventScript_Foster::                   @ trainer #6 (17,48) TRAINER_FOSTER, Emerald NORMAL sight 3
Route105_EventScript_Josue::                    @ trainer #7 (4,54) TRAINER_JOSUE, Emerald NORMAL sight 2
Route105_EventScript_Andres::                   @ trainer #8 (4,58) TRAINER_ANDRES_1, Emerald NORMAL sight 4
	end
