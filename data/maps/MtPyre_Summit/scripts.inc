.equ LOCALID_MT_PYRE_SUMMIT_ARCHIE, 2
.equ LOCALID_MT_PYRE_SUMMIT_OLD_LADY, 3
.equ LOCALID_MT_PYRE_SUMMIT_MAXIE, 4

MtPyre_Summit_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (MtPyre_Summit_OnTransition)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MtPyre_Summit/scripts.inc
MtPyre_Summit_EventScript_OldMan::              @ NPC #1 (22,5)
MtPyre_Summit_EventScript_OldLady::             @ NPC #3 (23,5)
	end
@ hoenn_import: left out: trigger (22,7) VAR_MT_PYRE_STATE==0 -> MtPyre_Summit_EventScript_TeamAquaTrigger0; trigger (23,7) VAR_MT_PYRE_STATE==0 -> MtPyre_Summit_EventScript_TeamAquaTrigger1; trigger (24,7) VAR_MT_PYRE_STATE==0 -> MtPyre_Summit_EventScript_TeamAquaTrigger2; trigger (22,9) VAR_MT_PYRE_STATE==2 -> MtPyre_Summit_EventScript_ArchieMaxieTrigger0; trigger (23,9) VAR_MT_PYRE_STATE==2 -> MtPyre_Summit_EventScript_ArchieMaxieTrigger1; trigger (24,9) VAR_MT_PYRE_STATE==2 -> MtPyre_Summit_EventScript_ArchieMaxieTrigger2
