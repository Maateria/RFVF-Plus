.equ LOCALID_SS_TIDAL_EXIT_SAILOR, 1
.equ LOCALID_SS_TIDAL_SCOTT, 5

SSTidalCorridor_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_FRAME_TABLE (SSTidalCorridor_OnFrame)
SSTidalCorridor_EventScript_Briney::
	msgbox SSTidalCorridor_Text_BrineyWelcomeAboard, MSGBOX_NPC
	end

SSTidalCorridor_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox SSTidalCorridor_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SSTidalCorridor_EventScript_Cabin1Sign::
	msgbox SSTidalCorridor_Text_Cabin1, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin2Sign::
	msgbox SSTidalCorridor_Text_Cabin2, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin3Sign::
	msgbox SSTidalCorridor_Text_Cabin3, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin4Sign::
	msgbox SSTidalCorridor_Text_Cabin4, MSGBOX_SIGN
	end

@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SSTidalCorridor/scripts.inc
SSTidalCorridor_EventScript_ExitSailor::        @ NPC #1 (1,11)
SSTidalCorridor_EventScript_Sailor::            @ NPC #2 (16,7)
SSTidalCorridor_EventScript_Porthole::          @ sign (2,1)
	end
