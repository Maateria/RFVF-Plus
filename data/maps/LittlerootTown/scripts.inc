.equ LOCALID_LITTLEROOT_TWIN, 1

LittlerootTown_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (LittlerootTown_OnTransition), ON_FRAME_TABLE (LittlerootTown_OnFrame), ON_WARP_INTO_MAP_TABLE (LittlerootTown_OnWarp)
LittlerootTown_EventScript_Twin::
	lock
	faceplayer
	goto LittlerootTown_EventScript_GoodLuck

LittlerootTown_EventScript_GoodLuck::
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_FatMan::
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
	end

LittlerootTown_EventScript_Boy::
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
	end

LittlerootTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BirchsLabSign::
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BrendansHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_PlayersHouseSignMale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_BirchsHouseSignFemale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_MaysHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_BirchsHouseSignMale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_PlayersHouseSignFemale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return
@ hoenn_import: left out: trigger (10,1) VAR_LITTLEROOT_TOWN_STATE==0 -> LittlerootTown_EventScript_NeedPokemonTriggerLeft; trigger (11,1) VAR_LITTLEROOT_TOWN_STATE==0 -> LittlerootTown_EventScript_NeedPokemonTriggerRight; trigger (11,1) VAR_LITTLEROOT_TOWN_STATE==1 -> LittlerootTown_EventScript_GoSaveBirchTrigger; trigger (8,9) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger4; trigger (9,9) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger5; trigger (10,9) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger2; trigger (11,9) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger3; trigger (10,2) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger0; trigger (11,2) VAR_LITTLEROOT_TOWN_STATE==3 -> LittlerootTown_EventScript_GiveRunningShoesTrigger1
