BattleFrontier_OutsideWest_MapScripts::
	.byte 0

@ RFVF+: the quay's Seagallop sails to Vermilion and to Hoenn's harbors (user's choice)
BattleFrontier_OutsideWest_EventScript_Sailor::
	lock
	faceplayer
	message Text_WhereDoYouWantToSail
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_BATTLE_FRONTIER
	multichoice 18, 4, MULTI_SEAGALLOP_FROM_FRONTIER, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToVermilionCity
	case 1, BattleFrontier_OutsideWest_EventScript_SailToSlateport
	case 2, BattleFrontier_OutsideWest_EventScript_SailToLilycove
	goto EventScript_CancelSail
	end

BattleFrontier_OutsideWest_EventScript_SailToSlateport::
	setvar VAR_0x8006, SEAGALLOP_SLATEPORT_CITY
	goto EventScript_SailToDest
	end

BattleFrontier_OutsideWest_EventScript_SailToLilycove::
	setvar VAR_0x8006, SEAGALLOP_LILYCOVE_CITY
	goto EventScript_SailToDest
	end
