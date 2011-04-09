#include "ids.h"

Rage::Frame largeBlueBlockFrames[2];

largeBlueBlockFrames[0].index = 1; largeBlueBlockFrames[0].duration = 30;
largeBlueBlockFrames[1].index = 0; largeBlueBlockFrames[1].duration = 60;


Rage::Frame largeBlueBlockHole;

largeBlueBlockHole.index = 0; largeBlueBlockHole.duration = 60;


Rage::Animation largeBlueBlockAnimations[2];

largeBlueBlockAnimations[0].image.gfx = large_blockbTiles;
largeBlueBlockAnimations[0].image.gfxLen = large_blockbTilesLen;
largeBlueBlockAnimations[0].image.pal = large_blockbPal;
largeBlueBlockAnimations[0].image.palLen = large_blockbPalLen;
largeBlueBlockAnimations[0].size = SpriteSize_32x32;
largeBlueBlockAnimations[0].looping = false;
largeBlueBlockAnimations[0].frameCount = 2;
largeBlueBlockAnimations[0].frames = largeBlueBlockFrames;

largeBlueBlockAnimations[1].image.gfx = large_blockb_holeTiles;
largeBlueBlockAnimations[1].image.gfxLen = large_blockb_holeTilesLen;
largeBlueBlockAnimations[1].image.pal = large_blockb_holePal;
largeBlueBlockAnimations[1].image.palLen = large_blockb_holePalLen;
largeBlueBlockAnimations[1].size = SpriteSize_32x32;
largeBlueBlockAnimations[1].looping = false;
largeBlueBlockAnimations[1].frameCount = 1;
largeBlueBlockAnimations[1].frames = &largeBlueBlockHole;


Rage::SpriteDefinition largeBlueBlockDef;

largeBlueBlockDef.version = 2;
largeBlueBlockDef.spriteID = BLOCK_BLUE;
largeBlueBlockDef.animationCount = 2;
largeBlueBlockDef.animations = largeBlueBlockAnimations;
