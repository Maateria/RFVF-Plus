# Importer Hoenn : `import_map.py`

`import_map.py` importe une ville ou une route d'Émeraude depuis pokeemerald, avec tous ses intérieurs (maisons,
Centre Pokémon, Boutique, Arène...), en une seule commande. Il importe tout sauf les scripts :

- **Ce qui est importé :** les maps et leurs liaisons, les portes, les objets au sol et cachés (ramassables), les
  Pokémon sauvages, la météo, la musique d'Émeraude et le point de retour du Centre Pokémon.
- **Ce qui reste muet :** les PNJ, les panneaux et les dresseurs (pas de combat) sont placés mais attendent leurs
  scripts. Ils sont listés dans le `scripts.inc` de chaque map.

## Avant de commencer

- Clonez pret/pokeemerald à côté du dépôt (`..\pokeemerald`), ou donnez son chemin avec `--emerald CHEMIN`.
- Installez [uv](https://docs.astral.sh/uv/). Il installe tout seul Python et Pillow.
- Commitez votre travail : l'outil refuse d'écrire un fichier qui a des modifications non commitées.
- Fermez Porymap pendant l'import. Sinon, à sa sauvegarde suivante, Porymap réécrit `map_groups.json` et
  `layouts.json` sans les nouvelles maps. Rouvrez-le après l'import.

## Essai, puis import (PowerShell, à la racine du dépôt)

```powershell
uv run tools/hoenn_import/import_map.py Route119 --dry-run   # vérifie tout, n'écrit rien
uv run tools/hoenn_import/import_map.py Route119             # importe
```

- **Noms des zones :** l'outil prend les noms anglais d'Émeraude : `Route101` à `Route134`, `LittlerootTown`
  (Bourg-en-Vol), `OldaleTown` (Rosyères), `PetalburgCity` (Clémenti-Ville), `RustboroCity` (Mérouville),
  `DewfordTown` (Myokara), `SlateportCity` (Poivressel), `MauvilleCity` (Lavandia), `VerdanturfTown` (Vergazon),
  `FallarborTown` (Autéquia), `LavaridgeTown` (Vermilava), `FortreeCity` (Cimetronelle), `LilycoveCity`
  (Nénucrique), `MossdeepCity` (Algatia), `SootopolisCity` (Atalanopolis), `PacifidlogTown` (Pacifiville),
  `EverGrandeCity` (Éternara).
- **Nom inconnu :** l'outil affiche la liste des noms valides.
- **Images :** `--render DOSSIER` enregistre aussi une image PNG de chaque map convertie.

## Lire le rapport

- **`Tilesets` :** les tilesets utilisés. `351/384 metatiles` est la place occupée dans un tileset secondaire (384 au
  maximum). Ensuite : `new` (nouveau), `+N metatiles` (agrandi) ou `unchanged` (inchangé).
  - `natural ids` : un grand tileset d'Émeraude garde ses numéros, et seulement les metatiles que ses maps utilisent.
    S'il ne tient pas dans un seul tileset, il est coupé en jumeaux (`gTileset_HoennMauville2`...). Il est écrit en
    entier la première fois et ne change plus.
  - `PRUNED` : un tileset compacté avant l'étape 3 (`HoennGenericBuilding`, `HoennFacility`,
    `HoennBattleFrontier`). Il ne fait que grandir.
- **`Behaviors` :** les comportements des tuiles (eau, herbe, porte...). `DEGRADED` ou `no counterpart` signale un
  effet perdu, par exemple le sable profond devient du sable normal.
- **Une ligne `MAP_...` par map,** suivie de :
  - `CONN` : les liaisons. `dive` et `emerge` (`needs Dive in game`) : on y passe en plongeant ;
  - `NPC` : les objets (PNJ, dresseurs, objets au sol) ;
  - `SIGN`, `HIDD` et `WEAT` : les panneaux, les objets cachés et la météo ;
  - `DROP` : ce qui n'est pas placé, avec la raison ;
  - `WARP` : les portes. `(placeholder)` signifie que la porte ramène sur la même map, en attendant que sa
    destination soit importée.
- **`DIFFERS (not written)` :** une map déjà importée diffère d'Émeraude, en général à cause de vos modifications.
  L'outil n'y touche pas.
- **`Re-linked` :** ce que les maps déjà là gagnent, c'est-à-dire les portes et les liaisons vers les nouvelles maps.
- **Lignes de fin :**
  - `Flags allocated` : les flags des objets ;
  - `Wild encounters added` : les Pokémon sauvages ajoutés ;
  - `Heal location` : le point de retour après un K.O. ;
  - `Render check` : chaque nouvelle map et chaque bande de liaison, comparées pixel par pixel à Émeraude ;
  - `can be reached from LilycoveCity` : la zone est accessible depuis Nénucrique (`with Dive only` : seulement en
    plongeant).
- **`REFUSED, nothing written:` :** l'import est refusé, avec toutes les raisons. Rien n'est écrit.
- **`Files written` :** les fichiers écrits (`A` = ajouté, `M` = modifié), suivis des commandes pour annuler.
- **Code de sortie :**
  - 0 : fait, ou `Nothing to do` si la zone est déjà importée ;
  - 1 : refusé ;
  - 2 : mauvaise commande ;
  - 3 : erreur d'écriture, et tout a été restauré.

## Compiler et vérifier en jeu

