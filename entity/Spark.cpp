#include <list>
#include <memory>

#include "../Color.h"
#include "../Screen.h"
#include "../level/Level.h"
#include "Mob.h"
#include "AirWizard.h"
#include "Spark.h"



using namespace std;

Spark::~Spark() {
	// TODO Auto-generated destructor stub
}

Spark::Spark(AirWizard * owner, double xa, double ya):
time(0)
{
	this->owner = owner;
	xx = this->x = owner->x;
	yy = this->y = owner->y;
	xr = 0;
	yr = 0;

	this->xa = xa;
	this->ya = ya;

	lifeTime = 60 * 10 + random->nextInt(30);
}

void Spark::tick()
{
	time++;
	if (time >= lifeTime) {
		remove();
		return;
	}
	xx += xa;
	yy += ya;
	x = (int) xx;
	y = (int) yy;
	auto_ptr<list<Entity*> > toHit(level->getEntities(x, y, x, y));
	for (list<Entity*>::iterator it = toHit->begin(); it != toHit->end(); it++ )
	{
		Entity * e = *it;
		if ((e->instanceOf(MOB) || e->instanceOf(PLAYER)) && !(e->instanceOf(AIR_WIZARD))) {
			e->hurt(owner, 1, ((Mob*) e)->dir ^ 1);
		}
	}
}

bool Spark::isBlockableBy(Mob * mob)
{
	return false;
}



void Spark::render(Screen * screen)
{
	if (time >= lifeTime - 6 * 20) {
		if (time / 6 % 2 == 0) return;
	}

//	int xt = 8;
//	int yt = 13;

	//screen->renderSpark(x - 4, y - 4);
	screen->render(x - 4, y - 4 - 2, 8 + 13 * 32, Color::get(-1, 555, 555, 555), random->nextInt(4));
	screen->render(x - 4, y - 4 + 2, 8 + 13 * 32, Color::get(-1, 000, 000, 000), random->nextInt(4));
}

