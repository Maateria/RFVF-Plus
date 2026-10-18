@ johto_import: generated from PokemonHnS data/maps/IcePath_1F_hns; scripted maps get their own file later
IcePath_1F_MapScripts::
	.byte 0

IcePath_1F_EventScript_Item1::                  @ item ball (FLAG_ITEM_ICEPATH1_PP_UP)
	finditem ITEM_PP_UP
	end

IcePath_1F_EventScript_Item2::                  @ item ball (FLAG_ITEM_ICEPATH1_HM_WATERFALL)
	finditem ITEM_HM07_WATERFALL
	end

IcePath_1F_EventScript_Item3::                  @ item ball (FLAG_ITEM_ICEPATH1_PROTEIN)
	finditem ITEM_PROTEIN
	end

