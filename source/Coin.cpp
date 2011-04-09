#include "Coin.h"
#include "graphics/ids.h"

Coin::Coin(int blockX, int blockY)
  : Collidable(COIN)
{
  setBoundingBox(12, 10, 1, 4);

  type = Collidable::CT_COIN;

  moveAbs(blockX * 32 + 9, blockY * 32 + 8);
}
