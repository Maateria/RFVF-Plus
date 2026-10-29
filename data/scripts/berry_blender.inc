@ Emerald's data/scripts/berry_blender.inc (contests session 3): the NPC Berry Blenders of the Lilycove contest lobby.
@ RFVF+: no link mode (the link blender explains a friend with a cable is needed); blender 1's spare Pecha Berry is the
@ old man's once-only gift (FLAG_RECEIVED_LILYCOVE_PECHA_BERRY, his talk script is in the lobby's scripts.inc).
.set NUM_OPPONENTS, VAR_0x8009
.equ LOCALID_BLEND_MASTER, 13 @ Emerald's name: blender 1's old man (Expert M), hidden while the Blend Master is there
.equ LOCALID_CONTEST_LOBBY_BLENDER_2_LEADER, 3
.equ LOCALID_CONTEST_LOBBY_BLENDER_2_PARTICIPANT, 8
.equ LOCALID_CONTEST_LOBBY_BLENDER_3_LEADER, 12
.equ LOCALID_CONTEST_LOBBY_BLENDER_3_PARTICIPANT_1, 7
.equ LOCALID_CONTEST_LOBBY_BLENDER_3_PARTICIPANT_2, 14

BerryBlender_EventScript_BerryBlender1::
	lockall
	goto_if_unset FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER, BerryBlender_EventScript_BlendMasterPresent
	setvar NUM_OPPONENTS, 1
	applymovement LOCALID_BLEND_MASTER, BerryBlender_Movement_BlendLeaderWalkInPlace
	waitmovement 0
	msgbox BerryBlender_Text_WantToMakePokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryBlender_EventScript_TryUseBerryBlender1
	msgbox BerryBlender_Text_MadeOldTimerSad, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_Blender1NoBerries:
	msgbox BerryBlender_Text_DontHaveAnyBerries, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_LILYCOVE_PECHA_BERRY, BerryBlender_EventScript_Blender1NoSpareBerries
	msgbox BerryBlender_Text_CanHaveOneOfMyBerries, MSGBOX_DEFAULT
	giveitem ITEM_PECHA_BERRY
	setflag FLAG_RECEIVED_LILYCOVE_PECHA_BERRY
	goto BerryBlender_EventScript_UseBerryBlender1
	end

BerryBlender_EventScript_Blender1NoSpareBerries:
	msgbox BerryBlender_Text_DontHaveAnyBerriesToSpare, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_UseBerryBlender1:
	msgbox BerryBlender_Text_KnowHowToMakePokeblocks, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, BerryBlender_EventScript_ExplainBlending1
	msgbox BerryBlender_Text_LetsBerryBlender, MSGBOX_DEFAULT
	goto BerryBlender_EventScript_DoBerryBlending
	end

BerryBlender_EventScript_ExplainBlending1:
	msgbox BerryBlender_Text_ExplainBerryBlending, MSGBOX_DEFAULT
	return

BerryBlender_EventScript_TryUseBerryBlender1:
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_Blender1NoCase
	specialvar VAR_RESULT, GetFirstFreePokeblockSlot
	goto_if_eq VAR_RESULT, 65535, BerryBlender_EventScript_Blender1CaseFull
	specialvar VAR_RESULT, HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_Blender1NoBerries
	msgbox BerryBlender_Text_Excellent, MSGBOX_DEFAULT
	goto BerryBlender_EventScript_UseBerryBlender1
	end

BerryBlender_EventScript_DoBerryBlending:
	copyvar VAR_0x8004, NUM_OPPONENTS
	fadescreen FADE_TO_BLACK
	special DoBerryBlending
	waitstate
	releaseall
	end

