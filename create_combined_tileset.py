#!/usr/bin/env python3
"""
Crée un tileset primaire combiné (primary + secondary) pour contourner
la limite de 384 tiles du tileset secondaire.

Stratégie:
1. Combiner tiles.png du primaire et du secondaire
2. Combiner les palettes
3. Combiner metatiles.bin (primaire + secondaire)
4. Remapper les IDs de tiles dans map.bin pour correspondre au nouveau tileset
5. Créer un tileset secondaire vide/minimal

Usage:
    python create_combined_tileset.py <primary_path> <secondary_path> <output_path> <map_bin_path>

Exemple:
    python create_combined_tileset.py \\
        data/tilesets/primary/hoenn_general \\
        data/tilesets/secondary/lilycove_emerald_raw \\
        data/tilesets/primary/lilycove_combined \\
        data/layouts/LilycoveCity/map.bin
"""

import sys
import struct
import shutil
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

def combine_tiles_images(primary_tiles: Path, secondary_tiles: Path, output_tiles: Path):
    """Combine deux images tiles.png verticalement avec ImageMagick"""

    primary_width, primary_height = get_image_dimensions(primary_tiles)
    secondary_width, secondary_height = get_image_dimensions(secondary_tiles)

    # Les deux images doivent avoir la même largeur
    if primary_width != secondary_width:
        print(f"⚠ Avertissement: largeurs différentes (primary: {primary_width}, secondary: {secondary_width})")
        width = max(primary_width, secondary_width)
    else:
        width = primary_width

    # Combiner verticalement avec ImageMagick (append)
    subprocess.run([
        'convert',
        str(primary_tiles),
        str(secondary_tiles),
        '-append',  # Coller verticalement
        'PNG8:' + str(output_tiles)  # Format PNG8 pour conserver les couleurs indexées
    ], check=True, capture_output=True)

    primary_tiles_count = (primary_width // 8) * (primary_height // 8)
    secondary_tiles_count = (secondary_width // 8) * (secondary_height // 8)
    combined_height = primary_height + secondary_height

    print(f"✓ Images combinées:")
    print(f"  - Primary: {primary_width}x{primary_height} ({primary_tiles_count} tiles)")
    print(f"  - Secondary: {secondary_width}x{secondary_height} ({secondary_tiles_count} tiles)")
    print(f"  - Combiné: {width}x{combined_height} ({primary_tiles_count + secondary_tiles_count} tiles)")
    print(f"  - Offset secondaire: tile {primary_tiles_count}")

    return primary_tiles_count

def combine_palettes(primary_path: Path, secondary_path: Path, output_path: Path):
    """Copie et combine les palettes"""

    output_palettes = output_path / "palettes"
    output_palettes.mkdir(exist_ok=True)

    # Copier les palettes du primaire
    primary_palettes = primary_path / "palettes"
    if primary_palettes.exists():
        for pal_file in primary_palettes.glob("*.pal"):
            shutil.copy(pal_file, output_palettes / pal_file.name)
        for pal_file in primary_palettes.glob("*.gbapal"):
            shutil.copy(pal_file, output_palettes / pal_file.name)

    # Copier les palettes du secondaire (en évitant les conflits)
    secondary_palettes = secondary_path / "palettes"
    if secondary_palettes.exists():
        for pal_file in secondary_palettes.glob("*.pal"):
            dest = output_palettes / pal_file.name
            if not dest.exists():
                shutil.copy(pal_file, dest)
        for pal_file in secondary_palettes.glob("*.gbapal"):
            dest = output_palettes / pal_file.name
            if not dest.exists():
                shutil.copy(pal_file, dest)

    print(f"✓ Palettes combinées dans {output_palettes}")

def combine_metatiles(primary_path: Path, secondary_path: Path, output_path: Path, tile_offset: int):
    """
    Combine metatiles.bin du primaire et secondaire.
    Ajuste les IDs de tiles du secondaire en ajoutant tile_offset.
    """

    primary_metatiles = primary_path / "metatiles.bin"
    secondary_metatiles = secondary_path / "metatiles.bin"
    output_metatiles = output_path / "metatiles.bin"

    # Lire les metatiles du primaire
    with open(primary_metatiles, 'rb') as f:
        primary_data = bytearray(f.read())

    # Lire les metatiles du secondaire
    with open(secondary_metatiles, 'rb') as f:
        secondary_data = bytearray(f.read())

    # Ajuster les IDs de tiles dans les metatiles du secondaire
    num_secondary_metatiles = len(secondary_data) // 8

    for i in range(num_secondary_metatiles):
        offset = i * 8
        for j in range(4):  # 4 tiles par metatile
            tile_offset_in_metatile = offset + j * 2
            tile_data = struct.unpack('<H', secondary_data[tile_offset_in_metatile:tile_offset_in_metatile+2])[0]

            # Extraire tile ID et flags
            tile_id = tile_data & 0x3FF  # 10 bits
            flags = tile_data & 0xFC00   # 6 bits de flags

            # Ajouter l'offset au tile ID
            new_tile_id = tile_id + tile_offset

            # Vérifier que le nouveau ID ne dépasse pas 1023 (limite 10 bits)
            if new_tile_id > 1023:
                print(f"⚠ Warning: Tile ID {new_tile_id} dépasse 1023 (metatile {i}, pos {j})")
                new_tile_id = 0  # Mettre à 0 si dépassement

            # Reconstruire le tile_data
            new_tile_data = new_tile_id | flags
            struct.pack_into('<H', secondary_data, tile_offset_in_metatile, new_tile_data)

    # Combiner les deux
    combined_data = primary_data + secondary_data

    # Sauvegarder
    with open(output_metatiles, 'wb') as f:
        f.write(combined_data)

    primary_count = len(primary_data) // 8
    secondary_count = len(secondary_data) // 8

    print(f"✓ Metatiles combinés:")
    print(f"  - Primary: {primary_count} metatiles")
    print(f"  - Secondary: {secondary_count} metatiles (IDs ajustés +{tile_offset})")
    print(f"  - Total: {primary_count + secondary_count} metatiles")

    return primary_count

def combine_metatile_attributes(primary_path: Path, secondary_path: Path, output_path: Path):
    """Combine metatile_attributes.bin du primaire et secondaire"""

    primary_attrs = primary_path / "metatile_attributes.bin"
    secondary_attrs = secondary_path / "metatile_attributes.bin"
    output_attrs = output_path / "metatile_attributes.bin"

    # Lire et combiner
    with open(primary_attrs, 'rb') as f:
        primary_data = f.read()

    with open(secondary_attrs, 'rb') as f:
        secondary_data = f.read()

    combined_data = primary_data + secondary_data

    # Sauvegarder
    with open(output_attrs, 'wb') as f:
        f.write(combined_data)

    # Déterminer le format (1, 2 ou 4 octets par metatile)
    primary_metatiles = len(primary_data) // 8  # Approximation
    bytes_per_metatile = len(primary_data) // max(1, (len((primary_path / "metatiles.bin").read_bytes()) // 8))

    print(f"✓ Attributs combinés: {len(combined_data)} octets")

def remap_map_bin(map_bin_path: Path, metatile_offset: int):
    """
    Remapper les IDs de metatiles dans map.bin.
    Tous les metatiles qui référencent le secondaire doivent être décalés.

    En fait, dans map.bin, les metatiles sont déjà numérotés de manière absolue,
    donc on n'a PAS besoin de remapper map.bin - il suffit de s'assurer que
    les metatiles sont dans le bon ordre dans le tileset combiné.

    MAIS: il faut vérifier si map.bin utilise des indices basés sur 0x200 (512)
    pour marquer le début du secondaire.
    """

    # Backup
    backup_path = map_bin_path.with_suffix('.bin.before_remap')
    if not backup_path.exists():
        shutil.copy(map_bin_path, backup_path)
        print(f"✓ Backup de map.bin: {backup_path}")

    with open(map_bin_path, 'rb') as f:
        map_data = bytearray(f.read())

    # Chaque entrée dans map.bin = 2 octets (metatile ID + attributs)
    num_entries = len(map_data) // 2

    changed = 0

    for i in range(num_entries):
        offset = i * 2
        metatile_data = struct.unpack('<H', map_data[offset:offset+2])[0]

        # Les metatiles sont généralement numérotés comme suit:
        # - 0x000-0x1FF: primaire (0-511)
        # - 0x200-0x3FF: secondaire (512-1023)
        #
        # Dans un tileset combiné, on veut garder la même numérotation
        # SAUF si le jeu attend un offset spécifique

        # Pour FireRed, généralement pas besoin de remapper car les IDs
        # sont déjà absolus. Mais on vérifie:

        metatile_id = metatile_data & 0x3FF  # 10 bits pour l'ID
        attributes = metatile_data & 0xFC00  # 6 bits d'attributs

        # Si metatile_id >= 512, c'est un metatile du secondaire
        # Dans le tileset combiné, il faut l'ajuster
        if metatile_id >= 512:
            # Ajuster: le secondaire commence maintenant après le primaire
            new_metatile_id = metatile_id - 512 + metatile_offset

            if new_metatile_id > 1023:
                print(f"⚠ Warning: Metatile {metatile_id} -> {new_metatile_id} dépasse 1023")
                new_metatile_id = 0

            new_metatile_data = new_metatile_id | attributes
            struct.pack_into('<H', map_data, offset, new_metatile_data)
            changed += 1

    # Sauvegarder
    with open(map_bin_path, 'wb') as f:
        f.write(map_data)

    if changed > 0:
        print(f"✓ map.bin remappé: {changed} metatiles ajustés")
    else:
        print(f"✓ map.bin vérifié: aucun remapping nécessaire")

def main():
    if len(sys.argv) < 5:
        print("Usage: python create_combined_tileset.py <primary_path> <secondary_path> <output_path> <map_bin_path>")
        print("\nExemple:")
        print("  python create_combined_tileset.py \\")
        print("      data/tilesets/primary/hoenn_general \\")
        print("      data/tilesets/secondary/lilycove_emerald_raw \\")
        print("      data/tilesets/primary/lilycove_combined \\")
        print("      data/layouts/LilycoveCity/map.bin")
        sys.exit(1)

    primary_path = Path(sys.argv[1])
    secondary_path = Path(sys.argv[2])
    output_path = Path(sys.argv[3])
    map_bin_path = Path(sys.argv[4])

    if not primary_path.exists():
        print(f"Erreur: Tileset primaire introuvable: {primary_path}")
        sys.exit(1)

    if not secondary_path.exists():
        print(f"Erreur: Tileset secondaire introuvable: {secondary_path}")
        sys.exit(1)

    if not map_bin_path.exists():
        print(f"Erreur: map.bin introuvable: {map_bin_path}")
        sys.exit(1)

    print("=" * 70)
    print("CRÉATION D'UN TILESET PRIMAIRE COMBINÉ")
    print("=" * 70)
    print(f"Primary:   {primary_path}")
    print(f"Secondary: {secondary_path}")
    print(f"Output:    {output_path}")
    print(f"Map.bin:   {map_bin_path}")
    print()

    # Créer le dossier de sortie
    output_path.mkdir(parents=True, exist_ok=True)

    # 1. Combiner les tiles.png
    print("Étape 1: Combinaison des images tiles.png...")
    tile_offset = combine_tiles_images(
        primary_path / "tiles.png",
        secondary_path / "tiles.png",
        output_path / "tiles.png"
    )
    print()

    # 2. Combiner les palettes
    print("Étape 2: Combinaison des palettes...")
    combine_palettes(primary_path, secondary_path, output_path)
    print()

    # 3. Combiner les metatiles.bin
    print("Étape 3: Combinaison des metatiles...")
    metatile_offset = combine_metatiles(primary_path, secondary_path, output_path, tile_offset)
    print()

    # 4. Combiner les metatile_attributes.bin
    print("Étape 4: Combinaison des attributs...")
    combine_metatile_attributes(primary_path, secondary_path, output_path)
    print()

    # 5. Remapper map.bin
    print("Étape 5: Remapping de map.bin...")
    remap_map_bin(map_bin_path, metatile_offset)
    print()

    print("=" * 70)
    print("✓ TILESET COMBINÉ CRÉÉ AVEC SUCCÈS!")
    print("=" * 70)
    print(f"\nTileset créé: {output_path}")
    print(f"  - Tiles offset: {tile_offset}")
    print(f"  - Metatiles offset: {metatile_offset}")
    print()
    print("Prochaines étapes:")
    print("  1. Mettre à jour layouts.json pour utiliser le nouveau tileset primaire")
    print("  2. Créer un tileset secondaire vide ou minimal")
    print("  3. Compiler avec make leafgreen")

if __name__ == "__main__":
    main()
