#include "Level.h"

#include "debug.h"
#include "Pickup.h"
#include "Marker.h"
#include "Coin.h"
#include "Goal.h"
#include "BlueSpark.h"
#include "RedSpark.h"
#include "Boots.h"
#include "Sweeper.h"
#include "Trundler.h"
#include "Trapper.h"
#include "Teleporter.h"

#include "Color.h"

#include <stdio.h>

#include <rage.h>
extern Rage rage;

#include "Sound.h"
extern Sound sound;

#include "Input.h"
extern Input input;

#include "DataManager.h"
extern DataManager dataManager;

#include "graphics/ids.h"

// PickupBlock represents between 1 to 5 markers. The offsets are used
// when the number of markers is between 2 and 5 inclusive.
struct PickupBlock
{
  int numberOfBlocks;
  int offsets[4][2];
};

PickupBlock pickupBlocks[14] =
  {
    {1, {{ 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}}},
    {2, {{ 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}}},
    {2, {{ 0,  1}, { 0,  0}, { 0,  0}, { 0,  0}}},
    {3, {{-1,  0}, { 1,  0}, { 0,  0}, { 0,  0}}},
    {3, {{ 0, -1}, { 0,  1}, { 0,  0}, { 0,  0}}},
    {3, {{ 0, -1}, { 1,  0}, { 0,  0}, { 0,  0}}},
    {3, {{-1,  0}, { 0, -1}, { 0,  0}, { 0,  0}}},
    {3, {{-1,  0}, { 0,  1}, { 0,  0}, { 0,  0}}},
    {3, {{ 0,  1}, { 1,  0}, { 0,  0}, { 0,  0}}},
    {4, {{ 0, -1}, { 1,  0}, { 0,  1}, { 0,  0}}},
    {4, {{ 0, -1}, {-1,  0}, { 1,  0}, { 0,  0}}},
    {4, {{ 0, -1}, {-1,  0}, { 0,  1}, { 0,  0}}},
    {4, {{-1,  0}, { 1,  0}, { 0,  1}, { 0,  0}}},
    {5, {{ 0, -1}, { 0,  1}, {-1,  0}, { 1,  0}}},
  };

Marker *markers[5];

Level::Level()
  : GameMode(), currentPickup(-1),
    isTouching(false), oldTouchX(-1), oldTouchY(-1)
{
  TRY(rage.setupBackground(Rage::SUB, 0, Rage::BG_MAP_512x512, 32, 32));

  // Border layer
  TRY(rage.setupBackground(Rage::MAIN, 0, Rage::BG_MAP_256x256, 16, 16));

  // Tile layer
  TRY(rage.setupBackground(Rage::MAIN, 1, Rage::BG_MAP_256x256, 16, 16));

  field = new Field();

  dataManager.loadTileSet(DataManager::MAIN, SMALL_TILES);
  dataManager.loadTileSet(DataManager::MAIN, BORDER);
  dataManager.loadTileSet(DataManager::SUB, LARGE_TILES);

  player = new Player(field);

  for(int i = 0;i < 5;i++)
    {
      markers[i] = new Marker();
      markers[i]->setVisible(false);
    }

  int borderMap[] =
    {
      0, 1, 1, 1, 1, 1, 1, 2,
      3, 4, 4, 4, 4, 4, 4, 5,
      3, 4, 4, 4, 4, 4, 4, 5,
      3, 4, 4, 4, 4, 4, 4, 5,
      3, 4, 4, 4, 4, 4, 4, 5,
      6, 7, 7, 7, 7, 7, 7, 8,
    };

  // Clear border layer
  for(int i = 0;i < 16*16;i++)
    TRY(rage.setTile(Rage::MAIN, 0, i%16, i/16, BORDER, 4));

  for(int y = 0;y < 6;y++)
    for(int x = 0;x < 8;x++)
      {
	TRY(rage.setTile(Rage::MAIN, 0, x, y, BORDER, borderMap[y * 8 + x]));
      }

  // load in first level from predefined set of levels
  loadLevel();

  scrollX = 0;
  scrollY = 0;

}

Level::~Level()
{
  delete field;
  delete player;

  // Delete stuff in 'objects'
  std::list<Object *>::iterator objIt;
  for(objIt = objects.begin();objIt != objects.end();objIt++)
      delete (*objIt);

  // Delete stuff in 'collidables'
  std::list<Collidable *>::iterator colIt;
  for(colIt = collidables.begin();colIt != collidables.end();colIt++)
      delete (*colIt);

  // Delete stuff in 'enemies'
  std::list<Enemy *>::iterator enemyIt;
  for(enemyIt = enemies.begin();enemyIt != enemies.end();enemyIt++)
      delete (*enemyIt);

  // Delete markers
  for(int i = 0;i < 5;i++)
    delete markers[i];

  // Release backgrounds
  TRY(rage.releaseBackground(Rage::SUB, 0));

  TRY(rage.releaseBackground(Rage::MAIN, 0));
  TRY(rage.releaseBackground(Rage::MAIN, 1));

  dataManager.unloadGraphics();
}

