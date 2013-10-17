#include "CactusTile.h"

#include "../../Color.h"
#include "../Level.h"
#include "../../Random.h"


CactusTile::CactusTile(int id) : Tile(id)
{
	connectsToSand = true;
}
CactusTile::~CactusTile() {
	}

void CactusTile::render(Screen * screen, Level * level, int x, int y)
{
	int col = Color::get(20, 40, 50, level->sandColor);
	screen->render(x * 16 + 0, y * 16 + 0, 8 + 2 * 32, col, 0);
	screen->render(x * 16 + 8, y * 16 + 0, 9 + 2 * 32, col, 0);
	screen->render(x * 16 + 0, y * 16 + 8, 8 + 3 * 32, col, 0);
	screen->render(x * 16 + 8, y * 16 + 8, 9 + 3 * 32, col, 0);
}

bool CactusTile::mayPass(Level * level, int x, int y, Entity * e)
{
	return false;
}

void CactusTile::hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir)
{
	int damage = level->getData(x, y) + dmg;
	//level->add(new SmashParticle(x * 16 + 8, y * 16 + 8));
	//level->add(new TextParticle("" + dmg, x * 16 + 8, y * 16 + 8, Color::get(-1, 500, 500, 500)));
	if (damage >= 10) {
		int count = random->nextInt(2) + 1;
		for (int i = 0; i < count; i++) {
			//level->add(new ItemEntity(new ResourceItem(Resource::cactusFlower), x * 16 + random->nextInt(10) + 3, y * 16 + random->nextInt(10) + 3));
		}
		level->setTile(x, y, Tile::sand, 0);
	} else {
		level->setData(x, y, damage);
	}
}

void CactusTile::bumpedInto(Level * level, int x, int y, Entity * entity)
{
	entity->hurt(this, x, y, 1);
}

void CactusTile::tick(Level * level, int xt, int yt)
{
	int damage = level->getData(xt, yt);
	if (damage > 0) level->setData(xt, yt, damage - 1);
}
