# /// script
# requires-python = ">=3.9"
# dependencies = ["numpy", "pillow"]
# ///
"""World map of the Town Map and the Fly map: Johto (placeholder), Kanto, the Sevii Islands and Hoenn on one tilemap.

Usage, from the repo root:  uv run tools/worldmap/worldmap.py [--emerald ../pokeemerald] [--preview world.png]
Writes (deterministic, run it again after changing it or its inputs):
  graphics/region_map/world.bin        BG0 text tilemap, WORLD_WIDTH x WORLD_HEIGHT u16 entries (read in place)
  graphics/region_map/world_tiles.png  the tiles Kanto's tileset lacks (BG0 tiles 320..511 then 576..), 8-bit
                                       indexed: the low nibble is the color, the high one the palette (from 5)
  graphics/region_map/world.pal        their palettes (BG palettes 5..)
  src/data/region_map/world_map.h      sizes, region table, masks, Hoenn's map sections, Hoenn's visited flags
Inputs: Kanto and the Sevii maps are FRLG's own screens (kanto.bin, sevii_*.bin, region_map.png) pasted as tilemap
entries; Hoenn is Emerald's map (pokeemerald graphics/pokenav/region_map, src/data/region_map/region_map_layout.h)
recoloured in FRLG's colors, its towns drawn with FRLG's town ball.
Checks: the four FRLG home views render pixel-identical to today's screens, the whole world renders back to its art,
regions, map sections and icons never share a cell, every Hoenn dungeon here is a map of the game.
"""
import argparse
import json
import re
import sys
from pathlib import Path

import numpy as np
from PIL import Image

REPO = Path(__file__).resolve().parents[2]
G = REPO / "graphics/region_map"

SEVII_GAP = 0           # sea rows between Kanto and each Sevii group: 0 = edge to edge (FRLG's overview), 2 = more sea
BAND = 18               # height of FRLG's map window, in cells
WT, HT = 60, 4 * BAND + 3 * SEVII_GAP
VW, VH = 24, 18         # viewport = FRLG's map window, screen px (24,16)-(216,160)
SEA = 0x0003            # region_map tile 3, palette 0
FIRST_NEW, LOW_END, HIGH_START, HIGH_END = 320, 512, 576, 960   # free BG0 tiles (512..575 hold BG1's tiles)
FIRST_PAL = 5           # BG palettes 0-4: region_map.pal
BAND_Y = [i * (BAND + SEVII_GAP) for i in range(4)]
# name, enum, art rect (x, y, w, h), grid rect or None, home camera, flag that shows it (0: always)
REGIONS = [
    ("kanto", "REGIONMAP_KANTO", (36, BAND_Y[0], 24, 18), (37, BAND_Y[0] + 2, 22, 15), (36, BAND_Y[0]), "0"),
    ("sevii_123", "REGIONMAP_SEVII123", (36, BAND_Y[1], 24, 18), (37, BAND_Y[1] + 2, 22, 15), (36, BAND_Y[1]),
     "FLAG_SYS_SEVII_MAP_123"),
    ("sevii_45", "REGIONMAP_SEVII45", (36, BAND_Y[2], 24, 18), (37, BAND_Y[2] + 2, 22, 15), (36, BAND_Y[2]),
     "FLAG_SYS_SEVII_MAP_4567"),
    ("sevii_67", "REGIONMAP_SEVII67", (36, BAND_Y[3], 24, 18), (37, BAND_Y[3] + 2, 22, 15), (36, BAND_Y[3]),
     "FLAG_SYS_SEVII_MAP_4567"),
    ("hoenn", "REGIONMAP_HOENN", (0, 20, 30, 20), (1, 22, 28, 15), (3, 20), "0"),
    ("johto", "REGIONMAP_JOHTO", (0, 0, 36, 20), None, (0, 0), "0"),
]
# FRLG's BufferRegionMapBg masks, moved into the world: sea and no map section until the flag is set
MASKS = [((36 + 10, BAND_Y[2] + 9, 3, 2), "FLAG_WORLD_MAP_NAVEL_ROCK_EXTERIOR", "MAPSEC_NAVEL_ROCK"),
         ((36 + 18, BAND_Y[3] + 14, 3, 3), "FLAG_WORLD_MAP_BIRTH_ISLAND_EXTERIOR", "MAPSEC_BIRTH_ISLAND")]
