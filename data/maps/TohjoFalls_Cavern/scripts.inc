@ johto_import: generated from PokemonHnS data/maps/TohjoFalls_Cavern_hns; scripted maps get their own file later
TohjoFalls_Cavern_MapScripts::
	.byte 0

TohjoFalls_Cavern_EventScript_Item1::           @ item ball (FLAG_ITEM_TOHJOFALLS_HEART_SCALE)
	finditem ITEM_HEART_SCALE
	end

