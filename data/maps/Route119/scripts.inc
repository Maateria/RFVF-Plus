Route119_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (Route119_OnResume), ON_TRANSITION (Route119_OnTransition)
Route119_EventScript_ItemSuperRepel::           @ item ball, works (FLAG_ITEM_ROUTE_119_SUPER_REPEL)
	finditem ITEM_SUPER_REPEL
	end
Route119_EventScript_ItemZinc::                 @ item ball, works (FLAG_ITEM_ROUTE_119_ZINC)
	finditem ITEM_ZINC
	end
Route119_EventScript_ItemElixir::               @ item ball, works (FLAG_ITEM_ROUTE_119_ELIXIR_1)
	finditem ITEM_ELIXIR
	end
Route119_EventScript_ItemLeafStone::            @ item ball, works (FLAG_ITEM_ROUTE_119_LEAF_STONE)
	finditem ITEM_LEAF_STONE
	end
Route119_EventScript_ItemRareCandy::            @ item ball, works (FLAG_ITEM_ROUTE_119_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end
Route119_EventScript_ItemHyperPotion::          @ item ball, works (FLAG_ITEM_ROUTE_119_HYPER_POTION_1)
	finditem ITEM_HYPER_POTION
	end
Route119_EventScript_ItemHyperPotion2::         @ item ball, works (FLAG_ITEM_ROUTE_119_HYPER_POTION_2)
	finditem ITEM_HYPER_POTION
	end
Route119_EventScript_ItemNugget::               @ item ball, works (FLAG_ITEM_ROUTE_119_NUGGET)
	finditem ITEM_NUGGET
	end
Route119_EventScript_ItemElixir2::              @ item ball, works (FLAG_ITEM_ROUTE_119_ELIXIR_2)
	finditem ITEM_ELIXIR
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route119/scripts.inc
Route119_EventScript_Greg::                     @ trainer #1 (12,123) TRAINER_GREG, Emerald NORMAL sight 1
Route119_EventScript_Taylor::                   @ trainer #2 (26,123) TRAINER_TAYLOR, Emerald NORMAL sight 1
Route119_EventScript_Donald::                   @ trainer #3 (5,125) TRAINER_DONALD, Emerald NORMAL sight 1
Route119_EventScript_Jackson::                  @ trainer #4 (7,74) TRAINER_JACKSON_1, Emerald NORMAL sight 3
Route119_EventScript_Brent::                    @ trainer #5 (28,116) TRAINER_BRENT, Emerald NORMAL sight 1
Route119_EventScript_Catherine::                @ trainer #6 (35,83) TRAINER_CATHERINE_1, Emerald NORMAL sight 2
Route119_EventScript_Doug::                     @ trainer #7 (34,122) TRAINER_DOUG, Emerald NORMAL sight 1
Route119_EventScript_Kent::                     @ trainer #8 (17,128) TRAINER_KENT, Emerald NORMAL sight 1
Route119_EventScript_Yasu::                     @ trainer #9 (28,14) TRAINER_YASU, Emerald NORMAL sight 1
Route119_EventScript_Takashi::                  @ trainer #10 (19,49) TRAINER_TAKASHI, Emerald NORMAL sight 3
Route119_EventScript_Hugh::                     @ trainer #11 (10,50) TRAINER_HUGH, Emerald NORMAL sight 3
Route119_EventScript_Phil::                     @ trainer #12 (8,63) TRAINER_PHIL, Emerald NORMAL sight 5
Route119_EventScript_Boy1::                     @ NPC #19 (31,109)
Route119_EventScript_CyclingTriathleteM::       @ NPC #20 (19,133)
Route119_EventScript_Boy2::                     @ NPC #22 (35,93)
Route119_EventScript_Hideo::                    @ trainer #23 (29,6) TRAINER_HIDEO, Emerald NORMAL sight 3
Route119_EventScript_Chris::                    @ trainer #24 (13,104) TRAINER_CHRIS, Emerald NORMAL sight 0
Route119_EventScript_Rachel::                   @ trainer #25 (8,68) TRAINER_RACHEL, Emerald NORMAL sight 5
Route119_EventScript_Dayton::                   @ trainer #26 (16,52) TRAINER_DAYTON, Emerald NORMAL sight 3
Route119_EventScript_Fabian::                   @ trainer #27 (32,15) TRAINER_FABIAN, Emerald NORMAL sight 4
Route119_EventScript_WeatherInstituteSign::     @ sign (9,33)
Route119_EventScript_RouteSignFortree::         @ sign (27,19)
Route119_EventScript_TrainerTipsDecoration::    @ sign (28,9)
	end
@ hoenn_import: left out: trigger (25,31) VAR_ROUTE119_STATE==0 -> Route119_EventScript_RivalTrigger1; trigger (26,31) VAR_ROUTE119_STATE==0 -> Route119_EventScript_RivalTrigger2
