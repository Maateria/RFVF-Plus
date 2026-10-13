# /// script
# requires-python = ">=3.9"
# dependencies = ["pillow"]
# ///
"""Import every Emerald town and route that import_map.py accepts, one after the other, one git commit each.

Usage, from the repo root in PowerShell (close Porymap and commit your work first):
    uv run tools/hoenn_import/import_all.py --dry-run          (what each unit gives today, writes nothing)
    uv run tools/hoenn_import/import_all.py                    (import every accepted unit, then build)
    uv run tools/hoenn_import/import_all.py Route121 Route122  (only these units, in this order)
Options: --no-build (skip .\\fast_build.cmd at the end), --emerald DIR (pokeemerald, default ..\\pokeemerald).

Units are tried in ORDER, outward from Lilycove where players arrive. A refused unit is skipped with its reasons
(import_map.py writes nothing for it); a unit already imported says "Nothing to do". Run it again once the tool
accepts more (step 3): only what is still missing gets imported. Each import becomes its own commit,
"[FEAT] - Import <unit> from Emerald (import_map.py)", so `git revert <commit>` undoes one unit. Nothing is pushed.
Full tool output per unit: build/import_all/<unit>.txt.
"""
import argparse
import os
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent
IMPORT_MAP = HERE / "import_map.py"
LOGS = REPO / "build" / "import_all"
# Outward from Lilycove (survey order). SootopolisCity late: it fills the shared house tileset. Underwater units
# last: they wait for Dive.
ORDER = """LilycoveCity Route121 Route122 Route123 Route120 FortreeCity Route119 Route118
Route124 MossdeepCity Route125 Route127 Route128 EverGrandeCity Route126 Route129 Route130
Route131 PacifidlogTown Route132 Route133 Route134
Route117 VerdanturfTown MauvilleCity Route110 Route111 Route112 LavaridgeTown Route113 FallarborTown Route114 Route115
RustboroCity Route116 Route104 Route105 Route106 DewfordTown Route107 Route108 Route109 SlateportCity
PetalburgCity Route102 OldaleTown Route101 LittlerootTown Route103
SootopolisCity Underwater_Route124 Underwater_Route126 Underwater_Route127 Underwater_Route128 Underwater_Route129
Underwater_Route105 Underwater_Route125""".split()
# Git for Windows: in PowerShell the first git on the PATH can be devkitPro's, which has no core.autocrlf
GIT = next((g for g in (r"C:\Program Files\Git\cmd\git.exe",) if os.path.exists(g)), "git")


def git(*args, stdin=None):
    r = subprocess.run([GIT, "-C", str(REPO), *args], input=stdin, capture_output=True, text=True, encoding="utf-8")
    if r.returncode:
        sys.exit("git %s failed:\n%s" % (" ".join(args[:2]), r.stderr))
    return r.stdout


def changed(tracked_only=False):
    """Paths git sees as changed (untracked files listed one by one), .claude/ left out."""
    out, paths = git("status", "--porcelain", "-z", "--untracked-files=all").split("\0"), set()
    entries = iter(out)
    for e in entries:
        if not e:
            continue
        if e[0] in "RC":
            next(entries, None)                       # a rename: skip its old path
        if not (tracked_only and e.startswith("??")) and not e[3:].startswith(".claude/"):
            paths.add(e[3:])
    return paths


