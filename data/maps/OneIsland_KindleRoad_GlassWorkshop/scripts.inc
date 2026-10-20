OneIsland_KindleRoad_GlassWorkshop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_KindleRoad_GlassWorkshop_OnTransition
	.byte 0

	.set BLUE_FLUTE_PRICE,   250
	.set YELLOW_FLUTE_PRICE, 500
	.set RED_FLUTE_PRICE,    500
	.set WHITE_FLUTE_PRICE,  1000
	.set BLACK_FLUTE_PRICE,  1000
	.set PRETTY_CHAIR_PRICE, 6000 @ Emerald's two glass decorations (Route 113's workshop runs on this script)
	.set PRETTY_DESK_PRICE,  8000
	.set LOWEST_ASH_PRICE,   BLUE_FLUTE_PRICE

OneIsland_KindleRoad_GlassWorkshop_OnTransition:
	compare VAR_GLASS_WORKSHOP_STATE, 1
	call_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack::
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_GlassWorker::
	lock
	faceplayer
	compare VAR_GLASS_WORKSHOP_STATE, 10
	goto_if_ge OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveItemAfterNoRoom
	compare VAR_GLASS_WORKSHOP_STATE, 2
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_CheckCollectedAsh
	compare VAR_GLASS_WORKSHOP_STATE, 1
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ExplainSootSack
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_GoCollectAshWithThis, MSGBOX_DEFAULT
	giveitem ITEM_SOOT_SACK
	setvar VAR_GLASS_WORKSHOP_STATE, 1
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_ExplainSootSack::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_CheckCollectedAsh::
	checkitem ITEM_SOOT_SACK, 1
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_SootSackNotInBag
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_LetsSeeCollectedAshes, MSGBOX_DEFAULT
	compare VAR_ASH_GATHER_COUNT, LOWEST_ASH_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAsh
	message OneIsland_KindleRoad_GlassWorkshop_Text_WhichGlassItemWoudYouLike
	waitmessage
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_SootSackNotInBag::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_HaventGotYourSootSack, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseGlassItem::
	multichoice 13, 0, MULTICHOICE_GLASS_WORKSHOP_VENDOR, FALSE
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	case 0, OneIsland_KindleRoad_GlassWorkshop_EventScript_BlueFlute
	case 1, OneIsland_KindleRoad_GlassWorkshop_EventScript_YellowFlute
	case 2, OneIsland_KindleRoad_GlassWorkshop_EventScript_RedFlute
	case 3, OneIsland_KindleRoad_GlassWorkshop_EventScript_WhiteFlute
	case 4, OneIsland_KindleRoad_GlassWorkshop_EventScript_BlackFlute
	case 5, OneIsland_KindleRoad_GlassWorkshop_EventScript_PrettyChair
	case 6, OneIsland_KindleRoad_GlassWorkshop_EventScript_PrettyDesk
	case 7, OneIsland_KindleRoad_GlassWorkshop_EventScript_CancelGlassItemSelect
	case 127, OneIsland_KindleRoad_GlassWorkshop_EventScript_CancelGlassItemSelect
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_BlueFlute::
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLUE_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 10
	subvar VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_YellowFlute::
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, YELLOW_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 11
	subvar VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_RedFlute::
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, RED_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 12
	subvar VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_WhiteFlute::
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, WHITE_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 13
	subvar VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_BlackFlute::
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLACK_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 14
	subvar VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

@ VAR_0x8009 (the menu row) >= 5: a decoration
OneIsland_KindleRoad_GlassWorkshop_EventScript_PrettyChair::
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_CHAIR_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE, OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 15
	subvar VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_PrettyDesk::
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_DESK_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE, OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 16
	subvar VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveGlassDecor::
	givedecoration VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForDecor
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForDecor::
	call Common_EventScript_NoRoomForDecor
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_NoRoomInPC, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GivePrettyChair::
	setvar VAR_0x8009, 5
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_CHAIR
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GivePrettyDesk::
	setvar VAR_0x8009, 6
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_DESK
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_CancelGlassItemSelect::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_AllThatAshButDontWantAnything, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAsh::
	setvar VAR_0x800A, LOWEST_ASH_PRICE
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_1, VAR_0x800A
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_NotEnoughAshNeedX, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem::
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_2, VAR_0x800A
	message OneIsland_KindleRoad_GlassWorkshop_Text_NotEnoughAshToMakeItem
	waitmessage
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem::
	message OneIsland_KindleRoad_GlassWorkshop_Text_WhichWouldYouLike
	waitmessage
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IllMakeItemForYou, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_GLASS_FLUTE
	delay 30
	fadescreen FADE_FROM_BLACK
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_lt VAR_0x8009, 5, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveGlassFlute
	call_if_ge VAR_0x8009, 5, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveGlassDecor
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveGlassFlute::
	switch VAR_0x8008
	case ITEM_BLUE_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveBlueFlute
	case ITEM_YELLOW_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveYellowFlute
	case ITEM_RED_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveRedFlute
	case ITEM_WHITE_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveWhiteFlute
	case ITEM_BLACK_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveBlackFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveBlueFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_BLUE_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveYellowFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_YELLOW_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveRedFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_RED_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveWhiteFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_WHITE_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveBlackFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_BLACK_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute::
	call EventScript_BagIsFull
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_NoRoomInBag, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveItemAfterNoRoom::
	switch VAR_GLASS_WORKSHOP_STATE
	case 10, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveBlueFlute
	case 11, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveYellowFlute
	case 12, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveRedFlute
	case 13, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveWhiteFlute
	case 14, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveBlackFlute
	case 15, OneIsland_KindleRoad_GlassWorkshop_EventScript_GivePrettyChair
	case 16, OneIsland_KindleRoad_GlassWorkshop_EventScript_GivePrettyDesk
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveBlueFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveYellowFlute::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveRedFlute::
	setvar VAR_0x8009, 2
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveWhiteFlute::
	setvar VAR_0x8009, 3
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveBlackFlute::
	setvar VAR_0x8009, 4
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveGlassFlute
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_NinjaBoy::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_FunToBlowGlassFlute, MSGBOX_NPC
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_Girl::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_Girl, MSGBOX_NPC
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_Sign::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_Sign, MSGBOX_SIGN
	end

