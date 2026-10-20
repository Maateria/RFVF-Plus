.equ LOCALID_LEAGUE_NURSE, 1
.equ LOCALID_LEAGUE_GUARD_1, 3
.equ LOCALID_LEAGUE_GUARD_2, 4
.equ LOCALID_LEAGUE_SCOTT, 5

EverGrandeCity_PokemonLeague_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PokemonLeague_1F_OnFrame
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition:
	setrespawn SPAWN_EVER_GRANDE_CITY_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	call EverGrandeCity_PokemonLeague_1F_EventScript_TryShowScott
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
	setobjectxyperm LOCALID_LEAGUE_GUARD_1, 9, 2
	setobjectxyperm LOCALID_LEAGUE_GUARD_2, 10, 2
	return

EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
EverGrandeCity_PokemonLeague_1F_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	pokemartlistend

@ RFVF+: all 8 badges (Emerald checks only the skippable FLAG_BADGE06_GET; with every HM, any gym can be skipped here)
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
	lockall
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
	waitmessage
	delay 120
	specialvar VAR_RESULT, CountHoennBadges
	goto_if_lt VAR_RESULT, 8, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	closemessage
	applymovement LOCALID_LEAGUE_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
	applymovement LOCALID_LEAGUE_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
	waitmovement 0
	delay 10
	playfanfare MUS_OBTAIN_BADGE
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
	waitmessage
	waitfanfare
	closemessage
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_1
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_2
	setflag FLAG_ENTERED_ELITE_FOUR
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
	playse SE_FAILURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
	walk_down
	walk_left
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
	walk_down
	walk_right
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
	walk_left
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
	walk_right
	walk_in_place_faster_down
	step_end

@ RFVF+: Emerald's S.S. Tidal scene with Scott, here after Hoenn's Hall of Fame (user's choice, 2026-10-20)
EverGrandeCity_PokemonLeague_1F_EventScript_TryShowScott::
	setflag FLAG_TEMP_1
	goto_if_unset FLAG_HOENN_GAME_CLEAR, Common_EventScript_NopReturn
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, Common_EventScript_NopReturn
	clearflag FLAG_TEMP_1
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	goto_if_ne VAR_TEMP_2, 3, Common_EventScript_NopReturn
	goto_if_ne VAR_TEMP_3, 4, Common_EventScript_NopReturn
	setvar VAR_TEMP_4, 1
	return

EverGrandeCity_PokemonLeague_1F_OnFrame:
	map_script_2 VAR_TEMP_4, 1, EverGrandeCity_PokemonLeague_1F_EventScript_ScottScene
	.2byte 0

EverGrandeCity_PokemonLeague_1F_EventScript_ScottScene::
	lockall
	setvar VAR_TEMP_4, 0
	applymovement LOCALID_LEAGUE_SCOTT, EverGrandeCity_PokemonLeague_1F_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_ScottBattleFrontierInvite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_SCOTT, EverGrandeCity_PokemonLeague_1F_Movement_ScottLeavePlayer
	waitmovement 0
	call EverGrandeCity_PokemonLeague_1F_EventScript_ScottExit
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Scott::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonLeague_1F_Text_ScottBattleFrontierInvite, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonLeague_1F_EventScript_ScottSidestep
	applymovement LOCALID_LEAGUE_SCOTT, EverGrandeCity_PokemonLeague_1F_Movement_ScottExit
	waitmovement 0
	call EverGrandeCity_PokemonLeague_1F_EventScript_ScottExit
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_ScottSidestep::
	applymovement LOCALID_LEAGUE_SCOTT, EverGrandeCity_PokemonLeague_1F_Movement_ScottSidestep
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_ScottExit::
	playse SE_EXIT
	waitse
	removeobject LOCALID_LEAGUE_SCOTT
	setflag FLAG_MET_SCOTT_ON_SS_TIDAL
	return

EverGrandeCity_PokemonLeague_1F_Movement_ScottApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_ScottLeavePlayer:
	walk_in_place_faster_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
EverGrandeCity_PokemonLeague_1F_Movement_ScottExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_ScottSidestep:
	walk_right
	step_end
