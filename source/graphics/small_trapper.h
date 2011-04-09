#include "ids.h"

Rage::Frame smallTrapperFrames[16];

for(int i = 0;i < 16;i++)
  {
    smallTrapperFrames[i].index = i; smallTrapperFrames[i].duration = 5;
  }

Rage::Animation smallTrapperAnimation;

smallTrapperAnimation.image.gfx = small_trapperTiles;
smallTrapperAnimation.image.gfxLen = small_trapperTilesLen;
smallTrapperAnimation.image.pal = small_trapperPal;
smallTrapperAnimation.image.palLen = small_trapperPalLen;
smallTrapperAnimation.size = SpriteSize_16x16;
smallTrapperAnimation.looping = true;
smallTrapperAnimation.frameCount = 16;
smallTrapperAnimation.frames = smallTrapperFrames;

Rage::SpriteDefinition smallTrapperDef;

smallTrapperDef.version = 2;
smallTrapperDef.spriteID = TRAPPER;
smallTrapperDef.animationCount = 1;
smallTrapperDef.animations = &smallTrapperAnimation;
