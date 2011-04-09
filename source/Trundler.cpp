#include "Trundler.h"

#include "graphics/ids.h"

#define TRUNDLER_FALL_DELAY 12

Trundler::Trundler(int blockX, int blockY, Field *field)
  : Enemy(TRUNDLER, field), dir(TRUNDLE_RIGHT), inAir(false), yvel(0),
    yvelTimer(TRUNDLER_FALL_DELAY)
{
  moveAbs(blockX * 32, blockY * 32);
  setBoundingBox(22, 25, 3, 3);
}

void
Trundler::update()
{
  // MOVE IT
  int oldX = x;
  int oldY = y;

  int animMap[] = {TRUNDLER_RIGHT, TRUNDLER_LEFT};

  if(inAir)
    {
      // Fall
      field->moveCollidableRel(this, 0, yvel);

      if(yvel < 4 && --yvelTimer == 0)
	{
	  yvel++;

	  yvelTimer = TRUNDLER_FALL_DELAY;
	}

      // See if we've landed
      if(oldY == y)
	{
	  inAir = false;
	  setAnimation(animMap[dir]);
	}
    }
  else
    {
      // Move in 'dir' direction
      int dirMap[] = {1, -1};
      TrundlerDir dirChangeMap[] = {TRUNDLE_LEFT, TRUNDLE_RIGHT};

      field->moveCollidableRel(this, dirMap[dir], 0);
      if(oldX == x)
	{
	  dir = dirChangeMap[dir];
	  setAnimation(animMap[dir]);
	}
    }

  // See if we're now suddenly in the air
  if(!inAir)
    {
      if(field->blockEmpty((x+boxX)/32, (y+boxY+boxHeight)/32)
	 && field->blockEmpty((x+boxX+boxWidth-1)/32, (y+boxY+boxHeight)/32))
	{
	  inAir = true;

	  setAnimation(TRUNDLER_PAUSE);

	  yvel = 1;
	  yvelTimer = TRUNDLER_FALL_DELAY;
	}
    }
}
