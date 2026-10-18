@ johto_import: generated from PokemonHnS data/maps/AzaleaTown_Gym_hns; scripted maps get their own file later
AzaleaTown_Gym_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/AzaleaTown_Gym_hns/scripts.inc)
AzaleaTown_Gym_EventScript_GymGuy::             @ GYM_GUY_HNS #1 (12,42)
AzaleaTown_Gym_EventScript_Bugsy::              @ BUGSY_HNS #2 (11,6), trainer TRAINER_BUGSY_1_HNS
AzaleaTown_Gym_EventScript_Amy::                @ TWIN_HNS #3 (5,26), trainer TRAINER_AMY_AND_MAY_HNS
AzaleaTown_Gym_EventScript_May::                @ TWIN_HNS #4 (6,26), trainer TRAINER_AMY_AND_MAY_HNS
AzaleaTown_Gym_EventScript_Benny::              @ BUG_CATCHER_HNS #5 (17,26), trainer TRAINER_BENNY_HNS
AzaleaTown_Gym_EventScript_Josh::               @ BUG_CATCHER_HNS #6 (17,5), trainer TRAINER_JOSH_HNS
AzaleaTown_Gym_EventScript_Al::                 @ BUG_CATCHER_HNS #7 (6,6), trainer TRAINER_AL_HNS
AzaleaTown_Gym_EventScript_Statue::             @ sign (9,42)
	end
