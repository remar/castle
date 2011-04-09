#include <stdio.h>
#include "Intro.h"

#include "debug.h"

#include <rage.h>
extern Rage rage;

#include "Input.h"
extern Input input;

#include "DataManager.h"
extern DataManager dataManager;

#include "graphics/ids.h"

Intro::Intro()
{
  // Setup backgrounds
  TRY(rage.setupBackground(Rage::SUB, 0, Rage::BG_MAP_256x256, 8, 8));
  TRY(rage.setupBackground(Rage::SUB, 1, Rage::BG_MAP_256x256, 32, 32));

  TRY(rage.setupBackground(Rage::MAIN, 0, Rage::BG_MAP_256x256, 32, 32));

  dataManager.loadTileSet(DataManager::SUB, BG_MAIN);
  dataManager.loadTileSet(DataManager::SUB, LARGE_TILES);
  dataManager.loadTileSet(DataManager::MAIN, LARGE_TILES);

  for(int y = 0; y < 6;y++)
    for(int x = 0;x < 8;x++)
      {
	TRY(rage.setTile(Rage::SUB, 1, x, y, LARGE_TILES, 0));
	TRY(rage.setTile(Rage::MAIN, 0, x, y, LARGE_TILES, 0));
      }

  for(int y = 0;y < 32;y++)
    for(int x = 0;x < 32;x++)
      {
	TRY(rage.setTile(Rage::SUB, 0, x, y, BG_MAIN, 12));
      }

#define A 10
#define B 11
#define C 12
#define D 13
#define E 14
#define F 15

  u16 title[]
    = {0, 0, 0, C, 0, 0, 0, C, 0, 0, 0, C, 0, 0, 2, C, 0, C, C, C, 0, 0, 0,
       B, C, C, C, 8, C, 4, C, 4, C, C, C, C, 7, C, C, B, C, C, C, 8, C, C,
       6, C, C, C, 0, 0, 0, C, 0, 0, 0, C, C, A, C, C, 6, C, C, C, 0, 0, C,
       5, C, C, C, 4, C, 4, C, C, C, 8, C, C, 5, C, C, 9, C, C, C, 4, C, C,
       0, 0, 1, C, 0, C, 0, C, 0, 0, 0, C, C, 0, C, C, 0, 0, 0, C, 0, 0, 0,

       C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, 
       C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, 

       C, C, C, C, C, C, C, C, 0, 0, 0, C, 0, 0, 0, C, C, C, C, C, C, C, C, 
       C, C, C, C, C, C, C, C, B, C, 7, C, 4, C, C, C, C, C, C, C, C, C, C, 
       C, C, C, C, C, C, C, C, 6, C, 6, C, 0, 0, C, C, C, C, C, C, C, C, C, 
       C, C, C, C, C, C, C, C, 5, C, 5, C, 8, C, C, C, C, C, C, C, C, C, C, 
       C, C, C, C, C, C, C, C, 0, 0, 0, C, 0, C, C, C, C, C, C, C, C, C, C, 

       C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, 
       C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, C, 

       C, C, C, 2, 0, 0, C, 0, C, C, C, 0, C, 0, 0, 0, C, 0, 0, 0, C, C, C, 
       C, C, C, 4, C, C, C, 7, C, C, C, 7, C, C, B, C, C, 8, C, C, C, C, C, 
       C, C, C, 0, 0, C, C, A, C, C, C, 6, C, C, 6, C, C, 0, 1, C, C, C, C, 
       C, C, C, 8, C, C, C, 5, C, C, C, 9, C, C, 5, C, C, 4, C, C, C, C, C, 
       C, C, C, 0, 0, 0, C, 0, 0, 2, C, 0, C, C, 0, C, C, 0, 0, 0, C, C, C, 

       0xBEEF};

  for(int i = 0, x = 0, y = 0;title[i+1] != 0xBEEF;i++)
    {
      TRY(rage.setTile(Rage::SUB, 0, x, y, BG_MAIN, title[i]));

      x++;

      if(x == 23)
	{
	  x = 0;
	  y++;
	}
    }

#undef A
#undef B
#undef C
#undef D
#undef E
#undef F      

  rage.setBackgroundScroll(Rage::SUB, 0, -36, -20);
}

Intro::~Intro()
{
  TRY(rage.releaseBackground(Rage::SUB, 0));
  TRY(rage.releaseBackground(Rage::SUB, 1));

  TRY(rage.releaseBackground(Rage::MAIN, 0));

  dataManager.unloadGraphics();
}

Mode
Intro::update()
{
  if(input.keyPressed(KEY_START))
    return LEVELSELECT;

  return INTRO;
}
