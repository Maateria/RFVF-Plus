#!/usr/bin/env python3
"""
Analyse metatiles.bin pour identifier les tiles utilisés et créer
une version réduite de tiles.png (max 384 tiles pour FireRed secondary)

Utilise ImageMagick au lieu de PIL pour la manipulation d'images.

Usage:
    python reduce_tileset_tiles_magick.py <tileset_path> [--max-tiles 384]

Exemple:
    python reduce_tileset_tiles_magick.py data/tilesets/secondary/lilycove
"""

import sys
import struct
import subprocess
import tempfile
from pathlib import Path

def analyze_metatiles(metatiles_bin_path: Path) -> set:
    """
    Analyse metatiles.bin et retourne l'ensemble des IDs de tiles utilisés.

    Format metatile.bin:
    - Chaque metatile = 8 octets (4 tiles de 2 octets chacun)
    - Chaque tile = 2 octets (tile_id en little-endian avec flip bits)
    """
    with open(metatiles_bin_path, 'rb') as f:
        data = f.read()

    used_tiles = set()
    num_metatiles = len(data) // 8

    print(f"Analyse de {num_metatiles} metatiles...")

    for i in range(num_metatiles):
        offset = i * 8
        # Chaque metatile a 4 tiles (2 octets chacun)
        for j in range(4):
            tile_offset = offset + j * 2
            tile_data = struct.unpack('<H', data[tile_offset:tile_offset+2])[0]

            # Les 10 bits de poids faible = tile ID
            # Les 6 bits de poids fort = flip/palette
            tile_id = tile_data & 0x3FF  # Masque pour garder les 10 bits de droite
            used_tiles.add(tile_id)

    return used_tiles

def create_tile_mapping(used_tiles: set, max_tiles: int) -> dict:
    """
    Crée un mapping: ancien_tile_id -> nouveau_tile_id
    Garde seulement les tiles utilisés, jusqu'à max_tiles
    """
    # Trier les tiles utilisés
    sorted_tiles = sorted(used_tiles)

    if len(sorted_tiles) > max_tiles:
        print(f"⚠ ATTENTION: {len(sorted_tiles)} tiles utilisés, mais max = {max_tiles}")
        print(f"   Seuls les {max_tiles} premiers tiles seront conservés")
        sorted_tiles = sorted_tiles[:max_tiles]

    # Créer le mapping
    tile_mapping = {}
    for new_id, old_id in enumerate(sorted_tiles):
        tile_mapping[old_id] = new_id

    return tile_mapping

def get_image_dimensions(image_path: Path) -> tuple:
    """Récupère les dimensions de l'image avec ImageMagick"""
    result = subprocess.run(
        ['identify', '-format', '%w,%h', str(image_path)],
        capture_output=True,
        text=True,
        check=True
    )
    width, height = map(int, result.stdout.strip().split(','))
    return width, height

