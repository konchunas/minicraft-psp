#ifndef FURNITUREITEM_H_
#define FURNITUREITEM_H_

#include <string>
#include "Item.h"
//#include "../Random.h"
#include "../entity/Furniture.h"

class FurnitureItem : public Item {
public:
	FurnitureItem(Furniture * furniture);
	virtual ~FurnitureItem();
	Furniture * furniture;
	bool placed;

	int getColor();
	int getSprite();
	void renderIcon(Screen * screen, int x, int y);
	void renderInventory(Screen * screen, int x, int y);
	void onTake(ItemEntity * itemEntity);
	bool canAttack();
	bool interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir);
	bool isDepleted();
	string getName();
	ClassType classType();
};

#endif /* FURNITUREITEM_H_ */
