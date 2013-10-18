#include "FlowerTile.h"

#include "../../Color.h"
#include "../Level.h"
#include "../../Random.h"
#include "../../entity/ItemEntity.h"
#include "../../item/ResourceItem.h"

FlowerTile::FlowerTile(int id) :
GrassTile(id)
{
	connectsToGrass = true;
}

FlowerTile::~FlowerTile()
{
}

void FlowerTile::render(Screen * screen, Level * level, int x, int y)
{
	GrassTile::render(screen, level, x, y);

	int data = level->getData(x, y);
	int shape = (data / 16) % 2;
	int flowerCol = Color::get(10, level->grassColor, 555, 440);

	if (shape == 0) screen->render(x * 16 + 0, y * 16 + 0, 1 + 1 * 32, flowerCol, 0);
	if (shape == 1) screen->render(x * 16 + 8, y * 16 + 0, 1 + 1 * 32, flowerCol, 0);
	if (shape == 1) screen->render(x * 16 + 0, y * 16 + 8, 1 + 1 * 32, flowerCol, 0);
	if (shape == 0) screen->render(x * 16 + 8, y * 16 + 8, 1 + 1 * 32, flowerCol, 0);
}

bool FlowerTile::interact(Level * level, int x, int y, Player * player, Item * item, int attackDir)
{
//	if (item->instanceOf(TOOL_ITEM)) {
//		ToolItem tool = (ToolItem) item;
//		if (tool->type == ToolType::shovel) {
//			if (player->payStamina(4 - tool->level)) {
//				level->add(new ItemEntity(new ResourceItem(Resource::flower), x * 16 + random->nextInt(10) + 3, y * 16 + random->nextInt(10) + 3));
//				level->add(new ItemEntity(new ResourceItem(Resource::flower), x * 16 + random->nextInt(10) + 3, y * 16 + random->nextInt(10) + 3));
//				level->setTile(x, y, Tile::grass, 0);
//				return true;
//			}
//		}
//	}
	return false;
}

void FlowerTile::hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir)
{
	int count = random->nextInt(2) + 1;
	for (int i = 0; i < count; i++)
	{
		level->add(new ItemEntity(new ResourceItem(Resource::flower), x * 16 + random->nextInt(10) + 3, y * 16 + random->nextInt(10) + 3));
	}
	level->setTile(x, y, Tile::grass, 0);
}
