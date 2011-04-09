#ifndef SWEEPER_H
#define SWEEPER_H

#include "Enemy.h"

class Sweeper : public Enemy
{
 public:
  Sweeper(int blockX, int blockY, Field *field);
  void update();

 private:
  enum SweeperDir {SWEEP_RIGHT, SWEEP_LEFT};
  SweeperDir dir;
};

#endif
