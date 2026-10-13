Route126_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route126_OnTransition)
Route126_EventScript_ItemGreenShard::           @ item ball, works (FLAG_ITEM_ROUTE_126_GREEN_SHARD)
	finditem ITEM_GREEN_SHARD
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route126/scripts.inc
Route126_EventScript_Barry::                    @ trainer #1 (51,65) TRAINER_BARRY, Emerald NORMAL sight 3
Route126_EventScript_Dean::                     @ trainer #2 (56,22) TRAINER_DEAN, Emerald NORMAL sight 3
Route126_EventScript_Nikki::                    @ trainer #3 (63,43) TRAINER_NIKKI, Emerald NORMAL sight 3
Route126_EventScript_Brenda::                   @ trainer #4 (9,48) TRAINER_BRENDA, Emerald NORMAL sight 3
Route126_EventScript_Sienna::                   @ trainer #6 (15,66) TRAINER_SIENNA, Emerald NORMAL sight 7
Route126_EventScript_Pablo::                    @ trainer #7 (7,66) TRAINER_PABLO_1, Emerald NORMAL sight 7
Route126_EventScript_Isobel::                   @ trainer #8 (64,5) TRAINER_ISOBEL, Emerald NORMAL sight 7
Route126_EventScript_Leonardo::                 @ trainer #9 (56,5) TRAINER_LEONARDO, Emerald NORMAL sight 7
	end
