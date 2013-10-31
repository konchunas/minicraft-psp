#ifndef SPARK_H_
#define SPARK_H_

#include "Entity.h"

class Screen;
class Mob;
class AirWizard;

class Spark : public Entity
{
public:
	Spark(AirWizard * owner, double xa, double ya);
	virtual ~Spark();

	void tick();
	bool isBlockableBy(Mob * mob);
	void render(Screen * screen);

	double xa, ya;
	double xx, yy;

private:
	int lifeTime;
	int time;
	AirWizard * owner;
};

#endif /* SPARK_H_ */
