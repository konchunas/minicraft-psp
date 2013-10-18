/*
 * Player.h
 *
 *  Created on: 16 окт. 2013 г.
 *      Author: user
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Game;
class Item;

#include "Mob.h"
#include "../InputHandler.h"
#include "Inventory.h"

class Player : public Mob {
public:
	Player(Game * game, InputHandler * input);
	virtual ~Player();

	Game * game;
	Inventory * inventory;
	Item * attackItem;
	Item * activeItem;
	int stamina;
	int staminaRecharge;
	int staminaRechargeDelay;
	int score;
	int maxStamina;
	int invulnerableTime;

	void render(Screen * screen);
	void touchItem(ItemEntity * itemEntity);
	bool canSwim();
	bool findStartPos(Level * level);
	bool payStamina(int cost);
	void changeLevel(int dir);
	int getLightRadius();
	void gameWon();
	virtual ClassType classType();

private:
	InputHandler * input;
	int attackTime, attackDir;
	int onStairDelay;

	void tick();
	bool use();
	void attack();
	bool use(int x0, int y0, int x1, int y1);
	bool interact(int x0, int y0, int x1, int y1);
	void hurt(int x0, int y0, int x1, int y1);
	int getAttackDamage(Entity * e);

protected:
	void die();
	void touchedBy(Entity * entity);
	void doHurt(int damage, int attackDir);
};

#endif /* PLAYER_H_ */