BerryBlender_EventScript_Blender1CaseFull:
	msgbox BerryBlender_Text_PokeblockCaseIsFull, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_Blender1NoCase:
	msgbox BerryBlender_Text_DontHavePokeblockCase, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_BerryBlender2::
	lockall
	setvar NUM_OPPONENTS, 2
	applymovement LOCALID_CONTEST_LOBBY_BLENDER_2_PARTICIPANT, Common_Movement_FaceOriginalDirection
	applymovement LOCALID_CONTEST_LOBBY_BLENDER_2_LEADER, BerryBlender_Movement_BlendLeaderWalkInPlace
	waitmovement 0
	msgbox BerryBlender_Text_WantToBlendPokeblocksWithUs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryBlender_EventScript_TryUseBerryBlender2
	msgbox BerryBlender_Text_ThatsTooBad, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_UseBerryBlender2:
	msgbox BerryBlender_Text_KnowHowToMakePokeblocks2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, BerryBlender_EventScript_ExplainBlending2
	msgbox BerryBlender_Text_LetsBerryBlender2, MSGBOX_DEFAULT
	goto BerryBlender_EventScript_DoBerryBlending
	end

BerryBlender_EventScript_ExplainBlending2:
	msgbox BerryBlender_Text_ExplainBerryBlending2, MSGBOX_DEFAULT
	return

BerryBlender_EventScript_TryUseBerryBlender2:
	specialvar VAR_RESULT, HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_Blender2NoBerries
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_Blender2NoCase
	msgbox BerryBlender_Text_Okay, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetFirstFreePokeblockSlot
	goto_if_ne VAR_RESULT, 65535, BerryBlender_EventScript_UseBerryBlender2
	msgbox BerryBlender_Text_PokeblockCaseIsFull2, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_Blender2NoBerries:
	msgbox BerryBlender_Text_DontHaveAnyBerries2, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_Blender2NoCase:
	msgbox BerryBlender_Text_DontHavePokeblockCase2, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_BerryBlender3::
	lockall
	setvar NUM_OPPONENTS, 3
	applymovement LOCALID_CONTEST_LOBBY_BLENDER_3_PARTICIPANT_1, Common_Movement_FaceOriginalDirection
	applymovement LOCALID_CONTEST_LOBBY_BLENDER_3_PARTICIPANT_2, Common_Movement_FaceOriginalDirection
	applymovement LOCALID_CONTEST_LOBBY_BLENDER_3_LEADER, BerryBlender_Movement_BlendLeaderWalkInPlace
	waitmovement 0
	msgbox BerryBlender_Text_LookGoodAtBlendingJoinUs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryBlender_EventScript_TryUseBlender3
	msgbox BerryBlender_Text_LeftUsInShock, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_UseBerryBlender3:
	msgbox BerryBlender_Text_KnowHowToMakePokeblocks3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, BerryBlender_EventScript_ExplainBlending3
	msgbox BerryBlender_Text_LetsBerryBlender3, MSGBOX_DEFAULT
	goto BerryBlender_EventScript_DoBerryBlending
	end

BerryBlender_EventScript_ExplainBlending3:
	msgbox BerryBlender_Text_ExplainBerryBlending3, MSGBOX_DEFAULT
	return

BerryBlender_EventScript_TryUseBlender3:
	specialvar VAR_RESULT, HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_Blender3NoBerries
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_Blender3NoCase
	msgbox BerryBlender_Text_OhDear, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetFirstFreePokeblockSlot
	goto_if_ne VAR_RESULT, 65535, BerryBlender_EventScript_UseBerryBlender3
	msgbox BerryBlender_Text_PokeblockCaseIsFull3, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_Blender3NoBerries:
	msgbox BerryBlender_Text_DontHaveAnyBerries3, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_Blender3NoCase:
	msgbox BerryBlender_Text_DontHavePokeblockCase3, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_BlendMasterPresent:
	setvar NUM_OPPONENTS, 1
	msgbox BerryBlender_Text_SeeMyMasteryInAction, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryBlender_EventScript_TryBlendWithBlendMaster
	msgbox BerryBlender_Text_TooBusyNowIsee, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_TryBlendWithBlendMaster:
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_BlendMasterNoCase
	specialvar VAR_RESULT, HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_BlendMasterNoBerries
	specialvar VAR_RESULT, GetFirstFreePokeblockSlot
	goto_if_eq VAR_RESULT, 65535, BerryBlender_EventScript_BlendMasterCaseFull
	msgbox BerryBlender_Text_BlendMasterKnowHowToMakePokeblocks, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, BerryBlender_EventScript_BlendMasterExplainBlending
	msgbox BerryBlender_Text_BlendMasterLetsBerryBlender, MSGBOX_DEFAULT
	goto BerryBlender_EventScript_DoBerryBlending
	end

