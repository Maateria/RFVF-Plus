@ johto_import: generated from PokemonHnS data/maps/EcruteakCity_hns; scripted maps get their own file later
.equ LOCALID_ECRUTEAK_GRAMPS, 3

EcruteakCity_MapScripts::
	.byte 0

EcruteakCity_EventScript_Item7::                @ item ball (FLAG_ITEM_ECRUTEAK_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end

@ silent until scripted (PokemonHnS data/maps/EcruteakCity_hns/scripts.inc)
EcruteakCity_EventScript_Lass::                 @ LASS_HNS #1 (35,43)
EcruteakCity_EventScript_SageRight::            @ SAGE_HNS #2 (51,34)
EcruteakCity_EventScript_Gramps::               @ OLD_MAN_HNS #3 (36,32)
EcruteakCity_EventScript_SageTower::            @ SAGE_HNS #4 (27,18)
EcruteakCity_EventScript_EcruteakCity_EventScrip_Man:: @ FAT_MAN_HNS #5 (22,42)
EcruteakCity_EventScript_Girl::                 @ WOMAN_1_HNS #6 (19,22)
EcruteakCity_EventScript_Eevee::                @ MON_BASE+SPECIES_EEVEE #8 (36,43)
EcruteakCity_EventScript_Youngster::            @ BOY_2_HNS #9 (52,49)
EcruteakCity_EventScript_GymSign::              @ sign (22,48)
EcruteakCity_EventScript_TheaterSign::          @ sign (36,40)
EcruteakCity_EventScript_OfficeSign::           @ sign (41,25)
EcruteakCity_EventScript_BurnedSign::           @ sign (24,15)
EcruteakCity_EventScript_CitySign::             @ sign (27,40)
	end
