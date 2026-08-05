# ilkimo — Dilemma 3x5_3

Personal keymap, kept in sync with the Charybdis 4x6 `ilkimo` keymap.
Colemak-based with home-row mods (Achordion), leader key, combos, tap dance,
swap-hands, dynamic macros and a Unicode/emoji layer.

## Build

```sh
qmk compile -kb bastardkb/dilemma/3x5_3 -km ilkimo
```

## Tuning

Tap-hold, leader and combo timings live in `config.h` in this directory
(keymap-level), not in the keyboard-level `config.h`, so upstream syncs do not
conflict with them.

This keymap requires no changes outside its own directory.
