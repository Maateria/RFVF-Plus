@ johto_import: generated from PokemonHnS data/maps/RocketHideout_B1F_hns; scripted maps get their own file later
JohtoRocketHideout_B1F_MapScripts::
	.byte 0

JohtoRocketHideout_B1F_EventScript_Item1::      @ item ball (FLAG_ITEM_ROCKETHIDEOUT1_HYPER_POTION)
	finditem ITEM_HYPER_POTION
	end

JohtoRocketHideout_B1F_EventScript_Item2::      @ item ball (FLAG_ITEM_ROCKETHIDEOUT1_REVIVE)
	finditem ITEM_REVIVE
	end

JohtoRocketHideout_B1F_EventScript_Item3::      @ item ball (FLAG_ITEM_ROCKETHIDEOUT1_BIG_NUGGET)
	finditem ITEM_NUGGET
	end

@ silent until scripted (PokemonHnS data/maps/RocketHideout_B1F_hns/scripts.inc)
JohtoRocketHideout_B1F_EventScript_DummyPanel:: @ sign (39,1)
JohtoRocketHideout_B1F_EventScript_Switch::     @ sign (31,11)
JohtoRocketHideout_B1F_EventScript_Persian::    @ sign (45,7)
	end
