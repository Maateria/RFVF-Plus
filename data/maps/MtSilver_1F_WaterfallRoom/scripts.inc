@ johto_import: generated from PokemonHnS data/maps/MtSilver_1F_WaterfallRoom_hns; scripted maps get their own file later
MtSilver_1F_WaterfallRoom_MapScripts::
	.byte 0

MtSilver_1F_WaterfallRoom_EventScript_Item1::   @ item ball (FLAG_ITEM_MTSILVER_FULLRESTORE)
	finditem ITEM_FULL_RESTORE
	end

MtSilver_1F_WaterfallRoom_EventScript_Item2::   @ item ball (FLAG_ITEM_MTSILVER_MAXPOTION)
	finditem ITEM_MAX_POTION
	end

MtSilver_1F_WaterfallRoom_EventScript_Item3::   @ item ball (FLAG_ITEM_MTSILVER_DIREHIT)
	finditem ITEM_DIRE_HIT
	end

MtSilver_1F_WaterfallRoom_EventScript_Item4::   @ item ball (FLAG_ITEM_MTSILVER_ULTRABALL)
	finditem ITEM_ULTRA_BALL
	end

