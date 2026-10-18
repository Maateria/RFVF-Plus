@ johto_import: generated from PokemonHnS data/maps/RuinsOfAlph_PuzzleAndRewardChambers_hns; scripted maps get their own file later
RuinsOfAlph_PuzzleAndRewardChambers_MapScripts::
	.byte 0

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item2:: @ item ball (FLAG_ITEM_RUINSOFALPH_LIFE_ORB)
	finditem ITEM_SHELL_BELL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item3:: @ item ball (FLAG_ITEM_RUINSOFALPH_CHARCOAL)
	finditem ITEM_CHARCOAL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item4:: @ item ball (FLAG_ITEM_RUINSOFALPH_MAX_REVIVE_1)
	finditem ITEM_MAX_REVIVE
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item5:: @ item ball (FLAG_ITEM_RUINSOFALPH_SACRED_ASH)
	finditem ITEM_SACRED_ASH
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item6:: @ item ball (FLAG_ITEM_RUINSOFALPH_HEAL_POWDER_1)
	finditem ITEM_HEAL_POWDER
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item7:: @ item ball (FLAG_ITEM_RUINSOFALPH_ENERGY_ROOT)
	finditem ITEM_ENERGY_ROOT
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item8:: @ item ball (FLAG_ITEM_RUINSOFALPH_SITRUS_BERRY_2)
	finditem ITEM_SITRUS_BERRY
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item9:: @ item ball (FLAG_ITEM_RUINSOFALPH_MOON_STONE)
	finditem ITEM_MOON_STONE
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item10:: @ item ball (FLAG_ITEM_RUINSOFALPH_PECHA_BERRY)
	finditem ITEM_PECHA_BERRY
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item11:: @ item ball (FLAG_ITEM_RUINSOFALPH_ENERGY_POWDER)
	finditem ITEM_ENERGY_POWDER
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item12:: @ item ball (FLAG_ITEM_RUINSOFALPH_HEAL_POWDER_2)
	finditem ITEM_HEAL_POWDER
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item13:: @ item ball (FLAG_ITEM_RUINSOFALPH_ORAN_BERRY)
	finditem ITEM_ORAN_BERRY
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item14:: @ item ball (FLAG_ITEM_RUINSOFALPH_WATER_STONE)
	finditem ITEM_WATER_STONE
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item15:: @ item ball (FLAG_ITEM_RUINSOFALPH_STAR_PIECE)
	finditem ITEM_STAR_PIECE
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item16:: @ item ball (FLAG_ITEM_RUINSOFALPH_STARDUST)
	finditem ITEM_STARDUST
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Item17:: @ item ball (FLAG_ITEM_RUINSOFALPH_LUM_BERRY_2)
	finditem ITEM_LUM_BERRY
	end

@ silent until scripted (PokemonHnS data/maps/RuinsOfAlph_PuzzleAndRewardChambers_hns/scripts.inc)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_Receptionist:: @ ATTENDANT_F_HNS #1 (24,5)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_HoohDescription:: @ sign (4,4)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_KabutoDescripton:: @ sign (20,4)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_OmanyteDescription:: @ sign (4,21)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_AerodactylDescription:: @ sign (20,21)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HooHPuzzle:: @ sign (5,4)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_KabutoPuzzle:: @ sign (21,4)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OmanytePuzzle:: @ sign (5,21)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_AerodactylPuzzle:: @ sign (21,21)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_RuinsOfAlph_PuzzleAndRewardChambers_MapScript_StatueDescription:: @ sign (19,5)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckHooh:: @ sign (4,1)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckKabuto:: @ sign (20,1)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckOmanyte:: @ sign (4,18)
RuinsOfAlph_PuzzleAndRewardChambers_EventScript_CheckAerodactyl:: @ sign (20,18)
	end
