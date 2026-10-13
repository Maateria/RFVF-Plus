JaggedPass_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (JaggedPass_OnResume), ON_TRANSITION (JaggedPass_OnTransition), ON_LOAD (JaggedPass_OnLoad)
JaggedPass_EventScript_ItemBurnHeal::           @ item ball, works (FLAG_ITEM_JAGGED_PASS_BURN_HEAL)
	finditem ITEM_BURN_HEAL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/JaggedPass/scripts.inc
JaggedPass_EventScript_Eric::                   @ trainer #1 (10,8) TRAINER_ERIC, Emerald NORMAL sight 3
JaggedPass_EventScript_Ethan::                  @ trainer #2 (16,35) TRAINER_ETHAN_1, Emerald NORMAL sight 4
JaggedPass_EventScript_Diana::                  @ trainer #4 (9,21) TRAINER_DIANA_1, Emerald NORMAL sight 3
JaggedPass_EventScript_Autumn::                 @ trainer #5 (14,25) TRAINER_AUTUMN, Emerald NORMAL sight 3
JaggedPass_EventScript_Julio::                  @ trainer #6 (18,25) TRAINER_JULIO, Emerald NORMAL sight 3
	end
@ hoenn_import: left out: trigger (21,15) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout; trigger (22,20) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout; trigger (21,20) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout; trigger (14,15) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout; trigger (13,15) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout
