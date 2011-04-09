#include "Teleporter.h"

#include "graphics/ids.h"

int sprTeleMap[] = {TELE_YELLOW, TELE_GREEN, TELE_BLUE};

Teleporter::Teleporter(int blockX, int blockY, Color color)
  : Collidable(sprTeleMap[color])
{
  setBoundingBox(10, 10, 9, 9);
  moveAbs(blockX * 32 + 2, blockY * 32 + 2);
}
