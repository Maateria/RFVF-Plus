FallarborTown_CozmosHouse_MapScripts::
	.byte 0
@ Prof. Cozmo is home, as at the end of Emerald's story: he only gives his TM, with an intro text (user's choice)
FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveTM
	msgbox FallarborTown_CozmosHouse_Text_CozmoIntro
	giveitem ITEM_TM27_RETURN
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveTM::
	msgbox FallarborTown_CozmosHouse_Text_CozmoResearch
	release
	end

@ Emerald's final state
FallarborTown_CozmosHouse_EventScript_CozmosWife::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_NPC
	end

