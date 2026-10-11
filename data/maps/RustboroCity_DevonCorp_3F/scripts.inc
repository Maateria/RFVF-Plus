.equ LOCALID_DEVON_CORP_3F_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (RustboroCity_DevonCorp_3F_OnTransition), ON_WARP_INTO_MAP_TABLE (RustboroCity_DevonCorp_3F_OnWarp), ON_FRAME_TABLE (RustboroCity_DevonCorp_3F_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/RustboroCity_DevonCorp_3F/scripts.inc
RustboroCity_DevonCorp_3F_EventScript_MrStone:: @ NPC #1 (17,5)
RustboroCity_DevonCorp_3F_EventScript_Employee:: @ NPC #2 (3,5)
RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay:: @ sign (1,5)
	end
