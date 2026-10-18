@ johto_import: generated from PokemonHnS data/maps/GoldenrodCity_DepartmentStoreBasement_hns; scripted maps get their own file later
.equ LOCALID_GOLDENROD_BOULDER1, 1
.equ LOCALID_GOLDENROD_BOULDER2, 2
.equ LOCALID_GOLDENROD_BOULDER3, 3
.equ LOCALID_GOLDENROD_MACHOKE1, 11
.equ LOCALID_GOLDENROD_MACHOKE2, 12
.equ LOCALID_GOLDENROD_MACHOKE3, 13

GoldenrodCity_DepartmentStoreBasement_MapScripts::
	.byte 0

GoldenrodCity_DepartmentStoreBasement_EventScript_Item4:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_AMULET_COIN)
	finditem ITEM_AMULET_COIN
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_Item5:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_Item6:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_EXP_SHARE)
	finditem ITEM_EXP_SHARE
	end

GoldenrodCity_DepartmentStoreBasement_EventScript_Item7:: @ item ball (FLAG_ITEM_GOLDENROD_UNDERGROUND_ETHER)
	finditem ITEM_ETHER
	end

@ silent until scripted (PokemonHnS data/maps/GoldenrodCity_DepartmentStoreBasement_hns/scripts.inc)
GoldenrodCity_DepartmentStoreBasement_EventScript_BlackBelt2:: @ BLACK_BELT_HNS #8 (16,11)
GoldenrodCity_DepartmentStoreBasement_EventScript_BlackBelt1:: @ BLACK_BELT_HNS #9 (5,9)
GoldenrodCity_DepartmentStoreBasement_EventScript_BlackBelt3:: @ BLACK_BELT_HNS #10 (12,14)
GoldenrodCity_DepartmentStoreBasement_EventScript_Machoke:: @ MON_BASE+SPECIES_MACHOKE #11 (5,11)
	end
