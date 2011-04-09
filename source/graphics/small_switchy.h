#include "ids.h"

Rage::Frame smallYellowSwitchOn[4];

for(int i = 0;i < 4;i++)
  {
    smallYellowSwitchOn[i].index = i;
    smallYellowSwitchOn[i].duration = 5;
  }

Rage::Frame smallYellowSwitchOff;

smallYellowSwitchOff.index = 0; smallYellowSwitchOff.duration = 60;


Rage::Animation smallYellowSwitchAnimations[2];

smallYellowSwitchAnimations[0].image.gfx = small_switchyTiles;
smallYellowSwitchAnimations[0].image.gfxLen = small_switchyTilesLen;
smallYellowSwitchAnimations[0].image.pal = small_switchyPal;
smallYellowSwitchAnimations[0].image.palLen = small_switchyPalLen;
smallYellowSwitchAnimations[0].size = SpriteSize_8x8;
smallYellowSwitchAnimations[0].looping = true;
smallYellowSwitchAnimations[0].frameCount = 4;
smallYellowSwitchAnimations[0].frames = smallYellowSwitchOn;

smallYellowSwitchAnimations[1].image.gfx = small_switchy_offTiles;
smallYellowSwitchAnimations[1].image.gfxLen = small_switchy_offTilesLen;
smallYellowSwitchAnimations[1].image.pal = small_switchy_offPal;
smallYellowSwitchAnimations[1].image.palLen = small_switchy_offPalLen;
smallYellowSwitchAnimations[1].size = SpriteSize_8x8;
smallYellowSwitchAnimations[1].looping = false;
smallYellowSwitchAnimations[1].frameCount = 1;
smallYellowSwitchAnimations[1].frames = &smallYellowSwitchOff;


Rage::SpriteDefinition smallYellowSwitchDef;

smallYellowSwitchDef.version = 2;
smallYellowSwitchDef.spriteID = SWITCH_YELLOW;
smallYellowSwitchDef.animationCount = 2;
smallYellowSwitchDef.animations = smallYellowSwitchAnimations;
