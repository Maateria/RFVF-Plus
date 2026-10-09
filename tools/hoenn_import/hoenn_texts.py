#!/usr/bin/env python3
"""Official French texts of Emerald maps for RFVF+, re-wrapped for the FRLG message box.

Usage (Git Bash, from the repo root):
    uv run --no-project --with pyelftools python tools/hoenn_import/hoenn_texts.py LilycoveCity [--out DIR] [--write]
        Every text the scripts of the Emerald maps LilycoveCity* reach (their own + the common ones they use), in
        French, re-wrapped -> DIR/LilycoveCity_fr_texts.inc (reference: source file, EN/FR addresses, context) and
        DIR/LilycoveCity_fr_texts.json (+ English). Default DIR: build/hoenn_texts.
        --write: also appends to data/maps/<Map>/text.inc, for each map of this repo starting with the prefix, every
        extracted text its scripts.inc names and neither file defines yet (so: write scripts.inc with Emerald's text
        labels first). A text already in text.inc whose words are still the official ones is re-wrapped in place
        (so a re-wrap fix reaches it); one adapted by hand is never touched (listed, check it with --check). A new
        text.inc gets its .include in data/event_scripts.s, right after the map's scripts.inc.
    uv run --no-project python tools/hoenn_import/hoenn_texts.py --check data/maps/LilycoveCity*/text.inc
        Every printed line of those texts must fit the message box, the down arrow included (exit 1 otherwise).
    Inputs, read only: --emerald (pret/pokeemerald clone with its built pokeemerald.gba + pokeemerald.elf, default
    ../pokeemerald) and --rom (French Emerald, BPEF; default "Pokemon - Version Emeraude (FR).gba" in the repo root).

Extraction: both ROMs run the same script bytecode, only pointers differ. Every script of the selected maps (map
headers found through gMapGroups; the French gMapGroups is located by fingerprint) is walked IN PARALLEL in the
English ROM (labels from pokeemerald.elf) and the French one, so each English text pointer meets its French twin.
Texts no script reaches (used from C, unused) come from their English neighbours: texts are stored back to back in
the same order in both ROMs. Decoding uses this repo's charmap (the bytes round-trip unchanged), except that French
Emerald's glyphs 55-59 spell POKéBLOC while this repo's spell the English POKéBLOCK: the French texts get it in letters.
Re-wrap: the FRLG box is 26 tiles = 208 px (Emerald's: 216 px), glyph widths of src/text.c; a line that waits for A
(\\l, or the \\p that closes a page) also holds FRLG's 10 px down arrow, drawn right after its last glyph, so it may
take 198 px. Only a page with a line over its limit is touched: its official breaks are kept and the overflowing last
words move to the next line; when the page has to gain a line, its words from the first overflowing line on are
spread evenly over the lines (no lone last word). {PLAYER} counts as 7 glyphs of 6 px, {STR_VAR_x} as 10 (a nickname).
"""
import argparse
import functools
import glob
import json
import os
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
BOX_PX = 208  # sStandardTextBox_WindowTemplates (src/new_menu_helpers.c): 26 tiles
ARROW_PX = 10  # TextPrinterDrawDownArrow (src/text.c): 10 px wide, at the end of a line that waits for A
# ponytail: placeholder widths = longest name x 6 px (the naming screen's glyphs): player / rival 7, nickname 10.
# A {STR_VAR_x} holding something longer (an item name: up to 12 glyphs) needs a look by hand.
PH_PX = dict.fromkeys(("PLAYER", "RIVAL", "VERSION", "AQUA", "MAGMA", "ARCHIE", "MAXIE", "KYOGRE", "GROUDON"), 42)
PH_PX.update(dict.fromkeys(("STR_VAR_1", "STR_VAR_2", "STR_VAR_3"), 60))
FR_POKEBLOCK = "POKéBLOC"  # French Emerald's {POKEBLOCK} glyphs, in letters (this repo's glyphs spell POKéBLOCK)
# a word: glyphs and {codes} (a space inside a {code} does not split it); ATQ. SPE., DEF. SPE. and numéro ID are one
WORD = re.compile(r"(?:\{[^}]*\}|(?:ATQ|DEF)\. SPE\.|numéros? ID|[^ {])+")
MULTI = {"PKMN": [0x53, 0x54], "POKEBLOCK": [0x55, 0x56, 0x57, 0x58, 0x59], "LV": [0x34], "SUPER_ER": [0x2C],
         "SUPER_E": [0x84], "SUPER_RE": [0xA0], "UP_ARROW": [0x79], "DOWN_ARROW": [0x7A]}


