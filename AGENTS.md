This repo is a personal QMK fork 

## Keyboards I own

Although there are many legacy keymaps, assume only the following keyboards in this repo's `keyboards` folder are mine and in active use:
- `keychron/q1v2/ansi_encoder/keymaps/endlessreform`: Keychron Q1 (75%, with physical Space Cadet legends)
- `novelkeys/nk_classic_tkl/keymaps/endlessreform`: TKL Tsangan, with physical Git and Space Cadet legends
- `1upkeyboards/pi60_hse/keymaps/endlessreform`: 60% Tsangan + split right shift / split backspace. This board is acceptable to make Mac-only.

Update this section of `AGENTS.md` if I ever purchase another board.

## Guidelines

QMK layouts are a bit out of your distribution as a coding agent, so your instincts might be wrong. To combat hallucinations,
- The `qmk` CLI is installed on PATH. So always ensure the keymap compiles before you call any of your changes done.
- Remember that you are IN the QMK repo. If you are unsure about what something does, you can always search through the docs or ground-truth implemntation here: for key scancodes, concepts like macros, or keyboard implementation details like physical vs exposed layout, MCUs, etc. Never ask me to Google or 'check the docs' unless you prove to me you have 'done your homework' and there is genuinely nothing here.
- If you 'come up short', remember that this is a fork and might be out of date with upstream, sometimes by years. Give this a check first.

## Philosophy
- **IMPORTANT!** To the extent possible, core keymaps should stay in sync with each other to preserve muscle memory. When making a change to one keyboard, that change should go across all keyboards, unless the layout doesn't permit it (e.g. when editing F-keys on a TKL, don't update a 60%). Assume I want a change to roll out across _all_ keyboards unless it is abundantly obvious what I am doing only is intended for / works on one.
    - Please refer to one of the existing keymaps as a starting point. There is a moderately complex personal layout (Base, FN, Markdown, Git layers) that have too many pre-existing idioms to list here.
    - Exception: the only LaTeX layer keyboards are the ones with actual Space Cadet physical key legends (Classic TKL and Keychron Q1).
- Muscle memory and composability are important. No matter how cool a feature is, if it's not intuitive, not ergonomic, and not consistent, it won't be used.
- Consistency and reliability are also important. I'm interested to hear about more complex features, but fiddly concepts (e.g. leader keys) need strong justification. An example of something I rejected due to fiddly-ness was Space Cadet Shift (vs paren) since in practice I kept triggering this accidentally, Shift was too important to overload.
- Assume binds are Mac-first but should work on Linux. Windows is not a concern except insofar as Linux DEs use Windows-like idioms.
- Gaming and non-typing usages are not a _top_ priority, but shouldn't be unnecessarily difficult/require rebind. For example, don't set tap/hold on Space (blocks jumping and pan in Figma).

### Mnemonics for keybinds
**Don't add keybinds without first consulting me** - my 'buy-in' is necessary for memory. However, it is very important that key Propose 2-4 options, using the following heuristics:
- First-letter mnemonics, including symbols (e.g. on Git layer, `git + r` for 'remote'). Default to this first.
- Conceptual equivalents for special keys: e.g. in LaTeX layer, the * key corresponds to $\cdot$, or in Git, the -- convenience flag (for CLI options) sits as 'stronger -' and the `revert ` as a 'stronger Backspace'. 
- Idiomatic keybinds from strong contexts of use: e.g. FN + hjkl corresponds to Vim arrow keys. Avoid outright collisions, but try to draw on existing muscle memory. Assume my intutions come from Vim, common applications like web browsers or Windows (e.g. `Win+E` and `F12` mean something semantically), and/or VS Code (e.g. `Ctrl/Cmd +B` to pull up a bar)

Antipatterns are:
- Positional keys (aside from the media keys on WASD, which is a historical antipattern).
- Too many combos: Insofar as possible, avoid scenarios where more than 2 keys have to be held down at one time
