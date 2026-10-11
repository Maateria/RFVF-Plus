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
- **`Behaviors` :** les comportements des tuiles (eau, herbe, porte...). `DEGRADED` ou `no counterpart` signale un
  effet perdu, par exemple le sable profond devient du sable normal.
- **Une ligne `MAP_...` par map,** suivie de :
  - `CONN` : les liaisons ;
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
  - `can be reached from LilycoveCity` : la zone est accessible depuis Nénucrique.
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

## Ce que l'outil refuse pour l'instant (étape 3)

Ces refus sont propres : rien n'est écrit et la raison commence par `needs step 3`.

- **Tilesets trop gros.** Un tileset secondaire FRLG contient au plus 384 metatiles. Ceux-ci doivent d'abord être
  découpés en tilesets jumeaux :
  - Lavandia, Vergazon et les Routes 110, 111, 117 et 118 ;
  - Poivressel et les Routes 108 et 109 ;
  - Algatia et les Routes 124 à 129 ;
  - Vermilava et la Route 112 ;
  - les grottes, pour la Route 130.
- **L'Arène de Vermilava :** les geysers de son sous-sol.
- **Les fonds marins :** ils attendent la Plongée.
- **Le tileset des maisons (`HoennGenericBuilding`).** Il est partagé et se remplit à chaque import : le rapport
  affiche `N/384`. Toutes les maisons des zones acceptées demandent environ 410 metatiles, donc les dernières zones
  importées qui l'agrandissent seront refusées jusqu'à l'étape 3. Dans l'ordre testé, seule Atalanopolis l'a été.

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
`HoennGenericBuilding`), il refuse. Restaurez ce tileset avec git, ou mettez vos metatiles dans votre propre tileset.

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
