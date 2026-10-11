Route132_MapScripts::
	.byte 0
Route132_EventScript_ItemRareCandy::            @ item ball, works (FLAG_ITEM_ROUTE_132_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end
Route132_EventScript_ItemProtein::              @ item ball, works (FLAG_ITEM_ROUTE_132_PROTEIN)
	finditem ITEM_PROTEIN
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route132/scripts.inc
Route132_EventScript_Gilbert::                  @ trainer #1 (40,13) TRAINER_GILBERT, Emerald NORMAL sight 2
Route132_EventScript_Dana::                     @ trainer #2 (10,6) TRAINER_DANA, Emerald NORMAL sight 2
Route132_EventScript_Kiyo::                     @ trainer #4 (9,15) TRAINER_KIYO, Emerald NORMAL sight 4
Route132_EventScript_Ronald::                   @ trainer #5 (49,28) TRAINER_RONALD, Emerald NORMAL sight 1
Route132_EventScript_Paxton::                   @ trainer #6 (33,26) TRAINER_PAXTON, Emerald NORMAL sight 4
Route132_EventScript_Darcy::                    @ trainer #7 (33,31) TRAINER_DARCY, Emerald NORMAL sight 4
Route132_EventScript_Makayla::                  @ trainer #8 (21,30) TRAINER_MAKAYLA, Emerald NORMAL sight 4
Route132_EventScript_Jonathan::                 @ trainer #9 (21,25) TRAINER_JONATHAN, Emerald NORMAL sight 4
	end
