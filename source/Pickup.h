#ifndef PICKUP_H
#define PICKUP_H

#include "Collidable.h"

class Pickup : public Collidable
{
 public:
  Pickup(int pickupType, int blockX, int blockY);
  void update();

 private:
  int bob;
  int bobDelay;
};

#endif
