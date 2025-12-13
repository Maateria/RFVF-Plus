#!/usr/bin/env python3
"""
Script d'importation SIMPLIFIÉ de maps de Pokémon Emerald vers Pokémon FireRed
Version: 2.0 - Structure uniquement (pas d'events ni scripts)

Ce script importe uniquement la structure de la map :
- Layout (map.bin, border.bin)
- Tilesets (primary + secondary) avec animations
- Configuration JSON

SANS importer :
- Events (object_events, warp_events, coord_events, bg_events)
- Scripts
- Connections
"""

import os
import sys
import json
import shutil
import argparse
from pathlib import Path
from typing import Dict, List, Optional

# Couleurs pour la console
class Colors:
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    BLUE = '\033[94m'
    RESET = '\033[0m'
    BOLD = '\033[1m'

def log_info(msg: str):
    print(f"{Colors.BLUE}[INFO]{Colors.RESET} {msg}")

def log_success(msg: str):
    print(f"{Colors.GREEN}[✓]{Colors.RESET} {msg}")

def log_warning(msg: str):
    print(f"{Colors.YELLOW}[!]{Colors.RESET} {msg}")

def log_error(msg: str):
    print(f"{Colors.RED}[✗]{Colors.RESET} {msg}")

class SimpleEmeraldMapImporter:
    def __init__(self, emerald_path: str, firered_path: str, map_name: str,
                 group_name: str = "gMapGroup_RSE", dry_run: bool = False):
        self.emerald_path = Path(emerald_path)
        self.firered_path = Path(firered_path)
        self.map_name = map_name
        self.group_name = group_name
        self.dry_run = dry_run

        # Chemins importants
        self.emerald_layouts = self.emerald_path / "data" / "layouts"
        self.emerald_tilesets = self.emerald_path / "data" / "tilesets"

        self.firered_maps = self.firered_path / "data" / "maps"
        self.firered_layouts = self.firered_path / "data" / "layouts"
        self.firered_tilesets = self.firered_path / "data" / "tilesets"

    def validate_paths(self) -> bool:
        """Valide que les chemins existent"""
        log_info("Validation des chemins...")

        if not self.emerald_path.exists():
            log_error(f"Le chemin Emerald n'existe pas: {self.emerald_path}")
            return False

        if not self.firered_path.exists():
            log_error(f"Le chemin FireRed n'existe pas: {self.firered_path}")
            return False

        layout_path = self.emerald_layouts / self.map_name
        if not layout_path.exists():
            log_error(f"Le layout {self.map_name} n'existe pas dans Emerald: {layout_path}")
            return False

        log_success("Tous les chemins sont valides")
        return True

    def create_empty_map_folder(self) -> bool:
        """Crée un dossier de map vide avec des fichiers minimaux"""
        dst = self.firered_maps / self.map_name

        log_info(f"Création du dossier de map: {self.map_name}")

        if dst.exists():
            log_warning(f"Le dossier {dst} existe déjà")
            if not self.dry_run:
                response = input("Voulez-vous le remplacer? (y/n): ").lower()
                if response != 'y':
                    log_info("Création annulée par l'utilisateur")
                    return True
                shutil.rmtree(dst)

        if not self.dry_run:
            dst.mkdir(parents=True, exist_ok=True)

            # Créer map.json minimal
            map_json = {
                "id": f"MAP_{self.map_name.upper()}",
                "name": self.map_name,
                "layout": f"LAYOUT_{self.map_name.upper()}",
                "music": "MUS_CITIES1",
                "region_map_section": "MAPSEC_NONE",
                "requires_flash": False,
                "weather": "WEATHER_NONE",
                "map_type": "MAP_TYPE_CITY",
                "floor_number": 0,
                "allow_cycling": True,
                "allow_escaping": True,
                "allow_running": True,
                "show_map_name": True,
                "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
                "connections": [],
                "object_events": [],
                "warp_events": [],
                "coord_events": [],
                "bg_events": []
            }

            with open(dst / "map.json", 'w', encoding='utf-8') as f:
                json.dump(map_json, f, indent=2)
            log_success("map.json créé (minimal, sans events)")

            # Créer scripts.pory vide
            with open(dst / "scripts.pory", 'w', encoding='utf-8') as f:
                f.write(f"// {self.map_name} scripts\n")
                f.write(f"// Empty - no scripts imported from Emerald\n\n")
                f.write(f"raw `\n")
                f.write(f"{self.map_name}_MapScripts::\n")
                f.write(f"\t.byte 0\n")
                f.write(f"\n")
                f.write(f"{self.map_name}_OnTransition::\n")
                f.write(f"\tend\n")
                f.write(f"`\n")
            log_success("scripts.pory créé (vide)")

            # Créer text.pory vide
            with open(dst / "text.pory", 'w', encoding='utf-8') as f:
                f.write(f"// {self.map_name} text\n")
                f.write(f"// Empty - no text imported from Emerald\n")
            log_success("text.pory créé (vide)")

            log_success(f"Dossier de map créé: {dst}")
        else:
            log_info(f"[DRY RUN] Créerait le dossier: {dst}")

        return True

    def update_map_groups(self) -> bool:
        """Ajoute la map au fichier map_groups.json"""
        map_groups_file = self.firered_maps / "map_groups.json"

        log_info("Mise à jour de map_groups.json...")

        if not map_groups_file.exists():
            log_error(f"Fichier map_groups.json introuvable: {map_groups_file}")
            return False

        with open(map_groups_file, 'r', encoding='utf-8') as f:
            map_groups = json.load(f)

        # Vérifier si le groupe existe
        if self.group_name not in map_groups:
            log_warning(f"Le groupe {self.group_name} n'existe pas, création...")
            if not self.dry_run:
                map_groups[self.group_name] = []
                # Ajouter aussi dans group_order si présent
                if "group_order" in map_groups and self.group_name not in map_groups["group_order"]:
                    map_groups["group_order"].append(self.group_name)

        # Ajouter la map si elle n'existe pas déjà
        if self.map_name not in map_groups.get(self.group_name, []):
            if not self.dry_run:
                map_groups[self.group_name].append(self.map_name)
                with open(map_groups_file, 'w', encoding='utf-8') as f:
                    json.dump(map_groups, f, indent=2)
                log_success(f"Map {self.map_name} ajoutée au groupe {self.group_name}")
            else:
                log_info(f"[DRY RUN] Ajouterait {self.map_name} au groupe {self.group_name}")
        else:
            log_info(f"La map {self.map_name} existe déjà dans {self.group_name}")

        return True

    def copy_layout(self) -> Dict:
        """Copie le layout et retourne ses informations"""
        log_info(f"Copie du layout pour {self.map_name}...")

        # Lire layouts.json d'Emerald
        emerald_layouts_file = self.emerald_layouts / "layouts.json"
        firered_layouts_file = self.firered_layouts / "layouts.json"

        if not emerald_layouts_file.exists():
            log_error(f"Fichier layouts.json d'Emerald introuvable: {emerald_layouts_file}")
            return {}

        with open(emerald_layouts_file, 'r', encoding='utf-8') as f:
            emerald_layouts = json.load(f)

        # Trouver le layout correspondant à la map
        layout_entry = None
        for layout in emerald_layouts.get("layouts", []):
            # Chercher par nom de map dans l'ID ou le name
            if self.map_name.upper() in layout.get("id", "").upper() or \
               self.map_name.upper() in layout.get("name", "").upper():
                layout_entry = layout.copy()
                break

        if not layout_entry:
            log_warning(f"Layout introuvable pour {self.map_name} dans Emerald")
            return {}

        log_success(f"Layout trouvé: {layout_entry.get('id', 'N/A')}")

        # S'assurer que border_width et border_height sont définis
        if not layout_entry.get('border_width'):
            layout_entry['border_width'] = 2
            log_info("border_width manquant, valeur par défaut: 2")
        if not layout_entry.get('border_height'):
            layout_entry['border_height'] = 2
            log_info("border_height manquant, valeur par défaut: 2")

        # Adapter les tilesets pour FireRed
        original_primary = layout_entry.get("primary_tileset", "")
        original_secondary = layout_entry.get("secondary_tileset", "")

        log_info(f"Tilesets originaux: {original_primary} / {original_secondary}")

        # Remplacer gTileset_General par gTileset_hoenn_general
        if "General" in original_primary:
            layout_entry["primary_tileset"] = "gTileset_hoenn_general"
            log_info(f"Primary tileset adapté: {layout_entry['primary_tileset']}")

        # Adapter le secondary tileset
        if original_secondary:
            tileset_name = original_secondary.replace("gTileset_", "")
            simplified_name = tileset_name.replace("City", "").lower()
            layout_entry["secondary_tileset"] = f"gTileset_{simplified_name}"
            log_info(f"Secondary tileset adapté: {layout_entry['secondary_tileset']}")

        # Copier le dossier du layout
        src_layout = self.emerald_layouts / self.map_name
        dst_layout = self.firered_layouts / self.map_name

        if src_layout.exists():
            if dst_layout.exists():
                log_warning(f"Le layout {dst_layout} existe déjà")
                if not self.dry_run:
                    # Backup de l'ancien map.bin si présent
                    old_map_bin = dst_layout / "map.bin"
                    if old_map_bin.exists():
                        shutil.copy(old_map_bin, dst_layout / "map.bin.frlg.backup")
                        log_info("Backup de l'ancien map.bin créé")
                    shutil.rmtree(dst_layout)

            if not self.dry_run:
                shutil.copytree(src_layout, dst_layout)
                # Renommer map.bin en map.bin.emerald pour garder l'original
                map_bin = dst_layout / "map.bin"
                if map_bin.exists():
                    shutil.copy(map_bin, dst_layout / "map.bin.emerald")
                log_success(f"Layout copié: {dst_layout}")
            else:
                log_info(f"[DRY RUN] Copierait: {src_layout} -> {dst_layout}")

        # Ajouter le layout à layouts.json de FireRed
        if not self.dry_run:
            with open(firered_layouts_file, 'r', encoding='utf-8') as f:
                firered_layouts = json.load(f)

            # Vérifier si le layout existe déjà
            existing_layout_idx = None
            for idx, layout in enumerate(firered_layouts.get("layouts", [])):
                if layout.get("id") == layout_entry.get("id"):
                    existing_layout_idx = idx
                    break

            if existing_layout_idx is not None:
                firered_layouts["layouts"][existing_layout_idx] = layout_entry
                log_info(f"Layout existant mis à jour: {layout_entry.get('id')}")
            else:
                firered_layouts.setdefault("layouts", []).append(layout_entry)
                log_success(f"Nouveau layout ajouté: {layout_entry.get('id')}")

            with open(firered_layouts_file, 'w', encoding='utf-8') as f:
                json.dump(firered_layouts, f, indent=2)
        else:
            log_info(f"[DRY RUN] Ajouterait le layout au fichier layouts.json")

        return layout_entry

    def copy_primary_tileset(self, tileset_name: str = "hoenn_general") -> bool:
        """Copie le tileset primary avec animations"""
        log_info(f"Copie du primary tileset: {tileset_name}")

        src = self.emerald_tilesets / "primary" / "general"
        dst = self.firered_tilesets / "primary" / tileset_name

        if not src.exists():
            log_error(f"Tileset primary introuvable dans Emerald: {src}")
            return False

        if dst.exists():
            log_warning(f"Le tileset {dst} existe déjà")
            if not self.dry_run:
                response = input("Voulez-vous le remplacer? (y/n): ").lower()
                if response != 'y':
                    log_info("Copie du primary tileset annulée")
                    return True
                # Backup
                backup_path = dst.parent / f"{tileset_name}.backup"
                if backup_path.exists():
                    shutil.rmtree(backup_path)
                shutil.copytree(dst, backup_path)
                log_info(f"Backup créé: {backup_path}")
                shutil.rmtree(dst)

        if not self.dry_run:
            shutil.copytree(src, dst)
            log_success(f"Primary tileset copié: {dst}")

            # Vérifier les animations
            anim_dir = dst / "anim"
            if anim_dir.exists():
                anim_types = [d.name for d in anim_dir.iterdir() if d.is_dir()]
                log_success(f"Animations trouvées: {', '.join(anim_types)}")
        else:
            log_info(f"[DRY RUN] Copierait: {src} -> {dst}")

        return True

    def copy_secondary_tileset(self, tileset_name: str) -> bool:
        """Copie le tileset secondary"""
        log_info(f"Copie du secondary tileset: {tileset_name}")

        # Chercher le tileset dans Emerald
        possible_names = [
            tileset_name,
            tileset_name.lower(),
            tileset_name.title(),
            f"{tileset_name}City",
            f"{tileset_name.title()}City"
        ]

        src = None
        for name in possible_names:
            test_path = self.emerald_tilesets / "secondary" / name
            if test_path.exists():
                src = test_path
                break

        if not src:
            log_error(f"Tileset secondary introuvable dans Emerald: {possible_names}")
            return False

        log_success(f"Tileset trouvé: {src.name}")

        dst = self.firered_tilesets / "secondary" / tileset_name.lower()

        if dst.exists():
            log_warning(f"Le tileset {dst} existe déjà")
            if not self.dry_run:
                response = input("Voulez-vous le remplacer? (y/n): ").lower()
                if response != 'y':
                    log_info("Copie du secondary tileset annulée")
                    return True
                # Backup
                backup_path = dst.parent / f"{tileset_name.lower()}.backup"
                if backup_path.exists():
                    shutil.rmtree(backup_path)
                shutil.copytree(dst, backup_path)
                log_info(f"Backup créé: {backup_path}")
                shutil.rmtree(dst)

        if not self.dry_run:
            shutil.copytree(src, dst)
            log_success(f"Secondary tileset copié: {dst}")
        else:
            log_info(f"[DRY RUN] Copierait: {src} -> {dst}")

        return True

    def check_configuration_files(self, secondary_tileset_name: str) -> bool:
        """Vérifie les fichiers de configuration"""
        log_info("Vérification des fichiers de configuration...")

        all_ok = True

        # Vérifier headers.h
        headers_file = self.firered_path / "src" / "data" / "tilesets" / "headers.h"
        if headers_file.exists():
            with open(headers_file, 'r', encoding='utf-8') as f:
                content = f.read()
            if "gTileset_hoenn_general" not in content:
                log_warning("gTileset_hoenn_general manquant dans headers.h")
                all_ok = False
            if f"gTileset_{secondary_tileset_name.lower()}" not in content:
                log_warning(f"gTileset_{secondary_tileset_name.lower()} manquant dans headers.h")
                all_ok = False

        # Vérifier graphics.h
        graphics_file = self.firered_path / "src" / "data" / "tilesets" / "graphics.h"
        if graphics_file.exists():
            with open(graphics_file, 'r', encoding='utf-8') as f:
                content = f.read()
            if "gTilesetTiles_hoenn_general" not in content:
                log_warning("Entrées hoenn_general manquantes dans graphics.h")
                all_ok = False

        # Vérifier metatiles.h
        metatiles_file = self.firered_path / "src" / "data" / "tilesets" / "metatiles.h"
        if metatiles_file.exists():
            with open(metatiles_file, 'r', encoding='utf-8') as f:
                content = f.read()
            if "gMetatiles_hoenn_general" not in content:
                log_warning("Entrées hoenn_general manquantes dans metatiles.h")
                all_ok = False

        # Vérifier tileset_anims.c
        anims_file = self.firered_path / "src" / "tileset_anims.c"
        if anims_file.exists():
            with open(anims_file, 'r', encoding='utf-8') as f:
                content = f.read()
            if "InitTilesetAnim_HoennGeneral" not in content:
                log_warning("Fonctions d'animation manquantes dans tileset_anims.c")
                all_ok = False

        if all_ok:
            log_success("Tous les fichiers de configuration sont OK")
        else:
            log_warning("Certaines entrées manquent - voir les warnings ci-dessus")

        return all_ok

    def generate_summary(self, layout_info: Dict):
        """Génère un résumé de l'importation"""
        print("\n" + "="*70)
        print(f"{Colors.BOLD}RÉSUMÉ DE L'IMPORTATION (VERSION SIMPLIFIÉE){Colors.RESET}")
        print("="*70)
        print(f"Map: {Colors.BOLD}{self.map_name}{Colors.RESET}")
        print(f"Groupe: {self.group_name}")

        if layout_info:
            print(f"\nLayout ID: {layout_info.get('id', 'N/A')}")
            print(f"Dimensions: {layout_info.get('width', '?')}x{layout_info.get('height', '?')}")
            print(f"Primary tileset: {layout_info.get('primary_tileset', 'N/A')}")
            print(f"Secondary tileset: {layout_info.get('secondary_tileset', 'N/A')}")

        print("\n" + "="*70)
        print(f"{Colors.BOLD}CE QUI A ÉTÉ IMPORTÉ{Colors.RESET}")
        print("="*70)
        print("✓ Structure de la map (map.json minimal)")
        print("✓ Layout (map.bin, border.bin)")
        print("✓ Tilesets (primary + secondary)")
        print("✓ Animations (water, waterfall, etc.)")
        print("\n✗ Events (désactivés)")
        print("✗ Scripts (désactivés)")
        print("✗ Connections (désactivées)")

        print("\n" + "="*70)
        print(f"{Colors.BOLD}PROCHAINES ÉTAPES{Colors.RESET}")
        print("="*70)
        print("1. Compilez avec: wsl make")
        print("2. Testez la map dans le jeu")
        print("3. Vérifiez que:")
        print("   - La map s'affiche correctement")
        print("   - Les animations d'eau/cascades fonctionnent")
        print("   - Il n'y a pas de glitchs graphiques")
        print("\n4. Une fois la structure validée, vous pourrez:")
        print("   - Ajouter manuellement les events dans map.json")
        print("   - Convertir les scripts d'Emerald en Pory")
        print("   - Activer les connections vers d'autres maps")
        print("="*70 + "\n")

    def run(self) -> bool:
        """Exécute l'importation simplifiée"""
        print(f"\n{Colors.BOLD}{'='*70}{Colors.RESET}")
        print(f"{Colors.BOLD}IMPORTATION SIMPLIFIÉE: {self.map_name}{Colors.RESET}")
        print(f"{Colors.BOLD}(Structure uniquement - pas d'events ni scripts){Colors.RESET}")
        print(f"{Colors.BOLD}{'='*70}{Colors.RESET}\n")

        if self.dry_run:
            log_warning("MODE DRY RUN - Aucune modification ne sera effectuée")

        # Validation
        if not self.validate_paths():
            return False

        # Étape 1: Créer le dossier de map vide
        if not self.create_empty_map_folder():
            return False

        # Étape 2: Mettre à jour map_groups.json
        if not self.update_map_groups():
            return False

        # Étape 3: Copier et configurer le layout
        layout_info = self.copy_layout()
        if not layout_info:
            log_error("Échec de la copie du layout")
            return False

        # Étape 4: Copier le primary tileset
        if not self.copy_primary_tileset():
            return False

        # Étape 5: Copier le secondary tileset
        secondary_name = layout_info.get("secondary_tileset", "").replace("gTileset_", "")
        if secondary_name:
            if not self.copy_secondary_tileset(secondary_name):
                return False

        # Étape 6: Vérifications
        self.check_configuration_files(secondary_name)

        # Résumé
        self.generate_summary(layout_info)

        if not self.dry_run:
            log_success(f"Importation simplifiée de {self.map_name} terminée avec succès!")
        else:
            log_info("DRY RUN terminé - Aucune modification effectuée")

        return True

