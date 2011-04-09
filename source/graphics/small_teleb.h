#include "ids.h"

Rage::Frame smallBlueTeleFrames[8];

for(int i = 0;i < 8;i++)
  {
    smallBlueTeleFrames[i].index = i;
    smallBlueTeleFrames[i].duration = 5;
  }

Rage::Animation smallBlueTeleAnimation;

smallBlueTeleAnimation.image.gfx = small_telebTiles;
smallBlueTeleAnimation.image.gfxLen = small_telebTilesLen;
smallBlueTeleAnimation.image.pal = small_telebPal;
smallBlueTeleAnimation.image.palLen = small_telebPalLen;
smallBlueTeleAnimation.size = SpriteSize_16x16;
smallBlueTeleAnimation.looping = true;
smallBlueTeleAnimation.frameCount = 8;
smallBlueTeleAnimation.frames = smallBlueTeleFrames;


Rage::SpriteDefinition smallBlueTeleDef;

smallBlueTeleDef.version = 2;
smallBlueTeleDef.spriteID = TELE_BLUE;
smallBlueTeleDef.animationCount = 1;
smallBlueTeleDef.animations = &smallBlueTeleAnimation;
