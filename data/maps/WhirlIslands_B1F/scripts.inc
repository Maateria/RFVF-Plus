@ johto_import: generated from PokemonHnS data/maps/WhirlIslands_B1F_hns; scripted maps get their own file later
WhirlIslands_B1F_MapScripts::
	.byte 0

WhirlIslands_B1F_EventScript_Item1::            @ item ball (FLAG_ITEM_WHIRL_ISLANDS_B2F_BIG_NUGGET)
	finditem ITEM_NUGGET
	end

WhirlIslands_B1F_EventScript_Item2::            @ item ball (FLAG_ITEM_WHIRL_ISLANDS_B2F_FULL_RESTORE)
	finditem ITEM_FULL_RESTORE
	end

WhirlIslands_B1F_EventScript_Item3::            @ item ball (FLAG_ITEM_WHIRL_ISLANDS_B2F_CARBOS)
	finditem ITEM_CARBOS
	end

WhirlIslands_B1F_EventScript_Item4::            @ item ball (FLAG_ITEM_WHIRL_ISLANDS_B2F_ESCAPE_ROPE)
	finditem ITEM_ESCAPE_ROPE
	end

WhirlIslands_B1F_EventScript_Item6::            @ item ball (FLAG_ITEM_WHIRL_ISLANDS_B2F_CALCIUM)
	finditem ITEM_CALCIUM
	end