def main():
    parser = argparse.ArgumentParser(
        description="Importe la STRUCTURE d'une map d'Emerald vers FireRed (sans events ni scripts)",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  # Import basique
  python import_emerald_map_simple.py --emerald /path/to/pokeemerald --map LilycoveCity

  # Dry run
  python import_emerald_map_simple.py --emerald /path/to/pokeemerald --map LilycoveCity --dry-run

  # Import avec groupe personnalisé
  python import_emerald_map_simple.py --emerald /path/to/pokeemerald --map MossdeepCity --group gMapGroup_HoennCities
        """
    )

    parser.add_argument("--emerald", required=True, help="Chemin vers le repo pokeemerald")
    parser.add_argument("--map", required=True, help="Nom de la map à importer (ex: LilycoveCity)")
    parser.add_argument("--group", default="gMapGroup_RSE", help="Groupe de map dans FireRed (défaut: gMapGroup_RSE)")
    parser.add_argument("--firered", default=".", help="Chemin vers le repo pokefirered (défaut: répertoire courant)")
    parser.add_argument("--dry-run", action="store_true", help="Simulation sans modification")

    args = parser.parse_args()

    importer = SimpleEmeraldMapImporter(
        emerald_path=args.emerald,
        firered_path=args.firered,
        map_name=args.map,
        group_name=args.group,
        dry_run=args.dry_run
    )

    success = importer.run()
    sys.exit(0 if success else 1)

if __name__ == "__main__":
    main()
