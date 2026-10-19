.equ LOCALID_FACTORY_ATTENDANT_SINGLES, 1
.equ LOCALID_FACTORY_ATTENDANT_DOUBLES, 6

BattleFrontier_BattleFactoryLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattleFactoryLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleFactoryLobby_OnWarp)
BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattleFactoryLobby/scripts.inc
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant:: @ NPC #1 (4,7)
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant:: @ NPC #6 (14,7)
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults:: @ sign (2,7)
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults:: @ sign (11,7)
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard:: @ sign (9,4)
	end
