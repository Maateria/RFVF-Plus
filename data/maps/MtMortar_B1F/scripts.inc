@ johto_import: generated from PokemonHnS data/maps/MtMortar_B1F_hns; scripted maps get their own file later
MtMortar_B1F_MapScripts::
	.byte 0

MtMortar_B1F_EventScript_Item3::                @ item ball (FLAG_ITEM_MTMORTAR4_PP_UP)
	finditem ITEM_PP_UP
	end

MtMortar_B1F_EventScript_Item4::                @ item ball (FLAG_ITEM_MTMORTAR4_MAX_REVIVE)
	finditem ITEM_MAX_REVIVE
	end

MtMortar_B1F_EventScript_Item5::                @ item ball (FLAG_ITEM_MTMORTAR4_CARBOS)
	finditem ITEM_CARBOS
	end

MtMortar_B1F_EventScript_Item6::                @ item ball (FLAG_ITEM_MTMORTAR4_MAX_ETHER)
	finditem ITEM_MAX_ETHER
	end

MtMortar_B1F_EventScript_Item7::                @ item ball (FLAG_ITEM_MTMORTAR4_HYPER_POTION)
	finditem ITEM_HYPER_POTION
	end

@ silent until scripted (PokemonHnS data/maps/MtMortar_B1F_hns/scripts.inc)
MtMortar_B1F_EventScript_Kiyo::                 @ BLACK_BELT_HNS #2 (39,8), trainer TRAINER_KIYO_HNS
	end
