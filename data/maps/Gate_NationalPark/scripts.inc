@ johto_import: generated from PokemonHnS data/maps/Gate_NationalPark_hns; scripted maps get their own file later
Gate_NationalPark_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/Gate_NationalPark_hns/scripts.inc)
Gate_NationalPark_EventScript_Policeman::       @ OFFICER_HNS #1 (1,6)
Gate_NationalPark_EventScript_BAttendant::      @ MYSTERY_EVENT_DELIVERYMAN_HNS #3 (38,2)
Gate_NationalPark_EventScript_Attendant::       @ MYSTERY_EVENT_DELIVERYMAN_HNS #4 (3,2)
Gate_NationalPark_EventScript_Rocker::          @ ROCKER_HNS #5 (11,4)
Gate_NationalPark_EventScript_BC1::             @ BUG_CATCHER_HNS #6 (14,9)
Gate_NationalPark_EventScript_BC2::             @ BUG_CATCHER_HNS #7 (39,11)
Gate_NationalPark_EventScript_Beauty::          @ BEAUTY_HNS #8 (36,11)
	end
