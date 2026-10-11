.equ LOCALID_FLOWER_SHOP_OWNER, 1

Route104_PrettyPetalFlowerShop_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route104_PrettyPetalFlowerShop_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route104_PrettyPetalFlowerShop/scripts.inc
Route104_PrettyPetalFlowerShop_EventScript_ShopOwner:: @ NPC #1 (0,3)
Route104_PrettyPetalFlowerShop_EventScript_WailmerPailGirl:: @ NPC #2 (7,3)
Route104_PrettyPetalFlowerShop_EventScript_RandomBerryGirl:: @ NPC #3 (11,6)
	end