def charmap():
    """repo charmap.txt, Latin part: byte -> source text, and char -> byte."""
    to_src, to_byte = {}, {}
    for line in open(REPO / "charmap.txt", encoding="utf-8"):
        if line.startswith("@ Hiragana"):
            break  # French superscripts reuse Japanese slots (2C = SUPER_ER, 84 = SUPER_E)
        m = re.match(r"^'(.)'\s*=\s*([0-9A-F]{2})\s*$", line) or re.match(r"^([A-Z_]+)\s*=\s*([0-9A-F]{2})\s*$", line)
        if m:
            b = int(m.group(2), 16)
            to_src.setdefault(b, m.group(1) if len(m.group(1)) == 1 else "{%s}" % m.group(1))
            if len(m.group(1)) == 1:
                to_byte.setdefault(m.group(1), b)
    to_src[0xB4], to_src[0xB0] = "'", "…"
    to_byte["'"] = 0xB4
    return to_src, to_byte


# ---------------------------------------------------------------- width model / re-wrap

@functools.lru_cache(None)
def font():
    """(glyph width of each byte, char -> byte); widest of the NPC (male/female) and sign (normal) fonts."""
    src = (REPO / "src/text.c").read_text(encoding="utf-8")
    tables = [[int(x) for x in re.findall(r"\d+", re.search(name + r"\[\]\s*=\s*\{(.*?)\};", src, re.S).group(1))]
              for name in ("sFontNormalLatinGlyphWidths", "sFontMaleLatinGlyphWidths", "sFontFemaleLatinGlyphWidths")]
    return [max(t[i] for t in tables) for i in range(len(tables[0]))], charmap()[1]


def tok_px(tok):
    widths, char_bytes = font()
    if tok.startswith("{"):
        name = (tok[1:-1].split() or [""])[0]
        return PH_PX.get(name) or sum(widths[b] for b in MULTI.get(name, []))  # other codes: no width
    return widths[char_bytes[tok]] if tok in char_bytes else 6


def line_px(line):
    return sum(tok_px(t) for t in re.findall(r"\{[^}]*\}|.", line))


def printed_lines(s):
    return re.split(r"\\[nlp]", s.replace("$", ""))


def too_wide(s):
    """(line, px, limit) of each printed line of s over its limit: the box, minus the down arrow if it waits for A."""
    parts = re.split(r"(\\[nlp])", s.replace("$", ""))
    lims = (BOX_PX - ARROW_PX * (brk in ("\\l", "\\p")) for brk in parts[1::2] + [""])
    return [(x, line_px(x), lim) for x, lim in zip(parts[0::2], lims) if line_px(x) > lim]


def limits(n, last_page):
    """px each line of an n-line page may take: every line waits for A (arrow) but the first of several (\\n follows)
    and the text's very last one."""
    return [BOX_PX - ARROW_PX * ((i > 0 or n == 1) and not (i == n - 1 and last_page)) for i in range(n)]


def words(s):
    """The words of s, line breaks ignored (pages kept: a \\p stays inside its word)."""
    return WORD.findall(re.sub(r"\\[nl]", " ", s))


def flow(ws, lims):
    """The words ws on len(lims) lines (line k at most lims[k] px), as evenly as possible: least sum of squared slack,
    the last line included (so no lone last word). None if they do not fit."""
    sp, w = line_px(" "), [line_px(x) for x in ws]
    best = {0: (0, [])}  # words placed -> (cost, line ends)
    for lim in lims:
        nxt = {}
        for i, (cost, ends) in best.items():
            px = -sp
            for j in range(i + 1, len(ws) + 1):
                px += sp + w[j - 1]
                if px > lim:
                    break
                if j not in nxt or cost + (lim - px) ** 2 < nxt[j][0]:
                    nxt[j] = (cost + (lim - px) ** 2, ends + [j])
        best = nxt
    ends = best.get(len(ws), (0, None))[1]
    return ends and [ws[a:b] for a, b in zip([0] + ends, ends)]


def rewrap_page(page, last_page):
    if not too_wide(page + ("" if last_page else "\\p")):
        return page
    lines = [WORD.findall(x) for x in re.split(r"\\[nl]", page)]
    n, first, i = len(lines), None, 0
    while i < len(lines):  # push the last words of an overflowing line onto the next one (the list may grow)
        while line_px(" ".join(lines[i])) > limits(len(lines), last_page)[i] and len(lines[i]) > 1:
            first = i if first is None else first
            if i + 1 == len(lines):
                lines.append([])
            lines[i + 1] = [lines[i].pop()] + lines[i + 1]
        i += 1
    if len(lines) > n:  # the page gained a line: spread its words from the first overflowing line on evenly
        lines[first:] = flow(sum(lines[first:], []), limits(len(lines), last_page)[first:]) or lines[first:]
    lines = [" ".join(x) for x in lines]
    return lines[0] + "".join(("\\n" if k == 1 else "\\l") + x for k, x in enumerate(lines[1:], 1))


def rewrap(s):
    """Re-wrap the pages of s that do not fit the FRLG box (see the module doc); the others keep the official breaks."""
    pages = s.split("\\p")
    return "\\p".join(rewrap_page(p, k == len(pages) - 1) for k, p in enumerate(pages))


