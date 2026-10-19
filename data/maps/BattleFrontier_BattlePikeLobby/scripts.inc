.equ LOCALID_PIKE_LOBBY_ATTENDANT, 1

BattleFrontier_BattlePikeLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattlePikeLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattlePikeLobby_OnWarp)
BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattlePikeLobby/scripts.inc
BattleFrontier_BattlePikeLobby_EventScript_Attendant:: @ NPC #1 (5,5)
BattleFrontier_BattlePikeLobby_EventScript_ShowResults:: @ sign (8,3)
BattleFrontier_BattlePikeLobby_EventScript_RulesBoard:: @ sign (1,3)
	end
