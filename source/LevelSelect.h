#ifndef LEVEL_SELECT_H
#define LEVEL_SELECT_H

#include "GameMode.h"

class LevelSelect : public GameMode
{
 public:
  LevelSelect();
  ~LevelSelect();
  Mode update();

 private:
  int levelSprites[12];
  int set;
};

#endif
