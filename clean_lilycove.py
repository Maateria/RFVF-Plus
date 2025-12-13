#!/usr/bin/env python3
"""
Script de nettoyage des fichiers Lilycove pour repartir sur une base propre
"""

import os
import sys
import json
import shutil
from pathlib import Path

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

def clean_lilycove(dry_run=False):
    """Nettoie tous les fichiers liés à Lilycove"""

    print(f"\n{Colors.BOLD}{'='*70}{Colors.RESET}")
    print(f"{Colors.BOLD}NETTOYAGE DES FICHIERS LILYCOVE{Colors.RESET}")
    print(f"{Colors.BOLD}{'='*70}{Colors.RESET}\n")

    if dry_run:
        log_warning("MODE DRY RUN - Aucune suppression ne sera effectuée")

    base_path = Path.cwd()

    # Liste des fichiers/dossiers à nettoyer
    items_to_clean = [
        # Maps
        ("data/maps/LilycoveCity", "Dossier de map"),

        # Layouts
        ("data/layouts/LilycoveCity", "Dossier de layout"),

        # Tilesets
        ("data/tilesets/secondary/lilycove", "Tileset secondary"),
        ("data/tilesets/secondary/lilycove.OLD", "Backup tileset secondary"),

        # Scripts Python temporaires
        ("analyze_water_tiles.py", "Script temporaire"),
        ("convert_frlg_to_emerald_attrs.py", "Script temporaire"),
        ("extract_static_water.py", "Script temporaire"),
        ("extract_water_anim_frames.py", "Script temporaire"),
        ("merge_emerald_animations.py", "Script temporaire"),
        ("merge_emerald_animations.sh", "Script temporaire"),
        ("info:palette.txt", "Fichier temporaire"),
    ]

    files_removed = []
    files_not_found = []

    # Supprimer les fichiers/dossiers
    for item_path, description in items_to_clean:
        full_path = base_path / item_path

        if full_path.exists():
            if not dry_run:
                if full_path.is_dir():
                    shutil.rmtree(full_path)
                else:
                    full_path.unlink()
                log_success(f"Supprimé: {item_path} ({description})")
                files_removed.append(item_path)
            else:
                log_info(f"[DRY RUN] Supprimerait: {item_path} ({description})")
                files_removed.append(item_path)
        else:
            log_info(f"Non trouvé (déjà absent): {item_path}")
            files_not_found.append(item_path)

    # Nettoyer map_groups.json
    log_info("\nNettoyage de map_groups.json...")
    map_groups_file = base_path / "data" / "maps" / "map_groups.json"

    if map_groups_file.exists():
        with open(map_groups_file, 'r', encoding='utf-8') as f:
            map_groups = json.load(f)

        modified = False
        for group_name, maps in map_groups.items():
            if isinstance(maps, list) and "LilycoveCity" in maps:
                if not dry_run:
                    maps.remove("LilycoveCity")
                    modified = True
                    log_success(f"LilycoveCity supprimée du groupe {group_name}")
                else:
                    log_info(f"[DRY RUN] Supprimerait LilycoveCity du groupe {group_name}")

        if modified and not dry_run:
            with open(map_groups_file, 'w', encoding='utf-8') as f:
                json.dump(map_groups, f, indent=2)

    # Nettoyer layouts.json
    log_info("Nettoyage de layouts.json...")
    layouts_file = base_path / "data" / "layouts" / "layouts.json"

    if layouts_file.exists():
        with open(layouts_file, 'r', encoding='utf-8') as f:
            layouts_data = json.load(f)

        original_count = len(layouts_data.get("layouts", []))

        if not dry_run:
            # Supprimer les layouts contenant "Lilycove" ou utilisant gTileset_lilycove
            layouts_data["layouts"] = [
                layout for layout in layouts_data.get("layouts", [])
                if "lilycove" not in layout.get("id", "").lower()
                and "lilycove" not in layout.get("name", "").lower()
                and layout.get("secondary_tileset") != "gTileset_lilycove"
            ]

            new_count = len(layouts_data["layouts"])
            removed = original_count - new_count

            if removed > 0:
                with open(layouts_file, 'w', encoding='utf-8') as f:
                    json.dump(layouts_data, f, indent=2)
                log_success(f"{removed} layout(s) lié(s) à Lilycove supprimé(s)")
            else:
                log_info("Aucun layout lié à Lilycove trouvé")
        else:
            # Compter combien seraient supprimés
            to_remove = [
                layout for layout in layouts_data.get("layouts", [])
                if "lilycove" in layout.get("id", "").lower()
                or "lilycove" in layout.get("name", "").lower()
                or layout.get("secondary_tileset") == "gTileset_lilycove"
            ]
            if to_remove:
                log_info(f"[DRY RUN] Supprimerait {len(to_remove)} layout(s) lié(s) à Lilycove")
                for layout in to_remove:
                    log_info(f"  - {layout.get('id', 'N/A')}")

    # Vérifier graphics.h
    log_info("\nVérification de graphics.h...")
    graphics_file = base_path / "src" / "data" / "tilesets" / "graphics.h"

    if graphics_file.exists():
        with open(graphics_file, 'r', encoding='utf-8') as f:
            content = f.read()

        if "lilycove" in content.lower():
            log_warning("Des entrées 'lilycove' existent dans graphics.h")
            log_info("Elles seront recréées lors de la réimportation")
        else:
            log_info("Aucune entrée 'lilycove' dans graphics.h")

    # Vérifier metatiles.h
    log_info("Vérification de metatiles.h...")
    metatiles_file = base_path / "src" / "data" / "tilesets" / "metatiles.h"

    if metatiles_file.exists():
        with open(metatiles_file, 'r', encoding='utf-8') as f:
            content = f.read()

        if "lilycove" in content.lower():
            log_warning("Des entrées 'lilycove' existent dans metatiles.h")
            log_info("Elles seront recréées lors de la réimportation")
        else:
            log_info("Aucune entrée 'lilycove' dans metatiles.h")

    # Vérifier headers.h
    log_info("Vérification de headers.h...")
    headers_file = base_path / "src" / "data" / "tilesets" / "headers.h"

    if headers_file.exists():
        with open(headers_file, 'r', encoding='utf-8') as f:
            content = f.read()

        if "gTileset_lilycove" in content:
            log_warning("gTileset_lilycove existe dans headers.h")
            log_info("Il sera recréé lors de la réimportation")
        else:
            log_info("Aucune entrée gTileset_lilycove dans headers.h")

    # Résumé
    print("\n" + "="*70)
    print(f"{Colors.BOLD}RÉSUMÉ DU NETTOYAGE{Colors.RESET}")
    print("="*70)
    print(f"Fichiers/dossiers supprimés: {len(files_removed)}")
    print(f"Fichiers/dossiers non trouvés: {len(files_not_found)}")

    print("\n" + "="*70)
    print(f"{Colors.BOLD}PROCHAINES ÉTAPES{Colors.RESET}")
    print("="*70)
    print("1. Exécutez le script d'importation:")
    print("   python3 import_emerald_map.py --emerald /path/to/pokeemerald --map LilycoveCity")
    print("\n2. Ou faites d'abord un dry-run:")
    print("   python3 import_emerald_map.py --emerald /path/to/pokeemerald --map LilycoveCity --dry-run")
    print("\n3. Après l'importation, compilez:")
    print("   wsl make")
    print("="*70 + "\n")

    if not dry_run:
        log_success("Nettoyage terminé!")
    else:
        log_info("DRY RUN terminé - Aucune modification effectuée")

def main():
    import argparse

    parser = argparse.ArgumentParser(description="Nettoie les fichiers Lilycove pour repartir sur une base propre")
    parser.add_argument("--dry-run", action="store_true", help="Simulation sans suppression")

    args = parser.parse_args()

    clean_lilycove(dry_run=args.dry_run)

if __name__ == "__main__":
    main()
