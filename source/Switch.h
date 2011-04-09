#ifndef SWITCH_H
#define SWITCH_H

#include "Collidable.h"
#include "Color.h"

class Switch : public Collidable
{
 public:
  Switch(int blockX, int blockY, Color color, bool active);
  void toggle();
  bool isActive();

 private:
  Color color;
  bool active;
};

#endif
