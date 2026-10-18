@ johto_import: generated from PokemonHnS data/maps/RuinsOfAlph_Lab_hns; scripted maps get their own file later
.equ LOCALID_RUINS_FOSSIL_SCIENTIST, 3

RuinsOfAlph_Lab_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/RuinsOfAlph_Lab_hns/scripts.inc)
RuinsOfAlph_Lab_EventScript_Scientist2::        @ SCIENTIST_F_HNS #1 (8,5)
RuinsOfAlph_Lab_EventScript_Scientist1::        @ SCIENTIST_M_HNS #2 (1,3)
RuinsOfAlph_Lab_EventScript_FossilScientist::   @ SCIENTIST_M_HNS #3 (7,2)
RuinsOfAlph_Lab_EventScript_HealingMachine1::   @ sign (8,2)
RuinsOfAlph_Lab_EventScript_Fossils::           @ sign (5,4)
RuinsOfAlph_Lab_EventScript_EventScript_FakePC:: @ sign (3,4)
	end
