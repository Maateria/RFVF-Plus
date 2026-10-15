MtPyre_5F_MapScripts::
	.byte 0
MtPyre_5F_EventScript_ItemLaxIncense::          @ item ball, works (FLAG_ITEM_MT_PYRE_5F_LAX_INCENSE)
	finditem ITEM_LAX_INCENSE
	end

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end
