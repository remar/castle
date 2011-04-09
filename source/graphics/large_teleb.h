#include "ids.h"

Rage::Frame largeBlueTeleFrames[8];

for(int i = 0;i < 8;i++)
  {
    largeBlueTeleFrames[i].index = i;
    largeBlueTeleFrames[i].duration = 5;
  }

Rage::Animation largeBlueTeleAnimation;

largeBlueTeleAnimation.image.gfx = large_telebTiles;
largeBlueTeleAnimation.image.gfxLen = large_telebTilesLen;
largeBlueTeleAnimation.image.pal = large_telebPal;
largeBlueTeleAnimation.image.palLen = large_telebPalLen;
largeBlueTeleAnimation.size = SpriteSize_32x32;
largeBlueTeleAnimation.looping = true;
largeBlueTeleAnimation.frameCount = 8;
largeBlueTeleAnimation.frames = largeBlueTeleFrames;


Rage::SpriteDefinition largeBlueTeleDef;

largeBlueTeleDef.version = 2;
largeBlueTeleDef.spriteID = TELE_BLUE;
largeBlueTeleDef.animationCount = 1;
largeBlueTeleDef.animations = &largeBlueTeleAnimation;
