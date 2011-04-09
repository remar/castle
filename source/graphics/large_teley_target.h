#include "ids.h"

Rage::Frame largeYellowTargetFrame;

largeYellowTargetFrame.index = 0;
largeYellowTargetFrame.duration = 60;


Rage::Animation largeYellowTargetAnimation;

largeYellowTargetAnimation.image.gfx = large_teley_targetTiles;
largeYellowTargetAnimation.image.gfxLen = large_teley_targetTilesLen;
largeYellowTargetAnimation.image.pal = large_teley_targetPal;
largeYellowTargetAnimation.image.palLen = large_teley_targetPalLen;
largeYellowTargetAnimation.size = SpriteSize_32x32;
largeYellowTargetAnimation.looping = false;
largeYellowTargetAnimation.frameCount = 1;
largeYellowTargetAnimation.frames = &largeYellowTargetFrame;


Rage::SpriteDefinition largeYellowTargetDef;

largeYellowTargetDef.version = 2;
largeYellowTargetDef.spriteID = TARGET_YELLOW;
largeYellowTargetDef.animationCount = 1;
largeYellowTargetDef.animations = &largeYellowTargetAnimation;
