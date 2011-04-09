#ifndef GAMEMODE_H
#define GAMEMODE_H

enum Mode
  {
    INTRO,
    MENU,
    LEVELSELECT,
    LEVEL,
    BONUSLEVEL,
    RESTARTLEVEL
  };

class GameMode
{
 public:
  GameMode();
  virtual ~GameMode();
  virtual Mode update();
};

#endif
