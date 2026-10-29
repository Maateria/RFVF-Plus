LilycoveCity_ContestLobby_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_ContestLobby_OnTransition
	.byte 0

@ Contests come in later contest sessions: the link receptionist and the contest boards stay silent.
@ Berry Blenders (session 3): data/scripts/berry_blender.inc

LilycoveCity_ContestLobby_OnTransition:
	call LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster
	end

@ RFVF+: Emerald's Blend Master PokeNews (TV) = FLAG_BLEND_MASTER_TODAY, drawn each 1,000-step day after Hoenn's
@ Hall of Fame (HoennDays_OnStep, src/hoenn_specials.c)
LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster::
	goto_if_set FLAG_BLEND_MASTER_TODAY, LilycoveCity_ContestLobby_EventScript_ShowBlendMaster
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
	return

LilycoveCity_ContestLobby_EventScript_ShowBlendMaster::
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
	return

LilycoveCity_ContestLobby_EventScript_BlackBelt::
	msgbox LilycoveCity_ContestLobby_Text_MasterRankHereICome, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Girl::
	msgbox LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Artist::
	msgbox LilycoveCity_ContestLobby_Text_ContestFeastForEyes, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_FatMan::
	msgbox LilycoveCity_ContestLobby_Text_ToughContestIsExtreme, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Fisherman::
	msgbox LilycoveCity_ContestLobby_Text_LavishedCareOnMon, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_NinjaBoy::
	msgbox LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase
	msgbox LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase::
	msgbox LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries, MSGBOX_DEFAULT
	release
	end

@ Emerald's contest receptionist (data/scripts/contest_hall.inc): only the Pokeblock case part until contests (session 4)
LilycoveCity_ContestLobby_EventScript_ContestReceptionist::
	lock
	faceplayer
	call_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_ReceptionWelcome
	call_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_GivePokeblockCase
	release
	end

LilycoveCity_ContestLobby_EventScript_ReceptionWelcome::
	msgbox LilycoveCity_ContestLobby_Text_ContestReception, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_GivePokeblockCase::
	msgbox LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	msgbox LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp, MSGBOX_DEFAULT
	return

@ Blender old man: Emerald's Pecha Berry (daily there, only for a player without berries), given once to every player
@ (no clock, no Pokeblock checks); a player who holds berries gets it without the "no berries?" line
BerryBlender_EventScript_Blender1ExpertM::
	lock
	faceplayer
	msgbox BerryBlender_Text_LoveMakingPokeblocks
	goto_if_set FLAG_RECEIVED_LILYCOVE_PECHA_BERRY, BerryBlender_EventScript_ExpertMReceivedBerry
	special HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, TRUE, BerryBlender_EventScript_ExpertMGiveBerry
	msgbox BerryBlender_Text_DontHaveAnyBerriesHaveOne
BerryBlender_EventScript_ExpertMGiveBerry::
	giveitem ITEM_PECHA_BERRY
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	setflag FLAG_RECEIVED_LILYCOVE_PECHA_BERRY
	msgbox BerryBlender_Text_UseItToMakePokeblocksTogether
	release
	end

BerryBlender_EventScript_ExpertMReceivedBerry::
	special HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, TRUE, BerryBlender_EventScript_ExpertMPlayerHasBerries
	msgbox BerryBlender_Text_DontHaveAnyBerriesNoneToSpare
	release
	end

BerryBlender_EventScript_ExpertMPlayerHasBerries::
	msgbox BerryBlender_Text_MakePokeblocksUsingBerryBlender
	release
	end

LilycoveCity_ContestLobby_EventScript_Blender3Boy::
	msgbox BerryBlender_Text_LetsGetBlendingAlready, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Blender3Girl::
	msgbox BerryBlender_Text_WhatKindOfPokeblockWillIGet, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_BerryBlenderSpeedRecords::
	lockall
	special ShowBerryBlenderRecordWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_BlendMaster::
	lock
	faceplayer
	msgbox BerryBlender_Text_BlendWithTheBlendMaster, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker1::
	lock
	msgbox BerryBlender_Text_WhoaAwesome, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker2::
	lock
	msgbox BerryBlender_Text_WickedlyFast, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker3::
	lock
	msgbox BerryBlender_Text_WhatAnExpert, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker4::
	lock
	faceplayer
	msgbox BerryBlender_Text_MadeAmazingPokeblocksWithMaster, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker5::
	lock
	faceplayer
	msgbox BerryBlender_Text_QualitiesOfBlendMaster, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker6::
	lock
	faceplayer
	msgbox BerryBlender_Text_MasterWorksOnSkillsInMountains, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
