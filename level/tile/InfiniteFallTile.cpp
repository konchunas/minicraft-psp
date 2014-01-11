#include "../../Color.h"
#include "../Level.h"
#include "../../Random.h"
#include "../../item/ResourceItem.h"

#include "InfiniteFallTile.h"

InfiniteFallTile::~InfiniteFallTile() {
	// TODO Auto-generated destructor stub
}

InfiniteFallTile::InfiniteFallTile(int id) : Tile(id)
{
}

void InfiniteFallTile::render(Screen * screen, Level * level, int x, int y)
{
}

void InfiniteFallTile::tick(Level * level, int xt, int yt)
{
}

bool InfiniteFallTile::mayPass(Level * level, int x, int y, Entity * e)
{
	if (e->instanceOf(AIR_WIZARD) || e->instanceOf(PLAYER)) return true;
	return false;
}
