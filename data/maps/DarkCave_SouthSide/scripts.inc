@ johto_import: generated from PokemonHnS data/maps/DarkCave_SouthSide_hns; scripted maps get their own file later
DarkCave_SouthSide_MapScripts::
	.byte 0

DarkCave_SouthSide_EventScript_Item1::          @ item ball (FLAG_ITEM_DARKCAVE1_POTION)
	finditem ITEM_POTION
	end

DarkCave_SouthSide_EventScript_Item6::          @ item ball (FLAG_ITEM_DARKCAVE1_REVIVE)
	finditem ITEM_REVIVE
	end

DarkCave_SouthSide_EventScript_Item7::          @ item ball (FLAG_ITEM_DARKCAVE1_MAX_REVIVE)
	finditem ITEM_MAX_REVIVE
	end

DarkCave_SouthSide_EventScript_Item8::          @ item ball (FLAG_ITEM_DARKCAVE1_ELIXIR)
	finditem ITEM_ELIXIR
	end

