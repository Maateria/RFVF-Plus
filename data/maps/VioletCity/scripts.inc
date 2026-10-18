@ johto_import: generated from PokemonHnS data/maps/VioletCity_hns; scripted maps get their own file later
VioletCity_MapScripts::
	.byte 0

VioletCity_EventScript_Item5::                  @ item ball (FLAG_ITEM_VIOLET_CITY_PECHA_BERRY)
	finditem ITEM_PECHA_BERRY
	end

VioletCity_EventScript_Item6::                  @ item ball (FLAG_ITEM_VIOLET_CITY_HYPER_POTION)
	finditem ITEM_HYPER_POTION
	end

VioletCity_EventScript_Item8::                  @ item ball (FLAG_ITEM_VIOLET_CITY_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end

@ silent until scripted (PokemonHnS data/maps/VioletCity_hns/scripts.inc)
VioletCity_EventScript_Lass::                   @ WOMAN_2_HNS #1 (32,48)
VioletCity_EventScript_Boy::                    @ BOY_2_HNS #2 (28,25)
VioletCity_EventScript_Gramps::                 @ OLD_MAN_2_HNS #3 (28,36)
VioletCity_EventScript_Youngster::              @ YOUNGSTER_HNS #4 (10,27)
VioletCity_EventScript_GymSign::                @ sign (25,36)
	end
