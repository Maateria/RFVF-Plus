LilycoveCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
	.byte 0

LilycoveCity_Harbor_OnTransition:
	setescapewarp MAP_LILYCOVE_CITY, 12, 33
	end

@ Seagallop link to Vermilion (FRLG's ferry scene, src/seagallop.c), with Emerald's attendant texts
LilycoveCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_LILYCOVE_CITY
	multichoice 20, 8, MULTICHOICE_SEAGALLOP_VERMILION, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_Harbor_EventScript_SailToVermilion
	case 1, LilycoveCity_Harbor_EventScript_ExitSailSelect
	case 127, LilycoveCity_Harbor_EventScript_ExitSailSelect
	end

LilycoveCity_Harbor_EventScript_SailToVermilion::
	msgbox LilycoveCity_Harbor_Text_PleaseBoard
	setvar VAR_0x8006, SEAGALLOP_VERMILION_CITY
	goto EventScript_SetSail
	end

LilycoveCity_Harbor_EventScript_ExitSailSelect::
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime
	release
	end

LilycoveCity_Harbor_EventScript_Sailor::
	msgbox LilycoveCity_Harbor_Text_SailorFerryAvailable, MSGBOX_NPC
	end
