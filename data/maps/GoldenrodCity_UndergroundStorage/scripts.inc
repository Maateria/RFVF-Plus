@ johto_import: generated from PokemonHnS data/maps/GoldenrodCity_UndergroundStorage_hns; scripted maps get their own file later
GoldenrodCity_UndergroundStorage_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Item1:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_ULTRA_BALL2)
	finditem ITEM_ULTRA_BALL
	end

GoldenrodCity_UndergroundStorage_EventScript_Item2:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_MAX_ETHER)
	finditem ITEM_MAX_ETHER
	end

GoldenrodCity_UndergroundStorage_EventScript_Item3:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_TM_CALM_MIND)
	finditem ITEM_TM04_CALM_MIND
	end

