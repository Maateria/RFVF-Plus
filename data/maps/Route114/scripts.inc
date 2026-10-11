Route114_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route114_OnTransition), ON_LOAD (Route114_OnLoad), ON_FRAME_TABLE (Route114_OnFrame)
Route114_EventScript_ItemRareCandy::            @ item ball, works (FLAG_ITEM_ROUTE_114_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end
Route114_EventScript_ItemProtein::              @ item ball, works (FLAG_ITEM_ROUTE_114_PROTEIN)
	finditem ITEM_PROTEIN
	end
Route114_EventScript_ItemEnergyPowder::         @ item ball, works (FLAG_ITEM_ROUTE_114_ENERGY_POWDER)
	finditem ITEM_ENERGY_POWDER
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route114/scripts.inc
Route114_EventScript_Lenny::                    @ trainer #1 (15,65) TRAINER_LENNY, Emerald NORMAL sight 6
Route114_EventScript_Lucas::                    @ trainer #2 (30,72) TRAINER_LUCAS_1, Emerald NORMAL sight 4
Route114_EventScript_Shane::                    @ trainer #3 (22,50) TRAINER_SHANE, Emerald NORMAL sight 3
Route114_EventScript_Nancy::                    @ trainer #4 (19,35) TRAINER_NANCY, Emerald NORMAL sight 3
Route114_EventScript_Steve::                    @ trainer #5 (20,56) TRAINER_STEVE_1, Emerald NORMAL sight 3
Route114_EventScript_RoarGentleman::            @ NPC #9 (19,11)
Route114_EventScript_Poochyena::                @ NPC #10 (19,12)
Route114_EventScript_Man::                      @ NPC #11 (27,42)
Route114_EventScript_Nolan::                    @ trainer #12 (25,6) TRAINER_NOLAN, Emerald NORMAL sight 0
Route114_EventScript_Claude::                   @ trainer #13 (19,26) TRAINER_CLAUDE, Emerald NORMAL sight 0
Route114_EventScript_Bernie::                   @ trainer #14 (30,58) TRAINER_BERNIE_1, Emerald NORMAL sight 3
Route114_EventScript_Ivy::                      @ trainer #19 (24,44) TRAINER_TYRA_AND_IVY, Emerald NORMAL sight 1
Route114_EventScript_Tyra::                     @ trainer #20 (23,44) TRAINER_TYRA_AND_IVY, Emerald NORMAL sight 1
Route114_EventScript_Charlotte::                @ trainer #21 (28,20) TRAINER_CHARLOTTE, Emerald NORMAL sight 3
Route114_EventScript_Angelina::                 @ trainer #22 (26,72) TRAINER_ANGELINA, Emerald NORMAL sight 4
Route114_EventScript_Kai::                      @ trainer #24 (28,16) TRAINER_KAI, Emerald NORMAL sight 3
Route114_EventScript_MeteorFallsSign::          @ sign (7,64)
Route114_EventScript_FossilManiacsHouseSign::   @ sign (31,7)
Route114_EventScript_LanettesHouseSign::        @ sign (25,38)
	end
