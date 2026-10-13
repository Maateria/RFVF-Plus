Route124_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route124_OnTransition)
Route124_EventScript_ItemRedShard::             @ item ball, works (FLAG_ITEM_ROUTE_124_RED_SHARD)
	finditem ITEM_RED_SHARD
	end
Route124_EventScript_ItemBlueShard::            @ item ball, works (FLAG_ITEM_ROUTE_124_BLUE_SHARD)
	finditem ITEM_BLUE_SHARD
	end
Route124_EventScript_ItemYellowShard::          @ item ball, works (FLAG_ITEM_ROUTE_124_YELLOW_SHARD)
	finditem ITEM_YELLOW_SHARD
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route124/scripts.inc
Route124_EventScript_Spencer::                  @ trainer #1 (34,25) TRAINER_SPENCER, Emerald NORMAL sight 3
Route124_EventScript_Roland::                   @ trainer #2 (61,74) TRAINER_ROLAND, Emerald NORMAL sight 7
Route124_EventScript_Jenny::                    @ trainer #3 (49,45) TRAINER_JENNY_1, Emerald NORMAL sight 3
Route124_EventScript_Grace::                    @ trainer #4 (7,23) TRAINER_GRACE, Emerald NORMAL sight 5
Route124_EventScript_Chad::                     @ trainer #5 (58,58) TRAINER_CHAD, Emerald NORMAL sight 2
Route124_EventScript_Lila::                     @ trainer #9 (18,44) TRAINER_LILA_AND_ROY_1, Emerald NORMAL sight 1
Route124_EventScript_Roy::                      @ trainer #10 (17,44) TRAINER_LILA_AND_ROY_1, Emerald NORMAL sight 1
Route124_EventScript_Declan::                   @ trainer #11 (7,29) TRAINER_DECLAN, Emerald NORMAL sight 5
Route124_EventScript_Isabella::                 @ trainer #12 (69,74) TRAINER_ISABELLA, Emerald NORMAL sight 7
Route124_EventScript_HuntersHouseSign::         @ sign (73,48)
	end
