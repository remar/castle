#include "ids.h"

Rage::Frame smallBootsFrame;

smallBootsFrame.index = 0; smallBootsFrame.duration = 60;

Rage::Animation smallBootsAnimation;

smallBootsAnimation.image.gfx = small_bootsTiles;
smallBootsAnimation.image.gfxLen = small_bootsTilesLen;
smallBootsAnimation.image.pal = small_bootsPal;
smallBootsAnimation.image.palLen = small_bootsPalLen;
smallBootsAnimation.size = SpriteSize_16x16;
smallBootsAnimation.looping = false;
smallBootsAnimation.frameCount = 1;
smallBootsAnimation.frames = &smallBootsFrame;

Rage::SpriteDefinition smallBootsDef;

smallBootsDef.version = 2;
smallBootsDef.spriteID = BOOTS;
smallBootsDef.animationCount = 1;
smallBootsDef.animations = &smallBootsAnimation;
