Route123_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route123_OnTransition)
Route123_EventScript_ItemCalcium::              @ item ball, works (FLAG_ITEM_ROUTE_123_CALCIUM)
	finditem ITEM_CALCIUM
	end
Route123_EventScript_ItemUltraBall::            @ item ball, works (FLAG_ITEM_ROUTE_123_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end
Route123_EventScript_ItemElixir::               @ item ball, works (FLAG_ITEM_ROUTE_123_ELIXIR)
	finditem ITEM_ELIXIR
	end
Route123_EventScript_ItemPPUp::                 @ item ball, works (FLAG_ITEM_ROUTE_123_PP_UP)
	finditem ITEM_PP_UP
	end
Route123_EventScript_ItemRevivalHerb::          @ item ball, works (FLAG_ITEM_ROUTE_123_REVIVAL_HERB)
	finditem ITEM_REVIVAL_HERB
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route123/scripts.inc
Route123_EventScript_Wendy::                    @ trainer #1 (70,12) TRAINER_WENDY, Emerald NORMAL sight 1
Route123_EventScript_Braxton::                  @ trainer #2 (58,7) TRAINER_BRAXTON, Emerald NORMAL sight 2
Route123_EventScript_GigaDrainGirl::            @ NPC #7 (108,13)
Route123_EventScript_Violet::                   @ trainer #8 (18,9) TRAINER_VIOLET, Emerald NORMAL sight 2
Route123_EventScript_Yuki::                     @ trainer #9 (38,13) TRAINER_MIU_AND_YUKI, Emerald NORMAL sight 1
Route123_EventScript_Miu::                      @ trainer #10 (37,13) TRAINER_MIU_AND_YUKI, Emerald NORMAL sight 1
Route123_EventScript_Cameron::                  @ trainer #11 (138,12) TRAINER_CAMERON_1, Emerald NORMAL sight 7
Route123_EventScript_Jacki::                    @ trainer #12 (49,16) TRAINER_JACKI_1, Emerald NORMAL sight 1
Route123_EventScript_Kindra::                   @ trainer #13 (87,12) TRAINER_KINDRA, Emerald NORMAL sight 4
Route123_EventScript_Jonas::                    @ trainer #16 (138,14) TRAINER_JONAS, Emerald NORMAL sight 1
Route123_EventScript_Kayley::                   @ trainer #17 (138,16) TRAINER_KAYLEY, Emerald NORMAL sight 1
Route123_EventScript_Ed::                       @ trainer #18 (87,17) TRAINER_ED, Emerald NORMAL sight 4
Route123_EventScript_Fernando::                 @ trainer #19 (66,16) TRAINER_FERNANDO_1, Emerald NORMAL sight 2
Route123_EventScript_Alberto::                  @ trainer #20 (66,19) TRAINER_ALBERTO, Emerald NORMAL sight 2
Route123_EventScript_Frederick::                @ trainer #21 (49,19) TRAINER_FREDRICK, Emerald NORMAL sight 2
Route123_EventScript_Jazmyn::                   @ trainer #23 (14,16) TRAINER_JAZMYN, Emerald NORMAL sight 3
Route123_EventScript_Davis::                    @ trainer #24 (14,12) TRAINER_DAVIS, Emerald NORMAL sight 3
Route123_EventScript_RouteSignMtPyre::          @ sign (117,10)
Route123_EventScript_RouteSign::                @ sign (10,12)
Route123_EventScript_BerryMastersHouseSign::    @ sign (20,7)
	end
