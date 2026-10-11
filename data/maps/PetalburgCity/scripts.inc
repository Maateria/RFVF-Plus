.equ LOCALID_PETALBURG_BOY, 1
.equ LOCALID_GYM_BOY, 5

PetalburgCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (PetalburgCity_OnTransition), ON_FRAME_TABLE (PetalburgCity_OnFrame)
PetalburgCity_EventScript_ItemMaxRevive::       @ item ball, works (FLAG_ITEM_PETALBURG_CITY_MAX_REVIVE)
	finditem ITEM_MAX_REVIVE
	end
PetalburgCity_EventScript_ItemEther::           @ item ball, works (FLAG_ITEM_PETALBURG_CITY_ETHER)
	finditem ITEM_ETHER
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/PetalburgCity/scripts.inc
PetalburgCity_EventScript_Boy::                 @ NPC #1 (8,22)
PetalburgCity_EventScript_Gentleman::           @ NPC #2 (20,10)
PetalburgCity_EventScript_GymBoy::              @ NPC #5 (12,15)
PetalburgCity_EventScript_GymSign::             @ sign (17,10)
PetalburgCity_EventScript_CitySign::            @ sign (17,16)
PetalburgCity_EventScript_WallyHouseSign::      @ sign (8,9)
	end
@ hoenn_import: left out: trigger (8,10) VAR_PETALBURG_CITY_STATE==0 -> PetalburgCity_EventScript_ShowGymToPlayer0; trigger (8,11) VAR_PETALBURG_CITY_STATE==0 -> PetalburgCity_EventScript_ShowGymToPlayer1; trigger (8,12) VAR_PETALBURG_CITY_STATE==0 -> PetalburgCity_EventScript_ShowGymToPlayer2; trigger (8,13) VAR_PETALBURG_CITY_STATE==0 -> PetalburgCity_EventScript_ShowGymToPlayer3; trigger (4,10) VAR_SCOTT_PETALBURG_ENCOUNTER==0 -> PetalburgCity_EventScript_Scott0; trigger (4,11) VAR_SCOTT_PETALBURG_ENCOUNTER==0 -> PetalburgCity_EventScript_Scott1; trigger (4,12) VAR_SCOTT_PETALBURG_ENCOUNTER==0 -> PetalburgCity_EventScript_Scott2; trigger (4,13) VAR_SCOTT_PETALBURG_ENCOUNTER==0 -> PetalburgCity_EventScript_Scott3
