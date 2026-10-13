NewMauville_Inside_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (NewMauville_Inside_OnResume), ON_TRANSITION (NewMauville_Inside_OnTransition), ON_LOAD (NewMauville_Inside_OnLoad)
NewMauville_Inside_EventScript_ItemUltraBall::  @ item ball, works (FLAG_ITEM_NEW_MAUVILLE_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end
NewMauville_Inside_EventScript_ItemEscapeRope:: @ item ball, works (FLAG_ITEM_NEW_MAUVILLE_ESCAPE_ROPE)
	finditem ITEM_ESCAPE_ROPE
	end
NewMauville_Inside_EventScript_ItemThunderStone:: @ item ball, works (FLAG_ITEM_NEW_MAUVILLE_THUNDER_STONE)
	finditem ITEM_THUNDER_STONE
	end
NewMauville_Inside_EventScript_ItemFullHeal::   @ item ball, works (FLAG_ITEM_NEW_MAUVILLE_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end
NewMauville_Inside_EventScript_ItemParalyzeHeal:: @ item ball, works (FLAG_ITEM_NEW_MAUVILLE_PARALYZE_HEAL)
	finditem ITEM_PARALYZE_HEAL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/NewMauville_Inside/scripts.inc
NewMauville_Inside_EventScript_Voltorb1::       @ NPC #6 (25,18)
NewMauville_Inside_EventScript_Voltorb2::       @ NPC #7 (6,11)
NewMauville_Inside_EventScript_Voltorb3::       @ NPC #8 (13,10)
NewMauville_Inside_EventScript_Generator::      @ sign (32,4)
	end
@ hoenn_import: left out: trigger (30,38) VAR_TEMP_1==0 -> NewMauville_Inside_EventScript_BlueButton; trigger (18,36) VAR_TEMP_2==0 -> NewMauville_Inside_EventScript_GreenButton; trigger (4,26) VAR_TEMP_1==0 -> NewMauville_Inside_EventScript_BlueButton; trigger (16,22) VAR_TEMP_1==0 -> NewMauville_Inside_EventScript_BlueButton; trigger (25,18) VAR_TEMP_2==0 -> NewMauville_Inside_EventScript_GreenButton; trigger (2,11) VAR_TEMP_2==0 -> NewMauville_Inside_EventScript_GreenButton; trigger (6,11) VAR_TEMP_1==0 -> NewMauville_Inside_EventScript_BlueButton; trigger (13,10) VAR_TEMP_1==0 -> NewMauville_Inside_EventScript_BlueButton; trigger (17,10) VAR_TEMP_2==0 -> NewMauville_Inside_EventScript_GreenButton; trigger (33,6) VAR_NEW_MAUVILLE_STATE==1 -> NewMauville_Inside_EventScript_RedButton
