MauvilleCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MauvilleCity_OnTransition)
MauvilleCity_EventScript_ItemXSpeed::           @ item ball, works (FLAG_ITEM_MAUVILLE_CITY_X_SPEED)
	finditem ITEM_X_SPEED
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MauvilleCity/scripts.inc
MauvilleCity_EventScript_Boy::                  @ NPC #1 (29,16)
MauvilleCity_EventScript_RichBoy::              @ NPC #2 (24,10)
MauvilleCity_EventScript_Maniac::               @ NPC #3 (14,11)
MauvilleCity_EventScript_Woman::                @ NPC #4 (18,6)
MauvilleCity_EventScript_SchoolKidM::           @ NPC #5 (17,14)
MauvilleCity_EventScript_RolloutTutor::         @ NPC #7 (13,7)
MauvilleCity_EventScript_GymSign::              @ sign (11,6)
MauvilleCity_EventScript_CitySign::             @ sign (19,7)
MauvilleCity_EventScript_BikeShopSign::         @ sign (33,6)
MauvilleCity_EventScript_GameCornerSign::       @ sign (11,15)
	end
