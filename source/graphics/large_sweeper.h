#include "ids.h"

Rage::Frame largeSweeperFramesRight[8];

largeSweeperFramesRight[0].index = 0; largeSweeperFramesRight[0].duration = 5;
largeSweeperFramesRight[1].index = 1; largeSweeperFramesRight[1].duration = 5;
largeSweeperFramesRight[2].index = 2; largeSweeperFramesRight[2].duration = 5;
largeSweeperFramesRight[3].index = 3; largeSweeperFramesRight[3].duration = 5;
largeSweeperFramesRight[4].index = 4; largeSweeperFramesRight[4].duration = 5;
largeSweeperFramesRight[5].index = 5; largeSweeperFramesRight[5].duration = 5;
largeSweeperFramesRight[6].index = 6; largeSweeperFramesRight[6].duration = 5;
largeSweeperFramesRight[7].index = 7; largeSweeperFramesRight[7].duration = 5;

Rage::Frame largeSweeperFramesLeft[8];

largeSweeperFramesLeft[0].index = 7; largeSweeperFramesLeft[0].duration = 5;
largeSweeperFramesLeft[1].index = 6; largeSweeperFramesLeft[1].duration = 5;
largeSweeperFramesLeft[2].index = 5; largeSweeperFramesLeft[2].duration = 5;
largeSweeperFramesLeft[3].index = 4; largeSweeperFramesLeft[3].duration = 5;
largeSweeperFramesLeft[4].index = 3; largeSweeperFramesLeft[4].duration = 5;
largeSweeperFramesLeft[5].index = 2; largeSweeperFramesLeft[5].duration = 5;
largeSweeperFramesLeft[6].index = 1; largeSweeperFramesLeft[6].duration = 5;
largeSweeperFramesLeft[7].index = 0; largeSweeperFramesLeft[7].duration = 5;

Rage::Animation largeSweeperAnimations[2];

largeSweeperAnimations[0].image.gfx = large_sweeperTiles;
largeSweeperAnimations[0].image.gfxLen = large_sweeperTilesLen;
largeSweeperAnimations[0].image.pal = large_sweeperPal;
largeSweeperAnimations[0].image.palLen = large_sweeperPalLen;
largeSweeperAnimations[0].size = SpriteSize_32x32;
largeSweeperAnimations[0].looping = true;
largeSweeperAnimations[0].frameCount = 8;
largeSweeperAnimations[0].frames = largeSweeperFramesRight;

largeSweeperAnimations[1] = largeSweeperAnimations[0];
largeSweeperAnimations[1].frames = largeSweeperFramesLeft;

Rage::SpriteDefinition largeSweeperDef;

largeSweeperDef.version = 2;
largeSweeperDef.spriteID = SWEEPER;
largeSweeperDef.animationCount = 2;
largeSweeperDef.animations = largeSweeperAnimations;
