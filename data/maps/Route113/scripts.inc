Route113_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route113_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_OnTransition
	.byte 0
@ hoenn_import: Emerald's mechanics, without its story lines (hoenn_decisions.MECHANICAL_SCRIPTS)
Route113_OnResume:
	setstepcallback STEP_CB_ASH
	end

Route113_OnTransition:
	call Route113_EventScript_CheckSetAshWeather
	end

Route113_EventScript_CheckSetAshWeather::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_0, 19, Route113_EventScript_DontSetAshWeather
	goto_if_gt VAR_TEMP_0, 84, Route113_EventScript_DontSetAshWeather
	setweather WEATHER_VOLCANIC_ASH
	return

Route113_EventScript_DontSetAshWeather::
	return
Route113_EventScript_ItemMaxEther::             @ item ball, works (FLAG_ITEM_ROUTE_113_MAX_ETHER)
	finditem ITEM_MAX_ETHER
	end
Route113_EventScript_ItemSuperRepel::           @ item ball, works (FLAG_ITEM_ROUTE_113_SUPER_REPEL)
	finditem ITEM_SUPER_REPEL
	end
Route113_EventScript_ItemHyperPotion::          @ item ball, works (FLAG_ITEM_ROUTE_113_HYPER_POTION)
	finditem ITEM_HYPER_POTION
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route113/scripts.inc
Route113_EventScript_NinjaBoy::                 @ NPC #1 (66,12)
Route113_EventScript_Gentleman::                @ NPC #2 (36,10)
Route113_EventScript_Jaylen::                   @ trainer #3 (62,8) TRAINER_JAYLEN, Emerald NORMAL sight 3
Route113_EventScript_Dillon::                   @ trainer #4 (21,11) TRAINER_DILLON, Emerald NORMAL sight 3
Route113_EventScript_Madeline::                 @ trainer #5 (51,11) TRAINER_MADELINE_1, Emerald NORMAL sight 2
Route113_EventScript_Tori::                     @ trainer #8 (45,6) TRAINER_TORI_AND_TIA, Emerald NORMAL sight 1
Route113_EventScript_Tia::                      @ trainer #9 (46,6) TRAINER_TORI_AND_TIA, Emerald NORMAL sight 1
Route113_EventScript_Wyatt::                    @ trainer #11 (75,3) TRAINER_WYATT, Emerald NORMAL sight 4
Route113_EventScript_Lawrence::                 @ trainer #12 (71,4) TRAINER_LAWRENCE, Emerald NORMAL sight 1
Route113_EventScript_Sophie::                   @ trainer #13 (7,6) TRAINER_SOPHIE, Emerald NORMAL sight 6
Route113_EventScript_Coby::                     @ trainer #14 (7,13) TRAINER_COBY, Emerald NORMAL sight 6
Route113_EventScript_RouteSign111::             @ sign (85,6)
Route113_EventScript_RouteSignFallarbor::       @ sign (12,9)
Route113_EventScript_TrainerTipsRegisterKeyItems:: @ sign (58,4)
Route113_EventScript_GlassWorkshopSign::        @ sign (31,5)
	end
