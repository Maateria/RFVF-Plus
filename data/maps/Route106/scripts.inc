Route106_MapScripts::
	.byte 0
Route106_EventScript_ItemProtein::              @ item ball, works (FLAG_ITEM_ROUTE_106_PROTEIN)
	finditem ITEM_PROTEIN
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route106/scripts.inc
Route106_EventScript_Douglas::                  @ trainer #1 (18,5) TRAINER_DOUGLAS, Emerald NORMAL sight 3
Route106_EventScript_Kyla::                     @ trainer #2 (29,10) TRAINER_KYLA, Emerald NORMAL sight 3
Route106_EventScript_Elliot::                   @ trainer #3 (51,14) TRAINER_ELLIOT_1, Emerald NORMAL sight 4
Route106_EventScript_Ned::                      @ trainer #4 (65,14) TRAINER_NED, Emerald NORMAL sight 3
Route106_EventScript_TrainerTipsSign::          @ sign (59,13)
	end
