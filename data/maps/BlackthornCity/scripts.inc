@ johto_import: generated from PokemonHnS data/maps/BlackthornCity_hns; scripted maps get their own file later
.equ LOCALID_BLACKTHORN_BOY, 2
.equ LOCALID_BLACKTHORN_SAGE, 7

BlackthornCity_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/BlackthornCity_hns/scripts.inc)
BlackthornCity_EventScript_Youngster::          @ YOUNGSTER_HNS #1 (16,28)
BlackthornCity_EventScript_GymBoy::             @ BOY_2_HNS #2 (25,27)
BlackthornCity_EventScript_Santos::             @ FAT_MAN_HNS #3 (27,39)
BlackthornCity_EventScript_CoolTrainerF2::      @ COOLTRAINER_F_HNS #4 (44,31)
BlackthornCity_EventScript_CoolTrainerF::       @ BATTLE_GIRL_HNS #5 (12,40)
BlackthornCity_EventScript_BlackBelt::          @ BLACK_BELT_HNS #6 (33,44)
BlackthornCity_EventScript_Sage::               @ SAGE_HNS #7 (25,13)
BlackthornCity_EventScript_DragonsDenSign::     @ sign (28,13)
BlackthornCity_EventScript_GymSign::            @ sign (26,26)
BlackthornCity_EventScript_MoveHouseSign::      @ sign (13,49)
BlackthornCity_EventScript_CitySign::           @ sign (42,42)
	end
