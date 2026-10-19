# Hoenn : scripts spéciaux à décider

Ces PNJ, panneaux et dresseurs font plus que parler, défier ou dire où l'on est. Ils restent muets en attendant qu'on décide ensemble quoi en faire. Les dialogues simples, les infirmières, les vendeurs et le point de retour des Centres Pokémon sont faits (2026-10-18), puis les choix du 2026-10-18 pour Rosyères, Clémenti-Ville, Mérouville et le pêcheur de Myokara (`work/hoenn_scripts/manual.py`), puis le lot 1 du 2026-10-19 : PNJ et services (`manual_b1.py`). Chaque ligne restante indique son lot.

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

## Myokara (13)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| DewfordTown | TrendyPhraseBoy (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | J'aime ce qui est en vogue, branché et à la mode. Je me tiens toujours… |
| DewfordTown_Hall | Bookshelf (panneau) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | RECONNAITRE LES BONS “{STR_VAR_1}” ET LES MAUVAIS “{STR_VAR_1}”… LE LI… |
| DewfordTown_Hall | ExpertM (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | Tout le monde parle de “{STR_VAR_1}”… N'y aurait-il pas une émission d… |
| DewfordTown_Hall | Girl (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | Qu'est-ce qui est à la mode? Heu, sans doute “{STR_VAR_1}”! Je n'imagi… |
| DewfordTown_Hall | LittleBoy (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | Je collectionne les objets dérivés de “{STR_VAR_1}”. J'ai les poupées … |
| DewfordTown_Hall | Man (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | En ce moment, j'étudie cette mode du “{STR_VAR_1}”. C'est vrai qu'il y… |
| DewfordTown_Hall | Painting (panneau) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | Le titre est: “LE DERNIER {STR_VAR_1}”. |
| DewfordTown_Hall | PsychicM (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | Si nous formons une équipe, nous serons invincibles, dès qu'il s'agira… |
| DewfordTown_Hall | SchoolKidM (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | Si nous formons une équipe, nous serons invincibles, dès qu'il s'agira… |
| DewfordTown_Hall | SludgeBombMan (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — donne CT36; phrase à la mode (système de Myokara, non porté) (selon FLAG_RECEIVED_TM_SLUDGE_BOMB) | Pour moi, la BOMB-BEURK, c'est le nec plus ultra. Pas de doute possibl… |
| DewfordTown_Hall | Twin (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | De l'autre côté de l'océan? Tu crois que “{STR_VAR_1}” est encore plus… |
| DewfordTown_Hall | Woman (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — phrase à la mode (système de Myokara, non porté) | J'essaie d'apprendre “{STR_VAR_1}” à mon POKéMON, mais ça ne marche pa… |
| DewfordTown_House2 | Man (PNJ) | **lot 2 : phrase à la mode (et Barpau)** — donne MOUCH. SOIE (selon FLAG_RECEIVED_SILK_SCARF) | Regarde-moi cette merveille! C'est un MOUCH. SOIE. C'est à la pointe d… |

## Poivressel (6)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| SlateportCity | DecorClerk (PNJ) | **lot 2 : décorations** — décorations (système non porté) (selon FLAG_RECEIVED_SECRET_POWER) | Bienvenue! En quoi puis-je vous aider? |
| SlateportCity | DollClerk (PNJ) | **lot 2 : décorations** — décorations (système non porté) | Bienvenue! En quoi puis-je vous aider? |
| SlateportCity_BattleTentLobby | Attendant (PNJ) | **lot 6 : Tentes et Zone de Combat** — Tente de Combat (défi, prix); ouvre une porte (selon VAR_FRONTIER_BATTLE_MODE, VAR_FRONTIER_FACILITY) | Bienvenue dans la TENTE DE COMBAT de POIVRESSEL! Je serai votre guide … |
| SlateportCity_BattleTentLobby | RulesBoard (panneau) | **lot 6 : Tentes et Zone de Combat** — menu à choix | Règles du COMBAT ECHANGE. |
| SlateportCity_Harbor | FerryAttendant (PNJ) | **lot 4 : S.S. Aqua** — menu à choix (selon FLAG_MET_SCOTT_ON_SS_TIDAL, FLAG_SYS_GAME_CLEAR, VAR_SS_TIDAL_STATE) | Je vous demande pardon? Vous cherchez un bateau? Désolée, vous ne pouv… |
| SlateportCity_Harbor | Sailor (PNJ) | **pas porté (décision du 2026-10-19)** — indique où Groudon / Kyogre causent une météo anormale (après la Ligue) (selon FLAG_DEFEATED_GROUDON, FLAG_DEFEATED_KYOGRE, FLAG_SYS_GAME_CLEAR) | Pour appareiller en toute sécurité, nous devons d'abord consulter la m… |

## Lavandia (1)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| MauvilleCity_PokemonCenter_1F | MauvilleOldMan (PNJ) | **lot 2 : vieil homme de Lavandia** — Vieil homme de Lavandia (chansons/histoires, non porté) (selon FLAG_UNLOCKED_TRENDY_SAYINGS) | Je m'appelle PAPOTEUR! J'ai une super histoire à te raconter! Tu veux … |

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

## Cimetronelle (2)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| FortreeCity_DecorationShop | ClerkChairs (PNJ) | **lot 2 : décorations** — décorations (système non porté) | Bienvenue! En quoi puis-je vous aider? |
| FortreeCity_DecorationShop | ClerkDesks (PNJ) | **lot 2 : décorations** — décorations (système non porté) | Bienvenue! En quoi puis-je vous aider? |

## Atalanopolis (1)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| SootopolisCity_House6 | Woman (PNJ) | **lot 2 : décorations** — décorations (système non porté) (selon FLAG_RECEIVED_WAILMER_DOLL) | Bonjour! Vous êtes la première personne à venir chez nous depuis longt… |

## Pacifiville (1)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| PacifidlogTown_House5 | MirageIslandWatcher (PNJ) | **lot 2 : Île Mirage (avec Latios ou Latias dans l'équipe)** — Île Mirage (selon le jour) | Je n'vois pas l'ILE MIRAGE aujourd'hui… |

## Routes (2)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| Route104_PrettyPetalFlowerShop | ShopOwner (PNJ) | **lot 2 : décorations** — décorations (système non porté) (selon FLAG_MET_PRETTY_PETAL_SHOP_OWNER) | Bonjour! Voici le FLEURISTE JOLIE FLEUR. Vive les fleurs, plantons-en … |
| Route114_LanettesHouse | Lanette (PNJ) | **lot 2 : décorations** — décorations (système non porté) (selon FLAG_RECEIVED_DOLL_LANETTE, FLAG_SYS_PC_LANETTE) | ANNETTE: Oh! {PLAYER}{KUN}! Je suis désolée. C'est la pagaille. Quand … |

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

## Donjons (52)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
| AbandonedShip_CaptainsOffice | CaptSternAide (PNJ) | **lot 3 : donjons** — demande / reprend SCANNER (selon FLAG_EXCHANGED_SCANNER) | J'examine ce bateau pour le CAPT. POUPE. Il m'a aussi demandé de rappo… |
| AbandonedShip_Corridors_B1F | StorageRoomDoor (panneau) | **lot 3 : donjons** — demande / reprend CLE STOCKAGE (selon FLAG_USED_STORAGE_KEY) | {PLAYER} insère et tourne la  CLE STOCKAGE. La CLE insérée se coince u… |
| AbandonedShip_HiddenFloorCorridors | Room1Door (panneau) | **lot 3 : donjons** — demande / reprend CLE SALLE 1 (selon FLAG_USED_ROOM_1_KEY) | {PLAYER} insère et tourne la CLE. La CLE insérée se coince un peu, mai… |
| AbandonedShip_HiddenFloorCorridors | Room2Door (panneau) | **lot 3 : donjons** — demande / reprend CLE SALLE 2 (selon FLAG_USED_ROOM_2_KEY) | {PLAYER} insère et tourne la CLE. La CLE insérée se coince un peu, mai… |
| AbandonedShip_HiddenFloorCorridors | Room4Door (panneau) | **lot 3 : donjons** — demande / reprend CLE SALLE 4 (selon FLAG_USED_ROOM_4_KEY) | {PLAYER} insère et tourne la CLE. La CLE insérée se coince un peu, mai… |
| AbandonedShip_HiddenFloorCorridors | Room6Door (panneau) | **lot 3 : donjons** — demande / reprend CLE SALLE 6 (selon FLAG_USED_ROOM_6_KEY) | {PLAYER} insère et tourne la CLE. La CLE insérée se coince un peu, mai… |
| AncientTomb | CaveEntranceMiddle (panneau) | **lot 3 : donjons** — texte en braille (selon FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED) | Il y a un gros trou dans le mur. |
| AncientTomb | CaveEntranceSide (panneau) | **lot 3 : donjons** — texte en braille |  |
| AncientTomb | Registeel (PNJ) | **lot 3 : donjons** — combat contre un Pokémon sauvage (SPECIES_REGISTEEL) (selon FLAG_DEFEATED_REGISTEEL, FLAG_SYS_CTRL_OBJ_DELETE) | Le {STR_VAR_1} s'est enfui! |
| AquaHideout_B1F | Electrode1 (PNJ) | **lot 3 : donjons** — combat contre un Pokémon sauvage (SPECIES_ELECTRODE) (selon FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, FLAG_SYS_CTRL_OBJ_DELETE) |  |
| AquaHideout_B1F | Electrode2 (PNJ) | **lot 3 : donjons** — combat contre un Pokémon sauvage (SPECIES_ELECTRODE) (selon FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, FLAG_SYS_CTRL_OBJ_DELETE) |  |
| DesertRuins | CaveEntranceMiddle (panneau) | **lot 3 : donjons** — texte en braille (selon FLAG_SYS_REGIROCK_PUZZLE_COMPLETED) | Il y a un gros trou dans le mur. |
| DesertRuins | CaveEntranceSide (panneau) | **lot 3 : donjons** — texte en braille |  |
| DesertRuins | Regirock (PNJ) | **lot 3 : donjons** — combat contre un Pokémon sauvage (SPECIES_REGIROCK) (selon FLAG_DEFEATED_REGIROCK, FLAG_SYS_CTRL_OBJ_DELETE) | Le {STR_VAR_1} s'est enfui! |
| IslandCave | CaveEntranceMiddle (panneau) | **lot 3 : donjons** — texte en braille (selon FLAG_SYS_BRAILLE_REGICE_COMPLETED, VAR_REGICE_STEPS_1, VAR_REGICE_STEPS_2)… | Il y a un gros trou dans le mur. |
| IslandCave | CaveEntranceSide (panneau) | **lot 3 : donjons** — texte en braille (selon FLAG_SYS_BRAILLE_REGICE_COMPLETED, VAR_REGICE_STEPS_1, VAR_REGICE_STEPS_2)… |  |
| IslandCave | Regice (PNJ) | **lot 3 : donjons** — combat contre un Pokémon sauvage (SPECIES_REGICE) (selon FLAG_DEFEATED_REGICE, FLAG_SYS_CTRL_OBJ_DELETE) | Le {STR_VAR_1} s'est enfui! |
| MirageTower_4F | ClawFossil (PNJ) | **lot 3 : donjons** — donne FOSS. GRIFFE (selon FLAG_CHOSE_CLAW_FOSSIL, FLAG_LANDMARK_MIRAGE_TOWER, VAR_MIRAGE_TOWER_STATE) | Tu as trouvé le FOSS. GRIFFE. Si ce FOSSILE est retiré, le sol autour … |
| MirageTower_4F | RootFossil (PNJ) | **lot 3 : donjons** — donne FOSS. RACINE (selon FLAG_CHOSE_ROOT_FOSSIL, FLAG_LANDMARK_MIRAGE_TOWER, VAR_MIRAGE_TOWER_STATE) | Tu as trouvé le FOSS. RACINE. Si ce FOSSILE est retiré, le sol autour … |
| MtChimney | LavaCookieLady (PNJ) | **lot 3 : donjons** — donne LAVA COOKIE; fait payer | Les LAVA COOKIES sont les spécialités locales du MONT CHIMNEE. Goûtes-… |
| MtPyre_1F | CleanseTagWoman (PNJ) | **lot 3 : donjons** — donne RUNE PURIF. (selon FLAG_RECEIVED_CLEANSE_TAG) | Toutes sortes d'êtres se promènent sur les versants du MONT MEMORIA… O… |
| SealedChamber_InnerRoom | BrailleBackWall (panneau) | **lot 3 : donjons** — texte en braille (selon FLAG_REGI_DOORS_OPENED) | Ça résonne comme si une porte s'était ouverte au loin. |
| SealedChamber_InnerRoom | BrailleStoryPart1 (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_InnerRoom | BrailleStoryPart2 (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_InnerRoom | BrailleStoryPart3 (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_InnerRoom | BrailleStoryPart4 (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_InnerRoom | BrailleStoryPart5 (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_InnerRoom | BrailleStoryPart6 (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BrailleABC (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BrailleComma (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BrailleDEF (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BrailleDigHere (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BrailleGHI (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BrailleJKL (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BrailleMNO (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BraillePQRS (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BraillePeriod (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BrailleTUV (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | BrailleWXYZ (panneau) | **lot 3 : donjons** — texte en braille |  |
| SealedChamber_OuterRoom | InnerRoomEntranceWall (panneau) | **lot 3 : donjons** — texte en braille (selon FLAG_SYS_BRAILLE_DIG) | Il y a un gros trou dans le mur. |
| ShoalCave_LowTideEntranceRoom | ShellBellExpert (PNJ) | **lot 3 : donjons** — donne SEL TREFONDS, CO. TREFOND, GRELOT COQUE (selon FLAG_RECEIVED_SHOAL_SALT_1, FLAG_RECEIVED_SHOAL_SALT_2, FLAG_RECEIVED_SHOAL_SALT_3)… | Oh, hé! Des SELS TREFONDS et des  CO. TREFONDS! Et suffisamment! Tu ve… |
| ShoalCave_LowTideInnerRoom | ShoalSalt1 (panneau) | **lot 3 : donjons** — donne SEL TREFONDS (selon FLAG_RECEIVED_SHOAL_SALT_1) | Dommage! Le SAC est plein. |
| ShoalCave_LowTideInnerRoom | ShoalSalt2 (panneau) | **lot 3 : donjons** — donne SEL TREFONDS (selon FLAG_RECEIVED_SHOAL_SALT_2) | Dommage! Le SAC est plein. |
| ShoalCave_LowTideInnerRoom | ShoalShell1 (panneau) | **lot 3 : donjons** — donne CO. TREFOND (selon FLAG_RECEIVED_SHOAL_SHELL_1) | Dommage! Le SAC est plein. |
| ShoalCave_LowTideInnerRoom | ShoalShell2 (panneau) | **lot 3 : donjons** — donne CO. TREFOND (selon FLAG_RECEIVED_SHOAL_SHELL_2) | Dommage! Le SAC est plein. |
| ShoalCave_LowTideInnerRoom | ShoalShell3 (panneau) | **lot 3 : donjons** — donne CO. TREFOND (selon FLAG_RECEIVED_SHOAL_SHELL_3) | Dommage! Le SAC est plein. |
| ShoalCave_LowTideInnerRoom | ShoalShell4 (panneau) | **lot 3 : donjons** — donne CO. TREFOND (selon FLAG_RECEIVED_SHOAL_SHELL_4) | Dommage! Le SAC est plein. |
| ShoalCave_LowTideLowerRoom | BlackBelt (PNJ) | **lot 3 : donjons** — donne BANDEAU (selon FLAG_RECEIVED_FOCUS_BAND) | Ce froid pénétrant dans les alentours est un obstacle à l'entraînement… |
| ShoalCave_LowTideLowerRoom | ShoalSalt4 (panneau) | **lot 3 : donjons** — donne SEL TREFONDS (selon FLAG_RECEIVED_SHOAL_SALT_4) | Dommage! Le SAC est plein. |
| ShoalCave_LowTideStairsRoom | ShoalSalt3 (panneau) | **lot 3 : donjons** — donne SEL TREFONDS (selon FLAG_RECEIVED_SHOAL_SALT_3) | Dommage! Le SAC est plein. |
| SkyPillar_Top | Rayquaza (PNJ) | **lot 3 : donjons** — combat contre un Pokémon sauvage (SPECIES_RAYQUAZA) (selon FLAG_DEFEATED_RAYQUAZA, FLAG_SYS_CTRL_OBJ_DELETE) | Le {STR_VAR_1} s'est enfui! |
| Underwater_SealedChamber | Braille (panneau) | **lot 3 : donjons** — texte en braille |  |
