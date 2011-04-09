#include "ids.h"

Rage::Frame smallBlueSparkFrames[8];

smallBlueSparkFrames[0].index = 0; smallBlueSparkFrames[0].duration = 5;
smallBlueSparkFrames[1].index = 1; smallBlueSparkFrames[1].duration = 5;
smallBlueSparkFrames[2].index = 2; smallBlueSparkFrames[2].duration = 5;
smallBlueSparkFrames[3].index = 3; smallBlueSparkFrames[3].duration = 5;
smallBlueSparkFrames[4].index = 4; smallBlueSparkFrames[4].duration = 5;
smallBlueSparkFrames[5].index = 5; smallBlueSparkFrames[5].duration = 5;
smallBlueSparkFrames[6].index = 6; smallBlueSparkFrames[6].duration = 5;
smallBlueSparkFrames[7].index = 7; smallBlueSparkFrames[7].duration = 5;

Rage::Animation smallBlueSparkAnimation;

smallBlueSparkAnimation.image.gfx = small_bluesparkTiles;
smallBlueSparkAnimation.image.gfxLen = small_bluesparkTilesLen;
smallBlueSparkAnimation.image.pal = small_bluesparkPal;
smallBlueSparkAnimation.image.palLen = small_bluesparkPalLen;
smallBlueSparkAnimation.size = SpriteSize_16x16;
smallBlueSparkAnimation.looping = true;
smallBlueSparkAnimation.frameCount = 8;
smallBlueSparkAnimation.frames = smallBlueSparkFrames;

Rage::SpriteDefinition smallBlueSparkDef;

smallBlueSparkDef.version = 2;
smallBlueSparkDef.spriteID = BLUE_SPARK;
smallBlueSparkDef.animationCount = 1;
smallBlueSparkDef.animations = &smallBlueSparkAnimation;
