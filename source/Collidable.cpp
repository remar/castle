#include "Collidable.h"

Collidable::Collidable(int sprite)
  : Object(sprite), collidableBlocksMarker(true)
{

}

Collidable::~Collidable()
{

}

void
Collidable::update()
{
  Object::update();
}


void
Collidable::setBoundingBox(int width, int height, int offX, int offY)
{
  boxWidth = width;
  boxHeight = height;
  boxX = offX;
  boxY = offY;
}

bool
Collidable::collides(Collidable *other)
{
  int box1x1, box1x2, box1y1, box1y2;
  int box2x1, box2x2, box2y1, box2y2;

  box1x1 = x + boxX;
  box1x2 = box1x1 + boxWidth;
  box1y1 = y + boxY;
  box1y2 = box1y1 + boxHeight;

  box2x1 = other->x + other->boxX;
  box2x2 = box2x1 + other->boxWidth;
  box2y1 = other->y + other->boxY;
  box2y2 = box2y1 + other->boxHeight;

  // Check if points from bounding box 2 is inside bounding box 1
  // x1, y1
  if(box2x1 >= box1x1 && box2x1 < box1x2
     && box2y1 >= box1y1 && box2y1 < box1y2)
    {
      return true;
    }
  // x2, y1
  if(box2x2 > box1x1 && box2x2 < box1x2
     && box2y1 >= box1y1 && box2y1 < box1y2)
    {
      return true;
    }
  // x1, y2
  if(box2x1 >= box1x1 && box2x1 < box1x2
     && box2y2 > box1y1 && box2y2 < box1y2)
    {
      return true;
    }
  // x2, y2
  if(box2x2 > box1x1 && box2x2 < box1x2
     && box2y2 > box1y1 && box2y2 < box1y2)
    {
      return true;
    }

  // Check if points from bounding box 1 is inside bounding box 2
  // x1, y1
  if(box1x1 >= box2x1 && box1x1 < box2x2
     && box1y1 >= box2y1 && box1y1 < box2y2)
    {
      return true;
    }
  // x2, y1
  if(box1x2 > box2x1 && box1x2 < box2x2
     && box1y1 >= box2y1 && box1y1 < box2y2)
    {
      return true;
    }
  // x1, y2
  if(box1x1 >= box2x1 && box1x1 < box2x2
     && box1y2 > box2y1 && box1y2 < box2y2)
    {
      return true;
    }
  // x2, y2
  if(box1x2 > box2x1 && box1x2 < box2x2
     && box1y2 > box2y1 && box1y2 < box2y2)
    {
      return true;
    }

  return false;
}

int
Collidable::getBoxWidth()
{
  return boxWidth;
}

int
Collidable::getBoxHeight()
{
  return boxHeight;
}

int
Collidable::getBoxOffsetX()
{
  return boxX;
}

int
Collidable::getBoxOffsetY()
{
  return boxY;
}

Collidable::CollidableType
Collidable::getType()
{
  return type;
}

int
Collidable::getPickupType()
{
  return pickupType;
}

bool
Collidable::blocksMarker()
{
  return collidableBlocksMarker;
}

void
Collidable::remove()
{
  destroyMe = true;
}

