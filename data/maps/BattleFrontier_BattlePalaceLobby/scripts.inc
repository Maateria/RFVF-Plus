.equ LOCALID_PALACE_ATTENDANT_SINGLES, 1

BattleFrontier_BattlePalaceLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattlePalaceLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattlePalaceLobby_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc
BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant:: @ NPC #1 (5,6)
BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt:: @ NPC #2 (11,8)
BattleFrontier_BattlePalaceLobby_EventScript_Maniac:: @ NPC #3 (24,5)
BattleFrontier_BattlePalaceLobby_EventScript_Man:: @ NPC #4 (18,10)
BattleFrontier_BattlePalaceLobby_EventScript_Beauty:: @ NPC #5 (2,10)
BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults:: @ sign (2,7)
BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults:: @ sign (16,7)
BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard:: @ sign (10,4)
	end
