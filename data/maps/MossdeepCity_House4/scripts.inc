MossdeepCity_House4_MapScripts::
	.byte 0
MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_HOENN_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

@ Basic text instead of the secret base check (user's choice)
MossdeepCity_House4_EventScript_NinjaBoy::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_NPC
	end

