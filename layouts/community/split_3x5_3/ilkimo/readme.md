# ilkimo — split_3x5_3 community layout

Personal keymap shared by every `split_3x5_3` board. Colemak-based with home-row
mods (Achordion), leader key, combos, tap dance, swap-hands, dynamic macros and
a Unicode/emoji layer.

It lives here rather than under a single keyboard so both Dilemmas build from
one source — edit once, both boards get it.

## Build

```sh
# Dilemma v2 (3x5+3)
qmk compile -kb bastardkb/dilemma/3x5_3 -km ilkimo

# Dilemma v3 (3x5+3, Procyon controller)
qmk compile -kb bastardkb/dilemma/3x5_3_procyon -km ilkimo
```

Both declare `"community_layouts": ["split_3x5_3"]` and expose
`LAYOUT_split_3x5_3`, so this keymap is portable between them unchanged.

## Why it ports cleanly

The two boards differ in pointing hardware — v2 uses a Cirque trackpad over
SPI, v3 a digitizer over I2C (`DIGITIZER_MOTION_PIN`, `PROCYON_42_50`). This
keymap contains no pointing-device code at all (`MOUSE_Z` is a layer-tap, not
trackball logic), so that difference stays in the keyboard-level config where
it belongs.

## Tuning

Tap-hold, leader and combo timings are in `config.h` here, not in any
keyboard-level `config.h`, so upstream syncs don't conflict with them.

## Related

The Charybdis 4x6 keeps its own copy under
`keyboards/bastardkb/charybdis/4x6/keymaps/ilkimo/` — it uses a different
layout macro and can't share this one. Changes made here are not picked up
there automatically.
