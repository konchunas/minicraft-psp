#include "FurnitureItem.h"

#include "../Color.h"
#include "../Font.h"
#include "../screen.h"
#include "../level/Level.h"
#include "../entity/ItemEntity.h"
#include "../entity/Entity.h"

FurnitureItem::~FurnitureItem()
{
	// TODO Auto-generated destructor stub
}

FurnitureItem::FurnitureItem(Furniture * furniture):
placed(false)
{
	this->furniture = furniture;
}

int FurnitureItem::getColor()
{
	return furniture->col;
}

int FurnitureItem::getSprite()
{
	return furniture->sprite + 10 * 32;
}

void FurnitureItem::renderIcon(Screen * screen, int x, int y) {
	screen->render(x, y, getSprite(), getColor(), 0);
}

void FurnitureItem::renderInventory(Screen * screen, int x, int y)
{
	screen->render(x, y, getSprite(), getColor(), 0);
	Font::draw(furniture->name, screen, x + 8, y, Color::get(-1, 555, 555, 555));
}

void FurnitureItem::onTake(ItemEntity * itemEntity) {
}

bool FurnitureItem::canAttack() {
	return false;
}

bool FurnitureItem::interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir) {
	if (tile->mayPass(level, xt, yt, furniture))
	{
		furniture->x = xt * 16 + 8;
		furniture->y = yt * 16 + 8;
		level->add(furniture);
		placed = true;
		return true;
	}
	return false;
}

bool FurnitureItem::isDepleted()
{
	return placed;
}

string FurnitureItem::getName()
{
	return furniture->name;
}

ClassType FurnitureItem::classType()
{
	return FURNITURE_ITEM;
}
