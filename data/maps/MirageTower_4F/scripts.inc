.equ LOCALID_MIRAGE_ROOT_FOSSIL, 1
.equ LOCALID_MIRAGE_CLAW_FOSSIL, 2

MirageTower_4F_MapScripts::
	.byte 0
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MirageTower_4F/scripts.inc
MirageTower_4F_EventScript_RootFossil::         @ NPC #1 (5,4)
MirageTower_4F_EventScript_ClawFossil::         @ NPC #2 (7,4)
	end
