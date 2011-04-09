#ifndef BOOTS_H
#define BOOTS_H

#include "Collidable.h"

class Boots : public Collidable
{
 public:
  Boots(int blockX, int blockY);
  void update();

 private:
  int bob;
  int bobDelay;
};

#endif
