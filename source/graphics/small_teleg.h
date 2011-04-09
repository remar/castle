#include "ids.h"

Rage::Frame smallGreenTeleFrames[8];

for(int i = 0;i < 8;i++)
  {
    smallGreenTeleFrames[i].index = i;
    smallGreenTeleFrames[i].duration = 5;
  }

Rage::Animation smallGreenTeleAnimation;

smallGreenTeleAnimation.image.gfx = small_telegTiles;
smallGreenTeleAnimation.image.gfxLen = small_telegTilesLen;
smallGreenTeleAnimation.image.pal = small_telegPal;
smallGreenTeleAnimation.image.palLen = small_telegPalLen;
smallGreenTeleAnimation.size = SpriteSize_16x16;
smallGreenTeleAnimation.looping = true;
smallGreenTeleAnimation.frameCount = 8;
smallGreenTeleAnimation.frames = smallGreenTeleFrames;


Rage::SpriteDefinition smallGreenTeleDef;

smallGreenTeleDef.version = 2;
smallGreenTeleDef.spriteID = TELE_GREEN;
smallGreenTeleDef.animationCount = 1;
smallGreenTeleDef.animations = &smallGreenTeleAnimation;
