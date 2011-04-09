#ifndef TRUNDLER_H
#define TRUNDLER_H

#include "Enemy.h"

class Trundler : public Enemy
{
 public:
  Trundler(int blockX, int blockY, Field *field);
  void update();

 private:
  enum TrundlerDir {TRUNDLE_RIGHT, TRUNDLE_LEFT};
  TrundlerDir dir;

  bool inAir;
  int yvel;
  int yvelTimer;
};

#endif
