@ johto_import: generated from PokemonHnS data/maps/NewBarkTown_Lab_hns; scripted maps get their own file later
.equ LOCALID_ELM, 1
.equ LOCALID_AIDE2, 2

NewBarkTown_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	.byte 0

NewBarkTown_Lab_OnTransition:
	setrespawn SPAWN_NEW_BARK_TOWN
	end

@ silent until scripted (PokemonHnS data/maps/NewBarkTown_Lab_hns/scripts.inc)
NewBarkTown_Lab_EventScript_Elm::               @ ELM_HNS #1 (6,3)
NewBarkTown_Lab_EventScript_Aide2::             @ SCIENTIST_F_HNS #2 (9,9)
NewBarkTown_Lab_EventScript_PC::                @ sign (3,1)
NewBarkTown_Lab_EventScript_HealingMachine1::   @ sign (2,2)
NewBarkTown_Lab_EventScript_Machine::           @ sign (1,4)
NewBarkTown_Lab_EventScript_Bookshelf::         @ sign (8,1)
NewBarkTown_Lab_EventScript_EventScript_EmptyTrashCan:: @ sign (11,4)
	end
