.equ LOCALID_TOWER_ATTENDANT_DOUBLES, 4
.equ LOCALID_TOWER_ATTENDANT_MULTIS, 5
.equ LOCALID_TOWER_ATTENDANT_LINK_MULTIS, 6

BattleFrontier_BattleTowerLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (BattleFrontier_BattleTowerLobby_OnResume), ON_TRANSITION (BattleFrontier_BattleTowerLobby_OnTransition), ON_FRAME_TABLE (BattleFrontier_BattleTowerLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleTowerLobby_OnWarp)
BattleFrontier_BattleTowerLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded, MSGBOX_NPC
	end

BattleFrontier_BattleTowerLobby_EventScript_Boy::
	msgbox BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattleTowerLobby/scripts.inc
BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan:: @ NPC #1 (23,5)
BattleFrontier_BattleTowerLobby_EventScript_DoublesAttendant:: @ NPC #4 (10,5)
BattleFrontier_BattleTowerLobby_EventScript_MultisAttendant:: @ NPC #5 (14,5)
BattleFrontier_BattleTowerLobby_EventScript_LinkMultisAttendant:: @ NPC #6 (18,5)
BattleFrontier_BattleTowerLobby_EventScript_ShowSinglesResults:: @ sign (4,5)
BattleFrontier_BattleTowerLobby_EventScript_ShowDoublesResults:: @ sign (8,5)
BattleFrontier_BattleTowerLobby_EventScript_ShowMultisResults:: @ sign (12,5)
BattleFrontier_BattleTowerLobby_EventScript_ShowLinkMultisResults:: @ sign (16,5)
BattleFrontier_BattleTowerLobby_EventScript_RulesBoard:: @ sign (2,1)
	end