BerryBlender_EventScript_BlendMasterExplainBlending:
	msgbox BerryBlender_Text_BlendMasterExplainBerryBlending, MSGBOX_DEFAULT
	return

BerryBlender_EventScript_BlendMasterNoBerries:
	msgbox BerryBlender_Text_BlendMasterNoBerries, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_BlendMasterNoCase:
	msgbox BerryBlender_Text_BlendMasterNoPokeblockCase, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_BlendMasterCaseFull:
	msgbox BerryBlender_Text_BlendMasterPokeblockCaseFull, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_Blender2Man::
	msgbox BerryBlender_Text_SetNewBlenderRecord, MSGBOX_NPC
	end

BerryBlender_EventScript_Blender3PokefanF::
	msgbox BerryBlender_Text_LookGoodAtBlendingJoinUs, MSGBOX_NPC
	end

BerryBlender_EventScript_Blender2Twin::
	msgbox BerryBlender_Text_MakeDeliciousPokeblocks, MSGBOX_NPC
	end

BerryBlender_Movement_BlendLeaderWalkInPlace:
	walk_in_place_faster_right
	step_end

@ RFVF+: no cable here: Emerald's checks and intro, then a friend with a cable is needed
BerryBlender_EventScript_BerryBlenderLink::
	lockall
	specialvar VAR_RESULT, HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_LinkBlenderNoBerries
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, BerryBlender_EventScript_LinkBlenderNoCase
	specialvar VAR_RESULT, GetFirstFreePokeblockSlot
	goto_if_eq VAR_RESULT, 65535, BerryBlender_EventScript_LinkBlenderCaseFull
	msgbox BerryBlender_Text_BerryBlenderLinkNeedFriend, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_LinkBlenderNoBerries:
	msgbox BerryBlender_Text_NoBerriesLink, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_LinkBlenderNoCase:
	msgbox BerryBlender_Text_DontHavePokeblockCaseLink, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_EventScript_LinkBlenderCaseFull:
	msgbox BerryBlender_Text_PokeblockCaseIsFullLink, MSGBOX_DEFAULT
	releaseall
	end

BerryBlender_Text_BerryBlenderLinkNeedFriend:
	.string "Il va être possible de créer des\n"
	.string "POKéBLOCS entre amis en utilisant\l"
	.string "des BAIES avec le MIXEUR.\p"
	.string "Pour cela, il vous faut un ami muni\n"
	.string "lui aussi d'un câble Game Boy\l"
	.string "Advance Game Link.$"

@ BEGIN texts (French Emerald, work/hoenn_scripts/blender_texts.py)
BerryBlender_Text_WantToMakePokeblocks:
	.string "Oh? Tu veux créer des POKéBLOCS\n"
	.string "avec un ancêtre comme moi?$"

BerryBlender_Text_MadeOldTimerSad:
	.string "Oh… Je suis l'ancêtre le plus\n"
	.string "triste du monde…$"

BerryBlender_Text_DontHaveAnyBerries:
	.string "Oh?\n"
	.string "Tu n'as pas de BAIE?\p"
	.string "Sans BAIE, il est impossible de créer\n"
	.string "des POKéBLOCS.$"

