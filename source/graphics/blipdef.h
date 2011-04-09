#include "ids.h"

#include "blipgreen.h"
#include "blipyellow.h"
#include "blipred.h"

Rage::Frame blipOneFrame[1];
blipOneFrame[0].index = 0; blipOneFrame[0].duration = 60;

Rage::Frame blipTwoFrames[2];
blipTwoFrames[0].index = 0; blipTwoFrames[0].duration = 30;
blipTwoFrames[1].index = 1; blipTwoFrames[1].duration = 30;

Rage::Animation blipAnimations[3];

// Green blip
blipAnimations[0].image.gfx = blipgreenTiles;
blipAnimations[0].image.gfxLen = blipgreenTilesLen;
blipAnimations[0].image.pal = blipgreenPal;
blipAnimations[0].image.palLen = blipgreenPalLen;
blipAnimations[0].size = SpriteSize_32x32;
blipAnimations[0].looping = true;
blipAnimations[0].frameCount = 2;
blipAnimations[0].frames = blipTwoFrames;

// Yellow blip
blipAnimations[1].image.gfx = blipyellowTiles;
blipAnimations[1].image.gfxLen = blipyellowTilesLen;
blipAnimations[1].image.pal = blipyellowPal;
blipAnimations[1].image.palLen = blipyellowPalLen;
blipAnimations[1].size = SpriteSize_32x32;
blipAnimations[1].looping = true;
blipAnimations[1].frameCount = 2;
blipAnimations[1].frames = blipTwoFrames;

// Red blip
blipAnimations[2].image.gfx = blipredTiles;
blipAnimations[2].image.gfxLen = blipredTilesLen;
blipAnimations[2].image.pal = blipredPal;
blipAnimations[2].image.palLen = blipredPalLen;
blipAnimations[2].size = SpriteSize_32x32;
blipAnimations[2].looping = false;
blipAnimations[2].frameCount = 1;
blipAnimations[2].frames = blipOneFrame;

Rage::SpriteDefinition blipDef;

blipDef.version = 2;
blipDef.spriteID = BLIP;
blipDef.animationCount = 3;
blipDef.animations = blipAnimations;
