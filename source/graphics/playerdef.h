#include "ids.h"


// Need to define these things BEFORE including this file:

// Rage::ImageDefinition player_right;
// Rage::ImageDefinition player_left;

// Need to modify these things AFTER including this file:

// playerAnimations[0].size = SpriteSize_16x16;
// playerAnimations[1].size = SpriteSize_16x16;
// playerAnimations[2].size = SpriteSize_16x16;
// playerAnimations[3].size = SpriteSize_16x16;
// playerAnimations[4].size = SpriteSize_16x16;
// playerAnimations[5].size = SpriteSize_16x16;

Rage::Animation playerAnimations[6];

// RIGHT ANIMATIONS ///////////////////////////////////////////////////////////

// Stand right
Rage::Frame playerStandRight[1];
playerStandRight[0].index = 0; playerStandRight[0].duration = 60;

playerAnimations[0].image = player_right;
playerAnimations[0].size = SpriteSize_16x16;
playerAnimations[0].looping = false;
playerAnimations[0].frameCount = 1;
playerAnimations[0].frames = playerStandRight;

// Walk right
Rage::Frame playerWalkRight[8];
playerWalkRight[0].index = 0; playerWalkRight[0].duration = 10;
playerWalkRight[1].index = 1; playerWalkRight[1].duration = 10;
playerWalkRight[2].index = 2; playerWalkRight[2].duration = 10;
playerWalkRight[3].index = 3; playerWalkRight[3].duration = 10;
playerWalkRight[4].index = 4; playerWalkRight[4].duration = 10;
playerWalkRight[5].index = 5; playerWalkRight[5].duration = 10;
playerWalkRight[6].index = 6; playerWalkRight[6].duration = 10;
playerWalkRight[7].index = 7; playerWalkRight[7].duration = 10;

playerAnimations[1].image = player_right;
playerAnimations[1].size = SpriteSize_16x16;
playerAnimations[1].looping = true;
playerAnimations[1].frameCount = 8;
playerAnimations[1].frames = playerWalkRight;

// Jump right
Rage::Frame playerJumpRight[1];
playerJumpRight[0].index = 8; playerJumpRight[0].duration = 60;

playerAnimations[2].image = player_right;
playerAnimations[2].size = SpriteSize_16x16;
playerAnimations[2].looping = false;
playerAnimations[2].frameCount = 1;
playerAnimations[2].frames = playerJumpRight;


// LEFT ANIMATIONS ///////////////////////////////////////////////////////////

// Stand left
playerAnimations[3].image = player_left;
playerAnimations[3].size = SpriteSize_16x16;
playerAnimations[3].looping = false;
playerAnimations[3].frameCount = 1;
playerAnimations[3].frames = playerStandRight;

// Walk left
playerAnimations[4].image = player_left;
playerAnimations[4].size = SpriteSize_16x16;
playerAnimations[4].looping = true;
playerAnimations[4].frameCount = 8;
playerAnimations[4].frames = playerWalkRight;

// Jump left
playerAnimations[5].image = player_left;
playerAnimations[5].size = SpriteSize_16x16;
playerAnimations[5].looping = false;
playerAnimations[5].frameCount = 1;
playerAnimations[5].frames = playerJumpRight;

Rage::SpriteDefinition playerDef;
playerDef.spriteID = PLAYER;
playerDef.version = 2;
playerDef.animationCount = 6;
playerDef.animations = playerAnimations;
