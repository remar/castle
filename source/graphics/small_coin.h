#include "ids.h"

Rage::Frame smallCoinFrames[2];

smallCoinFrames[0].index = 0; smallCoinFrames[0].duration = 5;
smallCoinFrames[1].index = 1; smallCoinFrames[1].duration = 5;

Rage::Animation smallCoinAnimation;

smallCoinAnimation.image.gfx = small_coinTiles;
smallCoinAnimation.image.gfxLen = small_coinTilesLen;
smallCoinAnimation.image.pal = small_coinPal;
smallCoinAnimation.image.palLen = small_coinPalLen;
smallCoinAnimation.size = SpriteSize_8x8;
smallCoinAnimation.looping = true;
smallCoinAnimation.frameCount = 2;
smallCoinAnimation.frames = smallCoinFrames;

Rage::SpriteDefinition smallCoinDef;

smallCoinDef.version = 2;
smallCoinDef.spriteID = COIN;
smallCoinDef.animationCount = 1;
smallCoinDef.animations = &smallCoinAnimation;
