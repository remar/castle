#include "Enemy.h"

Enemy::Enemy(int sprite, Field *field)
  : Collidable(sprite), field(field)
{
  collidableBlocksMarker = false;
}
