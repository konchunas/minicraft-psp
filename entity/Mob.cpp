/*
 * Mob.cpp
 *
 *  Created on: 16 окт. 2013 г.
 *      Author: user
 */

#include "Mob.h"
#include "../level/Level.h"
#include "../particle/TextParticle.h"
#include "../Color.h"
#include "Player.h"
#include "../Sound.h"

Mob::~Mob()
{
	// TODO Auto-generated destructor stub
}

Mob::Mob() :
xKnockback(0),
yKnockback(0)
{
	x = y = 8;
	xr = 4;
	yr = 3;
	//public
	hurtTime = 0;
	maxHealth = 10;
	health = maxHealth;
	swimTimer = 0;
	tickTime = 0;
	//protected
	walkDist = 0;
	dir = 0;
}

void Mob::tick()
{
	tickTime++;
	if (level->getTile(x >> 4, y >> 4) == Tile::lava)
	{
		hurt(this, 4, dir ^ 1);
	}

	if (health <= 0) {
		die();
	}
	if (hurtTime > 0) hurtTime--;
}

void Mob::die()
{
	remove();
}

bool Mob::move(int xa, int ya)
{
	if (isSwimming()) {
		if (swimTimer++ % 2 == 0) return true;
	}

	if (xKnockback < 0) {
		move2(-1, 0);
		xKnockback++;
	}
	if (xKnockback > 0) {
		move2(1, 0);
		xKnockback--;
	}
	if (yKnockback < 0) {
		move2(0, -1);
		yKnockback++;
	}
	if (yKnockback > 0) {
		move2(0, 1);
		yKnockback--;
	}

	if (hurtTime > 0) return true;
	if (xa != 0 || ya != 0) {
		walkDist++;
		if (xa < 0) dir = 2;
		if (xa > 0) dir = 3;
		if (ya < 0) dir = 1;
		if (ya > 0) dir = 0;
	}
	return Entity::move(xa, ya);
}

bool Mob::isSwimming()
{
	Tile * tile = level->getTile(x >> 4, y >> 4);
	return tile == Tile::water || tile == Tile::lava;
}

bool Mob::blocks(Entity * e) {
	return e->isBlockableBy(this);
}

void Mob::hurt(Mob * mob, int damage, int attackDir)
{
	doHurt(damage, attackDir);
}

void Mob::hurt(Tile * tile, int x, int y, int damage)
{
	int attackDir = dir ^ 1;
	doHurt(damage, attackDir);
}

void Mob::heal(int heal) {
	if (hurtTime > 0) return;

	level->add(new TextParticle(heal, x, y, Color::get(-1, 50, 50, 50)));
	health += heal;
	if (health > maxHealth) health = maxHealth;
}

void Mob::doHurt(int damage, int attackDir) {
	if (hurtTime > 0) return;

	if (level->player != NULL) {
		int xd = level->player->x - x;
		int yd = level->player->y - y;
		if (xd * xd + yd * yd < 80 * 80) {
			Sound::monsterHurt->play();
		}
	}
	level->add(new TextParticle(damage, x, y, Color::get(-1, 500, 500, 500)));
	health -= damage;
	if (attackDir == 0) yKnockback = +6;
	if (attackDir == 1) yKnockback = -6;
	if (attackDir == 2) xKnockback = -6;
	if (attackDir == 3) xKnockback = +6;
	hurtTime = 10;
}

bool Mob::findStartPos(Level * level)
{
	int x = random->nextInt(level->w);
	int y = random->nextInt(level->h);
	int xx = x * 16 + 8;
	int yy = y * 16 + 8;
	if (level->player != NULL)
	{
		int xd = level->player->x - xx;
		int yd = level->player->y - yy;
		if (xd * xd + yd * yd < 80 * 80)
		{
			return false;
		}
	}

	int r = level->monsterDensity * 16;
	if (!level->isRegionEmpty(xx - r, yy - r, xx + r, yy + r))
	{
		return false;
	}

	if (level->getTile(x, y)->mayPass(level, x, y, this))
	{
		this->x = xx;
		this->y = yy;
		return true;
	}

	return false;
}

ClassType Mob::classType()
{
	return MOB;
}
