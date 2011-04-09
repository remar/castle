#include "ids.h"

Rage::Frame largeBlueSwitchOn[4];

for(int i = 0;i < 4;i++)
  {
    largeBlueSwitchOn[i].index = i;
    largeBlueSwitchOn[i].duration = 5;
  }

Rage::Frame largeBlueSwitchOff;

largeBlueSwitchOff.index = 0; largeBlueSwitchOff.duration = 60;


Rage::Animation largeBlueSwitchAnimations[2];

largeBlueSwitchAnimations[0].image.gfx = large_switchbTiles;
largeBlueSwitchAnimations[0].image.gfxLen = large_switchbTilesLen;
largeBlueSwitchAnimations[0].image.pal = large_switchbPal;
largeBlueSwitchAnimations[0].image.palLen = large_switchbPalLen;
largeBlueSwitchAnimations[0].size = SpriteSize_16x16;
largeBlueSwitchAnimations[0].looping = true;
largeBlueSwitchAnimations[0].frameCount = 4;
largeBlueSwitchAnimations[0].frames = largeBlueSwitchOn;

largeBlueSwitchAnimations[1].image.gfx = large_switchb_offTiles;
largeBlueSwitchAnimations[1].image.gfxLen = large_switchb_offTilesLen;
largeBlueSwitchAnimations[1].image.pal = large_switchb_offPal;
largeBlueSwitchAnimations[1].image.palLen = large_switchb_offPalLen;
largeBlueSwitchAnimations[1].size = SpriteSize_16x16;
largeBlueSwitchAnimations[1].looping = false;
largeBlueSwitchAnimations[1].frameCount = 1;
largeBlueSwitchAnimations[1].frames = &largeBlueSwitchOff;


Rage::SpriteDefinition largeBlueSwitchDef;

largeBlueSwitchDef.version = 2;
largeBlueSwitchDef.spriteID = SWITCH_BLUE;
largeBlueSwitchDef.animationCount = 2;
largeBlueSwitchDef.animations = largeBlueSwitchAnimations;
