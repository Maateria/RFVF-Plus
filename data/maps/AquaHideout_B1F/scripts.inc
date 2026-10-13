AquaHideout_B1F_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (AquaHideout_B1F_OnResume), ON_TRANSITION (AquaHideout_B1F_OnTransition)
AquaHideout_B1F_EventScript_ItemMaxElixir::     @ item ball, works (FLAG_ITEM_AQUA_HIDEOUT_B1F_MAX_ELIXIR)
	finditem ITEM_MAX_ELIXIR
	end
AquaHideout_B1F_EventScript_ItemMasterBall::    @ item ball, works (FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL)
	finditem ITEM_MASTER_BALL
	end
AquaHideout_B1F_EventScript_ItemNugget::        @ item ball, works (FLAG_ITEM_AQUA_HIDEOUT_B1F_NUGGET)
	finditem ITEM_NUGGET
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/AquaHideout_B1F/scripts.inc
AquaHideout_B1F_EventScript_Electrode1::        @ NPC #3 (16,9)
AquaHideout_B1F_EventScript_Electrode2::        @ NPC #5 (16,10)
	end