def selftest():
    """The re-wrap: {codes} are never cut, the arrow fits, no lone last word, a page that fits is left alone."""
    for s in ("Mm " * 30 + "{COLOR RED}XY\\nfin", "Mm " * 30 + "XY{PAUSE 15}\\nfin",
              "Oh, regarder tous ces gracieux\\nPOKéMON me donne envie d'en avoir un!\\pFin."):
        out = rewrap(s)
        assert not too_wide(out) and words(out) == words(s), out
        assert min(line_px(x) for x in printed_lines(out)[:-1]) > 60, out
    assert rewrap("Oh?\\nTu n'as pas  de BAIES?\\pBon.") == "Oh?\\nTu n'as pas  de BAIES?\\pBon."
    assert "DEF. SPE." in rewrap("Je ne sais pas si je dois élever sa\\nDEFENSE avec le FER ou sa DEF. SPE.\\lavec.")


def to_inc(label, s):
    parts = re.split(r"(\\n|\\l|\\p)", s)
    lines, cur = [], ""
    for p in parts:
        cur += p
        if p in ("\\n", "\\l", "\\p"):
            lines.append(cur)
            cur = ""
    lines.append(cur + "$")
    return label + "::\n" + "".join('    .string "%s"\n' % x for x in lines) + "\n"


def read_inc_texts(path):
    """label -> source text (without $) of a text.inc-like file."""
    texts, cur = {}, None
    for line in open(path, encoding="utf-8"):
        m = re.match(r"^(\w+)::?\s*$", line)
        if m:
            cur = m.group(1)
            texts[cur] = ""
            continue
        m = re.match(r'^\s*\.string\s+"(.*)"\s*$', line)
        if m and cur:
            texts[cur] += m.group(1)
        elif line.strip() and not line.strip().startswith("@"):
            cur = None
    return {k: v.replace("$", "") for k, v in texts.items()}


def check(paths):
    bad = []
    for path in paths:
        for label, s in read_inc_texts(path).items():
            bad += ["%s %s: %d px > %d: \"%s\"" % (path, label, px, lim, x) for x, px, lim in too_wide(s)]
    print("\n".join(bad) or "check: every line of %d file(s) fits the %d px message box (%d px when it waits for A)"
          % (len(paths), BOX_PX, BOX_PX - ARROW_PX))
    return not bad


# ---------------------------------------------------------------- extraction (pokeemerald asm/macros/event.inc)

