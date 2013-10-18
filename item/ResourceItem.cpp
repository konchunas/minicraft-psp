#include "ResourceItem.h"

#include "../Font.h"
#include "../Color.h"
#include "../entity/Player.h"

ResourceItem::~ResourceItem() {
	// TODO Auto-generated destructor stub
}

ResourceItem::ResourceItem(Resource * resource) :
count(1)
{
	this->resource = resource;
}

ResourceItem::ResourceItem(Resource * resource, int count)
{
	this->resource = resource;
	this->count = count;
}

int ResourceItem::getColor()
{
	return resource->color;
}

int ResourceItem::getSprite() {
	return resource->sprite;
}

void ResourceItem::renderIcon(Screen * screen, int x, int y)
{
	screen->render(x, y, resource->sprite, resource->color, 0);
}

void ResourceItem::renderInventory(Screen * screen, int x, int y) {
	screen->render(x, y, resource->sprite, resource->color, 0);
	Font::draw(resource->name, screen, x + 32, y, Color::get(-1, 555, 555, 555));
	int cc = count;
	if (cc > 999) cc = 999;
	Font::draw("" + cc, screen, x + 8, y, Color::get(-1, 444, 444, 444));
}

string ResourceItem::getName()
{
	return resource->name;
}

void ResourceItem::onTake(ItemEntity * itemEntity) {
}

bool ResourceItem::interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir) {
	if (resource->interactOn(tile, level, xt, yt, player, attackDir)) {
		count--;
		return true;
	}
	return false;
}

bool ResourceItem::isDepleted() {
	return count <= 0;
}

ClassType ResourceItem::classType()
{
	return RESOURCE_ITEM;
}
