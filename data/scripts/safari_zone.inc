@ RFVF+: scene var 4 = playing in Hoenn's Safari Zone (Route121_SafariZoneEntrance), whose exits these branch to
SafariZone_EventScript_OutOfBallsMidBattle::
	goto_if_eq VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, SafariZone_EventScript_HoennOutOfBallsMidBattle
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
	special ExitSafariMode
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
	end

SafariZone_EventScript_HoennOutOfBallsMidBattle::
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	goto_if_eq VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, SafariZone_EventScript_HoennExit
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
	special ExitSafariMode
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
	waitstate
	end

SafariZone_EventScript_HoennExit::
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox SafariZone_Text_TimesUp
	goto SafariZone_EventScript_Exit
	end

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	msgbox SafariZone_Text_OutOfBalls
	goto SafariZone_EventScript_Exit
	end
