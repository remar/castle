#include "ids.h"

Rage::Frame smallGreenTargetFrame;

smallGreenTargetFrame.index = 0;
smallGreenTargetFrame.duration = 60;


Rage::Animation smallGreenTargetAnimation;

smallGreenTargetAnimation.image.gfx = small_teleg_targetTiles;
smallGreenTargetAnimation.image.gfxLen = small_teleg_targetTilesLen;
smallGreenTargetAnimation.image.pal = small_teleg_targetPal;
smallGreenTargetAnimation.image.palLen = small_teleg_targetPalLen;
smallGreenTargetAnimation.size = SpriteSize_16x16;
smallGreenTargetAnimation.looping = false;
smallGreenTargetAnimation.frameCount = 1;
smallGreenTargetAnimation.frames = &smallGreenTargetFrame;


Rage::SpriteDefinition smallGreenTargetDef;

smallGreenTargetDef.version = 2;
smallGreenTargetDef.spriteID = TARGET_GREEN;
smallGreenTargetDef.animationCount = 1;
smallGreenTargetDef.animations = &smallGreenTargetAnimation;
