Route103_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route103_OnTransition), ON_LOAD (Route103_OnLoad)
Route103_EventScript_ItemGuardSpec::            @ item ball, works (FLAG_ITEM_ROUTE_103_GUARD_SPEC)
	finditem ITEM_GUARD_SPEC
	end
Route103_EventScript_ItemPPUp::                 @ item ball, works (FLAG_ITEM_ROUTE_103_PP_UP)
	finditem ITEM_PP_UP
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route103/scripts.inc
Route103_EventScript_Man::                      @ NPC #1 (49,12)
Route103_EventScript_Daisy::                    @ trainer #2 (71,11) TRAINER_DAISY, Emerald NORMAL sight 3
Route103_EventScript_Liv::                      @ trainer #3 (65,12) TRAINER_AMY_AND_LIV_1, Emerald NORMAL sight 1
Route103_EventScript_Amy::                      @ trainer #4 (64,12) TRAINER_AMY_AND_LIV_1, Emerald NORMAL sight 1
Route103_EventScript_Andrew::                   @ trainer #5 (50,8) TRAINER_ANDREW, Emerald NORMAL sight 3
Route103_EventScript_Boy::                      @ NPC #6 (20,10)
Route103_EventScript_Miguel::                   @ trainer #7 (56,13) TRAINER_MIGUEL_1, Emerald NORMAL sight 5
Route103_EventScript_Rhett::                    @ trainer #11 (67,5) TRAINER_RHETT, Emerald NORMAL sight 2
Route103_EventScript_Marcos::                   @ trainer #12 (67,9) TRAINER_MARCOS, Emerald NORMAL sight 2
Route103_EventScript_Isabelle::                 @ trainer #13 (36,6) TRAINER_ISABELLE, Emerald NORMAL sight 5
Route103_EventScript_Pete::                     @ trainer #14 (36,13) TRAINER_PETE, Emerald NORMAL sight 5
Route103_EventScript_RouteSign::                @ sign (11,9)
	end
