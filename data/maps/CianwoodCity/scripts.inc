@ johto_import: generated from PokemonHnS data/maps/CianwoodCity_hns; scripted maps get their own file later
.equ LOCALID_CIANWOOD_CHUCKSWIFE, 4

CianwoodCity_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/CianwoodCity_hns/scripts.inc)
CianwoodCity_EventScript_PokefanM::             @ FAT_MAN_HNS #1 (20,36)
CianwoodCity_EventScript_Youngster::            @ YOUNGSTER_HNS #2 (27,41)
CianwoodCity_EventScript_Lass::                 @ BATTLE_GIRL_HNS #3 (20,54)
CianwoodCity_EventScript_ChucksWife::           @ WOMAN_3_HNS #4 (18,47)
CianwoodCity_EventScript_CitySign::             @ sign (33,48)
CianwoodCity_EventScript_Pharmacy::             @ sign (21,51)
CianwoodCity_EventScript_GymSign::              @ sign (17,44)
CianwoodCity_EventScript_CaveSign::             @ sign (14,33)
	end
