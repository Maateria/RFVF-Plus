@ johto_import: generated from PokemonHnS data/maps/Route27_hns; scripted maps get their own file later
.equ LOCALID_ROUTE27_FATMAN, 1

Route27_MapScripts::
	.byte 0

Route27_EventScript_Item6::                     @ item ball (FLAG_ITEM_ROUTE27_RARECANDY)
	finditem ITEM_RARE_CANDY
	end

Route27_EventScript_Item7::                     @ item ball (FLAG_ITEM_ROUTE27_MOONSTONE)
	finditem ITEM_MOON_STONE
	end

Route27_EventScript_Item11::                    @ item ball (FLAG_ITEM_ROUTE27_DRAGONCLAW)
	finditem ITEM_TM02_DRAGON_CLAW
	end

Route27_EventScript_Item12::                    @ item ball (FLAG_ITEM_ROUTE27_DESTINY_KNOT)
	finditem ITEM_MENTAL_HERB
	end

@ silent until scripted (PokemonHnS data/maps/Route27_hns/scripts.inc)
Route27_EventScript_Fatman::                    @ FAT_MAN_HNS #1 (27,24)
Route27_EventScript_Megan::                     @ COOLTRAINER_F_HNS #2 (44,22), trainer TRAINER_MEGAN_HNS
Route27_EventScript_Brian::                     @ COOLTRAINER_M_HNS #3 (66,19), trainer TRAINER_BRIAN_HNS
Route27_EventScript_Jose::                      @ ROCKER_HNS #4 (77,27), trainer TRAINER_JOSE_HNS
Route27_EventScript_Blake::                     @ COOLTRAINER_M_HNS #5 (89,18), trainer TRAINER_BLAKE_HNS
Route27_EventScript_Gilbert::                   @ PSYCHIC_M_HNS #8 (100,18), trainer TRAINER_GILBERT_HNS
Route27_EventScript_Reena::                     @ COOLTRAINER_F_HNS #9 (127,12), trainer TRAINER_REENA_HNS
Route27_EventScript_Scott::                     @ FISHERMAN_HNS #10 (145,25), trainer TRAINER_SCOTT_HNS
Route27_EventScript_TohjoFallsSign::            @ sign (32,20)
	end
