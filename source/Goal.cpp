#include "Goal.h"

#include "graphics/ids.h"

Goal::Goal(int blockX, int blockY)
  : Collidable(GOAL), isOpen(false)
{
  setBoundingBox(10, 10, 7, 7);

  moveAbs(blockX * 32 + 4, blockY * 32 + 4);

  setAnimation(CLOSED_GOAL);

  type = CT_GOAL;
}

void
Goal::update()
{

}

void
Goal::openGoal()
{
  isOpen = true;
  setAnimation(OPEN_GOAL);
}

bool
Goal::goalIsOpen()
{
  return isOpen;
}

