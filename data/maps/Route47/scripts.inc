@ johto_import: generated from PokemonHnS data/maps/Route47_hns; scripted maps get their own file later
Route47_MapScripts::
	.byte 0

Route47_EventScript_Item3::                     @ item ball (FLAG_ITEM_ROUTE47_REVIVE)
	finditem ITEM_REVIVE
	end

Route47_EventScript_Item6::                     @ item ball (FLAG_ITEM_ROUTE47_WHITE_FLUTE)
	finditem ITEM_WHITE_FLUTE
	end

Route47_EventScript_Item9::                     @ item ball (FLAG_ITEM_ROUTE47_PEARL)
	finditem ITEM_PEARL
	end

Route47_EventScript_Item10::                    @ item ball (FLAG_ITEM_ROUTE47_STARDUST)
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item11::                    @ item ball (FLAG_ITEM_LUCKY_PUNCH)
	finditem ITEM_LUCKY_PUNCH
	end

@ silent until scripted (PokemonHnS data/maps/Route47_hns/scripts.inc)
Route47_EventScript_Hiker::                     @ HIKER_HNS #1 (89,39), trainer TRAINER_DEVIN_HNS
Route47_EventScript_Camper::                    @ CAMPER_HNS #2 (71,37), trainer TRAINER_GRANT_HNS
Route47_EventScript_Kae::                       @ COOLTRAINER_F_HNS #4 (86,29), trainer TRAINER_THOM_AND_KAE_HNS
Route47_EventScript_Thom::                      @ COOLTRAINER_M_HNS #5 (86,30), trainer TRAINER_THOM_AND_KAE_HNS
Route47_EventScript_Duff::                      @ WORKER_M_HNS #7 (57,15), trainer TRAINER_DUFF_AND_EDA_HNS
Route47_EventScript_Eda::                       @ WORKER_F_HNS #8 (58,15), trainer TRAINER_DUFF_AND_EDA_HNS
	end
