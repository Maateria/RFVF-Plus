EventScript_FujiOutside::
# 2 "data/scripts/fuji_event.pory"
	lock
# 3 "data/scripts/fuji_event.pory"
	faceplayer
# 4 "data/scripts/fuji_event.pory"
	msgbox EventScript_FujiOutside_Text_0, MSGBOX_YESNO
EventScript_FujiOutside_2:
# 5 "data/scripts/fuji_event.pory"
	compare VAR_RESULT, NO
	goto_if_eq EventScript_FujiOutside_3
# 9 "data/scripts/fuji_event.pory"
	msgbox EventScript_FujiOutside_Text_2, MSGBOX_DEFAULT
# 10 "data/scripts/fuji_event.pory"
	checkitemspace ITEM_OLD_SEA_MAP, 1
# 11 "data/scripts/fuji_event.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_FujiOutside_6
# 17 "data/scripts/fuji_event.pory"
	giveitem_msg EventScript_FujiOutside_Text_3, ITEM_OLD_SEA_MAP, 1, MUS_OBTAIN_KEY_ITEM
# 18 "data/scripts/fuji_event.pory"
	setflag FLAG_RECEIVED_OLD_SEA_MAP
# 19 "data/scripts/fuji_event.pory"
	msgbox EventScript_FujiOutside_Text_4, MSGBOX_NPC
# 20 "data/scripts/fuji_event.pory"
	getplayerxy VAR_RESULT, VAR_0x8003
# 21 "data/scripts/fuji_event.pory"
	compare VAR_RESULT, 9
	goto_if_ne EventScript_FujiOutside_9
# 28 "data/scripts/fuji_event.pory"
	applymovement 4, Movement_FujiToHouseAroundPlayer
# 29 "data/scripts/fuji_event.pory"
	waitmovement 0
EventScript_FujiOutside_8:
# 31 "data/scripts/fuji_event.pory"
	opendoor 10, 11
# 32 "data/scripts/fuji_event.pory"
	waitdooranim
# 33 "data/scripts/fuji_event.pory"
	applymovement 4, PalletTown_Movement_OakEnterLab
# 34 "data/scripts/fuji_event.pory"
	waitmovement 0
# 35 "data/scripts/fuji_event.pory"
	closedoor 10, 11
# 36 "data/scripts/fuji_event.pory"
	waitdooranim
# 37 "data/scripts/fuji_event.pory"
	setflag FLAG_HIDE_LAVENDER_OUTSIDE_FUJI
# 38 "data/scripts/fuji_event.pory"
	clearflag FLAG_HIDE_POKEHOUSE_FUJI
# 39 "data/scripts/fuji_event.pory"
	release
	end

EventScript_FujiOutside_3:
# 7 "data/scripts/fuji_event.pory"
	msgbox EventScript_FujiOutside_Text_1, MSGBOX_YESNO
	goto EventScript_FujiOutside_2

EventScript_FujiOutside_6:
# 13 "data/scripts/fuji_event.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis, MSGBOX_DEFAULT
# 14 "data/scripts/fuji_event.pory"
	release
	end

EventScript_FujiOutside_9:
# 23 "data/scripts/fuji_event.pory"
	applymovement 4, Movement_FujiToHouse
# 24 "data/scripts/fuji_event.pory"
	waitmovement 0
	goto EventScript_FujiOutside_8


# 43 "data/scripts/fuji_event.pory"
Movement_FujiToHouse:
# 44 "data/scripts/fuji_event.pory"
	walk_right
# 44 "data/scripts/fuji_event.pory"
	walk_right
# 45 "data/scripts/fuji_event.pory"
	face_up
	step_end

# 48 "data/scripts/fuji_event.pory"
Movement_FujiToHouseAroundPlayer:
# 49 "data/scripts/fuji_event.pory"
	walk_down
# 50 "data/scripts/fuji_event.pory"
	walk_right
# 50 "data/scripts/fuji_event.pory"
	walk_right
# 51 "data/scripts/fuji_event.pory"
	walk_up
	step_end

EventScript_FujiOutside_Text_0:
# 4 "data/scripts/fuji_event.pory"
	.string "MR. FUJI: {PLAYER}!\nHow is your quest going?\pAh, you and your POKéMON are\nthe POKéMON LEAGUE CHAMPIONS!\pCongratulations!\nYour deep love for your POKéMON\lis obvious to anyone.\pI have a favor to ask.\pThere is an island far from KANTO\nwhere a certain POKéMON lives.\pThat POKéMON was mistreated by\nhumans in the past.\pI was hoping you would befriend\nthat POKéMON and show it that\lhumans can be kind and gentle.\pWill you do this for me?$"

EventScript_FujiOutside_Text_1:
# 7 "data/scripts/fuji_event.pory"
	.string "Helping this POKéMON is very\nimportant to me, {PLAYER}.\pPlease tell me you'll help.$"

EventScript_FujiOutside_Text_2:
# 9 "data/scripts/fuji_event.pory"
	.string "MR. FUJI: Thank you, {PLAYER}.\pI have an old map to the island.\nI'm sure you've befriended a sailor\lor two during your quest.\pThey will be able to read this\nmap and take you there.$"

EventScript_FujiOutside_Text_3:
# 17 "data/scripts/fuji_event.pory"
	.string "{PLAYER} received an VIEILLE CARTE\nfrom MR. FUJI.$"

EventScript_FujiOutside_Text_4:
# 19 "data/scripts/fuji_event.pory"
	.string "MR. FUJI: I know you will treat that\nPOKéMON with love and kindness.\pThank you, {PLAYER}.$"
