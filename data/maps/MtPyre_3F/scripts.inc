MtPyre_3F_MapScripts::
	.byte 0
MtPyre_3F_EventScript_ItemSuperRepel::          @ item ball, works (FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL)
	finditem ITEM_SUPER_REPEL
	end
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/MtPyre_3F/scripts.inc
MtPyre_3F_EventScript_William::                 @ trainer #1 (1,4) TRAINER_WILLIAM, Emerald NORMAL sight 4
MtPyre_3F_EventScript_Kayla::                   @ trainer #2 (11,4) TRAINER_KAYLA, Emerald NORMAL sight 4
MtPyre_3F_EventScript_Gabrielle::               @ trainer #4 (6,4) TRAINER_GABRIELLE_1, Emerald NORMAL sight 4
	end
