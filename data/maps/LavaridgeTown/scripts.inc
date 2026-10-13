LavaridgeTown_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (LavaridgeTown_OnTransition), ON_FRAME_TABLE (LavaridgeTown_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/LavaridgeTown/scripts.inc
LavaridgeTown_EventScript_ExpertF::             @ NPC #1 (8,7)
LavaridgeTown_EventScript_ExpertM::             @ NPC #2 (5,1)
LavaridgeTown_EventScript_OldMan::              @ NPC #3 (5,8)
LavaridgeTown_EventScript_Twin::                @ NPC #4 (10,13)
LavaridgeTown_EventScript_HotSpringsOldWoman1:: @ NPC #5 (4,4)
LavaridgeTown_EventScript_HotSpringsOldWoman2:: @ NPC #6 (5,4)
LavaridgeTown_EventScript_EggWoman::            @ NPC #7 (4,7)
LavaridgeTown_EventScript_HerbShopSign::        @ sign (14,16)
LavaridgeTown_EventScript_GymSign::             @ sign (7,15)
LavaridgeTown_EventScript_TownSign::            @ sign (13,8)
	end
@ hoenn_import: left out: trigger (6,3) TRIGGER_RUN_IMMEDIATELY==0 -> LavaridgeTown_EventScript_HotSpringsTrigger
