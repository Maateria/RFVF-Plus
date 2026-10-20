MauvilleCity_GameCorner_MapScripts::
	.byte 0

@ pokeemerald data/maps/MauvilleCity_GameCorner/scripts.inc. RFVF+: the doll counter and the girl give Hoenn's
@ starters (level 5, the PC if the party is full): this game has no decorations
	@ Game Corner prices
	.set TM_DOUBLE_TEAM_COINS, 1500
	.set TM_PSYCHIC_COINS, 3500
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_ICE_BEAM_COINS, 4000
	.set STARTER_COINS, 1000
	.set DOLL_COINS, 1000
	.set STARTER_LEVEL, 5
	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

MauvilleCity_GameCorner_EventScript_CoinsClerk:: @ NPC #3 (11,2)
	lock
	faceplayer
	goto_if_questlog EventScript_ReleaseEnd
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 0, 5
	multichoicedefault 15, 0, MULTI_GAME_CORNER_HOENN_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	goto MauvilleCity_GameCorner_EventScript_BoughtCoins
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	goto MauvilleCity_GameCorner_EventScript_BoughtCoins
	end

MauvilleCity_GameCorner_EventScript_BoughtCoins::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_RS_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_CloseCoinsClerk
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase::
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_CloseCoinsClerk
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_CloseCoinsClerk
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
MauvilleCity_GameCorner_EventScript_CloseCoinsClerk::
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

@ Emerald's doll counter: Hoenn's starters here
MauvilleCity_GameCorner_EventScript_PrizeCornerDolls:: @ NPC #4 (14,2)
	lock
	faceplayer
	goto_if_questlog EventScript_ReleaseEnd
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_ReleaseEnd
	showcoinsbox 0, 0
MauvilleCity_GameCorner_EventScript_ChooseStarterPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	multichoice 11, 0, MULTI_GAME_CORNER_HOENN_STARTERS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_PrizeTreecko
	case 1, MauvilleCity_GameCorner_EventScript_PrizeTorchic
	case 2, MauvilleCity_GameCorner_EventScript_PrizeMudkip
	case 3, MauvilleCity_GameCorner_EventScript_PrizeTreeckoDoll
	case 4, MauvilleCity_GameCorner_EventScript_PrizeTorchicDoll
	case 5, MauvilleCity_GameCorner_EventScript_PrizeMudkipDoll
	goto MauvilleCity_GameCorner_EventScript_CancelPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeTreecko::
	setvar VAR_TEMP_1, SPECIES_TREECKO
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeTorchic::
	setvar VAR_TEMP_1, SPECIES_TORCHIC
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeMudkip::
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize
	end

@ Emerald's doll prizes, next to the starters (user's choice, 2026-10-19)
MauvilleCity_GameCorner_EventScript_PrizeTreeckoDoll::
	setvar VAR_TEMP_1, DECOR_TREECKO_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeTorchicDoll::
	setvar VAR_TEMP_1, DECOR_TORCHIC_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeMudkipDoll::
	setvar VAR_TEMP_1, DECOR_MUDKIP_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
	end

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
	bufferdecorationname STR_VAR_1, VAR_TEMP_1
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelPrize
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForStarter
	bufferdecorationname STR_VAR_2, VAR_TEMP_1
	checkdecorspace VAR_TEMP_1
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration VAR_TEMP_1
	updatecoinsbox 0, 0
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseStarterPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
	call Common_EventScript_NoRoomForDecor
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelPrize
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, STARTER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForStarter
	givemon VAR_TEMP_1, STARTER_LEVEL, ITEM_NONE
	goto_if_eq VAR_RESULT, 2, MauvilleCity_GameCorner_EventScript_NoRoomForStarter
	copyvar VAR_TEMP_3, VAR_RESULT
	removecoins STARTER_COINS
	updatecoinsbox 0, 0
	call MauvilleCity_GameCorner_EventScript_ReceivedStarter
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForStarter::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseStarterPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarter::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_NoMoreRoomForPokemon, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_CancelPrize::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

