#include "ids.h"

Rage::Frame largeYellowTeleFrames[8];

for(int i = 0;i < 8;i++)
  {
    largeYellowTeleFrames[i].index = i;
    largeYellowTeleFrames[i].duration = 5;
  }

Rage::Animation largeYellowTeleAnimation;

largeYellowTeleAnimation.image.gfx = large_teleyTiles;
largeYellowTeleAnimation.image.gfxLen = large_teleyTilesLen;
largeYellowTeleAnimation.image.pal = large_teleyPal;
largeYellowTeleAnimation.image.palLen = large_teleyPalLen;
largeYellowTeleAnimation.size = SpriteSize_32x32;
largeYellowTeleAnimation.looping = true;
largeYellowTeleAnimation.frameCount = 8;
largeYellowTeleAnimation.frames = largeYellowTeleFrames;


Rage::SpriteDefinition largeYellowTeleDef;

largeYellowTeleDef.version = 2;
largeYellowTeleDef.spriteID = TELE_YELLOW;
largeYellowTeleDef.animationCount = 1;
largeYellowTeleDef.animations = &largeYellowTeleAnimation;
