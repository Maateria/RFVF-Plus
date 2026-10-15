.equ LOCALID_CHALLENGE_BIKER, 18

Route110_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (Route110_OnResume), ON_TRANSITION (Route110_OnTransition), ON_FRAME_TABLE (Route110_OnFrame)
Route110_EventScript_ItemDireHit::              @ item ball, works (FLAG_ITEM_ROUTE_110_DIRE_HIT)
	finditem ITEM_DIRE_HIT
	end
Route110_EventScript_ItemRareCandy::            @ item ball, works (FLAG_ITEM_ROUTE_110_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end
Route110_EventScript_ItemElixir::               @ item ball, works (FLAG_ITEM_ROUTE_110_ELIXIR)
	finditem ITEM_ELIXIR
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110/scripts.inc
Route110_EventScript_Boy2::                     @ NPC #1 (17,90)
Route110_EventScript_CyclingGuy2::              @ NPC #2 (29,79)
Route110_EventScript_OldWoman::                 @ NPC #3 (14,69)
Route110_EventScript_CyclingGuy1::              @ NPC #4 (9,57)
Route110_EventScript_OldMan::                   @ NPC #5 (10,11)
Route110_EventScript_CyclingGirl1::             @ NPC #6 (27,24)
Route110_EventScript_Boy1::                     @ NPC #7 (15,7)
Route110_EventScript_ChallengeGuy::             @ NPC #18 (27,92)
Route110_EventScript_VandalizedSign::           @ sign (15,25)
Route110_EventScript_SeasideParkingSign::       @ sign (9,51)
Route110_EventScript_CyclingRoadSign::          @ sign (14,88)
Route110_EventScript_SlateportCitySign::        @ sign (20,94)
Route110_EventScript_Route103Sign::             @ sign (7,79)
Route110_EventScript_MauvilleCitySign::         @ sign (3,17)
Route110_EventScript_TrainerTipsPrlzSleep::     @ sign (33,39)
Route110_EventScript_TrainerTipsRegisterItems:: @ sign (37,70)
Route110_EventScript_TrickHouseSign::           @ sign (8,67)
Route110_EventScript_CyclingRoadResultsSign::   @ sign (32,93)
	end
@ hoenn_import: left out: trigger (28,92) VAR_CYCLING_CHALLENGE_STATE==2 -> Route110_EventScript_CyclingChallengeEnd; trigger (29,92) VAR_CYCLING_CHALLENGE_STATE==2 -> Route110_EventScript_CyclingChallengeEnd; trigger (33,56) VAR_ROUTE110_STATE==0 -> Route110_EventScript_RivalTrigger1; trigger (34,56) VAR_ROUTE110_STATE==0 -> Route110_EventScript_RivalTrigger2; trigger (35,56) VAR_ROUTE110_STATE==0 -> Route110_EventScript_RivalTrigger3; trigger (7,85) VAR_REGISTER_BIRCH_STATE==1 -> Route110_EventScript_BirchScene1; trigger (8,85) VAR_REGISTER_BIRCH_STATE==1 -> Route110_EventScript_BirchScene2; trigger (9,85) VAR_REGISTER_BIRCH_STATE==1 -> Route110_EventScript_BirchScene3; trigger (10,85) VAR_REGISTER_BIRCH_STATE==1 -> Route110_EventScript_BirchScene4

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end
