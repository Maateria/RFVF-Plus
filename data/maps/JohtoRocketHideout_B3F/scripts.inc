@ johto_import: generated from PokemonHnS data/maps/RocketHideout_B3F_hns; scripted maps get their own file later
JohtoRocketHideout_B3F_MapScripts::
	.byte 0

JohtoRocketHideout_B3F_EventScript_Item1::      @ item ball (FLAG_ITEM_ROCKETHIDEOUT3_PROTEIN)
	finditem ITEM_PROTEIN
	end

JohtoRocketHideout_B3F_EventScript_Item2::      @ item ball (FLAG_ITEM_ROCKETHIDEOUT3_ICE_HEAL)
	finditem ITEM_ICE_HEAL
	end

JohtoRocketHideout_B3F_EventScript_Item3::      @ item ball (FLAG_ITEM_ROCKETHIDEOUT3_HYPER_POTION)
	finditem ITEM_HYPER_POTION
	end

JohtoRocketHideout_B3F_EventScript_Item4::      @ item ball (FLAG_ITEM_ROCKETHIDEOUT3_GUARD_SPEC)
	finditem ITEM_GUARD_SPEC
	end

JohtoRocketHideout_B3F_EventScript_Item5::      @ item ball (FLAG_ITEM_ROCKETHIDEOUT3_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end

@ silent until scripted (PokemonHnS data/maps/RocketHideout_B3F_hns/scripts.inc)
JohtoRocketHideout_B3F_EventScript_Door::       @ sign (11,12)
	end
