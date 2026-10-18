@ johto_import: generated from PokemonHnS data/maps/GoldenrodCity_UndergroundSwitches_hns; scripted maps get their own file later
GoldenrodCity_UndergroundSwitches_MapScripts::
	.byte 0

GoldenrodCity_UndergroundSwitches_EventScript_Item3:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_REVIVE)
	finditem ITEM_MAX_REVIVE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item4:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_MAX_POTION)
	finditem ITEM_MAX_POTION
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item5:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_SMOKE_BALL)
	finditem ITEM_SMOKE_BALL
	end

@ silent until scripted (PokemonHnS data/maps/GoldenrodCity_UndergroundSwitches_hns/scripts.inc)
GoldenrodCity_UndergroundSwitches_EventScript_Duncan:: @ BURGLAR_HNS #1 (3,9), trainer TRAINER_DUNCAN_HNS
GoldenrodCity_UndergroundSwitches_EventScript_Eddie:: @ BURGLAR_HNS #2 (11,13), trainer TRAINER_EDDIE_HNS
GoldenrodCity_UndergroundSwitches_EventScript_Panel1:: @ sign (22,1)
GoldenrodCity_UndergroundSwitches_EventScript_Panel2:: @ sign (13,1)
GoldenrodCity_UndergroundSwitches_EventScript_Panel3:: @ sign (5,1)
GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock:: @ sign (9,8)
	end
