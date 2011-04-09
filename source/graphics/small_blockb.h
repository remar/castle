#include "ids.h"

Rage::Frame smallBlueBlockFrames[2];

smallBlueBlockFrames[0].index = 1; smallBlueBlockFrames[0].duration = 30;
smallBlueBlockFrames[1].index = 0; smallBlueBlockFrames[1].duration = 60;


Rage::Frame smallBlueBlockHole;

smallBlueBlockHole.index = 0; smallBlueBlockHole.duration = 60;


Rage::Animation smallBlueBlockAnimations[2];

smallBlueBlockAnimations[0].image.gfx = small_blockbTiles;
smallBlueBlockAnimations[0].image.gfxLen = small_blockbTilesLen;
smallBlueBlockAnimations[0].image.pal = small_blockbPal;
smallBlueBlockAnimations[0].image.palLen = small_blockbPalLen;
smallBlueBlockAnimations[0].size = SpriteSize_16x16;
smallBlueBlockAnimations[0].looping = false;
smallBlueBlockAnimations[0].frameCount = 2;
smallBlueBlockAnimations[0].frames = smallBlueBlockFrames;

smallBlueBlockAnimations[1].image.gfx = small_blockb_holeTiles;
smallBlueBlockAnimations[1].image.gfxLen = small_blockb_holeTilesLen;
smallBlueBlockAnimations[1].image.pal = small_blockb_holePal;
smallBlueBlockAnimations[1].image.palLen = small_blockb_holePalLen;
smallBlueBlockAnimations[1].size = SpriteSize_16x16;
smallBlueBlockAnimations[1].looping = false;
smallBlueBlockAnimations[1].frameCount = 1;
smallBlueBlockAnimations[1].frames = &smallBlueBlockHole;


Rage::SpriteDefinition smallBlueBlockDef;

smallBlueBlockDef.version = 2;
smallBlueBlockDef.spriteID = BLOCK_BLUE;
smallBlueBlockDef.animationCount = 2;
smallBlueBlockDef.animations = smallBlueBlockAnimations;