BerryBlender_Text_CanHaveOneOfMyBerries:
	.string "Bon, ça ne va pas du\n"
	.string "tout, n'est-ce pas?\p"
	.string "Si ça ne te gêne pas de prendre mes\n"
	.string "restes, je peux te\l"
	.string "donner une BAIE.\p"
	.string "Comme ça, on peut créer des\n"
	.string "POKéBLOCS avec le MIXEUR.$"

BerryBlender_Text_DontHaveAnyBerriesToSpare:
	.string "S'il me restait des BAIES, je t'en\n"
	.string "donnerais volontiers une…\p"
	.string "Mais, aujourd'hui, je n'ai\n"
	.string "plus de BAIE à partager.\l"
	.string "Ce sera pour une autre fois.$"

BerryBlender_Text_KnowHowToMakePokeblocks:
	.string "Tu sais comment créer un POKéBLOC?$"

BerryBlender_Text_LetsBerryBlender:
	.string "Dans ce cas, allons-y!\p"
	.string "C'est parti pour le MIXEUR!$"

BerryBlender_Text_ExplainBerryBlending:
	.string "Dans ce cas, je vais t'expliquer.\p"
	.string "Ne t'inquiète pas, c'est simple comme\n"
	.string "bonjour.\p"
	.string "Lorsque la flèche du MIXEUR passe\n"
	.string "devant ton marqueur, appuie\l"
	.string "simplement sur le bouton A.\p"
	.string "Voilà, c'est tout.\n"
	.string "Essaie, tu verras, c'est enfantin.$"

BerryBlender_Text_Excellent:
	.string "Excellent!$"

BerryBlender_Text_PokeblockCaseIsFull:
	.string "Mais ta BOITE\n"
	.string "POKéBLOCS est pleine.\p"
	.string "Tu devrais utiliser des POKéBLOCS et\n"
	.string "revenir me voir.$"

BerryBlender_Text_DontHavePokeblockCase:
	.string "Mais tu n'as pas de\n"
	.string "BOITE POKéBLOCS.\p"
	.string "Trouve une BOITE POKéBLOCS et\n"
	.string "reviens me voir.$"

BerryBlender_Text_WantToBlendPokeblocksWithUs:
	.string "Salut toi!\n"
	.string "Tu veux créer des POKéBLOCS?$"

BerryBlender_Text_ThatsTooBad:
	.string "Quel dommage…\p"
	.string "Dès que tu as une petite envie de\n"
	.string "mixer, viens par ici!$"

BerryBlender_Text_KnowHowToMakePokeblocks2:
	.string "Tu sais comment créer\n"
	.string "un POKéBLOC, non?$"

BerryBlender_Text_LetsBerryBlender2:
	.string "Dans ce cas, allons-y!\p"
	.string "C'est parti pour le MIXEUR!$"

BerryBlender_Text_ExplainBerryBlending2:
	.string "Dans ce cas, je vais t'expliquer.\p"
	.string "Lorsque la flèche du MIXEUR passe\n"
	.string "devant ton marqueur, appuie\l"
	.string "simplement sur le bouton A.\p"
	.string "Voilà, c'est tout.\n"
	.string "C'est trop facile, tu verras!$"

BerryBlender_Text_Okay:
	.string "Excellent!$"

BerryBlender_Text_PokeblockCaseIsFull2:
	.string "Mais ta BOITE\n"
	.string "POKéBLOCS est pleine.\p"
	.string "Tu devrais utiliser des POKéBLOCS et\n"
	.string "repasser.$"

BerryBlender_Text_DontHaveAnyBerries2:
	.string "Oh?\n"
	.string "Tu n'as pas de BAIE?\p"
	.string "Sans BAIE, il est impossible de créer\n"
	.string "des POKéBLOCS.\p"
	.string "Repasse quand tu auras quelques\n"
	.string "BAIES à mixer.$"

