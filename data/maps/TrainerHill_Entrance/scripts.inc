.equ LOCALID_TRAINER_HILL_ATTENDANT, 1
.equ LOCALID_TRAINER_HILL_NURSE, 2
.equ LOCALID_TRAINER_HILL_GIRL, 4
.equ LOCALID_TRAINER_HILL_MAN, 5

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	.byte 0
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

TrainerHill_Entrance_OnTransition:
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_HoennTrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_HoennTrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	textcolor NPC_TEXT_COLOR_FEMALE
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	textcolor NPC_TEXT_COLOR_FEMALE
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	textcolor NPC_TEXT_COLOR_FEMALE
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_HOENN_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTICHOICE_YES_NO_INFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case SCR_MENU_CANCEL, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case SCR_MENU_CANCEL, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

@ Emerald's data/scripts/trainer_hill.inc (common to the floors)
TrainerHill_OnResume:
	setvar VAR_TEMP_2, 0
	trainerhill_resumetimer
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, TrainerHill_1F_EventScript_Lost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, TrainerHill_1F_EventScript_Lost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, TrainerHill_1F_EventScript_Lost
	end

TrainerHill_OnWarp:
	map_script_2 VAR_TEMP_3, 0, TrainerHill_1F_EventScript_DummyOnWarp
	.2byte 0

TrainerHill_1F_EventScript_DummyOnWarp::
	setvar VAR_TEMP_3, 1
	end  @ Missing end. By chance, the next byte (0x02 of VAR_TEMP_2) is also the id for the end cmd

TrainerHill_OnFrame:
	map_script_2 VAR_TEMP_2, 0, TrainerHill_1F_EventScript_DummyWarpToEntranceCounter
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

EventScript_TrainerHillTimer::
	lockall
	trainerhill_gettime
	msgbox TrainerHill_Entrance_Text_ChallengeTime, MSGBOX_DEFAULT
	releaseall
	end

TrainerHill_1F_EventScript_DummyWarpToEntranceCounter::
	setvar VAR_TEMP_2, 1
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_1F_EventScript_WarpSilentToEntranceCounter  @ VAR_RESULT always FALSE here
	end

@ Never reached
TrainerHill_1F_EventScript_WarpSilentToEntranceCounter::
	warpsilent MAP_TRAINER_HILL_ENTRANCE, 9, 6
	waitstate
	end

TrainerHill_1F_EventScript_Lost::
	trainerhill_settrainerflags
	trainerhill_lost
	setvar VAR_TEMP_1, 1
	end

TrainerHill_EventScript_WarpToEntranceCounter::
	setvar VAR_TEMP_1, 0
	warp MAP_TRAINER_HILL_ENTRANCE, 9, 6
	waitstate
	end

TrainerHill_1F_Movement_SetInvisible::
	set_invisible
	step_end

@ TRAINER_PHILLIP is an actual Trainer on the SS Tidal, but is used as a placeholder here
TrainerHill_EventScript_TrainerBattle::
	trainerbattle TRAINER_BATTLE_HILL, TRAINER_PHILLIP, 0, TrainerHill_Text_Placeholder, TrainerHill_Text_Placeholder
	trainerhill_postbattletext
	waitmessage
	waitbuttonpress
	closemessage
	end

@ RFVF+: the trainers' texts come from the floor data (Emerald's BattleFacility_TrainerBattle_PlaceholderText)
TrainerHill_Text_Placeholder:
	.string "$"

