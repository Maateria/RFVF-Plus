.equ LOCALID_DOME_ANNOUNCER, 1
.equ LOCALID_DOME_AUDIENCE_TWIN, 2
.equ LOCALID_DOME_AUDIENCE_WALKING, 6
.equ LOCALID_DOME_REFEREE, 9
.equ LOCALID_DOME_PLAYER, 13
.equ LOCALID_DOME_OPPONENT, 15

BattleFrontier_BattleDomeBattleRoom_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (BattleFrontier_BattleDomeBattleRoom_OnTransition), ON_FRAME_TABLE (BattleFrontier_BattleDomeBattleRoom_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleDomeBattleRoom_OnWarp), ON_RESUME (BattleFrontier_BattleDomeBattleRoom_OnResume)

@ RFVF+: Emerald's, shared with the Palace/Arena battle rooms (batch 6 session 3; session 5 ports the rest)
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RED_NORMAL
	return

BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_GREEN_NORMAL
	return

BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible:
	set_invisible
	step_end
