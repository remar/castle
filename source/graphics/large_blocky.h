#include "ids.h"

Rage::Frame largeYellowBlockFrames[2];

largeYellowBlockFrames[0].index = 1; largeYellowBlockFrames[0].duration = 30;
largeYellowBlockFrames[1].index = 0; largeYellowBlockFrames[1].duration = 60;


Rage::Frame largeYellowBlockHole;

largeYellowBlockHole.index = 0; largeYellowBlockHole.duration = 60;


Rage::Animation largeYellowBlockAnimations[2];

largeYellowBlockAnimations[0].image.gfx = large_blockyTiles;
largeYellowBlockAnimations[0].image.gfxLen = large_blockyTilesLen;
largeYellowBlockAnimations[0].image.pal = large_blockyPal;
largeYellowBlockAnimations[0].image.palLen = large_blockyPalLen;
largeYellowBlockAnimations[0].size = SpriteSize_32x32;
largeYellowBlockAnimations[0].looping = false;
largeYellowBlockAnimations[0].frameCount = 2;
largeYellowBlockAnimations[0].frames = largeYellowBlockFrames;

largeYellowBlockAnimations[1].image.gfx = large_blocky_holeTiles;
largeYellowBlockAnimations[1].image.gfxLen = large_blocky_holeTilesLen;
largeYellowBlockAnimations[1].image.pal = large_blocky_holePal;
largeYellowBlockAnimations[1].image.palLen = large_blocky_holePalLen;
largeYellowBlockAnimations[1].size = SpriteSize_32x32;
largeYellowBlockAnimations[1].looping = false;
largeYellowBlockAnimations[1].frameCount = 1;
largeYellowBlockAnimations[1].frames = &largeYellowBlockHole;


Rage::SpriteDefinition largeYellowBlockDef;

largeYellowBlockDef.version = 2;
largeYellowBlockDef.spriteID = BLOCK_YELLOW;
largeYellowBlockDef.animationCount = 2;
largeYellowBlockDef.animations = largeYellowBlockAnimations;
