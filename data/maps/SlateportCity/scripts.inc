.equ LOCALID_SLATEPORT_FAT_MAN, 1
.equ LOCALID_SLATEPORT_MAN_1, 2
.equ LOCALID_SLATEPORT_RICH_BOY, 3
.equ LOCALID_SLATEPORT_COOK, 5
.equ LOCALID_SLATEPORT_OLD_WOMAN, 6
.equ LOCALID_SLATEPORT_GIRL, 7
.equ LOCALID_SLATEPORT_ENERGY_GURU, 19

SlateportCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (SlateportCity_OnTransition), ON_FRAME_TABLE (SlateportCity_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SlateportCity/scripts.inc
SlateportCity_EventScript_FatMan::              @ NPC #1 (21,11)
SlateportCity_EventScript_Man1::                @ NPC #2 (34,29)
SlateportCity_EventScript_RichBoy::             @ NPC #3 (5,13)
SlateportCity_EventScript_Woman1::              @ NPC #4 (26,29)
SlateportCity_EventScript_Cook::                @ NPC #5 (5,43)
SlateportCity_EventScript_OldWoman::            @ NPC #6 (20,37)
SlateportCity_EventScript_Girl::                @ NPC #7 (8,42)
SlateportCity_EventScript_Sailor1::             @ NPC #8 (37,41)
SlateportCity_EventScript_Sailor2::             @ NPC #9 (28,46)
SlateportCity_EventScript_PokefanF::            @ NPC #10 (9,50)
SlateportCity_EventScript_Man2::                @ NPC #11 (16,46)
SlateportCity_EventScript_Maniac::              @ NPC #12 (8,24)
SlateportCity_EventScript_Woman2::              @ NPC #13 (15,31)
SlateportCity_EventScript_DecorClerk::          @ NPC #14 (6,38)
SlateportCity_EventScript_DollClerk::           @ NPC #15 (5,51)
SlateportCity_EventScript_Man3::                @ NPC #16 (34,51)
SlateportCity_EventScript_EffortRibbonWoman::   @ NPC #17 (4,47)
SlateportCity_EventScript_PowerTMClerk::        @ NPC #18 (11,47)
SlateportCity_EventScript_EnergyGuru::          @ NPC #19 (5,47)
SlateportCity_EventScript_BerryPowderClerk::    @ NPC #20 (11,37)
SlateportCity_EventScript_NameRatersHouseSign:: @ sign (8,19)
SlateportCity_EventScript_HarborSign::          @ sign (24,12)
SlateportCity_EventScript_MarketSign::          @ sign (14,51)
SlateportCity_EventScript_OceanicMuseumSign::   @ sign (26,26)
SlateportCity_EventScript_CitySign::            @ sign (16,22)
SlateportCity_EventScript_PokemonFanClubSign::  @ sign (8,26)
SlateportCity_EventScript_BattleTentSign::      @ sign (7,13)
SlateportCity_EventScript_SternsShipyardSign::  @ sign (23,38)
SlateportCity_EventScript_BerryCrushRankingsSign:: @ sign (10,36)
	end
@ hoenn_import: left out: trigger (10,13) VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE==2 -> SlateportCity_EventScript_ScottBattleTentScene
