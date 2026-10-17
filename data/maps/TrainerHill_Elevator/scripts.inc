.equ LOCALID_TRAINER_HILL_ELEVATOR_ATTENDANT, 1

TrainerHill_Elevator_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (TrainerHill_Elevator_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/TrainerHill_Elevator/scripts.inc
TrainerHill_Elevator_EventScript_Attendant::    @ NPC #1 (0,6)
	end
