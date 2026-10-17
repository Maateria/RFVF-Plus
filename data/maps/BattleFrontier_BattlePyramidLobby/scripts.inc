.equ LOCALID_PYRAMID_LOBBY_ATTENDANT, 1
.equ LOCALID_PYRAMID_LOBBY_HINT_GIVER, 2

BattleFrontier_BattlePyramidLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattlePyramidLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleDomeLobby_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc
BattleFrontier_BattlePyramidLobby_EventScript_Attendant:: @ NPC #1 (7,12)
BattleFrontier_BattlePyramidLobby_EventScript_HintGiver:: @ NPC #2 (14,13)
BattleFrontier_BattlePyramidLobby_EventScript_Woman:: @ NPC #3 (2,15)
BattleFrontier_BattlePyramidLobby_EventScript_FatMan:: @ NPC #4 (12,16)
BattleFrontier_BattlePyramidLobby_EventScript_ShowResults:: @ sign (5,12)
BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard:: @ sign (1,12)
	end
