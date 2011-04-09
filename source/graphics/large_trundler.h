#include "ids.h"

Rage::Frame largeTrundlerFramesRight[7];

largeTrundlerFramesRight[0].index = 0; largeTrundlerFramesRight[0].duration = 5;
largeTrundlerFramesRight[1].index = 1; largeTrundlerFramesRight[1].duration = 5;
largeTrundlerFramesRight[2].index = 2; largeTrundlerFramesRight[2].duration = 5;
largeTrundlerFramesRight[3].index = 3; largeTrundlerFramesRight[3].duration = 5;
largeTrundlerFramesRight[4].index = 4; largeTrundlerFramesRight[4].duration = 5;
largeTrundlerFramesRight[5].index = 5; largeTrundlerFramesRight[5].duration = 5;
largeTrundlerFramesRight[6].index = 6; largeTrundlerFramesRight[6].duration = 5;

Rage::Frame largeTrundlerFramesLeft[7];

largeTrundlerFramesLeft[0].index = 6; largeTrundlerFramesLeft[0].duration = 5;
largeTrundlerFramesLeft[1].index = 5; largeTrundlerFramesLeft[1].duration = 5;
largeTrundlerFramesLeft[2].index = 4; largeTrundlerFramesLeft[2].duration = 5;
largeTrundlerFramesLeft[3].index = 3; largeTrundlerFramesLeft[3].duration = 5;
largeTrundlerFramesLeft[4].index = 2; largeTrundlerFramesLeft[4].duration = 5;
largeTrundlerFramesLeft[5].index = 1; largeTrundlerFramesLeft[5].duration = 5;
largeTrundlerFramesLeft[6].index = 0; largeTrundlerFramesLeft[6].duration = 5;

Rage::Frame largeTrundlerPause;

largeTrundlerPause.index = 0; largeTrundlerPause.duration = 60;

Rage::Animation largeTrundlerAnimations[3];

largeTrundlerAnimations[0].image.gfx = large_trundlerTiles;
largeTrundlerAnimations[0].image.gfxLen = large_trundlerTilesLen;
largeTrundlerAnimations[0].image.pal = large_trundlerPal;
largeTrundlerAnimations[0].image.palLen = large_trundlerPalLen;
largeTrundlerAnimations[0].size = SpriteSize_32x32;
largeTrundlerAnimations[0].looping = true;
largeTrundlerAnimations[0].frameCount = 7;
largeTrundlerAnimations[0].frames = largeTrundlerFramesRight;

largeTrundlerAnimations[1] = largeTrundlerAnimations[0];
largeTrundlerAnimations[1].frames = largeTrundlerFramesLeft;

largeTrundlerAnimations[2] = largeTrundlerAnimations[0];
largeTrundlerAnimations[2].looping = false;
largeTrundlerAnimations[2].frameCount = 1;
largeTrundlerAnimations[2].frames = &largeTrundlerPause;

Rage::SpriteDefinition largeTrundlerDef;

largeTrundlerDef.version = 2;
largeTrundlerDef.spriteID = TRUNDLER;
largeTrundlerDef.animationCount = 3;
largeTrundlerDef.animations = largeTrundlerAnimations;
