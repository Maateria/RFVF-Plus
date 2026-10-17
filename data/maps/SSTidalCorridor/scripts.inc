.equ LOCALID_SS_TIDAL_EXIT_SAILOR, 1
.equ LOCALID_SS_TIDAL_SCOTT, 5

SSTidalCorridor_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (SSTidalCorridor_OnFrame)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SSTidalCorridor/scripts.inc
SSTidalCorridor_EventScript_ExitSailor::        @ NPC #1 (1,11)
SSTidalCorridor_EventScript_Sailor::            @ NPC #2 (16,7)
SSTidalCorridor_EventScript_Briney::            @ NPC #3 (9,2)
SSTidalCorridor_EventScript_Peeko::             @ NPC #4 (7,2)
SSTidalCorridor_EventScript_Porthole::          @ sign (2,1)
SSTidalCorridor_EventScript_Cabin1Sign::        @ sign (5,9)
SSTidalCorridor_EventScript_Cabin2Sign::        @ sign (8,9)
SSTidalCorridor_EventScript_Cabin3Sign::        @ sign (11,9)
SSTidalCorridor_EventScript_Cabin4Sign::        @ sign (14,9)
	end
