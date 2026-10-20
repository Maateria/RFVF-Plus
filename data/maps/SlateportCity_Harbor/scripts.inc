.equ LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 4
.equ LOCALID_SLATEPORT_HARBOR_SS_TIDAL, 5

SlateportCity_Harbor_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (SlateportCity_Harbor_OnTransition)
SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

@ Capt. Stern: the story is over; he gives BOTH Deep Sea items for the Scanner (user's choice), texts adjusted
SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_EXCHANGED_SCANNER, SlateportCity_Harbor_EventScript_TradedScanner
	msgbox SlateportCity_Harbor_Text_FerryIsFinished
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	msgbox SlateportCity_Harbor_Text_TradeScannerForBoth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_DeclineTrade
	checkitemspace ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	checkitemspace ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	giveitem ITEM_DEEP_SEA_TOOTH
	giveitem ITEM_DEEP_SEA_SCALE
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern
	setflag FLAG_EXCHANGED_SCANNER
SlateportCity_Harbor_EventScript_TradedScanner::
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch
	release
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow
	release
	end

@ RFVF+: Lilycove's Seagallop link (LilycoveCity_Harbor_EventScript_FerryAttendant), from here: Vermilion, Lilycove,
@ the Battle Frontier once Hoenn's League is beaten; Emerald's attendant texts
SlateportCity_Harbor_EventScript_FerryAttendant:: @ NPC #1 (8,10)
	lock
	faceplayer
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_SLATEPORT_CITY
	goto_if_set FLAG_HOENN_GAME_CLEAR, SlateportCity_Harbor_EventScript_ChooseWithFrontier
	multichoice 18, 6, MULTI_SEAGALLOP_FROM_SLATEPORT, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_SailToVermilion
	case 1, SlateportCity_Harbor_EventScript_SailToLilycove
	goto SlateportCity_Harbor_EventScript_ExitSailSelect
	end

SlateportCity_Harbor_EventScript_ChooseWithFrontier::
	multichoice 18, 4, MULTI_SEAGALLOP_FROM_SLATEPORT_BF, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_SailToVermilion
	case 1, SlateportCity_Harbor_EventScript_SailToLilycove
	case 2, SlateportCity_Harbor_EventScript_SailToFrontier
	goto SlateportCity_Harbor_EventScript_ExitSailSelect
	end

SlateportCity_Harbor_EventScript_SailToVermilion::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry
	setvar VAR_0x8006, SEAGALLOP_VERMILION_CITY
	goto EventScript_SetSail
	end

SlateportCity_Harbor_EventScript_SailToLilycove::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry
	setvar VAR_0x8006, SEAGALLOP_LILYCOVE_CITY
	goto EventScript_SetSail
	end

@ RFVF+: on board the S.S. Tidal (Emerald's crossing), the only ship to the Battle Frontier (user's choice)
SlateportCity_Harbor_EventScript_SailToFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseWithFrontier
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_ExitSailSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime
	release
	end

@ Emerald's line when no abnormal weather is reported (the reports come with batch 3)
SlateportCity_Harbor_EventScript_Sailor::       @ NPC #2 (4,12)
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_NPC
	end
@ hoenn_import: left out: trigger (8,11) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger0; trigger (8,12) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger1; trigger (8,13) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger2; trigger (8,14) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger3
