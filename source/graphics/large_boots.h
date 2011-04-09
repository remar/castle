#include "ids.h"

Rage::Frame largeBootsFrame;

largeBootsFrame.index = 0; largeBootsFrame.duration = 60;

Rage::Animation largeBootsAnimation;

largeBootsAnimation.image.gfx = large_bootsTiles;
largeBootsAnimation.image.gfxLen = large_bootsTilesLen;
largeBootsAnimation.image.pal = large_bootsPal;
largeBootsAnimation.image.palLen = large_bootsPalLen;
largeBootsAnimation.size = SpriteSize_32x32;
largeBootsAnimation.looping = false;
largeBootsAnimation.frameCount = 1;
largeBootsAnimation.frames = &largeBootsFrame;

Rage::SpriteDefinition largeBootsDef;

largeBootsDef.version = 2;
largeBootsDef.spriteID = BOOTS;
largeBootsDef.animationCount = 1;
largeBootsDef.animations = &largeBootsAnimation;
