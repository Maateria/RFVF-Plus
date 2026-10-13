PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (PacifidlogTown_OnTransition)
@ hoenn_import: Emerald's mechanics, without its story lines (hoenn_decisions.MECHANICAL_SCRIPTS)
PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/PacifidlogTown/scripts.inc
PacifidlogTown_EventScript_Girl::               @ NPC #1 (10,23)
PacifidlogTown_EventScript_Fisherman::          @ NPC #2 (11,14)
PacifidlogTown_EventScript_NinjaBoy::           @ NPC #3 (9,16)
PacifidlogTown_EventScript_TownSign::           @ sign (7,16)
	end
