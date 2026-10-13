Route127_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route127_OnTransition), ON_LOAD (Route127_OnLoad), ON_FRAME_TABLE (Route127_OnFrame)
Route127_EventScript_ItemZinc::                 @ item ball, works (FLAG_ITEM_ROUTE_127_ZINC)
	finditem ITEM_ZINC
	end
Route127_EventScript_ItemCarbos::               @ item ball, works (FLAG_ITEM_ROUTE_127_CARBOS)
	finditem ITEM_CARBOS
	end
Route127_EventScript_ItemRareCandy::            @ item ball, works (FLAG_ITEM_ROUTE_127_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route127/scripts.inc
Route127_EventScript_Camden::                   @ trainer #1 (45,42) TRAINER_CAMDEN, Emerald NORMAL sight 2
Route127_EventScript_Donny::                    @ trainer #2 (18,68) TRAINER_DONNY, Emerald NORMAL sight 4
Route127_EventScript_Jonah::                    @ trainer #5 (42,21) TRAINER_JONAH, Emerald NORMAL sight 0
Route127_EventScript_Roger::                    @ trainer #6 (64,19) TRAINER_ROGER, Emerald NORMAL sight 0
Route127_EventScript_Henry::                    @ trainer #7 (54,14) TRAINER_HENRY, Emerald NORMAL sight 0
Route127_EventScript_Aidan::                    @ trainer #8 (15,23) TRAINER_AIDAN, Emerald NORMAL sight 2
Route127_EventScript_Koji::                     @ trainer #9 (63,63) TRAINER_KOJI_1, Emerald NORMAL sight 3
Route127_EventScript_Athena::                   @ trainer #10 (12,23) TRAINER_ATHENA, Emerald NORMAL sight 2
	end
