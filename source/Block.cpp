#include "Block.h"

#include "graphics/ids.h"

int sprMap[] = {BLOCK_YELLOW, BLOCK_GREEN, BLOCK_BLUE};

Block::Block(int blockX, int blockY, Color color, bool on)
  :   Object(sprMap[color]), color(color), switchedOn(on)
{
  moveAbs(blockX * 32, blockY * 32);

  if(switchedOn)
    setAnimation(BLOCK_ON);
  else
    setAnimation(BLOCK_OFF);
}

bool
Block::toggle()
{
  switchedOn = !switchedOn;

  if(switchedOn)
    setAnimation(BLOCK_ON);
  else
    setAnimation(BLOCK_OFF);

  return switchedOn;
}
