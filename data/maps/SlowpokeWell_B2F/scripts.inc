@ johto_import: generated from PokemonHnS data/maps/SlowpokeWell_B2F_hns; scripted maps get their own file later
.equ LOCALID_WELL_SLOWKING, 1

SlowpokeWell_B2F_MapScripts::
	.byte 0

SlowpokeWell_B2F_EventScript_Item2::            @ item ball (FLAG_ITEM_SLOWPOKE_WELL_KINGS_ROCK)
	finditem ITEM_KINGS_ROCK
	end

@ silent until scripted (PokemonHnS data/maps/SlowpokeWell_B2F_hns/scripts.inc)
SlowpokeWell_B2F_EventScript_Slowking::         @ MON_BASE+SPECIES_SLOWKING #1 (13,9)
	end
