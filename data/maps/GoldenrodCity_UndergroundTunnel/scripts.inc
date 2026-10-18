@ johto_import: generated from PokemonHnS data/maps/GoldenrodCity_UndergroundTunnel_hns; scripted maps get their own file later
GoldenrodCity_UndergroundTunnel_MapScripts::
	.byte 0

GoldenrodCity_UndergroundTunnel_EventScript_Item1:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_COIN_CASE)
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item2:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_PARALYZE_HEAL)
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item3:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_ANTIDOTE)
	finditem ITEM_ANTIDOTE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item4:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_SUPER_POTION)
	finditem ITEM_SUPER_POTION
	end

@ silent until scripted (PokemonHnS data/maps/GoldenrodCity_UndergroundTunnel_hns/scripts.inc)
GoldenrodCity_UndergroundTunnel_EventScript_Door:: @ sign (12,10)
	end
