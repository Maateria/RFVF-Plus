@ johto_import: generated from PokemonHnS data/maps/UnionCave_1F_hns; scripted maps get their own file later
UnionCave_1F_MapScripts::
	.byte 0

UnionCave_1F_EventScript_Item1::                @ item ball (FLAG_ITEM_UNION_CAVE_POTION)
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item4::                @ item ball (FLAG_ITEM_UNION_CAVE_AWAKENING)
	finditem ITEM_AWAKENING
	end

UnionCave_1F_EventScript_Item6::                @ item ball (FLAG_ITEM_UNION_CAVE_GREAT_BALL)
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item9::                @ item ball (FLAG_ITEM_UNION_CAVE_X_ATTACK)
	finditem ITEM_X_ATTACK
	end

@ silent until scripted (PokemonHnS data/maps/UnionCave_1F_hns/scripts.inc)
UnionCave_1F_EventScript_HikerDaniel::          @ HIKER_HNS #2 (16,13), trainer TRAINER_DANIEL_HNS
UnionCave_1F_EventScript_HikerRussell::         @ HIKER_HNS #3 (24,3), trainer TRAINER_RUSSELL_HNS
UnionCave_1F_EventScript_FirebreatherBill::     @ FIREBREATHER_HNS #5 (27,30), trainer TRAINER_BILL_HNS
UnionCave_1F_EventScript_PokemaniacLarry::      @ SUPER_NERD_HNS #7 (7,31), trainer TRAINER_LARRY_HNS
UnionCave_1F_EventScript_FirebreatherRay::      @ FIREBREATHER_HNS #8 (25,37), trainer TRAINER_RAY_HNS
	end
