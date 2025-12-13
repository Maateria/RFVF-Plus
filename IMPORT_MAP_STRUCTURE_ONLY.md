# Guide d'importation SIMPLIFIÉ - Structure de map uniquement

Ce guide explique comment importer **uniquement la structure** d'une map d'Emerald (layout + tilesets + animations) **sans les events ni scripts**.

## 🎯 Avantages de cette approche

✅ **Simple et rapide** : Pas de problèmes de compatibilité avec les events/scripts
✅ **Testable immédiatement** : Vous pouvez voir la map et les animations fonctionner
✅ **Progressif** : Vous ajoutez les events/scripts plus tard, manuellement

## 🚀 Utilisation

### Étape 1 : Nettoyer (si la map existe déjà)

```bash
python3 clean_lilycove.py
```

### Étape 2 : Importer la structure

```bash
# Dry run (recommandé)
python3 import_emerald_map_simple.py \
  --emerald /path/to/pokeemerald \
  --map LilycoveCity \
  --dry-run

# Import réel
python3 import_emerald_map_simple.py \
  --emerald /path/to/pokeemerald \
  --map LilycoveCity
```

### Étape 3 : Compiler

```bash
wsl make leafgreen
```

### Étape 4 : Tester

Lancez votre ROM et vérifiez :
- ✅ La map s'affiche correctement
- ✅ Les animations d'eau/cascades fonctionnent
- ✅ Pas de glitchs graphiques

## 📦 Ce qui est importé

Le script importe **uniquement** :

1. **Structure de la map** : Crée `data/maps/MapName/` avec :
   - `map.json` minimal (sans events)
   - `scripts.pory` vide
   - `text.pory` vide

2. **Layout** : Copie `data/layouts/MapName/` avec :
   - `map.bin` (données de la map)
   - `border.bin` (bordures)
   - `map.bin.emerald` (backup de l'original)

3. **Tilesets** :
   - Primary tileset : `data/tilesets/primary/hoenn_general/`
   - Secondary tileset : `data/tilesets/secondary/mapname/`
   - Animations : `hoenn_general/anim/water/`, `waterfall/`, etc.

## ❌ Ce qui n'est PAS importé

Le script **ignore volontairement** :

- ❌ Events (object_events, warp_events, bg_events, coord_events)
- ❌ Scripts (scripts.inc d'Emerald)
- ❌ Connections vers d'autres maps
- ❌ Textes

## 🔧 Options du script

```
--emerald CHEMIN    : Chemin vers le repo pokeemerald (obligatoire)
--map NOM          : Nom de la map à importer (obligatoire)
--group GROUPE     : Groupe de map (défaut: gMapGroup_RSE)
--firered CHEMIN   : Chemin vers ce repo (défaut: répertoire courant)
--dry-run          : Simulation sans modification
```

## 📝 Exemple complet

```bash
# 1. Nettoyer
python3 clean_lilycove.py

# 2. Importer la structure
python3 import_emerald_map_simple.py \
  --emerald ../pokeemerald \
  --map LilycoveCity \
  --group gMapGroup_RSE

# 3. Compiler
wsl make leafgreen

# 4. Tester dans l'émulateur
```

## ➕ Ajouter des events plus tard (optionnel)

Une fois que la structure de la map fonctionne, vous pouvez ajouter manuellement des events dans `map.json` :

### Exemple : Ajouter un Centre Pokémon

```json
{
  "warp_events": [
    {
      "x": 24,
      "y": 14,
      "elevation": 0,
      "dest_map": "MAP_LILYCOVE_CITY_POKEMON_CENTER_1F",
      "dest_warp_id": 0
    }
  ]
}
```

### Exemple : Ajouter un PNJ

```json
{
  "object_events": [
    {
      "graphics_id": "OBJ_EVENT_GFX_GIRL_1",
      "x": 15,
      "y": 18,
      "elevation": 3,
      "movement_type": "MOVEMENT_TYPE_WANDER_AROUND",
      "movement_range_x": 1,
      "movement_range_y": 1,
      "trainer_type": "TRAINER_TYPE_NONE",
      "trainer_sight_or_berry_tree_id": 0,
      "script": "MyCustomScript",
      "flag": 0
    }
  ]
}
```

## 🐛 Dépannage

### Problème : La compilation échoue

**Solution** : Vérifiez que les entrées de tilesets existent dans :
- `src/data/tilesets/graphics.h`
- `src/data/tilesets/metatiles.h`
- `src/data/tilesets/headers.h`

Si elles manquent, consultez le guide complet `IMPORT_EMERALD_MAPS.md`.

### Problème : Les animations ne fonctionnent pas

**Solution** : Vérifiez que :
1. `InitTilesetAnim_HoennGeneral` existe dans `src/tileset_anims.c`
2. Les fichiers `.4bpp` existent dans `data/tilesets/primary/hoenn_general/anim/`

### Problème : La map est glitchée

**Solution** : Essayez d'utiliser `map.bin.emerald` :
```bash
cd data/layouts/LilycoveCity
cp map.bin.emerald map.bin
wsl make clean
wsl make leafgreen
```

## 🔄 Importer plusieurs maps

```bash
for map in LilycoveCity MossdeepCity SootopolisCity; do
  python3 import_emerald_map_simple.py \
    --emerald ../pokeemerald \
    --map $map
done

wsl make leafgreen
```

## 📊 Comparaison des scripts

| Fonctionnalité | `import_emerald_map.py` | `import_emerald_map_simple.py` |
|----------------|-------------------------|--------------------------------|
| Layout + Tilesets | ✅ | ✅ |
| Animations | ✅ | ✅ |
| Events | ✅ (peut causer erreurs) | ❌ (volontairement) |
| Scripts | ✅ (peut causer erreurs) | ❌ (volontairement) |
| Connections | ✅ (peut causer erreurs) | ❌ (volontairement) |
| Compilation garantie | ⚠️ Possible erreurs | ✅ Toujours OK |
| **Recommandation** | Pour utilisateurs avancés | **Pour débuter** ✨ |

## 💡 Workflow recommandé

1. **Phase 1 : Structure** (ce script)
   - Importer la structure de la map
   - Vérifier que la map + animations fonctionnent
   - Valider visuellement

2. **Phase 2 : Events basiques** (manuel)
   - Ajouter les warps vers d'autres maps
   - Ajouter quelques PNJs simples
   - Tester

3. **Phase 3 : Scripts** (manuel)
   - Convertir les scripts Emerald en Pory
   - Ajouter les dialogues
   - Tester

4. **Phase 4 : Polish** (manuel)
   - Ajouter tous les events restants
   - Activer les connections
   - Tests finaux

## 🎯 Résultat attendu

Après avoir utilisé ce script, vous devriez pouvoir :
- ✅ Compiler sans erreur
- ✅ Charger la map dans le jeu
- ✅ Voir les animations d'eau fonctionner
- ✅ Vous déplacer librement sur la map

La map sera vide (pas de PNJ, pas de warps), mais la structure visuelle sera complète et fonctionnelle.

## 📚 Ressources

- Script complet (avec events) : `import_emerald_map.py`
- Guide complet : `IMPORT_EMERALD_MAPS.md`
- Script de nettoyage : `clean_lilycove.py`
