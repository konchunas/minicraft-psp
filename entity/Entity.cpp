/*
 * Entity.cpp
 *
 *  Created on: 16 окт. 2013 г.
 *      Author: user
 */

#include "Entity.h"
#include "Mob.h"
#include "Player.h"
#include "ItemEntity.h"
#include "../item/Item.h"
#include "../Random.h"
#include "../level/Level.h"
#include <list>

using namespace std;

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

Entity::Entity():
xr(6),
yr(6)
{

}

void Entity::render(Screen * screen) {
}

void Entity::tick() {
}

void Entity::remove() {
	removed = true;
}

void Entity::init(Level * level) {
	this->level = level;
}

bool Entity::intersects(int x0, int y0, int x1, int y1) {
	return !(x + xr < x0 || y + yr < y0 || x - xr > x1 || y - yr > y1);
}

bool Entity::blocks(Entity * e) {
	return false;
}

void Entity::hurt(Mob * mob, int dmg, int attackDir)
{
}

void Entity::hurt(Tile * tile, int x, int y, int dmg) {
}

bool Entity::move(int xa, int ya) {
	if (xa != 0 || ya != 0) {
		bool stopped = true;
		if (xa != 0 && move2(xa, 0)) stopped = false;
		if (ya != 0 && move2(0, ya)) stopped = false;
		if (!stopped) {
			int xt = x >> 4;
			int yt = y >> 4;
			level->getTile(xt, yt)->steppedOn(level, xt, yt, this);
		}
		return !stopped;
	}
	return true;
}

bool Entity::move2(int xa, int ya) {
	if (xa != 0 && ya != 0) //throw new IllegalArgumentException("Move2 can only move along one axis at a time!");
		return false;

	int xto0 = ((x) - xr) >> 4;
	int yto0 = ((y) - yr) >> 4;
	int xto1 = ((x) + xr) >> 4;
	int yto1 = ((y) + yr) >> 4;

	int xt0 = ((x + xa) - xr) >> 4;
	int yt0 = ((y + ya) - yr) >> 4;
	int xt1 = ((x + xa) + xr) >> 4;
	int yt1 = ((y + ya) + yr) >> 4;
	bool blocked = false;
	for (int yt = yt0; yt <= yt1; yt++)
		for (int xt = xt0; xt <= xt1; xt++) {
			if (xt >= xto0 && xt <= xto1 && yt >= yto0 && yt <= yto1) continue;
			level->getTile(xt, yt)->bumpedInto(level, xt, yt, this);
			if (!level->getTile(xt, yt)->mayPass(level, xt, yt, this)) {
				blocked = true;
				return false;
			}
		}
	if (blocked) return false;

	list<Entity*> wasInside = level->getEntities(x - xr, y - yr, x + xr, y + yr);
	list<Entity*> isInside = level->getEntities(x + xa - xr, y + ya - yr, x + xa + xr, y + ya + yr);
	for (list<Entity*>::iterator it = isInside.begin(); it != isInside.end(); it++ )
	{
		Entity * e = *it;
		if (e == this) continue;

		e->touchedBy(this);
	}
	//isInside.removeAll(wasInside);
	for (list<Entity*>::iterator it = isInside.begin(); it != isInside.end(); it++ )
	{
		Entity * e = *it;
		if (e == this) continue;

		if (e->blocks(this)) {
			return false;
		}
	}

	x += xa;
	y += ya;
	return true;
}

void Entity::touchedBy(Entity * entity)
{
}

bool Entity::isBlockableBy(Mob * mob)
{
	return true;
}

void Entity::touchItem(ItemEntity * itemEntity)
{
}

bool Entity::canSwim()
{
	return false;
}

bool Entity::interact(Player * player, Item * item, int attackDir)
{
	return item->interact(player, this, attackDir);
}

bool Entity::use(Player * player, int attackDir)
{
	return false;
}

int Entity::getLightRadius() {
	return 0;
}
