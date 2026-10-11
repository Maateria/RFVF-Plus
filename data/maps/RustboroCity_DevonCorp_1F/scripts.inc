.equ LOCALID_DEVON_CORP_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (RustboroCity_DevonCorp_1F_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/RustboroCity_DevonCorp_1F/scripts.inc
RustboroCity_DevonCorp_1F_EventScript_Employee:: @ NPC #1 (2,6)
RustboroCity_DevonCorp_1F_EventScript_StairGuard:: @ NPC #2 (15,5)
RustboroCity_DevonCorp_1F_EventScript_Greeter:: @ NPC #3 (5,3)
RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay:: @ sign (3,2)
RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay:: @ sign (8,2)
	end
