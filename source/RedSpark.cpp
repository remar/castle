#include "RedSpark.h"

#include "graphics/ids.h"

RedSpark::RedSpark(int blockX, int blockY)
  : Collidable(RED_SPARK)
{
  setBoundingBox(32, 20, 0, 6);
  moveAbs(blockX * 32, blockY * 32);
  type = CT_REDSPARK;
  collidableBlocksMarker = false;
}
