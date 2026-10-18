@ johto_import: generated from PokemonHnS data/maps/CianwoodPokecenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

CianwoodPokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition:
	setrespawn SPAWN_CIANWOOD_CITY
	end

CianwoodPokecenter_EventScript_Nurse::          @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/CianwoodPokecenter_hns/scripts.inc)
CianwoodPokecenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
CianwoodPokecenter_EventScript_Nerd::           @ SUPER_NERD_HNS #3 (12,5)
CianwoodPokecenter_EventScript_GymGuide::       @ GYM_GUY_HNS #4 (9,4)
CianwoodPokecenter_EventScript_Lass::           @ LASS_HNS #5 (3,6)
CianwoodPokecenter_EventScript_Fisher::         @ FISHERMAN_HNS #6 (14,6)
CianwoodPokecenter_EventScript_WallClock::      @ sign (3,1)
CianwoodPokecenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
