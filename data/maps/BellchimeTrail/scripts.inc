@ johto_import: generated from PokemonHnS data/maps/BellchimeTrail_hns; scripted maps get their own file later
BellchimeTrail_MapScripts::
	.byte 0

BellchimeTrail_EventScript_Item1::              @ item ball (FLAG_ITEM_BELLCHIME_BIG_MUSHROOM)
	finditem ITEM_BIG_MUSHROOM
	end

@ silent until scripted (PokemonHnS data/maps/BellchimeTrail_hns/scripts.inc)
BellchimeTrail_EventScript_Door::               @ sign (54,58)
	end
