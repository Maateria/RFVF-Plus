.equ LOCALID_ARENA_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattleArenaLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleArenaLobby_OnWarp)
BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattleArenaLobby/scripts.inc
BattleFrontier_BattleArenaLobby_EventScript_Attendant:: @ NPC #1 (7,7)
BattleFrontier_BattleArenaLobby_EventScript_ShowResults:: @ sign (5,9)
BattleFrontier_BattleArenaLobby_EventScript_RulesBoard:: @ sign (1,7)
	end
