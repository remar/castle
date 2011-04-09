#include "Target.h"

#include "graphics/ids.h"

int sprTargetMap[] = {TARGET_YELLOW, TARGET_GREEN, TARGET_BLUE};

Target::Target(int blockX, int blockY, Color color)
  : Object(sprTargetMap[color])
{
  moveAbs(blockX * 32 + 3, blockY * 32 + 3);
}
