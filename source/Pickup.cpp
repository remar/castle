#include "Pickup.h"
#include "graphics/ids.h"

#define BOB_DELAY 6

int pickupSprites[] = {PICKUP_01, PICKUP_02, PICKUP_03, PICKUP_04, PICKUP_05,
		       PICKUP_06, PICKUP_07, PICKUP_08, PICKUP_09, PICKUP_10,
		       PICKUP_11, PICKUP_12, PICKUP_13, PICKUP_14};

Pickup::Pickup(int pickupType, int blockX, int blockY)
  : Collidable(pickupSprites[pickupType]),
    bob(0),
    bobDelay(BOB_DELAY)
{
  this->pickupType = pickupType;
  type = Collidable::CT_PICKUP;
  moveAbs(blockX * 32 + 4, blockY * 32 + 4);
  setBoundingBox(12, 10, 6, 7);
}

// Hehe. Hihi. Hoho. Bogobogo!
#define MAGIC_NUMBER 0xDEADBEEF

void
Pickup::update()
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
