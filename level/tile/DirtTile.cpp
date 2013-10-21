#include "DirtTile.h"

#include "../../Color.h"
#include "../Level.h"
#include "../../Random.h"
#include "../../entity/Player.h"
#include "../../entity/ItemEntity.h"
#include "../../item/ResourceItem.h"
#include "../../item/ToolItem.h"

DirtTile::DirtTile(int id):Tile(id)
{

}
DirtTile::~DirtTile() {
}

void DirtTile::render(Screen * screen, Level * level, int x, int y)
{
	int col = Color::get(level->dirtColor, level->dirtColor, level->dirtColor - 111, level->dirtColor - 111);
	screen->render(x * 16 + 0, y * 16 + 0, 0, col, 0);
	screen->render(x * 16 + 8, y * 16 + 0, 1, col, 0);
	screen->render(x * 16 + 0, y * 16 + 8, 2, col, 0);
	screen->render(x * 16 + 8, y * 16 + 8, 3, col, 0);
}

bool DirtTile::interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir)
{
	if (item->instanceOf(TOOL_ITEM)) {
		ToolItem * tool = (ToolItem*) item;
		if (tool->type == ToolType::shovel) {
			if (player->payStamina(4 - tool->level)) {
				level->setTile(xt, yt, Tile::hole, 0);
				level->add(new ItemEntity(new ResourceItem(Resource::dirt), xt * 16 + random->nextInt(10) + 3, yt * 16 + random->nextInt(10) + 3));
				//Sound::monsterHurt->play();
				return true;
			}
		}
		if (tool->type == ToolType::hoe) {
			if (player->payStamina(4 - tool->level)) {
				level->setTile(xt, yt, Tile::farmland, 0);
				//Sound::monsterHurt->play();
				return true;
			}
		}
	}
	return false;
}
