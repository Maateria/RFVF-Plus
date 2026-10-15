JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (JaggedPass_OnTransition), ON_LOAD (JaggedPass_OnLoad)
@ hoenn_import: Emerald's mechanics, without its story lines (hoenn_decisions.MECHANICAL_SCRIPTS)
JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	end
JaggedPass_EventScript_ItemBurnHeal::           @ item ball, works (FLAG_ITEM_JAGGED_PASS_BURN_HEAL)
	finditem ITEM_BURN_HEAL
	end
@ hoenn_import: left out: trigger (21,15) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout; trigger (22,20) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout; trigger (21,20) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout; trigger (14,15) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout; trigger (13,15) VAR_JAGGED_PASS_STATE==1 -> JaggedPass_EventScript_OpenMagmaHideout

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end
