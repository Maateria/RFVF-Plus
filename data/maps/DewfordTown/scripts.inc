DewfordTown_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (DewfordTown_OnTransition)
DewfordTown_EventScript_Woman::
	msgbox DewfordTown_Text_TinyIslandCommunity, MSGBOX_NPC
	end

DewfordTown_EventScript_TownSign::
	msgbox DewfordTown_Text_TownSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_GymSign::
	msgbox DewfordTown_Text_GymSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_HallSign::
	msgbox DewfordTown_Text_HallSign, MSGBOX_SIGN
	end

@ He gives his Old Rod only to a player who has none (it may come from Vermilion City) (user's choice)
DewfordTown_EventScript_OldRodFisherman::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_EventScript_AlreadyHaveOldRod
	msgbox DewfordTown_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_NotGettingItchToFish
	msgbox DewfordTown_Text_GiveYouOneOfMyRods
	giveitem ITEM_OLD_ROD
	msgbox DewfordTown_Text_ThrowInFishingAdvice
	release
	end

DewfordTown_EventScript_NotGettingItchToFish::
	msgbox DewfordTown_Text_ThatsTooBadThen
	release
	end

DewfordTown_EventScript_AlreadyHaveOldRod::
	msgbox DewfordTown_Text_AlreadyHaveOldRod
	release
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/DewfordTown/scripts.inc
DewfordTown_EventScript_TrendyPhraseBoy::       @ NPC #3 (1,6)
	end
