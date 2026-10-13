FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (FortreeCity_OnTransition)
@ hoenn_import: Emerald's mechanics, without its story lines (hoenn_decisions.MECHANICAL_SCRIPTS)
FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/FortreeCity/scripts.inc
FortreeCity_EventScript_Man::                   @ NPC #1 (31,3)
FortreeCity_EventScript_Girl::                  @ NPC #2 (32,16)
FortreeCity_EventScript_Woman::                 @ NPC #3 (32,10)
FortreeCity_EventScript_Boy::                   @ NPC #4 (11,14)
FortreeCity_EventScript_OldMan::                @ NPC #5 (8,10)
FortreeCity_EventScript_GameboyKid::            @ NPC #6 (9,16)
FortreeCity_EventScript_CitySign::              @ sign (6,9)
FortreeCity_EventScript_GymSign::               @ sign (26,10)
	end
