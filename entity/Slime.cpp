#include "../Color.h"
#include "../Screen.h"
#include "../item/ResourceItem.h"
#include "../item/resource/Resource.h"
#include "Player.h"

#include "Slime.h"

Slime::~Slime() {
	// TODO Auto-generated destructor stub
}

Slime::Slime(int lvl):
xa(0),ya(0),jumpTime(0)
{
	this->lvl = lvl;
	x = random->nextInt(64 * 16);
	y = random->nextInt(64 * 16);
	health = maxHealth = lvl * lvl * 5;
}

void Slime::tick()
{
	Mob::tick();

	int speed = 1;
	//if chance of moving is 1 of 40 as it was in java version, slimes would be standing still all the time
	if (!move(xa * speed, ya * speed) || random->nextInt(40) == 0)
	{
		if (jumpTime <= -10) {
			xa = (random->nextInt(3) - 1);
			ya = (random->nextInt(3) - 1);

			if (level->player != NULL) {
				int xd = level->player->x - x;
				int yd = level->player->y - y;
				if (xd * xd + yd * yd < 50 * 50) {
					if (xd < 0) xa = -1;
					if (xd > 0) xa = +1;
					if (yd < 0) ya = -1;
					if (yd > 0) ya = +1;
				}

			}

			if (xa != 0 || ya != 0) jumpTime = 10;
		}
	}

	jumpTime--;
	if (jumpTime == 0) {
		xa = ya = 0;
	}
}

void Slime::die()
{
	Mob::die();

	int count = random->nextInt(2) + 1;
	for (int i = 0; i < count; i++) {
		level->add(new ItemEntity(new ResourceItem(Resource::slime), x + random->nextInt(11) - 5, y + random->nextInt(11) - 5));
	}

	if (level->player != NULL) {
		level->player->score += 25*lvl;
	}

}

void Slime::render(Screen * screen)
{
	int xt = 0;
	int yt = 18;

	int xo = x - 8;
	int yo = y - 11;

	if (jumpTime > 0) {
		xt += 2;
		yo -= 4;
	}

	int col = Color::get(-1, 10, 252, 555);
	if (lvl == 2) col = Color::get(-1, 100, 522, 555);
	if (lvl == 3) col = Color::get(-1, 111, 444, 555);
	if (lvl == 4) col = Color::get(-1, 000, 111, 224);

	if (hurtTime > 0) {
		col = Color::get(-1, 555, 555, 555);
	}

	screen->render(xo + 0, yo + 0, xt + yt * 32, col, 0);
	screen->render(xo + 8, yo + 0, xt + 1 + yt * 32, col, 0);
	screen->render(xo + 0, yo + 8, xt + (yt + 1) * 32, col, 0);
	screen->render(xo + 8, yo + 8, xt + 1 + (yt + 1) * 32, col, 0);
}

void Slime::touchedBy(Entity * entity)
{
	if (entity->instanceOf(PLAYER))
	{
		entity->hurt(this, lvl, dir);
	}
}

