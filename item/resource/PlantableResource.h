#ifndef PLANTABLERESOURCE_H_
#define PLANTABLERESOURCE_H_

#include <list>

#include "../../level/tile/Tile.h"
#include "../../level/Level.h"
#include "../../entity/Player.h"
#include "Resource.h"

class Tile;

using namespace std;

class PlantableResource : public Resource {
public:
	PlantableResource(string name, int sprite, int color,
										Tile * targetTile, int numOfSourceTiles, ...);
	//PlantableResource(string name, int sprite, int color, Tile * targetTile, list<Tile *> sourceTiles);
	virtual ~PlantableResource();
	bool interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir);

private:
	list<Tile*> sourceTiles;
	Tile* targetTile;
};

#endif /* PLANTABLERESOURCE_H_ */
