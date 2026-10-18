@ johto_import: generated from PokemonHnS data/maps/DarkCave_NorthSide_hns; scripted maps get their own file later
DarkCave_NorthSide_MapScripts::
	.byte 0

DarkCave_NorthSide_EventScript_Item1::          @ item ball (FLAG_ITEM_DARKCAVE2_BLACK_FLUTE)
	finditem ITEM_BLACK_FLUTE
	end

DarkCave_NorthSide_EventScript_Item2::          @ item ball (FLAG_ITEM_DARKCAVE2_STAR_PIECE)
	finditem ITEM_STAR_PIECE
	end

@ silent until scripted (PokemonHnS data/maps/DarkCave_NorthSide_hns/scripts.inc)
DarkCave_NorthSide_EventScript_BlackGlasses::   @ SUPER_NERD_HNS #3 (8,5)
	end
