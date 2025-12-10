#!/usr/bin/env python3
"""Fix line endings in .pal files to CRLF (Windows format)"""

import os
import glob

palette_dir = "data/tilesets/secondary/lilycove/palettes"
pal_files = glob.glob(os.path.join(palette_dir, "*.pal"))

for pal_file in pal_files:
    # Read file in binary mode
    with open(pal_file, 'rb') as f:
        content = f.read()

    # Convert LF to CRLF if needed
    # First remove any existing CR to avoid double conversion
    content = content.replace(b'\r\n', b'\n')
    content = content.replace(b'\r', b'\n')
    # Now convert all LF to CRLF
    content = content.replace(b'\n', b'\r\n')

    # Write back
    with open(pal_file, 'wb') as f:
        f.write(content)

    print(f"✓ Fixed line endings: {pal_file}")

print(f"\n✓ Fixed {len(pal_files)} palette files")
