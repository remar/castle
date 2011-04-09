#include "ids.h"

Rage::Frame smallBlueSwitchOn[4];

for(int i = 0;i < 4;i++)
  {
    smallBlueSwitchOn[i].index = i;
    smallBlueSwitchOn[i].duration = 5;
  }

Rage::Frame smallBlueSwitchOff;

smallBlueSwitchOff.index = 0; smallBlueSwitchOff.duration = 60;


Rage::Animation smallBlueSwitchAnimations[2];

smallBlueSwitchAnimations[0].image.gfx = small_switchbTiles;
smallBlueSwitchAnimations[0].image.gfxLen = small_switchbTilesLen;
smallBlueSwitchAnimations[0].image.pal = small_switchbPal;
smallBlueSwitchAnimations[0].image.palLen = small_switchbPalLen;
smallBlueSwitchAnimations[0].size = SpriteSize_8x8;
smallBlueSwitchAnimations[0].looping = true;
smallBlueSwitchAnimations[0].frameCount = 4;
smallBlueSwitchAnimations[0].frames = smallBlueSwitchOn;

smallBlueSwitchAnimations[1].image.gfx = small_switchb_offTiles;
smallBlueSwitchAnimations[1].image.gfxLen = small_switchb_offTilesLen;
smallBlueSwitchAnimations[1].image.pal = small_switchb_offPal;
smallBlueSwitchAnimations[1].image.palLen = small_switchb_offPalLen;
smallBlueSwitchAnimations[1].size = SpriteSize_8x8;
smallBlueSwitchAnimations[1].looping = false;
smallBlueSwitchAnimations[1].frameCount = 1;
smallBlueSwitchAnimations[1].frames = &smallBlueSwitchOff;


Rage::SpriteDefinition smallBlueSwitchDef;

smallBlueSwitchDef.version = 2;
smallBlueSwitchDef.spriteID = SWITCH_BLUE;
smallBlueSwitchDef.animationCount = 2;
smallBlueSwitchDef.animations = smallBlueSwitchAnimations;
