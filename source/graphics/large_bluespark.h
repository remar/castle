#include "ids.h"

Rage::Frame largeBlueSparkFrames[8];

largeBlueSparkFrames[0].index = 0; largeBlueSparkFrames[0].duration = 5;
largeBlueSparkFrames[1].index = 1; largeBlueSparkFrames[1].duration = 5;
largeBlueSparkFrames[2].index = 2; largeBlueSparkFrames[2].duration = 5;
largeBlueSparkFrames[3].index = 3; largeBlueSparkFrames[3].duration = 5;
largeBlueSparkFrames[4].index = 4; largeBlueSparkFrames[4].duration = 5;
largeBlueSparkFrames[5].index = 5; largeBlueSparkFrames[5].duration = 5;
largeBlueSparkFrames[6].index = 6; largeBlueSparkFrames[6].duration = 5;
largeBlueSparkFrames[7].index = 7; largeBlueSparkFrames[7].duration = 5;

Rage::Animation largeBlueSparkAnimation;

largeBlueSparkAnimation.image.gfx = large_bluesparkTiles;
largeBlueSparkAnimation.image.gfxLen = large_bluesparkTilesLen;
largeBlueSparkAnimation.image.pal = large_bluesparkPal;
largeBlueSparkAnimation.image.palLen = large_bluesparkPalLen;
largeBlueSparkAnimation.size = SpriteSize_32x32;
largeBlueSparkAnimation.looping = true;
largeBlueSparkAnimation.frameCount = 8;
largeBlueSparkAnimation.frames = largeBlueSparkFrames;

Rage::SpriteDefinition largeBlueSparkDef;

largeBlueSparkDef.version = 2;
largeBlueSparkDef.spriteID = BLUE_SPARK;
largeBlueSparkDef.animationCount = 1;
largeBlueSparkDef.animations = &largeBlueSparkAnimation;
