.equ LOCALID_VERDANTURF_TWIN, 2

VerdanturfTown_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (VerdanturfTown_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/VerdanturfTown/scripts.inc
VerdanturfTown_EventScript_Man::                @ NPC #1 (4,17)
VerdanturfTown_EventScript_Twin::               @ NPC #2 (9,2)
VerdanturfTown_EventScript_Boy::                @ NPC #3 (7,11)
VerdanturfTown_EventScript_Camper::             @ NPC #4 (7,6)
VerdanturfTown_EventScript_TownSign::           @ sign (14,6)
VerdanturfTown_EventScript_WandasHouseSign::    @ sign (7,14)
VerdanturfTown_EventScript_BattleTentSign::     @ sign (1,8)
VerdanturfTown_EventScript_RusturfTunnelSign::  @ sign (7,3)
	end
