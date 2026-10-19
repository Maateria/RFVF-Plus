.equ LOCALID_SAFARI_EXIT_ATTENDANT, 1

HoennSafariZone_South_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (HoennSafariZone_South_OnTransition), ON_FRAME_TABLE (HoennSafariZone_South_OnFrame)
HoennSafariZone_South_EventScript_Boy::
	msgbox HoennSafariZone_South_Text_Boy, MSGBOX_NPC
	end

HoennSafariZone_South_EventScript_Man::
	msgbox HoennSafariZone_South_Text_Man, MSGBOX_NPC
	end

HoennSafariZone_South_EventScript_Youngster::
	msgbox HoennSafariZone_South_Text_Youngster, MSGBOX_NPC
	end

@ Emerald's exit attendant; leaving early uses the Hoenn Safari's own exit (data/scripts/safari_zone.inc)
HoennSafariZone_South_EventScript_ExitAttendant::
	lock
	faceplayer
	goto_if_unset FLAG_TEMP_3, HoennSafariZone_South_EventScript_GoodLuck
	msgbox HoennSafariZone_South_Text_StillHaveTimeExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, HoennSafariZone_South_EventScript_ExitEarly
	msgbox HoennSafariZone_South_Text_EnjoyTheRestOfYourAdventure
	release
	end

HoennSafariZone_South_EventScript_ExitEarly::
	msgbox HoennSafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	goto SafariZone_EventScript_HoennExit

@ FLAG_TEMP_3: Emerald's FLAG_GOOD_LUCK_SAFARI_ZONE, cleared each time the player comes in
HoennSafariZone_South_EventScript_GoodLuck::
	setflag FLAG_TEMP_3
	msgbox HoennSafariZone_South_Text_GoodLuck
	release
	end

