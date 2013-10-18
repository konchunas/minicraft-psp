#include <stdarg.h>

#include "PlantableResource.h"

PlantableResource::~PlantableResource()
{
	// TODO Auto-generated destructor stub
}

PlantableResource::PlantableResource(string name, int sprite, int color, Tile * targetTile, int numOfSourceTiles, ...)
:Resource(name, sprite, color)
{
	this->targetTile = targetTile;

	va_list arguments;
	va_start (arguments, numOfSourceTiles);
	for (int i = 0; i < numOfSourceTiles; ++i)
	{
		sourceTiles.push_back(va_arg(arguments,Tile*));
	}
	//this(name, sprite, color, targetTile, Arrays.asList(sourceTiles1));
}

//PlantableResource::PlantableResource(string name, int sprite, int color, Tile * targetTile, list<Tile *> sourceTiles)
//:Resource(name, sprite, color)
//{
//	this->sourceTiles = sourceTiles;
//	this->targetTile = targetTile;
//}

bool PlantableResource::interactOn(Tile *  tile, Level * level, int xt, int yt, Player * player, int attackDir)
{
	for (list<Tile*>::iterator it = sourceTiles.begin(); it != sourceTiles.end(); it++ )
	{
		Tile * e = *it;
		if (e == tile) 	//maybe it will work
		{
			level->setTile(xt, yt, targetTile, 0);
			return true;
		}
	}
	return false;
}

