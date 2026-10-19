.equ LOCALID_MAUVILLE_NURSE, 1

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (CableClub_OnResume)
MauvilleCity_PokemonCenter_1F_OnTransition::
	setrespawn SPAWN_MAUVILLE_CITY
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MauvilleCity_PokemonCenter_1F/scripts.inc
MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan:: @ NPC #2 (2,3)
	end
