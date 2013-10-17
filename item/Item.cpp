#include "../Screen.h"
#include "../entity/Player.h"
#include "../entity/Entity.h"
#include "../entity/ItemEntity.h"
#include "../level/tile/Tile.h"
#include "../level/Level.h"

#include "Item.h"

int Item::getColor()
{
	return 0;
}

int Item::getSprite()
{
	return 0;
}

void Item::onTake(ItemEntity * itemEntity)
{
}

void Item::renderInventory(Screen * screen, int x, int y) {
}

bool Item::interact(Player * player, Entity * entity, int attackDir) {
	return false;
}

void Item::renderIcon(Screen * screen, int x, int y) {
}

bool Item::interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir) {
	return false;
}

bool Item::isDepleted() {
	return false;
}

bool Item::canAttack() {
	return false;
}

int Item::getAttackDamageBonus(Entity * e) {
	return 0;
}

std::string Item::getName()
{
	return "";
}

bool Item::matches(Item * item)
{
	return (type() != UNDEFINED) && (item->type() == type());
}

