@ johto_import: generated from PokemonHnS data/maps/Route30_hns; scripted maps get their own file later
Route30_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/Route30_hns/scripts.inc)
Route30_EventScript_Boy::                       @ LITTLE_BOY_HNS #1 (26,31)
Route30_EventScript_Girl::                      @ WOMAN_1_HNS #2 (20,13)
Route30_EventScript_Bugcatcher_Don::            @ BUG_CATCHER_HNS #3 (20,8), trainer TRAINER_DON_HNS
Route30_EventScript_Youngster_Mikey::           @ YOUNGSTER_HNS #5 (23,22), trainer TRAINER_MIKEY_HNS
Route30_EventScript_Sign::                      @ sign (31,29)
Route30_EventScript_TrainerTips::               @ sign (20,19)
Route30_EventScript_Mailbox::                   @ sign (32,4)
	end
