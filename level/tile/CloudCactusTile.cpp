#include "../../Color.h"
#include "../Level.h"
#include "../../Random.h"
#include "../../entity/ItemEntity.h"
#include "../../item/ResourceItem.h"
#include "../../item/ToolItem.h"
#include "../../entity/Player.h"
#include "../../particle/TextParticle.h"
#include "../../particle/SmashParticle.h"

#include "CloudCactusTile.h"

CloudCactusTile::CloudCactusTile(int id) : Tile(id)
{
}
CloudCactusTile::~CloudCactusTile()
{
}

void CloudCactusTile::render(Screen * screen, Level * level, int x, int y)
{
	int color = Color::get(444, 111, 333, 555);
	screen->render(x * 16 + 0, y * 16 + 0, 17 + 1 * 32, color, 0);
	screen->render(x * 16 + 8, y * 16 + 0, 18 + 1 * 32, color, 0);
	screen->render(x * 16 + 0, y * 16 + 8, 17 + 2 * 32, color, 0);
	screen->render(x * 16 + 8, y * 16 + 8, 18 + 2 * 32, color, 0);
}

bool CloudCactusTile::mayPass(Level * level, int x, int y, Entity * e) {
		if (e->instanceOf(AIR_WIZARD)) return true;
		return false;
	}

void CloudCactusTile::hurt(Level * level, int x, int y, Mob * source, int dmg, int attackDir)
{
		hurt(level, x, y, 0);
	}

bool CloudCactusTile::interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir)
{
		if (item->instanceOf(TOOL_ITEM)) {
			ToolItem * tool = (ToolItem*) item;
			if (tool->type == ToolType::pickaxe) {
				if (player->payStamina(6 - tool->level)) {
					hurt(level, xt, yt, 1);
					return true;
				}
			}
		}
		return false;
	}

void CloudCactusTile::hurt(Level * level, int x, int y, int dmg) {
		int damage = level->getData(x, y) + 1;
		level->add(new SmashParticle(x * 16 + 8, y * 16 + 8));
		level->add(new TextParticle("" + dmg, x * 16 + 8, y * 16 + 8, Color::get(-1, 500, 500, 500)));
		if (dmg > 0) {
			if (damage >= 10) {
				level->setTile(x, y, Tile::cloud, 0);
			} else {
				level->setData(x, y, damage);
			}
		}
	}

void CloudCactusTile::bumpedInto(Level * level, int x, int y, Entity * entity) {
		if (entity->instanceOf(AIR_WIZARD)) return;
		entity->hurt(this, x, y, 3);
	}

