#include "ids.h"

Rage::Frame smallGreenSwitchOn[4];

for(int i = 0;i < 4;i++)
  {
    smallGreenSwitchOn[i].index = i;
    smallGreenSwitchOn[i].duration = 5;
  }

Rage::Frame smallGreenSwitchOff;

smallGreenSwitchOff.index = 0; smallGreenSwitchOff.duration = 60;


Rage::Animation smallGreenSwitchAnimations[2];

smallGreenSwitchAnimations[0].image.gfx = small_switchgTiles;
smallGreenSwitchAnimations[0].image.gfxLen = small_switchgTilesLen;
smallGreenSwitchAnimations[0].image.pal = small_switchgPal;
smallGreenSwitchAnimations[0].image.palLen = small_switchgPalLen;
smallGreenSwitchAnimations[0].size = SpriteSize_8x8;
smallGreenSwitchAnimations[0].looping = true;
smallGreenSwitchAnimations[0].frameCount = 4;
smallGreenSwitchAnimations[0].frames = smallGreenSwitchOn;

smallGreenSwitchAnimations[1].image.gfx = small_switchg_offTiles;
smallGreenSwitchAnimations[1].image.gfxLen = small_switchg_offTilesLen;
smallGreenSwitchAnimations[1].image.pal = small_switchg_offPal;
smallGreenSwitchAnimations[1].image.palLen = small_switchg_offPalLen;
smallGreenSwitchAnimations[1].size = SpriteSize_8x8;
smallGreenSwitchAnimations[1].looping = false;
smallGreenSwitchAnimations[1].frameCount = 1;
smallGreenSwitchAnimations[1].frames = &smallGreenSwitchOff;


Rage::SpriteDefinition smallGreenSwitchDef;

smallGreenSwitchDef.version = 2;
smallGreenSwitchDef.spriteID = SWITCH_GREEN;
smallGreenSwitchDef.animationCount = 2;
smallGreenSwitchDef.animations = smallGreenSwitchAnimations;
