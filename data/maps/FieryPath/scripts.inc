FieryPath_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (FieryPath_OnTransition)
FieryPath_EventScript_ItemTMToxic::             @ item ball, works (FLAG_ITEM_FIERY_PATH_TM_TOXIC)
	finditem ITEM_TM06_TOXIC
	end
FieryPath_EventScript_ItemFireStone::           @ item ball, works (FLAG_ITEM_FIERY_PATH_FIRE_STONE)
	finditem ITEM_FIRE_STONE
	end
