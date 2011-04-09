#include "ids.h"

Rage::Frame largeYellowSwitchOn[4];

for(int i = 0;i < 4;i++)
  {
    largeYellowSwitchOn[i].index = i;
    largeYellowSwitchOn[i].duration = 5;
  }

Rage::Frame largeYellowSwitchOff;

largeYellowSwitchOff.index = 0; largeYellowSwitchOff.duration = 60;


Rage::Animation largeYellowSwitchAnimations[2];

largeYellowSwitchAnimations[0].image.gfx = large_switchyTiles;
largeYellowSwitchAnimations[0].image.gfxLen = large_switchyTilesLen;
largeYellowSwitchAnimations[0].image.pal = large_switchyPal;
largeYellowSwitchAnimations[0].image.palLen = large_switchyPalLen;
largeYellowSwitchAnimations[0].size = SpriteSize_16x16;
largeYellowSwitchAnimations[0].looping = true;
largeYellowSwitchAnimations[0].frameCount = 4;
largeYellowSwitchAnimations[0].frames = largeYellowSwitchOn;

largeYellowSwitchAnimations[1].image.gfx = large_switchy_offTiles;
largeYellowSwitchAnimations[1].image.gfxLen = large_switchy_offTilesLen;
largeYellowSwitchAnimations[1].image.pal = large_switchy_offPal;
largeYellowSwitchAnimations[1].image.palLen = large_switchy_offPalLen;
largeYellowSwitchAnimations[1].size = SpriteSize_16x16;
largeYellowSwitchAnimations[1].looping = false;
largeYellowSwitchAnimations[1].frameCount = 1;
largeYellowSwitchAnimations[1].frames = &largeYellowSwitchOff;


Rage::SpriteDefinition largeYellowSwitchDef;

largeYellowSwitchDef.version = 2;
largeYellowSwitchDef.spriteID = SWITCH_YELLOW;
largeYellowSwitchDef.animationCount = 2;
largeYellowSwitchDef.animations = largeYellowSwitchAnimations;
