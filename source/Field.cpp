#include "Field.h"

#include "Sound.h"
extern Sound sound;

#include <nds.h>
#include <stdio.h>

Field::Field()
{
  for(int i = 0;i < 16*12;i++)
    {
      field[i] = EMPTY;
      breakables[i] = 0;
    }

  for(int i = 0;i < 3;i++)
    {
      targets[i].set = false;
      targets[i].target = 0;
    }
}

Field::~Field()
{
  for(int i = 0;i < 16*12;i++)
    {
      if(breakables[i])
	{
	  delete breakables[i];
	  breakables[i] = 0;
	}
    }

  std::list<Block *>::iterator blockIt;

  for(blockIt = yellowBlocks.begin();blockIt != yellowBlocks.end();blockIt++)
    delete (*blockIt);

  for(blockIt = greenBlocks.begin();blockIt != greenBlocks.end();blockIt++)
    delete (*blockIt);

  for(blockIt = blueBlocks.begin();blockIt != blueBlocks.end();blockIt++)
    delete (*blockIt);

  std::list<Switch *>::iterator swIt;

  for(swIt = yellowSwitches.begin();swIt != yellowSwitches.end();swIt++)
    delete (*swIt);

  for(swIt = greenSwitches.begin();swIt != greenSwitches.end();swIt++)
    delete (*swIt);

  for(swIt = blueSwitches.begin();swIt != blueSwitches.end();swIt++)
    delete (*swIt);

  std::list<Teleporter *>::iterator teleIt;

  for(teleIt = yellowTeleporters.begin()
	;teleIt != yellowTeleporters.end();teleIt++)
    delete (*teleIt);

  for(teleIt = greenTeleporters.begin()
	;teleIt != greenTeleporters.end();teleIt++)
    delete (*teleIt);

  for(teleIt = blueTeleporters.begin()
	;teleIt != blueTeleporters.end();teleIt++)
    delete (*teleIt);

  for(int i = 0;i < 3;i++)
    {
      if(targets[i].set)
	delete targets[i].target;
    }
}

void
Field::update()
{
  for(int i = 0;i < 16*12;i++)
    {
      if(breakables[i])
	{
	  breakables[i]->update();
	  if(breakables[i]->destroy())
	    {
	      setBlock(i % 16, i / 16, EMPTY);
	    }
	}
    }
}

void
Field::setBlock(int x, int y, BlockType block, BreakableTTL ttl)
{
  if(x < 0 || x > 15)
    return;
  if(y < 0 || y > 11)
    return;

  field[x + y * 16] = block;

  if(block == BREAKABLE && breakables[x + y * 16] == 0)
    {
      int breakableTTL = 0;

      switch(ttl)
	{
	case FOREVER:
	  breakableTTL = 0;
	  break;

	case SHORT:
	  breakableTTL = 3;
	  break;

	case LONG:
	  breakableTTL = 300;
	  break;
	}

      breakables[x + y * 16] = new Breakable(x, y, breakableTTL);
    }
  else if(block == EMPTY && breakables[x + y * 16] != 0)
    {
      sound.play(S_DESTROY);

      delete breakables[x + y * 16];
      breakables[x + y * 16] = 0;
    }
}

void
Field::moveCollidableRel(Collidable *collidable, int relx, int rely)
{
  // Move collidable object in the field, first along the x axis, then
  // along the y axis.

  int tempx = collidable->getX();
  int tempy = collidable->getY();

  int boxWidth = collidable->getBoxWidth();
  int boxHeight = collidable->getBoxHeight();
  int boxXOff = collidable->getBoxOffsetX();
  int boxYOff = collidable->getBoxOffsetY();

  if(relx > 0) // moving right
    {
      for(int i = 0;i < relx;i++)
        {
          if(field[(tempx+boxWidth+boxXOff)/32
		   + ((tempy+boxYOff)/32)*16] != 0
             || field[(tempx+boxWidth+boxXOff)/32
		      + ((tempy+boxHeight+boxYOff-1)/32)*16] != 0)
            break;

          tempx++;
        }
    }
  else if(relx < 0) // moving left
    {
      for(int i = 0;i > relx;i--)
        {
          if(field[(tempx+boxXOff-1)/32
		   + ((tempy+boxYOff)/32)*16] != 0
             || field[(tempx+boxXOff-1)/32
		      + ((tempy+boxHeight+boxYOff-1)/32)*16] != 0)
            break;

          tempx--;
        }
    }

  if(rely > 0) // moving down
    {
      for(int i = 0;i < rely;i++)
        {
          if(field[(tempx+boxXOff)/32
		   + ((tempy+boxHeight+boxYOff)/32)*16] != 0
             || field[(tempx+boxWidth+boxXOff-1)/32
		      + ((tempy+boxHeight+boxYOff)/32)*16] != 0)
            break;

          tempy++;
        }
    }
  else if(rely < 0) // moving up
    {
      for(int i = 0;i > rely;i--)
        {
          if(field[(tempx+boxXOff)/32
		   + ((tempy+boxYOff-1)/32)*16] != 0
             || field[(tempx+boxWidth+boxXOff-1)/32
		      + ((tempy+boxYOff-1)/32)*16] != 0)
            break;

          tempy--;
        }      
    }

  collidable->moveAbs(tempx, tempy);
}

