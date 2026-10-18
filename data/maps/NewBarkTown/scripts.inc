@ johto_import: generated from PokemonHnS data/maps/NewBarkTown_hns; scripted maps get their own file later
.equ LOCALID_LASS, 2

NewBarkTown_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/NewBarkTown_hns/scripts.inc)
NewBarkTown_EventScript_FatMan::                @ FAT_MAN_HNS #1 (20,18)
NewBarkTown_EventScript_Lass::                  @ LASS_HNS #2 (9,16)
NewBarkTown_EventScript_TownSign::              @ sign (10,14)
NewBarkTown_EventScript_Door::                  @ sign (12,7)
NewBarkTown_EventScript_PlayersHouseMailbox::   @ sign (17,11)
NewBarkTown_EventScript_ElmsHouseMailbox::      @ sign (12,21)
NewBarkTown_EventScript_LabSign::               @ sign (9,9)
	end
