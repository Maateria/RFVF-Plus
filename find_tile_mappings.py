#!/usr/bin/env python3
"""
Trouve les correspondances entre les tiles d'Emerald et FireRed.

Ce script :
1. Charge le primary tileset d'Emerald (tiles.png)
2. Charge le primary tileset de FireRed (tiles.png)
3. Pour chaque tile d'Emerald dans une plage donnée, trouve son équivalent dans FireRed
4. Affiche les mappings

Usage:
    python find_tile_mappings.py <emerald_primary_tiles.png> <firered_primary_tiles.png> <start_tile> <end_tile>

Exemple:
    python find_tile_mappings.py \\
        /mnt/c/Users/Utilisateur/Documents/RFVF-Plus/pokeemerald/data/tilesets/primary/hoenn_general/tiles.png \\
        data/tilesets/primary/hoenn_general/tiles.png \\
        432 462
"""

import sys
from pathlib import Path
from PIL import Image
import numpy as np

def load_tiles_from_png(tiles_png: Path):
    """
    Charge tous les tiles (8x8) depuis tiles.png en mode indexed.
    """
    img = Image.open(tiles_png)

    # Forcer en mode palette si ce n'est pas déjà le cas
    if img.mode != 'P':
        print(f"  ⚠ Warning: {tiles_png.name} n'est pas en mode palette, conversion...")
        img = img.convert('P', palette=Image.ADAPTIVE, colors=16)

    width, height = img.size
    tiles_per_row = width // 8
    num_tiles = (width // 8) * (height // 8)

    pixels = np.array(img)

    tiles = []
    for tile_id in range(num_tiles):
        row = (tile_id // tiles_per_row) * 8
        col = (tile_id % tiles_per_row) * 8

        tile_pixels = pixels[row:row+8, col:col+8]
        tiles.append(tile_pixels)

    return tiles

def tiles_are_identical(tile1, tile2):
    """Compare deux tiles et retourne True si identiques."""
    return np.array_equal(tile1, tile2)

def find_tile_in_firered(emerald_tile, firered_tiles):
    """
    Cherche un tile d'Emerald dans la liste des tiles FireRed.
    Retourne l'index du tile FireRed s'il est trouvé, sinon None.
    """
    for fr_idx, fr_tile in enumerate(firered_tiles):
        if tiles_are_identical(emerald_tile, fr_tile):
            return fr_idx
    return None

def main():
    if len(sys.argv) < 5:
        print("Usage: python find_tile_mappings.py <emerald_tiles.png> <firered_tiles.png> <start_tile> <end_tile>")
        print("\nExemple pour trouver les tiles d'eau (432-462 dans Emerald):")
        print("  python find_tile_mappings.py \\")
        print("      /path/to/pokeemerald/data/tilesets/primary/hoenn_general/tiles.png \\")
        print("      data/tilesets/primary/hoenn_general/tiles.png \\")
        print("      432 462")
        sys.exit(1)

    emerald_tiles_path = Path(sys.argv[1])
    firered_tiles_path = Path(sys.argv[2])
    start_tile = int(sys.argv[3])
    end_tile = int(sys.argv[4])

    # Vérifier que les fichiers existent
    if not emerald_tiles_path.exists():
        print(f"❌ Erreur: {emerald_tiles_path} introuvable")
        sys.exit(1)

    if not firered_tiles_path.exists():
        print(f"❌ Erreur: {firered_tiles_path} introuvable")
        sys.exit(1)

    print("=" * 70)
    print("RECHERCHE DE CORRESPONDANCES DE TILES EMERALD → FIRERED")
    print("=" * 70)
    print(f"Emerald tiles: {emerald_tiles_path}")
    print(f"FireRed tiles: {firered_tiles_path}")
    print(f"Plage de tiles: {start_tile} - {end_tile} ({end_tile - start_tile + 1} tiles)")
    print()

    # Charger les tiles
    print("📖 Chargement des tiles d'Emerald...")
    emerald_tiles = load_tiles_from_png(emerald_tiles_path)
    print(f"  ✓ {len(emerald_tiles)} tiles chargés")

    print("📖 Chargement des tiles de FireRed...")
    firered_tiles = load_tiles_from_png(firered_tiles_path)
    print(f"  ✓ {len(firered_tiles)} tiles chargés")
    print()

    # Rechercher les correspondances
    print("🔍 Recherche des correspondances...")
    print()

    mappings = []
    not_found = []

    for emerald_idx in range(start_tile, end_tile + 1):
        if emerald_idx >= len(emerald_tiles):
            print(f"  ⚠ Tile Emerald {emerald_idx} (0x{emerald_idx:03X}) hors limites")
            not_found.append(emerald_idx)
            continue

        emerald_tile = emerald_tiles[emerald_idx]
        firered_idx = find_tile_in_firered(emerald_tile, firered_tiles)

        if firered_idx is not None:
            mappings.append((emerald_idx, firered_idx))
            print(f"  ✓ Emerald {emerald_idx:3d} (0x{emerald_idx:03X}) → FireRed {firered_idx:3d} (0x{firered_idx:03X})")
        else:
            not_found.append(emerald_idx)
            print(f"  ✗ Emerald {emerald_idx:3d} (0x{emerald_idx:03X}) → NON TROUVÉ")

    print()
    print("=" * 70)
    print("RÉSUMÉ")
    print("=" * 70)
    print(f"✓ Tiles trouvés: {len(mappings)}/{end_tile - start_tile + 1}")
    print(f"✗ Tiles non trouvés: {len(not_found)}")
    print()

    if mappings:
        print("📋 PLAGE FIRERED POUR LES ANIMATIONS:")
        print()

        # Trouver la plage continue dans FireRed
        firered_indices = sorted([fr_idx for _, fr_idx in mappings])

        if len(firered_indices) == 1:
            print(f"  Tile unique: {firered_indices[0]} (0x{firered_indices[0]:03X})")
        else:
            # Vérifier si c'est une plage continue
            is_continuous = all(
                firered_indices[i+1] - firered_indices[i] == 1
                for i in range(len(firered_indices) - 1)
            )

            if is_continuous:
                print(f"  Plage continue: {firered_indices[0]} - {firered_indices[-1]}")
                print(f"  En hexadécimal: 0x{firered_indices[0]:03X} - 0x{firered_indices[-1]:03X}")
                print(f"  Nombre de tiles: {len(firered_indices)}")
                print()
                print(f"  💡 Pour src/tileset_anims.c, utilise:")
                print(f"     TILE_OFFSET_4BPP({firered_indices[0]})")
                print(f"     avec {len(firered_indices)} * TILE_SIZE_4BPP")
            else:
                print(f"  ⚠ Plage NON continue!")
                print(f"  Min: {firered_indices[0]} (0x{firered_indices[0]:03X})")
                print(f"  Max: {firered_indices[-1]} (0x{firered_indices[-1]:03X})")
                print()
                print("  Les tiles ne sont pas consécutifs dans FireRed.")
                print("  Tu dois les réorganiser dans ton tiles.png pour que les animations fonctionnent.")
                print()
                print("  Tiles trouvés aux positions FireRed:")
                for fr_idx in firered_indices:
                    print(f"    - {fr_idx} (0x{fr_idx:03X})")

    if not_found:
        print()
        print("⚠ TILES NON TROUVÉS DANS FIRERED:")
        for emerald_idx in not_found:
            print(f"  - Emerald {emerald_idx} (0x{emerald_idx:03X})")
        print()
        print("  Ces tiles sont manquants dans ton primary tileset FireRed.")
        print("  Tu dois les copier depuis Emerald pour que les animations fonctionnent.")

    print()
    print("=" * 70)

if __name__ == "__main__":
    main()