bool
Field::blockEmpty(int x, int y)
{
  return field[x + y * 16] == EMPTY;
}

bool
Field::blockBreakable(int x, int y)
{
  return field[x + y * 16] == BREAKABLE;
}

void
Field::setScroll(int scrollX, int scrollY)
{
  for(int i = 0;i < 16*12;i++)
    {
      if(breakables[i])
	{
	  breakables[i]->setScroll(scrollX, scrollY);
	}
    }

  std::list<Block *>::iterator blockIt;

  for(blockIt = yellowBlocks.begin();blockIt != yellowBlocks.end();blockIt++)
    (*blockIt)->setScroll(scrollX, scrollY);

  for(blockIt = greenBlocks.begin();blockIt != greenBlocks.end();blockIt++)
    (*blockIt)->setScroll(scrollX, scrollY);

  for(blockIt = blueBlocks.begin();blockIt != blueBlocks.end();blockIt++)
    (*blockIt)->setScroll(scrollX, scrollY);

  std::list<Switch *>::iterator swIt;

  for(swIt = yellowSwitches.begin();swIt != yellowSwitches.end();swIt++)
    (*swIt)->setScroll(scrollX, scrollY);

  for(swIt = greenSwitches.begin();swIt != greenSwitches.end();swIt++)
    (*swIt)->setScroll(scrollX, scrollY);

  for(swIt = blueSwitches.begin();swIt != blueSwitches.end();swIt++)
    (*swIt)->setScroll(scrollX, scrollY);


  std::list<Teleporter *>::iterator teleIt;

  for(teleIt = yellowTeleporters.begin()
	;teleIt != yellowTeleporters.end();teleIt++)
    (*teleIt)->setScroll(scrollX, scrollY);

  for(teleIt = greenTeleporters.begin()
	;teleIt != greenTeleporters.end();teleIt++)
    (*teleIt)->setScroll(scrollX, scrollY);

  for(teleIt = blueTeleporters.begin()
	;teleIt != blueTeleporters.end();teleIt++)
    (*teleIt)->setScroll(scrollX, scrollY);

  for(int i = 0;i < 3;i++)
    {
      if(targets[i].set)
	targets[i].target->setScroll(scrollX, scrollY);
    }
}

bool
Field::collidableIntersectsBreakable(Collidable *collidable)
{
  int x1 = collidable->getX() + collidable->getBoxOffsetX();
  int x2 = x1 + collidable->getBoxWidth() - 1;

  int y1 = collidable->getY() + collidable->getBoxOffsetY();
  int y2 = y1 + collidable->getBoxHeight() - 1;

  x1 /= 32;
  x2 /= 32;
  y1 /= 32;
  y2 /= 32;

  return (field[x1 + y1 * 16] == BREAKABLE
	  || field[x2 + y1 * 16] == BREAKABLE
	  || field[x1 + y2 * 16] == BREAKABLE
	  || field[x2 + y2 * 16] == BREAKABLE);
}

bool
Field::blocksMarker(int x, int y)
{
  return field[x + y * 16] == BLOCK;
}

void
Field::addBlock(int blockX, int blockY, Color color, bool on)
{
  switch(color)
    {
    case YELLOW:
      yellowBlocks.push_front(new Block(blockX, blockY, color, on));
      break;

    case GREEN:
      greenBlocks.push_front(new Block(blockX, blockY, color, on));
      break;

    case BLUE:
      blueBlocks.push_front(new Block(blockX, blockY, color, on));
      break;

    default:
      consoleDemoInit();
      printf("ERROR: Default case reached in Field::addBlock()\n");
      while(1);
      break;
    }

  if(on)
    setBlock(blockX, blockY, BLOCK);
}

void
Field::addSwitch(int blockX, int blockY, Color color, bool on)
{
  switch(color)
    {
    case YELLOW:
      yellowSwitches.push_front(new Switch(blockX, blockY, color, on));
      break;

    case GREEN:
      greenSwitches.push_front(new Switch(blockX, blockY, color, on));
      break;

    case BLUE:
      blueSwitches.push_front(new Switch(blockX, blockY, color, on));
      break;

    default:
      consoleDemoInit();
      printf("ERROR: Default case reached in Field::addSwitch()\n");
      while(1);
      break;
    }
}

