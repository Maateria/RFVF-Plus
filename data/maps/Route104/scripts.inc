Route104_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (Route104_OnFrame), ON_TRANSITION (Route104_OnTransition)
Route104_EventScript_ItemPPUp::                 @ item ball, works (FLAG_ITEM_ROUTE_104_PP_UP)
	finditem ITEM_PP_UP
	end
Route104_EventScript_ItemPokeBall::             @ item ball, works (FLAG_ITEM_ROUTE_104_POKE_BALL)
	finditem ITEM_POKE_BALL
	end
Route104_EventScript_ItemXAccuracy::            @ item ball, works (FLAG_ITEM_ROUTE_104_X_ACCURACY)
	finditem ITEM_X_ACCURACY
	end
Route104_EventScript_ItemPotion::               @ item ball, works (FLAG_ITEM_ROUTE_104_POTION)
	finditem ITEM_POTION
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route104/scripts.inc
Route104_EventScript_BugCatcher::               @ NPC #1 (15,60)
Route104_EventScript_Girl1::                    @ NPC #2 (25,49)
Route104_EventScript_Haley::                    @ trainer #3 (31,24) TRAINER_HALEY_1, Emerald NORMAL sight 7
Route104_EventScript_Boy1::                     @ NPC #4 (27,63)
Route104_EventScript_Woman::                    @ NPC #5 (30,50)
Route104_EventScript_Girl2::                    @ NPC #6 (28,74)
Route104_EventScript_Ivan::                     @ trainer #7 (29,8) TRAINER_IVAN, Emerald NORMAL sight 0
Route104_EventScript_ExpertF::                  @ NPC #8 (37,8)
Route104_EventScript_WhiteHerbFlorist::         @ NPC #10 (8,19)
Route104_EventScript_Gina::                     @ trainer #11 (27,15) TRAINER_GINA_AND_MIA_1, Emerald NORMAL sight 1
Route104_EventScript_Mia::                      @ trainer #12 (28,15) TRAINER_GINA_AND_MIA_1, Emerald NORMAL sight 1
Route104_EventScript_Winston::                  @ trainer #13 (21,25) TRAINER_WINSTON_1, Emerald NORMAL sight 3
Route104_EventScript_Cindy::                    @ trainer #14 (11,44) TRAINER_CINDY_1, Emerald NORMAL sight 3
Route104_EventScript_Billy::                    @ trainer #16 (18,67) TRAINER_BILLY, Emerald NORMAL sight 2
Route104_EventScript_Boy2::                     @ NPC #20 (5,26)
Route104_EventScript_Darian::                   @ trainer #21 (15,59) TRAINER_DARIAN, Emerald NORMAL sight 0
Route104_EventScript_BrineysCottageSign::       @ sign (20,50)
Route104_EventScript_RouteSignPetalburg::       @ sign (27,66)
Route104_EventScript_RouteSignRustboro::        @ sign (23,5)
Route104_EventScript_FlowerShopSign::           @ sign (7,20)
Route104_EventScript_TrainerTipsDoubleBattles:: @ sign (17,23)
	end
@ hoenn_import: left out: trigger (17,51) VAR_ROUTE104_STATE==1 -> Route104_EventScript_RivalTrigger
