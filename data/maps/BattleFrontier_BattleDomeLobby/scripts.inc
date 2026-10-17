.equ LOCALID_DOME_ATTENDANT_SINGLES, 1
.equ LOCALID_DOME_ATTENDANT_DOUBLES, 6

BattleFrontier_BattleDomeLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (BattleFrontier_BattleDomeLobby_OnResume), ON_FRAME_TABLE (BattleFrontier_BattleDomeLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleDomeLobby_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattleDomeLobby/scripts.inc
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant:: @ NPC #1 (5,10)
BattleFrontier_BattleDomeLobby_EventScript_Man:: @ NPC #2 (1,11)
BattleFrontier_BattleDomeLobby_EventScript_Lass:: @ NPC #3 (14,14)
BattleFrontier_BattleDomeLobby_EventScript_FatMan:: @ NPC #4 (18,14)
BattleFrontier_BattleDomeLobby_EventScript_Maniac:: @ NPC #5 (8,14)
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant:: @ NPC #6 (17,10)
BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults:: @ sign (4,10)
BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree:: @ sign (7,10)
BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults:: @ sign (18,10)
BattleFrontier_BattleDomeLobby_EventScript_RulesBoard:: @ sign (15,10)
	end
