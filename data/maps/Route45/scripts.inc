@ johto_import: generated from PokemonHnS data/maps/Route45_hns; scripted maps get their own file later
Route45_MapScripts::
	.byte 0

Route45_EventScript_Item3::                     @ item ball (FLAG_ITEM_ROUTE45_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item5::                     @ item ball (FLAG_ITEM_ROUTE45_NUGGET)
	finditem ITEM_NUGGET
	end

Route45_EventScript_Item8::                     @ item ball (FLAG_ITEM_ROUTE45_ELIXIR)
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item10::                    @ item ball (FLAG_ITEM_ROUTE45_MAX_POTION)
	finditem ITEM_MAX_POTION
	end

@ silent until scripted (PokemonHnS data/maps/Route45_hns/scripts.inc)
Route45_EventScript_Erik::                      @ HIKER_HNS #1 (8,10), trainer TRAINER_ERIK_HNS
Route45_EventScript_Ryan::                      @ ROCKER_HNS #2 (37,25), trainer TRAINER_RYAN_HNS
Route45_EventScript_Michael::                   @ HIKER_HNS #4 (25,28), trainer TRAINER_MICHAEL_HNS
Route45_EventScript_Kelly::                     @ BATTLE_GIRL_HNS #6 (30,14), trainer TRAINER_KELLY_HNS
Route45_EventScript_Kenji::                     @ BLACK_BELT_HNS #7 (28,45), trainer TRAINER_KENJI_HNS
Route45_EventScript_Timothy::                   @ HIKER_HNS #9 (33,64), trainer TRAINER_TIMOTHY_HNS
Route45_EventScript_Parry::                     @ HIKER_HNS #11 (29,61), trainer TRAINER_PARRY_HNS
Route45_EventScript_Quentin::                   @ CAMPER_HNS #12 (12,73), trainer TRAINER_QUENTIN_HNS
Route45_EventScript_Sign::                      @ sign (31,4)
	end
