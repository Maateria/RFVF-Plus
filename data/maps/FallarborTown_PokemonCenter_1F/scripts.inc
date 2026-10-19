.equ LOCALID_FALLARBOR_NURSE, 1

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (CableClub_OnResume)
FallarborTown_PokemonCenter_1F_OnTransition::
	setrespawn SPAWN_FALLARBOR_TOWN
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end
