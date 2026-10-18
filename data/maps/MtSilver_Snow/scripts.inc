@ johto_import: generated from PokemonHnS data/maps/MtSilver_Snow_hns; scripted maps get their own file later
MtSilver_Snow_MapScripts::
	.byte 0

MtSilver_Snow_EventScript_Item1::               @ item ball (FLAG_ITEM_MTSILVER_RARECANDY)
	finditem ITEM_RARE_CANDY
	end

MtSilver_Snow_EventScript_Item2::               @ item ball (FLAG_ITEM_MTSILVER_NERVERMELTICE)
	finditem ITEM_NEVER_MELT_ICE
	end

