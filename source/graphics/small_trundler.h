#include "ids.h"

Rage::Frame smallTrundlerFramesRight[7];

smallTrundlerFramesRight[0].index = 0; smallTrundlerFramesRight[0].duration = 5;
smallTrundlerFramesRight[1].index = 1; smallTrundlerFramesRight[1].duration = 5;
smallTrundlerFramesRight[2].index = 2; smallTrundlerFramesRight[2].duration = 5;
smallTrundlerFramesRight[3].index = 3; smallTrundlerFramesRight[3].duration = 5;
smallTrundlerFramesRight[4].index = 4; smallTrundlerFramesRight[4].duration = 5;
smallTrundlerFramesRight[5].index = 5; smallTrundlerFramesRight[5].duration = 5;
smallTrundlerFramesRight[6].index = 6; smallTrundlerFramesRight[6].duration = 5;

Rage::Frame smallTrundlerFramesLeft[7];

smallTrundlerFramesLeft[0].index = 6; smallTrundlerFramesLeft[0].duration = 5;
smallTrundlerFramesLeft[1].index = 5; smallTrundlerFramesLeft[1].duration = 5;
smallTrundlerFramesLeft[2].index = 4; smallTrundlerFramesLeft[2].duration = 5;
smallTrundlerFramesLeft[3].index = 3; smallTrundlerFramesLeft[3].duration = 5;
smallTrundlerFramesLeft[4].index = 2; smallTrundlerFramesLeft[4].duration = 5;
smallTrundlerFramesLeft[5].index = 1; smallTrundlerFramesLeft[5].duration = 5;
smallTrundlerFramesLeft[6].index = 0; smallTrundlerFramesLeft[6].duration = 5;

Rage::Frame smallTrundlerPause;

smallTrundlerPause.index = 0; smallTrundlerPause.duration = 60;

Rage::Animation smallTrundlerAnimations[2];

smallTrundlerAnimations[0].image.gfx = small_trundlerTiles;
smallTrundlerAnimations[0].image.gfxLen = small_trundlerTilesLen;
smallTrundlerAnimations[0].image.pal = small_trundlerPal;
smallTrundlerAnimations[0].image.palLen = small_trundlerPalLen;
smallTrundlerAnimations[0].size = SpriteSize_16x16;
smallTrundlerAnimations[0].looping = true;
smallTrundlerAnimations[0].frameCount = 7;
smallTrundlerAnimations[0].frames = smallTrundlerFramesRight;

smallTrundlerAnimations[1] = smallTrundlerAnimations[0];
smallTrundlerAnimations[1].frames = smallTrundlerFramesLeft;

smallTrundlerAnimations[2] = smallTrundlerAnimations[0];
smallTrundlerAnimations[2].looping = false;
smallTrundlerAnimations[2].frameCount = 1;
smallTrundlerAnimations[2].frames = &smallTrundlerPause;

Rage::SpriteDefinition smallTrundlerDef;

smallTrundlerDef.version = 2;
smallTrundlerDef.spriteID = TRUNDLER;
smallTrundlerDef.animationCount = 3;
smallTrundlerDef.animations = smallTrundlerAnimations;
