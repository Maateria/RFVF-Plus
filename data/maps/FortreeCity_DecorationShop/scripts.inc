FortreeCity_DecorationShop_MapScripts::
	.byte 0
FortreeCity_DecorationShop_EventScript_PokefanM::
	msgbox FortreeCity_DecorationShop_Text_MerchandiseSentToPC, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_Girl::
	msgbox FortreeCity_DecorationShop_Text_BuyingDeskForDolls, MSGBOX_NPC
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/FortreeCity_DecorationShop/scripts.inc
FortreeCity_DecorationShop_EventScript_ClerkDesks:: @ NPC #3 (1,2)
FortreeCity_DecorationShop_EventScript_ClerkChairs:: @ NPC #4 (6,2)
	end
