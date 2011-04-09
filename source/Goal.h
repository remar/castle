#ifndef GOAL_H
#define GOAL_H

#include "Collidable.h"

class Goal : public Collidable
{
 public:
  Goal(int blockX, int blockY);
  void update();
  void openGoal();
  bool goalIsOpen();

 private:
  bool isOpen;
};

#endif
