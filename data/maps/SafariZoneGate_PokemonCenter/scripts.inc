@ johto_import: generated from PokemonHnS data/maps/SafariZoneGate_PokemonCenter_hns; scripted maps get their own file later
.equ LOCALID_NURSE, 1

SafariZoneGate_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition:
	setrespawn SPAWN_SAFARI_ZONE_GATE
	end

SafariZoneGate_PokemonCenter_EventScript_Nurse:: @ Pokemon Center nurse
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ silent until scripted (PokemonHnS data/maps/SafariZoneGate_PokemonCenter_hns/scripts.inc)
SafariZoneGate_PokemonCenter_EventScript_CherryGrove_Pokecenter_Chansey:: @ NURSE_CHANSEY_HNS #2 (8,2)
SafariZoneGate_PokemonCenter_EventScript_NPC1:: @ WOMAN_3_HNS #3 (14,6)
SafariZoneGate_PokemonCenter_EventScript_NPC2:: @ HIKER_HNS #4 (12,5)
SafariZoneGate_PokemonCenter_EventScript_SafariZoneGate_PokemonCenter_Text_Boy:: @ LITTLE_BOY_HNS #5 (3,6)
SafariZoneGate_PokemonCenter_EventScript_WallClock:: @ sign (3,1)
SafariZoneGate_PokemonCenter_EventScript_EventScript_BookShelf:: @ sign (2,1)
	end
