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
Route110_EventScript_Jasmine::                  @ trainer #8 (16,73) TRAINER_JASMINE, Emerald NORMAL sight 3
Route110_EventScript_Anthony::                  @ trainer #9 (19,31) TRAINER_ANTHONY, Emerald NORMAL sight 3
Route110_EventScript_Abigail::                  @ trainer #10 (30,31) TRAINER_ABIGAIL_1, Emerald NORMAL sight 4
Route110_EventScript_Benjamin::                 @ trainer #11 (16,55) TRAINER_BENJAMIN_1, Emerald NORMAL sight 3
Route110_EventScript_Edward::                   @ trainer #12 (3,39) TRAINER_EDWARD, Emerald NORMAL sight 6
Route110_EventScript_Jaclyn::                   @ trainer #13 (33,15) TRAINER_JACLYN, Emerald NORMAL sight 1
Route110_EventScript_Edwin::                    @ trainer #14 (34,40) TRAINER_EDWIN_1, Emerald NORMAL sight 4
Route110_EventScript_Dale::                     @ trainer #15 (10,19) TRAINER_DALE, Emerald NORMAL sight 1
Route110_EventScript_ChallengeGuy::             @ NPC #18 (27,92)
Route110_EventScript_Jacob::                    @ trainer #19 (21,78) TRAINER_JACOB, Emerald NORMAL sight 2
Route110_EventScript_Timmy::                    @ trainer #20 (33,69) TRAINER_TIMMY, Emerald NORMAL sight 3
Route110_EventScript_Isabel::                   @ trainer #21 (10,76) TRAINER_ISABEL_1, Emerald NORMAL sight 2
Route110_EventScript_Kaleb::                    @ trainer #22 (7,76) TRAINER_KALEB, Emerald NORMAL sight 2
Route110_EventScript_Alyssa::                   @ trainer #23 (10,39) TRAINER_ALYSSA, Emerald NORMAL sight 6
Route110_EventScript_Joseph::                   @ trainer #24 (36,40) TRAINER_JOSEPH, Emerald NORMAL sight 3
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
