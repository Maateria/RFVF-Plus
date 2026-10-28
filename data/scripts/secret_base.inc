@ RFVF+: Emerald's secret bases (data/scripts/secret_base.inc, shared_secret_base.inc), the player's base only (no
@ record mixing: no other players' bases, owners or registry). French Emerald's texts: data/text/secret_base.inc.

@ A secret base entrance on a route, facing north (field_control_avatar.c BG_EVENT_SECRET_BASE)
SecretBase_EventScript_CheckEntrance::
	special GetSecretBaseTypeInFrontOfPlayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, TRUE, SecretBase_EventScript_AlreadyHasSecretBase
	checkpartymove MOVE_SECRET_POWER
	setfieldeffectargument 0, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_SECRET_POWER
	goto_if_eq VAR_0x8007, SECRET_BASE_RED_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_BROWN_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_BLUE_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_YELLOW_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_TREE, SecretBase_EventScript_Tree
	goto_if_eq VAR_0x8007, SECRET_BASE_SHRUB, SecretBase_EventScript_Shrub
	end

SecretBase_EventScript_Cave::
	lockall
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_CaveNoSecretPower
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox SecretBase_Text_IndentUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox Text_MonUsedMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
	waitstate
	goto SecretBase_EventScript_CaveEnter
	end

SecretBase_EventScript_CaveUseSecretPower::
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
	waitstate
	goto SecretBase_EventScript_CaveEnter
	end

SecretBase_EventScript_CaveNoSecretPower::
	msgbox SecretBase_Text_SmallIndentInWall, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_CaveEnter::
	msgbox SecretBase_Text_DiscoveredSmallCavern, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Tree::
	lockall
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_TreeNoSecretPower
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox SecretBase_Text_TreeUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox Text_MonUsedMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
	waitstate
	goto SecretBase_EventScript_TreeEnter
	end

SecretBase_EventScript_TreeUseSecretPower::
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
	waitstate
	goto SecretBase_EventScript_TreeEnter
	end

SecretBase_EventScript_TreeNoSecretPower::
	msgbox SecretBase_Text_TreeCanBeClimbed, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_TreeEnter::
	msgbox SecretBase_Text_VineDroppedDown, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Shrub::
	lockall
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_ShrubNoSecretPower
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox SecretBase_Text_ClumpUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox Text_MonUsedMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
	waitstate
	goto SecretBase_EventScript_ShrubEnter
	end

SecretBase_EventScript_ShrubUseSecretPower::
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
	waitstate
	goto SecretBase_EventScript_ShrubEnter
	end

SecretBase_EventScript_ShrubNoSecretPower::
	msgbox SecretBase_Text_ClumpOfGrass, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_ShrubEnter::
	msgbox SecretBase_Text_DiscoveredSmallEntrance, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

@ The entrance is open: in (the base is recorded now, cleared again if the player says no inside)
SecretBase_EventScript_InitSecretBase::
	closemessage
	playse SE_EXIT
	setvar VAR_INIT_SECRET_BASE, 0
	special SetPlayerSecretBase
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	waitstate
	end

SecretBase_EventScript_FirstEntrance::
	applymovement OBJ_EVENT_ID_PLAYER, SecretBase_Movement_EnterBase
	waitmovement 0
	setvar VAR_INIT_SECRET_BASE, 1
	msgbox SecretBase_Text_WantToMakeYourSecretBaseHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SecretBase_EventScript_SetAsBase
	closemessage
	playse SE_EXIT
	special ClearAndLeaveSecretBase
	end

SecretBase_EventScript_SetAsBase::
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	special EnterNewlyCreatedSecretBase
	waitstate
	end

SecretBase_Movement_EnterBase:
	walk_up
	walk_up
	step_end

@ Walking into the player's open entrance (field_control_avatar.c TryDoorWarp)
SecretBase_EventScript_Enter::
	lockall
	setvar VAR_INIT_SECRET_BASE, 1
	playse SE_EXIT
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	waitstate
	end

SecretBase_EventScript_AlreadyHasSecretBase::
	checkpartymove MOVE_SECRET_POWER
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_NoSecretPower
	setfieldeffectargument 0, VAR_RESULT
	setorcopyvar VAR_0x8004, VAR_RESULT
	lockall
	special GetSecretBaseNearbyMapName
	msgbox SecretBase_Text_WouldYouLikeToMoveBases, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	fadescreenswapbuffers FADE_TO_BLACK
	special MoveOutOfSecretBaseFromOutside
	closemessage
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox SecretBase_Text_MovingCompletedUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	buffermovename STR_VAR_2, MOVE_SECRET_POWER
	msgbox Text_MonUsedMove, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_0x8007, SECRET_BASE_RED_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BROWN_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BLUE_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_YELLOW_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_TREE, SecretBase_EventScript_TreeUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_SHRUB, SecretBase_EventScript_ShrubUseSecretPower
	releaseall
	end

SecretBase_EventScript_NoSecretPower::
	lockall
	goto_if_eq VAR_0x8007, SECRET_BASE_RED_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BROWN_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BLUE_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_YELLOW_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_TREE, SecretBase_EventScript_TreeNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_SHRUB, SecretBase_EventScript_ShrubNoSecretPower
	end

SecretBase_EventScript_CancelOnEntrance::
	closemessage
	releaseall
	end

@ The 24 SecretBase_* maps (shared_scripts_map). ponytail: the decorations' flags and sprites (OnTransition, OnWarp)
@ and the mats' step callback (OnResume) come with session 2
SecretBase_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SecretBase_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, SecretBase_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SecretBase_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SecretBase_OnResume
	.byte 0

SecretBase_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
	.2byte 0

SecretBase_OnTransition:
	call SecretBase_EventScript_SetDecorationFlags
	end

SecretBase_OnFrame:
	map_script_2 VAR_INIT_SECRET_BASE, 0, SecretBase_EventScript_FirstEntrance
	.2byte 0

@ Balloons and the breakable door (SecretBasePerStepCallback)
SecretBase_OnResume:
	setstepcallback STEP_CB_SECRET_BASE
	end

@ Hides the decoration objects: InitDecorations shows those of the placed dolls and cushions
SecretBase_EventScript_SetDecorationFlags::
	setflag FLAG_DECORATION_1
	setflag FLAG_DECORATION_2
	setflag FLAG_DECORATION_3
	setflag FLAG_DECORATION_4
	setflag FLAG_DECORATION_5
	setflag FLAG_DECORATION_6
	setflag FLAG_DECORATION_7
	setflag FLAG_DECORATION_8
	setflag FLAG_DECORATION_9
	setflag FLAG_DECORATION_10
	setflag FLAG_DECORATION_11
	setflag FLAG_DECORATION_12
	setflag FLAG_DECORATION_13
	setflag FLAG_DECORATION_14
	return

@ Also the Pallet Town bedroom's
SecretBase_EventScript_InitDecorations::
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special InitSecretBaseDecorationSprites
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	end

@ A doll or cushion just placed (decoration.c)
SecretBase_EventScript_SetDecoration::
	special SetDecoration
	end

@ Removes the dolls and cushions put away (decoration.c sets their flags)
SecretBase_EventScript_PutAwayDecoration::
	setvar VAR_0x8004, 0
SecretBase_EventScript_PutAwayDecorationLoop:
	special PutAwayDecorationIteration
	goto_if_eq VAR_RESULT, TRUE, SecretBase_EventScript_PutAwayDecorationEnd
	addvar VAR_0x8004, 1
	goto_if_eq VAR_0x8005, 0, SecretBase_EventScript_PutAwayDecorationLoop
	removeobject VAR_0x8006
	goto SecretBase_EventScript_PutAwayDecorationLoop
SecretBase_EventScript_PutAwayDecorationEnd:
	end

SecretBase_EventScript_SandOrnament::
	dofieldeffect FLDEFF_SAND_PILLAR
	waitstate
	end

SecretBase_EventScript_ShieldOrToyTV::
	special InteractWithShieldOrTVDecoration
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_BattleTowerShield
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_ToyTV
	goto_if_eq VAR_RESULT, 2, SecretBase_EventScript_SeedotTV
	goto_if_eq VAR_RESULT, 3, SecretBase_EventScript_SkittyTV
	end

SecretBase_EventScript_BattleTowerShield::
	msgbox SecretBase_Text_BattleTowerShield, MSGBOX_SIGN
	end

SecretBase_EventScript_ToyTV::
	msgbox SecretBase_Text_ToyTV, MSGBOX_SIGN
	end

SecretBase_EventScript_SeedotTV::
	msgbox SecretBase_Text_SeedotTV, MSGBOX_SIGN
	end

SecretBase_EventScript_SkittyTV::
	msgbox SecretBase_Text_SkittyTV, MSGBOX_SIGN
	end

@ The base PC (MB_SECRET_BASE_PC). Emerald shows REGISTRE once another player's base is registered; RFVF+ has no
@ other bases (no cable, no NPC bases): REGISTRE is always there and always empty (user's choice)
SecretBase_EventScript_PC::
	lockall
	playse SE_PC_LOGIN
	message SecretBase_Text_BootUpPC
	dofieldeffect FLDEFF_PCTURN_ON
	waitstate
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	goto SecretBase_EventScript_PCShowMainMenu
	end

SecretBase_EventScript_PCShowMainMenu::
	message SecretBase_Text_WhatWouldYouLikeToDo
	waitmessage
	multichoice 0, 0, MULTI_BASE_PC_WITH_REGISTRY, FALSE
	switch VAR_RESULT
	case 0, SecretBase_EventScript_PCDecorationMenu
	case 1, SecretBase_EventScript_PCPackUp
	case 2, SecretBase_EventScript_PCRegistryMenu
	case 3, SecretBase_EventScript_PCTurnOff
	case SCR_MENU_CANCEL, SecretBase_EventScript_PCTurnOff
	end

@ Emerald's ShowSecretBaseRegistryMenu with no registered base: its message, then the main menu again
SecretBase_EventScript_PCRegistryMenu::
	message SecretBase_Text_NoRegistry
	waitmessage
	goto SecretBase_EventScript_PCShowMainMenu
	end

@ Back from the DECORATION menu (secret_base.c)
SecretBase_EventScript_PCCancel::
	lockall
	goto SecretBase_EventScript_PCShowMainMenu
	end

SecretBase_EventScript_PCPackUp::
	msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_PCShowMainMenu
	closemessage
	special MoveOutOfSecretBase
	releaseall
	end

SecretBase_EventScript_PCDecorationMenu::
	special ShowSecretBaseDecorationMenu
	end

SecretBase_EventScript_PCTurnOff::
	special DoSecretBasePCTurnOffEffect
	closemessage
	releaseall
	end

	.include "data/text/secret_base.inc"