CANCEL = (21, 14, 3, 3)  # cancel button in a FRLG window (cells): fixed UI on BG3, sea in the world
CANCEL_TILES = {0xF0, 0xF1, 0xF2, 0x120, 0x121, 0x122, 0x130, 0x131, 0x132}
RECOLOR = {  # Emerald -> FRLG: same sea, routes and town reds; greens and water routes differ
    (0, 112, 0): (24, 128, 8), (96, 208, 0): (80, 200, 8), (168, 232, 48): (112, 224, 32),
    (208, 248, 120): (168, 240, 56), (72, 152, 224): (88, 168, 224), (40, 128, 224): (80, 144, 208),
    (64, 104, 200): (72, 128, 208), (32, 72, 192): (64, 112, 200), (232, 224, 168): (224, 216, 160),
    (240, 0, 0): (248, 56, 16),
}
HOENN_TOWNS = ["LITTLEROOT_TOWN", "OLDALE_TOWN", "DEWFORD_TOWN", "LAVARIDGE_TOWN", "FALLARBOR_TOWN", "VERDANTURF_TOWN",
               "PACIFIDLOG_TOWN", "PETALBURG_CITY", "SLATEPORT_CITY", "MAUVILLE_CITY", "RUSTBORO_CITY", "FORTREE_CITY",
               "LILYCOVE_CITY", "MOSSDEEP_CITY", "SOOTOPOLIS_CITY", "EVER_GRANDE_CITY"]   # MAPSEC 0x00..0x0F
# Hoenn dungeon icons: one cell each (Emerald's corner, region_map_sections.json), flag FLAG_WORLD_MAP_<name>.
# Fiery Path, Jagged Pass and Magma Hideout share (6,3): the first two take Emerald's *2 cells.
HOENN_DUNGEONS = {"PETALBURG_WOODS": None, "RUSTURF_TUNNEL": None, "GRANITE_CAVE": None, "METEOR_FALLS": None,
                  "MT_CHIMNEY": None, "JAGGED_PASS": "JAGGED_PASS2", "FIERY_PATH": "FIERY_PATH2", "MAGMA_HIDEOUT": None,
                  "NEW_MAUVILLE": None, "ABANDONED_SHIP": None, "MT_PYRE": None, "AQUA_HIDEOUT": None,
                  "SHOAL_CAVE": None, "SEAFLOOR_CAVERN": None, "CAVE_OF_ORIGIN": None, "VICTORY_ROAD": None,
                  "DESERT_RUINS": None, "ISLAND_CAVE": None, "ANCIENT_TOMB": None, "SEALED_CHAMBER": None,
                  "SKY_PILLAR": None, "MIRAGE_TOWER": None, "SCORCHED_SLAB": None, "DESERT_UNDERPASS": None,
                  "ALTERING_CAVE_E": None}
FRLG_TOWNS = {"PALLET_TOWN", "VIRIDIAN_CITY", "PEWTER_CITY", "CERULEAN_CITY", "LAVENDER_TOWN", "VERMILION_CITY",
              "CELADON_CITY", "FUCHSIA_CITY", "CINNABAR_ISLAND", "INDIGO_PLATEAU", "SAFFRON_CITY", "ROUTE_4_POKECENTER",
              "ROUTE_10_POKECENTER", "ONE_ISLAND", "TWO_ISLAND", "THREE_ISLAND", "FOUR_ISLAND", "FIVE_ISLAND",
              "SIX_ISLAND", "SEVEN_ISLAND"}
HOENN_LAYOUT_W, HOENN_LAYOUT_H = 28, 15


def read_pal(path):
    lines = Path(path).read_text().split("\n")
    return np.array([[int(v) for v in lines[3 + i].split()] for i in range(int(lines[2]))], np.int32)


def gba(c):
    return ((np.asarray(c) >> 3) << 3).astype(np.uint8)


