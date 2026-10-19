MauvilleCity_BikeShop_MapScripts::
	.byte 0

@ RFVF+: Rodolphe does not give a Mach or an Acro Bike, he upgrades the Bicycle: FLAG_BIKE_UPGRADED gives it the moves
@ of both (src/bike.c). His greeting is Emerald's; the rest is RFVF+'s
MauvilleCity_BikeShop_EventScript_Rydel::       @ NPC #1 (2,5)
	lock
	faceplayer
	goto_if_set FLAG_BIKE_UPGRADED, MauvilleCity_BikeShop_EventScript_AlreadyUpgraded
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	checkitem ITEM_BICYCLE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_BikeShop_EventScript_NoBike
	msgbox MauvilleCity_BikeShop_Text_LetMeUpgradeYourBike, MSGBOX_DEFAULT
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox MauvilleCity_BikeShop_Text_HandedOverBike, MSGBOX_DEFAULT
	setflag FLAG_BIKE_UPGRADED
	playfanfare MUS_OBTAIN_KEY_ITEM
	message MauvilleCity_BikeShop_Text_BikeUpgraded
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	msgbox MauvilleCity_BikeShop_Text_HowToRide, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_NoBike::
	msgbox MauvilleCity_BikeShop_Text_NoBikeWhereYouComeFrom, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_AlreadyUpgraded::
	msgbox MauvilleCity_BikeShop_Text_HowsYourBike, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_HowToRide, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_Assistant::   @ NPC #2 (7,6)
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

@ RFVF+: Emerald's handbooks describe its two bikes; these sum up the upgraded Bicycle's moves
MauvilleCity_BikeShop_EventScript_MachBikeHandbook:: @ sign (8,1)
	msgbox MauvilleCity_BikeShop_Text_MachHandbook, MSGBOX_SIGN
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook:: @ sign (11,1)
	msgbox MauvilleCity_BikeShop_Text_AcroHandbook, MSGBOX_SIGN
	end
