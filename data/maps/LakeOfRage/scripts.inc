@ johto_import: generated from PokemonHnS data/maps/LakeOfRage_hns; scripted maps get their own file later
.equ LOCALID_LAKEOFRAGE_OLDMAN, 3

LakeOfRage_MapScripts::
	.byte 0

LakeOfRage_EventScript_Item7::                  @ item ball (FLAG_ITEM_LAKEOFRAGE_FULL_RESTORE)
	finditem ITEM_FULL_RESTORE
	end

LakeOfRage_EventScript_Item8::                  @ item ball (FLAG_ITEM_LAKE_OF_RAGE_TM_SECRET_POWER)
	finditem ITEM_TM43_SECRET_POWER
	end

LakeOfRage_EventScript_Item9::                  @ item ball (FLAG_ITEM_LAKEOFRAGE_RED_FLUTE)
	finditem ITEM_RED_FLUTE
	end

@ silent until scripted (PokemonHnS data/maps/LakeOfRage_hns/scripts.inc)
LakeOfRage_EventScript_Lass::                   @ LASS_HNS #1 (37,36)
LakeOfRage_EventScript_Andre::                  @ FISHERMAN_HNS #2 (25,38), trainer TRAINER_ANDRE_HNS
LakeOfRage_EventScript_Gramps::                 @ OLD_MAN_HNS #3 (32,35)
LakeOfRage_EventScript_Raymond::                @ FISHERMAN_HNS #4 (3,39), trainer TRAINER_RAYMOND_HNS
LakeOfRage_EventScript_Wesley::                 @ BLACK_BELT_HNS #5 (55,15)
LakeOfRage_EventScript_Aaron::                  @ COOLTRAINER_M_HNS #6 (42,2), trainer TRAINER_AARON_HNS
LakeOfRage_EventScript_Nerd::                   @ SUPER_NERD_HNS #10 (46,32)
LakeOfRage_EventScript_Sign1::                  @ sign (30,36)
LakeOfRage_EventScript_Sign2::                  @ sign (37,41)
	end
