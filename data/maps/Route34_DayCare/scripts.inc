@ johto_import: generated from PokemonHnS data/maps/Route34_DayCare_hns; scripted maps get their own file later
.equ LOCALID_DAYCARE_LADY, 1

Route34_DayCare_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/Route34_DayCare_hns/scripts.inc)
Route34_DayCare_EventScript_DaycareWoman::      @ OLD_WOMAN_HNS #1 (3,8)
Route34_DayCare_EventScript_Ditto::             @ MON_BASE+SPECIES_DITTO #2 (12,4)
Route34_DayCare_EventScript_Eevee::             @ MON_BASE+SPECIES_EEVEE #3 (12,4)
Route34_DayCare_EventScript_Clerk::             @ MART_EMPLOYEE_HNS #4 (10,3)
Route34_DayCare_EventScript_Route34_DayCare_Bookshelf1:: @ sign (2,1)
Route34_DayCare_EventScript_Route34_DayCare_Bookshelf2:: @ sign (3,1)
Route34_DayCare_EventScript_Route34_DayCare_Bookshelf4:: @ sign (5,1)
Route34_DayCare_EventScript_Route34_DayCare_Bookshelf3:: @ sign (4,1)
	end