BerryBlender_Text_DontHavePokeblockCase2:
	.string "Mais tu n'as pas de\n"
	.string "BOITE POKéBLOCS.\p"
	.string "Trouve une BOITE POKéBLOCS et\n"
	.string "repasse nous voir.$"

BerryBlender_Text_LookGoodAtBlendingJoinUs:
	.string "Dis, toi!\n"
	.string "Je suis sûre que tu sais bien\l"
	.string "mixer! Tu veux te joindre à nous?$"

BerryBlender_Text_LeftUsInShock:
	.string "Oh…\p"
	.string "Nous sommes en état de choc.$"

BerryBlender_Text_KnowHowToMakePokeblocks3:
	.string "Bien sûr, tu dois savoir\n"
	.string "comment créer un POKéBLOC.\l"
	.string "N'est-ce pas que tu sais?$"

BerryBlender_Text_LetsBerryBlender3:
	.string "Dans ce cas, allons-y!\p"
	.string "C'est parti pour le MIXEUR!$"

BerryBlender_Text_ExplainBerryBlending3:
	.string "Pas possible!\p"
	.string "Dans ce cas, je vais t'expliquer.\p"
	.string "Lorsque la flèche du MIXEUR passe\n"
	.string "devant ton marqueur, appuie\l"
	.string "simplement sur le bouton A.\p"
	.string "Voilà, c'est tout.\n"
	.string "C'est trop facile, tu verras!$"

BerryBlender_Text_OhDear:
	.string "Oh!$"

BerryBlender_Text_PokeblockCaseIsFull3:
	.string "Mais ta BOITE\n"
	.string "POKéBLOCS est pleine.\p"
	.string "Tu devrais utiliser des POKéBLOCS et\n"
	.string "repasser.$"

BerryBlender_Text_DontHaveAnyBerries3:
	.string "Oh?\n"
	.string "Tu n'as pas de BAIE?\p"
	.string "Sans BAIE, il est impossible de créer\n"
	.string "des POKéBLOCS.\p"
	.string "Je reste ici pour faire des\n"
	.string "POKéBLOCS. Reviens dès que tu\l"
	.string "auras quelques BAIES!$"

BerryBlender_Text_DontHavePokeblockCase3:
	.string "Mais tu n'as pas de\n"
	.string "BOITE POKéBLOCS.\p"
	.string "Trouve une BOITE POKéBLOCS et\n"
	.string "repasse.$"

BerryBlender_Text_SeeMyMasteryInAction:
	.string "MAITRE MIXEUR: Hum! Alors comme ça,\n"
	.string "tu veux voir le maître à l'œuvre?$"

BerryBlender_Text_TooBusyNowIsee:
	.string "Hum!\p"
	.string "Tu n'as pas le temps, je vois!\p"
	.string "Mais ne crains rien!\n"
	.string "Je ne bouge pas d'ici aujourd'hui!\l"
	.string "Reviens vite!$"

BerryBlender_Text_BlendMasterKnowHowToMakePokeblocks:
	.string "Bien sûr!\n"
	.string "Bien sûr!\p"
	.string "Au fait…\n"
	.string "Tu sais comment mixer des BAIES\l"
	.string "pour faire des POKéBLOCS?$"

BerryBlender_Text_BlendMasterLetsBerryBlender:
	.string "Bien!\p"
	.string "Dans ce cas, allons-y!\p"
	.string "C'est parti pour le MIXEUR,\n"
	.string "avec le MAITRE MIXEUR!$"

BerryBlender_Text_BlendMasterExplainBerryBlending:
	.string "Hum!\p"
	.string "C'est simple comme bonjour!\p"
	.string "Lorsque la flèche du MIXEUR passe\n"
	.string "devant ton marqueur, appuie\l"
	.string "simplement sur le bouton A.\p"
	.string "C'est tout.\p"
	.string "Quand tu me verras appuyer sur le\n"
	.string "bouton A, tu comprendras comme\l"
	.string "c'est facile.$"