Mode
Level::update()
{
  if(input.keyPressed(KEY_START))
    return LEVELSELECT;

  if(input.keyPressed(KEY_SELECT))
    {
      consoleDemoInit();
      rage.listFreeBlocks();
      while(1);
    }

  player->update();

  if(player->destroy())
    {
      // Player killed, restart level
      return RESTARTLEVEL;
    }

  field->update();

  field->interactWithField(player);

  // Set scroll, home in on player
  int scrollX = player->getX() - (256/2 - 10);
  int scrollY = player->getY() - (192/2 - 14);

  if(scrollX < 0)
    scrollX = 0;
  else if(scrollX > 256)
    scrollX = 256;

  if(scrollY < 0)
    scrollY = 0;
  else if(scrollY > 192)
    scrollY = 192;

  player->setScroll(scrollX, scrollY);

  // Update objects
  std::list<Object *>::iterator objIt;
  for(objIt = objects.begin();objIt != objects.end();)
    {
      (*objIt)->update();
      (*objIt)->setScroll(scrollX, scrollY);

      if((*objIt)->destroy())
	{
	  delete (*objIt);
	  objIt = objects.erase(objIt);

	  continue;
	}
      objIt++;
    }

  // Update enemies
  std::list<Enemy *>::iterator enemyIt;
  for(enemyIt = enemies.begin();enemyIt != enemies.end();)
    {
      (*enemyIt)->update();
      field->interactWithField((*enemyIt));
      (*enemyIt)->setScroll(scrollX, scrollY);

      if(field->collidableIntersectsBreakable(*enemyIt))
	{
	  (*enemyIt)->remove();
	}

      if(player->collides(*enemyIt))
	{
	  // Kill player object
	  player->remove();
	}

      // Check for collision between enemy and various collidables
      std::list<Collidable *>::iterator colIt;
      for(colIt = collidables.begin();colIt != collidables.end();colIt++)
	{
	  if((*enemyIt)->collides(*colIt))
	    {
	      switch((*colIt)->getType())
		{
		case Collidable::CT_BLUESPARK:
		case Collidable::CT_REDSPARK:
		  (*enemyIt)->remove();
		  break;

		default:
		  break;
		}
	    }
	}

      if((*enemyIt)->destroy())
	{
	  delete (*enemyIt);
	  enemyIt = enemies.erase(enemyIt);

	  continue;
	}
      enemyIt++;
    }

  // Update collidables
  std::list<Collidable *>::iterator colIt;
  for(colIt = collidables.begin();colIt != collidables.end();)
    {
      // TODO: Move this to placement of breakable?
      if(field->collidableIntersectsBreakable(*colIt))
	{
	  if((*colIt)->getType() != Collidable::CT_BLUESPARK
	     && (*colIt)->getType() != Collidable::CT_REDSPARK)
	  (*colIt)->remove();
	}

      if(player->collides(*colIt))
	{
	  switch((*colIt)->getType())
	    {
	    case Collidable::CT_COIN:
	      (*colIt)->remove();
	      sound.play(S_COIN);
	      if(--coinsToCollect == 0)
		{
		  // Open goal
		  goal->openGoal();
		}
	      break;

	    case Collidable::CT_PICKUP:
	      if(currentPickup == -1)
		{
		  currentPickup = (*colIt)->getPickupType();
		  (*colIt)->remove();

		  sound.play(S_BRICK);
		}
	      break;

	    case Collidable::CT_BOOTS:
	      (*colIt)->remove();
	      sound.play(S_BRICK);
	      player->setHighJump();
	      break;

	    case Collidable::CT_GOAL:
	      if(goal->goalIsOpen())
		{
		  // Level finished!!
		  dataManager.saveLevelCleared();
		  
		  // TODO: Do something nice here instead
		  return LEVELSELECT;
		}
	      break;

	    case Collidable::CT_BLUESPARK:
	    case Collidable::CT_REDSPARK:
	      {
		player->remove();
	      }
	      break;

	    default:
	      {
		consoleDemoInit();
		printf("ERROR: Default case reached in Level::update()\n");
		while(1);
	      }
	      break;
	    }
	}

      (*colIt)->update();
      (*colIt)->setScroll(scrollX, scrollY);
      if((*colIt)->destroy())
	{
	  delete (*colIt);
	  colIt = collidables.erase(colIt);
	  continue;
	}
      colIt++;
    }

  // See if player tries to place blocks
  if(input.keyPressed(KEY_TOUCH) && !input.keyHeld(KEY_DOWN)
     && currentPickup != -1)
    {
      isTouching = true;

      setMarkersVisible(true);

      int x, y;
      input.getTouch(&x, &y);

      x /= 16;
      y /= 16;      

      moveMarkers(x, y);
    }
  else if(input.keyReleased(KEY_TOUCH) && isTouching)
    {
      isTouching = false;

      setMarkersVisible(false);

      bool blocked = false;
      for(int i = 0;i < pickupBlocks[currentPickup].numberOfBlocks;i++)
	{
	  if(markers[i]->isBlocked())
	    blocked = true;
	}

      if(!blocked)
	{
	  sound.play(S_PLACE);

	  for(int i = 0;i < pickupBlocks[currentPickup].numberOfBlocks;i++)
	    {
	      int blockX, blockY;

	      markers[i]->getPosition(&blockX, &blockY);

	      field->setBlock(blockX, blockY, Field::BREAKABLE,
			      markers[i]->getBreakableTTL());
	    }	  

	  currentPickup = -1;
	}
    }

  // Remove block
  if(input.keyPressed(KEY_TOUCH) && input.keyHeld(KEY_DOWN))
    {
      int x, y;
      input.getTouch(&x, &y);

      x /= 16;
      y /= 16;

      if(field->blockBreakable(x, y))
	{
	  field->setBlock(x, y, Field::EMPTY);
	}
    }

  if(isTouching)
    {
      int x, y;
      input.getTouch(&x, &y);

      x /= 16;
      y /= 16;      

      moveMarkers(x, y);
    }

  for(int i = 0;i < 5;i++)
    {
      markers[i]->setScroll(scrollX, scrollY);
    }

  field->setScroll(scrollX, scrollY);

  TRY(rage.setBackgroundScroll(Rage::SUB, 0, scrollX, scrollY));
  TRY(rage.setBackgroundScroll(Rage::MAIN, 0, -scrollX/2, -scrollY/2));

  return LEVEL;
}

