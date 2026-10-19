Route123_BerryMastersHouse_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route123_BerryMastersHouse_OnTransition)
Route123_BerryMastersHouse_EventScript_BerryMaster::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY, Route123_BerryMastersHouse_EventScript_ReceivedBerryToday
	msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry, MSGBOX_DEFAULT
	random NUM_BERRY_MASTER_BERRIES
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	msgbox Route123_BerryMastersHouse_Text_WhyBeStingyTakeAnother, MSGBOX_DEFAULT
	random NUM_BERRY_MASTER_BERRIES
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox Route123_BerryMastersHouse_Text_VisitPrettyPetalFlowerShop, MSGBOX_DEFAULT
	release
	end

Route123_BerryMastersHouse_EventScript_ReceivedBerryToday::
	msgbox Route123_BerryMastersHouse_Text_DoneForToday, MSGBOX_DEFAULT
	release
	end

@ The Berry Master's wife: ALL her berries at once (one of each, her phrase berries too) after every win against
@ Hoenn's gym leaders, Elite Four and Champion, rematches included (user's choice); no phrase to give
Route123_BerryMastersHouse_EventScript_BerryMastersWife::
	lock
	faceplayer
	goto_if_eq VAR_BERRY_MASTERS_WIFE_GIFTS, 0, Route123_BerryMastersHouse_EventScript_WifeNoGift
	msgbox Route123_BerryMastersHouse_Text_TakeAllMyBerries
	specialvar VAR_RESULT, GiveBerryMastersWifeBerries
	goto_if_eq VAR_RESULT, 0, Route123_BerryMastersHouse_EventScript_WifeBagFull
	subvar VAR_BERRY_MASTERS_WIFE_GIFTS, 1
	playfanfare MUS_OBTAIN_BERRY
	message Route123_BerryMastersHouse_Text_ReceivedAllBerries
	waitmessage
	waitfanfare
Route123_BerryMastersHouse_EventScript_WifeNoGift::
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife
	release
	end

Route123_BerryMastersHouse_EventScript_WifeBagFull::
	msgbox Text_TooBadBagFull
	release
	end

