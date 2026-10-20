# Hoenn : scripts spéciaux à décider

Ces PNJ, panneaux et dresseurs font plus que parler, défier ou dire où l'on est. Ils restent muets en attendant qu'on décide ensemble quoi en faire. Les dialogues simples, les infirmières, les vendeurs et le point de retour des Centres Pokémon sont faits (2026-10-18), puis les choix du 2026-10-18 pour Rosyères, Clémenti-Ville, Mérouville et le pêcheur de Myokara (`work/hoenn_scripts/manual.py`), puis le lot 1 du 2026-10-19 : PNJ et services (`manual_b1.py`), puis le lot 2 du 2026-10-19 : systèmes (phrase à la mode, vieil homme de Lavandia, décorations, Île Mirage, arbres à baies : `manual_b2.py`), puis le lot 3 du 2026-10-20 : donjons (braille et Regis, Grotte Tréfonds, Épave, Pilier Céleste, Tour Mirage, météo anormale : `manual_b3.py`). Chaque ligne restante indique son lot.

Liste produite par `work/hoenn_scripts/port.py` (hors dépôt). « Selon » = drapeaux ou variables d'Émeraude que le script regarde.

## Bourg-en-Vol (7)

**Décision : laissé tel quel (décision du 2026-10-18).**

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| LittlerootTown_BrendansHouse_2F | PC (panneau) | PC de la chambre du héros d'Émeraude (e-mails, objets stockés) | Il y a un e-mail de l'ECOLE DE DRESSEURS. … … … … … … Un POKéMON peut … |
| LittlerootTown_BrendansHouse_2F | WallClock (panneau) | horloge murale : régler l'heure (pas d'horloge réelle ici) (selon FLAG_SET_WALL_CLOCK, VAR_LITTLEROOT_INTRO_STATE) | L'horloge est arrêtée… Il vaudrait mieux la mettre à l'heure! |
| LittlerootTown_MaysHouse_2F | PC (panneau) | PC de la chambre du héros d'Émeraude (e-mails, objets stockés) | {PLAYER} allume le PC. |
| LittlerootTown_MaysHouse_2F | WallClock (panneau) | horloge murale : régler l'heure (pas d'horloge réelle ici) (selon FLAG_SET_WALL_CLOCK, VAR_LITTLEROOT_INTRO_STATE) | L'horloge est arrêtée… Il vaudrait mieux la mettre à l'heure! |
| LittlerootTown_ProfessorBirchsLab | Aide (PNJ) | parle seulement, mais selon VAR_BIRCH_LAB_STATE | Hein? Le PROF. SEKO? Le PROFESSEUR est sur le terrain. C'est-à-dire qu… |
| LittlerootTown_ProfessorBirchsLab | Birch (PNJ) | parle seulement, mais selon VAR_DEX_UPGRADE_JOHTO_STARTER_STATE | PROF. SEKO: Où est {RIVAL}? A la maison, je pense. Ou alors quelque pa… |
| LittlerootTown_ProfessorBirchsLab | Rival (PNJ) | parle seulement, mais selon VAR_DEX_UPGRADE_JOHTO_STARTER_STATE | BRICE: Où est-ce que je vais aller chercher des POKéMON, maintenant? |

## Poivressel (2)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| SlateportCity_BattleTentLobby | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Tente de Combat (défi, prix); ouvre une porte (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Bienvenue dans la TENTE DE COMBAT de POIVRESSEL! Je serai votre guide … |
| SlateportCity_BattleTentLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — menu à choix | Règles du COMBAT ECHANGE. |

## Vergazon (2)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| VerdanturfTown_BattleTentLobby | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Tente de Combat (défi, prix); ouvre une porte (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Bienvenue dans la TENTE DE COMBAT de VERGAZON! Nous testons la confian… |
| VerdanturfTown_BattleTentLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — panneau de règles à menu déroulant | Règles de la TENTE DE COMBAT de VERGAZON. |

## Autéquia (2)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| FallarborTown_BattleTentLobby | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Tente de Combat (défi, prix); ouvre une porte (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Bienvenue dans la TENTE DE COMBAT d'AUTEQUIA! Je serai votre guide pou… |
| FallarborTown_BattleTentLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — menu à choix | Règles du TOURNOI K.O. |

