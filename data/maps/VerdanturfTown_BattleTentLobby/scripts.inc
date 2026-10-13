.equ LOCALID_VERDANTURF_TENT_ATTENDANT, 1

VerdanturfTown_BattleTentLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (VerdanturfTown_BattleTentLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (VerdanturfTown_BattleTentLobby_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/VerdanturfTown_BattleTentLobby/scripts.inc
VerdanturfTown_BattleTentLobby_EventScript_Attendant:: @ NPC #1 (6,5)
VerdanturfTown_BattleTentLobby_EventScript_AttractGiver:: @ NPC #2 (0,5)
VerdanturfTown_BattleTentLobby_EventScript_Boy1:: @ NPC #3 (9,7)
VerdanturfTown_BattleTentLobby_EventScript_Boy2:: @ NPC #4 (1,8)
VerdanturfTown_BattleTentLobby_EventScript_LittleBoy:: @ NPC #5 (2,8)
VerdanturfTown_BattleTentLobby_EventScript_RulesBoard:: @ sign (4,5)
	end
