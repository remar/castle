#include "bg_main.h"

#include "ids.h"

Rage::TileSetDefinition bgMainDef;
bgMainDef.version = 2;
bgMainDef.tileSetID = BG_MAIN;
bgMainDef.image.gfx = bg_mainTiles;
bgMainDef.image.gfxLen = bg_mainTilesLen;
bgMainDef.image.pal = bg_mainPal;
bgMainDef.image.palLen = bg_mainPalLen;