void
Level::loadLevel()
{
  // Level specification are 14x10 blocks big (as the playing field is
  // 16x12 blocks, and the outer blocks are always solid)

  LevelData levelData = dataManager.getLevelData();

  if(levelData.length == 0)
    {
      // NULL level data!
      consoleDemoInit();
      printf("Error: No such level!\n");
      while(1);
    }

  coinsToCollect = 0;

  for(int y = 0;y < 16;y++)
    for(int x = 0;x < 16;x++)
      {
	TRY(rage.setTile(Rage::MAIN, 1, x, y, SMALL_TILES, 62));
	TRY(rage.setTile(Rage::SUB, 0, x, y, LARGE_TILES, 62));
      }

  for(int y = 0;y < 10;y++)
    for(int x = 0;x < 14;x++)
      {
	//int tileID = level_1_1_bin[x + y * 14];
	int tileID = levelData.data[x + y * 14];

	TRY(rage.setTile(Rage::MAIN, 1, x+1, y+1, SMALL_TILES, tileID));
	TRY(rage.setTile(Rage::SUB, 0, x+1, y+1, LARGE_TILES, tileID));

	field->setBlock(x + 1, y + 1,
			tileID <= 33 ? Field::EMPTY : Field::BLOCK);
      }

  int nrObjects = levelData.data[140];

  for(int i = 0;i < nrObjects;i++)
    {
      int x = (levelData.data[141 + i*2] >> 4) + 1;
      int y = (levelData.data[141 + i*2] & 0x0f) + 1;
      int obj = levelData.data[141 + i*2 + 1];

      switch(obj)
	{
	case OBJ_PLAYER:
	  player->moveAbs(x*32 + 6, y*32 + 4);
	  break;

	case OBJ_GOAL:
	  goal = new Goal(x, y);
	  collidables.push_front(goal);
	  break;

	case OBJ_COIN:
	  collidables.push_front(new Coin(x, y));
	  coinsToCollect++;
	  break;

	case OBJ_BOOTS:
	  collidables.push_front(new Boots(x, y));
	  break;

	case OBJ_BREAKABLE:
	  field->setBlock(x, y, Field::BREAKABLE);
	  break;

	case OBJ_BLUESPARK:
	  collidables.push_front(new BlueSpark(x, y));
	  break;

	case OBJ_REDSPARK:
	  collidables.push_front(new RedSpark(x, y));
	  break;

	case OBJ_PICKUP01: case OBJ_PICKUP02: case OBJ_PICKUP03:
	case OBJ_PICKUP04: case OBJ_PICKUP05: case OBJ_PICKUP06:
	case OBJ_PICKUP07: case OBJ_PICKUP08: case OBJ_PICKUP09:
	case OBJ_PICKUP10: case OBJ_PICKUP11: case OBJ_PICKUP12:
	case OBJ_PICKUP13: case OBJ_PICKUP14:
	  collidables.push_front(new Pickup(obj - OBJ_PICKUP01, x, y));
	  break;

	case OBJ_SWEEPER:
	  enemies.push_front(new Sweeper(x, y, field));
	  break;

	case OBJ_TRUNDLER:
	  enemies.push_front(new Trundler(x, y, field));
	  break;

	case OBJ_TRAPPER:
	  enemies.push_front(new Trapper(x, y, field));
	  break;

	case OBJ_YBLOCK:
	  field->addBlock(x, y, YELLOW, true /* on */);
	  break;

	case OBJ_YHOLE:
	  field->addBlock(x, y, YELLOW, false /* off */);
	  break;

	case OBJ_GBLOCK:
	  field->addBlock(x, y, GREEN, true /* on */);
	  break;

	case OBJ_GHOLE:
	  field->addBlock(x, y, GREEN, false /* off */);
	  break;

	case OBJ_BBLOCK:
	  field->addBlock(x, y, BLUE, true /* on */);
	  break;

	case OBJ_BHOLE:
	  field->addBlock(x, y, BLUE, false /* off */);
	  break;

	case OBJ_YSWITCH_ON:
	  field->addSwitch(x, y, YELLOW, true /* on */);
	  break;

	case OBJ_YSWITCH_OFF:
	  field->addSwitch(x, y, YELLOW, false /* off */);
	  break;

	case OBJ_GSWITCH_ON:
	  field->addSwitch(x, y, GREEN, true /* on */);
	  break;

	case OBJ_GSWITCH_OFF:
	  field->addSwitch(x, y, GREEN, false /* off */);
	  break;

	case OBJ_BSWITCH_ON:
	  field->addSwitch(x, y, BLUE, true /* on */);
	  break;

	case OBJ_BSWITCH_OFF:
	  field->addSwitch(x, y, BLUE, false /* off */);
	  break;

	case OBJ_YTELEPORTER:
	  field->addTeleporter(x, y, YELLOW);
	  break;

	case OBJ_GTELEPORTER:
	  field->addTeleporter(x, y, GREEN);
	  break;

	case OBJ_BTELEPORTER:
	  field->addTeleporter(x, y, BLUE);
	  break;

	case OBJ_YTELE_DEST:
	  field->addTarget(x, y, YELLOW);
	  break;

	case OBJ_GTELE_DEST:
	  field->addTarget(x, y, GREEN);
	  break;

	case OBJ_BTELE_DEST:
	  field->addTarget(x, y, BLUE);
	  break;
	}
    }

  // fill in the border
  for(int x = 0;x < 16;x++)
    {
      field->setBlock(x, 0, Field::BLOCK);
      field->setBlock(x, 11, Field::BLOCK);
    }
  for(int y = 0;y < 12;y++)
    {
      field->setBlock(0, y, Field::BLOCK);
      field->setBlock(15, y, Field::BLOCK);
    }
}

