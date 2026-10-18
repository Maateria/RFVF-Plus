# tools/johto_import — Johto depuis Pokémon Heart and Soul

Importe Johto depuis un clone de PokemonHnS (`../pokehns`, jamais modifié). Crédits : `CREDITS_JOHTO.md`.

## Lancer (depuis la racine du dépôt, Git Bash ou PowerShell)

Dans cet ordre (l'import vérifie que les sprites et les musiques existent) :

    uv run --no-project --with pillow python tools/johto_import/johto_sprites.py
    uv run --no-project --with pillow python tools/johto_import/johto_music.py
    uv run --no-project --with pillow python tools/johto_import/johto_import.py
    .\fast_build.cmd

Options de l'import : `--dry-run` (tout vérifier, ne rien écrire), `--no-render` (sans le contrôle de rendu, plus
rapide), `--render DOSSIER` (une image de chaque map). Les deux autres outils ont `--check`.

Chaque lancement **refait tout Johto** à partir de HnS et de `johto_decisions.py` : on change une décision, pas un
fichier généré. Relancer sans rien changer ne modifie aucun fichier. Les parties générées des fichiers partagés sont
entre des lignes `BEGIN/END johto_import` (ou `johto_sprites.py`, `johto_music`).

## Ce que font les outils

- `johto_sprites.py` : les sprites que montrent les objets gardés (personnages et objets de HnS
  → `OBJ_EVENT_GFX_JOHTO_*`, Pokémon que RFVF+ n'a pas → `OBJ_EVENT_GFX_JOHTO_MON_*` ; un Pokémon que RFVF+ a déjà garde
  le sprite de RFVF+). Ids dans le bloc Johto (512-767), étiquettes de palette 0x1160-0x11FE.
- `johto_music.py` : les musiques MUS_HG_* des maps (et Surf/Vélo de Johto), le voicegroup 229 de HnS et ses
  sous-voicegroups (renumérotés à partir de 192), ses tables de répartition (`KeySplitTableJohtoN`), ses samples WAV
  (`sound/direct_sound_samples/johto/`, convertis par `tools/wav2agb`).
- `johto_import.py` : les maps de Johto (celles que le joueur atteint depuis Bourg Geon), leurs layouts, leurs tilesets
  (copiés tels quels : HnS a déjà les tailles de FRLG ; attributs convertis par nom de behavior), les scripts muets,
  les objets ramassables et cachés, les rencontres, les Centres Pokémon (soin, réapparition, Vol), les portes animées,
  les animations de tuiles, la frontière avec Kanto.

## À savoir

- **Sauvegardes** : `johto_flags.json` (flags des objets), les ids de sprites et de musiques et l'ordre des maps
  dans leurs groupes sont enregistrés dans les sauvegardes : on ajoute, on ne renumérote jamais.
- **Objets laissés de côté** (liste dans `johto_report.txt`) : déclencheurs et objets d'histoire (ils viendront avec
  les scripts), Pokémon et lumières de nuit (pas de jour/nuit), arbres à baies, et les Pokémon de décor de HnS (les
  autres régions n'en ont pas) : un Pokémon sans flag d'histoire dont le script n'est rien ou son cri et une phrase.
  Restent ceux qui sont à côté d'une personne (son dresseur) et ceux de `POKEMON_KEPT` (les Pokémon d'Or/Argent/HG-SS
  et de la Pension). `johto_sprites.py` retire les sprites qu'aucun objet ne montre plus (leurs numéros restent
  réservés).
- **Moteur** (C) : `IsJohtoMapLayout()` (src/fieldmap.c) choisit les tables de Johto (portes, PC, ascenseur, Coupe) ;
  palettes des sprites en mode `OBJ_PAL_MODE_JOHTO` (4 palettes PNJ de HnS fixes, toute autre palette dans un
  emplacement libre 6-15) ; Coup d'Boule (`MB_HEADBUTT_TREE`, `EventScript_Headbutt`), escaliers latéraux
  (`MB_SIDEWAYS_STAIRS_*`), tourbillons (`EventScript_Whirlpool`, 7e badge de Kanto pour l'instant).
- **Portes** : celles de HnS font un seul metatile (`DOOR_SIZE_1x1`) ; sur les maps de Johto, leurs images vont aux
  tuiles 434-441 (libres dans les tilesets primaires de Johto), pas 1016-1023 que les tilesets de Johto utilisent.
- **Frontière avec Kanto** (deux postes) : le poste de Rouge Feu de la Route 22 mène toujours à la Route 23 ; le poste
  de Johto (Reception Gate de HnS) est au bout ouest de la Route 22 (le bâtiment du poste de la Route 18, posé à la
  main), on y entre en marchant vers l'ouest. Sorties : est Route 22, sud Route 26, ouest Route 28 (tapis en bas des
  couloirs latéraux : on sort vers le bas, comme dans HnS) ; le couloir nord est remplacé par un mur continu
  (`BLOCK_PATCHES` dans `johto_decisions.py`). Sur la Route 22, le chemin du bas est en sable, comme autour du poste
  de la Route 18, et la corniche au-dessus finit par son embout.
- **Carte du monde** : `tools/worldmap/worldmap.py --hns ../pokehns` dessine Johto, 3 cases plus bas que l'image de
  HnS (`JOHTO_DOWN`) pour que Mont Argenté, le poste, la Route 22 et Jadielle soient sur une ligne ; flags de lieux
  visités `FLAG_WORLD_MAP_JOHTO(mapsec)`. Position du joueur : le poste a sa case, Route 26 Nord + Route 26 et Mont
  Argenté + Route 28 comptent comme une seule bande (`JoinJohtoSectionMaps`, src/region_map.c).
