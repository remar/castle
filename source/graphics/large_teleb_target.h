#include "ids.h"

Rage::Frame largeBlueTargetFrame;

largeBlueTargetFrame.index = 0;
largeBlueTargetFrame.duration = 60;


Rage::Animation largeBlueTargetAnimation;

largeBlueTargetAnimation.image.gfx = large_teleb_targetTiles;
largeBlueTargetAnimation.image.gfxLen = large_teleb_targetTilesLen;
largeBlueTargetAnimation.image.pal = large_teleb_targetPal;
largeBlueTargetAnimation.image.palLen = large_teleb_targetPalLen;
largeBlueTargetAnimation.size = SpriteSize_32x32;
largeBlueTargetAnimation.looping = false;
largeBlueTargetAnimation.frameCount = 1;
largeBlueTargetAnimation.frames = &largeBlueTargetFrame;


Rage::SpriteDefinition largeBlueTargetDef;

largeBlueTargetDef.version = 2;
largeBlueTargetDef.spriteID = TARGET_BLUE;
largeBlueTargetDef.animationCount = 1;
largeBlueTargetDef.animations = &largeBlueTargetAnimation;
