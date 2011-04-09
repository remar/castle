#include "ids.h"

Rage::Frame largeGreenTeleFrames[8];

for(int i = 0;i < 8;i++)
  {
    largeGreenTeleFrames[i].index = i;
    largeGreenTeleFrames[i].duration = 5;
  }

Rage::Animation largeGreenTeleAnimation;

largeGreenTeleAnimation.image.gfx = large_telegTiles;
largeGreenTeleAnimation.image.gfxLen = large_telegTilesLen;
largeGreenTeleAnimation.image.pal = large_telegPal;
largeGreenTeleAnimation.image.palLen = large_telegPalLen;
largeGreenTeleAnimation.size = SpriteSize_32x32;
largeGreenTeleAnimation.looping = true;
largeGreenTeleAnimation.frameCount = 8;
largeGreenTeleAnimation.frames = largeGreenTeleFrames;


Rage::SpriteDefinition largeGreenTeleDef;

largeGreenTeleDef.version = 2;
largeGreenTeleDef.spriteID = TELE_GREEN;
largeGreenTeleDef.animationCount = 1;
largeGreenTeleDef.animations = &largeGreenTeleAnimation;
