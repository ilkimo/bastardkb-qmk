# ilkimo — Charybdis 4x6

Personal keymap. Colemak-based with home-row mods (Achordion), leader key,
combos, tap dance, swap-hands, dynamic macros and a Unicode/emoji layer.

## Build

```sh
qmk compile -kb bastardkb/charybdis/4x6/splinktegrated_rev1 -km ilkimo
```

Note the `/splinktegrated_rev1` suffix: upstream split the old flat
`charybdis/4x6` target into per-controller variants. `splinktegrated_rev1`
carries the pinout that the old `4x6/keyboard.json` used.

## ⚠️ Hardware modification — not upstream

This board uses **`GP14` instead of `GP28`** for matrix column 2. That change
lives in:

    keyboards/bastardkb/charybdis/4x6/splinktegrated_rev1/keyboard.json

`keyboard.json` is strict JSON and cannot hold a comment, which is why the note
lives here instead. Two things to know:

1. It is the only change outside this keymap directory, so it is the one thing
   an upstream sync can silently revert. Re-check it after every merge.
2. If you are flashing a **different** Charybdis than the modified one, revert
   that pin to `GP28` first or column 2 will not register.

## Tuning

Tap-hold, leader and combo timings live in `config.h` in this directory
(keymap-level), not in the keyboard-level `config.h`, so upstream syncs do not
conflict with them.
