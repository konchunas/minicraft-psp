#ifndef POWERGLOVEITEM_H_
#define POWERGLOVEITEM_H_

#include "Item.h"

class Screen;
class Player;
class Entity;

class PowerGloveItem : public Item {
public:
	PowerGloveItem();
	virtual ~PowerGloveItem();

	int getColor();
	int getSprite();
	void renderIcon(Screen * screen, int x, int y);
	void renderInventory(Screen * screen, int x, int y);
	string getName();
	bool interact(Player * player, Entity * entity, int attackDir);

};

#endif /* POWERGLOVEITEM_H_ */
