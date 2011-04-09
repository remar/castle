#include "border.h"

#include "ids.h"

Rage::TileSetDefinition borderDef;
borderDef.version = 2;
borderDef.tileSetID = BORDER;
borderDef.image.gfx = borderTiles;
borderDef.image.gfxLen = borderTilesLen;
borderDef.image.pal = borderPal;
borderDef.image.palLen = borderPalLen;
