.equ LOCALID_SLATEPORT_FAT_MAN, 1
.equ LOCALID_SLATEPORT_MAN_1, 2
.equ LOCALID_SLATEPORT_RICH_BOY, 3
.equ LOCALID_SLATEPORT_COOK, 5
.equ LOCALID_SLATEPORT_OLD_WOMAN, 6
.equ LOCALID_SLATEPORT_GIRL, 7
.equ LOCALID_SLATEPORT_ENERGY_GURU, 19

SlateportCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (SlateportCity_OnTransition), ON_FRAME_TABLE (SlateportCity_OnFrame)
SlateportCity_EventScript_FatMan::
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto SlateportCity_EventScript_Woman1AquaGone

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_PowerTMClerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs::
	.2byte ITEM_TM10_HIDDEN_POWER
	.2byte ITEM_TM43_SECRET_POWER
	pokemartlistend

SlateportCity_EventScript_EnergyGuru::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru::
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_HOENN_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_HOENN_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_HOENN_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

@ Emerald's clerk; the Powder Jar is Kanto's (FLAG_GOT_POWDER_JAR, Cerulean City) and so is the exchange list
SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries
	giveitem ITEM_POWDER_JAR
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	setflag FLAG_GOT_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, Script_HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder
	special DisplayBerryPowderVendorMenu
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	goto_if_questlog EventScript_ReleaseEnd
	message Text_MayIHelpYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls::
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox SlateportCity_Text_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

@ Emerald's: he sells only once the player has Secret Power (the Route 111 man's TM, or a base made)
SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_questlog EventScript_ReleaseEnd
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message Text_MayIHelpYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
SlateportCity_PokemartDecor::
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

@ hoenn_import: left out: trigger (10,13) VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE==2 -> SlateportCity_EventScript_ScottBattleTentScene
