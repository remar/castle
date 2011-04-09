#ifndef COLLIDABLE_H
#define COLLIDABLE_H

// An object in the game with collision detection

#include "Object.h"

class Collidable : public Object
{
 public:
  enum CollidableType {CT_PLAYER, CT_COIN, CT_PICKUP, CT_BOOTS,
		       CT_GOAL, CT_BLUESPARK, CT_REDSPARK};

  Collidable(int sprite);
  virtual ~Collidable();
  virtual void update();

  void setBoundingBox(int width, int height, int offX, int offY);
  bool collides(Collidable *other);

  int getBoxWidth();
  int getBoxHeight();
  int getBoxOffsetX();
  int getBoxOffsetY();

  CollidableType getType();
  int getPickupType();
  bool blocksMarker();

  // Tell collidable to remove itself in some nice way
  // TODO: Provide list of Objects to create graphical effects?
  void remove();

 protected:
  int boxWidth, boxHeight, boxX, boxY;  
  CollidableType type;
  int pickupType; // Used for the tetri style pickups
  bool collidableBlocksMarker;
};

#endif
