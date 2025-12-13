#!/bin/bash
# Script rapide pour réimporter le tileset lilycove depuis Emerald

EMERALD_PATH="/mnt/c/Users/Utilisateur/Documents/RFVF-Plus/pokeemerald_old/pokeemerald"

echo "Suppression du tileset corrompu..."
rm -rf data/tilesets/secondary/lilycove

echo "Copie depuis Emerald..."
cp -r "$EMERALD_PATH/data/tilesets/secondary/lilycove" data/tilesets/secondary/lilycove

echo "✓ Tileset lilycove réimporté"
ls -lh data/tilesets/secondary/lilycove/

echo ""
echo "Maintenant recompilez avec: make leafgreen"
