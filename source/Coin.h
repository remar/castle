#ifndef COIN_H
#define COIN_H

#include "Collidable.h"

class Coin : public Collidable
{
 public:
  Coin(int blockX, int blockY);
};

#endif
