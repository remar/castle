#ifndef TARGET_H
#define TARGET_H

#include "Object.h"
#include "Color.h"

class Target : public Object
{
 public:
  Target(int blockX, int blockY, Color color);
};

#endif
