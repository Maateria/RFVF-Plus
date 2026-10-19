.equ LOCALID_FALLARBOR_TENT_ATTENDANT, 1

FallarborTown_BattleTentLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (FallarborTown_BattleTentLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (FallarborTown_BattleTentLobby_OnWarp)
FallarborTown_BattleTentLobby_EventScript_Hiker::
	msgbox FallarborTown_BattleTentLobby_Text_CameToCampOut, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_LittleBoy::
	msgbox FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_Lass::
	msgbox FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/FallarborTown_BattleTentLobby/scripts.inc
FallarborTown_BattleTentLobby_EventScript_Attendant:: @ NPC #1 (6,5)
FallarborTown_BattleTentLobby_EventScript_RulesBoard:: @ sign (4,5)
	end
