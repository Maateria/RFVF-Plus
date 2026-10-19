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

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SlateportCity_Harbor/scripts.inc
SlateportCity_Harbor_EventScript_FerryAttendant:: @ NPC #1 (8,10)
SlateportCity_Harbor_EventScript_Sailor::       @ NPC #2 (4,12)
	end
@ hoenn_import: left out: trigger (8,11) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger0; trigger (8,12) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger1; trigger (8,13) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger2; trigger (8,14) VAR_SLATEPORT_HARBOR_STATE==1 -> SlateportCity_Harbor_EventScript_AquaEscapeTrigger3
