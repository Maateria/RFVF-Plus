#!/usr/bin/env python3
"""
Convertit metatile_attributes.bin de l'ancien format (1 octet/metatile)
vers le nouveau format Porymap 6.0.0 (4 octets/metatile)

Ancien format (1 octet par metatile):
  - behavior (8 bits)

Nouveau format (4 octets par metatile):
  - behavior (16 bits, little-endian)
  - terrainType (4 bits) + encounterType (4 bits) (8 bits total)
  - layerType (8 bits)
"""

import sys
from pathlib import Path

def convert_metatile_attributes(input_file: Path, output_file: Path = None):
    """Convertit metatile_attributes.bin vers le format Porymap 6"""

    if output_file is None:
        output_file = input_file.with_suffix('.bin.new')

    print(f"Lecture de: {input_file}")

    # Lire l'ancien format
    with open(input_file, 'rb') as f:
        old_data = f.read()

    num_metatiles = len(old_data)
    print(f"Nombre de metatiles: {num_metatiles}")
    print(f"Taille ancien format: {len(old_data)} octets (1 octet/metatile)")

    # Convertir vers le nouveau format
    new_data = bytearray()

    for i, behavior in enumerate(old_data):
        # Nouveau format (4 octets):
        # - behavior (16 bits) : on met l'ancien behavior sur 16 bits
        new_data.append(behavior)  # behavior low byte
        new_data.append(0x00)       # behavior high byte

        # - terrainType (4 bits) + encounterType (4 bits)
        new_data.append(0x00)       # Valeurs par défaut

        # - layerType (8 bits)
        new_data.append(0x00)       # METATILE_LAYER_TYPE_NORMAL par défaut

    print(f"Taille nouveau format: {len(new_data)} octets (4 octets/metatile)")
    print(f"Divisible par 4? {len(new_data) % 4 == 0}")

    # Sauvegarder
    with open(output_file, 'wb') as f:
        f.write(new_data)

    print(f"✓ Fichier converti: {output_file}")

    return output_file

def main():
    if len(sys.argv) < 2:
        print("Usage: python convert_metatile_attrs_to_porymap6.py <fichier_metatile_attributes.bin>")
        print("\nExemple:")
        print("  python convert_metatile_attrs_to_porymap6.py data/tilesets/secondary/lilycove/metatile_attributes.bin")
        sys.exit(1)

    input_file = Path(sys.argv[1])

    if not input_file.exists():
        print(f"Erreur: Fichier introuvable: {input_file}")
        sys.exit(1)

    # Backup de l'original
    backup_file = input_file.with_suffix('.bin.old_format')
    if not backup_file.exists():
        import shutil
        shutil.copy(input_file, backup_file)
        print(f"Backup créé: {backup_file}")

    # Convertir
    output_file = input_file  # Écraser l'original
    convert_metatile_attributes(input_file, output_file)

    print("\n✓ Conversion terminée!")
    print(f"  Original sauvegardé: {backup_file}")
    print(f"  Nouveau format: {output_file}")

if __name__ == "__main__":
    main()
