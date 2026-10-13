Route112_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route112_OnTransition)
Route112_EventScript_ItemNugget::               @ item ball, works (FLAG_ITEM_ROUTE_112_NUGGET)
	finditem ITEM_NUGGET
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route112/scripts.inc
Route112_EventScript_Brice::                    @ trainer #1 (24,34) TRAINER_BRICE, Emerald NORMAL sight 2
Route112_EventScript_Larry::                    @ trainer #2 (29,49) TRAINER_LARRY, Emerald NORMAL sight 3
Route112_EventScript_Carol::                    @ trainer #3 (22,46) TRAINER_CAROL, Emerald NORMAL sight 3
Route112_EventScript_Trent::                    @ trainer #4 (15,40) TRAINER_TRENT_1, Emerald NORMAL sight 3
Route112_EventScript_Hiker::                    @ NPC #5 (8,50)
Route112_EventScript_Bryant::                   @ trainer #7 (31,7) TRAINER_BRYANT, Emerald NORMAL sight 3
Route112_EventScript_Shayla::                   @ trainer #8 (31,11) TRAINER_SHAYLA, Emerald NORMAL sight 3
Route112_EventScript_MtChimneySign::            @ sign (19,44)
Route112_EventScript_MtChimneyCableCarSign::    @ sign (22,37)
Route112_EventScript_RouteSignLavaridge::       @ sign (4,49)
	end
