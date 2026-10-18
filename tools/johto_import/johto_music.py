#!/usr/bin/env python3
"""Import PokemonHnS's HeartGold/SoulSilver music the Johto maps play (MUS_HG_*), with its instruments.

Usage, from the repo root, before tools/johto_import/johto_import.py, then build as usual:
    uv run --no-project python tools/johto_import/johto_music.py [--hns ../pokehns] [--check]

The songs: every MUS_HG_ a Johto map plays (johto_import's selection), plus the HGSS surf and bicycle themes (Johto's
regional field music, overworld.c). HnS builds them with mid2agb on its voicegroup 229 ("HGSS main"), whose voicegroups,
key split tables and samples (WAV, converted by tools/wav2agb, copied from HnS: MIT, ipatix) are copied:
  sound/songs/midi/mus_hg_*.mid             HnS's MIDIs; songs.mk rules with HnS's mid2agb flags, -G renumbered
  sound/voicegroups/voicegroupNNN.inc       HnS's voicegroups, numbered after this repo's (192..), append-only
  sound/keysplit_tables.inc                 KeySplitTableJohtoN = HnS's KeySplitTableN
  sound/direct_sound_samples/johto/*.wav    HnS's samples this repo lacks (DirectSoundWaveData_ names kept)
  include/constants/songs.h, sound/song_table.inc, ld_script.ld: MUS_HG_* after the last song (610..), append-only
Generated parts sit between "BEGIN/END johto_music" comment lines. Credits: CREDITS_JOHTO.md.
"""
import argparse
import re
import shutil
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
MARK = "johto_music"
EXTRA = ["mus_hg_surf", "mus_hg_cycling"]  # Johto's regional field music (overworld.c GetRegionalFieldMusic)


def read(path):
    with open(path, encoding="utf-8", newline="") as f:
        return f.read()


def labels(text):
    parts = re.split(r"^(\w+)::?[ \t]*(?:@[^\n]*)?$", text, flags=re.M)
    return dict(zip(parts[1::2], parts[2::2]))


