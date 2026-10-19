PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (PacifidlogTown_OnTransition)
@ hoenn_import: Emerald's mechanics, without its story lines (hoenn_decisions.MECHANICAL_SCRIPTS)
PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end
PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end
