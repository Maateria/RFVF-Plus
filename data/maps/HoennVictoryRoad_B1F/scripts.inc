HoennVictoryRoad_B1F_MapScripts::
	.byte 0
HoennVictoryRoad_B1F_EventScript_ItemTMPsychic:: @ item ball, works (FLAG_ITEM_HOENN_VICTORY_ROAD_B1F_TM_PSYCHIC)
	finditem ITEM_TM29_PSYCHIC
	end
HoennVictoryRoad_B1F_EventScript_ItemFullRestore:: @ item ball, works (FLAG_ITEM_HOENN_VICTORY_ROAD_B1F_FULL_RESTORE)
	finditem ITEM_FULL_RESTORE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/VictoryRoad_B1F/scripts.inc
HoennVictoryRoad_B1F_EventScript_Samuel::       @ trainer #14 (37,12) TRAINER_SAMUEL, Emerald NORMAL sight 3
HoennVictoryRoad_B1F_EventScript_Shannon::      @ trainer #15 (26,16) TRAINER_SHANNON, Emerald NORMAL sight 4
HoennVictoryRoad_B1F_EventScript_Michelle::     @ trainer #16 (5,21) TRAINER_MICHELLE, Emerald NORMAL sight 2
HoennVictoryRoad_B1F_EventScript_Mitchell::     @ trainer #20 (14,16) TRAINER_MITCHELL, Emerald NORMAL sight 4
HoennVictoryRoad_B1F_EventScript_Halle::        @ trainer #21 (14,20) TRAINER_HALLE, Emerald NORMAL sight 3
	end
