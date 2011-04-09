#ifndef BLOCK_H
#define BLOCK_H

#include "Object.h"
#include "Color.h"

class Block : public Object
{
 public:
  Block(int blockX, int blockY, Color color, bool on);
  bool toggle();

 private:
  Color color;
  bool switchedOn;
};

#endif
