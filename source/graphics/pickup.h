#include "ids.h"

Rage::Frame pickupFrames[1];

pickupFrames[0].index = 0; pickupFrames[0].duration = 60;

Rage::Animation pickupAnimation;

pickupAnimation.looping = false;
pickupAnimation.frameCount = 1;
pickupAnimation.frames = pickupFrames;

Rage::SpriteDefinition pickupDef;

pickupDef.version = 2;
pickupDef.animationCount = 1;
pickupDef.animations = &pickupAnimation;

// After including this file, before adding sprite to Rage, you need to define:

/*
  pickupAnimation.image.gfx = ;
  pickupAnimation.image.gfxLen = ;
  pickupAnimation.image.pal = ;
  pickupAnimation.image.palLen = ;
  pickupAnimation.size = ;
  pickupDef.spriteID = ;
*/
