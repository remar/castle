#include "coeplugin.h"

#include "map.h"
#include "tile.h"
#include "tilelayer.h"
#include "tileset.h"

#include <QDataStream>
#include <QFile>
#include <QFileInfo>
#include <QDir>

#define COE_MAP_WIDTH 14
#define COE_MAP_HEIGHT 10

using namespace Coe;

CoePlugin::CoePlugin()
{
}

Tiled::Map *
CoePlugin::read(const QString &fileName)
{
  using namespace Tiled;

  QFile file(fileName);
  mError.clear();
  Map *map = 0;

  if(!file.exists())
    {
      mError = tr("File not found: %1").arg(file.fileName());
      return 0;
    }
  else if(!file.open(QFile::ReadOnly))
    {
      mError = tr("Unable to read file: %1").arg(file.fileName());
      return 0;
    }

  mPath = QFileInfo(file).absolutePath();

  QDataStream stream(&file);

  map = new Map(Map::Orthogonal,
		COE_MAP_WIDTH, COE_MAP_HEIGHT,
		32, 32);

  // Add the two tilesets "tiles" and "objects", based on the files
  // "tiles.png" and "objects.png" respectively
  Tileset *tiles = new Tileset("tiles", 32, 32, 0, 0);
  QString source = makeAbsolute("tiles.png");
  tiles->loadFromImage(source);
  map->addTileset(tiles);

  Tileset *objects = new Tileset("objects", 32, 32, 0, 0);
  source = makeAbsolute("objects.png");
  objects->setTransparentColor(QColor("#ffffff"));
  objects->loadFromImage(source);
  map->addTileset(objects);

  // Add the two layers "tiles" and "objects"
  TileLayer *tilesLayer = new TileLayer("Tiles", 0, 0,
					COE_MAP_WIDTH, COE_MAP_HEIGHT);

  qint8 tileID;

  for(int y = 0;y < COE_MAP_HEIGHT;y++)
    for(int x = 0;x < COE_MAP_WIDTH;x++)
      {
	if(stream.atEnd())
	  {
	    mError = tr("Unexpected end of file");

	    // Cleanup
	    delete tilesLayer;
	    delete objects;
	    delete tiles;
	    delete map;

	    return 0;
	  }

	stream >> tileID;

	Tile *tile = tiles->tileAt(tileID);
	tilesLayer->setTile(x, y, tile);
      }

  map->addLayer(tilesLayer);

  TileLayer *objectsLayer = new TileLayer("Objects", 0, 0,
					  COE_MAP_WIDTH, COE_MAP_HEIGHT);

  qint8 numberOfObjects;

  if(stream.atEnd())
    {
      mError = tr("Unexpected end of file");

      // Cleanup
      delete objects;
      delete tiles;
      delete map;

      return 0;
    }

  stream >> numberOfObjects;

  quint8 pos, obj;

  for(int i = 0;i < numberOfObjects;i++)
    {
      stream >> pos;
      stream >> obj;

      if(i != numberOfObjects - 1 && stream.atEnd())
	{
	  mError = tr("Unexpected end of file");
	  
	  // Cleanup
	  delete objects;
	  delete tiles;
	  delete map;
	  
	  return 0;
	}

      int x = pos >> 4;
      int y = pos & 0x0f;

      Tile *tile = objects->tileAt(obj);
      objectsLayer->setTile(x, y, tile);
    }

  map->addLayer(objectsLayer);

  return map;
}

bool
CoePlugin::write(const Tiled::Map *map, const QString &fileName)
{
  using namespace Tiled;

  // Find layers
  TileLayer *bgLayer = 0;
  TileLayer *objectLayer = 0;

  foreach(Layer *layer, map->layers())
    {
      if(layer->name().compare(QLatin1String("tiles"),
			       Qt::CaseInsensitive) == 0)
	{
	  if(TileLayer *tileLayer = layer->asTileLayer())
	    {
	      if(bgLayer)
		{
		  mError = tr("Multiple background layers found!");
		  return false;
		}
	      bgLayer = tileLayer;
	    }
	}
      else if(layer->name().compare(QLatin1String("objects"),
				    Qt::CaseInsensitive) == 0)
	{
	  if(TileLayer *tileLayer = layer->asTileLayer())
	    {
	      if(objectLayer)
		{
		  mError = tr("Multiple object layers found!");
		  return false;
		}
	      objectLayer = tileLayer;
	    }
	}
    }

  if (!bgLayer) {
    mError = tr("No background layer found!");
    return false;
  }

  if (!objectLayer) {
    mError = tr("No object layer found!");
    return false;
  }

  if(COE_MAP_WIDTH != bgLayer->width()
     || COE_MAP_HEIGHT != bgLayer->height()
     || COE_MAP_WIDTH != objectLayer->width()
     || COE_MAP_HEIGHT != objectLayer->height())
    {
      mError = tr("Bad map dimensions.");
      return false;
    }

  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    mError = tr("Could not open file for writing.");
    return false;
  }

  QDataStream stream(&file);

  // Store background tiles as a simple array of 140 (14x10) bytes
  for(int y = 0;y < COE_MAP_HEIGHT;y++)
    for(int x = 0;x < COE_MAP_WIDTH;x++)
      {
	Tile *tile = bgLayer->tileAt(x, y);

	if(!tile)
	  {
	    mError = tr("Empty tile found in background layer!");
	    return false;
	  }
	else if(tile->tileset()->name().compare(QLatin1String("tiles"),
						Qt::CaseInsensitive) != 0)
	  {
	    mError = tr("Background tile from wrong tileset! "
			"Tile at %1,%2 is from tileset \"%3\".")
	      .arg(x).arg(y).arg(tile->tileset()->name());
	    return false;
	  }

	stream << (qint8)(tile->id());
      }

  // Count number of objects, store this as 1 byte
  int objectCount = 0;
  for(int y = 0;y < COE_MAP_HEIGHT;y++)
    for(int x = 0;x < COE_MAP_WIDTH;x++)
      {
	Tile *tile = objectLayer->tileAt(x, y);
	if(tile)
	  objectCount++;
      }
  stream << (qint8)objectCount;

  // Store each object as two bytes, A and B:
  // Byte A represents the position (A = x << 4 | y).
  // Byte B represents the object type.
  for(int y = 0;y < COE_MAP_HEIGHT;y++)
    for(int x = 0;x < COE_MAP_WIDTH;x++)
      {
	Tile *tile = objectLayer->tileAt(x, y);

	if(tile && tile->tileset()->name().compare(QLatin1String("objects"),
						   Qt::CaseInsensitive) != 0)
	  {
	    mError = tr("Object tile from wrong tileset! "
			"Tile at %1,%2 is from tileset \"%3\".")
	      .arg(x).arg(y).arg(tile->tileset()->name());
	    return false;
	  }

	if(tile)
	  {
	    // Position
	    stream << (qint8)(x << 4 | y);

	    // Object type
	    stream << (qint8)(tile->id());
	  }
      }

  return true;
}

QString CoePlugin::nameFilter() const
{
    return tr("Castle of Elite level file (*.coe)");
}

QString CoePlugin::errorString() const
{
    return mError;
}

bool
CoePlugin::supportsFile(const QString &fileName) const
{
  return fileName.endsWith(QLatin1String(".coe"));
}

QString
CoePlugin::makeAbsolute(const QString &path)
{
    if (QDir::isRelativePath(path))
        return mPath + QLatin1Char('/') + path;
    else
        return path;
}

Q_EXPORT_PLUGIN2(Coe, CoePlugin)
