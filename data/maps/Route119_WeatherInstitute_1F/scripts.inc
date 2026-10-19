.equ LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 3

Route119_WeatherInstitute_1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route119_WeatherInstitute_1F_OnTransition)
Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

@ Basic text instead of the abnormal weather report (user's choice)
Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_NPC
	end

