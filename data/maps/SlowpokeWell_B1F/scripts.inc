@ johto_import: generated from PokemonHnS data/maps/SlowpokeWell_B1F_hns; scripted maps get their own file later
SlowpokeWell_B1F_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item2::            @ item ball (FLAG_ITEM_SLOWPOKE_WELL_SUPER_POTION)
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item3::            @ item ball (FLAG_ITEM_SLOWPOKE_WELL_SUPER_POTION2)
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item4::            @ item ball (FLAG_ITEM_SLOWPOKE_WELL_GREAT_BALL)
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item5::            @ item ball (FLAG_ITEM_SLOWPOKE_WELL_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end