void
Field::addTeleporter(int blockX, int blockY, Color color)
{
  switch(color)
    {
    case YELLOW:
      yellowTeleporters.push_front(new Teleporter(blockX, blockY, color));
      break;

    case GREEN:
      greenTeleporters.push_front(new Teleporter(blockX, blockY, color));
      break;

    case BLUE:
      blueTeleporters.push_front(new Teleporter(blockX, blockY, color));
      break;

    default:
      consoleDemoInit();
      printf("ERROR: Default case reached in Field::addTeleporter()\n");
      while(1);
      break;
    }  
}

void
Field::addTarget(int blockX, int blockY, Color color)
{
  if(targets[color].set)
    {
      consoleDemoInit();
      printf("ERROR: Only one target per color allowed!\n");
      while(1);
    }

  targets[color].target = new Target(blockX, blockY, color);

  targets[color].x = blockX;
  targets[color].y = blockY;

  targets[color].set = true;
}

void
Field::interactWithField(Collidable *collidable)
{
  std::list<Switch *>::iterator swIt;

  for(swIt = yellowSwitches.begin();swIt != yellowSwitches.end();swIt++)
    {
      if(collidable->collides((*swIt)) && (*swIt)->isActive())
	{
	  toggleBlocksAndSwitches(YELLOW);
	}
    }

  for(swIt = greenSwitches.begin();swIt != greenSwitches.end();swIt++)
    {
      if(collidable->collides((*swIt)) && (*swIt)->isActive())
	{
	  toggleBlocksAndSwitches(GREEN);
	}
    }

  for(swIt = blueSwitches.begin();swIt != blueSwitches.end();swIt++)
    {
      if(collidable->collides((*swIt)) && (*swIt)->isActive())
	{
	  toggleBlocksAndSwitches(BLUE);
	}
    }


  std::list<Teleporter *>::iterator teleIt;

  for(teleIt = yellowTeleporters.begin()
	;teleIt != yellowTeleporters.end();teleIt++)
    {
      if(collidable->collides((*teleIt)))
	{
	  teleport(collidable, YELLOW);
	  return;
	}
    }

  for(teleIt = greenTeleporters.begin()
	;teleIt != greenTeleporters.end();teleIt++)
    {
      if(collidable->collides((*teleIt)))
	{
	  teleport(collidable, GREEN);
	  return;
	}
    }

  for(teleIt = blueTeleporters.begin()
	;teleIt != blueTeleporters.end();teleIt++)
    {
      if(collidable->collides((*teleIt)))
	{
	  teleport(collidable, BLUE);
	  return;
	}
    }
}

void
Field::toggleBlocksAndSwitches(Color color)
{
  std::list<Block *>::iterator blIt;
  std::list<Switch *>::iterator swIt;
  int blockX, blockY;

  switch(color)
    {
    case YELLOW:
      for(blIt = yellowBlocks.begin();blIt != yellowBlocks.end();blIt++)
	{
	  bool on = (*blIt)->toggle();
	  blockX = (*blIt)->getX() / 32;
	  blockY = (*blIt)->getY() / 32;
	  setBlock(blockX, blockY, on ? BLOCK : EMPTY);
	}
      for(swIt = yellowSwitches.begin();swIt != yellowSwitches.end();swIt++)
	(*swIt)->toggle();
      break;

    case GREEN:
      for(blIt = greenBlocks.begin();blIt != greenBlocks.end();blIt++)
	{
	  bool on = (*blIt)->toggle();
	  blockX = (*blIt)->getX() / 32;
	  blockY = (*blIt)->getY() / 32;
	  setBlock(blockX, blockY, on ? BLOCK : EMPTY);
	}
      for(swIt = greenSwitches.begin();swIt != greenSwitches.end();swIt++)
	(*swIt)->toggle();
      break;

    case BLUE:
      for(blIt = blueBlocks.begin();blIt != blueBlocks.end();blIt++)
	{
	  bool on = (*blIt)->toggle();
	  blockX = (*blIt)->getX() / 32;
	  blockY = (*blIt)->getY() / 32;
	  setBlock(blockX, blockY, on ? BLOCK : EMPTY);
	}
      for(swIt = blueSwitches.begin();swIt != blueSwitches.end();swIt++)
	(*swIt)->toggle();
      break;
    }
}

void
Field::teleport(Collidable *collidable, Color color)
{
  if(targets[color].set)
    {
      // TODO: Play teleport sound
      int targetX = targets[color].x * 32 + 16 
	- collidable->getBoxWidth()/2 - collidable->getBoxOffsetX();
      int targetY = targets[color].y * 32 + 16
	- collidable->getBoxHeight()/2 - collidable->getBoxOffsetY();

      collidable->moveAbs(targetX, targetY);
    }
  else
    {
      consoleDemoInit();
      printf("ERROR: Teleport target missing!\n");
      while(1);
    }
}
