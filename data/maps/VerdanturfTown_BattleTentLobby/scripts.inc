.equ LOCALID_VERDANTURF_TENT_ATTENDANT, 1

VerdanturfTown_BattleTentLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (VerdanturfTown_BattleTentLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (VerdanturfTown_BattleTentLobby_OnWarp)
VerdanturfTown_BattleTentLobby_EventScript_Boy1::
	msgbox VerdanturfTown_BattleTentLobby_Text_TaughtWhatKindsOfMoves, MSGBOX_NPC
	end

VerdanturfTown_BattleTentLobby_EventScript_Boy2::
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_MonsReluctantToUseDislikedMoves, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_LittleBoy::
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_GentleMonsScaryIfAngry, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_AttractGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ATTRACT, VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionRunsDeep, MSGBOX_DEFAULT
	giveitem ITEM_TM45_ATTRACT
	goto_if_eq VAR_RESULT, 0, EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM_ATTRACT
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract::
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/VerdanturfTown_BattleTentLobby/scripts.inc
VerdanturfTown_BattleTentLobby_EventScript_Attendant:: @ NPC #1 (6,5)
VerdanturfTown_BattleTentLobby_EventScript_RulesBoard:: @ sign (4,5)
	end
