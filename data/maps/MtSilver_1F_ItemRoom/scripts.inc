@ johto_import: generated from PokemonHnS data/maps/MtSilver_1F_ItemRoom_hns; scripted maps get their own file later
MtSilver_1F_ItemRoom_MapScripts::
	.byte 0

MtSilver_1F_ItemRoom_EventScript_Item1::        @ item ball (FLAG_ITEM_MTSILVER_SPELL_TAG)
	finditem ITEM_SPELL_TAG
	end