def put_block(text, comment, body, anchor_after=None, anchor_before=None, end=None):
    """`text` with `body` between "<comment> BEGIN/END johto_music" lines (replaced if there)."""
    end = end or ""
    begin_l, end_l = "%s BEGIN %s%s\n" % (comment, MARK, end), "%s END %s%s\n" % (comment, MARK, end)
    nl = "\r\n" if "\r\n" in text else "\n"
    t = text.replace("\r\n", "\n")
    content = begin_l + body + ("" if body.endswith("\n") or not body else "\n") + end_l
    if begin_l in t:
        a = t.index(begin_l)
        b = t.index(end_l, a) + len(end_l)
        t = t[:a] + content + t[b:]
    elif anchor_after:
        m = list(re.finditer(anchor_after, t, re.M))[-1]
        t = t[:m.end()] + content + t[m.end():]
    elif anchor_before:
        m = re.search(anchor_before, t, re.M)
        t = t[:m.start()] + content + t[m.start():]
    else:
        t = t + ("" if t.endswith("\n") else "\n") + content
    return t.replace("\n", nl)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--hns", type=Path, default=REPO.parent / "pokehns", help="PokemonHnS clone")
    ap.add_argument("--check", action="store_true", help="write nothing; exit 1 if a file would change")
    args = ap.parse_args()
    hns = args.hns
    sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "hoenn_import"))
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    import johto_import as ji
    h = ji.HnS(hns)
    order, _ = ji.select(h)
    songs = sorted({h.maps[m]["music"].lower() for m in order} - {"mus_none"}) + EXTRA
    cfg = dict(re.findall(r"^(mus_\w+)\.mid:\s*([^\n]*)", read(hns / "sound/songs/midi/midi.cfg"), re.M))
    missing = [s for s in songs if s not in cfg or not (hns / "sound/songs/midi" / (s + ".mid")).exists()]
    if missing:
        raise SystemExit("not in HnS's sound/songs/midi: %s" % missing)

    # voicegroups: the closure of the songs' -G ones, numbered after this repo's own (kept from the last run)
    vg_text = {}
    for p in (hns / "sound/voicegroups").glob("*.inc"):
        vg_text.update(labels(read(p)))
    todo = ["voicegroup%03d" % int(re.search(r"-G(\d+)", cfg[s]).group(1)) for s in songs]
    order_vg, samples, keysplits = [], [], []
    while todo:
        vg = todo.pop(0)
        if vg in order_vg:
            continue
        order_vg.append(vg)
        body = vg_text[vg]
        todo += [v for v in re.findall(r"\b(voicegroup\d+)\b", body) if v not in order_vg]
        samples = list(dict.fromkeys(samples + re.findall(r"\bDirectSoundWaveData_\w+", body)))
        keysplits = list(dict.fromkeys(keysplits + re.findall(r"\bKeySplitTable\d+", body)))
    vgi = read(REPO / "sound/voice_groups.inc")
    previous = dict(re.findall(r'voicegroup(\d+)\.inc" @ HnS (voicegroup\d+)', vgi))
    previous = {hv: int(n) for n, hv in previous.items()}
    own = set(re.findall(r'"sound/voicegroups/(voicegroup\d+)\.inc"', vgi)) - {"voicegroup%03d" % n for n in previous.values()}
    first = max(int(v[10:]) for v in own) + 1
    number = dict(previous)
    for vg in order_vg:
        if vg not in number:
            number[vg] = max(list(number.values()) + [first - 1]) + 1
    rename = lambda text: re.sub(r"\bvoicegroup(\d+)\b", lambda m: "voicegroup%03d" % number["voicegroup%s" % m.group(1)],
                                 re.sub(r"\bKeySplitTable(\d+)\b", r"KeySplitTableJohto\1", text))
    files = {}  # repo path -> text
    copies = {}  # repo path -> HnS path
    for vg in order_vg:
        files["sound/voicegroups/voicegroup%03d.inc" % number[vg]] = (
            "@ johto_music: PokemonHnS sound/voicegroups (%s)\n\t.align 2\n%s::%s" % (
                vg, rename(vg), rename(vg_text[vg]).rstrip() + "\n"))
    # samples this repo lacks (by name)
    ds_here = read(REPO / "sound/direct_sound_data.inc")
    ds_hns = read(hns / "sound/direct_sound_data.inc")
    new_samples = [s for s in samples if not re.search(r"^%s::" % s, ds_here, re.M) or "johto/" in ds_here.split(s + "::", 1)[1][:200]]
    ds_lines = []
    for s in new_samples:
        src = re.search(r"^%s::\s*\n\s*\.incbin \"([^\"]+)\.bin\"" % s, ds_hns, re.M).group(1)
        name = Path(src).name
        if not (hns / (src + ".wav")).exists():
            raise SystemExit("%s: no %s.wav in HnS" % (s, src))
        copies["sound/direct_sound_samples/johto/%s.wav" % name] = src + ".wav"
        ds_lines.append("\t.align 2\n%s::\n\t.incbin \"sound/direct_sound_samples/johto/%s.bin\"\n\n" % (s, name))
    # key split tables
    ks_hns = read(hns / "sound/keysplit_tables.inc").replace("\r\n", "\n")
    ks_lines = []
    for k in keysplits:
        m = re.search(r"^\.set %s, [^\n]*\n(?:[ \t]*\.byte[^\n]*\n)+" % k, ks_hns, re.M)
        ks_lines.append(rename(m.group(0)) + "\n")
    # songs: ids after the last one (kept from the last run)
    songs_h = read(REPO / "include/constants/songs.h")
    old_ids = {n.lower(): int(v) for n, v in re.findall(r"^#define (MUS_HG_\w+)\s+(\d+)", songs_h, re.M)}
    base = max(int(v) for n, v in re.findall(r"^#define ((?:MUS|SE|PH)_\w+)\s+(\d+)\b", songs_h, re.M)
               if not n.startswith("MUS_HG_")) + 1
    ids = dict(old_ids)
    for s in songs:
        if s not in ids:
            ids[s] = max(list(ids.values()) + [base - 1]) + 1
    by_id = sorted(ids, key=ids.get)
    assert [ids[s] for s in by_id] == list(range(base, base + len(by_id))), "MUS_HG_ ids must follow the last song"
    for s in songs:
        copies["sound/songs/midi/%s.mid" % s] = "sound/songs/midi/%s.mid" % s

    out = {}
    out["sound/voice_groups.inc"] = put_block(vgi, "@", "".join(
        '.include "sound/voicegroups/voicegroup%03d.inc" @ HnS %s\n' % (number[v], v) for v in order_vg))
    out["sound/direct_sound_data.inc"] = put_block(ds_here, "@", "".join(ds_lines))
    out["sound/keysplit_tables.inc"] = put_block(read(REPO / "sound/keysplit_tables.inc"), "@", "".join(ks_lines))
    out["songs.mk"] = put_block(read(REPO / "songs.mk"), "#", "".join(
        "$(MID_SUBDIR)/%s.s: %%.s: %%.mid\n\t$(MID) $< $@ %s\n\n" % (
            s, re.sub(r"-G(\d+)", lambda m: "-G%03d" % number["voicegroup%03d" % int(m.group(1))], cfg[s]).strip())
        for s in by_id))
    out["include/constants/songs.h"] = put_block(songs_h, "//", "".join(
        "#define %-30s %d // PokemonHnS (HeartGold/SoulSilver)\n" % (s.upper(), ids[s]) for s in by_id),
        anchor_after=r"^#define PH_NURSE_SOLO\s+\d+[^\n]*\n")
    out["sound/song_table.inc"] = put_block(read(REPO / "sound/song_table.inc"), "@", "".join(
        "\tsong %s, 0, 0\n" % s for s in by_id), anchor_after=r"^\tsong ph_nurse_solo[^\n]*\n")
    out["ld_script.ld"] = put_block(read(REPO / "ld_script.ld"), "        /*", "".join(
        "        sound/songs/midi/%s.o(.rodata);\n" % s for s in by_id),
        anchor_after=r"^[ \t]*sound/songs/midi/ph_nurse_solo\.o\(\.rodata\);\n", end=" */")
    out.update(files)
    changed = []
    for p, text in out.items():
        path = REPO / p
        if not path.exists() or read(path) != text:
            changed.append(p)
            if not args.check:
                path.parent.mkdir(parents=True, exist_ok=True)
                with open(path, "w", encoding="utf-8", newline="") as f:
                    f.write(text)
    for dst, src in copies.items():
        if not (REPO / dst).exists() or (REPO / dst).read_bytes() != (hns / src).read_bytes():
            changed.append(dst)
            if not args.check:
                (REPO / dst).parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(hns / src, REPO / dst)
    print("%d songs (MUS_HG_ %d..%d), %d voicegroups (%03d..%03d), %d key split tables, %d samples" % (
        len(by_id), base, base + len(by_id) - 1, len(order_vg), min(number.values()), max(number.values()),
        len(keysplits), len(new_samples)))
    print(("would change: " if args.check else "changed: ") + ("%d files" % len(changed) if changed else "nothing"))
    if args.check and changed:
        sys.exit(1)


if __name__ == "__main__":
    main()
