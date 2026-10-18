@ johto_import: generated from PokemonHnS data/maps/WhirlIslands_1F_hns; scripted maps get their own file later
WhirlIslands_1F_MapScripts::
	.byte 0

WhirlIslands_1F_EventScript_Item1::             @ item ball (FLAG_ITEM_WHIRL_ISLANDS_1F_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end

WhirlIslands_1F_EventScript_Item2::             @ item ball (FLAG_ITEM_WHIRL_ISLANDS_1F_GUARD_SPEC)
	finditem ITEM_GUARD_SPEC
	end

WhirlIslands_1F_EventScript_Item3::             @ item ball (FLAG_ITEM_WHIRL_ISLANDS_1F_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end

WhirlIslands_1F_EventScript_Item4::             @ item ball (FLAG_ITEM_WHIRL_ISLANDS_1F_FULL_RESTORE)
	finditem ITEM_FULL_RESTORE
	end

