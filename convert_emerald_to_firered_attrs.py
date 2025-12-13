#!/usr/bin/env python3
"""
Convertit metatile_attributes.bin d'Emerald (1 octet/metatile)
vers le format FireRed/Porymap 5.x (2 octets/metatile)

Format Emerald (1 octet par metatile):
  - behavior (8 bits)

Format FireRed/Porymap 5.x (2 octets par metatile):
  - behavior (8 bits)
  - layerType (8 bits)
"""

import sys
from pathlib import Path

def convert_emerald_to_firered(input_file: Path, output_file: Path = None):
    """Convertit metatile_attributes.bin d'Emerald vers FireRed"""

    if output_file is None:
        output_file = input_file

    print(f"Lecture de: {input_file}")

    # Lire l'ancien format Emerald
    with open(input_file, 'rb') as f:
        emerald_data = f.read()

    num_metatiles = len(emerald_data)
    print(f"Nombre de metatiles: {num_metatiles}")
    print(f"Taille format Emerald: {len(emerald_data)} octets (1 octet/metatile)")

    # Convertir vers le format FireRed (2 octets)
    firered_data = bytearray()

    for behavior in emerald_data:
        # Format FireRed (2 octets):
        # - behavior (8 bits)
        firered_data.append(behavior)

        # - layerType (8 bits)
        # Valeurs possibles:
        # 0x00 = METATILE_LAYER_TYPE_NORMAL
        # 0x01 = METATILE_LAYER_TYPE_COVERED
        # 0x02 = METATILE_LAYER_TYPE_SPLIT

        # Par défaut, on met NORMAL (0x00)
        # Les metatiles d'eau/ponts devraient être SPLIT, mais on ne peut pas
        # le détecter automatiquement de manière fiable
        firered_data.append(0x00)

    print(f"Taille format FireRed: {len(firered_data)} octets (2 octets/metatile)")
    print(f"Divisible par 2? {len(firered_data) % 2 == 0}")

    # Backup de l'original
    if output_file == input_file:
        backup_file = input_file.with_suffix('.bin.emerald')
        if not backup_file.exists():
            import shutil
            shutil.copy(input_file, backup_file)
            print(f"Backup créé: {backup_file}")

    # Sauvegarder
    with open(output_file, 'wb') as f:
        f.write(firered_data)

    print(f"✓ Fichier converti: {output_file}")

    return output_file

def main():
    if len(sys.argv) < 2:
        print("Usage: python convert_emerald_to_firered_attrs.py <fichier_metatile_attributes.bin>")
        print("\nConvertit le format Emerald (1 octet/metatile) vers FireRed (2 octets/metatile)")
        print("\nExemple:")
        print("  python convert_emerald_to_firered_attrs.py data/tilesets/secondary/lilycove/metatile_attributes.bin")
        sys.exit(1)

    input_file = Path(sys.argv[1])

    if not input_file.exists():
        print(f"Erreur: Fichier introuvable: {input_file}")
        sys.exit(1)

    # Vérifier le format actuel
    file_size = input_file.stat().st_size

    # Essayer de détecter le format
    if file_size % 2 == 0:
        # Peut être déjà au format FireRed, vérifier avec metatiles.bin
        metatiles_file = input_file.parent / "metatiles.bin"
        if metatiles_file.exists():
            num_metatiles = metatiles_file.stat().st_size // 8
            bytes_per_metatile = file_size / num_metatiles

            if bytes_per_metatile == 2.0:
                print(f"⚠ Le fichier semble déjà au format FireRed (2 octets/metatile)")
                response = input("Voulez-vous quand même le convertir? (y/n): ")
                if response.lower() != 'y':
                    print("Conversion annulée")
                    sys.exit(0)
            elif bytes_per_metatile == 1.0:
                print(f"✓ Format Emerald détecté (1 octet/metatile)")

    # Convertir
    convert_emerald_to_firered(input_file)

    print("\n✓ Conversion terminée!")
    print("  Le fichier est maintenant compatible avec FireRed/Porymap 5.x")

if __name__ == "__main__":
    main()
