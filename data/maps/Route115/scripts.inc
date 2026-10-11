Route115_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (Route115_OnLoad), ON_TRANSITION (Route115_OnTransition), ON_FRAME_TABLE (Route115_OnFrame)
Route115_EventScript_ItemSuperPotion::          @ item ball, works (FLAG_ITEM_ROUTE_115_SUPER_POTION)
	finditem ITEM_SUPER_POTION
	end
Route115_EventScript_ItemTMFocusPunch::         @ item ball, works (FLAG_ITEM_ROUTE_115_TM_FOCUS_PUNCH)
	finditem ITEM_TM01_FOCUS_PUNCH
	end
Route115_EventScript_ItemIron::                 @ item ball, works (FLAG_ITEM_ROUTE_115_IRON)
	finditem ITEM_IRON
	end
Route115_EventScript_ItemGreatBall::            @ item ball, works (FLAG_ITEM_ROUTE_115_GREAT_BALL)
	finditem ITEM_GREAT_BALL
	end
Route115_EventScript_ItemPPUp::                 @ item ball, works (FLAG_ITEM_ROUTE_115_PP_UP)
	finditem ITEM_PP_UP
	end
Route115_EventScript_ItemHealPowder::           @ item ball, works (FLAG_ITEM_ROUTE_115_HEAL_POWDER)
	finditem ITEM_HEAL_POWDER
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route115/scripts.inc
Route115_EventScript_Woman::                    @ NPC #1 (18,68)
Route115_EventScript_Timothy::                  @ trainer #2 (5,15) TRAINER_TIMOTHY_1, Emerald NORMAL sight 6
Route115_EventScript_Nob::                      @ trainer #3 (27,53) TRAINER_NOB_1, Emerald NORMAL sight 4
Route115_EventScript_Cyndy::                    @ trainer #4 (15,50) TRAINER_CYNDY_1, Emerald NORMAL sight 3
Route115_EventScript_Koichi::                   @ trainer #5 (19,15) TRAINER_KOICHI, Emerald NORMAL sight 2
Route115_EventScript_Hector::                   @ trainer #6 (24,62) TRAINER_HECTOR, Emerald NORMAL sight 4
Route115_EventScript_Kyra::                     @ trainer #12 (10,15) TRAINER_KYRA, Emerald NORMAL sight 2
Route115_EventScript_Jaiden::                   @ trainer #13 (11,12) TRAINER_JAIDEN, Emerald NORMAL sight 3
Route115_EventScript_Helene::                   @ trainer #14 (15,7) TRAINER_HELENE, Emerald NORMAL sight 4
Route115_EventScript_Alix::                     @ trainer #15 (10,7) TRAINER_ALIX, Emerald NORMAL sight 4
Route115_EventScript_Marlene::                  @ trainer #16 (28,62) TRAINER_MARLENE, Emerald NORMAL sight 4
Route115_EventScript_RouteSignRustboro::        @ sign (16,64)
Route115_EventScript_MeteorFallsSign::          @ sign (25,38)
	end
