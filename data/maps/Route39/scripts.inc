@ johto_import: generated from PokemonHnS data/maps/Route39_hns; scripted maps get their own file later
Route39_MapScripts::
	.byte 0

Route39_EventScript_Item9::                     @ item ball (FLAG_ITEM_ROUTE39_TM_DRAIN_PUNCH)
	finditem ITEM_TM31_BRICK_BREAK
	end

Route39_EventScript_Item10::                    @ item ball (FLAG_ITEM_ROUTE39_NUGGET)
	finditem ITEM_NUGGET
	end

@ silent until scripted (PokemonHnS data/maps/Route39_hns/scripts.inc)
Route39_EventScript_Norman::                    @ PSYCHIC_M_HNS #1 (29,17), trainer TRAINER_NORMAN_HNS
Route39_EventScript_Ruth::                      @ WOMAN_1_HNS #2 (22,38), trainer TRAINER_RUTH_HNS
Route39_EventScript_Derek::                     @ BALDING_MAN_HNS #3 (29,40), trainer TRAINER_DEREK_HNS
Route39_EventScript_Eugene::                    @ SAILOR_HNS #4 (22,42), trainer TRAINER_EUGENE_HNS
Route39_EventScript_Miltank::                   @ MON_BASE+SPECIES_MILTANK #5 (16,24)
Route39_EventScript_Woman::                     @ WOMAN_3_HNS #11 (37,30)
Route39_EventScript_Sign3::                     @ sign (25,31)
Route39_EventScript_Sign1::                     @ sign (22,46)
Route39_EventScript_Sign2::                     @ sign (25,17)
	end
