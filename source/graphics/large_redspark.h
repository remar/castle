#include "ids.h"

Rage::Frame largeRedSparkFrames[8];

largeRedSparkFrames[0].index = 0; largeRedSparkFrames[0].duration = 5;
largeRedSparkFrames[1].index = 1; largeRedSparkFrames[1].duration = 5;
largeRedSparkFrames[2].index = 2; largeRedSparkFrames[2].duration = 5;
largeRedSparkFrames[3].index = 3; largeRedSparkFrames[3].duration = 5;
largeRedSparkFrames[4].index = 4; largeRedSparkFrames[4].duration = 5;
largeRedSparkFrames[5].index = 5; largeRedSparkFrames[5].duration = 5;
largeRedSparkFrames[6].index = 6; largeRedSparkFrames[6].duration = 5;
largeRedSparkFrames[7].index = 7; largeRedSparkFrames[7].duration = 5;

Rage::Animation largeRedSparkAnimation;

largeRedSparkAnimation.image.gfx = large_redsparkTiles;
largeRedSparkAnimation.image.gfxLen = large_redsparkTilesLen;
largeRedSparkAnimation.image.pal = large_redsparkPal;
largeRedSparkAnimation.image.palLen = large_redsparkPalLen;
largeRedSparkAnimation.size = SpriteSize_32x32;
largeRedSparkAnimation.looping = true;
largeRedSparkAnimation.frameCount = 8;
largeRedSparkAnimation.frames = largeRedSparkFrames;

Rage::SpriteDefinition largeRedSparkDef;

largeRedSparkDef.version = 2;
largeRedSparkDef.spriteID = RED_SPARK;
largeRedSparkDef.animationCount = 1;
largeRedSparkDef.animations = &largeRedSparkAnimation;
