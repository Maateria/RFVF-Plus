.equ LOCALID_SLATEPORT_TENT_ATTENDANT, 1

SlateportCity_BattleTentLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (SlateportCity_BattleTentLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (SlateportCity_BattleTentLobby_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SlateportCity_BattleTentLobby/scripts.inc
SlateportCity_BattleTentLobby_EventScript_Attendant:: @ NPC #1 (6,5)
SlateportCity_BattleTentLobby_EventScript_TormentGiver:: @ NPC #2 (1,5)
SlateportCity_BattleTentLobby_EventScript_Man:: @ NPC #3 (3,7)
SlateportCity_BattleTentLobby_EventScript_Girl:: @ NPC #4 (1,8)
SlateportCity_BattleTentLobby_EventScript_Woman:: @ NPC #5 (11,8)
SlateportCity_BattleTentLobby_EventScript_RulesBoard:: @ sign (4,5)
	end
