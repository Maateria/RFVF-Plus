#!/usr/bin/env python3
"""
Réduit un tileset à exactement 384 tiles en croppant l'image
et en remappant les tiles hors limites dans metatiles.bin

Usage:
    python crop_tileset_384.py <tileset_path>

Exemple:
    python crop_tileset_384.py data/tilesets/secondary/lilycove_temp
"""

import sys
import struct
import subprocess
from pathlib import Path

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

def crop_tileset(input_png: Path, output_png: Path, max_tiles: int = 384, tile_size: int = 8):
    """
    Crop le tileset pour garder seulement max_tiles tiles.
    """
    width, height = get_image_dimensions(input_png)
    tiles_per_row = width // tile_size
    total_tiles = (width // tile_size) * (height // tile_size)

    print(f"Image originale: {width}x{height} = {total_tiles} tiles ({tiles_per_row} tiles/ligne)")

    if total_tiles <= max_tiles:
        print(f"✓ L'image a déjà {total_tiles} tiles (<= {max_tiles}), aucune réduction nécessaire")
        import shutil
        shutil.copy(input_png, output_png)
        return

    # Calculer nouvelle hauteur
    new_rows = (max_tiles + tiles_per_row - 1) // tiles_per_row
    new_height = new_rows * tile_size

    print(f"Nouvelle image: {width}x{new_height} = {max_tiles} tiles")

    # Cropper l'image avec ImageMagick en préservant le format indexed 4bpp
    subprocess.run([
        'convert',
        str(input_png),
        '-crop', f'{width}x{new_height}+0+0',
        '+repage',
        '-colors', '16',  # Préserver 16 couleurs
        '-type', 'Palette',  # Format indexé
        str(output_png)
    ], check=True, capture_output=True)

    print(f"✓ Image croppée: {output_png}")

def remap_metatiles(metatiles_path: Path, output_path: Path, max_tile_id: int = 383):
    """
    Met à jour metatiles.bin pour remapper les tiles > max_tile_id vers tile 0
    """
    with open(metatiles_path, 'rb') as f:
        data = bytearray(f.read())

    num_metatiles = len(data) // 8
    num_remapped = 0

    for i in range(num_metatiles):
        offset = i * 8
        for j in range(4):
            tile_offset = offset + j * 2
            tile_data = struct.unpack('<H', data[tile_offset:tile_offset+2])[0]

            # Extraire tile ID et flags
            tile_id = tile_data & 0x3FF
            flags = tile_data & 0xFC00

            # Remapper si nécessaire
            if tile_id > max_tile_id:
                new_tile_id = 0  # Remapper vers tile 0 (transparent/vide)
                new_tile_data = new_tile_id | flags
                struct.pack_into('<H', data, tile_offset, new_tile_data)
                num_remapped += 1

    # Sauvegarder
    with open(output_path, 'wb') as f:
        f.write(data)

    if num_remapped > 0:
        print(f"✓ metatiles.bin mis à jour: {num_remapped} références de tiles remappées vers tile 0")
    else:
        print(f"✓ metatiles.bin vérifié: aucun tile hors limites trouvé")

def main():
    if len(sys.argv) < 2:
        print("Usage: python crop_tileset_384.py <tileset_path>")
        print("\nExemple:")
        print("  python crop_tileset_384.py data/tilesets/secondary/lilycove_temp")
        sys.exit(1)

    tileset_path = Path(sys.argv[1])
    max_tiles = 384

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
    print("RÉDUCTION DU TILESET À 384 TILES")
    print("=" * 60)
    print(f"Tileset: {tileset_path}")
    print()

    # 1. Créer backups
    print("Étape 1: Création des backups...")
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

    # 2. Cropper l'image à 384 tiles
    print("Étape 2: Crop de l'image à 384 tiles...")
    try:
        crop_tileset(tiles_backup, tiles_png_path, max_tiles)
    except subprocess.CalledProcessError as e:
        print(f"Erreur ImageMagick: {e}")
        if hasattr(e, 'stderr'):
            print(f"stderr: {e.stderr.decode()}")
        sys.exit(1)
    print()

    # 3. Remapper metatiles.bin
    print("Étape 3: Remapping des tiles hors limites dans metatiles.bin...")
    remap_metatiles(metatiles_backup, metatiles_path, max_tiles - 1)
    print()

    print("=" * 60)
    print("✓ RÉDUCTION TERMINÉE!")
    print("=" * 60)
    print(f"\nFichiers mis à jour:")
    print(f"  - {tiles_png_path} (384 tiles max)")
    print(f"  - {metatiles_path} (tiles hors limites remappés)")
    print(f"\nBackups:")
    print(f"  - {tiles_backup}")
    print(f"  - {metatiles_backup}")
    print()
    print("Vous pouvez maintenant:")
    print("  1. Ouvrir le tileset dans Porymap pour vérifier")
    print("  2. Compiler avec: make leafgreen")

if __name__ == "__main__":
    main()
