@ johto_import: generated from PokemonHnS data/maps/NationalPark_BugContest_hns; scripted maps get their own file later
.equ LOCALID_BUGCONTEST_BC1, 1
.equ LOCALID_BUGCONTEST_BC2, 2
.equ LOCALID_BUGCONTEST_ATTENDANT, 3
.equ LOCALID_BUGCONTEST_BOY, 4
.equ LOCALID_BUGCONTEST_GIRL, 5

NationalPark_BugContest_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/NationalPark_BugContest_hns/scripts.inc)
NationalPark_BugContest_EventScript_BC2::       @ BUG_CATCHER_HNS #1 (11,13)
NationalPark_BugContest_EventScript_BC1::       @ BUG_CATCHER_HNS #2 (26,9)
NationalPark_BugContest_EventScript_Attendant:: @ MYSTERY_EVENT_DELIVERYMAN_HNS #3 (10,49)
NationalPark_BugContest_EventScript_Boy::       @ LITTLE_BOY_HNS #4 (29,27)
NationalPark_BugContest_EventScript_Belinda::   @ COOLTRAINER_F_HNS #5 (14,28)
NationalPark_BugContest_EventScript_RelaxationSquare:: @ sign (16,45)
NationalPark_BugContest_EventScript_BattleSign:: @ sign (31,33)
NationalPark_BugContest_EventScript_TrainerTips:: @ sign (14,4)
NationalPark_BugContest_EventScript_Trash::     @ sign (14,42)
	end
