LilycoveCity_ContestLobby_MapScripts::
	.byte 0

@ Contests and Berry Blenders are not ported: their receptionists, blender players, machines and boards stay silent.

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
	msgbox LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase, MSGBOX_NPC
	end

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
