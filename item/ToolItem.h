/*
 * ToolItem.h
 *
 *  Created on: 18 окт. 2013 г.
 *      Author: user
 */

#ifndef TOOLITEM_H_
#define TOOLITEM_H_

#include <string>
#include "ToolType.h"
#include "Item.h"
#include "../Random.h"

class Screen;
class ItemEntity;
class Entity;

using namespace std;

class ToolItem : public Item {
public:
	ToolItem(ToolType * type, int level);
	virtual ~ToolItem();
	ToolType * type;	//hand to rename it from
	int level;

	static const string LEVEL_NAMES[];
	static const int LEVEL_COLORS[];

	int getColor();
	int getSprite();
	void renderIcon(Screen * screen, int x, int y);
	void renderInventory(Screen * screen, int x, int y);
	string getName();
	void onTake(ItemEntity * itemEntity);
	bool canAttack();
	int getAttackDamageBonus(Entity * e);
	bool matches(Item * item);
	ClassType classType();


private:
	Random * random;
};

#endif /* TOOLITEM_H_ */
