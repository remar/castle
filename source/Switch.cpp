#include "Switch.h"

#include "graphics/ids.h"

int switchSprMap[] = {SWITCH_YELLOW, SWITCH_GREEN, SWITCH_BLUE};

Switch::Switch(int blockX, int blockY, Color color, bool active)
  : Collidable(switchSprMap[color]), color(color), active(active)
{
  setBoundingBox(16, 16, 0, 0);
  moveAbs(blockX * 32 + 8, blockY * 32 + 8);

  if(active)
    setAnimation(SWITCH_LIT);
  else
    setAnimation(SWITCH_OFF);
}

void
Switch::toggle()
{
  active = !active;

  if(active)
    setAnimation(SWITCH_LIT);
  else
    setAnimation(SWITCH_OFF);
}

bool
Switch::isActive()
{
  return active;
}
