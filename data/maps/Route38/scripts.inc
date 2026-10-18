@ johto_import: generated from PokemonHnS data/maps/Route38_hns; scripted maps get their own file later
Route38_MapScripts::
	.byte 0

Route38_EventScript_Item9::                     @ item ball (FLAG_ITEM_ROUTE38_LAX_INCENSE)
	finditem ITEM_LAX_INCENSE
	end

@ silent until scripted (PokemonHnS data/maps/Route38_hns/scripts.inc)
Route38_EventScript_Harry::                     @ SAILOR_HNS #1 (39,7), trainer TRAINER_HARRY_HNS
Route38_EventScript_Dana::                      @ LASS_HNS #2 (28,12), trainer TRAINER_DANA_HNS
Route38_EventScript_Olivia::                    @ WOMAN_2_HNS #3 (15,6), trainer TRAINER_OLIVIA_HNS
Route38_EventScript_Toby::                      @ ROCKER_HNS #4 (13,28), trainer TRAINER_TOBY_HNS
Route38_EventScript_Chad::                      @ LITTLE_BOY_HNS #5 (2,7), trainer TRAINER_CHAD_HNS
Route38_EventScript_Valerie::                   @ BEAUTY_HNS #6 (38,29), trainer TRAINER_VALERIE_HNS
Route38_EventScript_Sign1::                     @ sign (42,14)
Route38_EventScript_Sign2::                     @ sign (15,27)
	end
