@ johto_import: generated from PokemonHnS data/maps/Route42_hns; scripted maps get their own file later
Route42_MapScripts::
	.byte 0

Route42_EventScript_Item1::                     @ item ball (FLAG_ITEM_ROUTE42_SUPER_POTION)
	finditem ITEM_SUPER_POTION
	end

Route42_EventScript_Item2::                     @ item ball (FLAG_ITEM_ROUTE42_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end

Route42_EventScript_Item7::                     @ item ball (FLAG_ITEM_ROUTE42_TM_SHADOW_CLAW)
	finditem ITEM_TM30_SHADOW_BALL
	end

@ silent until scripted (PokemonHnS data/maps/Route42_hns/scripts.inc)
Route42_EventScript_Tully::                     @ FISHERMAN_HNS #4 (40,18), trainer TRAINER_TULLY_HNS
Route42_EventScript_Shane::                     @ SUPER_NERD_HNS #5 (77,11), trainer TRAINER_SHANE_HNS
Route42_EventScript_Ben::                       @ HIKER_HNS #6 (84,14), trainer TRAINER_BENJAMIN_HNS
Route42_EventScript_MortarSign::                @ sign (18,9)
Route42_EventScript_Sign::                      @ sign (89,10)
	end
