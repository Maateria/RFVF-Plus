@ johto_import: generated from PokemonHnS data/maps/WhirlIslands_Descent_hns; scripted maps get their own file later
WhirlIslands_Descent_MapScripts::
	.byte 0

WhirlIslands_Descent_EventScript_Item1::        @ item ball (FLAG_ITEM_WHIRL_ISLANDS_B1F_PP_MAX)
	finditem ITEM_PP_MAX
	end

WhirlIslands_Descent_EventScript_Item2::        @ item ball (FLAG_ITEM_WHIRL_ISLANDS_B1F_FULL_RESTORE)
	finditem ITEM_FULL_RESTORE
	end

WhirlIslands_Descent_EventScript_Item3::        @ item ball (FLAG_ITEM_WHIRL_ISLANDS_B1F_MAX_REVIVE)
	finditem ITEM_MAX_REVIVE
	end

