Route120_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (Route120_OnResume), ON_TRANSITION (Route120_OnTransition), ON_LOAD (Route120_OnLoad)
Route120_EventScript_ItemNugget::               @ item ball, works (FLAG_ITEM_ROUTE_120_NUGGET)
	finditem ITEM_NUGGET
	end
Route120_EventScript_ItemFullHeal::             @ item ball, works (FLAG_ITEM_ROUTE_120_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end
Route120_EventScript_ItemNestBall::             @ item ball, works (FLAG_ITEM_ROUTE_120_NEST_BALL)
	finditem ITEM_NEST_BALL
	end
Route120_EventScript_ItemHyperPotion::          @ item ball, works (FLAG_ITEM_ROUTE_120_HYPER_POTION)
	finditem ITEM_HYPER_POTION
	end
Route120_EventScript_ItemRevive::               @ item ball, works (FLAG_ITEM_ROUTE_120_REVIVE)
	finditem ITEM_REVIVE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route120/scripts.inc
Route120_EventScript_Colin::                    @ trainer #1 (5,22) TRAINER_COLIN, Emerald NORMAL sight 3
Route120_EventScript_Robert::                   @ trainer #2 (32,14) TRAINER_ROBERT_1, Emerald NORMAL sight 3
Route120_EventScript_Lorenzo::                  @ trainer #3 (27,51) TRAINER_LORENZO, Emerald NORMAL sight 7
Route120_EventScript_Jenna::                    @ trainer #4 (36,45) TRAINER_JENNA, Emerald NORMAL sight 2
Route120_EventScript_Jeffrey::                  @ trainer #5 (19,80) TRAINER_JEFFREY_1, Emerald NORMAL sight 3
Route120_EventScript_BerryBeauty::              @ NPC #9 (14,92)
Route120_EventScript_Jennifer::                 @ trainer #10 (31,37) TRAINER_JENNIFER, Emerald NORMAL sight 4
Route120_EventScript_Chip::                     @ trainer #11 (9,60) TRAINER_CHIP, Emerald NORMAL sight 4
Route120_EventScript_Clarissa::                 @ trainer #12 (16,6) TRAINER_CLARISSA, Emerald NORMAL sight 4
Route120_EventScript_Angelica::                 @ trainer #13 (18,34) TRAINER_ANGELICA, Emerald NORMAL sight 3
Route120_EventScript_Keigo::                    @ trainer #18 (10,72) TRAINER_KEIGO, Emerald NORMAL sight 3
Route120_EventScript_Riley::                    @ trainer #19 (19,28) TRAINER_RILEY, Emerald NORMAL sight 3
Route120_EventScript_Callie::                   @ trainer #20 (19,32) TRAINER_CALLIE, Emerald NORMAL sight 3
Route120_EventScript_Leonel::                   @ trainer #21 (14,34) TRAINER_LEONEL, Emerald NORMAL sight 3
Route120_EventScript_RouteSignFortree::         @ sign (27,3)
Route120_EventScript_RouteSign121::             @ sign (38,88)
	end
