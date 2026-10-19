.equ LOCALID_MT_PYRE_SUMMIT_ARCHIE, 2
.equ LOCALID_MT_PYRE_SUMMIT_OLD_LADY, 3
.equ LOCALID_MT_PYRE_SUMMIT_MAXIE, 4

MtPyre_Summit_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MtPyre_Summit_OnTransition)
MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto MtPyre_Summit_EventScript_OldManAfterRayquaza

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end
@ hoenn_import: left out: trigger (22,7) VAR_MT_PYRE_STATE==0 -> MtPyre_Summit_EventScript_TeamAquaTrigger0; trigger (23,7) VAR_MT_PYRE_STATE==0 -> MtPyre_Summit_EventScript_TeamAquaTrigger1; trigger (24,7) VAR_MT_PYRE_STATE==0 -> MtPyre_Summit_EventScript_TeamAquaTrigger2; trigger (22,9) VAR_MT_PYRE_STATE==2 -> MtPyre_Summit_EventScript_ArchieMaxieTrigger0; trigger (23,9) VAR_MT_PYRE_STATE==2 -> MtPyre_Summit_EventScript_ArchieMaxieTrigger1; trigger (24,9) VAR_MT_PYRE_STATE==2 -> MtPyre_Summit_EventScript_ArchieMaxieTrigger2