1. Lancez `.\fast_build.cmd`, qui produit `pokeleafgreen.gba`.
2. Ouvrez la ROM et allez à Nénucrique, puis vers la zone importée. Les liaisons se font toutes seules dès que la
   map voisine existe. Si le rapport dit `can NOT be reached yet`, importez d'abord une zone entre les deux.
3. Vérifiez :
   - l'aspect de la map comparé à Émeraude, la musique et le nom affiché à l'entrée ;
   - les portes, dans les deux sens ;
   - les objets au sol (une seule fois) et les objets cachés ;
   - les Pokémon sauvages ;
   - le retour au Centre Pokémon après un K.O.
4. Les PNJ muets et les dresseurs qui ne combattent pas sont normaux.
5. Commitez tous les fichiers listés, y compris `include/constants/map_groups.h` et `layouts.h`.

## Tout importer d'un coup

`import_all.py` importe toutes les zones qui manquent, une par une, avec un commit par zone :

```powershell
uv run tools/hoenn_import/import_all.py --dry-run           # ce que chaque zone donnerait, n'écrit rien
uv run tools/hoenn_import/import_all.py                     # importe tout ce qui manque, puis compile
uv run tools/hoenn_import/import_all.py Route118 MauvilleCity   # seulement ces zones, dans cet ordre
```

- **Avant :** fermez Porymap et commitez votre travail, sinon l'outil s'arrête sans rien faire.
- **Ordre :** les zones partent de Nénucrique. Une zone déjà importée est sautée (`déjà là`). L'ordre ne change pas
  les tilesets : importer la Route 118 avant ou après Lavandia donne les mêmes fichiers.
- **Commits :** chaque zone devient un commit `[FEAT] - Import <zone> from Emerald (import_map.py)`, donc
  `git revert <commit>` annule une zone. Rien n'est poussé.
- **Options :** `--no-build` saute la compilation de la fin ; `--emerald CHEMIN` donne pokeemerald.
- **Détail :** le rapport complet de chaque zone est dans `build/import_all/<zone>.txt`.

## Limites

- **Les 57 zones sont acceptées.** Deux cas attendent le travail moteur de l'étape 3, c'est-à-dire la constante
  `MB_LAVARIDGE_GYM_B1F_WARP` dans `include/constants/metatile_behaviors.h`. Sans elle, ils sont refusés proprement,
  rien n'est écrit et la raison le dit :
  - **Vermilava :** les geysers du sous-sol de l'Arène sont la seule sortie ;
  - **les 7 fonds marins** (`Underwater_Route105`, `Underwater_Route124` à `Underwater_Route129`) : plongée,
    remontée et carte de la région.
- **Plongée :** les liaisons `dive` et `emerge` d'Émeraude sont copiées, et le rapport les marque
  `needs Dive in game`. On n'atteint les fonds marins qu'en plongeant. Atalanopolis n'a aucune liaison : on y
  arrive par le passage sous-marin `Underwater_SootopolisCity`, qui viendra avec les donjons (le rapport dit
  `can NOT be reached yet`).
- **Tilesets jumeaux :** un tileset secondaire FRLG contient au plus 384 metatiles et 376 tuiles. Les plus grands
  d'Émeraude sont coupés en deux (`SIBLINGS` dans `hoenn_decisions.py`) :
  - `HoennMauville2` pour les Routes 110 et 111 ;
  - `HoennSlateport2` pour les Routes 108 et 109 ;
  - `HoennGenericBuilding2` pour les maisons d'Algatia, d'Atalanopolis, de Vergazon et des Routes 110 et 124.
- **Pour plus tard :** les scripts, les animations des tilesets secondaires, les portes sans animation (elles
  marchent quand même) et les effets perdus (`DEGRADED`, `no counterpart`). Le rapport les liste.

## Vos modifications dans Porymap sont gardées

L'outil ne réécrit jamais ce qui existe déjà. Les imports suivants gardent donc :

- les blocs peints ;
- les PNJ déplacés ou ajoutés ;
- la musique et les autres réglages de la map ;
- une liaison supprimée ;
- les Pokémon sauvages modifiés ;
- un label ajouté dans `metatile_labels.h` ;
- un tileset modifié.

Une seule exception : si un import doit ajouter des metatiles à un tileset partagé que vous avez modifié (par exemple
`HoennFacility`), il refuse. Restaurez ce tileset avec git, ou mettez vos metatiles dans votre propre tileset.

Après avoir placé ou changé des PNJ sur une map Hoenn, vérifiez leurs sprites (les maps Hoenn utilisent les palettes
d'Émeraude) :

```powershell
uv run --no-project --with pillow python tools/hoenn_import/hoenn_import.py --check-gfx
```

## Annuler un import

- **Pas encore commité :** l'outil affiche à la fin deux commandes, `git restore -- ...` et `git clean -fdq -- ...`.
  Elles ne touchent que les fichiers de cet import : copiez-les telles quelles.
- **À éviter :** `git checkout -- .`, `git restore .` et `git clean -fd` sans chemin. Elles touchent aussi vos autres
  fichiers, `.claude/` compris. Si c'est déjà fait, relancer l'import fonctionne quand même.
- **Déjà commité :** `git revert <commit>` est sûr. `git reset --hard HEAD~1` annule aussi le dernier commit, mais
  efface en plus tout ce qui n'est pas commité.
