@ johto_import: generated from PokemonHnS data/maps/RuinsOfAlph_B1F_hns; scripted maps get their own file later
RuinsOfAlph_B1F_MapScripts::
	.byte 0

RuinsOfAlph_B1F_EventScript_Item4::             @ item ball (FLAG_ITEM_DOME_FOSSIL)
	finditem ITEM_DOME_FOSSIL
	end

RuinsOfAlph_B1F_EventScript_Item5::             @ item ball (FLAG_ITEM_OLD_AMBER)
	finditem ITEM_OLD_AMBER
	end

RuinsOfAlph_B1F_EventScript_Item6::             @ item ball (FLAG_ITEM_HELIX_FOSSIL)
	finditem ITEM_HELIX_FOSSIL
	end

@ silent until scripted (PokemonHnS data/maps/RuinsOfAlph_B1F_hns/scripts.inc)
RuinsOfAlph_B1F_EventScript_Hiker::             @ HIKER_HNS #1 (18,10)
RuinsOfAlph_B1F_EventScript_Gramps::            @ OLD_MAN_HNS #2 (13,23)
RuinsOfAlph_B1F_EventScript_Teacher::           @ WOMAN_2_HNS #3 (19,16)
RuinsOfAlph_B1F_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (22,22)
RuinsOfAlph_B1F_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_UnownText:: @ sign (6,7)
	end
