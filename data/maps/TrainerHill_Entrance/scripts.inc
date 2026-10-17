.equ LOCALID_TRAINER_HILL_ATTENDANT, 1
.equ LOCALID_TRAINER_HILL_NURSE, 2
.equ LOCALID_TRAINER_HILL_GIRL, 4
.equ LOCALID_TRAINER_HILL_MAN, 5

TrainerHill_Entrance_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (TrainerHill_Entrance_OnResume), ON_RETURN_TO_FIELD (TrainerHill_Entrance_OnReturn), ON_TRANSITION (TrainerHill_Entrance_OnTransition), ON_LOAD (TrainerHill_Entrance_OnLoad), ON_FRAME_TABLE (TrainerHill_Entrance_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/TrainerHill_Entrance/scripts.inc
TrainerHill_Entrance_EventScript_Attendant::    @ NPC #1 (11,6)
TrainerHill_Entrance_EventScript_Nurse::        @ NPC #2 (4,9)
TrainerHill_Entrance_EventScript_Clerk::        @ NPC #3 (14,9)
TrainerHill_Entrance_EventScript_Girl::         @ NPC #4 (5,14)
TrainerHill_Entrance_EventScript_Man::          @ NPC #5 (14,15)
TrainerHill_Entrance_EventScript_Records::      @ sign (8,10)
	end
@ hoenn_import: left out: trigger (9,6) VAR_TRAINER_HILL_IS_ACTIVE==0 -> TrainerHill_Entrance_EventScript_EntryTrigger
