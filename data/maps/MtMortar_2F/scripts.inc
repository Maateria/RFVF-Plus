@ johto_import: generated from PokemonHnS data/maps/MtMortar_2F_hns; scripted maps get their own file later
MtMortar_2F_MapScripts::
	.byte 0

MtMortar_2F_EventScript_Item1::                 @ item ball (FLAG_ITEM_MTMORTAR3_IRON)
	finditem ITEM_IRON
	end

MtMortar_2F_EventScript_Item2::                 @ item ball (FLAG_ITEM_MTMORTAR3_MAX_REVIVE)
	finditem ITEM_MAX_REVIVE
	end

MtMortar_2F_EventScript_Item3::                 @ item ball (FLAG_ITEM_MTMORTAR3_ETHER)
	finditem ITEM_ETHER
	end

MtMortar_2F_EventScript_Item4::                 @ item ball (FLAG_ITEM_MTMORTAR3_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end

MtMortar_2F_EventScript_Item5::                 @ item ball (FLAG_ITEM_MTMORTAR3_DRAGON_SCALE)
	finditem ITEM_DRAGON_SCALE
	end

MtMortar_2F_EventScript_Item6::                 @ item ball (FLAG_ITEM_MTMORTAR3_ELIXIR)
	finditem ITEM_ELIXIR
	end

@ silent until scripted (PokemonHnS data/maps/MtMortar_2F_hns/scripts.inc)
MtMortar_2F_EventScript_Nerd::                  @ SUPER_NERD_HNS #7 (17,31), trainer TRAINER_HUGH_HNS
	end
