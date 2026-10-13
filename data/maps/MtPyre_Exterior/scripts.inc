MtPyre_Exterior_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MtPyre_Exterior_OnTransition)
MtPyre_Exterior_EventScript_ItemMaxPotion::     @ item ball, works (FLAG_ITEM_MT_PYRE_EXTERIOR_MAX_POTION)
	finditem ITEM_MAX_POTION
	end
MtPyre_Exterior_EventScript_ItemTMSkillSwap::   @ item ball, works (FLAG_ITEM_MT_PYRE_EXTERIOR_TM_SKILL_SWAP)
	finditem ITEM_TM48_SKILL_SWAP
	end
@ hoenn_import: left out: trigger (24,21) TRIGGER_RUN_IMMEDIATELY==0 -> MtPyre_Exterior_EventScript_FogTrigger; trigger (25,21) TRIGGER_RUN_IMMEDIATELY==0 -> MtPyre_Exterior_EventScript_FogTrigger; trigger (22,27) TRIGGER_RUN_IMMEDIATELY==0 -> MtPyre_Exterior_EventScript_SunTrigger; trigger (23,28) TRIGGER_RUN_IMMEDIATELY==0 -> MtPyre_Exterior_EventScript_SunTrigger; trigger (26,21) TRIGGER_RUN_IMMEDIATELY==0 -> MtPyre_Exterior_EventScript_FogTrigger
