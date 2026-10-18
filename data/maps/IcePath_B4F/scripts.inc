@ johto_import: generated from PokemonHnS data/maps/IcePath_B4F_hns; scripted maps get their own file later
IcePath_B4F_MapScripts::
	.byte 0

IcePath_B4F_EventScript_Item1::                 @ item ball (FLAG_ITEM_ICEPATH3_NEVER_MELT_ICE)
	finditem ITEM_NEVER_MELT_ICE
	end

