#ifndef MARKER_H
#define MARKER_H

#include "Collidable.h"
#include "Field.h"

class Marker : public Collidable
{
 public:
  Marker();
  void update();
  void setPosition(int blockX, int blockY);
  void getPosition(int *blockX, int *blockY);
  void setIsBlocked(bool blocked);
  bool isBlocked();
  void setBreakableTTL(Field::BreakableTTL ttl);
  Field::BreakableTTL getBreakableTTL();

 private:
  bool blocked;
  int blockX, blockY;
  Field::BreakableTTL breakableTTL;
};

#endif