## Zone de Combat (47)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| BattleFrontier_BattleArenaLobby | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Palais Combat (Arène) : accueil, règles ou résultats du défi; ouvre une porte (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Bienvenue au DOJO DE COMBAT! Ici, nous mettons à l'épreuve le cran des… |
| BattleFrontier_BattleArenaLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Palais Combat (Arène) : accueil, règles ou résultats du défi | Règles du TOURNOI K.O. |
| BattleFrontier_BattleArenaLobby | ShowResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Palais Combat (Arène) : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattleDomeLobby | DoublesAttendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Dôme de Combat : accueil, règles ou résultats du défi; soigne l'équipe; ouvre une porte (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Le tournoi propose deux niveaux de défi: niveau 50 et niveau libre. Qu… |
| BattleFrontier_BattleDomeLobby | Maniac (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Dôme de Combat : accueil, règles ou résultats du défi | Tu as assisté au dernier TOURNOI DE COMBAT? {STR_VAR_1}, le vainqueur,… |
| BattleFrontier_BattleDomeLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Dôme de Combat : accueil, règles ou résultats du défi | Règles du TOURNOI DE COMBAT. |
| BattleFrontier_BattleDomeLobby | ShowDoublesResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Dôme de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattleDomeLobby | ShowPrevTourneyTree (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Dôme de Combat : accueil, règles ou résultats du défi | Résultats du dernier TOURNOI DE COMBAT DUO niveau libre. |
| BattleFrontier_BattleDomeLobby | ShowSinglesResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Dôme de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattleDomeLobby | SinglesAttendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Dôme de Combat : accueil, règles ou résultats du défi; soigne l'équipe; ouvre une porte (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Le tournoi propose deux niveaux de défi: niveau 50 et niveau libre. Qu… |
| BattleFrontier_BattleFactoryLobby | DoublesAttendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Usine de Combat : accueil, règles ou résultats du défi (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Que choisissez-vous: niveau 50 ou niveau libre? |
| BattleFrontier_BattleFactoryLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Usine de Combat : accueil, règles ou résultats du défi | Règles du COMBAT ECHANGE. |
| BattleFrontier_BattleFactoryLobby | ShowDoublesResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Usine de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattleFactoryLobby | ShowSinglesResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Usine de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattleFactoryLobby | SinglesAttendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Usine de Combat : accueil, règles ou résultats du défi (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Que choisissez-vous: niveau 50 ou niveau libre? |
| BattleFrontier_BattlePalaceLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Palace de Combat : accueil, règles ou résultats du défi | Règles des HALLS DE COMBAT. |
| BattleFrontier_BattlePalaceLobby | ShowDoublesResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Palace de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattlePalaceLobby | ShowSinglesResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Palace de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattlePalaceLobby | SinglesAttendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Palace de Combat : accueil, règles ou résultats du défi; soigne l'équipe; ouvre une porte (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Il y a deux HALLS DE COMBAT: niveau 50 et niveau libre. Que choisissez… |
| BattleFrontier_BattlePikeLobby | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Reptile de Combat : accueil, règles ou résultats du défi; soigne l'équipe (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Bienvenue au REPTILE DE COMBAT… Ici, nous mettons à l'épreuve la chanc… |
| BattleFrontier_BattlePikeLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Reptile de Combat : accueil, règles ou résultats du défi | Règles du COMBAT HASARD. |
| BattleFrontier_BattlePikeLobby | ShowResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Reptile de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattlePikeRoomNormal | NPC (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Reptile de Combat : accueil, règles ou résultats du défi | Bonne chance à toi. Adieu. |
| BattleFrontier_BattlePikeRoomNormal | StatusMon (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Reptile de Combat : accueil, règles ou résultats du défi | … … … … … … … … … … … … |
| BattleFrontier_BattlePikeThreePathRoom | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Reptile de Combat : accueil, règles ou résultats du défi | Vous êtes dans la salle nº 13… |
| BattleFrontier_BattlePikeThreePathRoom | HintGiver (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Reptile de Combat : accueil, règles ou résultats du défi | Oui? Avez-vous du mal à choisir un chemin? |
| BattleFrontier_BattlePyramidLobby | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Pyramide de Combat : accueil, règles ou résultats du défi; soigne l'équipe (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Bienvenue à la PYRAMIDE DE COMBAT! Ici, nous mettons à l'épreuve le co… |
| BattleFrontier_BattlePyramidLobby | HintGiver (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Pyramide de Combat : accueil, règles ou résultats du défi | Bienvenue à toi… Je serais ravie de te dire les malheurs qui t'attende… |
| BattleFrontier_BattlePyramidLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Pyramide de Combat : accueil, règles ou résultats du défi | Règles du COMBAT QUETE. |
| BattleFrontier_BattlePyramidLobby | ShowResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Pyramide de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattlePyramidTop | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Pyramide de Combat : accueil, règles ou résultats du défi | Ça me fait plaisir de vous revoir! Vous avez atteint le sommet de la P… |
| BattleFrontier_BattleTowerLobby | DoublesAttendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Tour de Combat : accueil, règles ou résultats du défi; ouvre une porte (selon FLAG_CANCEL_BATTLE_ROOM_CHALLENGE, VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, VAR_FRONTIER_BATTLE_MODE)… | Bienvenue dans la TOUR DE COMBAT! Ici, nous mettons à l'épreuve le tal… |
| BattleFrontier_BattleTowerLobby | FeelingsMan (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Tour de Combat : accueil, règles ou résultats du défi | Bonjour, bonjour! Vous avez un instant? Pouvez-vous me dire ce que vou… |
| BattleFrontier_BattleTowerLobby | LinkMultisAttendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Tour de Combat : accueil, règles ou résultats du défi; ouvre une porte (selon FLAG_CANCEL_BATTLE_ROOM_CHALLENGE, VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, VAR_FRONTIER_BATTLE_MODE)… | Bienvenue dans la TOUR DE COMBAT! Ici, nous mettons à l'épreuve le tal… |
| BattleFrontier_BattleTowerLobby | MultisAttendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Tour de Combat : accueil, règles ou résultats du défi; ouvre une porte (selon FLAG_CANCEL_BATTLE_ROOM_CHALLENGE, FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, VAR_BRAVO_TRAINER_BATTLE_TOWER_ON)… | Bienvenue dans la TOUR DE COMBAT! Ici, nous mettons à l'épreuve le tal… |
| BattleFrontier_BattleTowerLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Tour de Combat : accueil, règles ou résultats du défi | Règles de la TOUR DE COMBAT. |
| BattleFrontier_BattleTowerLobby | ShowDoublesResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Tour de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattleTowerLobby | ShowLinkMultisResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Tour de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattleTowerLobby | ShowMultisResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Tour de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattleTowerLobby | ShowSinglesResults (panneau) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat, Tour de Combat : accueil, règles ou résultats du défi |  |
| BattleFrontier_BattleTowerMultiPartnerRoom | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat (selon VAR_FRONTIER_BATTLE_MODE) | {PLAYER}, vous n'avez pas trouvé de partenaire. Voulez-vous arrêter de… |
| BattleFrontier_BattleTowerMultiPartnerRoom | Partner1 (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat (selon FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER) |  |
| BattleFrontier_BattleTowerMultiPartnerRoom | Partner2 (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat (selon FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER) |  |
| BattleFrontier_BattleTowerMultiPartnerRoom | Partner3 (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat (selon FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER) |  |
| BattleFrontier_BattleTowerMultiPartnerRoom | Partner4 (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat (selon FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER) |  |
| BattleFrontier_BattleTowerMultiPartnerRoom | Partner5 (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat (selon FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER) |  |
| BattleFrontier_BattleTowerMultiPartnerRoom | Partner6 (PNJ) | **lot 6 : Tentes et Zone de Combat** — Zone de Combat (selon FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER) |  |

## S.S. Aqua (14)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| SSTidalCorridor | ExitSailor (PNJ) | **lot 4 : S.S. Aqua** — téléporte le joueur (selon FLAG_RECEIVED_TM_SNATCH, VAR_SS_TIDAL_STATE) | A mon avis, nous ne toucherons pas terre avant un petit moment. Allez … |
| SSTidalCorridor | Porthole (panneau) | **lot 4 : S.S. Aqua** — parle seulement, mais selon VAR_SS_TIDAL_STATE | Le hublot offre une belle vue sur l'horizon. |
| SSTidalCorridor | Sailor (PNJ) | **lot 4 : S.S. Aqua** — parle seulement, mais selon FLAG_DEFEATED_SS_TIDAL_TRAINERS | N'hésitez pas à entrer dans les autres cabines. Les DRESSEURS qui s'en… |
| SSTidalLowerDeck | Leonard (dresseur) | **lot 4 : S.S. Aqua** — dresseur (combat) du S.S. Aqua, pendant les traversées | Nous sommes les FRERES PROPRETE! L'aîné répand le détergent et le benj… |
| SSTidalLowerDeck | Phillip (dresseur) | **lot 4 : S.S. Aqua** — dresseur (combat) du S.S. Aqua, pendant les traversées | Nous sommes les FRERES PROPRETE! L'aîné répand le détergent et le benj… |
| SSTidalRooms | Bed (panneau) | **lot 4 : S.S. Aqua** — soigne l'équipe (selon VAR_SS_TIDAL_STATE) | Ah, un lit! Je vais me reposer. |
| SSTidalRooms | Colton (dresseur) | **lot 4 : S.S. Aqua** — dresseur (combat) du S.S. Aqua, pendant les traversées | Je suis tout nerveux à l'idée de découvrir de nouveaux POKéMON pendant… |
| SSTidalRooms | Garret (dresseur) | **lot 4 : S.S. Aqua** — dresseur (combat) du S.S. Aqua, pendant les traversées | Je devrais peut-être demander à mon père de m'acheter un yacht. Un yac… |
| SSTidalRooms | Jed (dresseur) | **lot 4 : S.S. Aqua** — dresseur (combat) du S.S. Aqua, pendant les traversées | ALI: C'est la première fois que le pouvoir de notre amour n'est pas le… |
| SSTidalRooms | Lea (dresseur) | **lot 4 : S.S. Aqua** — dresseur (combat) du S.S. Aqua, pendant les traversées | LISE: Je n'y crois pas! Le pouvoir de notre amour n'a pas été le plus … |
| SSTidalRooms | Micah (dresseur) | **lot 4 : S.S. Aqua** — dresseur (combat) du S.S. Aqua, pendant les traversées | Les amis ne sont pas forcément humains. Mes POKéMON sont mes meilleurs… |
| SSTidalRooms | Naomi (dresseur) | **lot 4 : S.S. Aqua** — dresseur (combat) du S.S. Aqua, pendant les traversées | Une croisière autour du monde dans un yacht de luxe n'est pas sans cha… |
| SSTidalRooms | SnatchGiver (PNJ) | **lot 4 : S.S. Aqua** — donne CT49 (selon FLAG_RECEIVED_TM_SNATCH) | Heu… Salut! Je… Non, je n'ai pas l'air suspect! Hé… Tu veux ça? C'est … |
| SSTidalRooms | Thomas (dresseur) | **lot 4 : S.S. Aqua** — dresseur (combat) du S.S. Aqua, pendant les traversées | Un véritable GENTLEMAN ne doit jamais s'énerver, quelle que soit la si… |

## Mont Dresseurs (3)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| TrainerHill_Entrance | Attendant (PNJ) | **lot 5 : Mont Dresseurs** — Mont Dresseurs (défi chronométré) | Faites de votre mieux! |
| TrainerHill_Entrance | Records (panneau) | **lot 5 : Mont Dresseurs** — tableau des records du Mont Dresseurs |  |
| TrainerHill_Roof | Owner (PNJ) | **lot 5 : Mont Dresseurs** — Mont Dresseurs (défi chronométré) | Hum! Hum! Te voilà enfin! Oui, te voilà! Non, ne dis rien! Je sais pou… |
