HoennVictoryRoad_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (HoennVictoryRoad_1F_OnTransition)
HoennVictoryRoad_1F_EventScript_ItemMaxElixir:: @ item ball, works (FLAG_ITEM_HOENN_VICTORY_ROAD_1F_MAX_ELIXIR)
	finditem ITEM_MAX_ELIXIR
	end
HoennVictoryRoad_1F_EventScript_ItemPPUp::      @ item ball, works (FLAG_ITEM_HOENN_VICTORY_ROAD_1F_PP_UP)
	finditem ITEM_PP_UP
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/VictoryRoad_1F/scripts.inc
HoennVictoryRoad_1F_EventScript_Edgar::         @ trainer #1 (33,22) TRAINER_EDGAR, Emerald NORMAL sight 3
HoennVictoryRoad_1F_EventScript_Hope::          @ trainer #2 (6,15) TRAINER_HOPE, Emerald NORMAL sight 4
HoennVictoryRoad_1F_EventScript_Albert::        @ trainer #3 (27,34) TRAINER_ALBERT, Emerald NORMAL sight 3
HoennVictoryRoad_1F_EventScript_ExitWally::     @ NPC #6 (31,9)
HoennVictoryRoad_1F_EventScript_Katelynn::      @ trainer #7 (29,17) TRAINER_KATELYNN, Emerald NORMAL sight 2
HoennVictoryRoad_1F_EventScript_Quincy::        @ trainer #8 (32,17) TRAINER_QUINCY, Emerald NORMAL sight 2
	end
@ hoenn_import: left out: trigger (2,23) VAR_VICTORY_ROAD_1F_STATE==0 -> HoennVictoryRoad_1F_EventScript_WallyBattleTrigger1; trigger (3,23) VAR_VICTORY_ROAD_1F_STATE==0 -> HoennVictoryRoad_1F_EventScript_WallyBattleTrigger2
