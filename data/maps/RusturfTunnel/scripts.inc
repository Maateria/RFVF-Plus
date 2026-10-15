RusturfTunnel_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (RusturfTunnel_OnTransition), ON_FRAME_TABLE (RusturfTunnel_OnFrame)
RusturfTunnel_EventScript_ItemPokeBall::        @ item ball, works (FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL)
	finditem ITEM_POKE_BALL
	end
RusturfTunnel_EventScript_ItemMaxEther::        @ item ball, works (FLAG_ITEM_RUSTURF_TUNNEL_MAX_ETHER)
	finditem ITEM_MAX_ETHER
	end
@ hoenn_import: left out: trigger (23,4) TRIGGER_RUN_IMMEDIATELY==0 -> RusturfTunnel_EventScript_TunnelBlockagePos1; trigger (9,4) VAR_RUSTURF_TUNNEL_STATE==2 -> RusturfTunnel_EventScript_AquaGruntBackUp; trigger (9,5) VAR_RUSTURF_TUNNEL_STATE==2 -> RusturfTunnel_EventScript_AquaGruntBackUp; trigger (25,4) TRIGGER_RUN_IMMEDIATELY==0 -> RusturfTunnel_EventScript_TunnelBlockagePos2; trigger (25,5) TRIGGER_RUN_IMMEDIATELY==0 -> RusturfTunnel_EventScript_TunnelBlockagePos3

RusturfTunnel_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end
