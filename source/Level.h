#ifndef LEVEL_H
#define LEVEL_H

#include <list>

#include "GameMode.h"
#include "Field.h"

#include "Object.h"
#include "Collidable.h"
#include "Enemy.h"

#include "Player.h"
#include "Marker.h"
#include "Goal.h"

// Enumeration of objects found in level file
enum {OBJ_PLAYER, OBJ_GOAL, OBJ_COIN, OBJ_BOOTS, OBJ_BREAKABLE, OBJ_BLUESPARK,
      OBJ_REDSPARK, OBJ_PICKUP01, OBJ_PICKUP02, OBJ_PICKUP03, OBJ_PICKUP04,
      OBJ_PICKUP05, OBJ_PICKUP06, OBJ_PICKUP07, OBJ_PICKUP08, OBJ_PICKUP09,
      OBJ_PICKUP10, OBJ_PICKUP11, OBJ_PICKUP12, OBJ_PICKUP13, OBJ_PICKUP14,
      OBJ_SWEEPER, OBJ_YBLOCK, OBJ_YHOLE, OBJ_YSWITCH_ON, OBJ_YSWITCH_OFF,
      OBJ_YTELEPORTER, OBJ_YTELE_DEST,
      OBJ_TRUNDLER, OBJ_GBLOCK, OBJ_GHOLE, OBJ_GSWITCH_ON, OBJ_GSWITCH_OFF,
      OBJ_GTELEPORTER, OBJ_GTELE_DEST,
      OBJ_TRAPPER, OBJ_BBLOCK, OBJ_BHOLE, OBJ_BSWITCH_ON, OBJ_BSWITCH_OFF,
      OBJ_BTELEPORTER, OBJ_BTELE_DEST };

class Level : public GameMode
{
 public:
  Level();
  ~Level();
  Mode update();

 private:
  void loadLevel();

  void setMarkersVisible(bool visible);
  void moveMarkers(int blockX, int blockY);

  bool markerBlocked(Marker *marker);
  Field *field;

  int scrollX, scrollY;

  Player *player;
  Goal *goal;

  int currentPickup;

  bool isTouching;
  int oldTouchX, oldTouchY;

  int coinsToCollect;

  std::list<Object *> objects;
  std::list<Collidable *> collidables;
  std::list<Enemy *> enemies;
};

#endif
