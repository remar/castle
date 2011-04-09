#include "ids.h"

Rage::Frame smallClosedGoalFrames[1];

smallClosedGoalFrames[0].index = 0; smallClosedGoalFrames[0].duration = 60;

Rage::Frame smallOpenGoalFrames[4];

smallOpenGoalFrames[0].index = 0; smallOpenGoalFrames[0].duration = 5;
smallOpenGoalFrames[1].index = 1; smallOpenGoalFrames[1].duration = 5;
smallOpenGoalFrames[2].index = 2; smallOpenGoalFrames[2].duration = 5;
smallOpenGoalFrames[3].index = 3; smallOpenGoalFrames[3].duration = 5;

Rage::Animation smallGoalAnimations[2];

smallGoalAnimations[0].image.gfx = small_closed_goalTiles;
smallGoalAnimations[0].image.gfxLen = small_closed_goalTilesLen;
smallGoalAnimations[0].image.pal = small_closed_goalPal;
smallGoalAnimations[0].image.palLen = small_closed_goalPalLen;
smallGoalAnimations[0].size = SpriteSize_16x16;
smallGoalAnimations[0].looping = false;
smallGoalAnimations[0].frameCount = 1;
smallGoalAnimations[0].frames = smallClosedGoalFrames;

smallGoalAnimations[1].image.gfx = small_open_goalTiles;
smallGoalAnimations[1].image.gfxLen = small_open_goalTilesLen;
smallGoalAnimations[1].image.pal = small_open_goalPal;
smallGoalAnimations[1].image.palLen = small_open_goalPalLen;
smallGoalAnimations[1].size = SpriteSize_16x16;
smallGoalAnimations[1].looping = true;
smallGoalAnimations[1].frameCount = 4;
smallGoalAnimations[1].frames = smallOpenGoalFrames;

Rage::SpriteDefinition smallGoalDef;

smallGoalDef.version = 2;
smallGoalDef.spriteID = GOAL;
smallGoalDef.animationCount = 2;
smallGoalDef.animations = smallGoalAnimations;
