#include "ids.h"

Rage::Frame smallBreakableFrames[3];

smallBreakableFrames[0].index = 1; smallBreakableFrames[0].duration = 5;
smallBreakableFrames[1].index = 2; smallBreakableFrames[1].duration = 5;
smallBreakableFrames[2].index = 0; smallBreakableFrames[2].duration = 5;

Rage::Frame smallBreakableFrames2[2];

smallBreakableFrames2[0].index = 0; smallBreakableFrames2[0].duration = 10;
smallBreakableFrames2[1].index = 1; smallBreakableFrames2[1].duration = 10;

Rage::Animation smallBreakableAnimations[2];

smallBreakableAnimations[0].image.gfx = small_breakableTiles;
smallBreakableAnimations[0].image.gfxLen = small_breakableTilesLen;
smallBreakableAnimations[0].image.pal = small_breakablePal;
smallBreakableAnimations[0].image.palLen = small_breakablePalLen;
smallBreakableAnimations[0].size = SpriteSize_16x16;
smallBreakableAnimations[0].looping = false;
smallBreakableAnimations[0].frameCount = 3;
smallBreakableAnimations[0].frames = smallBreakableFrames;

smallBreakableAnimations[1].image.gfx = small_breakableTiles;
smallBreakableAnimations[1].image.gfxLen = small_breakableTilesLen;
smallBreakableAnimations[1].image.pal = small_breakablePal;
smallBreakableAnimations[1].image.palLen = small_breakablePalLen;
smallBreakableAnimations[1].size = SpriteSize_16x16;
smallBreakableAnimations[1].looping = true;
smallBreakableAnimations[1].frameCount = 2;
smallBreakableAnimations[1].frames = smallBreakableFrames2;

Rage::SpriteDefinition smallBreakableDef;

smallBreakableDef.version = 2;
smallBreakableDef.spriteID = BREAKABLE;
smallBreakableDef.animationCount = 2;
smallBreakableDef.animations = smallBreakableAnimations;
