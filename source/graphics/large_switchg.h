#include "ids.h"

Rage::Frame largeGreenSwitchOn[4];

for(int i = 0;i < 4;i++)
  {
    largeGreenSwitchOn[i].index = i;
    largeGreenSwitchOn[i].duration = 5;
  }

Rage::Frame largeGreenSwitchOff;

largeGreenSwitchOff.index = 0; largeGreenSwitchOff.duration = 60;


Rage::Animation largeGreenSwitchAnimations[2];

largeGreenSwitchAnimations[0].image.gfx = large_switchgTiles;
largeGreenSwitchAnimations[0].image.gfxLen = large_switchgTilesLen;
largeGreenSwitchAnimations[0].image.pal = large_switchgPal;
largeGreenSwitchAnimations[0].image.palLen = large_switchgPalLen;
largeGreenSwitchAnimations[0].size = SpriteSize_16x16;
largeGreenSwitchAnimations[0].looping = true;
largeGreenSwitchAnimations[0].frameCount = 4;
largeGreenSwitchAnimations[0].frames = largeGreenSwitchOn;

largeGreenSwitchAnimations[1].image.gfx = large_switchg_offTiles;
largeGreenSwitchAnimations[1].image.gfxLen = large_switchg_offTilesLen;
largeGreenSwitchAnimations[1].image.pal = large_switchg_offPal;
largeGreenSwitchAnimations[1].image.palLen = large_switchg_offPalLen;
largeGreenSwitchAnimations[1].size = SpriteSize_16x16;
largeGreenSwitchAnimations[1].looping = false;
largeGreenSwitchAnimations[1].frameCount = 1;
largeGreenSwitchAnimations[1].frames = &largeGreenSwitchOff;


Rage::SpriteDefinition largeGreenSwitchDef;

largeGreenSwitchDef.version = 2;
largeGreenSwitchDef.spriteID = SWITCH_GREEN;
largeGreenSwitchDef.animationCount = 2;
largeGreenSwitchDef.animations = largeGreenSwitchAnimations;
