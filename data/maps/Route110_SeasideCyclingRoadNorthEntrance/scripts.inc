Route110_SeasideCyclingRoadNorthEntrance_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route110_SeasideCyclingRoadNorthEntrance_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.inc
Route110_SeasideCyclingRoadNorthEntrance_EventScript_Clerk:: @ NPC #1 (7,2)
	end
@ hoenn_import: left out: trigger (7,4) VAR_TEMP_1==0 -> Route110_SeasideCyclingRoadNorthEntrance_EventScript_BikeCheck; trigger (5,4) VAR_TEMP_1==1 -> Route110_SeasideCyclingRoadNorthEntrance_EventScript_ClearCyclingRoad
