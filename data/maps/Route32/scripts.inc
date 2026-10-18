@ johto_import: generated from PokemonHnS data/maps/Route32_hns; scripted maps get their own file later
.equ LOCALID_ROUTE32_BALDINGMAN, 1
.equ LOCALID_SLOWPOKETAIL_MAN, 14

Route32_MapScripts::
	.byte 0

Route32_EventScript_Item3::                     @ item ball (FLAG_ITEM_ROUTE_32_SUPERPOTION)
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Item4::                     @ item ball (FLAG_ITEM_ROUTE_32_GREATBALL)
	finditem ITEM_GREAT_BALL
	end

Route32_EventScript_Item5::                     @ item ball (FLAG_ITEM_ROUTE32_TM_BULLET_SEED)
	finditem ITEM_TM09_BULLET_SEED
	end

Route32_EventScript_Item15::                    @ item ball (FLAG_ITEM_ROUTE_32_GREATBALL2)
	finditem ITEM_GREAT_BALL
	end

@ silent until scripted (PokemonHnS data/maps/Route32_hns/scripts.inc)
Route32_EventScript_BaldingMan::                @ BALDING_MAN_HNS #1 (26,10)
Route32_EventScript_Roar::                      @ FAT_MAN_HNS #2 (22,13)
Route32_EventScript_YoungsterAlbert::           @ YOUNGSTER_HNS #6 (22,23), trainer TRAINER_ALBERT_HNS
Route32_EventScript_PicnickerLiz::              @ PICNICKER_HNS #7 (20,31), trainer TRAINER_LIZ_HNS
Route32_EventScript_CamperRoland::              @ CAMPER_HNS #9 (14,45), trainer TRAINER_ROLAND_HNS
Route32_EventScript_FisherRalph::               @ FISHERMAN_HNS #10 (25,57), trainer TRAINER_RALPH_HNS
Route32_EventScript_FisherHenry::               @ FISHERMAN_HNS #11 (28,63), trainer TRAINER_HENRY_HNS
Route32_EventScript_FisherJustin::              @ FISHERMAN_HNS #12 (20,56), trainer TRAINER_JUSTIN_HNS
Route32_EventScript_YoungsterGordon::           @ YOUNGSTER_HNS #13 (15,63), trainer TRAINER_GORDON_HNS
Route32_EventScript_SlowpokeTail::              @ FAT_MAN_HNS #14 (14,80)
Route32_EventScript_BirdkeeperPeter::           @ ROCKER_HNS #16 (24,95), trainer TRAINER_PETER_HNS
Route32_EventScript_Frieda::                    @ BATTLE_GIRL_HNS #17 (27,78)
Route32_EventScript_LiquidJustice::             @ COOLTRAINER_M_HNS #19 (8,58)
Route32_EventScript_Sign1::                     @ sign (22,5)
Route32_EventScript_Sign2::                     @ sign (17,1)
Route32_EventScript_Sign3::                     @ sign (20,96)
	end
