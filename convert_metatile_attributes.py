#!/usr/bin/env python3
"""
Convert metatile_attributes.bin from Emerald format (2 bytes) to FireRed format (4 bytes)

Emerald format (2 bytes per metatile):
  Byte 0: behavior
  Byte 1: terrain_type (bits 0-3), layer_type (bits 4-6), unused (bit 7)

FireRed format (4 bytes per metatile):
  Byte 0: behavior
  Byte 1: terrain_type << 1 (bits 1-4)
  Byte 2: layer_type << 5 (bits 5-7)
  Byte 3: padding (0x00)
"""

import sys
import struct

def convert_emerald_to_firered(input_path, output_path, num_metatiles):
    """Convert metatile attributes from Emerald to FireRed format"""

    # Read Emerald format (2 bytes per metatile)
    with open(input_path, 'rb') as f:
        emerald_data = f.read()

    expected_size = num_metatiles * 2
    if len(emerald_data) != expected_size:
        print(f"Warning: Expected {expected_size} bytes for {num_metatiles} metatiles, got {len(emerald_data)} bytes")
        num_metatiles = len(emerald_data) // 2

    # Convert to FireRed format (4 bytes per metatile)
    firered_data = bytearray()

    for i in range(num_metatiles):
        offset = i * 2

        # Read Emerald format
        behavior = emerald_data[offset]
        flags = emerald_data[offset + 1]

        # Extract fields from flags
        terrain_type = flags & 0x0F          # bits 0-3
        layer_type = (flags >> 4) & 0x07     # bits 4-6
        # bit 7 is unused in both formats

        # Convert to FireRed format
        byte0 = behavior
        byte1 = (terrain_type << 1) & 0xFF   # shift left by 1
        byte2 = (layer_type << 5) & 0xFF     # shift left by 5
        byte3 = 0x00                          # padding

        firered_data.extend([byte0, byte1, byte2, byte3])

    # Write FireRed format
    with open(output_path, 'wb') as f:
        f.write(firered_data)

    print(f"✓ Converted {input_path}")
    print(f"  {num_metatiles} metatiles: {len(emerald_data)} bytes → {len(firered_data)} bytes")
    return len(firered_data)

if __name__ == "__main__":
    # Convert hoenn_general (512 metatiles)
    hoenn_input = "data/tilesets/primary/hoenn_general/metatile_attributes.bin"
    hoenn_output = "data/tilesets/primary/hoenn_general/metatile_attributes.bin"
    hoenn_size = convert_emerald_to_firered(hoenn_input, hoenn_output, 512)

    # Convert lilycove (352 metatiles - from 704 bytes / 2)
    lilycove_input = "data/tilesets/secondary/lilycove/metatile_attributes.bin"
    lilycove_output = "data/tilesets/secondary/lilycove/metatile_attributes.bin"

    # Read actual number of metatiles from file size
    with open(lilycove_input, 'rb') as f:
        lilycove_data = f.read()
    lilycove_metatiles = len(lilycove_data) // 2

    lilycove_size = convert_emerald_to_firered(lilycove_input, lilycove_output, lilycove_metatiles)

    print(f"\n✓ Conversion complete!")
    print(f"  hoenn_general: {hoenn_size} bytes (expected 2048)")
    print(f"  lilycove: {lilycove_size} bytes (expected {lilycove_metatiles * 4})")
