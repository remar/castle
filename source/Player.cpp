#include "Player.h"

#include "graphics/ids.h"

#include "Input.h"
extern Input input;

#include "Sound.h"
extern Sound sound;

Player::Player(Field *field)
  : Collidable(PLAYER), field(field), direction(RIGHT),
    xvel(0), yvel(0), inAir(false), gravityDelay(12), highJump(false)
{
  setAnimation(STAND_RIGHT);
  setBoundingBox(10, 28, 5, 0);
}

void
Player::update()
{
  Collidable::update();

  if(input.keyPressed(KEY_RIGHT))
    {
      direction = RIGHT;
      xvel = 1;

      if(inAir)
        setAnimation(JUMP_RIGHT);
      else
        setAnimation(WALK_RIGHT);
    }
  else if(input.keyPressed(KEY_LEFT))
    {
      direction = LEFT;
      xvel = -1;

      if(inAir)
        setAnimation(JUMP_LEFT);
      else
        setAnimation(WALK_LEFT);
    }

  if((input.keyPressed(KEY_UP) || input.keyPressed(KEY_L)) && !inAir)
    {
      int blockX1 = (x+boxX)/32;
      int blockX2 = (x+boxX+boxWidth-1)/32;
      int blockY = y/32 - 1;

      if(field->blockEmpty(blockX1, blockY)
	 && field->blockEmpty(blockX2, blockY))
	{
	  sound.play(S_JUMP);

	  inAir = true;
	  yvel = (highJump == true ? -3 : -2);

	  gravityDelayTimer = gravityDelay;

	  if(direction == LEFT)
	    setAnimation(JUMP_LEFT);
	  else
	    setAnimation(JUMP_RIGHT);
	}
    }

  if(input.keyReleased(KEY_RIGHT))
    {
      xvel = 0;

      if(!inAir)
	setAnimation(STAND_RIGHT);
    }
  if(input.keyReleased(KEY_LEFT))
    {
      xvel = 0;

      if(!inAir)
	setAnimation(STAND_LEFT);
    }

  if(yvel < 5 && inAir)
    {
      if(--gravityDelayTimer == 0)
        {
          yvel++;
	  
          gravityDelayTimer = gravityDelay;
        }
    }

  int tempy = y;
  field->moveCollidableRel(this, xvel, yvel);

  // have we landed?
  if(y == tempy && yvel != 0)
    {
      inAir = false;
      yvel = 0;

      if(xvel != 0)
        setAnimation(direction == LEFT ? WALK_LEFT : WALK_RIGHT);
      else
        setAnimation(direction == LEFT ? STAND_LEFT : STAND_RIGHT);
    }

  // check if we're now suddenly in the air
  if(!inAir)
    {
      if(field->blockEmpty((x+boxX)/32, (y+boxY+boxHeight)/32)
	 && field->blockEmpty((x+boxX+boxWidth-1)/32, (y+boxY+boxHeight)/32))
	{
	  inAir = true;
	  yvel = 1;
	  gravityDelayTimer = gravityDelay;

	  if(direction == LEFT)
	    setAnimation(JUMP_LEFT);
	  else
	    setAnimation(JUMP_RIGHT);
	}
    }
}

void
Player::setHighJump()
{
  highJump = true;
}
