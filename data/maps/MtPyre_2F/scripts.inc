MtPyre_2F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (CaveHole_CheckFallDownHole), ON_TRANSITION (CaveHole_FixCrackedGround), ON_RESUME (MtPyre_2F_SetHoleWarp)
MtPyre_2F_EventScript_ItemUltraBall::           @ item ball, works (FLAG_ITEM_MT_PYRE_2F_ULTRA_BALL)
	finditem ITEM_ULTRA_BALL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MtPyre_2F/scripts.inc
MtPyre_2F_EventScript_Mark::                    @ trainer #1 (3,6) TRAINER_MARK, Emerald NORMAL sight 2
MtPyre_2F_EventScript_Woman::                   @ NPC #3 (9,3)
MtPyre_2F_EventScript_PokefanM::                @ NPC #4 (12,10)
MtPyre_2F_EventScript_Dez::                     @ trainer #5 (2,9) TRAINER_DEZ_AND_LUKE, Emerald NORMAL sight 1
MtPyre_2F_EventScript_Luke::                    @ trainer #6 (3,9) TRAINER_DEZ_AND_LUKE, Emerald NORMAL sight 1
MtPyre_2F_EventScript_Zander::                  @ trainer #7 (6,9) TRAINER_ZANDER, Emerald NORMAL sight 2
MtPyre_2F_EventScript_Leah::                    @ trainer #8 (6,6) TRAINER_LEAH, Emerald NORMAL sight 2
	end
