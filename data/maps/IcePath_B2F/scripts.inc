@ johto_import: generated from PokemonHnS data/maps/IcePath_B2F_hns; scripted maps get their own file later
IcePath_B2F_MapScripts::
	.byte 0

IcePath_B2F_EventScript_Item1::                 @ item ball (FLAG_ITEM_ICEPATH3_MAX_POTION)
	finditem ITEM_MAX_POTION
	end

IcePath_B2F_EventScript_Item2::                 @ item ball (FLAG_ITEM_ICEPATH3_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end

IcePath_B2F_EventScript_Item3::                 @ item ball (FLAG_ITEM_ICEPATH3_CARBOS)
	finditem ITEM_CARBOS
	end

