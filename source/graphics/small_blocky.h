#include "ids.h"

Rage::Frame smallYellowBlockFrames[2];

smallYellowBlockFrames[0].index = 1; smallYellowBlockFrames[0].duration = 30;
smallYellowBlockFrames[1].index = 0; smallYellowBlockFrames[1].duration = 60;


Rage::Frame smallYellowBlockHole;

smallYellowBlockHole.index = 0; smallYellowBlockHole.duration = 60;


Rage::Animation smallYellowBlockAnimations[2];

smallYellowBlockAnimations[0].image.gfx = small_blockyTiles;
smallYellowBlockAnimations[0].image.gfxLen = small_blockyTilesLen;
smallYellowBlockAnimations[0].image.pal = small_blockyPal;
smallYellowBlockAnimations[0].image.palLen = small_blockyPalLen;
smallYellowBlockAnimations[0].size = SpriteSize_16x16;
smallYellowBlockAnimations[0].looping = false;
smallYellowBlockAnimations[0].frameCount = 2;
smallYellowBlockAnimations[0].frames = smallYellowBlockFrames;

smallYellowBlockAnimations[1].image.gfx = small_blocky_holeTiles;
smallYellowBlockAnimations[1].image.gfxLen = small_blocky_holeTilesLen;
smallYellowBlockAnimations[1].image.pal = small_blocky_holePal;
smallYellowBlockAnimations[1].image.palLen = small_blocky_holePalLen;
smallYellowBlockAnimations[1].size = SpriteSize_16x16;
smallYellowBlockAnimations[1].looping = false;
smallYellowBlockAnimations[1].frameCount = 1;
smallYellowBlockAnimations[1].frames = &smallYellowBlockHole;


Rage::SpriteDefinition smallYellowBlockDef;

smallYellowBlockDef.version = 2;
smallYellowBlockDef.spriteID = BLOCK_YELLOW;
smallYellowBlockDef.animationCount = 2;
smallYellowBlockDef.animations = smallYellowBlockAnimations;
