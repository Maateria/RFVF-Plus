@ johto_import: generated from PokemonHnS data/maps/Route35_hns; scripted maps get their own file later
Route35_MapScripts::
	.byte 0

Route35_EventScript_Item10::                    @ item ball (FLAG_ITEM_ROUTE35_PAYBACK)
	finditem ITEM_TM12_TAUNT
	end

Route35_EventScript_Item11::                    @ item ball (FLAG_ITEM_ROUTE35_BIG_NUGGET)
	finditem ITEM_NUGGET
	end

Route35_EventScript_Item12::                    @ item ball (FLAG_ITEM_ROUTE35_PARALYZE_HEAL)
	finditem ITEM_PARALYZE_HEAL
	end

@ silent until scripted (PokemonHnS data/maps/Route35_hns/scripts.inc)
Route35_EventScript_PicnickerKim::              @ PICNICKER_HNS #1 (10,38), trainer TRAINER_KIM_HNS
Route35_EventScript_BirdKeeperBryan::           @ ROCKER_HNS #2 (18,41), trainer TRAINER_BRYAN_HNS
Route35_EventScript_PicnickerBrooke::           @ PICNICKER_HNS #3 (21,23), trainer TRAINER_BROOKE_HNS
Route35_EventScript_CamperElliot::              @ CAMPER_HNS #4 (22,23), trainer TRAINER_ELLIOT_HNS
Route35_EventScript_CamperIvan::                @ CAMPER_HNS #5 (14,23), trainer TRAINER_IVAN_HNS
Route35_EventScript_FirebreatherWalt::          @ FIREBREATHER_HNS #6 (15,11), trainer TRAINER_WALT_HNS
Route35_EventScript_JugglerIrwin::              @ JUGGLER_HNS #7 (18,16), trainer TRAINER_IRWIN_HNS
Route35_EventScript_BugCatcherArnie::           @ BUG_CATCHER_HNS #8 (30,7), trainer TRAINER_ARNIE_HNS
Route35_EventScript_Sign2::                     @ sign (15,7)
Route35_EventScript_Sign1::                     @ sign (11,46)
	end
