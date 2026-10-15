PetalburgWoods_MapScripts::
	.byte 0
PetalburgWoods_EventScript_ItemGreatBall::      @ item ball, works (FLAG_ITEM_PETALBURG_WOODS_GREAT_BALL)
	finditem ITEM_GREAT_BALL
	end
PetalburgWoods_EventScript_ItemXAttack::        @ item ball, works (FLAG_ITEM_PETALBURG_WOODS_X_ATTACK)
	finditem ITEM_X_ATTACK
	end
PetalburgWoods_EventScript_ItemEther::          @ item ball, works (FLAG_ITEM_PETALBURG_WOODS_ETHER)
	finditem ITEM_ETHER
	end
PetalburgWoods_EventScript_ItemParalyzeHeal::   @ item ball, works (FLAG_ITEM_PETALBURG_WOODS_PARALYZE_HEAL)
	finditem ITEM_PARALYZE_HEAL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/PetalburgWoods/scripts.inc
PetalburgWoods_EventScript_Boy1::               @ NPC #6 (15,19)
PetalburgWoods_EventScript_Boy2::               @ NPC #9 (30,34)
PetalburgWoods_EventScript_Girl::               @ NPC #11 (33,5)
PetalburgWoods_EventScript_Sign1::              @ sign (14,32)
PetalburgWoods_EventScript_Sign2::              @ sign (11,8)
	end
@ hoenn_import: left out: trigger (26,23) VAR_PETALBURG_WOODS_STATE==0 -> PetalburgWoods_EventScript_DevonResearcherLeft; trigger (27,23) VAR_PETALBURG_WOODS_STATE==0 -> PetalburgWoods_EventScript_DevonResearcherRight

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end
