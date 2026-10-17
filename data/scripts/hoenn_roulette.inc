@ pokeemerald data/scripts/roulette.inc (its texts are in src/roulette_hoenn.c). No Pokenews here: no special rate day
Roulette_EventScript_Table1::
	goto_if_questlog EventScript_ReleaseEnd
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	goto_if_questlog EventScript_ReleaseEnd
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end
