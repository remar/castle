#include "tiles.h"

#include "ids.h"

Rage::TileSetDefinition tilesDef;
tilesDef.version = 2;
tilesDef.tileSetID = LARGE_TILES;
tilesDef.image.gfx = tilesTiles;
tilesDef.image.gfxLen = tilesTilesLen;
tilesDef.image.pal = tilesPal;
tilesDef.image.palLen = tilesPalLen;
