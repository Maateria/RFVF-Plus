@ johto_import: generated from PokemonHnS data/maps/SSAqua_B1F_hns; scripted maps get their own file later
.equ LOCALID_SSAQUA_B1F_SAILORLOOKING, 10

SSAqua_B1F_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/SSAqua_B1F_hns/scripts.inc)
SSAqua_B1F_EventScript_Wai::                    @ BLACK_BELT_HNS #1 (10,10), trainer TRAINER_WAI_HNS
SSAqua_B1F_EventScript_Nate::                   @ LITTLE_BOY_HNS #2 (10,11), trainer TRAINER_NATE_HNS
SSAqua_B1F_EventScript_Shirley::                @ WOMAN_3_HNS #3 (7,11), trainer TRAINER_SHIRLEY_HNS
SSAqua_B1F_EventScript_Ricky::                  @ LITTLE_BOY_HNS #4 (7,12), trainer TRAINER_RICKY_HNS
SSAqua_B1F_EventScript_Debra::                  @ PICNICKER_HNS #5 (16,8), trainer TRAINER_DEBRA_HNS
SSAqua_B1F_EventScript_Kenneth::                @ SAILOR_HNS #6 (1,7), trainer TRAINER_KENNETH_HNS
SSAqua_B1F_EventScript_SleepySailor::           @ SAILOR_HNS #7 (18,3)
SSAqua_B1F_EventScript_Jonah::                  @ FISHERMAN_HNS #8 (19,12), trainer TRAINER_JONAH_HNS
SSAqua_B1F_EventScript_Fritz::                  @ JUGGLER_HNS #9 (24,8), trainer TRAINER_FRITZ_HNS
SSAqua_B1F_EventScript_SailorLookingForBuddy::  @ SAILOR_HNS #10 (28,8)
SSAqua_B1F_EventScript_Garrett::                @ SAILOR_HNS #11 (11,3), trainer TRAINER_GARRETT_HNS
SSAqua_B1F_EventScript_Trash::                  @ sign (13,14)
SSAqua_B1F_EventScript_Barfcan::                @ sign (25,8)
	end
