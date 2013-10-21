#ifndef TEXTPARTICLE_H_
#define TEXTPARTICLE_H_

#include <string>

#include "Screen.h"
#include "../particle/Particle.h"

using namespace std;

class TextParticle : public Particle {
public:
	TextParticle(string msg, int x, int y, int col);
	TextParticle(int num, int x, int y, int col);
	void init(string msg, int x, int y, int col);
	virtual ~TextParticle();

	double xa, ya, za;
	double xx, yy, zz;

	void tick();
	void render(Screen * screen);

private:
	string msg;
	int col;
	int time;
};

#endif /* TEXTPARTICLE_H_ */
