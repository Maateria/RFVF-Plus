@ johto_import: generated from PokemonHnS data/maps/OlivineCity_hns; scripted maps get their own file later
OlivineCity_MapScripts::
	.byte 0

OlivineCity_EventScript_Item6::                 @ item ball (FLAG_ITEM_OLIVINE_TM_CHARGEBEAM)
	finditem ITEM_TM34_SHOCK_WAVE
	end

@ silent until scripted (PokemonHnS data/maps/OlivineCity_hns/scripts.inc)
OlivineCity_EventScript_Youngster::             @ YOUNGSTER_HNS #1 (21,28)
OlivineCity_EventScript_Sailor2::               @ SAILOR_HNS #2 (33,46)
OlivineCity_EventScript_Sailor1::               @ SAILOR_HNS #3 (11,44)
OlivineCity_EventScript_Machoke::               @ MON_BASE+SPECIES_MACHOKE #4 (33,47)
OlivineCity_EventScript_EonTicketWoman::        @ ATTENDANT_F_HNS #7 (26,52)
OlivineCity_EventScript_MetronomeTutor::        @ TWIN_HNS #8 (28,41)
OlivineCity_EventScript_GymSign::               @ sign (13,27)
OlivineCity_EventScript_LighthouseSign::        @ sign (36,48)
OlivineCity_EventScript_PortSign::              @ sign (22,52)
OlivineCity_EventScript_Sign::                  @ sign (22,24)
OlivineCity_EventScript_CafeSign::              @ sign (7,44)
	end
