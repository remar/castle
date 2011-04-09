#ifndef FIELD_H
#define FIELD_H

#include <list>

#include "Collidable.h"
#include "Breakable.h"
#include "Color.h"

#include "Block.h"
#include "Switch.h"
#include "Teleporter.h"
#include "Target.h"

class Field
{
 public:
  enum BlockType {EMPTY, BLOCK, BREAKABLE};
  enum BreakableTTL {FOREVER, SHORT, LONG};

  Field();
  ~Field();
  void update(); // Update the breakable blocks
  void setBlock(int x, int y, BlockType block, BreakableTTL ttl = FOREVER);
  void moveCollidableRel(Collidable *collidable, int x, int y);
  bool blockEmpty(int x, int y);
  bool blockBreakable(int x, int y);
  void setScroll(int scrollX, int scrollY);
  bool collidableIntersectsBreakable(Collidable *collidable);
  bool blocksMarker(int blockX, int blockY);
  void addBlock(int blockX, int blockY, Color color, bool on);
  void addSwitch(int blockX, int blockY, Color color, bool on);
  void addTeleporter(int blockX, int blockY, Color color);
  void addTarget(int blockX, int blockY, Color color);
  void interactWithField(Collidable *collidable);

 private:
  void toggleBlocksAndSwitches(Color color);
  void teleport(Collidable *collidable, Color color);

  int field[16*12];

  // TODO: Make a <list> of breakables instead
  Breakable *breakables[16*12];

  std::list<Block *> yellowBlocks;
  std::list<Block *> greenBlocks;
  std::list<Block *> blueBlocks;

  std::list<Switch *> yellowSwitches;
  std::list<Switch *> greenSwitches;
  std::list<Switch *> blueSwitches;

  std::list<Teleporter *> yellowTeleporters;
  std::list<Teleporter *> greenTeleporters;
  std::list<Teleporter *> blueTeleporters;

  struct
  {
    Target *target;
    int x;
    int y;
    bool set;
  }
  targets[3];

  // targets[0] is yellow target
  // targets[1] is green target
  // targets[2] is blue target
};

#endif
