#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "../entity/Entity.h"
#include "../Screen.h"

class Particle : public Entity {
public:
	Particle() {};
	virtual ~Particle() {};
	virtual void tick() {};
	virtual void render(Screen * screen) {};

};

#endif /* PARTICLE_H_ */
