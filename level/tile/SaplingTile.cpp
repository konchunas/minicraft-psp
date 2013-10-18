#include "SaplingTile.h"

#include "../../Color.h"
#include "../Level.h"
#include "../../Random.h"
#include "../../entity/ItemEntity.h"
#include "../../item/ResourceItem.h"

SaplingTile::SaplingTile(int id, Tile * onType, Tile * growsTo)
:Tile(id)
{
	this->onType = onType;
	this->growsTo = growsTo;
	connectsToSand = onType->connectsToSand;
	connectsToGrass = onType->connectsToGrass;
	connectsToWater = onType->connectsToWater;
	connectsToLava = onType->connectsToLava;
}
SaplingTile::~SaplingTile() {
}

void SaplingTile::render(Screen * screen, Level * level, int x, int y)
{
	onType->render(screen, level, x, y);
	int col = Color::get(10, 40, 50, -1);
	screen->render(x * 16 + 4, y * 16 + 4, 11 + 3 * 32, col, 0);
}

void SaplingTile::tick(Level * level, int x, int y)
{
	int age = level->getData(x, y) + 1;
	if (age > 100) {
		level->setTile(x, y, growsTo, 0);
	} else {
		level->setData(x, y, age);
	}
}

void SaplingTile::hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir)
{
	level->setTile(x, y, onType, 0);
}
