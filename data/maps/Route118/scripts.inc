Route118_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route118_OnTransition), ON_LOAD (Route118_OnLoad), ON_FRAME_TABLE (Route118_OnFrame)
Route118_EventScript_ItemHyperPotion::          @ item ball, works (FLAG_ITEM_ROUTE_118_HYPER_POTION)
	finditem ITEM_HYPER_POTION
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route118/scripts.inc
Route118_EventScript_Perry::                    @ trainer #1 (64,10) TRAINER_PERRY, Emerald NORMAL sight 3
Route118_EventScript_Girl::                     @ NPC #2 (12,10)
Route118_EventScript_GoodRodFisherman::         @ NPC #4 (28,8)
Route118_EventScript_Rose::                     @ trainer #5 (7,12) TRAINER_ROSE_1, Emerald NORMAL sight 4
Route118_EventScript_Wade::                     @ trainer #6 (14,14) TRAINER_WADE, Emerald NORMAL sight 0
Route118_EventScript_Chester::                  @ trainer #7 (56,7) TRAINER_CHESTER, Emerald NORMAL sight 3
Route118_EventScript_Barny::                    @ trainer #8 (39,15) TRAINER_BARNY, Emerald NORMAL sight 2
Route118_EventScript_Dalton::                   @ trainer #9 (17,11) TRAINER_DALTON_1, Emerald NORMAL sight 3
Route118_EventScript_Deandre::                  @ trainer #11 (7,7) TRAINER_DEANDRE, Emerald NORMAL sight 4
Route118_EventScript_RouteSignMauville::        @ sign (13,6)
Route118_EventScript_RouteSign119::             @ sign (56,8)
	end
@ hoenn_import: left out: trigger (43,11) VAR_ROUTE118_STATE==0 -> Route118_EventScript_StevenTrigger0; trigger (44,11) VAR_ROUTE118_STATE==0 -> Route118_EventScript_StevenTrigger1; trigger (45,11) VAR_ROUTE118_STATE==0 -> Route118_EventScript_StevenTrigger2
