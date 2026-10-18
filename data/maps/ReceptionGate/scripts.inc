@ johto_import: generated from PokemonHnS data/maps/ReceptionGate_hns; scripted maps get their own file later
.equ LOCALID_INDIGOJUNCTION_POLICEMAN, 1

ReceptionGate_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/ReceptionGate_hns/scripts.inc)
ReceptionGate_EventScript_Officer::             @ OFFICER_HNS #1 (9,14)
	end
