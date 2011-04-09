#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <rage.h>
#include "Sound.h"
#include "Input.h"
#include "GameMode.h"

class GameLogic
{
 public:
  GameLogic();
  void update();

 private:
  GameMode *gameMode;
  Mode mode;
};

#endif
