#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <nds.h>
#include "graphics/ids.h"

struct LevelData
{
  const u8 *data;
  u32 length;
  bool cleared;
};

class DataManager
{
 public:
  enum Screen {MAIN, SUB};

  DataManager();
  ~DataManager();

  bool loadSprite(Screen screen, int id);
  bool loadTileSet(Screen screen, int id);
  void unloadGraphics();

  void setSelectedLevel(int set, int level);
  int getSelectedSet();
  LevelData getLevelData();

  bool saveLevelCleared();
  bool getLevelCleared(int set, int level);
  bool getSetUnlocked(int set);

 private:
  void initLevelData();
  void clearLoadedInfo();

  LevelData nullLevel;
  LevelData levels[4][12];
  bool setUnlocked[4];

  bool spriteLoaded[2][LAST_SPRITE];
  bool tileSetLoaded[2][LAST_TILESET];

  int set;
  int level;
};

#endif
