#include "ids.h"

Rage::Frame largeTrapperFrames[16];

for(int i = 0;i < 16;i++)
  {
    largeTrapperFrames[i].index = i; largeTrapperFrames[i].duration = 5;
  }

Rage::Animation largeTrapperAnimation;

largeTrapperAnimation.image.gfx = large_trapperTiles;
largeTrapperAnimation.image.gfxLen = large_trapperTilesLen;
largeTrapperAnimation.image.pal = large_trapperPal;
largeTrapperAnimation.image.palLen = large_trapperPalLen;
largeTrapperAnimation.size = SpriteSize_32x32;
largeTrapperAnimation.looping = true;
largeTrapperAnimation.frameCount = 16;
largeTrapperAnimation.frames = largeTrapperFrames;

Rage::SpriteDefinition largeTrapperDef;

largeTrapperDef.version = 2;
largeTrapperDef.spriteID = TRAPPER;
largeTrapperDef.animationCount = 1;
largeTrapperDef.animations = &largeTrapperAnimation;
