.equ LOCALID_DEVON_CORP_3F_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (RustboroCity_DevonCorp_3F_OnTransition), ON_WARP_INTO_MAP_TABLE (RustboroCity_DevonCorp_3F_OnWarp), ON_FRAME_TABLE (RustboroCity_DevonCorp_3F_OnFrame)
RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

@ No letter for Steven here: Mr. Stone gives the Exp. Share on the first visit (adapted thanks)
RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	msgbox RustboroCity_DevonCorp_3F_Text_WelcomeHaveExpShare
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

@ Emerald's text once the Repeat Ball is out (no story reference)
RustboroCity_DevonCorp_3F_EventScript_Employee::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_NPC
	end

