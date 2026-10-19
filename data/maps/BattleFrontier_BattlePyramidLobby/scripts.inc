.equ LOCALID_PYRAMID_LOBBY_ATTENDANT, 1
.equ LOCALID_PYRAMID_LOBBY_HINT_GIVER, 2

BattleFrontier_BattlePyramidLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattlePyramidLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleDomeLobby_OnWarp)
BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc
BattleFrontier_BattlePyramidLobby_EventScript_Attendant:: @ NPC #1 (7,12)
BattleFrontier_BattlePyramidLobby_EventScript_HintGiver:: @ NPC #2 (14,13)
BattleFrontier_BattlePyramidLobby_EventScript_ShowResults:: @ sign (5,12)
BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard:: @ sign (1,12)
	end
