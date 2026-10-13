MeteorFalls_1F_1R_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (MeteorFalls_1F_1R_OnLoad)
MeteorFalls_1F_1R_EventScript_ItemTMIronTail::  @ item ball, works (FLAG_ITEM_METEOR_FALLS_1F_1R_TM_IRON_TAIL)
	finditem ITEM_TM23_IRON_TAIL
	end
MeteorFalls_1F_1R_EventScript_ItemMoonStone::   @ item ball, works (FLAG_ITEM_METEOR_FALLS_1F_1R_MOON_STONE)
	finditem ITEM_MOON_STONE
	end
MeteorFalls_1F_1R_EventScript_ItemFullHeal::    @ item ball, works (FLAG_ITEM_METEOR_FALLS_1F_1R_FULL_HEAL)
	finditem ITEM_FULL_HEAL
	end
MeteorFalls_1F_1R_EventScript_ItemPPUP::        @ item ball, works (FLAG_ITEM_METEOR_FALLS_1F_1R_PP_UP)
	finditem ITEM_PP_UP
	end
@ hoenn_import: left out: trigger (14,18) VAR_METEOR_FALLS_STATE==0 -> MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene
