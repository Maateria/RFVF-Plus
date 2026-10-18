@ johto_import: generated from PokemonHnS data/maps/Route36_hns; scripted maps get their own file later
.equ LOCALID_ROUTE36_ROCKSMASHGUY, 3

Route36_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/Route36_hns/scripts.inc)
Route36_EventScript_Lass::                      @ BATTLE_GIRL_HNS #1 (57,20)
Route36_EventScript_Arthur::                    @ BOY_2_HNS #2 (47,16)
Route36_EventScript_RockSmashGuy::              @ BLACK_BELT_HNS #3 (46,20)
Route36_EventScript_Mark::                      @ PSYCHIC_M_HNS #4 (24,24), trainer TRAINER_MARK_HNS
Route36_EventScript_Schoolboy::                 @ LITTLE_BOY_HNS #5 (31,23), trainer TRAINER_ALAN_HNS
Route36_EventScript_Sign::                      @ sign (54,23)
Route36_EventScript_Sign2::                     @ sign (25,16)
	end
