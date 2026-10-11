.equ LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 3

Route119_WeatherInstitute_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route119_WeatherInstitute_1F_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route119_WeatherInstitute_1F/scripts.inc
Route119_WeatherInstitute_1F_EventScript_InstituteWorker2:: @ NPC #1 (5,4)
Route119_WeatherInstitute_1F_EventScript_InstituteWorker1:: @ NPC #2 (2,11)
Route119_WeatherInstitute_1F_EventScript_LittleBoy:: @ NPC #3 (14,11)
Route119_WeatherInstitute_1F_EventScript_Bed::  @ sign (1,2)
	end
