.equ LOCALID_DAYCARE_MAN, 3

Route117_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route117_OnTransition)
Route117_EventScript_ItemGreatBall::            @ item ball, works (FLAG_ITEM_ROUTE_117_GREAT_BALL)
	finditem ITEM_GREAT_BALL
	end
Route117_EventScript_ItemRevive::               @ item ball, works (FLAG_ITEM_ROUTE_117_REVIVE)
	finditem ITEM_REVIVE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route117/scripts.inc
Route117_EventScript_Woman::                    @ NPC #1 (13,13)
Route117_EventScript_LittleBoy::                @ NPC #2 (25,5)
Route117_EventScript_DaycareMan::               @ NPC #3 (47,4)
Route117_EventScript_Dylan::                    @ trainer #8 (38,16) TRAINER_DYLAN_1, Emerald NORMAL sight 4
Route117_EventScript_Lydia::                    @ trainer #9 (8,10) TRAINER_LYDIA_1, Emerald NORMAL sight 3
Route117_EventScript_Isaac::                    @ trainer #10 (33,11) TRAINER_ISAAC_1, Emerald NORMAL sight 4
Route117_EventScript_Maria::                    @ trainer #14 (26,13) TRAINER_MARIA_1, Emerald NORMAL sight 5
Route117_EventScript_Derek::                    @ trainer #15 (17,12) TRAINER_DEREK, Emerald NORMAL sight 4
Route117_EventScript_Meg::                      @ trainer #16 (43,6) TRAINER_ANNA_AND_MEG_1, Emerald NORMAL sight 1
Route117_EventScript_Anna::                     @ trainer #17 (42,6) TRAINER_ANNA_AND_MEG_1, Emerald NORMAL sight 1
Route117_EventScript_Girl::                     @ NPC #18 (48,10)
Route117_EventScript_Brandi::                   @ trainer #19 (15,4) TRAINER_BRANDI, Emerald NORMAL sight 4
Route117_EventScript_Aisha::                    @ trainer #20 (21,4) TRAINER_AISHA, Emerald NORMAL sight 4
Route117_EventScript_Melina::                   @ trainer #21 (16,4) TRAINER_MELINA, Emerald NORMAL sight 4
Route117_EventScript_RouteSignVerdanturf::      @ sign (16,6)
Route117_EventScript_RouteSignMauville::        @ sign (49,12)
Route117_EventScript_DayCareSign::              @ sign (49,5)
	end
