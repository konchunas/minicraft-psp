#include "ToolItem.h"

#include "../Color.h"
#include "../Font.h"
#include "../Screen.h"
#include "../entity/ItemEntity.h"
#include "../entity/Entity.h"

#define MAX_LEVEL 5//public static final int MAX_LEVEL = 5;

const string ToolItem::LEVEL_NAMES[] = {
"Wood", "Rock", "Iron", "Gold", "Gem"
};

const int ToolItem::LEVEL_COLORS[] = {//
		Color::get(-1, 100, 321, 431),//
		Color::get(-1, 100, 321, 111),//
		Color::get(-1, 100, 321, 555),//
		Color::get(-1, 100, 321, 550),//
		Color::get(-1, 100, 321, 055),//
};

ToolItem::~ToolItem() {
	// TODO Auto-generated destructor stub
}

ToolItem::ToolItem(ToolType * type, int level)
:random(new Random()),
level(0)
{
	this->type = type;
	this->level = level;
}

int ToolItem::getColor()
{
	return LEVEL_COLORS[level];
}

int ToolItem::getSprite()
{
	return type->sprite + 5 * 32;
}

void ToolItem::renderIcon(Screen * screen, int x, int y)
{
	screen->render(x, y, getSprite(), getColor(), 0);
}

void ToolItem::renderInventory(Screen * screen, int x, int y) {
	screen->render(x, y, getSprite(), getColor(), 0);
	Font::draw(getName(), screen, x + 8, y, Color::get(-1, 555, 555, 555));
}

string ToolItem::getName()
{
	return LEVEL_NAMES[level] + " " + type->name;
}

void ToolItem::onTake(ItemEntity * itemEntity) {
}

bool ToolItem::canAttack()
{
	return true;
}

int ToolItem::getAttackDamageBonus(Entity * e)
{
	if (type == ToolType::axe)
	{
		return (level + 1) * 2 + random->nextInt(4);
	}
	if (type == ToolType::sword)
	{
		return (level + 1) * 3 + random->nextInt(2 + level * level * 2);
	}
	return 1;
}

bool ToolItem::matches(Item * item)
{
	if (item->instanceOf(TOOL_ITEM))
	{
		ToolItem * other = (ToolItem*) item;
		if (other->type != type) return false;
		if (other->level != level) return false;
		return true;
	}
	return false;
}

ClassType ToolItem::classType()
{
	return TOOL_ITEM;
}
