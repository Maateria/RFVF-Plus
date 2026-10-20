.equ LOCALID_LILYCOVE_HARBOR_SS_TIDAL, 3

LilycoveCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
	.byte 0

LilycoveCity_Harbor_OnTransition:
	setescapewarp MAP_LILYCOVE_CITY, 12, 33
	end

@ Seagallop link (FRLG's ferry scene, src/seagallop.c) to Vermilion and Slateport, and to the Battle Frontier once
@ Hoenn's League is beaten (user's choice), with Emerald's attendant texts. Slateport's attendant does the same.
LilycoveCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_LILYCOVE_CITY
	goto_if_set FLAG_HOENN_GAME_CLEAR, LilycoveCity_Harbor_EventScript_ChooseWithFrontier
	multichoice 18, 6, MULTI_SEAGALLOP_FROM_LILYCOVE, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_Harbor_EventScript_SailToVermilion
	case 1, LilycoveCity_Harbor_EventScript_SailToSlateport
	goto LilycoveCity_Harbor_EventScript_ExitSailSelect
	end

LilycoveCity_Harbor_EventScript_ChooseWithFrontier::
	multichoice 18, 4, MULTI_SEAGALLOP_FROM_LILYCOVE_BF, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_Harbor_EventScript_SailToVermilion
	case 1, LilycoveCity_Harbor_EventScript_SailToSlateport
	case 2, LilycoveCity_Harbor_EventScript_SailToFrontier
	goto LilycoveCity_Harbor_EventScript_ExitSailSelect
	end

LilycoveCity_Harbor_EventScript_SailToSlateport::
	msgbox LilycoveCity_Harbor_Text_PleaseBoard
	setvar VAR_0x8006, SEAGALLOP_SLATEPORT_CITY
	goto EventScript_SetSail
	end

@ RFVF+: on board the S.S. Tidal (Emerald's crossing), the only ship to the Battle Frontier (user's choice)
LilycoveCity_Harbor_EventScript_SailToFrontier::
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_ChooseNewDestination::
	message LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_ChooseWithFrontier
	end

LilycoveCity_Harbor_EventScript_BoardFerry::
	msgbox LilycoveCity_Harbor_Text_PleaseBoard, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_LILYCOVE_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

LilycoveCity_Harbor_EventScript_BoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

LilycoveCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

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
