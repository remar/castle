#include "ids.h"

Rage::Frame smallBlueTargetFrame;

smallBlueTargetFrame.index = 0;
smallBlueTargetFrame.duration = 60;


Rage::Animation smallBlueTargetAnimation;

smallBlueTargetAnimation.image.gfx = small_teleb_targetTiles;
smallBlueTargetAnimation.image.gfxLen = small_teleb_targetTilesLen;
smallBlueTargetAnimation.image.pal = small_teleb_targetPal;
smallBlueTargetAnimation.image.palLen = small_teleb_targetPalLen;
smallBlueTargetAnimation.size = SpriteSize_16x16;
smallBlueTargetAnimation.looping = false;
smallBlueTargetAnimation.frameCount = 1;
smallBlueTargetAnimation.frames = &smallBlueTargetFrame;


Rage::SpriteDefinition smallBlueTargetDef;

smallBlueTargetDef.version = 2;
smallBlueTargetDef.spriteID = TARGET_BLUE;
smallBlueTargetDef.animationCount = 1;
smallBlueTargetDef.animations = &smallBlueTargetAnimation;
