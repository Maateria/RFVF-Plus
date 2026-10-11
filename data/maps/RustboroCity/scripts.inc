.equ LOCALID_RUSTBORO_LITTLE_BOY, 7
.equ LOCALID_RUSTBORO_LITTLE_GIRL, 8

RustboroCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (RustboroCity_OnTransition), ON_FRAME_TABLE (RustboroCity_OnFrame)
RustboroCity_EventScript_ItemXDefend::          @ item ball, works (FLAG_ITEM_RUSTBORO_CITY_X_DEFEND)
	finditem ITEM_X_DEFEND
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/RustboroCity/scripts.inc
RustboroCity_EventScript_Woman::                @ NPC #1 (22,34)
RustboroCity_EventScript_FatMan::               @ NPC #2 (19,13)
RustboroCity_EventScript_NinjaBoy::             @ NPC #3 (25,37)
RustboroCity_EventScript_Twin::                 @ NPC #4 (21,46)
RustboroCity_EventScript_Boy2::                 @ NPC #5 (12,45)
RustboroCity_EventScript_Man1::                 @ NPC #6 (26,23)
RustboroCity_EventScript_LittleBoy::            @ NPC #7 (24,51)
RustboroCity_EventScript_LittleGirl::           @ NPC #8 (25,51)
RustboroCity_EventScript_DevonEmployee2::       @ NPC #9 (13,34)
RustboroCity_EventScript_Man2::                 @ NPC #11 (19,27)
RustboroCity_EventScript_Boy1::                 @ NPC #12 (31,36)
RustboroCity_EventScript_GymSign::              @ sign (23,19)
RustboroCity_EventScript_TrainersSchoolSign::   @ sign (25,35)
RustboroCity_EventScript_CitySign::             @ sign (19,49)
RustboroCity_EventScript_DevonCorpSign::        @ sign (17,20)
RustboroCity_EventScript_TunnelSign::           @ sign (30,8)
RustboroCity_EventScript_CuttersHouseSign::     @ sign (12,38)
	end
@ hoenn_import: left out: trigger (23,20) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger0; trigger (23,21) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger1; trigger (23,22) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger2; trigger (23,23) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger3; trigger (23,24) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger4; trigger (30,9) VAR_RUSTBORO_CITY_STATE==2 -> RustboroCity_EventScript_HelpGetGoodsTrigger0; trigger (29,10) VAR_RUSTBORO_CITY_STATE==2 -> RustboroCity_EventScript_HelpGetGoodsTrigger1; trigger (30,11) VAR_RUSTBORO_CITY_STATE==2 -> RustboroCity_EventScript_HelpGetGoodsTrigger2; trigger (30,12) VAR_RUSTBORO_CITY_STATE==2 -> RustboroCity_EventScript_HelpGetGoodsTrigger3; trigger (30,9) VAR_RUSTBORO_CITY_STATE==4 -> RustboroCity_EventScript_ReturnGoodsTrigger0; trigger (31,10) VAR_RUSTBORO_CITY_STATE==4 -> RustboroCity_EventScript_ReturnGoodsTrigger1; trigger (30,11) VAR_RUSTBORO_CITY_STATE==4 -> RustboroCity_EventScript_ReturnGoodsTrigger2; trigger (30,12) VAR_RUSTBORO_CITY_STATE==4 -> RustboroCity_EventScript_ReturnGoodsTrigger3; trigger (12,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger0; trigger (13,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger1; trigger (14,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger2; trigger (15,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger3; trigger (16,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger4; trigger (17,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger5; trigger (18,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger6; trigger (19,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger7