BerryBlender_Text_BlendMasterNoBerries:
	.string "Hum!\p"
	.string "Tu n'as pas une seule BAIE!\p"
	.string "Je ne bouge pas d'ici aujourd'hui!\n"
	.string "Reviens vite!$"

BerryBlender_Text_BlendMasterNoPokeblockCase:
	.string "Hum!\p"
	.string "On dirait que tu n'as pas encore\n"
	.string "de BOITE POKéBLOCS!\p"
	.string "Je ne bouge pas d'ici aujourd'hui!\n"
	.string "Trouve vite une BOITE POKéBLOCS!$"

BerryBlender_Text_BlendMasterPokeblockCaseFull:
	.string "Hum!\p"
	.string "Ta BOITE POKéBLOCS est pleine!\p"
	.string "Je ne bouge pas d'ici aujourd'hui!\n"
	.string "Utilise quelques\l"
	.string "POKéBLOCS et reviens!$"

BerryBlender_Text_SetNewBlenderRecord:
	.string "Aujourd'hui, je vais battre le record\n"
	.string "de vitesse du MIXEUR!$"

BerryBlender_Text_MakeDeliciousPokeblocks:
	.string "Je vais faire de délicieux POKéBLOCS\n"
	.string "pour rendre mes\l"
	.string "POKéMON plus gracieux.$"

BerryBlender_Text_NoBerriesLink:
	.string "Vous n'avez pas de BAIES.\n"
	.string "Impossible d'utiliser le MIXEUR.$"

BerryBlender_Text_DontHavePokeblockCaseLink:
	.string "Vous n'avez pas de BOITE POKéBLOCS.\n"
	.string "Impossible d'utiliser le MIXEUR.$"

BerryBlender_Text_PokeblockCaseIsFullLink:
	.string "Votre BOITE POKéBLOCS est pleine.\n"
	.string "Impossible d'utiliser le MIXEUR.$"

BerryBlender_Text_LetsGetBlendingAlready:
	.string "C'est parti pour le mélange!$"

BerryBlender_Text_WhatKindOfPokeblockWillIGet:
	.string "Je me demande quel type de POKéBLOC\n"
	.string "je vais créer! C'est palpitant!$"

BerryBlender_Text_BlendWithTheBlendMaster:
	.string "MAITRE MIXEUR: C'est moi!\n"
	.string "Je suis le MAITRE MIXEUR!\p"
	.string "Mixe avec moi et tu verras le\n"
	.string "maître à l'œuvre!$"

BerryBlender_Text_WhoaAwesome:
	.string "Waouh!\n"
	.string "Joli!$"

BerryBlender_Text_WickedlyFast:
	.string "Super rapide!$"

BerryBlender_Text_WhatAnExpert:
	.string "Formidable!$"

BerryBlender_Text_MadeAmazingPokeblocksWithMaster:
	.string "J'ai mixé avec le MAITRE MIXEUR et\n"
	.string "on a fait de superbes POKéBLOCS!$"

BerryBlender_Text_QualitiesOfBlendMaster:
	.string "Des yeux de lynx qui suivent la\n"
	.string "flèche au centième\l"
	.string "de millimètre près…\p"
	.string "Une main qui appuie sur le bouton A\n"
	.string "avec la précision d'un métronome…\p"
	.string "C'est ça qui fait le succès du\n"
	.string "MAITRE MIXEUR.$"

BerryBlender_Text_MasterWorksOnSkillsInMountains:
	.string "Le MAITRE MIXEUR passe tout son\n"
	.string "temps à s'entraîner\l"
	.string "dans la montagne.\p"
	.string "Parfois, il nous fait l'honneur\n"
	.string "de venir à NENUCRIQUE\l"
	.string "pour y mixer des BAIES.$"
@ END texts
