#include "ids.h"

Rage::Frame smallYellowTargetFrame;

smallYellowTargetFrame.index = 0;
smallYellowTargetFrame.duration = 60;


Rage::Animation smallYellowTargetAnimation;

smallYellowTargetAnimation.image.gfx = small_teley_targetTiles;
smallYellowTargetAnimation.image.gfxLen = small_teley_targetTilesLen;
smallYellowTargetAnimation.image.pal = small_teley_targetPal;
smallYellowTargetAnimation.image.palLen = small_teley_targetPalLen;
smallYellowTargetAnimation.size = SpriteSize_16x16;
smallYellowTargetAnimation.looping = false;
smallYellowTargetAnimation.frameCount = 1;
smallYellowTargetAnimation.frames = &smallYellowTargetFrame;


Rage::SpriteDefinition smallYellowTargetDef;

smallYellowTargetDef.version = 2;
smallYellowTargetDef.spriteID = TARGET_YELLOW;
smallYellowTargetDef.animationCount = 1;
smallYellowTargetDef.animations = &smallYellowTargetAnimation;