# b=u8 h=u16 w=u32 value  S=script ptr  T=text ptr  M=movement ptr  P=data ptr  L=loadword value  R=ram/code ptr
W7 = "bbbhh"  # map(2 bytes) + warp id + x + y
OPS = {0x00: "", 0x01: "", 0x02: "", 0x03: "", 0x04: "S", 0x05: "S", 0x06: "bS", 0x07: "bS", 0x08: "b", 0x09: "b",
       0x0a: "bb", 0x0b: "bb", 0x0c: "", 0x0d: "", 0x0e: "b", 0x0f: "bL", 0x10: "bb", 0x11: "bR", 0x12: "bR", 0x13: "bR",
       0x14: "bb", 0x15: "RR", 0x16: "hh", 0x17: "hh", 0x18: "hh", 0x19: "hh", 0x1a: "hh", 0x1b: "bb", 0x1c: "bb",
       0x1d: "bR", 0x1e: "Rb", 0x1f: "Rb", 0x20: "RR", 0x21: "hh", 0x22: "hh", 0x23: "R", 0x24: "R", 0x25: "h",
       0x26: "hh", 0x27: "", 0x28: "h", 0x29: "h", 0x2a: "h", 0x2b: "h", 0x2c: "hh", 0x2d: "", 0x2e: "", 0x2f: "h",
       0x30: "", 0x31: "h", 0x32: "", 0x33: "hb", 0x34: "h", 0x35: "", 0x36: "h", 0x37: "b", 0x38: "b", 0x39: W7,
       0x3a: W7, 0x3b: W7, 0x3c: "bb", 0x3d: W7, 0x3e: W7, 0x3f: W7, 0x40: W7, 0x41: W7, 0x42: "hh", 0x43: "",
       0x44: "hh", 0x45: "hh", 0x46: "hh", 0x47: "hh", 0x48: "h", 0x49: "hh", 0x4a: "hh", 0x4b: "h", 0x4c: "h",
       0x4d: "h", 0x4e: "h", 0x4f: "hM", 0x50: "hMbb", 0x51: "h", 0x52: "hbb", 0x53: "h", 0x54: "hbb", 0x55: "h",
       0x56: "hbb", 0x57: "hhh", 0x58: "hbb", 0x59: "hbb", 0x5a: "", 0x5b: "hb", 0x5d: "", 0x5e: "", 0x5f: "",
       0x60: "h", 0x61: "h", 0x62: "h", 0x63: "hhh", 0x64: "h", 0x65: "hb", 0x66: "", 0x67: "T", 0x68: "", 0x69: "",
       0x6a: "", 0x6b: "", 0x6c: "", 0x6d: "", 0x6e: "bb", 0x6f: "bbbb", 0x70: "bbbbb", 0x71: "bbbbb", 0x72: "",
       0x73: "bbbb", 0x74: "bbbb", 0x75: "hbb", 0x76: "", 0x77: "b", 0x78: "P", 0x79: "hbhwwb", 0x7a: "h", 0x7b: "bbh",
       0x7c: "h", 0x7d: "bh", 0x7e: "b", 0x7f: "bh", 0x80: "bh", 0x81: "bh", 0x82: "bh", 0x83: "bh", 0x84: "bh",
       0x85: "bT", 0x86: "P", 0x87: "P", 0x88: "P", 0x89: "h", 0x8a: "bbb", 0x8b: "", 0x8c: "", 0x8d: "", 0x8e: "",
       0x8f: "h", 0x90: "wb", 0x91: "wb", 0x92: "wb", 0x93: "bbb", 0x94: "bb", 0x95: "bbb", 0x96: "h", 0x97: "b",
       0x98: "bb", 0x99: "h", 0x9a: "b", 0x9b: "T", 0x9c: "h", 0x9d: "bh", 0x9e: "h", 0x9f: "h", 0xa0: "", 0xa1: "hh",
       0xa2: "hhhh", 0xa3: "", 0xa4: "h", 0xa5: "", 0xa6: "b", 0xa7: "h", 0xa8: "hbbb", 0xa9: "hbb", 0xaa: "bbhhbb",
       0xab: "bb", 0xac: "hh", 0xad: "hh", 0xae: "", 0xaf: "hh", 0xb0: "hh", 0xb1: "bhhh", 0xb2: "", 0xb3: "h",
       0xb4: "h", 0xb5: "h", 0xb6: "hbh", 0xb7: "", 0xb8: "w", 0xb9: "w", 0xba: "w", 0xbb: "bw", 0xbc: "bw", 0xbd: "w",
       0xbe: "w", 0xbf: "bw", 0xc0: "bb", 0xc1: "bb", 0xc2: "bb", 0xc3: "b", 0xc4: W7, 0xc5: "", 0xc6: "bh", 0xc7: "b",
       0xc8: "T", 0xc9: "", 0xca: "", 0xcb: "", 0xcc: "bw", 0xcd: "h", 0xce: "h", 0xcf: "", 0xd0: "h", 0xd1: W7,
       0xd2: "hb", 0xd3: "h", 0xd4: "", 0xd5: "h", 0xd6: "", 0xd7: W7, 0xd8: "", 0xd9: "", 0xda: "", 0xdb: "T",
       0xdc: "b", 0xdd: "bh", 0xde: "bh", 0xdf: "T", 0xe0: W7, 0xe1: "bh", 0xe2: "bhh"}
TRAINER_PTRS = {0: "TT", 1: "TTS", 2: "TTS", 3: "T", 4: "TTT", 5: "TT", 6: "TTTS", 7: "TTT", 8: "TTTS", 9: "TT",
                10: "TT", 11: "TT", 12: "TT"}
STOP = {0x02, 0x03, 0x05, 0x08, 0x0c, 0x0d, 0x5e, 0x5f, 0xb9}
STD = {0: "giveitem", 1: "finditem", 2: "MSGBOX_NPC", 3: "MSGBOX_SIGN", 4: "MSGBOX_DEFAULT", 5: "MSGBOX_YESNO",
       6: "MSGBOX_AUTOCLOSE", 7: "givedecoration", 8: "register_matchcall", 9: "MSGBOX_GETPOINTS", 10: "MSGBOX_POKENAV"}
SIZE = {"b": 1, "h": 2, "w": 4, "S": 4, "T": 4, "M": 4, "P": 4, "L": 4, "R": 4}
EM_FD = {1: "PLAYER", 2: "STR_VAR_1", 3: "STR_VAR_2", 4: "STR_VAR_3", 5: "KUN", 6: "RIVAL", 7: "VERSION", 8: "AQUA",
         9: "MAGMA", 10: "ARCHIE", 11: "MAXIE", 12: "KYOGRE", 13: "GROUDON"}
FC_ARGS = {1: 1, 2: 1, 3: 1, 4: 3, 5: 1, 6: 1, 7: 0, 8: 1, 9: 0, 10: 0, 11: 2, 12: 1, 13: 1, 14: 1, 15: 0, 16: 2,
           17: 1, 18: 1, 19: 1, 20: 1, 21: 0, 22: 0, 23: 0, 24: 0}
FC_NAME = {1: "COLOR", 2: "HIGHLIGHT", 3: "SHADOW", 4: "COLOR_HIGHLIGHT_SHADOW", 5: "PALETTE", 6: "FONT",
           7: "RESET_FONT", 8: "PAUSE", 9: "PAUSE_UNTIL_PRESS", 10: "WAIT_SE", 11: "PLAY_BGM", 12: "ESCAPE",
           13: "SHIFT_RIGHT", 14: "SHIFT_DOWN", 15: "FILL_WINDOW", 16: "PLAY_SE", 17: "CLEAR", 18: "SKIP",
           19: "CLEAR_TO", 20: "MIN_LETTER_SPACING", 21: "JPN", 22: "ENG", 23: "PAUSE_MUSIC", 24: "RESUME_MUSIC"}
