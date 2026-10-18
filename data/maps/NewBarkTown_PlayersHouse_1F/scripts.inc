@ johto_import: generated from PokemonHnS data/maps/NewBarkTown_PlayersHouse_1F_hns; scripted maps get their own file later
.equ LOCALID_MOM, 1

NewBarkTown_PlayersHouse_1F_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/NewBarkTown_PlayersHouse_1F_hns/scripts.inc)
NewBarkTown_PlayersHouse_1F_EventScript_Mom::   @ MOM_HNS #1 (2,2)
	end
