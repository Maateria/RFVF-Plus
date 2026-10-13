.equ LOCALID_ROUTE111_TY_1, 7
.equ LOCALID_ROUTE111_GABBY_1, 8

Route111_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_LOAD (Route111_OnLoad), ON_TRANSITION (Route111_OnTransition), ON_WARP_INTO_MAP_TABLE (Route111_OnWarp), ON_FRAME_TABLE (Route111_OnFrame)
Route111_EventScript_ItemTMSandstorm::          @ item ball, works (FLAG_ITEM_ROUTE_111_TM_SANDSTORM)
	finditem ITEM_TM37_SANDSTORM
	end
Route111_EventScript_ItemStardust::             @ item ball, works (FLAG_ITEM_ROUTE_111_STARDUST)
	finditem ITEM_STARDUST
	end
Route111_EventScript_ItemHPUp::                 @ item ball, works (FLAG_ITEM_ROUTE_111_HP_UP)
	finditem ITEM_HP_UP
	end
Route111_EventScript_ItemElixir::               @ item ball, works (FLAG_ITEM_ROUTE_111_ELIXIR)
	finditem ITEM_ELIXIR
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route111/scripts.inc
Route111_EventScript_Heidi::                    @ trainer #1 (28,51) TRAINER_HEIDI, Emerald NORMAL sight 3
Route111_EventScript_Man1::                     @ NPC #2 (8,91)
Route111_EventScript_Drew::                     @ trainer #3 (29,37) TRAINER_DREW, Emerald NORMAL sight 3
Route111_EventScript_Dusty::                    @ trainer #4 (27,69) TRAINER_DUSTY_1, Emerald NORMAL sight 2
Route111_EventScript_Beau::                     @ trainer #5 (21,47) TRAINER_BEAU, Emerald NORMAL sight 4
Route111_EventScript_Becky::                    @ trainer #6 (32,66) TRAINER_BECKY, Emerald NORMAL sight 3
Route111_EventScript_Girl::                     @ NPC #11 (23,8)
Route111_EventScript_Irene::                    @ trainer #16 (10,82) TRAINER_IRENE, Emerald NORMAL sight 2
Route111_EventScript_Travis::                   @ trainer #17 (11,71) TRAINER_TRAVIS, Emerald NORMAL sight 3
Route111_EventScript_Daisuke::                  @ trainer #18 (32,29) TRAINER_DAISUKE, Emerald NORMAL sight 2
Route111_EventScript_Brooke::                   @ trainer #19 (11,11) TRAINER_BROOKE_1, Emerald NORMAL sight 4
Route111_EventScript_Wilton::                   @ trainer #20 (9,27) TRAINER_WILTON_1, Emerald NORMAL sight 3
Route111_EventScript_Man2::                     @ NPC #21 (20,114)
Route111_EventScript_Tyron::                    @ trainer #22 (26,132) TRAINER_TYRON, Emerald NORMAL sight 5
Route111_EventScript_Celina::                   @ trainer #23 (20,132) TRAINER_CELINA, Emerald NORMAL sight 5
Route111_EventScript_Bianca::                   @ trainer #24 (19,121) TRAINER_BIANCA, Emerald NORMAL sight 2
Route111_EventScript_Hayden::                   @ trainer #25 (16,119) TRAINER_HAYDEN, Emerald NORMAL sight 3
Route111_EventScript_Bryan::                    @ trainer #26 (29,77) TRAINER_BRYAN, Emerald NORMAL sight 7
Route111_EventScript_Celia::                    @ trainer #27 (22,77) TRAINER_CELIA, Emerald NORMAL sight 6
Route111_EventScript_Branden::                  @ trainer #28 (37,77) TRAINER_BRANDEN, Emerald NORMAL sight 7
Route111_EventScript_Hiker::                    @ NPC #30 (14,56)
Route111_EventScript_WinstrateHouseSign::       @ sign (16,114)
Route111_EventScript_RouteSignMauville::        @ sign (24,126)
Route111_EventScript_RouteSign112::             @ sign (7,66)
Route111_EventScript_RouteSign113::             @ sign (13,6)
Route111_EventScript_OldLadysRestStopSign::     @ sign (25,19)
Route111_EventScript_TrainerTipsSpAtkSpDef::    @ sign (7,84)
Route111_EventScript_TrainerHillSign::          @ sign (24,116)
	end
@ hoenn_import: left out: trigger (12,62) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (11,61) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerDown; trigger (12,61) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerDown; trigger (13,61) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerDown; trigger (7,63) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (12,44) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerLeft; trigger (13,43) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerLeft; trigger (14,42) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerLeft; trigger (16,40) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerLeft; trigger (14,61) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerDown; trigger (18,32) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (17,31) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (9,37) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (10,36) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (17,39) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerLeft; trigger (18,38) VAR_TEMP_3==0 -> Route111_EventScript_ViciousSandstormTriggerLeft; trigger (8,64) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (9,65) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (10,65) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (11,66) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (12,67) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (13,68) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (14,69) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SunTrigger; trigger (10,61) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (11,62) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (13,62) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (14,62) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (17,38) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (16,39) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (15,40) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (14,41) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (13,42) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (12,43) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger; trigger (11,44) TRIGGER_RUN_IMMEDIATELY==0 -> Route111_EventScript_SandstormTrigger
