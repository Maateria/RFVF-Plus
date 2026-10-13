SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SlateportCity_OceanicMuseum_1F/scripts.inc
SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant:: @ NPC #1 (7,7)
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1:: @ NPC #3 (4,2)
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2:: @ NPC #4 (10,2)
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3:: @ NPC #5 (17,7)
SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4:: @ NPC #6 (18,8)
SlateportCity_OceanicMuseum_1F_EventScript_Reporter:: @ NPC #7 (7,4)
SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment:: @ sign (2,7)
SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment:: @ sign (2,4)
SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay:: @ sign (9,1)
SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay:: @ sign (12,1)
SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1:: @ sign (15,4)
SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2:: @ sign (18,4)
SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3:: @ sign (18,7)
SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay:: @ sign (2,1)
SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine:: @ sign (16,1)
	end
@ hoenn_import: left out: trigger (9,7) VAR_SLATEPORT_MUSEUM_1F_STATE==0 -> SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft; trigger (10,7) VAR_SLATEPORT_MUSEUM_1F_STATE==0 -> SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight
