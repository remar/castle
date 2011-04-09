#include "ids.h"

Rage::Frame largeGreenBlockFrames[2];

largeGreenBlockFrames[0].index = 1; largeGreenBlockFrames[0].duration = 30;
largeGreenBlockFrames[1].index = 0; largeGreenBlockFrames[1].duration = 60;


Rage::Frame largeGreenBlockHole;

largeGreenBlockHole.index = 0; largeGreenBlockHole.duration = 60;


Rage::Animation largeGreenBlockAnimations[2];

largeGreenBlockAnimations[0].image.gfx = large_blockgTiles;
largeGreenBlockAnimations[0].image.gfxLen = large_blockgTilesLen;
largeGreenBlockAnimations[0].image.pal = large_blockgPal;
largeGreenBlockAnimations[0].image.palLen = large_blockgPalLen;
largeGreenBlockAnimations[0].size = SpriteSize_32x32;
largeGreenBlockAnimations[0].looping = false;
largeGreenBlockAnimations[0].frameCount = 2;
largeGreenBlockAnimations[0].frames = largeGreenBlockFrames;

largeGreenBlockAnimations[1].image.gfx = large_blockg_holeTiles;
largeGreenBlockAnimations[1].image.gfxLen = large_blockg_holeTilesLen;
largeGreenBlockAnimations[1].image.pal = large_blockg_holePal;
largeGreenBlockAnimations[1].image.palLen = large_blockg_holePalLen;
largeGreenBlockAnimations[1].size = SpriteSize_32x32;
largeGreenBlockAnimations[1].looping = false;
largeGreenBlockAnimations[1].frameCount = 1;
largeGreenBlockAnimations[1].frames = &largeGreenBlockHole;


Rage::SpriteDefinition largeGreenBlockDef;

largeGreenBlockDef.version = 2;
largeGreenBlockDef.spriteID = BLOCK_GREEN;
largeGreenBlockDef.animationCount = 2;
largeGreenBlockDef.animations = largeGreenBlockAnimations;
