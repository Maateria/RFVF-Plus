.equ LOCALID_FOSSIL_SCIENTIST, 5

RustboroCity_DevonCorp_2F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (RustboroCity_DevonCorp_2F_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/RustboroCity_DevonCorp_2F/scripts.inc
RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist:: @ NPC #1 (6,5)
RustboroCity_DevonCorp_2F_EventScript_BallScientist:: @ NPC #2 (1,5)
RustboroCity_DevonCorp_2F_EventScript_PokenavScientist:: @ NPC #3 (2,6)
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist:: @ NPC #4 (10,5)
RustboroCity_DevonCorp_2F_EventScript_FossilScientist:: @ NPC #5 (14,8)
RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist:: @ NPC #6 (14,5)
	end
