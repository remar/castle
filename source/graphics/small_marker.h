#include "ids.h"

Rage::Frame smallMarkerFrames[3];

smallMarkerFrames[0].index = 0; smallMarkerFrames[0].duration = 10;
smallMarkerFrames[1].index = 1; smallMarkerFrames[1].duration = 10;
smallMarkerFrames[2].index = 2; smallMarkerFrames[2].duration = 10;

Rage::Animation smallMarkerAnimations[2];

smallMarkerAnimations[0].image.gfx = small_markerTiles;
smallMarkerAnimations[0].image.gfxLen = small_markerTilesLen;
smallMarkerAnimations[0].image.pal = small_markerPal;
smallMarkerAnimations[0].image.palLen = small_markerPalLen;
smallMarkerAnimations[0].size = SpriteSize_16x16;
smallMarkerAnimations[0].looping = true;
smallMarkerAnimations[0].frameCount = 3;
smallMarkerAnimations[0].frames = smallMarkerFrames;

smallMarkerAnimations[1].image.gfx = small_redmarkerTiles;
smallMarkerAnimations[1].image.gfxLen = small_redmarkerTilesLen;
smallMarkerAnimations[1].image.pal = small_redmarkerPal;
smallMarkerAnimations[1].image.palLen = small_redmarkerPalLen;
smallMarkerAnimations[1].size = SpriteSize_16x16;
smallMarkerAnimations[1].looping = true;
smallMarkerAnimations[1].frameCount = 3;
smallMarkerAnimations[1].frames = smallMarkerFrames;

Rage::SpriteDefinition smallMarkerDef;

smallMarkerDef.version = 2;
smallMarkerDef.spriteID = MARKER;
smallMarkerDef.animationCount = 2;
smallMarkerDef.animations = smallMarkerAnimations;
