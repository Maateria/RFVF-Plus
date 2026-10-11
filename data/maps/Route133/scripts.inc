Route133_MapScripts::
	.byte 0
Route133_EventScript_ItemBigPearl::             @ item ball, works (FLAG_ITEM_ROUTE_133_BIG_PEARL)
	finditem ITEM_BIG_PEARL
	end
Route133_EventScript_ItemStarPiece::            @ item ball, works (FLAG_ITEM_ROUTE_133_STAR_PIECE)
	finditem ITEM_STAR_PIECE
	end
Route133_EventScript_ItemMaxRevive::            @ item ball, works (FLAG_ITEM_ROUTE_133_MAX_REVIVE)
	finditem ITEM_MAX_REVIVE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route133/scripts.inc
Route133_EventScript_Franklin::                 @ trainer #1 (68,27) TRAINER_FRANKLIN, Emerald NORMAL sight 3
Route133_EventScript_Linda::                    @ trainer #2 (13,3) TRAINER_LINDA, Emerald NORMAL sight 3
Route133_EventScript_Debra::                    @ trainer #3 (68,28) TRAINER_DEBRA, Emerald NORMAL sight 3
Route133_EventScript_Beck::                     @ trainer #6 (7,14) TRAINER_BECK, Emerald NORMAL sight 2
Route133_EventScript_Warren::                   @ trainer #7 (37,15) TRAINER_WARREN, Emerald NORMAL sight 4
Route133_EventScript_Mollie::                   @ trainer #8 (56,11) TRAINER_MOLLIE, Emerald NORMAL sight 3
Route133_EventScript_Conor::                    @ trainer #9 (56,15) TRAINER_CONOR, Emerald NORMAL sight 3
	end
