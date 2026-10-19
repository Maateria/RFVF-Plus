MossdeepCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MossdeepCity_OnTransition)
MossdeepCity_EventScript_ItemNetBall::          @ item ball, works (FLAG_ITEM_MOSSDEEP_CITY_NET_BALL)
	finditem ITEM_NET_BALL
	end
MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto MossdeepCity_EventScript_SailorMagmaGone

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto MossdeepCity_EventScript_PokefanFMagmaGone

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor::
	goto SaffronCity_EventScript_DynamicPunchTutor

@ hoenn_import: left out: trigger (25,25) VAR_TEMP_1==0 -> MossdeepCity_EventScript_VisitedMossdeep; trigger (26,25) VAR_TEMP_1==0 -> MossdeepCity_EventScript_VisitedMossdeep; trigger (32,27) VAR_TEMP_1==0 -> MossdeepCity_EventScript_VisitedMossdeep; trigger (33,27) VAR_TEMP_1==0 -> MossdeepCity_EventScript_VisitedMossdeep; trigger (42,21) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (41,22) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (41,23) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (41,24) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (40,25) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (40,26) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter
