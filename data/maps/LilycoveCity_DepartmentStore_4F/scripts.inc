LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs::
	.2byte ITEM_TM38_FIRE_BLAST
	.2byte ITEM_TM25_THUNDER
	.2byte ITEM_TM14_BLIZZARD
	.2byte ITEM_TM15_HYPER_BEAM
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs::
	.2byte ITEM_TM17_PROTECT
	.2byte ITEM_TM20_SAFEGUARD
	.2byte ITEM_TM33_REFLECT
	.2byte ITEM_TM16_LIGHT_SCREEN
	.2byte ITEM_NONE
	release
	end
