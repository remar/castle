#include "Boots.h"

#include "graphics/ids.h"

#define BOB_DELAY 6

Boots::Boots(int blockX, int blockY)
  : Collidable(BOOTS), bob(0), bobDelay(BOB_DELAY)
{
  setBoundingBox(10, 10, 7, 7);

  moveAbs(blockX * 32 + 4, blockY * 32 + 4);

  type = CT_BOOTS;

  collidableBlocksMarker = false;
}

#define MAGIC_NUMBER 0xDEADBEEF

void
Boots::update()
{
  Object::update();

  int bobbing[] = {0, 0, 1, 0, 1, 0, 0, -1, 0, -1, MAGIC_NUMBER};

  if(--bobDelay == 0)
    {
      moveRel(0, bobbing[bob]);
      bobDelay = BOB_DELAY;

      if(bobbing[++bob] == MAGIC_NUMBER)
	bob = 0;
    }
}
