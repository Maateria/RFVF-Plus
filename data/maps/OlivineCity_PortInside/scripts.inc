@ johto_import: generated from PokemonHnS data/maps/OlivineCity_PortInside_hns; scripted maps get their own file later
.equ LOCALID_OLIVINEPORT_SAILOR, 1
.equ LOCALID_OLIVINEPORT_BOAT, 6

OlivineCity_PortInside_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/OlivineCity_PortInside_hns/scripts.inc)
OlivineCity_PortInside_EventScript_Sailor::     @ SAILOR_HNS #1 (8,17)
OlivineCity_PortInside_EventScript_Youngster::  @ YOUNGSTER_HNS #2 (5,12)
OlivineCity_PortInside_EventScript_CooltrainerF:: @ COOLTRAINER_F_HNS #3 (12,12)
OlivineCity_PortInside_EventScript_Fisher2::    @ FISHERMAN_HNS #4 (3,14)
OlivineCity_PortInside_EventScript_Fisher1::    @ FISHERMAN_HNS #5 (14,12)
	end
