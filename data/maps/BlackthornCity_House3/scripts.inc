@ johto_import: generated from PokemonHnS data/maps/BlackthornCity_House3_hns; scripted maps get their own file later
.equ LOCALID_MOVE_DELETER, 1
.equ LOCALID_BLACKTHORN_MOVE_RELEARNER, 2

BlackthornCity_House3_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/BlackthornCity_House3_hns/scripts.inc)
BlackthornCity_House3_EventScript_MoveDeleter:: @ OLD_MAN_HNS #1 (4,4)
BlackthornCity_House3_EventScript_MoveRelearner:: @ FAT_MAN_HNS #2 (7,4)
	end
