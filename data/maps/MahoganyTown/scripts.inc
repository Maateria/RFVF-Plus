@ johto_import: generated from PokemonHnS data/maps/Mahoganytown_hns; scripted maps get their own file later
.equ LOCALID_MAHOGANY_MERCHANT, 3

MahoganyTown_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/Mahoganytown_hns/scripts.inc)
MahoganyTown_EventScript_Gramps::               @ OLD_MAN_HNS #1 (7,13)
MahoganyTown_EventScript_Lass::                 @ WOMAN_1_HNS #2 (24,8)
MahoganyTown_EventScript_Merchant::             @ BALDING_MAN_HNS #3 (30,11)
MahoganyTown_EventScript_Sign::                 @ sign (7,11)
MahoganyTown_EventScript_CandybarSign::         @ sign (17,11)
MahoganyTown_EventScript_GymSign::              @ sign (12,19)
	end
