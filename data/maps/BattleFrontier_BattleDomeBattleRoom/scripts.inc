.equ LOCALID_DOME_ANNOUNCER, 1
.equ LOCALID_DOME_AUDIENCE_TWIN, 2
.equ LOCALID_DOME_AUDIENCE_WALKING, 6
.equ LOCALID_DOME_REFEREE, 9
.equ LOCALID_DOME_PLAYER, 13
.equ LOCALID_DOME_OPPONENT, 15

BattleFrontier_BattleDomeBattleRoom_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (BattleFrontier_BattleDomeBattleRoom_OnTransition), ON_FRAME_TABLE (BattleFrontier_BattleDomeBattleRoom_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleDomeBattleRoom_OnWarp), ON_RESUME (BattleFrontier_BattleDomeBattleRoom_OnResume)
