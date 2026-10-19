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
PetalburgCity_EventScript_Boy::
	lock
	faceplayer
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_EventScript_Gentleman::
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
	end

PetalburgCity_EventScript_GymBoy::
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
	end

PetalburgCity_EventScript_GymSign::
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_CitySign::
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_WallyHouseSign::
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
	end
@ hoenn_import: left out: trigger (8,10) VAR_PETALBURG_CITY_STATE==0 -> PetalburgCity_EventScript_ShowGymToPlayer0; trigger (8,11) VAR_PETALBURG_CITY_STATE==0 -> PetalburgCity_EventScript_ShowGymToPlayer1; trigger (8,12) VAR_PETALBURG_CITY_STATE==0 -> PetalburgCity_EventScript_ShowGymToPlayer2; trigger (8,13) VAR_PETALBURG_CITY_STATE==0 -> PetalburgCity_EventScript_ShowGymToPlayer3; trigger (4,10) VAR_SCOTT_PETALBURG_ENCOUNTER==0 -> PetalburgCity_EventScript_Scott0; trigger (4,11) VAR_SCOTT_PETALBURG_ENCOUNTER==0 -> PetalburgCity_EventScript_Scott1; trigger (4,12) VAR_SCOTT_PETALBURG_ENCOUNTER==0 -> PetalburgCity_EventScript_Scott2; trigger (4,13) VAR_SCOTT_PETALBURG_ENCOUNTER==0 -> PetalburgCity_EventScript_Scott3
