#include "../Font.h"
#include "../Color.h"
#include "../entity/Player.h"
#include "../entity/Furniture.h"

#include "PowerGloveItem.h"

PowerGloveItem::PowerGloveItem() {
	// TODO Auto-generated constructor stub

}

PowerGloveItem::~PowerGloveItem() {
	// TODO Auto-generated destructor stub
}

int PowerGloveItem::getColor() {
	return Color::get(-1, 100, 320, 430);
}

int PowerGloveItem::getSprite() {
	return 7 + 4 * 32;
}

void PowerGloveItem::renderIcon(Screen * screen, int x, int y) {
	screen->render(x, y, getSprite(), getColor(), 0);
}

void PowerGloveItem::renderInventory(Screen * screen, int x, int y) {
	screen->render(x, y, getSprite(), getColor(), 0);
	Font::draw(getName(), screen, x + 8, y, Color::get(-1, 555, 555, 555));
}

string PowerGloveItem::getName() {
	return "Pow glove";
}

bool PowerGloveItem::interact(Player * player, Entity * entity, int attackDir) {
	if (entity->instanceOf(FURNITURE_ITEM))
	{
		Furniture * f = (Furniture*) entity;
		f->take(player);
		return true;
	}
	return false;
}

