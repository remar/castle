#ifndef TRAPPER_H
#define TRAPPER_H

#include "Enemy.h"

class Trapper : public Enemy
{
 public:
  Trapper(int blockX, int blockY, Field *field);
  void update();

 private:
  enum TrapperDir {TRAPPER_RIGHT, TRAPPER_UP, TRAPPER_LEFT, TRAPPER_DOWN};
  TrapperDir dir;
};

#endif
