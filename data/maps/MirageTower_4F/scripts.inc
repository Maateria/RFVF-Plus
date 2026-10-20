.equ LOCALID_MIRAGE_ROOT_FOSSIL, 1
.equ LOCALID_MIRAGE_CLAW_FOSSIL, 2

MirageTower_4F_MapScripts::
	.byte 0
@ RFVF+ (user's choice): both fossils can be taken; the tower collapses after the second one
MirageTower_4F_EventScript_RootFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveRootFossil
	giveitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	closemessage
	setflag FLAG_CHOSE_ROOT_FOSSIL
	removeobject LOCALID_MIRAGE_ROOT_FOSSIL
	delay 30
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, MirageTower_4F_EventScript_CollapseMirageTower
	release
	end

MirageTower_4F_EventScript_LeaveRootFossil::
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_ClawFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveClawFossil
	giveitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	closemessage
	setflag FLAG_CHOSE_CLAW_FOSSIL
	removeobject LOCALID_MIRAGE_CLAW_FOSSIL
	delay 30
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, MirageTower_4F_EventScript_CollapseMirageTower
	release
	end

MirageTower_4F_EventScript_LeaveClawFossil::
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_CollapseMirageTower::
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 32
	setvar VAR_0x8007, 2
	special ShakeScreen
	waitstate
	special DoMirageTowerCeilingCrumble
	waitstate
	setvar VAR_MIRAGE_TOWER_STATE, 1
	warp MAP_ROUTE111, 19, 59
	waitstate
	release
	end

