#ifndef PLAYER_H
#define PLAYER_H

#include "Collidable.h"
#include "Field.h"

class Player : public Collidable
{
 public:
  Player(Field *field);
  void update();
  void setHighJump();

 private:
  Field *field;

  enum Dir {LEFT, RIGHT} direction;
  int xvel, yvel;
  bool inAir;

  int gravityDelayTimer;
  int gravityDelay;

  bool highJump;
};

#endif
