MtPyre_4F_MapScripts::
	.byte 0
MtPyre_4F_EventScript_ItemSeaIncense::          @ item ball, works (FLAG_ITEM_MT_PYRE_4F_SEA_INCENSE)
	finditem ITEM_SEA_INCENSE
	end

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end
