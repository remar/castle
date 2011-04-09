#ifndef BREAKABLE_H
#define BREAKABLE_H

#include "Object.h"

class Breakable : public Object
{
 public:
 Breakable(int blockX, int blockY, int ttl);
 void update();
};

#endif
