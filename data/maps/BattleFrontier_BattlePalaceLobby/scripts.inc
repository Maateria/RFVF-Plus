.equ LOCALID_PALACE_ATTENDANT_SINGLES, 1

BattleFrontier_BattlePalaceLobby_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (BattleFrontier_BattlePalaceLobby_OnFrame), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattlePalaceLobby_OnWarp)
BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc
BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant:: @ NPC #1 (5,6)
BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults:: @ sign (2,7)
BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults:: @ sign (16,7)
BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard:: @ sign (10,4)
	end
