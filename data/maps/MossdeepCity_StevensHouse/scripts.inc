.equ LOCALID_STEVENS_HOUSE_BALL, 1

MossdeepCity_StevensHouse_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (MossdeepCity_StevensHouse_OnLoad), ON_TRANSITION (MossdeepCity_StevensHouse_OnTransition), ON_FRAME_TABLE (MossdeepCity_StevensHouse_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MossdeepCity_StevensHouse/scripts.inc
MossdeepCity_StevensHouse_EventScript_BeldumPokeball:: @ NPC #1 (4,3)
MossdeepCity_StevensHouse_EventScript_Letter::  @ NPC #2 (6,4)
MossdeepCity_StevensHouse_EventScript_RockDisplay:: @ sign (0,1)
	end
