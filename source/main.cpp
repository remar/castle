#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>
#include <time.h>

#include <rage.h>
#include "Input.h"
#include "Sound.h"
#include "GameLogic.h"
#include "DataManager.h"

#include "debug.h"

Rage rage;
Sound sound;
Input input;
DataManager dataManager;

int main(void)
{
  srand(time(0));

  rage.init();

  rage.selectOnTop(Rage::SUB);

  GameLogic *gameLogic = new GameLogic();

  while(1)
    {
      input.getInput();
      gameLogic->update();
      TRY(rage.redraw());
    }

  return 0;
}
