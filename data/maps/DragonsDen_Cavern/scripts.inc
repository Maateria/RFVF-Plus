@ johto_import: generated from PokemonHnS data/maps/DragonsDen_Cavern_hns; scripted maps get their own file later
DragonsDen_Cavern_MapScripts::
	.byte 0

DragonsDen_Cavern_EventScript_Item5::           @ item ball (FLAG_ITEM_DRAGONSDEN2_PP_MAX)
	finditem ITEM_PP_MAX
	end

DragonsDen_Cavern_EventScript_Item6::           @ item ball (FLAG_ITEM_DRAGONSDEN2_MAX_POTION)
	finditem ITEM_MAX_POTION
	end

DragonsDen_Cavern_EventScript_Item7::           @ item ball (FLAG_ITEM_DRAGONSDEN2_DRAGON_FANG)
	finditem ITEM_DRAGON_FANG
	end

@ silent until scripted (PokemonHnS data/maps/DragonsDen_Cavern_hns/scripts.inc)
DragonsDen_Cavern_EventScript_Darin::           @ COOLTRAINER_M_HNS #1 (36,13), trainer TRAINER_DARIN_HNS
DragonsDen_Cavern_EventScript_TwinPia::         @ TWIN_HNS #2 (7,32), trainer TRAINER_LEA_AND_PIA_HNS
DragonsDen_Cavern_EventScript_TwinLea::         @ TWIN_HNS #3 (7,31), trainer TRAINER_LEA_AND_PIA_HNS
DragonsDen_Cavern_EventScript_Cara::            @ COOLTRAINER_F_HNS #4 (13,19), trainer TRAINER_CARA_HNS
DragonsDen_Cavern_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (27,46)
	end
