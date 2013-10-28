#include "Entity.h"
#include "Mob.h"
#include "Player.h"
#include "../item/Item.h"
#include "../Color.h"
#include "../Sound.h"

#include "ItemEntity.h"

ItemEntity::ItemEntity(Item * item, int x, int y) :
hurtTime(0),
time(0),
walkDist(0),
dir(0)
{
	this->item = item;
	xx = this->x = x;
	yy = this->y = y;
	xr = 3;
	yr = 3;

	zz = 2;
	xa = random->nextGaussian() * 0.3;
	ya = random->nextGaussian() * 0.2;
	za = random->nextFloat() * 0.7 + 1;

	lifeTime = 60 * 10 + random->nextInt(60);
}

ItemEntity::~ItemEntity() {
	// TODO Auto-generated destructor stub
}
void ItemEntity::tick() {
	time++;
	if (time >= lifeTime) {
		remove();
		return;
	}
	xx += xa;
	yy += ya;
	zz += za;
	if (zz < 0) {
		zz = 0;
		za *= -0.5;
		xa *= 0.6;
		ya *= 0.6;
	}
	za -= 0.15;
	int ox = x;
	int oy = y;
	int nx = (int) xx;
	int ny = (int) yy;
	int expectedx = nx - x;
	int expectedy = ny - y;
	move(nx - x, ny - y);
	int gotx = x - ox;
	int goty = y - oy;
	xx += gotx - expectedx;
	yy += goty - expectedy;

	if (hurtTime > 0)
		hurtTime--;
}

bool ItemEntity::isBlockableBy(Mob * mob)
{
	return false;
}

void ItemEntity::render(Screen * screen)
{
	if (time >= lifeTime - 6 * 20) {
		if (time / 6 % 2 == 0) return;
	}
	screen->render(x - 4, y - 4, item->getSprite(), Color::get(-1, 0, 0, 0), 0);
	screen->render(x - 4, y - 4 - (int) (zz), item->getSprite(), item->getColor(), 0);
}

void ItemEntity::touchedBy(Entity * entity)
{
	if (time > 30) entity->touchItem(this);
}

void ItemEntity::take(Player * player)
{
	Sound::pickup->play();
	player->score++;
	item->onTake(this);
	remove();
}

