#ifndef SLIME_H_
#define SLIME_H_

#include "Mob.h"

class Slime : public Mob {
public:
	Slime(int lvl);
	virtual ~Slime();

	void render(Screen * screen);
	void tick();


private:
	int xa, ya;
	int jumpTime;
	int lvl;

protected:
	void touchedBy(Entity * entity);
	void die();
};

#endif /* SLIME_H_ */