COLORS = ["TRANSPARENT", "WHITE", "DARK_GRAY", "LIGHT_GRAY", "RED", "LIGHT_RED", "GREEN", "LIGHT_GREEN", "BLUE",
          "LIGHT_BLUE"]


def extract(em_dir, fr_rom, prefix):
    from elftools.elf.elffile import ELFFile

    EN = (em_dir / "pokeemerald.gba").read_bytes()
    FR = fr_rom.read_bytes()
    assert EN[0xAC:0xB0] == b"BPEE" and FR[0xAC:0xB0] == b"BPEF", "expected pokeemerald (BPEE) + French Emerald (BPEF)"
    u8 = lambda r, a: r[a - 0x08000000]
    u16 = lambda r, a: struct.unpack_from("<H", r, a - 0x08000000)[0]
    u32 = lambda r, a: struct.unpack_from("<I", r, a - 0x08000000)[0]
    is_rom = lambda p: 0x08000000 <= p < 0x08000000 + len(EN)

    sym, addr = defaultdict(list), {}  # EN symbols, local labels included
    for s in ELFFile(open(em_dir / "pokeemerald.elf", "rb")).get_section_by_name(".symtab").iter_symbols():
        v, n = s["st_value"], s.name
        if n and not n.startswith(("$", ".")) and 0x08000000 <= v < 0x0A000000 and s["st_info"]["type"] != "STT_SECTION":
            sym[v].append(n)
            addr.setdefault(n, v)
    name_of = lambda a: (sym.get(a) or sym.get(a & ~1) or ["0x%08X" % a])[0]

    chars = charmap()[0]

    def raw_string(rom, a, limit=2048):
        o = a - 0x08000000
        e = rom.find(b"\xff", o, o + limit)
        return rom[o:e + 1] if e >= 0 else None

    def decode(bs):
        """bytes (FF-terminated) -> source text (without the final $)."""
        out, i = [], 0
        while i < len(bs):
            b = bs[i]
            i += 1
            if b == 0xFF:
                break
            if b == 0xFE:
                out.append("\\n")
            elif b == 0xFA:
                out.append("\\l")
            elif b == 0xFB:
                out.append("\\p")
            elif b == 0xFD:
                out.append("{%s}" % EM_FD.get(bs[i], "STRING %d" % bs[i]))
                i += 1
            elif b == 0xFC:
                c = bs[i]
                i += 1
                args = list(bs[i:i + FC_ARGS.get(c, 0)])
                i += FC_ARGS.get(c, 0)
                if c in (1, 2, 3) and args[0] < len(COLORS):
                    out.append("{%s %s}" % (FC_NAME[c], COLORS[args[0]]))
                elif c == 0x0C and args == [0xFB]:
                    out.append("{TALL_PLUS}")
                else:
                    out.append("{%s}" % " ".join([FC_NAME.get(c, "FC_%02X" % c)] + [str(x) for x in args]))
            elif b == 0x53 and i < len(bs) and bs[i] == 0x54:
                out.append("{PKMN}")
                i += 1
            elif b == 0x55 and bs[i:i + 4] == b"\x56\x57\x58\x59":
                out.append("{POKEBLOCK}")
                i += 4
            elif b == 0x34:
                out.append("{LV}")
            elif b in chars:
                out.append(chars[b])
            else:
                out.append("{0x%02X}" % b)
        return "".join(out)

    # map headers
    groups = json.loads((em_dir / "data/maps/map_groups.json").read_text(encoding="utf-8"))
    maps = [(gi, mi, m) for gi, g in enumerate(groups["group_order"]) for mi, m in enumerate(groups[g])
            if m.startswith(prefix)]
    assert maps, "no Emerald map starts with " + prefix
    gmg_en = addr["gMapGroups"]
    en_header = lambda g, m: u32(EN, u32(EN, gmg_en + 4 * g) + 4 * m)

    def find_fr_gmapgroups():
        """A FR header found by fingerprint (music, layout id, mapsec, flags...), then pointers climbed to gMapGroups."""
        for g, m, _ in maps:
            tail = EN[en_header(g, m) - 0x08000000 + 0x10: en_header(g, m) - 0x08000000 + 0x1C]
            hits = [x.start() - 0x10 for x in re.finditer(re.escape(tail), FR) if (x.start() - 0x10) % 4 == 0]
            hits = [h for h in hits if all(is_rom(x) for x in struct.unpack_from("<3I", FR, h))]
            if len(hits) != 1:
                continue
            for loc in (x.start() for x in re.finditer(re.escape(struct.pack("<I", hits[0] + 0x08000000)), FR)):
                q = struct.pack("<I", loc - 4 * m + 0x08000000)
                for gl in (x.start() for x in re.finditer(re.escape(q), FR)):
                    cand = gl - 4 * g + 0x08000000
                    if all(is_rom(u32(FR, cand + 4 * k)) for k in range(len(groups["group_order"]))):
                        return cand
        raise SystemExit("French gMapGroups not found")

    gmg_fr = find_fr_gmapgroups()
    fr_header = lambda g, m: u32(FR, u32(FR, gmg_fr + 4 * g) + 4 * m)

    def parse_events(rom, hdr):
        ev, ms = u32(rom, hdr + 4), u32(rom, hdr + 8)
        no, nw, nc, nb = (u8(rom, ev + k) for k in range(4))
        po, pw, pc, pb = (u32(rom, ev + 4 + 4 * k) for k in range(4))
        out = []  # (kind, index, info, script ptr)
        for i in range(no):
            a = po + 24 * i
            out.append(("object", i, dict(local_id=u8(rom, a), x=u16(rom, a + 4), y=u16(rom, a + 6),
                                          flag=u16(rom, a + 0x14)), u32(rom, a + 0x10)))
        for i in range(nc):
            a = pc + 16 * i
            out.append(("coord", i, dict(x=u16(rom, a), y=u16(rom, a + 2), var=u16(rom, a + 6),
                                         value=u16(rom, a + 8)), u32(rom, a + 12)))
        for i in range(nb):
            a = pb + 12 * i
            if u8(rom, a + 5) <= 4:
                out.append(("bg", i, dict(x=u16(rom, a), y=u16(rom, a + 2), facing=u8(rom, a + 5)), u32(rom, a + 8)))
        a, i = ms, 0
        while u8(rom, a):
            t, p = u8(rom, a), u32(rom, a + 1)
            if t in (2, 4):
                b = p
                while u16(rom, b):
                    out.append(("mapscript_t%d" % t, i, dict(var=u16(rom, b), value=u16(rom, b + 2)), u32(rom, b + 4)))
                    i += 1
                    b += 8
            else:
                out.append(("mapscript_t%d" % t, i, {}, p))
                i += 1
            a += 5
        return out

    texts, seen, divergences, arg_diffs = {}, set(), [], []

    def walk(en0, fr0, ctx):
        queue = [(en0, fr0)]
        while queue:
            e, f = queue.pop()
            if (e, f) in seen or not (is_rom(e) and is_rom(f)):
                continue
            seen.add((e, f))
            owner = name_of(e)
            for _ in range(4000):
                op, opf = u8(EN, e), u8(FR, f)
                if op != opf or op not in OPS and op != 0x5c:  # same unknown op on both sides = ran into data
                    divergences.append(dict(script=owner, en=hex(e), fr=hex(f), ctx=ctx))
                    break
                ce = e
                e += 1
                f += 1
                fmt = OPS.get(op, "") if op != 0x5c else "bhh" + TRAINER_PTRS.get(u8(EN, e), "")
                vals = []
                for k in fmt:
                    n = SIZE[k]
                    ve = int.from_bytes(EN[e - 0x08000000:e - 0x08000000 + n], "little")
                    vf = int.from_bytes(FR[f - 0x08000000:f - 0x08000000 + n], "little")
                    e += n
                    f += n
                    vals.append((k, ve, vf))
                    if k in "bhw" and ve != vf:
                        arg_diffs.append(dict(script=owner, at=hex(ce), op=hex(op), en=ve, fr=vf))
                for k, ve, vf in vals:
                    if k == "S":
                        queue.append((ve, vf))
                    elif k in "TL" and is_rom(ve):
                        nxt = u8(EN, e)
                        kind = STD.get(u8(EN, e + 1), "callstd") if (op == 0x0f and nxt == 0x09) else \
                            {0x0f: "loadword", 0x67: "message", 0x85: "bufferstring", 0x5c: "trainerbattle"}.get(op, hex(op))
                        t = texts.setdefault(ve, dict(fr=set(), refs=[]))
                        t["fr"].add(vf)
                        ref = dict(script=owner, cmd=kind, ctx=ctx)
                        if ref not in t["refs"]:
                            t["refs"].append(ref)
                if op in STOP:
                    break

    for g, m, mname in maps:
        he, hf = en_header(g, m), fr_header(g, m)
        assert EN[he - 0x08000000 + 0x10: he - 0x08000000 + 0x1C] == FR[hf - 0x08000000 + 0x10: hf - 0x08000000 + 0x1C], mname
        ee, ef = parse_events(EN, he), parse_events(FR, hf)
        assert [(k, i, d) for k, i, d, _ in ee] == [(k, i, d) for k, i, d, _ in ef], "event layout differs: " + mname
        for (k, i, d, pe), (_, _, _, pf) in zip(ee, ef):
            if pe and pf:
                walk(pe, pf, "%s %s#%d %s" % (mname, k, i, d))

    # English source texts: proof that the labels and the decoder are right
    src, src_file, file_order = {}, {}, defaultdict(list)
    for path in glob.glob(str(em_dir / "data/**/*.inc"), recursive=True):
        rel, cur = os.path.relpath(path, em_dir).replace("\\", "/"), None
        for line in open(path, encoding="utf-8"):
            m = re.match(r"^(\w+)::?\s*$", line)
            if m:
                cur = m.group(1)
                continue
            m = re.match(r'^\s*\.string\s+"(.*)"\s*$', line)
            if m and cur:
                if cur not in src:
                    file_order[rel].append(cur)
                src[cur] = src.get(cur, "") + m.group(1)
                src_file[cur] = rel
            elif line.strip() and not line.strip().startswith("@"):
                cur = None
    norm_src = lambda s: re.sub(r"0x([0-9A-Fa-f]+)", lambda m: str(int(m.group(1), 16)), s.replace("$", ""))

    # labels of the selected maps no script reaches: from the previous resolved text, stored just before
    resolved = {a: next(iter(t["fr"])) for a, t in texts.items() if len(t["fr"]) == 1}
    inferred, checked, contradicted = {}, 0, 0
    for path, labels in file_order.items():
        if not path.startswith("data/maps/" + prefix):
            continue
        seq = sorted((addr[l], l) for l in labels if l in addr)
        follows = lambda j: seq[j][0] + len(raw_string(EN, seq[j][0])) == seq[j + 1][0]
        for idx, (a, _) in enumerate(seq):
            if a in resolved:
                continue
            j = idx - 1
            while j >= 0 and follows(j) and seq[j][0] not in resolved:
                j -= 1
            if j < 0 or seq[j][0] not in resolved or not follows(j):
                continue
            fa = resolved[seq[j][0]]
            for _ in range(j, idx):
                fa += len(raw_string(FR, fa))
            inferred[a] = fa
        for idx in range(1, len(seq)):  # the rule, checked on walked neighbours
            (pa, _), (a, _) = seq[idx - 1], seq[idx]
            if pa in resolved and a in resolved and follows(idx - 1):
                checked += 1
                contradicted += resolved[pa] + len(raw_string(FR, resolved[pa])) != resolved[a]

    rows = []
    for a in sorted(set(texts) | set(inferred)):
        t, fr, label = texts.get(a), resolved.get(a) or inferred.get(a), name_of(a)
        en_txt = decode(raw_string(EN, a))
        fr_txt = decode(raw_string(FR, fr)) if fr else None
        rows.append(dict(label=label, file=src_file.get(label, ""), en_addr="0x%08X" % a,
                         fr_addr=("0x%08X" % fr) if fr else None,
                         method="walk" if a in resolved else "neighbour" if a in inferred else "ambiguous",
                         en=en_txt, fr=fr_txt, fr_wrapped=rewrap(repo_form(fr_txt)) if fr_txt else None,
                         src_match=(norm_src(src[label]) == en_txt) if label in src else None,
                         refs=t["refs"] if t else []))
    own = [l for p, ls in file_order.items() if p.startswith("data/maps/" + prefix) for l in ls]
    missing = [l for l in own if l not in {r["label"] for r in rows if r["fr"]}]
    src_checked = [r for r in rows if r["src_match"] is not None]
    report = [
        "French gMapGroups = %s; maps %d; scripts walked %d; divergences %d; non-pointer argument diffs %d"
        % (hex(gmg_fr), len(maps), len(seen), len(divergences), len(arg_diffs)),
        "texts reached by the walk %d (common ones included), from neighbours %d (rule checked on %d pairs, %d "
        "contradictions); English decode == pokeemerald source: %d / %d"
        % (len(resolved), len(inferred), checked, contradicted, sum(r["src_match"] for r in src_checked), len(src_checked)),
        "labels of the %s* script files: %d, French found: %d, missing: %s" % (prefix, len(own), len(own) - len(missing), missing),
        "re-wrapped for the FRLG box: %d texts (%d gained a line)" % (
            sum(repo_form(r["fr"]) != r["fr_wrapped"] for r in rows if r["fr"]),
            sum(len(printed_lines(r["fr_wrapped"])) > len(printed_lines(r["fr"])) for r in rows if r["fr"])),
    ]
    assert src_checked and sum(r["src_match"] for r in src_checked) / len(src_checked) > 0.95, "decoder/labels broken"
    too_long = [(r["label"], x) for r in rows if r["fr"] for x, _, _ in too_wide(r["fr_wrapped"]) if " " in x.strip()]
    assert not too_long, "re-wrap left lines over their limit: %s" % too_long[:5]
    return rows, report


