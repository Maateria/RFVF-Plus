@ johto_import: generated from PokemonHnS data/maps/Route34_hns; scripted maps get their own file later
.equ LOCALID_ROUTE34_DAYCAREMAN, 11

Route34_MapScripts::
	.byte 0

Route34_EventScript_Item8::                     @ item ball (FLAG_ITEM_ROUTE34_SOFTSAND)
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item9::                     @ item ball (FLAG_ITEM_ROUTE34_RARECANDY)
	finditem ITEM_RARE_CANDY
	end

Route34_EventScript_Item12::                    @ item ball (FLAG_ITEM_ROUTE34_TM_EMBARGO)
	finditem ITEM_TM41_TORMENT
	end

@ silent until scripted (PokemonHnS data/maps/Route34_hns/scripts.inc)
Route34_EventScript_YoungsterSamuel::           @ YOUNGSTER_HNS #1 (34,59), trainer TRAINER_SAMUEL_HNS
Route34_EventScript_PokefanMBrandon::           @ BALDING_MAN_HNS #2 (41,53), trainer TRAINER_BRANDON_HNS
Route34_EventScript_CamperTodd::                @ CAMPER_HNS #3 (30,48), trainer TRAINER_TODD_HNS
Route34_EventScript_YoungsterIan::              @ YOUNGSTER_HNS #4 (37,38), trainer TRAINER_IAN_HNS
Route34_EventScript_Jenn::                      @ COOLTRAINER_F_HNS #5 (20,84), trainer TRAINER_JENN_HNS
Route34_EventScript_Irene::                     @ COOLTRAINER_F_HNS #6 (25,84), trainer TRAINER_IRENE_HNS
Route34_EventScript_Kate::                      @ COOLTRAINER_F_HNS #7 (22,87), trainer TRAINER_KATE_HNS
Route34_EventScript_PicnickerGina::             @ PICNICKER_HNS #10 (32,15), trainer TRAINER_GINA_HNS
Route34_EventScript_DaycareMan::                @ OLD_MAN_HNS #11 (31,34)
Route34_EventScript_Sign3::                     @ sign (29,8)
Route34_EventScript_Sign2::                     @ sign (27,28)
Route34_EventScript_Sign1::                     @ sign (33,65)
Route34_EventScript_Door::                      @ sign (23,50)
	end
