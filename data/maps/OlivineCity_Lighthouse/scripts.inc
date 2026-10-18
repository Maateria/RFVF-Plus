@ johto_import: generated from PokemonHnS data/maps/OlivineCity_Lighthouse_hns; scripted maps get their own file later
.equ LOCALID_LIGHTHOUSE_AMPHAROS, 12

OlivineCity_Lighthouse_MapScripts::
	.byte 0

OlivineCity_Lighthouse_EventScript_Item13::     @ item ball (FLAG_ITEM_LIGHTHOUSE_PROTEIN)
	finditem ITEM_PROTEIN
	end

OlivineCity_Lighthouse_EventScript_Item14::     @ item ball (FLAG_ITEM_LIGHTHOUSE_HYPER_POTION)
	finditem ITEM_HYPER_POTION
	end

OlivineCity_Lighthouse_EventScript_Item15::     @ item ball (FLAG_ITEM_OLIVINE_TM_SWAGGER)
	finditem ITEM_TM45_ATTRACT
	end

OlivineCity_Lighthouse_EventScript_Item16::     @ item ball (FLAG_ITEM_LIGHTHOUSE_RARE_CANDY)
	finditem ITEM_RARE_CANDY
	end

OlivineCity_Lighthouse_EventScript_Item17::     @ item ball (FLAG_ITEM_LIGHTHOUSE_ETHER)
	finditem ITEM_ETHER
	end

@ silent until scripted (PokemonHnS data/maps/OlivineCity_Lighthouse_hns/scripts.inc)
OlivineCity_Lighthouse_EventScript_1FPokefanF:: @ WOMAN_3_HNS #1 (19,9)
OlivineCity_Lighthouse_EventScript_1FSailor::   @ SAILOR_HNS #2 (5,3)
OlivineCity_Lighthouse_EventScript_Huey::       @ SAILOR_HNS #3 (47,3), trainer TRAINER_HUEY_HNS
OlivineCity_Lighthouse_EventScript_GentlemanAlfred:: @ GENTLEMAN_HNS #4 (43,13), trainer TRAINER_ALFRED_HNS
OlivineCity_Lighthouse_EventScript_SailorTerrell:: @ SAILOR_HNS #5 (67,3), trainer TRAINER_TERRELL_HNS
OlivineCity_Lighthouse_EventScript_BirdKeeperTheo:: @ ROCKER_HNS #6 (61,9), trainer TRAINER_THEO_HNS
OlivineCity_Lighthouse_EventScript_GentlemanPreston:: @ GENTLEMAN_HNS #7 (78,7), trainer TRAINER_PRESTON_HNS
OlivineCity_Lighthouse_EventScript_SailorKent:: @ SAILOR_HNS #8 (101,4), trainer TRAINER_KENT_HNS
OlivineCity_Lighthouse_EventScript_LassConnie:: @ COOLTRAINER_F_HNS #9 (101,14), trainer TRAINER_CONNIE_HNS
OlivineCity_Lighthouse_EventScript_BirdKeeperDenis:: @ ROCKER_HNS #10 (127,3), trainer TRAINER_DENIS_HNS
OlivineCity_Lighthouse_EventScript_SailorErnest:: @ SAILOR_HNS #11 (126,12), trainer TRAINER_ERNEST_HNS
OlivineCity_Lighthouse_EventScript_Ampharos::   @ MON_BASE+SPECIES_AMPHAROS #12 (156,8)
	end
