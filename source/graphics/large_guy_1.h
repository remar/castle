#include "spr_right_guy1.h"
#include "spr_left_guy1.h"

#include "ids.h"

Rage::ImageDefinition guy1_right;
guy1_right.gfx = spr_right_guy1Tiles;
guy1_right.gfxLen = spr_right_guy1TilesLen;
guy1_right.pal = spr_right_guy1Pal;
guy1_right.palLen = spr_right_guy1PalLen;

Rage::ImageDefinition guy1_left;
guy1_left.gfx = spr_left_guy1Tiles;
guy1_left.gfxLen = spr_left_guy1TilesLen;
guy1_left.pal = spr_left_guy1Pal;
guy1_left.palLen = spr_left_guy1PalLen;


Rage::Animation guy1Animations[6];

// RIGHT ANIMATIONS ///////////////////////////////////////////////////////////

// Stand right
Rage::Frame guy1StandRight[1];
guy1StandRight[0].index = 0; guy1StandRight[0].duration = 60;

guy1Animations[0].image = guy1_right;
guy1Animations[0].size = SpriteSize_32x32;
guy1Animations[0].looping = false;
guy1Animations[0].frameCount = 1;
guy1Animations[0].frames = guy1StandRight;

// Walk right
Rage::Frame guy1WalkRight[8];
guy1WalkRight[0].index = 0; guy1WalkRight[0].duration = 10;
guy1WalkRight[1].index = 1; guy1WalkRight[1].duration = 10;
guy1WalkRight[2].index = 2; guy1WalkRight[2].duration = 10;
guy1WalkRight[3].index = 3; guy1WalkRight[3].duration = 10;
guy1WalkRight[4].index = 4; guy1WalkRight[4].duration = 10;
guy1WalkRight[5].index = 5; guy1WalkRight[5].duration = 10;
guy1WalkRight[6].index = 6; guy1WalkRight[6].duration = 10;
guy1WalkRight[7].index = 7; guy1WalkRight[7].duration = 10;

guy1Animations[1].image = guy1_right;
guy1Animations[1].size = SpriteSize_32x32;
guy1Animations[1].looping = true;
guy1Animations[1].frameCount = 8;
guy1Animations[1].frames = guy1WalkRight;

// Jump right
Rage::Frame guy1JumpRight[1];
guy1StandRight[0].index = 8; guy1StandRight[0].duration = 60;

guy1Animations[2].image = guy1_right;
guy1Animations[2].size = SpriteSize_32x32;
guy1Animations[2].looping = false;
guy1Animations[2].frameCount = 1;
guy1Animations[2].frames = guy1JumpRight;


// LEFT ANIMATIONS ///////////////////////////////////////////////////////////

// Stand left
Rage::Frame guy1StandLeft[1];
guy1StandLeft[0].index = 0; guy1StandLeft[0].duration = 60;

guy1Animations[3].image = guy1_left;
guy1Animations[3].size = SpriteSize_32x32;
guy1Animations[3].looping = false;
guy1Animations[3].frameCount = 1;
guy1Animations[3].frames = guy1StandLeft;

// Walk left
Rage::Frame guy1WalkLeft[8];
guy1WalkLeft[0].index = 0; guy1WalkLeft[0].duration = 10;
guy1WalkLeft[1].index = 1; guy1WalkLeft[1].duration = 10;
guy1WalkLeft[2].index = 2; guy1WalkLeft[2].duration = 10;
guy1WalkLeft[3].index = 3; guy1WalkLeft[3].duration = 10;
guy1WalkLeft[4].index = 4; guy1WalkLeft[4].duration = 10;
guy1WalkLeft[5].index = 5; guy1WalkLeft[5].duration = 10;
guy1WalkLeft[6].index = 6; guy1WalkLeft[6].duration = 10;
guy1WalkLeft[7].index = 7; guy1WalkLeft[7].duration = 10;

guy1Animations[4].image = guy1_left;
guy1Animations[4].size = SpriteSize_32x32;
guy1Animations[4].looping = true;
guy1Animations[4].frameCount = 8;
guy1Animations[4].frames = guy1WalkLeft;

// Jump left
Rage::Frame guy1JumpLeft[1];
guy1StandLeft[0].index = 8; guy1StandLeft[0].duration = 60;

guy1Animations[5].image = guy1_left;
guy1Animations[5].size = SpriteSize_32x32;
guy1Animations[5].looping = false;
guy1Animations[5].frameCount = 1;
guy1Animations[5].frames = guy1JumpLeft;


Rage::SpriteDefinition large_guy1Def;
large_guy1Def.version = 2;
large_guy1Def.spriteID = LARGE_PLAYER;
large_guy1Def.animationCount = 6;
large_guy1Def.animations = guy1Animations;
