RustboroCity_CuttersHouse_MapScripts::
	.byte 0
RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

@ The player has known HM01 Cut since Kanto: the Cutter has nothing left to give (user's choice)
RustboroCity_CuttersHouse_EventScript_Cutter::
	msgbox RustboroCity_CuttersHouse_Text_AlreadyKnowCut, MSGBOX_NPC
	end

