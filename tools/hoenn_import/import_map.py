# /// script
# requires-python = ">=3.9"
# dependencies = ["pillow"]
# ///
"""Import one Emerald town or route with all its interiors from pokeemerald, complete except scripts.

Usage, from the repo root (PowerShell or Git Bash):
    uv run tools/hoenn_import/import_map.py FortreeCity --dry-run      (plan and check everything, write nothing)
    uv run tools/hoenn_import/import_map.py FortreeCity [--render DIR] [--emerald ..\\pokeemerald]
The unit is one of the 57 maps of Emerald's gMapGroup_TownsAndRoutes. Its interiors are the maps of Emerald's
gMapGroup_Indoor<Unit without Town/City> (minus three maps nothing reaches); the town or route joins
gMapGroup_TownsAndRoutes here, its interiors gMapGroup_Indoor<...>. Maps imported before are never regenerated: they
only get the warps and connections this import makes possible. NPCs, trainers and signs are placed silent: their
Emerald labels are stubs in the new scripts.inc files, where the scripting happens. Item balls and hidden items work
(their Emerald flags are allocated in flags.h), Emerald's wild encounters and the town's heal location are added.
Exit codes: 0 done (or nothing to do), 1 refused (nothing written, every reason listed), 2 usage, 3 writing (or
reading back) failed and every file was restored. Then: build with .\\fast_build.cmd, check in game, commit (a real
run prints how to undo it). French guide: LISEZMOI.md.
How it works: hoenn_import.py.
"""
import argparse
import difflib
import json
import re
import sys
from pathlib import Path

import hoenn_import as hi

# Emerald indoor-group maps nothing reaches (survey): never imported
NEVER = {"LilycoveCity_UnusedMart", "Route104_Prototype", "Route104_PrototypePrettyPetalFlowerShop"}
OUTDOOR = "gMapGroup_TownsAndRoutes"


def closure(groups, unit):
    """The unit and the maps of its Emerald indoor group, in Emerald's order: {map: its group here}."""
    group = "gMapGroup_Indoor" + re.sub(r"(Town|City)$", "", unit)
    return dict({unit: OUTDOOR}, **{m: group for m in groups.get(group, []) if m not in NEVER})


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("unit", help="an Emerald town or route, e.g. FortreeCity or Route119")
    parser.add_argument("--dry-run", action="store_true", help="plan and check everything, write nothing")
    parser.add_argument("--emerald", type=Path, default=hi.REPO.parent / "pokeemerald", help="pret/pokeemerald clone")
    parser.add_argument("--render", type=Path, help="also save each converted map and connection strip as a PNG here")
    args = parser.parse_args()
    groups_file = args.emerald / "data/maps/map_groups.json"
    if not groups_file.exists():
        print("pokeemerald not found at %s (--emerald DIR)" % args.emerald.resolve())
        return 2
    groups = json.loads(hi.read(groups_file))
    units = groups[OUTDOOR]
    if args.unit not in units:
        close = difflib.get_close_matches(args.unit, units, 1, 0.5)
        print("%s is not an Emerald town or route%s. Valid: %s" % (
            args.unit, " (did you mean %s?)" % close[0] if close else "", " ".join(units)))
        return 2
    if args.unit.startswith("Underwater_"):
        print("REFUSED, nothing written:\n  - needs step 3: %s is an underwater map; underwater maps wait for Dive "
              "support (design: engine-gaps #1, #17)" % args.unit)
        return 1
    maps = closure(groups, args.unit)
    print("%s: %d maps (%s)" % (args.unit, len(maps), ", ".join(maps)))
    return hi.run(list(maps), maps, args.emerald, args.render, args.dry_run, unit=args.unit)


if __name__ == "__main__":
    sys.exit(main())
