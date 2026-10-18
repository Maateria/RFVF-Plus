@ johto_import: generated from PokemonHnS data/maps/GoldenrodCity_DepartmentStore_7F_hns; scripted maps get their own file later
.equ LOCALID_GOLDENROD_ROOF_NERD, 1

GoldenrodCity_DepartmentStore_7F_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/GoldenrodCity_DepartmentStore_7F_hns/scripts.inc)
GoldenrodCity_DepartmentStore_7F_EventScript_Nerd:: @ SUPER_NERD_HNS #1 (22,11)
GoldenrodCity_DepartmentStore_7F_EventScript_PokefanF:: @ WOMAN_2_HNS #2 (19,8)
GoldenrodCity_DepartmentStore_7F_EventScript_PokefanM:: @ FAT_MAN_HNS #3 (11,6)
GoldenrodCity_DepartmentStore_7F_EventScript_Bugcatcher:: @ BUG_CATCHER_HNS #4 (12,10)
GoldenrodCity_DepartmentStore_7F_EventScript_VendingMachine:: @ sign (10,5)
	end
