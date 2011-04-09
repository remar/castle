#!/bin/bash
cp levels/tiles.png gfx/tiles.png
mkdir -p data
cp levels/level_* data/
rename 's/coe/bin/' data/*
make
