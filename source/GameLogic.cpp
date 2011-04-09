#include "GameLogic.h"

#include <stdio.h>
#include "Intro.h"
#include "LevelSelect.h"
#include "Level.h"

GameLogic::GameLogic()
{
  mode = INTRO;
  gameMode = new Intro();
}

void
GameLogic::update()
{
  Mode oldMode = mode;

  mode = gameMode->update();

  if(oldMode != mode)
    {
      delete gameMode;
      gameMode = 0;

      switch(mode)
	{
	case INTRO:
	  // Create "intro" mode
	  gameMode = new Intro();
	  break;

	case MENU:
	  // Create "menu" mode
	  break;

	case LEVELSELECT:
	  gameMode = new LevelSelect();
	  break;

	case LEVEL:
	  // Create "level" mode
	  gameMode = new Level();
	  break;

	case BONUSLEVEL:
	  // Create "bonus level" mode
	  break;

	case RESTARTLEVEL:
	  gameMode = new Level();
	  mode = LEVEL;
	  break;
	  
	default:
	  {
	    consoleDemoInit();
	    printf("ERROR: Crash in gameloop!\n");
	    while(1);
	  }
	  break;
	}
    }
}
