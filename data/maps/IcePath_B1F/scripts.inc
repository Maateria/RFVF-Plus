@ johto_import: generated from PokemonHnS data/maps/IcePath_B1F_hns; scripted maps get their own file later
IcePath_B1F_MapScripts::
	.byte 0

IcePath_B1F_EventScript_Item1::                 @ item ball (FLAG_ITEM_ICEPATH2_IRON)
	finditem ITEM_IRON
	end

IcePath_B1F_EventScript_Item2::                 @ item ball (FLAG_ITEM_ICEPATH2_REVIVE)
	finditem ITEM_REVIVE
	end

@ silent until scripted (PokemonHnS data/maps/IcePath_B1F_hns/scripts.inc)
IcePath_B1F_EventScript_Sign::                  @ sign (4,12)
IcePath_B1F_EventScript_PuzzleSkipButton::      @ sign (4,13)
	end
