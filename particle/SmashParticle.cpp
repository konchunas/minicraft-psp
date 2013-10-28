#include "SmashParticle.h"

#include "../Color.h"
#include "../Sound.h"

SmashParticle::~SmashParticle()
{

}

SmashParticle::SmashParticle(int x, int y)
{
	this->x = x;
	this->y = y;
	time = 0;
	Sound::monsterHurt->play();
}

void SmashParticle::tick() {
	time++;
	if (time > 10)
	{
		remove();
	}
}

void SmashParticle::render(Screen * screen)
{
	int col = Color::get(-1, 555, 555, 555);
	screen->render(x - 8, y - 8, 5 + 12 * 32, col, 2);
	screen->render(x - 0, y - 8, 5 + 12 * 32, col, 3);
	screen->render(x - 8, y - 0, 5 + 12 * 32, col, 0);
	screen->render(x - 0, y - 0, 5 + 12 * 32, col, 1);
}
