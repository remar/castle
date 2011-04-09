#include "ids.h"

Rage::Frame smallGreenBlockFrames[2];

smallGreenBlockFrames[0].index = 1; smallGreenBlockFrames[0].duration = 30;
smallGreenBlockFrames[1].index = 0; smallGreenBlockFrames[1].duration = 60;


Rage::Frame smallGreenBlockHole;

smallGreenBlockHole.index = 0; smallGreenBlockHole.duration = 60;


Rage::Animation smallGreenBlockAnimations[2];

smallGreenBlockAnimations[0].image.gfx = small_blockgTiles;
smallGreenBlockAnimations[0].image.gfxLen = small_blockgTilesLen;
smallGreenBlockAnimations[0].image.pal = small_blockgPal;
smallGreenBlockAnimations[0].image.palLen = small_blockgPalLen;
smallGreenBlockAnimations[0].size = SpriteSize_16x16;
smallGreenBlockAnimations[0].looping = false;
smallGreenBlockAnimations[0].frameCount = 2;
smallGreenBlockAnimations[0].frames = smallGreenBlockFrames;

smallGreenBlockAnimations[1].image.gfx = small_blockg_holeTiles;
smallGreenBlockAnimations[1].image.gfxLen = small_blockg_holeTilesLen;
smallGreenBlockAnimations[1].image.pal = small_blockg_holePal;
smallGreenBlockAnimations[1].image.palLen = small_blockg_holePalLen;
smallGreenBlockAnimations[1].size = SpriteSize_16x16;
smallGreenBlockAnimations[1].looping = false;
smallGreenBlockAnimations[1].frameCount = 1;
smallGreenBlockAnimations[1].frames = &smallGreenBlockHole;


Rage::SpriteDefinition smallGreenBlockDef;

smallGreenBlockDef.version = 2;
smallGreenBlockDef.spriteID = BLOCK_GREEN;
smallGreenBlockDef.animationCount = 2;
smallGreenBlockDef.animations = smallGreenBlockAnimations;
