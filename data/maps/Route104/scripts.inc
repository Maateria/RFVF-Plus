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
Route104_EventScript_Boy1::                     @ NPC #4 (27,63)
Route104_EventScript_Woman::                    @ NPC #5 (30,50)
Route104_EventScript_Girl2::                    @ NPC #6 (28,74)
Route104_EventScript_ExpertF::                  @ NPC #8 (37,8)
Route104_EventScript_WhiteHerbFlorist::         @ NPC #10 (8,19)
Route104_EventScript_Boy2::                     @ NPC #20 (5,26)
Route104_EventScript_BrineysCottageSign::       @ sign (20,50)
Route104_EventScript_RouteSignPetalburg::       @ sign (27,66)
Route104_EventScript_RouteSignRustboro::        @ sign (23,5)
Route104_EventScript_FlowerShopSign::           @ sign (7,20)
Route104_EventScript_TrainerTipsDoubleBattles:: @ sign (17,23)
	end
@ hoenn_import: left out: trigger (17,51) VAR_ROUTE104_STATE==1 -> Route104_EventScript_RivalTrigger

Route104_EventScript_Haley::
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchHaley
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RematchHaley::
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Ivan::
	trainerbattle_single TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Gina::
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Mia::
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Winston::
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchWinston
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RematchWinston::
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Cindy::
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_CindyIntro, Route104_Text_CindyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchCindy
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RematchCindy::
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Darian::
	trainerbattle_single TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
	end
