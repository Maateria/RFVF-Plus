@ johto_import: generated from PokemonHnS data/maps/DragonsDen_Shrine_hns; scripted maps get their own file later
.equ LOCALID_DRAGONSDEN3_ELDER, 1

DragonsDen_Shrine_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/DragonsDen_Shrine_hns/scripts.inc)
DragonsDen_Shrine_EventScript_Elder::           @ OLD_MAN_HNS #1 (6,9)
DragonsDen_Shrine_EventScript_Elder2::          @ SAGE_HNS #2 (3,12)
DragonsDen_Shrine_EventScript_Elder3::          @ SAGE_HNS #3 (9,12)
DragonsDen_Shrine_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (4,15)
	end