void
Level::setMarkersVisible(bool visible)
{
  if(currentPickup == -1)
    return;

  for(int i = 0;i < pickupBlocks[currentPickup].numberOfBlocks;i++)
    {
      markers[i]->setVisible(visible);
      // markers[i]->setAnimation(OK_MARKER);
    }
}

void
Level::moveMarkers(int blockX, int blockY)
{
  if(currentPickup == -1)
    return;

  PickupBlock *block = &pickupBlocks[currentPickup];

  for(int i = 0;i < pickupBlocks[currentPickup].numberOfBlocks;i++)
    {
      int offX = (i == 0) ? 0 : block->offsets[i-1][0];
      int offY = (i == 0) ? 0 : block->offsets[i-1][1];

      markers[i]->setPosition(blockX+offX, blockY+offY);
      markers[i]->setBreakableTTL(Field::FOREVER);

      // Check for collision against various objects and background
      if(markerBlocked(markers[i]))
	{
	  markers[i]->setIsBlocked(true);
	}
      else
	{
	  markers[i]->setIsBlocked(false);
	}
    }
}

bool
Level::markerBlocked(Marker *marker)
{
  if(field->blocksMarker(marker->getX()/32, marker->getY()/32))
    return true;

  if(marker->collides(player))
    return true;

  std::list<Collidable *>::iterator colIt;
  for(colIt = collidables.begin();colIt != collidables.end();colIt++)
    {
      if(marker->collides(*colIt))
	{
	  if((*colIt)->blocksMarker())
	    return true;
	  else if((*colIt)->getType() == Collidable::CT_BLUESPARK)
	    marker->setBreakableTTL(Field::LONG);
	  else if((*colIt)->getType() == Collidable::CT_REDSPARK)
	    marker->setBreakableTTL(Field::SHORT);
	}
    }

  return false;
}