@ givemon's result in VAR_TEMP_3 (0 party, 1 PC), the species in VAR_TEMP_1: Celadon's prize Pokémon (nickname,
@ RFVF+'s Nuzlocke mode names it anyway)
MauvilleCity_GameCorner_EventScript_ReceivedStarter::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	callnative CheckNuzlockeMode
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_NicknameStarter
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_StarterNoNickname
MauvilleCity_GameCorner_EventScript_NicknameStarter::
	goto_if_eq VAR_TEMP_3, 1, MauvilleCity_GameCorner_EventScript_NicknameBoxStarter
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call EventScript_ChangePokemonNickname
	return

MauvilleCity_GameCorner_EventScript_NicknameBoxStarter::
	call EventScript_NameReceivedBoxMon
	call EventScript_TransferredToPC
	return

MauvilleCity_GameCorner_EventScript_StarterNoNickname::
	goto_if_eq VAR_TEMP_3, 1, MauvilleCity_GameCorner_EventScript_StarterToPC
	return

MauvilleCity_GameCorner_EventScript_StarterToPC::
	call EventScript_TransferredToPC
	return

MauvilleCity_GameCorner_EventScript_PrizeCornerTMs:: @ NPC #9 (13,2)
	lock
	faceplayer
	goto_if_questlog EventScript_ReleaseEnd
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_ReleaseEnd
	showcoinsbox 0, 0
MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	multichoice 11, 0, MULTI_GAME_CORNER_HOENN_TMS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TMDoubleTeam
	case 1, MauvilleCity_GameCorner_EventScript_TMPsychic
	case 2, MauvilleCity_GameCorner_EventScript_TMFlamethrower
	case 3, MauvilleCity_GameCorner_EventScript_TMThunderbolt
	case 4, MauvilleCity_GameCorner_EventScript_TMIceBeam
	goto MauvilleCity_GameCorner_EventScript_CancelPrize
	end

MauvilleCity_GameCorner_EventScript_TMDoubleTeam::
	setvar VAR_0x8004, ITEM_TM32_DOUBLE_TEAM
	setvar VAR_TEMP_2, TM_DOUBLE_TEAM_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
	end

MauvilleCity_GameCorner_EventScript_TMPsychic::
	setvar VAR_0x8004, ITEM_TM29_PSYCHIC
	setvar VAR_TEMP_2, TM_PSYCHIC_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
	end

MauvilleCity_GameCorner_EventScript_TMFlamethrower::
	setvar VAR_0x8004, ITEM_TM35_FLAMETHROWER
	setvar VAR_TEMP_2, TM_FLAMETHROWER_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
	end

MauvilleCity_GameCorner_EventScript_TMThunderbolt::
	setvar VAR_0x8004, ITEM_TM24_THUNDERBOLT
	setvar VAR_TEMP_2, TM_THUNDERBOLT_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
	end

MauvilleCity_GameCorner_EventScript_TMIceBeam::
	setvar VAR_0x8004, ITEM_TM13_ICE_BEAM
	setvar VAR_TEMP_2, TM_ICE_BEAM_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
	end

MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
	checkitem VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_AlreadyHaveTM
	special BufferTMHMMoveName              @ FRLG's: into STR_VAR_1 (Emerald's: STR_VAR_2)
	bufferstring STR_VAR_2, gStringVar1
	bufferitemname STR_VAR_1, VAR_0x8004
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelPrize
	checkcoins VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, VAR_TEMP_2, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins VAR_TEMP_2
	additem VAR_0x8004
	updatecoinsbox 0, 0
	playse SE_RS_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_AlreadyHaveTM::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouAlreadyHaveThisTM, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_ReleaseEnd::
	release
	end

MauvilleCity_GameCorner_EventScript_Woman2::    @ NPC #1 (12,7)
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman:: @ NPC #2 (16,5)
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

@ Emerald's girl gives the doll of the player's starter; RFVF+: she offers one of Hoenn's starters
MauvilleCity_GameCorner_EventScript_Girl::      @ NPC #5 (7,3)
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameMonWantOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	message MauvilleCity_GameCorner_Text_WhichOneDoYouWant
	waitmessage
	multichoice 17, 6, MULTI_HOENN_STARTERS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_GirlTreecko
	case 1, MauvilleCity_GameCorner_EventScript_GirlTorchic
	case 2, MauvilleCity_GameCorner_EventScript_GirlMudkip
	goto MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GirlTreecko::
	setvar VAR_TEMP_1, SPECIES_TREECKO
	goto MauvilleCity_GameCorner_EventScript_GiveStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GirlTorchic::
	setvar VAR_TEMP_1, SPECIES_TORCHIC
	goto MauvilleCity_GameCorner_EventScript_GiveStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GirlMudkip::
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	goto MauvilleCity_GameCorner_EventScript_GiveStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveStarterDoll::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, MauvilleCity_GameCorner_EventScript_GiveStarterDollRoom
	specialvar VAR_RESULT, IsThereRoomInAnyBoxForMorePokemon
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
MauvilleCity_GameCorner_EventScript_GiveStarterDollRoom::
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givemon VAR_TEMP_1, STARTER_LEVEL, ITEM_NONE
	goto_if_eq VAR_RESULT, 2, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	copyvar VAR_TEMP_3, VAR_RESULT
	setflag FLAG_RECEIVED_STARTER_DOLL
	call MauvilleCity_GameCorner_EventScript_ReceivedStarter
	call EventScript_RestorePrevTextColor
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_NoMoreRoomForPokemon, MSGBOX_DEFAULT
	call EventScript_RestorePrevTextColor
	msgbox MauvilleCity_GameCorner_Text_YouWantOneButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_DontBeNegativeTakeOne, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM::  @ NPC #6 (19,4)
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_RS_SHOP
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal::
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan::    @ NPC #7 (20,8)
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook::      @ NPC #8 (6,8)
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man::       @ NPC #10 (1,7)
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac::    @ NPC #11 (9,8)
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman::     @ NPC #12 (4,6)
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

@ Emerald's slot machines (src/slot_machine_hoenn.c)
MauvilleCity_GameCorner_EventScript_SlotMachine0:: @ sign (2,6)
	setvar VAR_0x8004, 0
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1:: @ sign (2,8)
	setvar VAR_0x8004, 1
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2:: @ sign (2,9)
	setvar VAR_0x8004, 2
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3:: @ sign (3,7)
	setvar VAR_0x8004, 3
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4:: @ sign (3,8)
	setvar VAR_0x8004, 4
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5:: @ sign (3,9)
	setvar VAR_0x8004, 5
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6:: @ sign (7,6)
	setvar VAR_0x8004, 6
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7:: @ sign (7,7)
	setvar VAR_0x8004, 7
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8:: @ sign (7,9)
	setvar VAR_0x8004, 8
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9:: @ sign (8,6)
	setvar VAR_0x8004, 9
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10:: @ sign (8,7)
	setvar VAR_0x8004, 10
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11:: @ sign (8,9)
	setvar VAR_0x8004, 11
	goto MauvilleCity_GameCorner_EventScript_PlaySlots
	end

@ Emerald repeats this in each machine's script
MauvilleCity_GameCorner_EventScript_PlaySlots::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase::
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end
