#!/usr/bin/env python3
"""
Script d'import de maps Hoenn depuis pokeemerald vers RFVF-PLUS
Usage: python import_hoenn_map.py <map_name>
Exemple: python import_hoenn_map.py LilycoveCity
"""

import sys
import os
import shutil
from pathlib import Path

# Chemins de base
POKEEMERALD_ROOT = Path("../pokeemerald")
RFVF_ROOT = Path(".")

def import_map(map_name):
    """Importe une map depuis pokeemerald"""

    print(f"🔄 Import de {map_name} depuis pokeemerald...")

    # 1. Copier les fichiers de layout (map.bin, border.bin)
    emerald_layout = POKEEMERALD_ROOT / "data" / "layouts" / map_name
    rfvf_layout = RFVF_ROOT / "data" / "layouts" / map_name

    if not emerald_layout.exists():
        print(f"❌ Erreur: {emerald_layout} n'existe pas dans pokeemerald")
        return False

    # Créer le dossier de destination si nécessaire
    rfvf_layout.mkdir(parents=True, exist_ok=True)

    # Copier map.bin et border.bin
    for filename in ["map.bin", "border.bin"]:
        src = emerald_layout / filename
        dst = rfvf_layout / filename
        if src.exists():
            shutil.copy2(src, dst)
            print(f"  ✅ Copié: {filename}")
        else:
            print(f"  ⚠️  Manquant: {filename}")

    # 2. Copier les metatiles du tileset hoenn_general
    print("\n🔄 Import des metatiles hoenn_general...")
    emerald_tileset = POKEEMERALD_ROOT / "data" / "tilesets" / "primary" / "general"
    rfvf_tileset = RFVF_ROOT / "data" / "tilesets" / "primary" / "hoenn_general"

    # Copier metatiles.bin et metatile_attributes.bin
    for filename in ["metatiles.bin", "metatile_attributes.bin"]:
        src = emerald_tileset / filename
        dst = rfvf_tileset / filename
        if src.exists():
            shutil.copy2(src, dst)
            print(f"  ✅ Copié: {filename}")
        else:
            print(f"  ⚠️  Manquant: {filename}")

    # 3. Copier les palettes primary
    print("\n🔄 Import des palettes hoenn_general...")
    emerald_palettes = emerald_tileset / "palettes"
    rfvf_palettes = rfvf_tileset / "palettes"

    if emerald_palettes.exists():
        # Copier tous les fichiers .gbapal
        for palette_file in emerald_palettes.glob("*.gbapal"):
            dst = rfvf_palettes / palette_file.name
            shutil.copy2(palette_file, dst)
            print(f"  ✅ Copié: {palette_file.name}")

        # Copier aussi les .pal si présents
        for palette_file in emerald_palettes.glob("*.pal"):
            dst = rfvf_palettes / palette_file.name
            shutil.copy2(palette_file, dst)
            print(f"  ✅ Copié: {palette_file.name}")
    else:
        print(f"  ⚠️  Dossier palettes manquant")

    # 4. Copier le tileset secondaire (ex: lilycove pour LilycoveCity)
    # Convertir le nom de map en minuscule et retirer "city" si présent
    secondary_name = map_name.lower().replace("city", "")
    emerald_secondary = POKEEMERALD_ROOT / "data" / "tilesets" / "secondary" / secondary_name
    rfvf_secondary = RFVF_ROOT / "data" / "tilesets" / "secondary" / secondary_name

    if emerald_secondary.exists():
        print(f"\n🔄 Import du tileset secondaire {secondary_name}...")
        rfvf_secondary.mkdir(parents=True, exist_ok=True)

        # Copier metatiles, attributs et tiles
        for filename in ["metatiles.bin", "metatile_attributes.bin", "tiles.png"]:
            src = emerald_secondary / filename
            dst = rfvf_secondary / filename
            if src.exists():
                shutil.copy2(src, dst)
                print(f"  ✅ Copié: {filename}")

        # Copier les palettes
        emerald_sec_palettes = emerald_secondary / "palettes"
        rfvf_sec_palettes = rfvf_secondary / "palettes"

        if emerald_sec_palettes.exists():
            rfvf_sec_palettes.mkdir(parents=True, exist_ok=True)
            for palette_file in emerald_sec_palettes.glob("*.gbapal"):
                dst = rfvf_sec_palettes / palette_file.name
                shutil.copy2(palette_file, dst)
                print(f"  ✅ Copié palette: {palette_file.name}")
            for palette_file in emerald_sec_palettes.glob("*.pal"):
                dst = rfvf_sec_palettes / palette_file.name
                shutil.copy2(palette_file, dst)
                print(f"  ✅ Copié palette: {palette_file.name}")
    else:
        print(f"\n⚠️  Pas de tileset secondaire {secondary_name} trouvé")

    print(f"\n✅ Import de {map_name} terminé !")
    print(f"\n📝 Prochaines étapes:")
    print(f"  1. Ouvre Porymap")
    print(f"  2. Ouvre la map {map_name}")
    print(f"  3. Vérifie que les tiles s'affichent correctement")
    print(f"  4. Compile avec 'wsl make -j4'")
    print(f"  5. Teste dans l'émulateur")

    return True

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python import_hoenn_map.py <map_name>")
        print("Exemple: python import_hoenn_map.py LilycoveCity")
        sys.exit(1)

    map_name = sys.argv[1]

    # Vérifier que pokeemerald existe
    if not POKEEMERALD_ROOT.exists():
        print(f"❌ Erreur: Le dossier pokeemerald n'existe pas à {POKEEMERALD_ROOT.absolute()}")
        print(f"   Vérifie que le script est lancé depuis RFVF-PLUS/")
        sys.exit(1)

    success = import_map(map_name)
    sys.exit(0 if success else 1)
