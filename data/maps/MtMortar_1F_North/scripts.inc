@ johto_import: generated from PokemonHnS data/maps/MtMortar_1F_North_hns; scripted maps get their own file later
MtMortar_1F_North_MapScripts::
	.byte 0

MtMortar_1F_North_EventScript_Item1::           @ item ball (FLAG_ITEM_MTMORTAR2_MAX_REPEL)
	finditem ITEM_MAX_REPEL
	end

MtMortar_1F_North_EventScript_Item2::           @ item ball (FLAG_ITEM_MTMORTAR2_ESCAPE_ROPE)
	finditem ITEM_ESCAPE_ROPE
	end

MtMortar_1F_North_EventScript_Item3::           @ item ball (FLAG_ITEM_MTMORTAR2_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end

MtMortar_1F_North_EventScript_Item4::           @ item ball (FLAG_ITEM_MTMORTAR2_PROTECTOR)
	finditem ITEM_HARD_STONE
	end

MtMortar_1F_North_EventScript_Item5::           @ item ball (FLAG_ITEM_MTMORTAR2_MAX_POTION)
	finditem ITEM_MAX_POTION
	end

MtMortar_1F_North_EventScript_Item6::           @ item ball (FLAG_ITEM_MTMORTAR2_REVIVE)
	finditem ITEM_REVIVE
	end

MtMortar_1F_North_EventScript_Item7::           @ item ball (FLAG_ITEM_MTMORTAR2_KINGS_ROCK)
	finditem ITEM_KINGS_ROCK
	end

@ silent until scripted (PokemonHnS data/maps/MtMortar_1F_North_hns/scripts.inc)
MtMortar_1F_North_EventScript_Markus::          @ SUPER_NERD_HNS #8 (36,42), trainer TRAINER_MARKUS_HNS
MtMortar_1F_North_EventScript_Miller::          @ FAT_MAN_HNS #9 (51,63), trainer TRAINER_MILLER_HNS
	end
