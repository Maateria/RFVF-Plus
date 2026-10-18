@ johto_import: generated from PokemonHnS data/maps/Route46_hns; scripted maps get their own file later
Route46_MapScripts::
	.byte 0

Route46_EventScript_Item1::                     @ item ball (FLAG_ITEM_ROUTE46_REVIVE)
	finditem ITEM_REVIVE
	end

@ silent until scripted (PokemonHnS data/maps/Route46_hns/scripts.inc)
Route46_EventScript_Ted::                       @ CAMPER_HNS #2 (6,18), trainer TRAINER_TED_HNS
Route46_EventScript_Erin::                      @ PICNICKER_HNS #3 (4,18), trainer TRAINER_ERIN_HNS
Route46_EventScript_Bailey::                    @ HIKER_HNS #4 (19,25), trainer TRAINER_BAILEY_HNS
Route46_EventScript_Sign::                      @ sign (11,35)
	end
