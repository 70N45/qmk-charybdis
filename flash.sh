#!/bin/bash
set -e

KEYBOARD="bastardkb/charybdis/4x6/v2/splinky_3"
KEYMAP="default"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Install QMK if not present
if ! command -v qmk &>/dev/null; then
  echo "Installing QMK..."
  brew install qmk/qmk/qmk
fi

# Set up QMK firmware repo if not done
QMK_HOME="$(qmk config -ro user.qmk_home 2>/dev/null | cut -d= -f2 || echo "$HOME/qmk_firmware")"
if [ ! -d "$QMK_HOME" ]; then
  echo "Setting up QMK firmware..."
  qmk setup -y
fi

# Sync keymap files into QMK firmware
KEYMAP_DIR="$QMK_HOME/keyboards/$KEYBOARD/keymaps/$KEYMAP"
echo "Syncing keymap to $KEYMAP_DIR..."
mkdir -p "$KEYMAP_DIR"
cp "$SCRIPT_DIR/$KEYMAP/"* "$KEYMAP_DIR/"

# Compile
echo "Compiling..."
qmk compile -kb "$KEYBOARD" -km "$KEYMAP"

# Find the built .uf2
UF2=$(find "$QMK_HOME" -maxdepth 1 -name "*.uf2" | grep "$(echo "$KEYBOARD" | tr '/' '_')_${KEYMAP}" | tail -1)
if [ -z "$UF2" ]; then
  echo "Error: could not find compiled .uf2 file."
  exit 1
fi
echo "Built: $UF2"

# Copy built artifact back to repo
cp "$UF2" "$SCRIPT_DIR/"
echo "Copied .uf2 to repo directory."

# Flash
echo ""
echo "Put the keyboard into bootloader mode (double-tap reset or hold BOOT while plugging in)."
echo "Waiting for RPI-RP2 volume..."

RPI_VOLUME=""
while [ -z "$RPI_VOLUME" ]; do
  RPI_VOLUME=$(ls /Volumes/ 2>/dev/null | grep -i "RPI-RP2" || true)
  [ -z "$RPI_VOLUME" ] && sleep 1
done

echo "Found volume: /Volumes/$RPI_VOLUME — flashing..."
cp "$UF2" "/Volumes/$RPI_VOLUME/"
echo "Done! The keyboard will reboot automatically."
