.equ LOCALID_FOSSIL_MANIAC, 1

Route114_FossilManiacsTunnel_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route114_FossilManiacsTunnel_OnTransition), ON_LOAD (Route114_FossilManiacsTunnel_OnLoad)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/Route114_FossilManiacsTunnel/scripts.inc
Route114_FossilManiacsTunnel_EventScript_FossilManiac:: @ NPC #1 (6,5)
	end
@ hoenn_import: left out: trigger (5,4) VAR_FOSSIL_MANIAC_STATE==1 -> Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn; trigger (6,4) VAR_FOSSIL_MANIAC_STATE==1 -> Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn
