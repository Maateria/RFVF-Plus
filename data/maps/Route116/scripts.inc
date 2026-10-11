Route116_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route116_OnTransition), ON_LOAD (Route116_OnLoad), ON_FRAME_TABLE (Route116_OnFrame)
Route116_EventScript_ItemEther::                @ item ball, works (FLAG_ITEM_ROUTE_116_ETHER)
	finditem ITEM_ETHER
	end
Route116_EventScript_ItemRepel::                @ item ball, works (FLAG_ITEM_ROUTE_116_REPEL)
	finditem ITEM_REPEL
	end
Route116_EventScript_ItemHPUp::                 @ item ball, works (FLAG_ITEM_ROUTE_116_HP_UP)
	finditem ITEM_HP_UP
	end
Route116_EventScript_ItemXSpecial::             @ item ball, works (FLAG_ITEM_ROUTE_116_X_SPECIAL)
	finditem ITEM_X_SPECIAL
	end
Route116_EventScript_ItemPotion::               @ item ball, works (FLAG_ITEM_ROUTE_116_POTION)
	finditem ITEM_POTION
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route116/scripts.inc
Route116_EventScript_Joey::                     @ trainer #1 (12,7) TRAINER_JOEY, Emerald NORMAL sight 3
Route116_EventScript_Jose::                     @ trainer #4 (13,17) TRAINER_JOSE, Emerald NORMAL sight 2
Route116_EventScript_Clark::                    @ trainer #8 (36,17) TRAINER_CLARK, Emerald NORMAL sight 3
Route116_EventScript_Janice::                   @ trainer #11 (26,6) TRAINER_JANICE, Emerald NORMAL sight 2
Route116_EventScript_Karen::                    @ trainer #12 (22,16) TRAINER_KAREN_1, Emerald NORMAL sight 3
Route116_EventScript_Jerry::                    @ trainer #13 (28,8) TRAINER_JERRY_1, Emerald NORMAL sight 4
Route116_EventScript_GlassesMan::               @ NPC #15 (74,13)
Route116_EventScript_Sarah::                    @ trainer #16 (33,8) TRAINER_SARAH, Emerald NORMAL sight 1
Route116_EventScript_Dawson::                   @ trainer #17 (33,5) TRAINER_DAWSON, Emerald NORMAL sight 2
Route116_EventScript_Johnson::                  @ trainer #20 (36,13) TRAINER_JOHNSON, Emerald NORMAL sight 5
Route116_EventScript_Devan::                    @ trainer #21 (42,13) TRAINER_DEVAN, Emerald NORMAL sight 5
Route116_EventScript_RouteSignRustboro::        @ sign (5,10)
Route116_EventScript_RusturfTunnelSign::        @ sign (48,9)
Route116_EventScript_TunnelersRestHouseSign::   @ sign (40,9)
Route116_EventScript_TrainerTipsBToStopEvolution:: @ sign (16,12)
Route116_EventScript_TrainerTipsBagHasPockets:: @ sign (29,10)
	end
@ hoenn_import: left out: trigger (47,9) VAR_ROUTE116_STATE==1 -> Route116_EventScript_BrineyTrigger
