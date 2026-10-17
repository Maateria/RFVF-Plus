.equ LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (BattleFrontier_BattleTowerMultiPartnerRoom_OnResume), ON_TRANSITION (BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition), ON_WARP_INTO_MAP_TABLE (BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp), ON_FRAME_TABLE (BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.inc
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant:: @ NPC #1 (11,2)
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1:: @ NPC #2 (2,10)
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2:: @ NPC #3 (17,11)
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3:: @ NPC #4 (6,9)
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4:: @ NPC #5 (8,13)
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5:: @ NPC #6 (10,11)
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6:: @ NPC #7 (13,10)
	end
