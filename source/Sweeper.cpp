#include "Sweeper.h"

#include "graphics/ids.h"

Sweeper::Sweeper(int blockX, int blockY, Field *field)
  : Enemy(SWEEPER, field), dir(SWEEP_RIGHT)
{
  moveAbs(blockX * 32, blockY * 32);
  setBoundingBox(22, 22, 3, 3);
}

void
Sweeper::update()
{
  int oldX = x;

  switch(dir)
    {
    case SWEEP_RIGHT:
      field->moveCollidableRel(this, 1, 0);
      if(x == oldX) // Collision with wall
	{
	  dir = SWEEP_LEFT;
	  setAnimation(SWEEPER_LEFT);
	}
      break;

    case SWEEP_LEFT:
      field->moveCollidableRel(this, -1, 0);
      if(x == oldX) // Collision with wall
	{
	  dir = SWEEP_RIGHT;
	  setAnimation(SWEEPER_RIGHT);
	}
      break;
    }
}
