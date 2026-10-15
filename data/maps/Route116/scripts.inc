Route116_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route116_OnTransition), ON_LOAD (Route116_OnLoad), ON_FRAME_TABLE (Route116_OnFrame)
Route116_EventScript_ItemEther::                @ item ball, works (FLAG_ITEM_ROUTE_116_ETHER)
	finditem ITEM_ETHER
	end
Route116_EventScript_ItemRepel::                @ item ball, works (FLAG_ITEM_ROUTE_116_REPEL)
	finditem ITEM_REPEL
	end
Route116_EventScript_ItemHPUp::                 @ item ball, works (FLAG_ITEM_ROUTE_116_HP_UP)
	finditem ITEM_HP_UP
	end
Route116_EventScript_ItemXSpecial::             @ item ball, works (FLAG_ITEM_ROUTE_116_X_SPECIAL)
	finditem ITEM_X_SPECIAL
	end
Route116_EventScript_ItemPotion::               @ item ball, works (FLAG_ITEM_ROUTE_116_POTION)
	finditem ITEM_POTION
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route116/scripts.inc
Route116_EventScript_GlassesMan::               @ NPC #15 (74,13)
Route116_EventScript_RouteSignRustboro::        @ sign (5,10)
Route116_EventScript_RusturfTunnelSign::        @ sign (48,9)
Route116_EventScript_TunnelersRestHouseSign::   @ sign (40,9)
Route116_EventScript_TrainerTipsBToStopEvolution:: @ sign (16,12)
Route116_EventScript_TrainerTipsBagHasPockets:: @ sign (29,10)
	end
@ hoenn_import: left out: trigger (47,9) VAR_ROUTE116_STATE==1 -> Route116_EventScript_BrineyTrigger

Route116_EventScript_Joey::
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Clark::
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Janice::
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Karen::
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RematchKaren::
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RematchJerry::
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Sarah::
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Dawson::
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Johnson::
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Devan::
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
	end
