#!/usr/bin/env bash
# build.sh — сборка кастомного FBL и полного образа NOR 16 МБ для Banana Pi BPI-RV2
set -e
cd "$(dirname "$0")/.."
PYTHONPATH=. python3 scripts/build.py "$@"
