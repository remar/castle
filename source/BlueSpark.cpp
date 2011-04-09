#include "BlueSpark.h"

#include "graphics/ids.h"

BlueSpark::BlueSpark(int blockX, int blockY)
  : Collidable(BLUE_SPARK)
{
  setBoundingBox(32, 20, 0, 6);
  moveAbs(blockX * 32, blockY * 32);
  type = CT_BLUESPARK;
  collidableBlocksMarker = false;
}
