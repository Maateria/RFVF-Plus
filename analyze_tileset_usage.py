#!/usr/bin/env python3
"""
Analyse l'utilisation des tiles dans metatiles.bin pour voir
quels tiles sont vraiment utilisés et lesquels peuvent être supprimés.

Usage:
    python analyze_tileset_usage.py <tileset_path>
"""

import sys
import struct
from pathlib import Path
from collections import defaultdict

def analyze_tile_usage(metatiles_path: Path, max_tile_id: int = 383):
    """
    Analyse metatiles.bin et retourne des statistiques sur l'utilisation des tiles.
    """
    with open(metatiles_path, 'rb') as f:
        data = f.read()

    num_metatiles = len(data) // 8

    # Compteur d'utilisation de chaque tile
    tile_usage = defaultdict(int)
    tiles_over_limit = defaultdict(list)  # tile_id -> liste des metatiles qui l'utilisent

    for i in range(num_metatiles):
        offset = i * 8
        for j in range(4):
            tile_offset = offset + j * 2
            tile_data = struct.unpack('<H', data[tile_offset:tile_offset+2])[0]

            # Extraire tile ID et flags
            tile_id = tile_data & 0x3FF
            palette = (tile_data >> 12) & 0xF
            h_flip = (tile_data >> 10) & 1
            v_flip = (tile_data >> 11) & 1

            tile_usage[tile_id] += 1

            if tile_id > max_tile_id:
                tiles_over_limit[tile_id].append({
                    'metatile': i,
                    'position': j,
                    'palette': palette,
                    'h_flip': h_flip,
                    'v_flip': v_flip
                })

    return tile_usage, tiles_over_limit, num_metatiles

def main():
    if len(sys.argv) < 2:
        print("Usage: python analyze_tileset_usage.py <tileset_path>")
        print("\nExemple:")
        print("  python analyze_tileset_usage.py data/tilesets/secondary/lilycove_emerald_raw")
        sys.exit(1)

    tileset_path = Path(sys.argv[1])

    if not tileset_path.exists():
        print(f"Erreur: Dossier introuvable: {tileset_path}")
        sys.exit(1)

    metatiles_path = tileset_path / "metatiles.bin"

    if not metatiles_path.exists():
        print(f"Erreur: {metatiles_path} introuvable")
        sys.exit(1)

    print("=" * 70)
    print("ANALYSE DE L'UTILISATION DES TILES")
    print("=" * 70)
    print(f"Tileset: {tileset_path}")
    print()

    tile_usage, tiles_over_limit, num_metatiles = analyze_tile_usage(metatiles_path)

    print(f"Nombre total de metatiles: {num_metatiles}")
    print(f"Nombre de tiles uniques utilisés: {len(tile_usage)}")
    print(f"Range de tiles utilisés: {min(tile_usage.keys())} - {max(tile_usage.keys())}")
    print()

    if tiles_over_limit:
        print(f"⚠ TILES HORS LIMITES (> 383): {len(tiles_over_limit)} tiles")
        print()
        print("Détails des tiles > 383:")
        print("-" * 70)

        for tile_id in sorted(tiles_over_limit.keys()):
            usages = tiles_over_limit[tile_id]
            print(f"\nTile {tile_id}: utilisé {len(usages)} fois")

            # Montrer les 5 premiers usages
            for usage in usages[:5]:
                print(f"  - Metatile {usage['metatile']}, position {usage['position']}, "
                      f"palette {usage['palette']}, "
                      f"flip: H={usage['h_flip']} V={usage['v_flip']}")

            if len(usages) > 5:
                print(f"  ... et {len(usages) - 5} autres utilisations")

        print()
        print("=" * 70)
        print(f"TOTAL: {sum(len(usages) for usages in tiles_over_limit.values())} "
              f"références à des tiles > 383")
        print("=" * 70)
    else:
        print("✓ Aucun tile > 383 trouvé!")
        print("  Le tileset peut être utilisé tel quel avec 384 tiles max.")

    # Statistiques sur les tiles les plus/moins utilisés
    print()
    print("Tiles les plus utilisés:")
    top_tiles = sorted(tile_usage.items(), key=lambda x: x[1], reverse=True)[:10]
    for tile_id, count in top_tiles:
        status = "⚠ HORS LIMITES" if tile_id > 383 else "OK"
        print(f"  Tile {tile_id}: {count} utilisations [{status}]")

    # Tiles non utilisés dans la range 0-383
    used_tiles_in_range = set(t for t in tile_usage.keys() if t <= 383)
    all_possible_tiles = set(range(384))
    unused_tiles = all_possible_tiles - used_tiles_in_range

    print()
    print(f"Tiles non utilisés dans la range 0-383: {len(unused_tiles)} tiles")
    if len(unused_tiles) < 50:
        print(f"  Liste: {sorted(unused_tiles)}")

if __name__ == "__main__":
    main()
