#include "ids.h"

Rage::Frame largeMarkerFrames[3];

largeMarkerFrames[0].index = 0; largeMarkerFrames[0].duration = 10;
largeMarkerFrames[1].index = 1; largeMarkerFrames[1].duration = 10;
largeMarkerFrames[2].index = 2; largeMarkerFrames[2].duration = 10;

Rage::Animation largeMarkerAnimations[2];

largeMarkerAnimations[0].image.gfx = large_markerTiles;
largeMarkerAnimations[0].image.gfxLen = large_markerTilesLen;
largeMarkerAnimations[0].image.pal = large_markerPal;
largeMarkerAnimations[0].image.palLen = large_markerPalLen;
largeMarkerAnimations[0].size = SpriteSize_32x32;
largeMarkerAnimations[0].looping = true;
largeMarkerAnimations[0].frameCount = 3;
largeMarkerAnimations[0].frames = largeMarkerFrames;

largeMarkerAnimations[1].image.gfx = large_redmarkerTiles;
largeMarkerAnimations[1].image.gfxLen = large_redmarkerTilesLen;
largeMarkerAnimations[1].image.pal = large_redmarkerPal;
largeMarkerAnimations[1].image.palLen = large_redmarkerPalLen;
largeMarkerAnimations[1].size = SpriteSize_32x32;
largeMarkerAnimations[1].looping = true;
largeMarkerAnimations[1].frameCount = 3;
largeMarkerAnimations[1].frames = largeMarkerFrames;

Rage::SpriteDefinition largeMarkerDef;

largeMarkerDef.version = 2;
largeMarkerDef.spriteID = MARKER;
largeMarkerDef.animationCount = 2;
largeMarkerDef.animations = largeMarkerAnimations;
