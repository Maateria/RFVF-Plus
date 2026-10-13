HoennVictoryRoad_B2F_MapScripts::
	.byte 0
HoennVictoryRoad_B2F_EventScript_ItemFullHeal:: @ item ball, works (FLAG_ITEM_HOENN_VICTORY_ROAD_B2F_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/VictoryRoad_B2F/scripts.inc
HoennVictoryRoad_B2F_EventScript_Vito::         @ trainer #1 (15,6) TRAINER_VITO, Emerald NORMAL sight 2
HoennVictoryRoad_B2F_EventScript_Owen::         @ trainer #2 (43,14) TRAINER_OWEN, Emerald NORMAL sight 4
HoennVictoryRoad_B2F_EventScript_Caroline::     @ trainer #3 (2,17) TRAINER_CAROLINE, Emerald NORMAL sight 2
HoennVictoryRoad_B2F_EventScript_Julie::        @ trainer #4 (35,22) TRAINER_JULIE, Emerald NORMAL sight 2
HoennVictoryRoad_B2F_EventScript_Dianne::       @ trainer #6 (25,18) TRAINER_DIANNE, Emerald NORMAL sight 2
HoennVictoryRoad_B2F_EventScript_Felix::        @ trainer #7 (25,21) TRAINER_FELIX, Emerald NORMAL sight 2
	end