def create_reduced_tileset_magick(
    input_png: Path,
    output_png: Path,
    tile_mapping: dict,
    tile_size: int = 8
):
    """
    Crée une nouvelle image tiles.png avec seulement les tiles utilisés.
    Utilise ImageMagick pour la manipulation d'images.
    """
    width, height = get_image_dimensions(input_png)

    # Calculer dimensions
    tiles_per_row = width // tile_size
    total_tiles = (width // tile_size) * (height // tile_size)

    print(f"Image originale: {width}x{height} = {total_tiles} tiles ({tiles_per_row} par ligne)")

    # Nombre de tiles dans la nouvelle image
    num_new_tiles = len(tile_mapping)
    new_tiles_per_row = tiles_per_row  # Garder la même largeur
    new_height = ((num_new_tiles + new_tiles_per_row - 1) // new_tiles_per_row) * tile_size

    print(f"Nouvelle image: {width}x{new_height} = {num_new_tiles} tiles")

    # Créer un fichier temporaire avec les commandes ImageMagick
    with tempfile.TemporaryDirectory() as tmpdir:
        tmpdir_path = Path(tmpdir)

        # Extraire chaque tile utilisé
        tile_files = []
        for old_id, new_id in sorted(tile_mapping.items(), key=lambda x: x[1]):
            # Position de l'ancien tile
            old_x = (old_id % tiles_per_row) * tile_size
            old_y = (old_id // tiles_per_row) * tile_size

            # Vérifier que le tile est dans les limites de l'image
            if old_y + tile_size > height or old_x + tile_size > width:
                print(f"⚠ Warning: Tile {old_id} est hors limites ({old_x},{old_y}), ignoré")
                continue

            # Extraire le tile
            tile_file = tmpdir_path / f"tile_{new_id:04d}.png"
            tile_files.append(tile_file)

            subprocess.run([
                'convert',
                str(input_png),
                '-crop', f'{tile_size}x{tile_size}+{old_x}+{old_y}',
                '+repage',
                str(tile_file)
            ], check=True, capture_output=True)

        # Créer une nouvelle image avec tous les tiles
        # Utiliser montage pour arranger les tiles en grille
        subprocess.run([
            'montage',
            *[str(f) for f in tile_files],
            '-tile', f'{tiles_per_row}x',
            '-geometry', f'{tile_size}x{tile_size}+0+0',
            '-background', 'none',
            str(output_png)
        ], check=True, capture_output=True)

    print(f"✓ Nouvelle image sauvegardée: {output_png}")

def update_metatiles_bin(
    metatiles_path: Path,
    output_path: Path,
    tile_mapping: dict
):
    """
    Met à jour metatiles.bin avec les nouveaux IDs de tiles.
    """
    with open(metatiles_path, 'rb') as f:
        data = bytearray(f.read())

    num_metatiles = len(data) // 8

    for i in range(num_metatiles):
        offset = i * 8
        for j in range(4):
            tile_offset = offset + j * 2
            tile_data = struct.unpack('<H', data[tile_offset:tile_offset+2])[0]

            # Extraire tile ID et flags
            old_tile_id = tile_data & 0x3FF
            flags = tile_data & 0xFC00  # Flip/palette bits

            # Remapper le tile ID
            if old_tile_id in tile_mapping:
                new_tile_id = tile_mapping[old_tile_id]
                new_tile_data = new_tile_id | flags
                struct.pack_into('<H', data, tile_offset, new_tile_data)
            else:
                # Tile non utilisé (ne devrait pas arriver)
                print(f"⚠ Warning: Tile {old_tile_id} dans metatile {i} non trouvé dans mapping")

    # Sauvegarder
    with open(output_path, 'wb') as f:
        f.write(data)

    print(f"✓ metatiles.bin mis à jour: {output_path}")

def main():
    if len(sys.argv) < 2:
        print("Usage: python reduce_tileset_tiles_magick.py <tileset_path> [--max-tiles 384]")
        print("\nExemple:")
        print("  python reduce_tileset_tiles_magick.py data/tilesets/secondary/lilycove")
        sys.exit(1)

    tileset_path = Path(sys.argv[1])
    max_tiles = 384

    # Parse --max-tiles argument
    if '--max-tiles' in sys.argv:
        idx = sys.argv.index('--max-tiles')
        if idx + 1 < len(sys.argv):
            max_tiles = int(sys.argv[idx + 1])

    if not tileset_path.exists():
        print(f"Erreur: Dossier introuvable: {tileset_path}")
        sys.exit(1)

    metatiles_path = tileset_path / "metatiles.bin"
    tiles_png_path = tileset_path / "tiles.png"

    if not metatiles_path.exists():
        print(f"Erreur: {metatiles_path} introuvable")
        sys.exit(1)

    if not tiles_png_path.exists():
        print(f"Erreur: {tiles_png_path} introuvable")
        sys.exit(1)

    print("=" * 60)
    print("RÉDUCTION DU TILESET")
    print("=" * 60)
    print(f"Tileset: {tileset_path}")
    print(f"Max tiles: {max_tiles}")
    print()

    # 1. Analyser les tiles utilisés
    print("Étape 1: Analyse des metatiles...")
    used_tiles = analyze_metatiles(metatiles_path)
    print(f"✓ {len(used_tiles)} tiles uniques utilisés")
    print()

    # 2. Créer le mapping
    print("Étape 2: Création du mapping...")
    tile_mapping = create_tile_mapping(used_tiles, max_tiles)
    print(f"✓ Mapping créé: {len(tile_mapping)} tiles")
    print()

    # 3. Créer backups
    print("Étape 3: Création des backups...")
    backup_suffix = ".original"

    tiles_backup = tiles_png_path.with_suffix(tiles_png_path.suffix + backup_suffix)
    if not tiles_backup.exists():
        import shutil
        shutil.copy(tiles_png_path, tiles_backup)
        print(f"✓ Backup: {tiles_backup}")

    metatiles_backup = metatiles_path.with_suffix(metatiles_path.suffix + backup_suffix)
    if not metatiles_backup.exists():
        import shutil
        shutil.copy(metatiles_path, metatiles_backup)
        print(f"✓ Backup: {metatiles_backup}")
    print()

    # 4. Créer la nouvelle image
    print("Étape 4: Création de la nouvelle image tiles.png...")
    try:
        create_reduced_tileset_magick(tiles_backup, tiles_png_path, tile_mapping)
    except subprocess.CalledProcessError as e:
        print(f"Erreur ImageMagick: {e}")
        print(f"stdout: {e.stdout if hasattr(e, 'stdout') else 'N/A'}")
        print(f"stderr: {e.stderr if hasattr(e, 'stderr') else 'N/A'}")
        sys.exit(1)
    print()

    # 5. Mettre à jour metatiles.bin
    print("Étape 5: Mise à jour de metatiles.bin...")
    update_metatiles_bin(metatiles_backup, metatiles_path, tile_mapping)
    print()

    print("=" * 60)
    print("✓ RÉDUCTION TERMINÉE!")
    print("=" * 60)
    print(f"Tiles originaux: {len(used_tiles)}")
    print(f"Tiles conservés: {len(tile_mapping)}")
    print(f"\nFichiers mis à jour:")
    print(f"  - {tiles_png_path}")
    print(f"  - {metatiles_path}")
    print(f"\nBackups:")
    print(f"  - {tiles_backup}")
    print(f"  - {metatiles_backup}")
    print()
    print("Vous pouvez maintenant:")
    print("  1. Ouvrir le tileset dans Porymap pour vérifier")
    print("  2. Compiler avec: make leafgreen")

if __name__ == "__main__":
    main()
