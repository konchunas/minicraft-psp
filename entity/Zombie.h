#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include "Mob.h"

class Zombie : public Mob {
public:
	Zombie(int lvl);
	virtual ~Zombie();

	void tick();
	void render(Screen * screen);

private:
	int xa, ya;
	int lvl;
	int randomWalkTime;

protected:
	void die();
	void touchedBy(Entity * entity);

};

#endif /* ZOMBIE_H_ */
