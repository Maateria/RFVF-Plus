MossdeepCity_House3_MapScripts::
	.byte 0
@ He gives his Super Rod only to a player who has none (user's choice)
MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	checkitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper
	giveitem ITEM_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon
	release
	end

