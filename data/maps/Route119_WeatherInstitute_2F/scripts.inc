.equ LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 1

Route119_WeatherInstitute_2F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route119_WeatherInstitute_2F_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route119_WeatherInstitute_2F/scripts.inc
Route119_WeatherInstitute_2F_EventScript_WeatherScientist:: @ NPC #1 (2,2)
	end
