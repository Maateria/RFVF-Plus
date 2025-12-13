# Guide d'importation des maps Emerald vers FireRed

Ce guide explique comment utiliser les scripts d'importation automatique pour importer des maps de Pokémon Emerald vers votre rom hack Pokémon FireRed.

## 📋 Prérequis

1. Un clone du repo **pokeemerald** (https://github.com/pret/pokeemerald)
2. Votre repo **pokefirered** (celui-ci)
3. Python 3.6+

## 🚀 Utilisation rapide

### Étape 1 : Nettoyer une map existante (optionnel)

Si vous avez déjà essayé d'importer une map et que vous voulez repartir de zéro :

```bash
# Simulation (aucune modification)
python3 clean_lilycove.py --dry-run

# Nettoyage réel
python3 clean_lilycove.py
```

### Étape 2 : Importer une map d'Emerald

```bash
# Simulation (recommandé pour la première fois)
python3 import_emerald_map.py \
  --emerald /path/to/pokeemerald \
  --map LilycoveCity \
  --dry-run

# Import réel
python3 import_emerald_map.py \
  --emerald /path/to/pokeemerald \
  --map LilycoveCity
```

### Étape 3 : Compiler

```bash
wsl make
```

### Étape 4 : Tester

Testez la map dans votre émulateur pour vérifier que :
- La map s'affiche correctement
- Les animations (eau, cascades, fleurs) fonctionnent
- Les collisions sont correctes

## 📖 Documentation détaillée

### Options du script d'importation

```
--emerald CHEMIN    : Chemin vers le repo pokeemerald (obligatoire)
--map NOM          : Nom de la map à importer (obligatoire)
--group GROUPE     : Groupe de map (défaut: gMapGroup_RSE)
--firered CHEMIN   : Chemin vers ce repo (défaut: répertoire courant)
--dry-run          : Simulation sans modification
```

### Ce que fait le script d'importation

1. **Copie la map** : `data/maps/MapName/`
   - `map.json`, `scripts.pory`, `text.pory`, etc.

2. **Copie le layout** : `data/layouts/MapName/`
   - `map.bin`, `border.bin`
   - Crée `map.bin.emerald` comme backup de l'original

3. **Met à jour les configurations** :
   - Ajoute la map dans `data/maps/map_groups.json`
   - Ajoute le layout dans `data/layouts/layouts.json`
   - Adapte les noms de tilesets (Emerald → FireRed)

4. **Copie les tilesets** :
   - **Primary tileset** : `data/tilesets/primary/hoenn_general/`
     - Tiles, metatiles, attributes, palettes
     - **Animations** : `anim/water/`, `anim/waterfall/`, etc.
   - **Secondary tileset** : `data/tilesets/secondary/nom_map/`
     - Tiles, metatiles, attributes, palettes

5. **Vérifie les fichiers** :
   - `src/data/tilesets/graphics.h`
   - `src/data/tilesets/metatiles.h`
   - `src/data/tilesets/headers.h`
   - `src/tileset_anims.c`

### Adaptation automatique des tilesets

Le script adapte automatiquement les noms de tilesets d'Emerald vers FireRed :

| Emerald                    | FireRed                      |
|----------------------------|------------------------------|
| `gTileset_General`         | `gTileset_hoenn_general`     |
| `gTileset_LilycoveCity`    | `gTileset_lilycove`          |
| `gTileset_MossdeepCity`    | `gTileset_mossdeep`          |

## 🎯 Exemple complet : Importer Lilycove City

```bash
# 1. Nettoyer les anciennes tentatives (si nécessaire)
python3 clean_lilycove.py

# 2. Importer depuis Emerald
python3 import_emerald_map.py \
  --emerald ../pokeemerald \
  --map LilycoveCity \
  --group gMapGroup_RSE

# 3. Compiler
wsl make

# 4. Tester dans l'émulateur
```

## 🐛 Dépannage

### Problème : Les animations ne fonctionnent pas

**Symptômes** : La map s'affiche correctement, mais l'eau/cascades ne s'animent pas.

**Solutions** :
1. Vérifier que `InitTilesetAnim_HoennGeneral` est bien présent dans `src/tileset_anims.c`
2. Vérifier que les fichiers `.4bpp` existent dans `data/tilesets/primary/hoenn_general/anim/`
3. Compiler avec `wsl make clean && wsl make`

### Problème : La map est cassée/corrompue

**Symptômes** : La map s'affiche avec des tiles incorrects ou des glitchs visuels.

**Solutions** :
1. Vérifier que `map.bin.emerald` a bien été créé dans `data/layouts/MapName/`
2. Utiliser `map.bin.emerald` au lieu de `map.bin` :
   ```bash
   cd data/layouts/LilycoveCity
   cp map.bin.emerald map.bin
   ```
3. Vérifier que les `metatile_attributes.bin` sont corrects
4. Recompiler

### Problème : Erreurs de compilation

**Symptômes** : `make` échoue avec des erreurs sur les tilesets.

**Solutions** :
1. Vérifier que les entrées sont présentes dans :
   - `src/data/tilesets/graphics.h`
   - `src/data/tilesets/metatiles.h`
   - `src/data/tilesets/headers.h`

2. Exemple d'entrées manquantes à ajouter dans `graphics.h` :
   ```c
   const u32 gTilesetTiles_hoenn_general[] = INCBIN_U32("data/tilesets/primary/hoenn_general/tiles.4bpp.lz");
   const u16 gTilesetPalettes_hoenn_general[][16] = {
       INCBIN_U16("data/tilesets/primary/hoenn_general/palettes/00.gbapal"),
       // ... 01 à 12
   };
   ```

3. Exemple d'entrées manquantes à ajouter dans `metatiles.h` :
   ```c
   const u16 gMetatiles_hoenn_general[] = INCBIN_U16("data/tilesets/primary/hoenn_general/metatiles.bin");
   const u32 gMetatileAttributes_hoenn_general[] = INCBIN_U32("data/tilesets/primary/hoenn_general/metatile_attributes.bin");
   ```

4. Exemple d'entrée manquante à ajouter dans `headers.h` :
   ```c
   const struct Tileset gTileset_hoenn_general = {
       .isCompressed = TRUE,
       .isSecondary = FALSE,
       .tiles = gTilesetTiles_hoenn_general,
       .palettes = gTilesetPalettes_hoenn_general,
       .metatiles = gMetatiles_hoenn_general,
       .metatileAttributes = gMetatileAttributes_hoenn_general,
       .callback = InitTilesetAnim_HoennGeneral,
   };
   ```

### Problème : Animations présentes mais map cassée

**Symptômes** : Les animations d'eau fonctionnent, mais la map est glitchée.

**Cause** : Conflit entre les indices de metatiles d'Emerald et FireRed.

**Solution** :
1. Utiliser `map.bin.emerald` :
   ```bash
   cd data/layouts/MapName
   cp map.bin.emerald map.bin
   ```

2. S'assurer que les `metatile_attributes.bin` proviennent bien d'Emerald et n'ont pas été convertis

3. Utiliser le tileset primary complet d'Emerald sans modification

## 📝 Structure des fichiers après importation

```
pokefirered/
├── data/
│   ├── maps/
│   │   ├── map_groups.json          (mis à jour)
│   │   └── LilycoveCity/            (nouveau)
│   │       ├── map.json
│   │       ├── scripts.pory
│   │       └── ...
│   ├── layouts/
│   │   ├── layouts.json             (mis à jour)
│   │   └── LilycoveCity/            (nouveau)
│   │       ├── map.bin              (actif)
│   │       ├── map.bin.emerald      (backup original)
│   │       ├── map.bin.frlg.backup  (ancien si existait)
│   │       └── border.bin
│   └── tilesets/
│       ├── primary/
│       │   └── hoenn_general/       (nouveau si n'existait pas)
│       │       ├── tiles.png
│       │       ├── metatiles.bin
│       │       ├── metatile_attributes.bin
│       │       ├── palettes/
│       │       └── anim/            (crucial pour animations)
│       │           ├── water/       (8 frames: 0.png à 7.png)
│       │           ├── waterfall/   (4 frames)
│       │           ├── land_water_edge/ (4 frames)
│       │           └── sand_water_edge/ (7 frames)
│       └── secondary/
│           └── lilycove/            (nouveau)
│               ├── tiles.png
│               ├── metatiles.bin
│               ├── metatile_attributes.bin
│               └── palettes/
└── src/
    ├── tileset_anims.c              (doit contenir InitTilesetAnim_HoennGeneral)
    └── data/
        └── tilesets/
            ├── graphics.h           (vérifié)
            ├── metatiles.h          (vérifié)
            └── headers.h            (vérifié)
```

## 🔍 Vérifications manuelles après importation

Après avoir exécuté le script, vérifiez :

### 1. Fichiers copiés
```bash
# Vérifier que la map existe
ls data/maps/LilycoveCity/

# Vérifier que le layout existe
ls data/layouts/LilycoveCity/

# Vérifier les tilesets
ls data/tilesets/primary/hoenn_general/
ls data/tilesets/secondary/lilycove/

# Vérifier les animations
ls data/tilesets/primary/hoenn_general/anim/water/
```

### 2. Configurations JSON

```bash
# Vérifier map_groups.json
grep -A 5 "gMapGroup_RSE" data/maps/map_groups.json

# Vérifier layouts.json
grep -A 10 "LilycoveCity" data/layouts/layouts.json
```

### 3. Code d'animation

```bash
# Vérifier tileset_anims.c
grep "InitTilesetAnim_HoennGeneral" src/tileset_anims.c
grep "QueueAnimTiles_HoennGeneral_Water" src/tileset_anims.c
```

## 🎨 Personnalisation

### Importer plusieurs maps

```bash
# Script pour importer plusieurs maps
for map in LilycoveCity MossdeepCity SootopolisCity; do
  python3 import_emerald_map.py \
    --emerald ../pokeemerald \
    --map $map \
    --group gMapGroup_RSE
done
```

### Créer un groupe personnalisé

```bash
python3 import_emerald_map.py \
  --emerald ../pokeemerald \
  --map LilycoveCity \
  --group gMapGroup_HoennCities
```

Le groupe sera créé automatiquement s'il n'existe pas.

## ⚠️ Notes importantes

1. **Backup** : Le script crée des backups automatiquement :
   - `map.bin.emerald` : Original d'Emerald
   - `map.bin.frlg.backup` : Ancien fichier FireRed si existait
   - `tileset.backup/` : Backup des tilesets remplacés

2. **Dry run** : Utilisez toujours `--dry-run` la première fois pour voir ce qui sera fait

3. **Primary tileset** : Le tileset `hoenn_general` est partagé entre toutes les maps Hoenn. Il ne doit être importé qu'une seule fois.

4. **Animations** : Les animations sont dans le primary tileset (`hoenn_general`), pas dans le secondary tileset de la map.

5. **Format des metatile_attributes** : Le script utilise directement le format d'Emerald (4 octets par metatile) au lieu du format FireRed (2 octets). C'est voulu pour l'Option 1.

## 🚀 Workflow recommandé

1. **Première map Hoenn** :
   ```bash
   python3 import_emerald_map.py --emerald ../pokeemerald --map LilycoveCity --dry-run
   python3 import_emerald_map.py --emerald ../pokeemerald --map LilycoveCity
   wsl make
   # Tester
   ```

2. **Maps suivantes** (le primary tileset existe déjà) :
   ```bash
   python3 import_emerald_map.py --emerald ../pokeemerald --map MossdeepCity
   # Le script détectera que hoenn_general existe et demandera si on veut le remplacer
   # Répondre 'n' pour garder l'existant
   wsl make
   # Tester
   ```

3. **En cas de problème** :
   ```bash
   # Nettoyer
   python3 clean_lilycove.py

   # Réimporter
   python3 import_emerald_map.py --emerald ../pokeemerald --map LilycoveCity

   # Compiler proprement
   wsl make clean
   wsl make
   ```

## 📚 Ressources

- [Guide PORTINGMAPS.md original](https://github.com/ultima-soul/pokefireredemerald/blob/master/PORTINGMAPS.md) (sens inverse)
- [Pret pokeemerald](https://github.com/pret/pokeemerald)
- [Pret pokefirered](https://github.com/pret/pokefirered)
- [Porymap documentation](https://github.com/huderlem/porymap)

## 🤝 Contribution

Si vous trouvez des bugs ou avez des suggestions d'amélioration pour ces scripts, n'hésitez pas à créer une issue ou un PR.

## 📄 Licence

Ces scripts sont fournis tels quels, sans garantie. Utilisez-les à vos propres risques.
