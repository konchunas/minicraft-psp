#ifndef MOB_H_
#define MOB_H_

#include "Entity.h"

class Mob : public Entity {
public:
	Mob();
	virtual ~Mob();
	int hurtTime;
	int maxHealth;
	int health;
	int swimTimer;
	int tickTime;

	virtual void tick();
	virtual bool move(int xa, int ya);
	virtual bool blocks(Entity * e);
	virtual void hurt(Mob * mob, int damage, int attackDir);
	virtual void hurt(Tile * tile, int x, int y, int damage);
	virtual void heal(int heal);

protected:
	int walkDist;
	int dir;
	int xKnockback, yKnockback;

	virtual void die();
	virtual bool isSwimming();
	virtual void doHurt(int damage, int attackDir);
	virtual bool findStartPos(Level * level);
};

#endif /* MOB_H_ */
