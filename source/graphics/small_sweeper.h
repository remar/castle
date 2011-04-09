#include "ids.h"

Rage::Frame smallSweeperFramesRight[8];

smallSweeperFramesRight[0].index = 0; smallSweeperFramesRight[0].duration = 5;
smallSweeperFramesRight[1].index = 1; smallSweeperFramesRight[1].duration = 5;
smallSweeperFramesRight[2].index = 2; smallSweeperFramesRight[2].duration = 5;
smallSweeperFramesRight[3].index = 3; smallSweeperFramesRight[3].duration = 5;
smallSweeperFramesRight[4].index = 4; smallSweeperFramesRight[4].duration = 5;
smallSweeperFramesRight[5].index = 5; smallSweeperFramesRight[5].duration = 5;
smallSweeperFramesRight[6].index = 6; smallSweeperFramesRight[6].duration = 5;
smallSweeperFramesRight[7].index = 7; smallSweeperFramesRight[7].duration = 5;

Rage::Frame smallSweeperFramesLeft[8];

smallSweeperFramesLeft[0].index = 7; smallSweeperFramesLeft[0].duration = 5;
smallSweeperFramesLeft[1].index = 6; smallSweeperFramesLeft[1].duration = 5;
smallSweeperFramesLeft[2].index = 5; smallSweeperFramesLeft[2].duration = 5;
smallSweeperFramesLeft[3].index = 4; smallSweeperFramesLeft[3].duration = 5;
smallSweeperFramesLeft[4].index = 3; smallSweeperFramesLeft[4].duration = 5;
smallSweeperFramesLeft[5].index = 2; smallSweeperFramesLeft[5].duration = 5;
smallSweeperFramesLeft[6].index = 1; smallSweeperFramesLeft[6].duration = 5;
smallSweeperFramesLeft[7].index = 0; smallSweeperFramesLeft[7].duration = 5;

Rage::Animation smallSweeperAnimations[2];

smallSweeperAnimations[0].image.gfx = small_sweeperTiles;
smallSweeperAnimations[0].image.gfxLen = small_sweeperTilesLen;
smallSweeperAnimations[0].image.pal = small_sweeperPal;
smallSweeperAnimations[0].image.palLen = small_sweeperPalLen;
smallSweeperAnimations[0].size = SpriteSize_16x16;
smallSweeperAnimations[0].looping = true;
smallSweeperAnimations[0].frameCount = 8;
smallSweeperAnimations[0].frames = smallSweeperFramesRight;

smallSweeperAnimations[1] = smallSweeperAnimations[0];
smallSweeperAnimations[1].frames = smallSweeperFramesLeft;

Rage::SpriteDefinition smallSweeperDef;

smallSweeperDef.version = 2;
smallSweeperDef.spriteID = SWEEPER;
smallSweeperDef.animationCount = 2;
smallSweeperDef.animations = smallSweeperAnimations;
