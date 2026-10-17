.equ LOCALID_ARENA_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattleArenaLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleArenaLobby_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattleArenaLobby/scripts.inc
BattleFrontier_BattleArenaLobby_EventScript_Attendant:: @ NPC #1 (7,7)
BattleFrontier_BattleArenaLobby_EventScript_Woman:: @ NPC #2 (2,10)
BattleFrontier_BattleArenaLobby_EventScript_Man:: @ NPC #3 (14,11)
BattleFrontier_BattleArenaLobby_EventScript_Camper:: @ NPC #4 (14,12)
BattleFrontier_BattleArenaLobby_EventScript_Youngster:: @ NPC #5 (14,10)
BattleFrontier_BattleArenaLobby_EventScript_ShowResults:: @ sign (5,9)
BattleFrontier_BattleArenaLobby_EventScript_RulesBoard:: @ sign (1,7)
	end
