/*
 * Furniture.h
 *
 *  Created on: 19 окт. 2013 г.
 *      Author: user
 */

#ifndef FURNITURE_H_
#define FURNITURE_H_

#include <string>

#include "Entity.h"

class Screen;
class Player;

using namespace std;

class Furniture : public Entity {
public:
	Furniture(string name);
	virtual ~Furniture();

	int col, sprite;
	string name;

	virtual void tick();
	virtual void render(Screen * screen);
	virtual bool blocks(Entity * e);
	virtual void take(Player * player);

private:
	int pushTime;
	int pushDir;
	Player * shouldTake;

protected:
	virtual void touchedBy(Entity * entity);

};

#endif /* FURNITURE_H_ */
