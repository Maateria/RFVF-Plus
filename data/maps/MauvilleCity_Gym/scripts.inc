MauvilleCity_Gym_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (MauvilleCity_Gym_OnLoad)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MauvilleCity_Gym/scripts.inc
MauvilleCity_Gym_EventScript_Wattson::          @ NPC #1 (5,2)
MauvilleCity_Gym_EventScript_Shawn::            @ trainer #2 (7,8) TRAINER_SHAWN, Emerald NORMAL sight 1
MauvilleCity_Gym_EventScript_Vivian::           @ trainer #3 (1,16) TRAINER_VIVIAN, Emerald NORMAL sight 2
MauvilleCity_Gym_EventScript_Ben::              @ trainer #4 (5,10) TRAINER_BEN, Emerald NORMAL sight 2
MauvilleCity_Gym_EventScript_Kirk::             @ trainer #5 (1,13) TRAINER_KIRK, Emerald NORMAL sight 2
MauvilleCity_Gym_EventScript_GymGuide::         @ NPC #6 (7,20)
MauvilleCity_Gym_EventScript_Angelo::           @ trainer #7 (7,10) TRAINER_ANGELO, Emerald NORMAL sight 1
MauvilleCity_Gym_EventScript_LeftGymStatue::    @ sign (3,18)
MauvilleCity_Gym_EventScript_RightGymStatue::   @ sign (6,18)
	end
@ hoenn_import: left out: trigger (4,12) VAR_TEMP_0==0 -> MauvilleCity_Gym_EventScript_Switch2; trigger (3,9) VAR_TEMP_0==0 -> MauvilleCity_Gym_EventScript_Switch3; trigger (0,15) VAR_TEMP_0==0 -> MauvilleCity_Gym_EventScript_Switch1; trigger (8,9) VAR_TEMP_0==0 -> MauvilleCity_Gym_EventScript_Switch4
