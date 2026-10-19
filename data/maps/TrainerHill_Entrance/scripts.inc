.equ LOCALID_TRAINER_HILL_ATTENDANT, 1
.equ LOCALID_TRAINER_HILL_NURSE, 2
.equ LOCALID_TRAINER_HILL_GIRL, 4
.equ LOCALID_TRAINER_HILL_MAN, 5

TrainerHill_Entrance_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (TrainerHill_Entrance_OnResume), ON_RETURN_TO_FIELD (TrainerHill_Entrance_OnReturn), ON_TRANSITION (TrainerHill_Entrance_OnTransition), ON_LOAD (TrainerHill_Entrance_OnLoad), ON_FRAME_TABLE (TrainerHill_Entrance_OnFrame)
TrainerHill_Entrance_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

TrainerHill_Entrance_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	goto_if_set FLAG_HOENN_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox Text_PleaseComeAgain
	release
	end

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic::
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

	.align 2
TrainerHill_Entrance_Pokemart_Expanded::
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_HOENN_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_HOENN_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/TrainerHill_Entrance/scripts.inc
TrainerHill_Entrance_EventScript_Attendant::    @ NPC #1 (11,6)
TrainerHill_Entrance_EventScript_Records::      @ sign (8,10)
	end
@ hoenn_import: left out: trigger (9,6) VAR_TRAINER_HILL_IS_ACTIVE==0 -> TrainerHill_Entrance_EventScript_EntryTrigger
