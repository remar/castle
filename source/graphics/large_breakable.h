#include "ids.h"

Rage::Frame largeBreakableFrames[3];

largeBreakableFrames[0].index = 1; largeBreakableFrames[0].duration = 5;
largeBreakableFrames[1].index = 2; largeBreakableFrames[1].duration = 5;
largeBreakableFrames[2].index = 0; largeBreakableFrames[2].duration = 5;

Rage::Frame largeBreakableFrames2[2];

largeBreakableFrames2[0].index = 0; largeBreakableFrames2[0].duration = 10;
largeBreakableFrames2[1].index = 1; largeBreakableFrames2[1].duration = 10;

Rage::Animation largeBreakableAnimations[2];

largeBreakableAnimations[0].image.gfx = large_breakableTiles;
largeBreakableAnimations[0].image.gfxLen = large_breakableTilesLen;
largeBreakableAnimations[0].image.pal = large_breakablePal;
largeBreakableAnimations[0].image.palLen = large_breakablePalLen;
largeBreakableAnimations[0].size = SpriteSize_32x32;
largeBreakableAnimations[0].looping = false;
largeBreakableAnimations[0].frameCount = 3;
largeBreakableAnimations[0].frames = largeBreakableFrames;

largeBreakableAnimations[1].image.gfx = large_breakableTiles;
largeBreakableAnimations[1].image.gfxLen = large_breakableTilesLen;
largeBreakableAnimations[1].image.pal = large_breakablePal;
largeBreakableAnimations[1].image.palLen = large_breakablePalLen;
largeBreakableAnimations[1].size = SpriteSize_32x32;
largeBreakableAnimations[1].looping = true;
largeBreakableAnimations[1].frameCount = 2;
largeBreakableAnimations[1].frames = largeBreakableFrames2;

Rage::SpriteDefinition largeBreakableDef;

largeBreakableDef.version = 2;
largeBreakableDef.spriteID = BREAKABLE;
largeBreakableDef.animationCount = 2;
largeBreakableDef.animations = largeBreakableAnimations;