def repo_form(fr):
    """An official French text as this repo writes it (re-wrap aside)."""
    return fr.replace("{POKEBLOCK}", FR_POKEBLOCK)


def repo_symbols():
    """Labels this repo already defines: asm (data/) and C arrays (src/). Emerald and FRLG share some common names
    (CableClub_Text_*, EventTicket_Text_*...): those stay FRLG's."""
    read = lambda p: p.read_text(encoding="utf-8", errors="replace")
    asm = [p for ext in ("inc", "s") for p in REPO.glob("data/**/*." + ext)]
    return ({l for p in asm for l in re.findall(r"^(\w+)::?", read(p), re.M)}
            | {l for p in REPO.glob("src/**/*.c") for l in re.findall(r"\b(\w+)\[\]\s*=", read(p))})


def write_texts(rows, prefix):
    """Append the extracted texts each map's scripts.inc names to its text.inc, re-wrap the official ones already
    there (see --write)."""
    by_label = {r["label"]: r["fr_wrapped"] for r in rows if r["fr"]}
    official = {r["label"]: words(repo_form(r["fr"])) for r in rows if r["fr"]}
    event_scripts = REPO / "data/event_scripts.s"
    known = repo_symbols()
    for scripts in sorted((REPO / "data/maps").glob(prefix + "*/scripts.inc")):
        text_inc = scripts.parent / "text.inc"
        old = text_inc.read_text(encoding="utf-8") if text_inc.exists() else ""
        body, redone = old, []
        for label, cur in (read_inc_texts(text_inc) if old else {}).items():
            if label not in by_label or cur == by_label[label]:
                continue
            if words(repo_form(cur)) != official[label]:
                print("%s: %s adapted by hand, kept" % (text_inc.relative_to(REPO).as_posix(), label))
                continue
            body = re.sub(r"^%s::\n(?:[ \t]*\.string .*\n)+" % label, lambda _: to_inc(label, by_label[label])[:-1],
                          body, count=1, flags=re.M)
            redone.append(label)
        used = re.findall(r"\b\w+\b", re.sub(r"@.*", "", scripts.read_text(encoding="utf-8")))
        new = [l for l in dict.fromkeys(used) if l in by_label and l not in known]
        known |= set(new)
        if redone:
            print("%s: re-wrapped %s" % (text_inc.relative_to(REPO).as_posix(), redone))
        if not new and body == old:
            continue
        added = "".join(to_inc(l, by_label[l]) for l in new).rstrip("\n") + "\n" if new else ""
        with open(text_inc, "w", encoding="utf-8", newline="") as f:
            f.write(body + ("\n" if body and added and not body.endswith("\n\n") else "") + added)
        if not new:
            continue
        inc = '\t.include "data/maps/%s/%s"\n'
        text = event_scripts.read_text(encoding="utf-8")
        if inc % (scripts.parent.name, "text.inc") not in text:
            anchor = inc % (scripts.parent.name, "scripts.inc")
            assert anchor in text, "%s is not included in data/event_scripts.s" % scripts
            with open(event_scripts, "w", encoding="utf-8", newline="") as f:
                f.write(text.replace(anchor, anchor + inc % (scripts.parent.name, "text.inc"), 1))
        print("%s: +%d texts %s" % (text_inc.relative_to(REPO).as_posix(), len(new), new))


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("prefix", nargs="?", help="Emerald map name prefix, e.g. LilycoveCity (its interiors too)")
    parser.add_argument("--emerald", type=Path, default=REPO.parent / "pokeemerald")
    parser.add_argument("--rom", type=Path, default=REPO / "Pokemon - Version Emeraude (FR).gba")
    parser.add_argument("--out", type=Path, default=REPO / "build/hoenn_texts")
    parser.add_argument("--write", action="store_true", help="append the texts scripts.inc names to text.inc")
    parser.add_argument("--check", nargs="+", metavar="TEXT_INC", help="only check that these texts fit the box")
    args = parser.parse_args()
    sys.stdout.reconfigure(encoding="utf-8")
    selftest()
    if args.check:
        raise SystemExit(0 if check(args.check) else 1)
    if not args.prefix:
        parser.error("no map prefix given")
    rows, report = extract(args.emerald.resolve(), args.rom.resolve(), args.prefix)
    args.out.mkdir(parents=True, exist_ok=True)
    with open(args.out / (args.prefix + "_fr_texts.json"), "w", encoding="utf-8") as f:
        json.dump(rows, f, ensure_ascii=False, indent=1)
    with open(args.out / (args.prefix + "_fr_texts.inc"), "w", encoding="utf-8", newline="") as f:
        for r in sorted(rows, key=lambda r: (r["file"], r["en_addr"])):
            if r["fr"]:
                f.write("@ %s  EN %s  FR %s  (%s)%s  %s\n" % (
                    r["file"] or "common", r["en_addr"], r["fr_addr"], r["method"],
                    "  RE-WRAPPED" if r["fr"] != r["fr_wrapped"] else "",
                    "; ".join(sorted({"%s %s" % (x["cmd"], x["ctx"].split(" {")[0]) for x in r["refs"]}))))
                f.write(to_inc(r["label"], r["fr_wrapped"]))
    print("\n".join(report))
    print("-> %s" % (args.out / (args.prefix + "_fr_texts.inc")))
    if args.write:
        write_texts(rows, args.prefix)


if __name__ == "__main__":
    main()
