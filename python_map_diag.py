#!/usr/bin/env python3
import json, re, sys, pathlib

JSON_PATH = "data/maps/map_groups.json"
H_PATH    = "include/constants/map_groups.h"
OVR_PATH  = "include/constants/map_overrides.h"

def to_snake(name: str) -> str:
    # "BattleFrontier_OutsideWest" -> "BATTLE_FRONTIER_OUTSIDE_WEST"
    parts = []
    for tok in name.split("_"):
        tok = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", tok)
        parts.append(tok.upper())
    return "_".join(parts)

# Charge JSON en gardant l'ordre
with open(JSON_PATH, "r", encoding="utf-8") as f:
    j = json.load(f)

groups = list(j.keys())
expected = {}   # MAP_NAME (snake) -> (g,i) attendu
for g_idx, gname in enumerate(groups):
    for i_idx, m in enumerate(j[gname]):
        if isinstance(m, str):
            expected[to_snake(m)] = (g_idx, i_idx)

# Parse les #define MAP_... (i | (g << 8))
with open(H_PATH, "r", encoding="utf-8") as f:
    txt = f.read()
pat = re.compile(r"#define\s+MAP_([A-Z0-9_]+)\s*\(\s*(\d+)\s*\|\s*\(\s*(\d+)\s*<<\s*8\)\s*\)")
actual = {m.group(1):(int(m.group(3)), int(m.group(2))) for m in pat.finditer(txt)}  # name -> (g,i)

# Diff
missing = [n for n in expected if n not in actual]
mismatch = [(n, expected[n], actual[n]) for n in expected if n in actual and expected[n] != actual[n]]
extra = [n for n in actual if n not in expected]

print("== Résumé ==")
print(f"Groupes (JSON): {len(groups)}")
mgc = re.search(r"MAP_GROUPS_COUNT\s+(\d+)", txt)
print("MAP_GROUPS_COUNT (H):", mgc.group(1) if mgc else "??")
print(f"Manquants dans H: {len(missing)}")
print(f"Désaccords (JSON vs H): {len(mismatch)}")
print(f"En trop dans H: {len(extra)}")

# Focus utile
for key in ["PALLET_TOWN","VERMILION_CITY","FUCHSIA_CITY","LILYCOVE_CITY"]:
    print(f"{key:20s} JSON={expected.get(key)}  H={actual.get(key)}")

# Génère un header d'overrides pour corriger sans toucher map_groups.h
lines = []
lines.append("#ifndef GUARD_CONSTANTS_MAP_OVERRIDES_H")
lines.append("#define GUARD_CONSTANTS_MAP_OVERRIDES_H")
# Synchronise aussi le compteur
lines.append(f"#undef MAP_GROUPS_COUNT")
lines.append(f"#define MAP_GROUPS_COUNT {len(groups)}")
for n in missing:
    g,i = expected[n]
    lines.append(f"#define MAP_{n} ({i} | ({g} << 8))")
for n,(gexp,iexp),(gact,iact) in mismatch:
    lines.append(f"#undef MAP_{n}")
    lines.append(f"#define MAP_{n} ({iexp} | ({gexp} << 8))")
lines.append("#endif // GUARD_CONSTANTS_MAP_OVERRIDES_H")

pathlib.Path(OVR_PATH).parent.mkdir(parents=True, exist_ok=True)
with open(OVR_PATH, "w", encoding="utf-8") as f:
    f.write("\n".join(lines) + "\n")

print(f"\nÉcrit: {OVR_PATH}  (overrides auto)")
if missing or mismatch:
    print("=> Des corrections ont été écrites. Rebuild recommandé.")
else:
    print("=> Aucun décalage détecté.")
