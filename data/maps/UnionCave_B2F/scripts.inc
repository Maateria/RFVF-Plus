@ johto_import: generated from PokemonHnS data/maps/UnionCave_B2F_hns; scripted maps get their own file later
UnionCave_B2F_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_Item1::               @ item ball (FLAG_ITEM_UNION_CAVE_ETHER)
	finditem ITEM_ETHER
	end

UnionCave_B2F_EventScript_Item3::               @ item ball (FLAG_ITEM_UNION_CAVE_MAXREVIVE)
	finditem ITEM_MAX_REVIVE
	end

UnionCave_B2F_EventScript_Item6::               @ item ball (FLAG_ITEM_UNION_CAVE_HYPERPOTION)
	finditem ITEM_HYPER_POTION
	end

@ silent until scripted (PokemonHnS data/maps/UnionCave_B2F_hns/scripts.inc)
UnionCave_B2F_EventScript_CooltrainerNick::     @ COOLTRAINER_M_HNS #2 (6,12), trainer TRAINER_NICK_HNS
UnionCave_B2F_EventScript_CooltrainerfGwen::    @ COOLTRAINER_F_HNS #4 (17,20), trainer TRAINER_GWEN_HNS
UnionCave_B2F_EventScript_CooltrainerfEmma::    @ COOLTRAINER_F_HNS #5 (2,27), trainer TRAINER_EMMA_HNS
	end
