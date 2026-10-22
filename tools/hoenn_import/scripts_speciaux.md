# Hoenn : scripts spéciaux à décider

Ces PNJ, panneaux et dresseurs font plus que parler, défier ou dire où l'on est. Ils restent muets en attendant qu'on décide ensemble quoi en faire. Les dialogues simples, les infirmières, les vendeurs et le point de retour des Centres Pokémon sont faits (2026-10-18), puis les choix du 2026-10-18 pour Rosyères, Clémenti-Ville, Mérouville et le pêcheur de Myokara (`work/hoenn_scripts/manual.py`), puis le lot 1 du 2026-10-19 : PNJ et services (`manual_b1.py`), puis le lot 2 du 2026-10-19 : systèmes (phrase à la mode, vieil homme de Lavandia, décorations, Île Mirage, arbres à baies : `manual_b2.py`), puis le lot 3 du 2026-10-20 : donjons (braille et Regis, Grotte Tréfonds, Épave, Pilier Céleste, Tour Mirage, météo anormale : `manual_b3.py`), puis les lots 4 et 5 du 2026-10-20 : le S.S. Aqua (vers la Zone de Combat) et le Mont Dresseurs (`manual_b45.py`, `trainer_hill_data.py`). Chaque ligne restante indique son lot.

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

## Zone de Combat (12)

| Carte | Script | Ce qu'il fait | Premier texte |
|---|---|---|---|
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
