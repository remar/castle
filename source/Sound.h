#ifndef SOUND_H
#define SOUND_H

#include "sounds.h"

class Sound
{
 public:
  Sound();
  void play(int s);

 private:
  void initEffects();
};

#endif
