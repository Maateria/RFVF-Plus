.equ LOCALID_RUSTBORO_LITTLE_BOY, 7
.equ LOCALID_RUSTBORO_LITTLE_GIRL, 8

RustboroCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (RustboroCity_OnTransition), ON_FRAME_TABLE (RustboroCity_OnFrame)
RustboroCity_EventScript_ItemXDefend::          @ item ball, works (FLAG_ITEM_RUSTBORO_CITY_X_DEFEND)
	finditem ITEM_X_DEFEND
	end
RustboroCity_EventScript_Woman::
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
	end

RustboroCity_EventScript_FatMan::
	lock
	faceplayer
	goto RustboroCity_EventScript_FatManSawGrunt

RustboroCity_EventScript_FatManSawGrunt::
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_NinjaBoy::
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
	end

RustboroCity_EventScript_Twin::
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
	end

RustboroCity_EventScript_Boy2::
	lock
	faceplayer
	goto RustboroCity_EventScript_Boy2BrineyLeftTunnel

RustboroCity_EventScript_Boy2BrineyLeftTunnel::
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Man1::
	lock
	faceplayer
	goto_if_set FLAG_HOENN_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Man1HaveBadge::
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_DevonEmployee2::
	lock
	faceplayer
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Man2::
	lock
	faceplayer
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy1::
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign::
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign::
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TunnelSign::
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign::
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end
@ hoenn_import: left out: trigger (23,20) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger0; trigger (23,21) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger1; trigger (23,22) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger2; trigger (23,23) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger3; trigger (23,24) VAR_RUSTBORO_CITY_STATE==1 -> RustboroCity_EventScript_StolenGoodsTrigger4; trigger (30,9) VAR_RUSTBORO_CITY_STATE==2 -> RustboroCity_EventScript_HelpGetGoodsTrigger0; trigger (29,10) VAR_RUSTBORO_CITY_STATE==2 -> RustboroCity_EventScript_HelpGetGoodsTrigger1; trigger (30,11) VAR_RUSTBORO_CITY_STATE==2 -> RustboroCity_EventScript_HelpGetGoodsTrigger2; trigger (30,12) VAR_RUSTBORO_CITY_STATE==2 -> RustboroCity_EventScript_HelpGetGoodsTrigger3; trigger (30,9) VAR_RUSTBORO_CITY_STATE==4 -> RustboroCity_EventScript_ReturnGoodsTrigger0; trigger (31,10) VAR_RUSTBORO_CITY_STATE==4 -> RustboroCity_EventScript_ReturnGoodsTrigger1; trigger (30,11) VAR_RUSTBORO_CITY_STATE==4 -> RustboroCity_EventScript_ReturnGoodsTrigger2; trigger (30,12) VAR_RUSTBORO_CITY_STATE==4 -> RustboroCity_EventScript_ReturnGoodsTrigger3; trigger (12,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger0; trigger (13,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger1; trigger (14,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger2; trigger (15,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger3; trigger (16,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger4; trigger (17,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger5; trigger (18,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger6; trigger (19,53) VAR_RUSTBORO_CITY_STATE==7 -> RustboroCity_EventScript_RivalTrigger7
