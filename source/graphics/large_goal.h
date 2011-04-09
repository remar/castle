#include "ids.h"

Rage::Frame largeClosedGoalFrames[1];

largeClosedGoalFrames[0].index = 0; largeClosedGoalFrames[0].duration = 60;

Rage::Frame largeOpenGoalFrames[4];

largeOpenGoalFrames[0].index = 0; largeOpenGoalFrames[0].duration = 5;
largeOpenGoalFrames[1].index = 1; largeOpenGoalFrames[1].duration = 5;
largeOpenGoalFrames[2].index = 2; largeOpenGoalFrames[2].duration = 5;
largeOpenGoalFrames[3].index = 3; largeOpenGoalFrames[3].duration = 5;

Rage::Animation largeGoalAnimations[2];

largeGoalAnimations[0].image.gfx = large_closed_goalTiles;
largeGoalAnimations[0].image.gfxLen = large_closed_goalTilesLen;
largeGoalAnimations[0].image.pal = large_closed_goalPal;
largeGoalAnimations[0].image.palLen = large_closed_goalPalLen;
largeGoalAnimations[0].size = SpriteSize_32x32;
largeGoalAnimations[0].looping = false;
largeGoalAnimations[0].frameCount = 1;
largeGoalAnimations[0].frames = largeClosedGoalFrames;

largeGoalAnimations[1].image.gfx = large_open_goalTiles;
largeGoalAnimations[1].image.gfxLen = large_open_goalTilesLen;
largeGoalAnimations[1].image.pal = large_open_goalPal;
largeGoalAnimations[1].image.palLen = large_open_goalPalLen;
largeGoalAnimations[1].size = SpriteSize_32x32;
largeGoalAnimations[1].looping = true;
largeGoalAnimations[1].frameCount = 4;
largeGoalAnimations[1].frames = largeOpenGoalFrames;

Rage::SpriteDefinition largeGoalDef;

largeGoalDef.version = 2;
largeGoalDef.spriteID = GOAL;
largeGoalDef.animationCount = 2;
largeGoalDef.animations = largeGoalAnimations;
