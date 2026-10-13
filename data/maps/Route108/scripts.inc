Route108_MapScripts::
	.byte 0
Route108_EventScript_ItemStarPiece::            @ item ball, works (FLAG_ITEM_ROUTE_108_STAR_PIECE)
	finditem ITEM_STAR_PIECE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route108/scripts.inc
Route108_EventScript_Jerome::                   @ trainer #1 (52,13) TRAINER_JEROME, Emerald NORMAL sight 3
Route108_EventScript_Tara::                     @ trainer #2 (35,12) TRAINER_TARA, Emerald NORMAL sight 3
Route108_EventScript_Matthew::                  @ trainer #3 (13,13) TRAINER_MATTHEW, Emerald NORMAL sight 3
Route108_EventScript_Missy::                    @ trainer #4 (8,7) TRAINER_MISSY, Emerald NORMAL sight 3
Route108_EventScript_Carolina::                 @ trainer #5 (41,5) TRAINER_CAROLINA, Emerald NORMAL sight 1
Route108_EventScript_Cory::                     @ trainer #6 (43,5) TRAINER_CORY_1, Emerald NORMAL sight 1
	end
