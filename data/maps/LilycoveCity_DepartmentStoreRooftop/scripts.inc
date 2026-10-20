LilycoveCity_DepartmentStoreRooftop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
	.byte 0

@ Emerald's clear-out sale comes with a TV news; RFVF+: every 7th day (src/hoenn_specials.c). FLAG_TEMP_1 hides the
@ sale woman (Emerald's FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN)
LilycoveCity_DepartmentStoreRooftop_OnTransition:
	specialvar VAR_RESULT, IsLilycoveClearOutSaleDay
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman::
	setflag FLAG_TEMP_1
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_Man::
	lock
	faceplayer
	specialvar VAR_RESULT, IsLilycoveClearOutSaleDay
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman::
	lock
	faceplayer
	goto_if_questlog EventScript_ReleaseEnd
	message Text_MayIHelpYou
	waitmessage
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
	msgbox Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale::
	.2byte DECOR_MUD_BALL
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_TIRE
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SOLID_BOARD
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_STAND
	.2byte DECOR_SLIDE
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	.2byte DECOR_WAILMER_DOLL
	.2byte DECOR_RHYDON_DOLL
	pokemartlistend

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty, MSGBOX_NPC
	end

@ Copy of the Fuchsia Substitute tutor (FuchsiaCity_EventScript_SubstituteTutor, data/scripts/move_tutors.inc): same
@ rules (free once, then 5000¥ a lesson) and the same FLAG_TUTOR_SUBSTITUTE, with Emerald's lines for this tutor.
LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SUBSTITUTE, LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteReteach
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteWhichMon
	setvar VAR_0x8005, MOVETUTOR_SUBSTITUTE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteDeclined
	setflag FLAG_TUTOR_SUBSTITUTE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTaught
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTaught::
	msgbox MoveTutor_Text_SubstituteTaught
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteReteach::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SubstituteReteach
	showmoneybox 0, 0
	msgbox Text_SubstituteReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteNotEnoughMoney
	msgbox MoveTutor_Text_SubstituteWhichMon
	setvar VAR_0x8005, MOVETUTOR_SUBSTITUTE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox MoveTutor_Text_SubstituteTaught
	hidemoneybox
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteDeclined2::
	msgbox MoveTutor_Text_SubstituteDeclined
	hidemoneybox
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteNotEnoughMoney::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SubstituteNotEnoughMoney
	hidemoneybox
	release
	end

@ Same machine, drinks and prices as the Celadon Dept Store roof
LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine::
	goto CeladonCity_DepartmentStore_Roof_EventScript_VendingMachine
	end