@ Adapted (RFVF+): Emerald's, official French text
OneIsland_KindleRoad_GlassWorkshop_Text_NoRoomInPC:
    .string "C'est vraiment bête,\n"
    .string "rheu-teu.\p"
    .string "Je vais garder l'objet. Reviens me\n"
    .string "voir plus tard, rheu-teu.$"


OneIsland_KindleRoad_GlassWorkshop_Text_GoCollectAshWithThis:
	.string "Cet endroit est recouvert de cendres\n"
	.string "volcaniques, huff-puff!\p"
	.string "Je suis spécialement doué,\n"
	.string "huff-puff.\p"
	.string "Je fabrique des objets à partir\n"
	.string "des cendres, huff-puff.\p"
	.string "Va ramasser des cendres avec ça,\nhuff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_ExplainSootSack:
	.string "Il suffit de prendre ce SAC A SUIE\n"
	.string "et de marcher dans les cendres,\l"
	.string "huff-puff.\p"
	.string "Et il se remplira de cendres\n"
	.string "volcaniques, huff-puff.\p"
	.string "Une fois que tu penses en avoir\n"
	.string "collecté beaucoup, reviens\l"
	.string "me voir, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_LetsSeeCollectedAshes:
	.string "Tu as ramassé des cendres, huff-puff?\n"
	.string "Voyons voir, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_NotEnoughAshNeedX:
	.string "Hmmm…\n"
	.string "Tu n'en a pas assez, huff-puff.\l"
	.string "Je ne peux rien fabriquer, huff-puff.\p"
	.string "Voyons… tu dois marcher encore {STR_VAR_1}\n"
	.string "pas pour que je te fabrique la\l"
	.string "FLUTE BLEUE, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_WhichGlassItemWoudYouLike:
	.string "Oh! Tu as ramassé beaucoup de cendres,\n"
	.string "huff-puff!\p"
	.string "J'vais te fabriquer quelque chose!\n"
	.string "Qu'est-ce que tu veux, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou:
	.string "Une {STR_VAR_1}, huff-puff?\n"
	.string "C'est ce que tu veux, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_WhichWouldYouLike:
	.string "Laquelle tu veux, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_IllMakeItemForYou:
	.string "Une {STR_VAR_1}, très bien,\nhuff-puff!\p"
	.string "Ok! Je vais la fabriquer, huff-puff.\n"
	.string "Juste une petite minute, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_NotEnoughAshToMakeItem:
	.string "Une {STR_VAR_1}, huff-puff?\p"
	.string "Tu n'as pas assez de cendre\n"
	.string "pour la fabriquer huff-puff.\p"
	.string "Voyons… tu dois marcher encore {STR_VAR_2}\npas "
	.string "pour que je puisse te fabriquer\l"
	.string "cet objet, huff-puff.\p"
	.string "Quel objet veux-tu que je fabrique\n"
	.string "à la place, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_AllThatAshButDontWantAnything:
	.string "Tu as ramassé toutes ces cendre\nmais "
	.string "tu ne veux rien, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_IveFinishedGlassItem:
	.string "Ah, j'ai terminé ta {STR_VAR_1}.\n"
	.string "Prends-la, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_NoRoomInBag:
	.string "Oh?\n"
	.string "Ton inventaire est plein, huff-puff.\p"
	.string "Je te la met de côté, reviens la\n"
	.string "chercher plus tard, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_HaventGotYourSootSack:
	.string "Ah? Tu n'as pas ton SAC A SUIE\n"
	.string "avec toi, huff-puff.\p"
	.string "Tu as besoin de l'avoir sur toi\n"
	.string "pour collecter des cendres, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_FunToBlowGlassFlute:
	.string "J'apprends à fabriquer des objets\n"
	.string "à partir de cendres volcaniques.\p"
	.string "Savais-tu que la FLUTE BLEUE\n"
	.string "réveil les POKéMON endormis?\p"
	.string "Mais pour moi la meilleure FLUTE\n"
	.string "pour réveiller les POKéMON endormis\l"
	.string "c'est la POKé FLUTE!\p"
	.string "…J'espère qu'un jour je saurais\n"
	.string "fabriquer des FLUTES.$"

OneIsland_KindleRoad_GlassWorkshop_Text_Girl:
	.string "Mon oncle fait aussi des FLUTES!\n"
	.string "Il habite loin d'ici, huff-puff.\p"
	.string "J'ai vu un POKéMON étourdi et\n"
	.string "tacheté quand je lui ai rendu visite!$"

OneIsland_KindleRoad_GlassWorkshop_Text_Sign:
	.string "“OBJETS EN VERRE DISPONIBLES,”\n"
	.string "Le panneau indique :\p"
	.string "FLUTE BLEUE: Réveil un POKéMON\n"
	.string "endormi.\p"
	.string "FLUTE JAUNE: Soigne un POKéMON\n"
	.string "confus.\p"
	.string "FLUTE ROUGE: Soigne un POKéMON\n"
	.string "amoureux.\p"
	.string "FLUTE BLANCHE: Fais apparaître\n"
	.string "plus de POKéMON.\p"
	.string "FLUTE NOIRE: Fais apparaître\n"
	.string "moins de POKéMON.$"

OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute:
	.string "{PLAYER} obtient la\n{STR_VAR_1}!$"

