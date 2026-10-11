.equ LOCALID_PETALBURG_GYM_NORMAN, 1

PetalburgCity_Gym_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (PetalburgCity_Gym_OnLoad), ON_TRANSITION (PetalburgCity_Gym_OnTransition), ON_WARP_INTO_MAP_TABLE (PetalburgCity_Gym_OnWarp), ON_FRAME_TABLE (PetalburgCity_Gym_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/PetalburgCity_Gym/scripts.inc
PetalburgCity_Gym_EventScript_Norman::          @ NPC #1 (4,2)
PetalburgCity_Gym_EventScript_Mary::            @ trainer #2 (4,94) TRAINER_MARY, Emerald NORMAL sight 0
PetalburgCity_Gym_EventScript_Randall::         @ trainer #3 (4,81) TRAINER_RANDALL, Emerald NORMAL sight 0
PetalburgCity_Gym_EventScript_Parker::          @ trainer #4 (4,42) TRAINER_PARKER, Emerald NORMAL sight 0
PetalburgCity_Gym_EventScript_Alexia::          @ trainer #5 (4,55) TRAINER_ALEXIA, Emerald NORMAL sight 0
PetalburgCity_Gym_EventScript_George::          @ trainer #6 (4,68) TRAINER_GEORGE, Emerald NORMAL sight 0
PetalburgCity_Gym_EventScript_Jody::            @ trainer #7 (4,16) TRAINER_JODY, Emerald NORMAL sight 0
PetalburgCity_Gym_EventScript_Berke::           @ trainer #8 (4,29) TRAINER_BERKE, Emerald NORMAL sight 0
PetalburgCity_Gym_EventScript_SpeedRoomDoor::   @ sign (1,105)
PetalburgCity_Gym_EventScript_AccuracyRoomDoor:: @ sign (7,105)
PetalburgCity_Gym_EventScript_ConfusionRoomDoor:: @ sign (1,79)
PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor:: @ sign (7,79)
PetalburgCity_Gym_EventScript_RightDefenseRoomDoor:: @ sign (1,92)
PetalburgCity_Gym_EventScript_RecoveryRoomDoor:: @ sign (7,92)
PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor:: @ sign (7,40)
PetalburgCity_Gym_EventScript_RightStrengthRoomDoor:: @ sign (1,53)
PetalburgCity_Gym_EventScript_LeftOHKORoomDoor:: @ sign (7,53)
PetalburgCity_Gym_EventScript_RightOHKORoomDoor:: @ sign (1,66)
PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor:: @ sign (7,14)
PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor:: @ sign (1,27)
PetalburgCity_Gym_EventScript_LeftGymStatue::   @ sign (1,110)
PetalburgCity_Gym_EventScript_RightGymStatue::  @ sign (7,110)
	end
