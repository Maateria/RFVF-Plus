#!/usr/bin/env python3
"""Import all palettes from Version-3.0 and fix line endings"""

import subprocess
import os

def import_palette(palette_path):
    """Import a palette from Version-3.0 and fix line endings"""
    # Get content from git
    result = subprocess.run(
        ['wsl', 'git', 'show', f'Version-3.0:{palette_path}'],
        capture_output=True,
        cwd='.'
    )

    if result.returncode != 0:
        print(f"✗ Failed to import {palette_path}")
        return False

    # Fix line endings (LF -> CRLF)
    content = result.stdout
    content = content.replace(b'\r\n', b'\n')  # Remove existing CR
    content = content.replace(b'\r', b'\n')    # Normalize
    content = content.replace(b'\n', b'\r\n')  # Add CRLF

    # Write to file
    with open(palette_path, 'wb') as f:
        f.write(content)

    print(f"✓ Imported {palette_path}")
    return True

# Import all hoenn_general palettes (00-15)
print("Importing hoenn_general palettes...")
for i in range(16):
    palette_path = f"data/tilesets/primary/hoenn_general/palettes/{i:02d}.pal"
    import_palette(palette_path)

print("\n✓ All palettes imported with correct line endings!")
