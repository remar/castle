#include "ids.h"

Rage::Frame smallRedSparkFrames[8];

smallRedSparkFrames[0].index = 0; smallRedSparkFrames[0].duration = 5;
smallRedSparkFrames[1].index = 1; smallRedSparkFrames[1].duration = 5;
smallRedSparkFrames[2].index = 2; smallRedSparkFrames[2].duration = 5;
smallRedSparkFrames[3].index = 3; smallRedSparkFrames[3].duration = 5;
smallRedSparkFrames[4].index = 4; smallRedSparkFrames[4].duration = 5;
smallRedSparkFrames[5].index = 5; smallRedSparkFrames[5].duration = 5;
smallRedSparkFrames[6].index = 6; smallRedSparkFrames[6].duration = 5;
smallRedSparkFrames[7].index = 7; smallRedSparkFrames[7].duration = 5;

Rage::Animation smallRedSparkAnimation;

smallRedSparkAnimation.image.gfx = small_redsparkTiles;
smallRedSparkAnimation.image.gfxLen = small_redsparkTilesLen;
smallRedSparkAnimation.image.pal = small_redsparkPal;
smallRedSparkAnimation.image.palLen = small_redsparkPalLen;
smallRedSparkAnimation.size = SpriteSize_16x16;
smallRedSparkAnimation.looping = true;
smallRedSparkAnimation.frameCount = 8;
smallRedSparkAnimation.frames = smallRedSparkFrames;

Rage::SpriteDefinition smallRedSparkDef;

smallRedSparkDef.version = 2;
smallRedSparkDef.spriteID = RED_SPARK;
smallRedSparkDef.animationCount = 1;
smallRedSparkDef.animations = &smallRedSparkAnimation;
