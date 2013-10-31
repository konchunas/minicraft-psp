#ifndef AIRWIZARD_H_
#define AIRWIZARD_H_

class AirWizard : public Mob {
public:
	AirWizard();
	virtual ~AirWizard();
	void tick();
	void doHurt(int damage, int attackDir);
	void render(Screen * screen);

private:
	int xa, ya;
	int randomWalkTime;
	int attackDelay;
	int attackTime;
	int attackType;

protected:
	void die();
	void touchedBy(Entity * entity);
};

#endif /* AIRWIZARD_H_ */
