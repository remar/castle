#ifndef INTRO_H
#define INTRO_H

#include "GameMode.h"

class Intro : public GameMode
{
 public:
  Intro();
  ~Intro();
  Mode update();
};

#endif
