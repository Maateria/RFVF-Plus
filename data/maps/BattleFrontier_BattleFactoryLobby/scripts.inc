.equ LOCALID_FACTORY_ATTENDANT_SINGLES, 1
.equ LOCALID_FACTORY_ATTENDANT_DOUBLES, 6

BattleFrontier_BattleFactoryLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattleFactoryLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleFactoryLobby_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattleFactoryLobby/scripts.inc
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant:: @ NPC #1 (4,7)
BattleFrontier_BattleFactoryLobby_EventScript_Woman:: @ NPC #2 (3,11)
BattleFrontier_BattleFactoryLobby_EventScript_Camper:: @ NPC #3 (14,11)
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker:: @ NPC #4 (13,11)
BattleFrontier_BattleFactoryLobby_EventScript_FatMan:: @ NPC #5 (6,10)
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant:: @ NPC #6 (14,7)
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults:: @ sign (2,7)
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults:: @ sign (11,7)
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard:: @ sign (9,4)
	end
