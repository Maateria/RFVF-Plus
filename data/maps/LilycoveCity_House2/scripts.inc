LilycoveCity_House2_MapScripts::
	.byte 0

LilycoveCity_House2_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LILYCOVE_TM44, LilycoveCity_House2_EventScript_ReceivedRest
	msgbox LilycoveCity_House2_Text_NotAwakeYetHaveThis
	giveitem ITEM_TM44
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	setflag FLAG_RECEIVED_LILYCOVE_TM44
	msgbox LilycoveCity_House2_Text_SleepIsEssential
	release
	end

LilycoveCity_House2_EventScript_ReceivedRest::
	msgbox LilycoveCity_House2_Text_SleepIsEssential
	release
	end
