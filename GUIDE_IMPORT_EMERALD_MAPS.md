# Guide complet : Importer une map d'Emerald vers FireRed

Ce guide documente le processus complet pour importer une map de pokeemerald vers pokefirered, basé sur l'expérience de l'import de Lilycove City.

---

## 📋 Table des matières

1. [Prérequis et limitations](#prérequis-et-limitations)
2. [Étape 1 : Préparation du tileset secondary](#étape-1--préparation-du-tileset-secondary)
3. [Étape 2 : Import de la map](#étape-2--import-de-la-map)
4. [Étape 3 : Configuration des animations](#étape-3--configuration-des-animations)
5. [Étape 4 : Reconstruction des metatiles](#étape-4--reconstruction-des-metatiles)
6. [Problèmes courants et solutions](#problèmes-courants-et-solutions)
7. [Outils et scripts utiles](#outils-et-scripts-utiles)

---

## Prérequis et limitations

### Limites de FireRed
- **Primary tileset** : 640 metatiles maximum (vs 512 dans Emerald)
- **Secondary tileset** : 384 metatiles maximum (vs 512 dans Emerald)
- **Total tiles par secondary** : 384 tiles (8x8) maximum
- **Palettes** : 16 couleurs par palette, similaire à Emerald

### Différences majeures Emerald ↔ FireRed

| Aspect | Emerald | FireRed |
|--------|---------|---------|
| Adressage tiles dans metatiles | Absolu (0-1071) | Relatif par tileset |
| Attributs metatiles | 1 byte | 2 bytes |
| Nombre de metatiles secondary | 512 | 384 |
| Primary tileset size | 512 metatiles | 640 metatiles |

### Outils nécessaires
- Porymap (éditeur de maps)
- Aseprite ou éditeur d'images avec support grille 8x8
- Python 3 avec PIL (Pillow) et numpy
- Les scripts créés dans ce projet

---

## Étape 1 : Préparation du tileset secondary

### 1.1 Créer le répertoire du tileset

```bash
mkdir -p data/tilesets/secondary/nom_map
```

### 1.2 Copier les fichiers de base depuis Emerald

```bash
# Depuis pokeemerald
cp pokeemerald/data/tilesets/secondary/nom_map/tiles.png data/tilesets/secondary/nom_map/
cp pokeemerald/data/tilesets/secondary/nom_map/palettes.pal data/tilesets/secondary/nom_map/
cp pokeemerald/data/tilesets/secondary/nom_map/metatiles.bin data/tilesets/secondary/nom_map/
cp pokeemerald/data/tilesets/secondary/nom_map/metatile_attributes.bin data/tilesets/secondary/nom_map/
```

### 1.3 Réduire le tileset à 384 tiles

⚠️ **CRITIQUE** : Le tiles.png d'Emerald contient souvent plus de 384 tiles. Il faut le réduire.

#### Option A : Crop manuel (rapide mais peut perdre des tiles importants)

```bash
# Vérifier la taille actuelle
identify data/tilesets/secondary/nom_map/tiles.png
# Exemple: 128x216 = 432 tiles

# Cropper à 384 tiles (128x192)
convert data/tilesets/secondary/nom_map/tiles.png -crop 128x192+0+0 data/tilesets/secondary/nom_map/tiles.png
```

#### Option B : Sélection manuelle des tiles nécessaires (recommandé)

1. **Ouvrir le tiles.png d'Emerald dans Aseprite**
2. **Configurer la grille 8x8** :
   - `View` → `Grid` → `Grid Settings` (Ctrl+Shift+G)
   - Grid Width: `8`, Grid Height: `8`
   - Activer `Snap to Grid` (Shift+S)
3. **Créer un nouveau fichier 128x192** (384 tiles)
4. **Copier les tiles les plus utilisés** depuis l'original
5. **Sauvegarder** comme tiles.png

### 1.4 Convertir les attributs de metatiles

FireRed utilise 2 bytes par metatile (vs 1 byte dans Emerald).

**Script de conversion** : `convert_metatile_attributes.py`

```bash
python3 convert_metatile_attributes.py \
    pokeemerald/data/tilesets/secondary/nom_map/metatile_attributes.bin \
    data/tilesets/secondary/nom_map/metatile_attributes.bin
```

### 1.5 Ajouter les déclarations dans les headers

#### `src/data/tilesets/graphics.h`

Ajouter à la fin du fichier (avant le `#endif`) :

```c
// nom_map tiles
extern const u32 gTilesetTiles_nom_map[];

// nom_map palettes
extern const u16 gTilesetPalettes_nom_map[][16];
```

#### `src/data/tilesets/metatiles.h`

Ajouter à la fin du fichier (avant le `#endif`) :

```c
// nom_map metatiles
extern const u16 gMetatiles_nom_map[];

// nom_map metatile attributes
extern const u32 gMetatileAttributes_nom_map[];
```

#### `src/data/tilesets/headers.h`

Ajouter à la fin du fichier (avant le `#endif`) :

```c
const struct Tileset gTileset_nom_map =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_nom_map,
    .palettes = gTilesetPalettes_nom_map,
    .metatiles = gMetatiles_nom_map,
    .metatileAttributes = gMetatileAttributes_nom_map,
    .callback = NULL,
};
```

---

## Étape 2 : Import de la map

### 2.1 Copier les fichiers de map depuis Emerald

```bash
# Copier le dossier complet de la map
cp -r pokeemerald/data/maps/NomMap data/maps/
cp -r pokeemerald/data/layouts/NomMap data/layouts/
```

### 2.2 Créer les scripts minimaux

Si le fichier `data/maps/NomMap/scripts.pory` n'existe pas ou est incomplet, créer :

```pory
// Map scripts definition
raw `
NomMap_MapScripts::
	.byte 0
`

// Script de transition (optionnel)
script NomMap_OnTransition {
    end
}
```

### 2.3 Ajouter la map dans layouts.json

Éditer `data/layouts/layouts.json` et ajouter :

```json
{
  "id": "LAYOUT_NOM_MAP",
  "name": "NomMap_Layout",
  "width": 80,
  "height": 40,
  "border_width": 2,
  "border_height": 2,
  "primary_tileset": "gTileset_hoenn_general",
  "secondary_tileset": "gTileset_nom_map",
  "border_filepath": "data/layouts/NomMap/border.bin",
  "blockdata_filepath": "data/layouts/NomMap/map.bin"
}
```

⚠️ Adapter `width`, `height`, et les noms de tilesets selon ta map.

### 2.4 Backup du map.bin original

```bash
cp data/layouts/NomMap/map.bin data/layouts/NomMap/map.bin.emerald
```

---

## Étape 3 : Configuration des animations

### 3.1 Vérifier le primary tileset utilisé

Les animations sont gérées par le **primary tileset**. Pour Hoenn, c'est `gTileset_hoenn_general`.

### 3.2 Animations disponibles

Dans `src/tileset_anims.c`, vérifier que les animations suivantes sont actives :

```c
static void TilesetAnim_HoennGeneral(u16 timer)
{
    if (timer % 16 == 1)
        QueueAnimTiles_HoennGeneral_Water(timer / 16);
    // Les animations suivantes peuvent être désactivées si les tiles
    // ne correspondent pas (voir section Problèmes courants)
    // if (timer % 16 == 2)
    //     QueueAnimTiles_HoennGeneral_SandWaterEdge(timer / 16);
    if (timer % 16 == 3)
        QueueAnimTiles_HoennGeneral_Waterfall(timer / 16);
    // if (timer % 16 == 4)
    //     QueueAnimTiles_HoennGeneral_LandWaterEdge(timer / 16);
}
```

### 3.3 Tile IDs des animations

Les animations s'appliquent aux tiles suivants du **primary tileset** :

- **Eau** : Tiles 432-462 (30 tiles)
- **Bord eau/terre** : Tiles 416-440 (24 tiles) - ⚠️ Peut animer les mauvais tiles
- **Bord eau/sable** : Tiles 464-474 (10 tiles) - ⚠️ Peut animer les mauvais tiles
- **Cascade** : Tiles 496-502 (6 tiles)

Si des arbres ou autres éléments s'animent incorrectement, désactiver les animations problématiques (voir code ci-dessus).

---

## Étape 4 : Reconstruction des metatiles

### 4.1 Le problème principal

Emerald utilise un **adressage absolu** des tiles dans les metatiles (0-1071 pour primary+secondary combinés), tandis que FireRed utilise un **adressage relatif** (0-383 pour le secondary seulement).

Résultat : **Les metatiles copiés directement d'Emerald ne fonctionnent pas**.

### 4.2 Solution : Reconstruction manuelle dans Porymap

C'est la **seule méthode fiable** actuellement :

1. **Ouvrir la map dans Porymap**
2. **Panneau des metatiles** : Voir tous les metatiles du secondary
3. **Reconstruire chaque metatile** un par un :
   - Sélectionner le metatile dans la liste
   - Dans la zone d'édition (4 tiles en 2x2), placer les bons tiles
   - Choisir les bonnes palettes (0-15)
   - Configurer les flips H/V si nécessaire
   - Sauvegarder (Ctrl+S)

### 4.3 Optimisation avec Aseprite

Pour identifier rapidement les tiles nécessaires :

1. **Ouvrir côte à côte** :
   - Le metatiles exporté depuis Emerald (Tools → Export Secondary Metatiles Image)
   - Le tiles.png de FireRed
2. **Utiliser la grille 8x8** pour sélectionner les tiles précis
3. **Copier les tiles manquants** dans les emplacements vides du tiles.png FireRed
4. **Recompiler et rouvrir Porymap** pour voir les nouveaux tiles

### 4.4 Références visuelles

Garder une capture d'écran ou une référence de la map dans Emerald pour vérifier que les metatiles reconstruits sont corrects.

---

## Problèmes courants et solutions

### Problème 1 : `make clean` échoue

**Erreur** :
```
make[1]: *** No rule to make target 'clean'. Stop.
```

**Cause** : `tools/wav2agb/Makefile` n'a pas de règle `clean`.

**Solution** : Ajouter dans `tools/wav2agb/Makefile` :
```makefile
.PHONY: all clean

all:

clean:
	$(RM) wav2agb wav2agb.exe
```

---

### Problème 2 : `src/tilesets.s` introuvable

**Erreur** :
```
Error: can't open src/tilesets.s for reading: No such file or directory
```

**Cause** : Le Makefile essaie d'assembler `.s` au lieu de compiler `.c`.

**Solution** : Le fichier `Makefile` doit contenir une règle explicite pour `tilesets.o` (lignes 292-298) :

```makefile
# Explicit rule for tilesets.o to force compilation from .c
$(C_BUILDDIR)/tilesets.o: tilesets_c_dep = $(shell $(SCANINC) -I include -I tools/agbcc/include $(C_SUBDIR)/tilesets.c)
$(C_BUILDDIR)/tilesets.o: $(C_SUBDIR)/tilesets.c $$(tilesets_c_dep)
	@$(CPP) $(CPPFLAGS) $< -o $(C_BUILDDIR)/tilesets.i
	@$(PREPROC) $(C_BUILDDIR)/tilesets.i charmap.txt | $(CC1) $(CFLAGS) -o $(C_BUILDDIR)/tilesets.s
	@echo -e ".text\n\t.align\t2, 0 @ Don't pad with nop\n" >> $(C_BUILDDIR)/tilesets.s
	$(AS) $(ASFLAGS) -o $@ $(C_BUILDDIR)/tilesets.s
```

Et `src/tilesets.c` doit contenir :
```c
#include "global.h"
#include "tilesets.h"
#include "tileset_anims.h"

#include "data/tilesets/graphics.h"
#include "data/tilesets/metatiles.h"
#include "data/tilesets/headers.h"

// Force compilation
void __tilesets_dummy(void) {}
```

---

### Problème 3 : MapScripts manquants

**Erreur** :
```
undefined reference to 'NomMap_MapScripts'
```

**Cause** : Le fichier `scripts.pory` ne définit pas `MapScripts`.

**Solution** : Ajouter dans `data/maps/NomMap/scripts.pory` :
```pory
raw `
NomMap_MapScripts::
	.byte 0
`
```

---

### Problème 4 : Animations s'appliquent aux mauvais tiles

**Symptôme** : Les arbres, fleurs ou autres éléments s'animent au lieu de l'eau.

**Cause** : Les tiles du primary ne sont pas aux mêmes positions qu'Emerald.

**Solution rapide** : Désactiver les animations problématiques dans `src/tileset_anims.c` :

```c
static void TilesetAnim_HoennGeneral(u16 timer)
{
    if (timer % 16 == 1)
        QueueAnimTiles_HoennGeneral_Water(timer / 16);
    // Désactivé : tiles non continus dans FireRed
    // if (timer % 16 == 2)
    //     QueueAnimTiles_HoennGeneral_SandWaterEdge(timer / 16);
    if (timer % 16 == 3)
        QueueAnimTiles_HoennGeneral_Waterfall(timer / 16);
    // Désactivé : anime les arbres au lieu des bords eau
    // if (timer % 16 == 4)
    //     QueueAnimTiles_HoennGeneral_LandWaterEdge(timer / 16);
}
```

**Solution complète** : Réorganiser le primary tileset pour que les tiles d'eau soient aux bonnes positions (voir script `find_tile_mappings.py`).

---

### Problème 5 : Metatiles s'affichent différemment in-game vs Porymap

**Symptôme** : Tu places le metatile 0x024 dans Porymap, mais 0x2B3 s'affiche in-game.

**Causes possibles** :
1. **Primary tileset trop grand** : Si le primary a plus de 640 metatiles, il y a un décalage
2. **Cache de compilation** : Les fichiers binaires ne sont pas à jour
3. **Corruption du map.bin** : Le fichier est corrompu

**Solution** :

1. **Vérifier la taille du primary** :
```bash
stat -c '%s' data/tilesets/primary/hoenn_general/metatiles.bin
# Doit être 5120 bytes (640 metatiles * 8 bytes)
```

2. **Si trop grand, cropper** :
```bash
head -c 5120 data/tilesets/primary/hoenn_general/metatiles.bin > temp.bin
mv temp.bin data/tilesets/primary/hoenn_general/metatiles.bin

head -c 1280 data/tilesets/primary/hoenn_general/metatile_attributes.bin > temp.bin
mv temp.bin data/tilesets/primary/hoenn_general/metatile_attributes.bin
```

3. **Recompiler proprement** :
```bash
make clean && make
```

4. **Rouvrir Porymap** et vérifier

---

### Problème 6 : Porymap affiche des metatiles magenta

**Symptôme** : Tous les metatiles du secondary apparaissent en magenta dans Porymap.

**Cause** : Mauvaise configuration dans `porymap.project.cfg` ou `include/fieldmap.h`.

**Solution** :

1. Vérifier `include/fieldmap.h` :
```c
#define NUM_METATILES_IN_PRIMARY 640  // Doit être 640
#define NUM_METATILES_TOTAL 1024      // Doit être 1024
```

2. Vérifier `porymap.project.cfg` :
```ini
block_metatile_id_mask=0x3FF  # Doit être 0x3FF (pas 0x7FF)
```

3. **Fermer et rouvrir Porymap**

---

## Outils et scripts utiles

### Script : `find_tile_mappings.py`

Trouve les correspondances entre tiles Emerald et FireRed.

**Usage** :
```bash
python3 find_tile_mappings.py \
    pokeemerald/data/tilesets/primary/general/tiles.png \
    data/tilesets/primary/hoenn_general/tiles.png \
    432 462
```

**Utilité** : Diagnostiquer les problèmes d'animations.

---

### Script : `smart_remap_metatiles.py`

Tente de remapper automatiquement les metatiles (résultats variables).

**Usage** :
```bash
python3 smart_remap_metatiles.py \
    pokeemerald/data/tilesets/secondary/nom_map \
    data/tilesets/secondary/nom_map
```

⚠️ **Note** : Ce script ne fonctionne pas parfaitement à cause des différences d'adressage. La reconstruction manuelle reste nécessaire.

---

### Script : `convert_metatile_attributes.py`

Convertit les attributs de metatiles d'Emerald (1 byte) vers FireRed (2 bytes).

**Usage** :
```bash
python3 convert_metatile_attributes.py \
    pokeemerald/data/tilesets/secondary/nom_map/metatile_attributes.bin \
    data/tilesets/secondary/nom_map/metatile_attributes.bin
```

**Important** : Ce script doit être créé si nécessaire.

---

## Checklist complète pour import d'une nouvelle map

### Phase 1 : Préparation (15-30 min)
- [ ] Créer le répertoire du secondary tileset
- [ ] Copier tiles.png, palettes.pal, metatiles.bin, metatile_attributes.bin
- [ ] Réduire tiles.png à 384 tiles maximum
- [ ] Convertir metatile_attributes.bin (Emerald 1 byte → FireRed 2 bytes)
- [ ] Ajouter les déclarations dans graphics.h, metatiles.h, headers.h

### Phase 2 : Import de la map (10-15 min)
- [ ] Copier data/maps/NomMap et data/layouts/NomMap
- [ ] Créer scripts.pory avec MapScripts minimal
- [ ] Ajouter l'entrée dans layouts.json
- [ ] Backup du map.bin original

### Phase 3 : Compilation (5 min)
- [ ] Compiler : `make clean && make`
- [ ] Vérifier les erreurs de compilation
- [ ] Corriger les déclarations manquantes si nécessaire

### Phase 4 : Reconstruction des metatiles (2-8 heures selon la complexité)
- [ ] Ouvrir Porymap
- [ ] Exporter les metatiles depuis Emerald (Tools → Export Secondary Metatiles Image)
- [ ] Reconstruire chaque metatile dans Porymap
- [ ] Ajouter les tiles manquants dans tiles.png si nécessaire
- [ ] Tester régulièrement in-game

### Phase 5 : Tests finaux (15-30 min)
- [ ] Vérifier les animations (eau, cascade)
- [ ] Vérifier les collisions
- [ ] Vérifier les warps (si applicable)
- [ ] Commit des changements

---

## Estimation de temps par map

| Complexité | Tiles nécessaires | Metatiles à reconstruire | Temps estimé |
|------------|-------------------|--------------------------|--------------|
| Simple (Route) | < 200 tiles | < 300 metatiles | 3-4 heures |
| Moyenne (Petite ville) | 200-350 tiles | 300-600 metatiles | 6-8 heures |
| Complexe (Grande ville) | > 350 tiles | > 600 metatiles | 10-15 heures |

---

## Notes importantes

1. **Sauvegarde régulière** : Commit après chaque étape majeure
2. **Test incrémental** : Tester in-game régulièrement, pas seulement à la fin
3. **Documentation des problèmes** : Noter tous les problèmes spécifiques rencontrés
4. **Réutilisation** : Les tiles et metatiles créés pour une ville Hoenn peuvent être réutilisés pour d'autres villes similaires
5. **Primary tileset** : Ne pas dépasser 640 metatiles, sinon Porymap et le jeu se désynchronisent

---

## Ressources

- [Repo pokefirered officiel](https://github.com/pret/pokefirered)
- [Repo pokeemerald officiel](https://github.com/pret/pokeemerald)
- [Porymap](https://github.com/huderlem/porymap)
- [Documentation Porymap](https://huderlem.github.io/porymap/)

---

## Crédits

Guide créé suite à l'import de Lilycove City de pokeemerald vers pokefirered.
Basé sur des heures de débogage et d'expérimentation. 🎉
