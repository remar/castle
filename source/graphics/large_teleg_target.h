#include "ids.h"

Rage::Frame largeGreenTargetFrame;

largeGreenTargetFrame.index = 0;
largeGreenTargetFrame.duration = 60;


Rage::Animation largeGreenTargetAnimation;

largeGreenTargetAnimation.image.gfx = large_teleg_targetTiles;
largeGreenTargetAnimation.image.gfxLen = large_teleg_targetTilesLen;
largeGreenTargetAnimation.image.pal = large_teleg_targetPal;
largeGreenTargetAnimation.image.palLen = large_teleg_targetPalLen;
largeGreenTargetAnimation.size = SpriteSize_32x32;
largeGreenTargetAnimation.looping = false;
largeGreenTargetAnimation.frameCount = 1;
largeGreenTargetAnimation.frames = &largeGreenTargetFrame;


Rage::SpriteDefinition largeGreenTargetDef;

largeGreenTargetDef.version = 2;
largeGreenTargetDef.spriteID = TARGET_GREEN;
largeGreenTargetDef.animationCount = 1;
largeGreenTargetDef.animations = &largeGreenTargetAnimation;