def porymap_running():
    if os.name != "nt":
        return False
    r = subprocess.run(["tasklist", "/FI", "IMAGENAME eq porymap.exe", "/NH"], capture_output=True, text=True)
    return "porymap.exe" in r.stdout.lower()


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("units", nargs="*", help="units to try, in this order (default: all, in ORDER)")
    parser.add_argument("--dry-run", action="store_true", help="check every unit, write nothing")
    parser.add_argument("--no-build", action="store_true", help="do not run .\\fast_build.cmd at the end")
    parser.add_argument("--emerald", help="pret/pokeemerald clone (default ..\\pokeemerald)")
    args = parser.parse_args()
    units = args.units or ORDER
    unknown = [u for u in units if u not in ORDER]
    if unknown:
        sys.exit("Inconnu : %s\nNoms valides : %s" % (" ".join(unknown), " ".join(ORDER)))
    if not args.dry_run:
        if porymap_running():
            sys.exit("Porymap est ouvert : ferme-le d'abord (il réécrirait map_groups.json et layouts.json).")
        dirty = changed(tracked_only=True)
        if dirty:
            sys.exit("Fichiers modifiés non committés (committe-les ou mets-les de côté d'abord) :\n  "
                     + "\n  ".join(sorted(dirty)))
    LOGS.mkdir(parents=True, exist_ok=True)
    extra = ["--dry-run"] if args.dry_run else []
    if args.emerald:
        extra += ["--emerald", args.emerald]
    env = dict(os.environ, PYTHONIOENCODING="utf-8")
    done, nothing, refused = [], [], []
    start = time.time()
    for n, unit in enumerate(units, 1):
        t = time.time()
        print("[%d/%d] %s ..." % (n, len(units), unit), end=" ", flush=True)
        before = changed()
        try:
            r = subprocess.run([sys.executable, str(IMPORT_MAP), unit, *extra], cwd=REPO, env=env,
                               capture_output=True, text=True, encoding="utf-8", errors="replace")
        except KeyboardInterrupt:
            sys.exit("\nInterrompu pendant %s : les zones d'avant sont committées. Vérifie `git status` : si %s a "
                     "écrit des fichiers, restaure-les avec `git restore -- <fichiers>` et supprime ses nouveaux "
                     "dossiers avec `git clean -fd -- <dossiers>` (jamais sans chemin, voir LISEZMOI.md)."
                     % (unit, unit))
        out = r.stdout + r.stderr
        (LOGS / ("%s.txt" % unit)).write_text(out, encoding="utf-8")
        secs = "%.0f s" % (time.time() - t)
        if r.returncode == 1:
            reasons = [l.strip()[2:] for l in out.splitlines() if l.startswith("  - ")]
            refused.append((unit, reasons or ["voir build/import_all/%s.txt" % unit]))
            print("refusée (%s)" % secs)
            if changed() != before:
                sys.exit("%s a été refusée mais des fichiers ont changé : vérifie `git status`." % unit)
            continue
        if r.returncode != 0:
            print("ERREUR (code %d)" % r.returncode)
            sys.exit("Arrêt. Sortie complète : build/import_all/%s.txt\n%s" % (unit, "\n".join(out.splitlines()[-15:])))
        new = changed() - before
        if args.dry_run:
            if "Nothing to do" in out:
                nothing.append(unit)
                print("déjà là (%s)" % secs)
            else:
                done.append((unit, ""))
                print("acceptée (%s)" % secs)
            continue
        if not new:
            nothing.append(unit)
            print("déjà là (%s)" % secs)
            continue
        git("add", "-A", "--pathspec-from-file=-", "--pathspec-file-nul", stdin="\0".join(sorted(new)))
        git("commit", "-q", "-m", "[FEAT] - Import %s from Emerald (import_map.py)" % unit,
            "-m", "%s\nGenerated by tools/hoenn_import/import_all.py." % out.splitlines()[0])
        sha = git("rev-parse", "--short", "HEAD").strip()
        done.append((unit, sha))
        print("importée, commit %s, %d fichiers (%s)" % (sha, len(new), secs))

    print("\n=== Bilan (%.0f min) ===" % ((time.time() - start) / 60))
    if args.dry_run:
        print("Simulation : chaque zone est testée sur le dépôt actuel, sans les imports des zones d'avant. Un vrai")
        print("lancement peut donc en refuser une de plus (par exemple quand le tileset des maisons se remplit).")
    print("%s (%d) : %s" % ("Acceptées" if args.dry_run else "Importées", len(done),
                            " ".join(u + (" (%s)" % s if s else "") for u, s in done) or "-"))
    print("Déjà là (%d) : %s" % (len(nothing), " ".join(nothing) or "-"))
    print("Refusées (%d) :" % len(refused))
    for unit, reasons in refused:
        print("  %s : %s" % (unit, reasons[0]) + ("  (+%d autre(s))" % (len(reasons) - 1) if len(reasons) > 1 else ""))
    if args.dry_run or not done:
        return 0
    build = REPO / "fast_build.cmd"
    if args.no_build or not build.exists() or os.name != "nt":
        print("\nCompile avec .\\fast_build.cmd, vérifie en jeu, puis `git push` quand tout va bien.")
        return 0
    print("\nCompilation (.\\fast_build.cmd) ...", flush=True)
    rc = subprocess.run(["cmd", "/c", str(build)], cwd=REPO).returncode
    print("Compilation %s. Vérifie en jeu, puis `git push` quand tout va bien." % ("réussie" if rc == 0 else
          "en ÉCHEC (code %d) : les commits sont faits, corrige puis relance .\\fast_build.cmd" % rc))
    return rc


if __name__ == "__main__":
    sys.exit(main())
