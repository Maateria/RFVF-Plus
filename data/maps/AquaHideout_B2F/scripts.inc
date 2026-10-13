AquaHideout_B2F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (AquaHideout_B2F_OnTransition)
AquaHideout_B2F_EventScript_ItemNestBall::      @ item ball, works (FLAG_ITEM_AQUA_HIDEOUT_B2F_NEST_BALL)
	finditem ITEM_NEST_BALL
	end
@ hoenn_import: left out: trigger (28,17) VAR_TEMP_1==0 -> AquaHideout_B2F_EventScript_MattNoticePlayer; trigger (28,16) VAR_TEMP_1==0 -> AquaHideout_B2F_EventScript_MattNoticePlayer
