@ johto_import: generated from PokemonHnS data/maps/IlexForest_hns; scripted maps get their own file later
.equ LOCALID_ILEX_FOREST_BUTTERFREE, 8

IlexForest_MapScripts::
	.byte 0

IlexForest_EventScript_Item5::                  @ item ball (FLAG_ITEM_ILEX_FOREST_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end

IlexForest_EventScript_Item6::                  @ item ball (FLAG_ITEM_ILEX_FOREST_ETHER)
	finditem ITEM_ETHER
	end

IlexForest_EventScript_Item7::                  @ item ball (FLAG_ITEM_ILEX_FOREST_SUPER_POTION)
	finditem ITEM_SUPER_POTION
	end

IlexForest_EventScript_Item9::                  @ item ball (FLAG_ITEM_ILEX_FOREST_TM_FALSE_SWIPE)
	finditem ITEM_TM46_THIEF
	end

@ silent until scripted (PokemonHnS data/maps/IlexForest_hns/scripts.inc)
IlexForest_EventScript_Picnicker::              @ PICNICKER_HNS #2 (37,21)
IlexForest_EventScript_HeadbuttMoveTutor::      @ FAT_MAN_HNS #3 (42,26)
IlexForest_EventScript_BugcatcherWayne::        @ BUG_CATCHER_HNS #4 (39,8), trainer TRAINER_WAYNE_HNS
IlexForest_EventScript_FuryCutterTutor::        @ LITTLE_BOY_HNS #8 (24,14)
IlexForest_EventScript_Shrine::                 @ sign (32,36)
IlexForest_EventScript_Sign::                   @ sign (23,27)
	end
