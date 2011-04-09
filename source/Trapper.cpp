#include "Trapper.h"

#include "graphics/ids.h"

Trapper::Trapper(int blockX, int blockY, Field *field)
  : Enemy(TRAPPER, field)
{
  setBoundingBox(22, 22, 3, 3);
  moveAbs(blockX * 32 + 2, blockY * 32 + 2);
}

void
Trapper::update()
{
  // MUUUUUVE IIIYYYYT

  int oldX = x;
  int oldY = y;

  //enum TrapperDir {TRAPPER_RIGHT, TRAPPER_UP, TRAPPER_LEFT, TRAPPER_DOWN};

  int moveX[] = {1, 0, -1, 0};
  int moveY[] = {0, -1, 0, 1};

  field->moveCollidableRel(this, moveX[dir], moveY[dir]);

  if(oldX == x && oldY == y)
    {
      // Change direction!
      TrapperDir newDir[] = {TRAPPER_UP, TRAPPER_LEFT, TRAPPER_DOWN,
			     TRAPPER_RIGHT};

      dir = newDir[dir];
    }
}
