#include "Breakable.h"

#include "graphics/ids.h"

Breakable::Breakable(int blockX, int blockY, int ttl)
  : Object(BREAKABLE)
{
  moveAbs(blockX*32, blockY*32);

  if(ttl != 0)
    {
      destroyTimer = ttl;
    }
}

void
Breakable::update()
{
  Object::update();

  if(destroyTimer == 90)
    {
      setAnimation(BLINK_BRICK);
    }
}
