#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "Collidable.h"
#include "Color.h"

class Teleporter : public Collidable
{
 public:
  Teleporter(int blockX, int blockY, Color color);
};

#endif