def tiles_of(png):
    a = np.array(Image.open(png))
    return a.reshape(a.shape[0] // 8, 8, a.shape[1] // 8, 8).transpose(0, 2, 1, 3).reshape(-1, 8, 8)


def frlg_pal():
    pal = read_pal(G / "region_map.pal")
    pal[0x20:0x2F] = pal[0x20:0x2F] * 95 // 100            # TintMapEdgesPalette, color 15 kept
    return gba(pal)


def flips(t):
    return {(0, 0): t, (1, 0): t[:, ::-1], (0, 1): t[::-1], (1, 1): t[::-1, ::-1]}


def render(tm, tiles, pal, w, h):
    """Text tilemap -> RGB; color 0 (transparent on the GBA) must not appear: -> None for those pixels' cell."""
    out = np.zeros((h * 8, w * 8, 3), np.uint8)
    for y in range(h):
        for x in range(w):
            e = int(tm[y, x])
            px = flips(tiles[e & 0x3FF])[((e >> 10) & 1, (e >> 11) & 1)]
            assert (px != 0).all(), "color 0 (transparent) in world cell %d,%d" % (x, y)
            out[y * 8:y * 8 + 8, x * 8:x * 8 + 8] = pal[(e >> 12) * 16 + px]
    return out


def layout(path, name_prefix="MAPSEC_"):
    """FRLG/Emerald region map layout header -> [layer][y][x] of MAPSEC names (one layer for Emerald)."""
    src = Path(path).read_text()
    layers = []
    for part in src.split("[LAYER_DUNGEON]"):
        rows = re.findall(r"\{([^{}]*%s[^{}]*)\}" % name_prefix, part)
        layers.append([[c.strip() for c in r.split(",") if c.strip()] for r in rows])
    return layers


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--emerald", default=str(REPO.parent / "pokeemerald"), help="pret/pokeemerald clone")
    ap.add_argument("--preview", help="also write the whole world as a PNG (1x)")
    args = ap.parse_args()
    em = Path(args.emerald)
    if not (em / "graphics/pokenav/region_map/map.png").exists():
        sys.exit("pokeemerald not found at %s (--emerald PATH)" % em)

    secs = {s["map_section"]: s for s in json.loads((REPO / "src/data/region_map/region_map_sections.json")
                                                    .read_text(encoding="utf-8"))["map_sections"]}
    consts = set(re.findall(r"#define (MAPSEC_\w+)", (REPO / "include/constants/region_map_sections.h").read_text()))
    rm_tiles = tiles_of(G / "region_map.png") & 0xF
    pal = frlg_pal()

    # ---- FRLG windows: kanto.bin / sevii_*.bin entries, the cancel button becomes sea (it is fixed UI on BG3) ----
    wtm = np.full((HT, WT), SEA, np.uint16)
    fixed = np.zeros((HT, WT), bool)
    for name, _, (ax, ay, aw, ah), *_ in REGIONS[:4]:
        win = np.frombuffer((G / (name + ".bin")).read_bytes(), "<u2").reshape(20, 30)[2:20, 3:27].copy()
        cx, cy, cw, ch = CANCEL
        assert {int(e) & 0x3FF for e in win[cy:cy + ch, cx:cx + cw].flat} <= CANCEL_TILES, name
        win[cy:cy + ch, cx:cx + cw] = SEA
        wtm[ay:ay + ah, ax:ax + aw] = win
        fixed[ay:ay + ah, ax:ax + aw] = True
    W = render(wtm, rm_tiles, pal, WT, HT)          # the art, FRLG part exact; Hoenn and Johto drawn below
    SEA0, SEA1 = tuple(W[0, 0]), tuple(W[1, 0])

    def is_land(a):
        return ~(np.all(a == SEA0, -1) | np.all(a == SEA1, -1))

    def sea(h, w):
        a = np.zeros((h, w, 3), np.uint8)
        a[:] = SEA1
        a[0::2] = SEA0
        return a

    # ---- Hoenn: Emerald's map (8bpp, 64x64 affine tilemap), FRLG colors, FRLG town ball, cut coasts closed ----
    im = Image.open(em / "graphics/pokenav/region_map/map.png")
    etiles = tiles_of(em / "graphics/pokenav/region_map/map.png")
    epal = gba(np.array(im.getpalette(), np.int32).reshape(-1, 3))
    etm = np.frombuffer((em / "graphics/pokenav/region_map/map.bin").read_bytes(), np.uint8).reshape(64, 64)
    hx, hy, hw, hh = REGIONS[4][2]
    h = np.zeros((hh * 8, hw * 8, 3), np.uint8)
    for ty in range(hh):
        for tx in range(hw):
            h[ty * 8:ty * 8 + 8, tx * 8:tx * 8 + 8] = epal[etiles[etm[ty, tx]]]
    assert {SEA0, SEA1} <= {tuple(c) for c in h.reshape(-1, 3)}, "Emerald's sea differs from FRLG's"
    for src, dst in RECOLOR.items():
        h[np.all(h == src, -1)] = dst
    gx, gy = REGIONS[0][3][:2]
    ball = W[(gy + 11) * 8:(gy + 12) * 8, (gx + 4) * 8:(gx + 5) * 8].copy()     # Pallet Town's cell
    for t in HOENN_TOWNS:
        s = secs["MAPSEC_" + t]
        if s["width"] == s["height"] == 1:
            h[16 + 8 * s["y"]:24 + 8 * s["y"], 8 + 8 * s["x"]:16 + 8 * s["x"]] = ball
    for sl in (np.s_[0:2, :], np.s_[:, 0:3], np.s_[:, hw * 8 - 4:]):
        part = h[sl]
        m = is_land(part)
        part[m] = sea(hh * 8, hw * 8)[sl][m]
    W[hy * 8:(hy + hh) * 8, hx * 8:(hx + hw) * 8] = h

    # ---- Johto: reserved, placeholder land that closes Kanto's cut west coast ----
    jx, jy, jw, jh = REGIONS[5][2]
    x1 = (jx + jw) * 8
    kl = [y for y in range(BAND * 8) if is_land(W[y:y + 1, x1:x1 + 1])[0, 0]]
    xs = np.arange(jx * 8, x1)
    wav = xs < x1 - 24
    coast = (max(kl) + 1 + 10 * np.sin((xs - x1) / 23.0) * wav + 6 * np.sin(xs / 9.0) * wav).astype(int)
    jl = np.arange(jh * 8)[:, None] < coast[None, :]
    J = W[jy * 8:(jy + jh) * 8, jx * 8:x1]
    J[jl] = (56, 168, 8)
    J[(np.add.outer(np.arange(jh * 8), xs) % 6 == 0) & jl] = (128, 152, 112)
    J[jl & ~np.pad(jl, 1)[2:, 1:-1]] = (24, 128, 8)

    # ---- the drawn cells -> tilemap: region_map tiles when they render the same, else new tiles and palettes ----
    known = {}
    for p in range(5):
        for t in range(1, len(rm_tiles)):
            if (rm_tiles[t] == 0).any():
                continue
            for (hf, vf), px in flips(rm_tiles[t]).items():
                known.setdefault(pal[p * 16 + px].tobytes(), t | hf << 10 | vf << 11 | p << 12)
    new, new_of = [], {}                  # new tiles (8x8 RGB), {RGB bytes of a flip: (index, hf, vf)}
    cells = {}
    for y in range(HT):
        for x in range(WT):
            if fixed[y, x]:
                continue
            c = W[y * 8:y * 8 + 8, x * 8:x * 8 + 8]
            k = c.tobytes()
            if k in known:
                wtm[y, x] = known[k]
                continue
            if k not in new_of:
                for (hf, vf), f in flips(c).items():
                    new_of.setdefault(f.tobytes(), (len(new), hf, vf))
                new.append(c.copy())
            cells[(x, y)] = new_of[k]
    sets = [frozenset(map(tuple, t.reshape(-1, 3))) for t in new]
    assert all(len(s) <= 15 for s in sets), "a tile with more than 15 colors"
    banks = []
    for s in sorted(set(sets), key=lambda s: (-len(s), sorted(s))):
        for b in banks:
            if len(b | s) <= 15:
                b |= s
                break
        else:
            banks.append(set(s))
    banks = [sorted(b) for b in banks]
    assert FIRST_PAL + len(banks) <= 12, "palettes 12-15 are the top bar's and the dungeon preview's"
    tile_bank = [next(i for i, b in enumerate(banks) if s <= set(b)) for s in sets]
    slots = list(range(FIRST_NEW, LOW_END)) + list(range(HIGH_START, HIGH_END))
    assert len(new) <= len(slots), "%d new tiles, %d free BG0 tiles" % (len(new), len(slots))
    for (x, y), (i, hf, vf) in cells.items():
        wtm[y, x] = slots[i] | hf << 10 | vf << 11 | (FIRST_PAL + tile_bank[i]) << 12

    # ---- checks: render back; home views == today's screens ----
    all_tiles = np.zeros((HIGH_END, 8, 8), np.uint8)
    all_tiles[:len(rm_tiles)] = rm_tiles
    idx_tiles = []
    for i, t in enumerate(new):
        b = banks[tile_bank[i]]
        it = np.array([[b.index(tuple(p)) + 1 for p in row] for row in t], np.uint8)
        idx_tiles.append(it)
        all_tiles[slots[i]] = it
    full_pal = np.zeros((256, 3), np.uint8)
    full_pal[:80] = pal
    for i, b in enumerate(banks):
        full_pal[(FIRST_PAL + i) * 16 + 1:(FIRST_PAL + i) * 16 + 1 + len(b)] = b
    back = render(wtm, all_tiles, full_pal, WT, HT)
    assert (back == W).all(), "the world tilemap does not render back to the art"
    button = np.frombuffer((G / "kanto.bin").read_bytes(), "<u2").reshape(20, 30)[16:19, 24:27]
    for name, _, (ax, ay, aw, ah), *_ in REGIONS[:4]:
        tm = np.frombuffer((G / (name + ".bin")).read_bytes(), "<u2").reshape(20, 30)
        today = render(tm[2:20, 3:27], all_tiles, full_pal, VW, VH)
        view = back[ay * 8:(ay + VH) * 8, ax * 8:(ax + VW) * 8].copy()
        view[14 * 8:17 * 8, 21 * 8:24 * 8] = render(button, all_tiles, full_pal, 3, 3)    # BG3 over BG0
        assert (view == today).all(), "%s: home view differs from today's screen" % name

    # ---- map sections: FRLG layouts at their grids, Hoenn = Emerald's map layer + the dungeon cells ----
    em_layer = layout(em / "src/data/region_map/region_map_layout.h")[0]
    assert len(em_layer) == HOENN_LAYOUT_H and all(len(r) == HOENN_LAYOUT_W for r in em_layer)
    hoenn = [em_layer, [["MAPSEC_NONE"] * HOENN_LAYOUT_W for _ in range(HOENN_LAYOUT_H)]]
    used = {json.loads(p.read_text(encoding="utf-8")).get("region_map_section") for p in REPO.glob("data/maps/*/map.json")}
    for d, cell_of in HOENN_DUNGEONS.items():
        assert "MAPSEC_" + d in used, "MAPSEC_%s: no map of the game uses it" % d
        s = secs["MAPSEC_" + (cell_of or d)]
        assert hoenn[1][s["y"]][s["x"]] == "MAPSEC_NONE", "two Hoenn dungeons on cell %d,%d" % (s["x"], s["y"])
        hoenn[1][s["y"]][s["x"]] = "MAPSEC_" + d
    assert {c for layer in hoenn for r in layer for c in r} <= consts, "unknown MAPSEC in Emerald's layout"
    grids = {name: layout(REPO / ("src/data/region_map/region_map_layout_%s.h" % name)) for name, *_ in REGIONS[:4]}
    grids["hoenn"] = hoenn
    owner, fly, dungeon, town_cells = {}, {}, [], set()
    for name, _, art, grid, *_ in REGIONS[:5]:
        x0, y0, w, h_ = grid
        assert art[0] <= x0 and x0 + w <= art[0] + art[2] and art[1] <= y0 and y0 + h_ <= art[1] + art[3], name
        for y in range(h_):
            for x in range(w):
                c = (x0 + x, y0 + y)
                assert c not in owner, "%s and %s share cell %s" % (name, owner[c], c)
                owner[c] = name
                m, d = grids[name][0][y][x][7:], grids[name][1][y][x]
                if m in FRLG_TOWNS or m in HOENN_TOWNS:
                    fly.setdefault(m, c)
                    town_cells.add(c)
                if d != "MAPSEC_NONE":
                    dungeon.append(c)
    origin = {name: grid for name, _, _, grid, *_ in REGIONS if grid}
    for (x, y, w, h_), _, sec in MASKS:
        assert any(grids[n][0][c[1] - origin[n][1]][c[0] - origin[n][0]] == sec for c, n in owner.items()
                   if x <= c[0] < x + w and y <= c[1] < y + h_), "%s is not inside its mask" % sec

    def most(cells):          # most icons around one view (one cell of margin: a 16x16 icon overhangs its cell)
        return max(sum(cx - 1 <= x <= cx + VW and cy - 1 <= y <= cy + VH for x, y in cells)
                   for cx in range(WT - VW + 1) for cy in range(HT - VH + 1))
    n_fly, n_dun = most(fly.values()), most(dungeon)
    assert n_fly + n_dun + 2 + 4 + 6 <= 64, "too many sprites"        # + cursor, player, 4 arrows, 6 map edges

    # ---- outputs ----
    (G / "world.bin").write_bytes(wtm.astype("<u2").tobytes())
    rows = (len(new) + 15) // 16
    img = np.zeros((rows * 8, 128), np.uint8)
    for i, t in enumerate(idx_tiles):
        img[(i // 16) * 8:(i // 16) * 8 + 8, (i % 16) * 8:(i % 16) * 8 + 8] = t + 16 * tile_bank[i]
    png_pal = np.zeros((256, 3), np.uint8)
    png_pal[:16 * len(banks)] = full_pal[FIRST_PAL * 16:(FIRST_PAL + len(banks)) * 16]
    out = Image.fromarray(img, "P")
    out.putpalette(png_pal.flatten().tolist())
    out.save(G / "world_tiles.png", optimize=False)
    (G / "world.pal").write_text("JASC-PAL\r\n0100\r\n%d\r\n" % (16 * len(banks)) + "".join(
        "%d %d %d\r\n" % tuple(c) for c in png_pal[:16 * len(banks)]), newline="")

    def rect(r):
        return "{%d, %d, %d, %d}" % r if r else "{0}"
    c = ["// Generated by tools/worldmap/worldmap.py: change the generator and run it again, do not edit.",
         "#define WORLD_WIDTH %d" % WT, "#define WORLD_HEIGHT %d" % HT,
         "#define WORLD_NUM_TILES %d // world_tiles.png: BG0 tiles %d.. then %d.." % (len(new), FIRST_NEW, HIGH_START),
         "#define WORLD_TILES_LOW %d" % min(len(new), LOW_END - FIRST_NEW),
         "#define WORLD_FIRST_PAL %d" % FIRST_PAL, "#define WORLD_NUM_PALS %d" % len(banks),
         "#define NUM_FLY_ICON_SPRITES %d // most icons around one view" % n_fly,
         "#define NUM_DUNGEON_ICON_SPRITES %d" % n_dun, "#define MAX_WORLD_ICONS %d" % (len(fly) + len(dungeon)), "",
         "static const u8 sRegionMapSections_Hoenn[LAYER_COUNT][%d][%d] = {" % (HOENN_LAYOUT_H, HOENN_LAYOUT_W)]
    for i, lay in enumerate(hoenn):
        c.append("    [%s] =\n    {" % ("LAYER_MAP", "LAYER_DUNGEON")[i])
        c += ["        {%s}," % ", ".join(r) for r in lay]
        c.append("    },")
    c += ["};", "", "static const struct WorldRegion sWorldRegions[REGIONMAP_COUNT] = {"]
    for name, enum, art, grid, home, flag in REGIONS:
        lay = "&sRegionMapSections_%s[0][0][0]" % {"kanto": "Kanto", "sevii_123": "Sevii123", "sevii_45": "Sevii45",
                                                    "sevii_67": "Sevii67", "hoenn": "Hoenn"}[name] if grid else "NULL"
        c.append("    [%s] = {%s, %s, {%d, %d}, %s, %s}," % (enum, rect(art), rect(grid), home[0], home[1], flag, lay))
    c += ["};", "", "static const struct WorldMask sWorldMasks[] = {"]
    c += ["    {%s, %s}," % (rect(r), flag) for r, flag, _ in MASKS]
    c += ["};", "", "// Hoenn dungeons: icon cell above, visited flag set on entering any map of the section",
          "static const u16 sHoennDungeonFlags[][2] = {"]
    c += ["    {MAPSEC_%s, FLAG_WORLD_MAP_%s}," % (d, d) for d in HOENN_DUNGEONS]
    c.append("};")
    (REPO / "src/data/region_map/world_map.h").write_text("\n".join(c) + "\n", newline="\n")
    if args.preview:
        Image.fromarray(back).save(args.preview)
    print("world %dx%d: %d new tiles (BG0 %d..), %d palettes (BG %d..), icons around a view: fly %d, dungeon %d; "
          "home views identical to today" % (WT, HT, len(new), FIRST_NEW, len(banks), FIRST_PAL, n_fly, n_dun))


if __name__ == "__main__":
    main()
