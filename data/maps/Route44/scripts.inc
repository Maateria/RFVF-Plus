@ johto_import: generated from PokemonHnS data/maps/Route44_hns; scripted maps get their own file later
Route44_MapScripts::
	.byte 0

Route44_EventScript_Item7::                     @ item ball (FLAG_ITEM_ROUTE44_ELIXIR)
	finditem ITEM_ELIXIR
	end

Route44_EventScript_Item8::                     @ item ball (FLAG_ITEM_ROUTE44_MAX_REPEL)
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item9::                     @ item ball (FLAG_ITEM_ROUTE44_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end

@ silent until scripted (PokemonHnS data/maps/Route44_hns/scripts.inc)
Route44_EventScript_Phil::                      @ PSYCHIC_M_HNS #1 (11,5), trainer TRAINER_PHIL_HNS
Route44_EventScript_Edgar::                     @ FISHERMAN_HNS #2 (28,23), trainer TRAINER_EDGAR_HNS
Route44_EventScript_Wilton::                    @ FISHERMAN_HNS #3 (40,5), trainer TRAINER_WILTON_HNS
Route44_EventScript_Zach::                      @ SUPER_NERD_HNS #4 (49,3), trainer TRAINER_ZACH_HNS
Route44_EventScript_Allen::                     @ COOLTRAINER_M_HNS #5 (64,13), trainer TRAINER_ALLEN_HNS
Route44_EventScript_Cybil::                     @ COOLTRAINER_F_HNS #6 (46,22), trainer TRAINER_CYBIL_HNS
Route44_EventScript_Vance::                     @ ROCKER_HNS #10 (17,20), trainer TRAINER_VANCE_HNS
Route44_EventScript_Sign1::                     @ sign (66,13)
Route44_EventScript_Sign2::                     @ sign (5,17)
	end
