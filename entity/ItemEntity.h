/*
 * ItemEntity.h
 *
 *  Created on: 17 окт. 2013 г.
 *      Author: user
 */

#ifndef ITEMENTITY_H_
#define ITEMENTITY_H_

class Item;
class Mob;
class Player;
class Screen;

#include "Entity.h"

class ItemEntity : public Entity {
public:
	ItemEntity(Item * item, int x, int y);
	virtual ~ItemEntity();

	int hurtTime;
	double xa, ya, za;
	double xx, yy, zz;
	Item * item;

	void tick();
	bool isBlockableBy(Mob * mob);
	void render(Screen * screen);
	void touchedBy(Entity * entity);
	void take(Player * player);

private:
	int time;
	int lifeTime;

protected:
	int walkDist;
	int dir;
	int xKnockback, yKnockback;
};

#endif /* ITEMENTITY_H_ */
