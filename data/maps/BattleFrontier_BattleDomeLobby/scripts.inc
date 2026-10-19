.equ LOCALID_DOME_ATTENDANT_SINGLES, 1
.equ LOCALID_DOME_ATTENDANT_DOUBLES, 6

BattleFrontier_BattleDomeLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (BattleFrontier_BattleDomeLobby_OnResume), ON_FRAME_TABLE (BattleFrontier_BattleDomeLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleDomeLobby_OnWarp)
BattleFrontier_BattleDomeLobby_EventScript_Man::
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Lass::
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattleDomeLobby/scripts.inc
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant:: @ NPC #1 (5,10)
BattleFrontier_BattleDomeLobby_EventScript_Maniac:: @ NPC #5 (8,14)
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant:: @ NPC #6 (17,10)
BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults:: @ sign (4,10)
BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree:: @ sign (7,10)
BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults:: @ sign (18,10)
BattleFrontier_BattleDomeLobby_EventScript_RulesBoard:: @ sign (15,10)
	end
