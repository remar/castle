#include "Marker.h"

#include "graphics/ids.h"

Marker::Marker()
  : Collidable(MARKER), blocked(false), blockX(0), blockY(0),
    breakableTTL(Field::FOREVER)
{
  setBoundingBox(32, 32, 0, 0);
}

void
Marker::update()
{

}

void
Marker::setPosition(int blockX, int blockY)
{
  this->blockX = blockX;
  this->blockY = blockY;

  moveAbs(blockX * 32, blockY * 32);
}

void
Marker::getPosition(int *blockX, int *blockY)
{
  *blockX = this->blockX;
  *blockY = this->blockY;
}

void
Marker::setIsBlocked(bool blocked)
{
  if(this->blocked != blocked)
    {
      this->blocked = blocked;

      setAnimation(blocked ? RED_MARKER : OK_MARKER);
    }
}

bool
Marker::isBlocked()
{
  return blocked;
}

void
Marker::setBreakableTTL(Field::BreakableTTL ttl)
{
  breakableTTL = ttl;
}

Field::BreakableTTL
Marker::getBreakableTTL()
{
  return breakableTTL;
}
