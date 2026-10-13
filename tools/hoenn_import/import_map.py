# /// script
# requires-python = ">=3.9"
# dependencies = ["pillow"]
# ///
"""Import one Emerald town or route with all its interiors, or one dungeon, from pokeemerald, complete except scripts.

Usage, from the repo root (PowerShell or Git Bash):
    uv run tools/hoenn_import/import_map.py FortreeCity --dry-run      (plan and check everything, write nothing)
    uv run tools/hoenn_import/import_map.py FortreeCity [--render DIR] [--emerald ..\\pokeemerald]
    uv run tools/hoenn_import/import_map.py GraniteCave                (a dungeon: all its floors)
A town or route is one of the 57 maps of Emerald's gMapGroup_TownsAndRoutes. Its interiors are the maps of Emerald's
gMapGroup_Indoor<Unit without Town/City> (minus three maps nothing reaches); the town or route joins
gMapGroup_TownsAndRoutes here, its interiors gMapGroup_Indoor<...>. A dungeon is one of the 28 units of Emerald's
gMapGroup_Dungeons (hoenn_import.dungeon_units: GraniteCave = GraniteCave_1F, _B1F, _B2F, _StevensRoom); its maps join
gMapGroup_HoennDungeons here, Victory Road's as HoennVictoryRoad_* (hoenn_decisions.RENAMES). Maps imported before are
never regenerated: they only get the warps and connections this import makes possible (the doors left onto themselves
until then). NPCs, trainers and signs are placed silent: their Emerald labels are stubs in the new scripts.inc files,
where the scripting happens. Item balls and hidden items work (their Emerald flags are allocated in flags.h), Emerald's
wild encounters and the town's heal location are added. The report lists the maps the player cannot reach yet.
Exit codes: 0 done (or nothing to do), 1 refused (nothing written, every reason listed), 2 usage, 3 writing (or
reading back) failed and every file was restored. Then: build with .\\fast_build.cmd, check in game, commit (a real
run prints how to undo it). French guide: LISEZMOI.md.
How it works: hoenn_import.py.
"""
import argparse
import difflib
import json
import sys
from pathlib import Path

import hoenn_import as hi


def main():
    pre = argparse.ArgumentParser(add_help=False)  # pokeemerald first: the help lists its units
    pre.add_argument("--emerald", type=Path, default=hi.REPO.parent / "pokeemerald")
    groups_file = pre.parse_known_args()[0].emerald / "data/maps/map_groups.json"
    groups = json.loads(hi.rename(hi.read(groups_file))) if groups_file.exists() else None
    towns, dungeons = (groups[hi.OUTDOOR], list(hi.dungeon_units(groups))) if groups else ([], [])
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0], epilog="Towns and routes: %s. Dungeons: %s."
                                     % (" ".join(towns), " ".join(dungeons)) if groups else None)
    parser.add_argument("unit", help="an Emerald town or route (FortreeCity, Route119) or dungeon (GraniteCave)")
    parser.add_argument("--dry-run", action="store_true", help="plan and check everything, write nothing")
    parser.add_argument("--emerald", type=Path, default=hi.REPO.parent / "pokeemerald", help="pret/pokeemerald clone")
    parser.add_argument("--render", type=Path, help="also save each converted map and connection strip as a PNG here")
    args = parser.parse_args()
    if not groups:
        print("pokeemerald not found at %s (--emerald DIR)" % args.emerald.resolve())
        return 2
    if args.unit not in towns + dungeons:
        owner = next((u for u in towns + dungeons if args.unit in hi.closure(groups, u)), None)
        known = [m for g in groups["group_order"] for m in groups[g] if m == args.unit or m.startswith(args.unit + "_")]
        close = difflib.get_close_matches(args.unit, towns + dungeons, 1, 0.5)
        if owner:
            print("%s is a map of %s: import_map.py %s imports it with the others" % (args.unit, owner, owner))
        elif known:
            print("%s (Emerald's %s) is not imported by this tool: special areas (Battle Frontier, Safari Zone, Trainer "
                  "Hill...), secret bases, the S.S. Tidal and unused maps are out of its scope" % (
                      args.unit, " ".join(known[:3]) + (" ..." if len(known) > 3 else "")))
        else:
            print("%s is not an Emerald town, route or dungeon%s. Valid: %s" % (
                args.unit, " (did you mean %s?)" % close[0] if close else "", " ".join(towns + dungeons)))
        return 2
    maps = hi.closure(groups, args.unit)
    print("%s: %d maps (%s)" % (args.unit, len(maps), ", ".join(maps)))
    return hi.run(list(maps), maps, args.emerald, args.render, args.dry_run, unit=args.unit)


if __name__ == "__main__":
    sys.exit(main())
