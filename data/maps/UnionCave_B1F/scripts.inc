@ johto_import: generated from PokemonHnS data/maps/UnionCave_B1F_hns; scripted maps get their own file later
UnionCave_B1F_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_Item3::               @ item ball (FLAG_ITEM_UNION_CAVE_ROCK_TOMB)
	finditem ITEM_TM39_ROCK_TOMB
	end

UnionCave_B1F_EventScript_Item5::               @ item ball (FLAG_ITEM_UNION_CAVE_X_DEFEND)
	finditem ITEM_X_DEFEND
	end

@ silent until scripted (PokemonHnS data/maps/UnionCave_B1F_hns/scripts.inc)
UnionCave_B1F_EventScript_HikerPhillip::        @ HIKER_HNS #1 (9,2), trainer TRAINER_PHILLIP_HNS
UnionCave_B1F_EventScript_HikerLeonard::        @ HIKER_HNS #2 (13,12), trainer TRAINER_LEONARD_HNS
UnionCave_B1F_EventScript_PokemaniacCalvin::    @ SUPER_NERD_HNS #6 (20,39), trainer TRAINER_CALVIN_HNS
UnionCave_B1F_EventScript_PokemaniacAndrew::    @ SUPER_NERD_HNS #7 (3,44), trainer TRAINER_ANDREW_HNS
	end
