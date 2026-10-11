.equ LOCALID_FALLARBOR_TENT_ATTENDANT, 1

FallarborTown_BattleTentLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (FallarborTown_BattleTentLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (FallarborTown_BattleTentLobby_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/FallarborTown_BattleTentLobby/scripts.inc
FallarborTown_BattleTentLobby_EventScript_Attendant:: @ NPC #1 (6,5)
FallarborTown_BattleTentLobby_EventScript_Hiker:: @ NPC #2 (1,5)
FallarborTown_BattleTentLobby_EventScript_LittleBoy:: @ NPC #3 (12,6)
FallarborTown_BattleTentLobby_EventScript_Lass:: @ NPC #4 (10,9)
FallarborTown_BattleTentLobby_EventScript_RulesBoard:: @ sign (4,5)
	end
