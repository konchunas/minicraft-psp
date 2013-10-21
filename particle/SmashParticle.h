#ifndef SMASHPARTICLE_H_
#define SMASHPARTICLE_H_

#include "Particle.h"

#include "Screen.h"

class SmashParticle : public Particle
{
public:
	SmashParticle(int x, int y);
	virtual ~SmashParticle();
	void tick();
	void render(Screen * screen);

private:
	int time;
};

#endif /* SMASHPARTICLE_H_ */
