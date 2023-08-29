# QMK for gnu/linux

## Reason

https://github.com/qmk/qmk_firmware

https://github.com/rvaiya/keyd

https://github.com/kmonad/kmonad

https://github.com/manna-harbour/xmk

`keyd` and `kmonad` are both nice, but typing feels different (not necessarily
_bad_, just different) from `qmk` (ok, typing on laptop feels bad anyway...)

`xmk` has x86 but only for `zmk`. I like `qmk` better and probably hacking this
together took the same amount of time I would have needed to fight with Weston
and Zephyr and their weird config and unintelligible errors (I did that some
time ago and it was no fun)

## How does it work

Input/output same as `keyd` (grab device / output on uinput), processing `qmk`.

You'll have to run as `root` (or change permissions for `uinput` and add your
user to `input` group - bad security!)

## Config

Do a `make` first to rule out other problems. If the build is ok, look in

### Makefile

First couple of lines, should be obvious. This is _instead of_ qmk's `config.h`
and `rules.mk`. Of course, there's only a fraction of qmk's settings to worry
about.

### `keyboards/<some_kb>/kb.c`

This is qmk's `<kb_name>.c`.

### `keyboards/<some_kb>/keymap.c`

`qmk`'s layers

### `keyboards/<some_kb>/layout.cpp`

`kbName` and `kbBlacklist` are for picking the input (you can check your
keyboard's name with `xinput` for instance).

`layout` - rows on your physical keyboard. For key names look in
`platforms/x86/cpp/keynames.cpp`.

It doesn't matter how you distribute your keys on rows/columns, it just has to
be the same in layout/keymap (it _doesn't_ have to look like a picture of your
keyboard)

## Hacking

Besides `qmk`, almost all relevant code is in `platforms/x86`. I did very few
changes to `qmk` (but removed a lot from it, mostly to be able to search for
things more easily).

Makefile... well, can't build `qmk` with g++ and I was too lazy to write C.

For other qmk features (like leader key, tap-dance, ...) you'll have to enable
them in Makefile, find the needed files, add them to the Makefile and fix build
errors.

I think at least a mutex is needed for `catrix` (var name to avoid "matrix").
But it hasn't crashed on me yet.

Plenty of room for improvement, like sleeping longer than 20ms in main loop and
waking it with an interrupt. Integrating with upstream qmk as another platform
(even though I don't think future improvements in qmk will benefit a standard or
laptop keyboard).

## Copyright

Whatever `qmk` and `keyd` have (this is mostly copy/paste from those 2
projects).
