@ johto_import: generated from PokemonHnS data/maps/CianwoodGym_hns; scripted maps get their own file later
.equ LOCALID_CIANWOOD_CHUCK, 1
.equ LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, 9
.equ LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, 10

CianwoodGym_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/CianwoodGym_hns/scripts.inc)
CianwoodGym_EventScript_Chuck::                 @ CHUCK_HNS #1 (10,2)
CianwoodGym_EventScript_Nob::                   @ BLACK_BELT_HNS #2 (4,4), trainer TRAINER_NOB_HNS
CianwoodGym_EventScript_Yoshi::                 @ BLACK_BELT_HNS #3 (3,8), trainer TRAINER_YOSHI_HNS
CianwoodGym_EventScript_Lao::                   @ BLACK_BELT_HNS #4 (14,8), trainer TRAINER_LAO_HNS
CianwoodGym_EventScript_Lung::                  @ BLACK_BELT_HNS #5 (15,6), trainer TRAINER_LUNG_HNS
CianwoodGym_EventScript_Statue::                @ sign (13,14)
	end
