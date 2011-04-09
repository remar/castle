#include "ids.h"

Rage::Frame largeCoinFrames[2];

largeCoinFrames[0].index = 0; largeCoinFrames[0].duration = 5;
largeCoinFrames[1].index = 1; largeCoinFrames[1].duration = 5;

Rage::Animation largeCoinAnimation;

largeCoinAnimation.image.gfx = large_coinTiles;
largeCoinAnimation.image.gfxLen = large_coinTilesLen;
largeCoinAnimation.image.pal = large_coinPal;
largeCoinAnimation.image.palLen = large_coinPalLen;
largeCoinAnimation.size = SpriteSize_16x16;
largeCoinAnimation.looping = true;
largeCoinAnimation.frameCount = 2;
largeCoinAnimation.frames = largeCoinFrames;

Rage::SpriteDefinition largeCoinDef;

largeCoinDef.version = 2;
largeCoinDef.spriteID = COIN;
largeCoinDef.animationCount = 1;
largeCoinDef.animations = &largeCoinAnimation;
