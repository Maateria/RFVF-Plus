@ Johto's field obstacles (tools/johto_import): PokemonHnS's whirlpools and headbutt trees.

@ A whirlpool (OBJ_EVENT_GFX_JOHTO_WHIRLPOOL): the player swims through it, 3 tiles, as in PokemonHnS (its script
@ checks the 7th badge only). ponytail: Kanto's 7th badge until Johto's gyms are scripted, then FLAG_JOHTO_BADGE07_GET.
EventScript_Whirlpool::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	goto_if_unset FLAG_BADGE07_GET, EventScript_CantWhirlpool
	playse SE_M_WATERFALL
	goto_if_eq VAR_FACING, DIR_NORTH, EventScript_WhirlpoolGoNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, EventScript_WhirlpoolGoSouth
	goto_if_eq VAR_FACING, DIR_EAST, EventScript_WhirlpoolGoEast
	goto_if_eq VAR_FACING, DIR_WEST, EventScript_WhirlpoolGoWest
	releaseall
	end

EventScript_WhirlpoolGoNorth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolNorth
	waitmovement 0
	releaseall
	end

EventScript_WhirlpoolGoSouth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolSouth
	waitmovement 0
	releaseall
	end

EventScript_WhirlpoolGoEast::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolEast
	waitmovement 0
	releaseall
	end

EventScript_WhirlpoolGoWest::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolWest
	waitmovement 0
	releaseall
	end

EventScript_CantWhirlpool::
	msgbox Text_CantWhirlpool
	closemessage
	releaseall
	end

Movement_WhirlpoolNorth:
	slide_up
	slide_up
	slide_up
	step_end

Movement_WhirlpoolSouth:
	slide_down
	slide_down
	slide_down
	step_end

Movement_WhirlpoolEast:
	slide_right
	slide_right
	slide_right
	step_end

Movement_WhirlpoolWest:
	slide_left
	slide_left
	slide_left
	step_end

@ Adapted (RFVF+): PokemonHnS's text in French
Text_CantWhirlpool::
	.string "L'eau tourbillonne et gronde\n"
	.string "avec fureur.$"

@ A headbutt tree (MB_HEADBUTT_TREE, field_control_avatar.c): a POKéMON that knows HEADBUTT shakes it. Its wild POKéMON
@ are the map's Rock Smash table, as in PokemonHnS.
EventScript_Headbutt::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	checkpartymove MOVE_HEADBUTT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_HeadbuttNoMon
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_HEADBUTT
	msgbox Text_UseHeadbutt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_HeadbuttEnd
	msgbox Text_MonUsedMove
	closemessage
	playse SE_M_HEADBUTT
	waitse
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_HeadbuttNothing
	waitstate
	releaseall
	end

EventScript_HeadbuttNothing::
	msgbox Text_HeadbuttNothing
	closemessage
	releaseall
	end

EventScript_HeadbuttNoMon::
	msgbox Text_HeadbuttTree
	closemessage
	releaseall
	end

EventScript_HeadbuttEnd::
	closemessage
	releaseall
	end

@ Adapted (RFVF+)
Text_HeadbuttTree::
	.string "Un POKéMON pourrait se cacher\n"
	.string "dans cet arbre.$"

Text_UseHeadbutt::
	.string "Un POKéMON pourrait se cacher\n"
	.string "dans cet arbre.\p"
	.string "Voulez-vous utiliser {STR_VAR_2}?$"

Text_HeadbuttNothing::
	.string "Rien ne se passe...$"
