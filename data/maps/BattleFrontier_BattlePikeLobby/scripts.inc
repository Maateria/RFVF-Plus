.equ LOCALID_PIKE_LOBBY_ATTENDANT, 1

BattleFrontier_BattlePikeLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattlePikeLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattlePikeLobby_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattlePikeLobby/scripts.inc
BattleFrontier_BattlePikeLobby_EventScript_Attendant:: @ NPC #1 (5,5)
BattleFrontier_BattlePikeLobby_EventScript_Hiker:: @ NPC #2 (10,9)
BattleFrontier_BattlePikeLobby_EventScript_Twin:: @ NPC #3 (0,5)
BattleFrontier_BattlePikeLobby_EventScript_Beauty:: @ NPC #4 (8,9)
BattleFrontier_BattlePikeLobby_EventScript_ShowResults:: @ sign (8,3)
BattleFrontier_BattlePikeLobby_EventScript_RulesBoard:: @ sign (1,3)
	end
