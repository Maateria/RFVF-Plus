@ johto_import: generated from PokemonHnS data/maps/MtMortar_1F_South_hns; scripted maps get their own file later
MtMortar_1F_South_MapScripts::
	.byte 0

MtMortar_1F_South_EventScript_Item1::           @ item ball (FLAG_ITEM_MTMORTAR1_ELIXIR)
	finditem ITEM_ELIXIR
	end

MtMortar_1F_South_EventScript_Item2::           @ item ball (FLAG_ITEM_MTMORTAR1_TM_AERIAL_ACE)
	finditem ITEM_TM40_AERIAL_ACE
	end

