#include "Object.h"
#include <stdio.h>

#include <rage.h>
extern Rage rage;

#include "DataManager.h"
extern DataManager dataManager;

#include "debug.h"

Object::Object(int sprite)
  : x(0), y(0), destroyTimer(0), destroyMe(false),
    smallSpriteInst(0), largeSpriteInst(0),
    scrollX(0), scrollY(0), show(true)
{
  bool loadSub = dataManager.loadSprite(DataManager::SUB, sprite);
  bool loadMain = dataManager.loadSprite(DataManager::MAIN, sprite);

  if(loadSub == false || loadMain == false)
    {
      consoleDemoInit();
      printf("[Object::Object]\nUnable to load sprite: %d\n",
	     sprite);
      while(1);
    }

  TRY(largeSpriteInst = rage.createSpriteInstance(Rage::SUB, sprite));
  TRY(smallSpriteInst = rage.createSpriteInstance(Rage::MAIN, sprite));

  if(largeSpriteInst == 0 || smallSpriteInst == 0)
    {
      consoleDemoInit();
      printf("[Object::Object]\nSpriteInst L:%d S:%d\nSprite: %d\n",
	     largeSpriteInst,
	     smallSpriteInst,
	     sprite);
      while(1);
    }
}

Object::~Object()
{
  TRY(rage.removeSpriteInstance(Rage::SUB, largeSpriteInst));
  TRY(rage.removeSpriteInstance(Rage::MAIN, smallSpriteInst));
}

void
Object::update()
{
  if(destroyTimer > 0)
    {
      --destroyTimer;
      if(destroyTimer == 0)
	{
	  destroyMe = true;
	}
    }
}

void
Object::moveAbs(int x, int y)
{
  this->x = x;
  this->y = y;

  TRY(rage.moveSpriteAbs(Rage::MAIN, smallSpriteInst, x/2, y/2));
  TRY(rage.moveSpriteAbs(Rage::SUB, largeSpriteInst, x - scrollX, y - scrollY));

  if(y - scrollY < -32 || y - scrollY > 192)
    {
      // Hide sprite if it's outside this window
      TRY(rage.showSprite(Rage::SUB, largeSpriteInst, false));
    }
  else
    {
      TRY(rage.showSprite(Rage::SUB, largeSpriteInst, show));
    }
}

void
Object::moveRel(int x, int y)
{
  this->x += x;
  this->y += y;

  TRY(rage.moveSpriteAbs(Rage::MAIN, smallSpriteInst, this->x/2, this->y/2));
  TRY(rage.moveSpriteRel(Rage::SUB, largeSpriteInst, x, y));

  if(y - scrollY < -32 || y - scrollY > 192)
    {
      // Hide sprite if it's outside this window
      TRY(rage.showSprite(Rage::SUB, largeSpriteInst, false));
    }
  else
    {
      TRY(rage.showSprite(Rage::SUB, largeSpriteInst, show));
    }
}

void
Object::setAnimation(int anim)
{
  int res1, res2;

  TRY(res1 = rage.selectAnimation(Rage::MAIN, smallSpriteInst, anim));
  TRY(res2 = rage.selectAnimation(Rage::SUB, largeSpriteInst, anim));

  if(res1 == 0 || res2 == 0)
    {
      consoleDemoInit();
      printf("[Object::setAnimation] %d %d\n[Rage] %s\n",
	     res1,
	     res2,
	     rage.getErrorString());
      while(1);
    }
}

void
Object::setScroll(int scrollX, int scrollY)
{
  this->scrollX = scrollX;
  this->scrollY = scrollY;

  TRY(rage.moveSpriteAbs(Rage::SUB, largeSpriteInst, x - scrollX, y - scrollY));

  if(y - scrollY < -32 || y - scrollY > 192)
    {
      // Hide sprite if it's outside this window
      TRY(rage.showSprite(Rage::SUB, largeSpriteInst, false));
    }
  else
    {
      TRY(rage.showSprite(Rage::SUB, largeSpriteInst, show));
    }
}

void
Object::setVisible(bool show)
{
  this->show = show;

  TRY(rage.showSprite(Rage::SUB, largeSpriteInst, show));
  TRY(rage.showSprite(Rage::MAIN, smallSpriteInst, show));
}

bool
Object::destroy()
{
  return destroyMe;
}

int
Object::getX()
{
  return x;
}

int
Object::getY()
{
  return y;
}
