.equ LOCALID_SOOTOPOLIS_EXPERT, 1
.equ LOCALID_KIRI, 2
.equ LOCALID_SOOTOPOLIS_NINJA_BOY, 3
.equ LOCALID_SOOTOPOLIS_BOY_1, 4
.equ LOCALID_SOOTOPOLIS_WOMAN_1, 6

SootopolisCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (SootopolisCity_OnLoad), ON_TRANSITION (SootopolisCity_OnTransition), ON_RESUME (SootopolisCity_OnResume), ON_FRAME_TABLE (SootopolisCity_OnFrame), ON_WARP_INTO_MAP_TABLE (SootopolisCity_OnWarp)
SootopolisCity_EventScript_CaveOfOriginExpert::
	lock
	faceplayer
	goto SootopolisCity_EventScript_ExpertPostLegendaries

SootopolisCity_EventScript_ExpertPostLegendaries::
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoy::
	lockall
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
	waitmovement 0
	goto SootopolisCity_EventScript_NinjaBoyNormal

SootopolisCity_EventScript_NinjaBoyNormal::
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1::
	lockall
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_HOENN_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
	goto SootopolisCity_EventScript_Boy1Normal

SootopolisCity_EventScript_Boy1GameClear::
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1Normal::
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Man::
	lock
	faceplayer
	goto SootopolisCity_EventScript_ManPostLegendaries

SootopolisCity_EventScript_ManPostLegendaries::
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1::
	lock
	faceplayer
	goto SootopolisCity_EventScript_Woman1PostLegendaries

SootopolisCity_EventScript_Woman1PostLegendaries::
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GymSign::
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
	end

SootopolisCity_EventScript_CitySign::
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
	end

@ Kiri (JOY): her two berries again after every win against Hoenn's gym leaders, Elite Four and Champion, rematches
@ included (user's choice): VAR_KIRI_BERRY_GIFTS counts the wins she has not paid yet (src/hoenn_specials.c)
SootopolisCity_EventScript_Kiri::
	lock
	faceplayer
	goto_if_eq VAR_KIRI_BERRY_GIFTS, 0, SootopolisCity_EventScript_KiriReceivedBerry
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese
	random NUM_KIRI_BERRIES
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	subvar VAR_KIRI_BERRY_GIFTS, 1
	msgbox SootopolisCity_Text_GiveYouThisBerryToo
	random 2
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
	giveitem ITEM_IAPAPA_BERRY
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName
	release
	end

SootopolisCity_EventScript_GiveFigyBerry::
	giveitem ITEM_FIGY_BERRY
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName
	release
	end

SootopolisCity_EventScript_KiriReceivedBerry::
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
	msgbox SootopolisCity_Text_OhDoesntMatter
	release
	end

SootopolisCity_EventScript_KiriLikeSeasonBornIn::
	msgbox SootopolisCity_Text_ThenILoveAutumn
	release
	end

