@ RFVF+: Hoenn's berry trees (work/hoenn_scripts/berry_trees.py places them), always fully grown with Emerald's new game
@ berry; a picked tree hides (its flag) until the next day (1,000 steps, src/hoenn_specials.c). No planting nor watering.
@ Emerald's BerryTree_EventScript_CheckBerryFullyGrown and _PickBerry (data/scripts/berry_tree.inc), official French texts.
EventScript_HoennBerryTree::
	lock
	faceplayer
	special GetHoennBerryTreeBerries
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_HoennBerryTreeLeave
	checkitemspace VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, EventScript_HoennBerryTreeFull
	additem VAR_0x8004, VAR_0x8005
	removeobject VAR_LAST_TALKED
	message BerryTree_Text_PickedTheBerry
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	release
	end

EventScript_HoennBerryTreeFull::
	message BerryTree_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

EventScript_HoennBerryTreeLeave::
	message BerryTree_Text_BerryLeftUnpicked
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_Text_WantToPick::
    .string "Il y a {STR_VAR_2} {STR_VAR_1}!\p"
    .string "Cueillir {STR_VAR_1}?$"

BerryTree_Text_PickedTheBerry::
    .string "{PLAYER} a cueilli\n"
    .string "{STR_VAR_2} {STR_VAR_1}.$"

BerryTree_Text_PutAwayBerry::
    .string "{PLAYER} met {STR_VAR_1} dans la\n"
    .string "POCHE BAIES du SAC.\p"
    .string "Le sol est à nouveau\n"
    .string "meuble et fertile.$"

BerryTree_Text_BerryPocketFull::
    .string "La POCHE BAIES du SAC est pleine.\p"
    .string "Impossible de cueillir {STR_VAR_1}.$"

BerryTree_Text_BerryLeftUnpicked::
    .string "{PLAYER} n'a pas cueilli\n"
    .string "{STR_VAR_1}.$"

