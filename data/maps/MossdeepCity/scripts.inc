MossdeepCity_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MossdeepCity_OnTransition)
MossdeepCity_EventScript_ItemNetBall::          @ item ball, works (FLAG_ITEM_MOSSDEEP_CITY_NET_BALL)
	finditem ITEM_NET_BALL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MossdeepCity/scripts.inc
MossdeepCity_EventScript_Sailor::               @ NPC #1 (38,12)
MossdeepCity_EventScript_ExpertM::              @ NPC #2 (50,34)
MossdeepCity_EventScript_PokefanF::             @ NPC #3 (32,12)
MossdeepCity_EventScript_NinjaBoy::             @ NPC #4 (26,21)
MossdeepCity_EventScript_Girl::                 @ NPC #5 (45,18)
MossdeepCity_EventScript_Man::                  @ NPC #7 (55,5)
MossdeepCity_EventScript_Woman::                @ NPC #8 (56,21)
MossdeepCity_EventScript_KingsRockBoy::         @ NPC #9 (23,13)
MossdeepCity_EventScript_DynamicPunchTutor::    @ NPC #10 (19,25)
MossdeepCity_EventScript_BlackBelt::            @ NPC #11 (31,29)
MossdeepCity_EventScript_CitySign::             @ sign (25,16)
MossdeepCity_EventScript_GymSign::              @ sign (34,9)
MossdeepCity_EventScript_SpaceCenterSign::      @ sign (66,16)
MossdeepCity_EventScript_WhiteRock::            @ sign (57,21)
	end
@ hoenn_import: left out: trigger (25,25) VAR_TEMP_1==0 -> MossdeepCity_EventScript_VisitedMossdeep; trigger (26,25) VAR_TEMP_1==0 -> MossdeepCity_EventScript_VisitedMossdeep; trigger (32,27) VAR_TEMP_1==0 -> MossdeepCity_EventScript_VisitedMossdeep; trigger (33,27) VAR_TEMP_1==0 -> MossdeepCity_EventScript_VisitedMossdeep; trigger (42,21) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (41,22) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (41,23) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (41,24) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (40,25) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter; trigger (40,26) VAR_MOSSDEEP_CITY_STATE==1 -> MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter
