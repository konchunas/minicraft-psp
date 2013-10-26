/*
 * Player.cpp
 *
 *  Created on: 16 окт. 2013 г.
 *      Author: user
 */

#include "Player.h"
#include "../Game.h"
#include "../InputHandler_Key.h"
#include "../item/Item.h"
#include "ItemEntity.h"
#include "../menu/InventoryMenu.h"
#include "../item/resource/Resource.h"
#include "../item/FurnitureItem.h"
#include "../entity/Workbench.h"
#include "../entity/Furnace.h" //temporary include
#include "../Color.h"
#include "../item/ToolItem.h"

#include <oslib/oslib.h>

Player::~Player() {
	// TODO Auto-generated destructor stub
}

Player::Player(Game * game, InputHandler * input) :
inventory(new Inventory()),
attackItem(NULL),
activeItem(NULL),
staminaRecharge(0),
staminaRechargeDelay(0),
maxStamina(10),
invulnerableTime(0),
onStairDelay(0),
score(0),
attackTime(0)
{
	this->game = game;
	this->input = input;
	x = 24;
	y = 24;
	stamina = maxStamina;

	//inventory->add(new ResourceItem(Resource::dirt));
	//inventory->add(new ResourceItem(Resource::wood));
	inventory->add(new FurnitureItem(new Workbench()));
	inventory->add(new FurnitureItem(new Furnace()));
	inventory->add(new ToolItem(ToolType::pickaxe,1));
	inventory->add(new ResourceItem(Resource::sand, 30));
	inventory->add(new ResourceItem(Resource::coal, 30));


//	inventory.add(new FurnitureItem(new Workbench()));
//	inventory.add(new PowerGloveItem());
}

void Player::tick() {
	Mob::tick();

	if (invulnerableTime > 0)
		invulnerableTime--;
	Tile * onTile = level->getTile(x >> 4, y >> 4);
	if (onTile == Tile::stairsDown || onTile == Tile::stairsUp)
	{
		//oslDebug("");
		if (onStairDelay == 0)
		{
			changeLevel((onTile == Tile::stairsUp) ? 1 : -1);
			onStairDelay = 10;
			return;
		}
		onStairDelay = 10;
	}
	else
	{
		if (onStairDelay > 0)
			onStairDelay--;
	}

	if (stamina <= 0 && staminaRechargeDelay == 0 && staminaRecharge == 0) {
		staminaRechargeDelay = 40;
	}

	if (staminaRechargeDelay > 0) {
		staminaRechargeDelay--;
	}

	if (staminaRechargeDelay == 0) {
		staminaRecharge++;
		if (isSwimming()) {
			staminaRecharge = 0;
		}
		while (staminaRecharge > 10) {
			staminaRecharge -= 10;
			if (stamina < maxStamina)
				stamina++;
		}
	}

	int xa = 0;
	int ya = 0;
	if (input->up->down) {
		ya--;
	}
	if (input->down->down) {
		ya++;
	}
	if (input->left->down) {
		xa--;
	}
	if (input->right->down) {
		xa++;
	}

	if (isSwimming() && tickTime % 60 == 0) {
		if (stamina > 0) {
			stamina--;
		} else {
			Mob::hurt(this, 1, dir ^ 1);
		}
	}

	if (staminaRechargeDelay % 2 == 0) {
		move(xa, ya);
	}

	if (input->attack->clicked) {
		if (stamina == 0) {

		} else {
			stamina--;
			staminaRecharge = 0;
			attack();
		}
	}
	if (input->menu->clicked) {
		if (!use()) {
			game->setMenu(new InventoryMenu(this));
		}
	}
	if (attackTime > 0)
		attackTime--;

}

bool Player::use() {
	int yo = -2;
	if (dir == 0 && use(x - 8, y + 4 + yo, x + 8, y + 12 + yo))
		return true;
	if (dir == 1 && use(x - 8, y - 12 + yo, x + 8, y - 4 + yo))
		return true;
	if (dir == 3 && use(x + 4, y - 8 + yo, x + 12, y + 8 + yo))
		return true;
	if (dir == 2 && use(x - 12, y - 8 + yo, x - 4, y + 8 + yo))
		return true;

	int xt = x >> 4;
	int yt = (y + yo) >> 4;
	int r = 12;
	if (attackDir == 0)
		yt = (y + r + yo) >> 4;
	if (attackDir == 1)
		yt = (y - r + yo) >> 4;
	if (attackDir == 2)
		xt = (x - r) >> 4;
	if (attackDir == 3)
		xt = (x + r) >> 4;

	if (xt >= 0 && yt >= 0 && xt < level->w && yt < level->h) {
		if (level->getTile(xt, yt)->use(level, xt, yt, this, attackDir))
			return true;
	}

	return false;
}

void Player::attack()
{
	walkDist += 8;
	attackDir = dir;
	attackItem = activeItem;
	bool done = false;

	if (activeItem != NULL) {
		attackTime = 10;
		int yo = -2;
		int range = 12;
		if (dir == 0 && interact(x - 8, y + 4 + yo, x + 8, y + range + yo))
			done = true;
		if (dir == 1 && interact(x - 8, y - range + yo, x + 8, y - 4 + yo))
			done = true;
		if (dir == 3 && interact(x + 4, y - 8 + yo, x + range, y + 8 + yo))
			done = true;
		if (dir == 2 && interact(x - range, y - 8 + yo, x - 4, y + 8 + yo))
			done = true;
		if (done)
			return;

		int xt = x >> 4;
		int yt = (y + yo) >> 4;
		int r = 12;
		if (attackDir == 0)
			yt = (y + r + yo) >> 4;
		if (attackDir == 1)
			yt = (y - r + yo) >> 4;
		if (attackDir == 2)
			xt = (x - r) >> 4;
		if (attackDir == 3)
			xt = (x + r) >> 4;

		if (xt >= 0 && yt >= 0 && xt < level->w && yt < level->h) {
			if (activeItem->interactOn(level->getTile(xt, yt), level, xt, yt,
					this, attackDir)) {
				done = true;
			} else {
				if (level->getTile(xt, yt)->interact(level, xt, yt, this,
						activeItem, attackDir)) {
					done = true;
				}
			}
			if (activeItem->isDepleted()) {
				activeItem = NULL;
			}
		}
	}

	if (done)
		return;

	if (activeItem == NULL || activeItem->canAttack())
	{
		attackTime = 5;
		int yo = -2;
		int range = 20;
		if (dir == 0)
			hurt(x - 8, y + 4 + yo, x + 8, y + range + yo);
		if (dir == 1)
			hurt(x - 8, y - range + yo, x + 8, y - 4 + yo);
		if (dir == 3)
			hurt(x + 4, y - 8 + yo, x + range, y + 8 + yo);
		if (dir == 2)
			hurt(x - range, y - 8 + yo, x - 4, y + 8 + yo);

		int xt = x >> 4;
		int yt = (y + yo) >> 4;
		int r = 12;
		if (attackDir == 0)
			yt = (y + r + yo) >> 4;
		if (attackDir == 1)
			yt = (y - r + yo) >> 4;
		if (attackDir == 2)
			xt = (x - r) >> 4;
		if (attackDir == 3)
			xt = (x + r) >> 4;

		if (xt >= 0 && yt >= 0 && xt < level->w && yt < level->h) {
			level->getTile(xt, yt)->hurt(level, xt, yt, this,
					random->nextInt(3) + 1, attackDir);
		}
	}
}

bool Player::use(int x0, int y0, int x1, int y1) {
	list<Entity*> entities = level->getEntities(x0, y0, x1, y1);
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		Entity * e = *it;
		if (e != this)
			if (e->use(this, attackDir))
				return true;
	}
	return false;
}

bool Player::interact(int x0, int y0, int x1, int y1) {
	list<Entity*> entities = level->getEntities(x0, y0, x1, y1);
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end();
			it++) {
		Entity * e = *it;
		if (e != this)
			if (e->interact(this, activeItem, attackDir))
				return true;
	}
	return false;
}

void Player::hurt(int x0, int y0, int x1, int y1) {
	list<Entity*> entities = level->getEntities(x0, y0, x1, y1);
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end();
			it++) {
		Entity * e = *it;
		if (e != this)
			e->hurt(this, getAttackDamage(e), attackDir);
	}
}

int Player::getAttackDamage(Entity * e) {
	int dmg = random->nextInt(3) + 1;
	if (attackItem != NULL) {
		dmg += attackItem->getAttackDamageBonus(e);
	}
	return dmg;
}

void Player::render(Screen * screen) {
	int xt = 0;
	int yt = 14;

	int flip1 = (walkDist >> 3) & 1;
	int flip2 = (walkDist >> 3) & 1;

	if (dir == 1) {
		xt += 2;
	}
	if (dir > 1) {
		flip1 = 0;
		flip2 = ((walkDist >> 4) & 1);
		if (dir == 2) {
			flip1 = 1;
		}
		xt += 4 + ((walkDist >> 3) & 1) * 2;
	}

	int xo = x - 8;
	int yo = y - 11;
	if (isSwimming())
	{
		yo += 4;
		int waterColor = Color::get(-1, -1, 115, 335);
		if (tickTime / 8 % 2 == 0) {
			waterColor = Color::get(-1, 335, 5, 115);
		}
		screen->render(xo + 0, yo + 3, 5 + 13 * 32, waterColor, 0);
		screen->render(xo + 8, yo + 3, 5 + 13 * 32, waterColor, 1);
	}

	if (attackTime > 0 && attackDir == 1) {
		screen->render(xo + 0, yo - 4, 6 + 13 * 32,
				Color::get(-1, 555, 555, 555), 0);
		screen->render(xo + 8, yo - 4, 6 + 13 * 32,
				Color::get(-1, 555, 555, 555), 1);
		if (attackItem != NULL)
		{
			attackItem->renderIcon(screen, xo + 4, yo - 4);
		}
	}
	int col = Color::get(-1, 100, 220, 532);
	if (hurtTime > 0) {
		col = Color::get(-1, 555, 555, 555);
	}

	if (activeItem && activeItem->instanceOf(FURNITURE_ITEM))
	{
		yt += 2;
	}
	screen->render(xo + 8 * flip1, yo + 0, xt + yt * 32, col, flip1);
	screen->render(xo + 8 - 8 * flip1, yo + 0, xt + 1 + yt * 32, col, flip1);
	if (!isSwimming()) {
		screen->render(xo + 8 * flip2, yo + 8, xt + (yt + 1) * 32, col, flip2);
		screen->render(xo + 8 - 8 * flip2, yo + 8, xt + 1 + (yt + 1) * 32, col,
				flip2);
	}

	if (attackTime > 0 && attackDir == 2) {
		screen->render(xo - 4, yo, 7 + 13 * 32, Color::get(-1, 555, 555, 555),
				1);
		screen->render(xo - 4, yo + 8, 7 + 13 * 32,
				Color::get(-1, 555, 555, 555), 3);
		if (attackItem != NULL)
		{
			attackItem->renderIcon(screen, xo - 4, yo + 4);
		}
	}
	if (attackTime > 0 && attackDir == 3) {
		screen->render(xo + 8 + 4, yo, 7 + 13 * 32,
				Color::get(-1, 555, 555, 555), 0);
		screen->render(xo + 8 + 4, yo + 8, 7 + 13 * 32,
				Color::get(-1, 555, 555, 555), 2);
		if (attackItem != NULL) {
			attackItem->renderIcon(screen, xo + 8 + 4, yo + 4);
		}
	}
	if (attackTime > 0 && attackDir == 0) {
		screen->render(xo + 0, yo + 8 + 4, 6 + 13 * 32,
				Color::get(-1, 555, 555, 555), 2);
		screen->render(xo + 8, yo + 8 + 4, 6 + 13 * 32,
				Color::get(-1, 555, 555, 555), 3);
		if (attackItem != NULL) {
			attackItem->renderIcon(screen, xo + 4, yo + 8 + 4);
		}
	}
	if (activeItem!=NULL)
		if (activeItem->instanceOf(FURNITURE_ITEM))
		{
			Furniture * furniture = static_cast<FurnitureItem*>(activeItem)->furniture;
			furniture->x = x;
			furniture->y = yo;
			furniture->render(screen);
		}
}

void Player::touchItem(ItemEntity * itemEntity) {
	itemEntity->take(this);
	inventory->add(itemEntity->item);
}

bool Player::canSwim()
{
	return true;
}

bool Player::findStartPos(Level * level) {
	while (true)
	{
		int x = random->nextInt(level->w);
		int y = random->nextInt(level->h);
		if (level->getTile(x, y) == Tile::tiles[0]) {
			this->x = x * 16 + 8;
			this->y = y * 16 + 8;
			return true;
		}
	}
}

bool Player::payStamina(int cost) {
	if (cost > stamina)
		return false;
	stamina -= cost;
	return true;
}

void Player::changeLevel(int dir)
{
	game->scheduleLevelChange(dir);
}

int Player::getLightRadius()
{
	int r = 2;
	if (activeItem != NULL)
	{
		if (activeItem->instanceOf(FURNITURE_ITEM))
		{
			Furniture * furniture = static_cast<FurnitureItem*>(activeItem)->furniture;
			int rr = furniture->getLightRadius();
			if (rr > r) r = rr;
		}
	}
	return r;
}

void Player::die()
{
	Mob::die();
	//Sound.playerDeath.play();
}

void Player::touchedBy(Entity * entity) {
	//no rtti no dynamic_cast
	if (!entity->instanceOf(PLAYER))
		entity->touchedBy(this);
}

void Player::doHurt(int damage, int attackDir) {
	if (hurtTime > 0 || invulnerableTime > 0)
		return;

	//Sound.playerHurt.play();
	//level->add(new TextParticle("" + damage, x, y, Color::get(-1, 504, 504, 504)));
	health -= damage;
	if (attackDir == 0)
		yKnockback = +6;
	if (attackDir == 1)
		yKnockback = -6;
	if (attackDir == 2)
		xKnockback = -6;
	if (attackDir == 3)
		xKnockback = +6;
	hurtTime = 10;
	invulnerableTime = 30;
}

void Player::gameWon() {
	//level->player.invulnerableTime = 60 * 5;
	//game.won();
}

ClassType Player::classType() {
	return PLAYER;
}
