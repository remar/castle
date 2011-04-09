#ifndef ENEMY_H
#define ENEMY_H

#include "Collidable.h"
#include "Field.h"

class Enemy : public Collidable
{
 public:
  Enemy(int sprite, Field *field);

 protected:
  Field *field;
};

#endif
