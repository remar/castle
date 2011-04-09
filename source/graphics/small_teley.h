#include "ids.h"

Rage::Frame smallYellowTeleFrames[8];

for(int i = 0;i < 8;i++)
  {
    smallYellowTeleFrames[i].index = i;
    smallYellowTeleFrames[i].duration = 5;
  }

Rage::Animation smallYellowTeleAnimation;

smallYellowTeleAnimation.image.gfx = small_teleyTiles;
smallYellowTeleAnimation.image.gfxLen = small_teleyTilesLen;
smallYellowTeleAnimation.image.pal = small_teleyPal;
smallYellowTeleAnimation.image.palLen = small_teleyPalLen;
smallYellowTeleAnimation.size = SpriteSize_16x16;
smallYellowTeleAnimation.looping = true;
smallYellowTeleAnimation.frameCount = 8;
smallYellowTeleAnimation.frames = smallYellowTeleFrames;


Rage::SpriteDefinition smallYellowTeleDef;

smallYellowTeleDef.version = 2;
smallYellowTeleDef.spriteID = TELE_YELLOW;
smallYellowTeleDef.animationCount = 1;
smallYellowTeleDef.animations = &smallYellowTeleAnimation;
