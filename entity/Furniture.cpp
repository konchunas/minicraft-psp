#include "Inventory.h"

#include "Furniture.h"
#include "Player.h"
#include "Mob.h"


Furniture::~Furniture()
{
	// TODO Auto-generated destructor stub
}

Furniture::Furniture(string name):
pushTime(0),
pushDir(-1),
shouldTake(NULL)
{
	this->name = name;
	xr = 3;
	yr = 3;
}

void Furniture::tick()
{
	if (shouldTake != NULL)
	{
		if (shouldTake->activeItem->instanceOf(POWERGLOVE_ITEM))
		{
			remove();
			shouldTake->inventory->add(0, shouldTake->activeItem);
//			shouldTake->activeItem = new FurnitureItem(this);
		}
		shouldTake = NULL;
	}
	//oslDebug("%d",pushDir);
	if (pushDir == 0) move(0, +1);
	if (pushDir == 1) move(0, -1);
	if (pushDir == 2) move(-1, 0);
	if (pushDir == 3) move(+1, 0);
	pushDir = -1;
	if (pushTime > 0) pushTime--;
}

void Furniture::render(Screen * screen)
{
	screen->render(x - 8, y - 8 - 4, sprite * 2 + 8 * 32, col, 0);
	screen->render(x - 0, y - 8 - 4, sprite * 2 + 8 * 32 + 1, col, 0);
	screen->render(x - 8, y - 0 - 4, sprite * 2 + 8 * 32 + 32, col, 0);
	screen->render(x - 0, y - 0 - 4, sprite * 2 + 8 * 32 + 33, col, 0);
}

bool Furniture::blocks(Entity * e)
{
	return true;
}

ClassType Furniture::classType()
{
	return FURNITURE_ENTITY;
}

void Furniture::touchedBy(Entity * entity)
{
	oslDebug("furniture touched by");
	if (entity->instanceOf(PLAYER) && pushTime == 0)
	{
		pushDir = static_cast<Player*>(entity)->dir;
		pushTime = 10;
	}
}

void Furniture::take(Player * player)
{
	shouldTake = player;
}
