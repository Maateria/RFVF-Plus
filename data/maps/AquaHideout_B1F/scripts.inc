AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (AquaHideout_B1F_OnTransition)
AquaHideout_B1F_EventScript_ItemMaxElixir::     @ item ball, works (FLAG_ITEM_AQUA_HIDEOUT_B1F_MAX_ELIXIR)
	finditem ITEM_MAX_ELIXIR
	end
AquaHideout_B1F_EventScript_ItemMasterBall::    @ item ball, works (FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL)
	finditem ITEM_MASTER_BALL
	end
AquaHideout_B1F_EventScript_ItemNugget::        @ item ball, works (FLAG_ITEM_AQUA_HIDEOUT_B1F_NUGGET)
	finditem ITEM_NUGGET
	end
@ Emerald's: the two Electrode "items" are gone after their battle, whatever its outcome
AquaHideout_B1F_OnResume:
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, AquaHideout_B1F_EventScript_TryRemoveElectrode
	end

AquaHideout_B1F_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_EventScript_Electrode1::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, AquaHideout_B1F_EventScript_CaughtElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_CaughtElectrode1::
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_Electrode2::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, AquaHideout_B1F_EventScript_CaughtElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_CaughtElectrode2::
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

