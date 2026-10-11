Route134_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (Route134_OnResume)
Route134_EventScript_ItemCarbos::               @ item ball, works (FLAG_ITEM_ROUTE_134_CARBOS)
	finditem ITEM_CARBOS
	end
Route134_EventScript_ItemStarPiece::            @ item ball, works (FLAG_ITEM_ROUTE_134_STAR_PIECE)
	finditem ITEM_STAR_PIECE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route134/scripts.inc
Route134_EventScript_Jack::                     @ trainer #1 (49,9) TRAINER_JACK, Emerald NORMAL sight 2
Route134_EventScript_Laurel::                   @ trainer #2 (58,7) TRAINER_LAUREL, Emerald NORMAL sight 3
Route134_EventScript_Aaron::                    @ trainer #3 (41,23) TRAINER_AARON, Emerald NORMAL sight 2
Route134_EventScript_Alex::                     @ trainer #4 (24,23) TRAINER_ALEX, Emerald NORMAL sight 6
Route134_EventScript_Hitoshi::                  @ trainer #5 (49,16) TRAINER_HITOSHI, Emerald NORMAL sight 5
Route134_EventScript_Marley::                   @ trainer #6 (43,23) TRAINER_MARLEY, Emerald NORMAL sight 2
Route134_EventScript_Kelvin::                   @ trainer #7 (24,30) TRAINER_KELVIN, Emerald NORMAL sight 6
Route134_EventScript_Reyna::                    @ trainer #8 (50,16) TRAINER_REYNA, Emerald NORMAL sight 5
Route134_EventScript_Hudson::                   @ trainer #9 (63,14) TRAINER_HUDSON, Emerald NORMAL sight 3
	end
