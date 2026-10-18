@ johto_import: generated from PokemonHnS data/maps/NationalPark_Normal_hns; scripted maps get their own file later
NationalPark_Normal_MapScripts::
	.byte 0

NationalPark_Normal_EventScript_Item12::        @ item ball (FLAG_ITEM_NATIONAL_PARK_TM_DIG)
	finditem ITEM_TM28_DIG
	end

NationalPark_Normal_EventScript_Item13::        @ item ball (FLAG_ITEM_NATIONAL_PARK_SOOTHE_BELL)
	finditem ITEM_SOOTHE_BELL
	end

@ silent until scripted (PokemonHnS data/maps/NationalPark_Normal_hns/scripts.inc)
NationalPark_Normal_EventScript_Lass::          @ LASS_HNS #1 (22,39)
NationalPark_Normal_EventScript_Youngster2::    @ YOUNGSTER_HNS #2 (11,42)
NationalPark_Normal_EventScript_Youngster1::    @ GAMEBOY_KID_HNS #3 (12,42)
NationalPark_Normal_EventScript_TeacherQuickclaw:: @ WOMAN_2_HNS #4 (32,42)
NationalPark_Normal_EventScript_Persian::       @ MON_BASE+SPECIES_PERSIAN #5 (31,42)
NationalPark_Normal_EventScript_Beverly::       @ BEAUTY_HNS #6 (11,27), trainer TRAINER_BEVERLY_HNS
NationalPark_Normal_EventScript_Jack::          @ LITTLE_BOY_HNS #7 (25,30), trainer TRAINER_JACK_HNS
NationalPark_Normal_EventScript_Krise::         @ LASS_HNS #8 (11,13), trainer TRAINER_KRISE_HNS
NationalPark_Normal_EventScript_William::       @ BALDING_MAN_HNS #9 (25,9), trainer TRAINER_WILLIAM_HNS
NationalPark_Normal_EventScript_Teacher2::      @ OLD_WOMAN_HNS #10 (17,4)
NationalPark_Normal_EventScript_Trash::         @ sign (14,42)
NationalPark_Normal_EventScript_RelaxationSquare:: @ sign (16,45)
NationalPark_Normal_EventScript_BattleSign::    @ sign (31,33)
NationalPark_Normal_EventScript_TrainerTips::   @ sign (14,4)
	end
