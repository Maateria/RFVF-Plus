@ johto_import: generated from PokemonHnS data/maps/MtSilver_MountainSide_hns; scripted maps get their own file later
MtSilver_MountainSide_MapScripts::
	.byte 0

MtSilver_MountainSide_EventScript_Item1::       @ item ball (FLAG_ITEM_MT_SILVER_CAVE_TM_STEALTH_ROCK)
	finditem ITEM_TM39_ROCK_TOMB
	end

