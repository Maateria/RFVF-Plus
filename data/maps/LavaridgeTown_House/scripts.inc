LavaridgeTown_House_MapScripts::
	.byte 0
LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

@ Emerald's Mimic tutor, with Kanto's flag and reteach rule (EventScript_MimicTutor, without its Poke Doll)
LavaridgeTown_House_EventScript_MimicTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_MIMIC, EventScript_MimicReteach
	msgbox MoveTutor_MimicTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_House_EventScript_MimicDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_House_EventScript_MimicDeclined
	msgbox MoveTutor_Text_MimicWhichMon
	setvar VAR_0x8005, MOVETUTOR_MIMIC
	call EventScript_ChooseMoveTutorMon
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, LavaridgeTown_House_EventScript_MimicDeclined
	setflag FLAG_TUTOR_MIMIC
	msgbox MoveTutor_Text_MimicTaught
	release
	end

LavaridgeTown_House_EventScript_MimicDeclined::
	msgbox MoveTutor_MimicDeclined
	release
	end

