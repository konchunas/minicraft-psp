#ifndef STAIRSTILE_H_
#define STAIRSTILE_H_

#include "Tile.h"

class Level;
class Entity;
class Screen;

class StairsTile : public Tile {
public:
	StairsTile(int id, bool leadsUp);
	virtual ~StairsTile();
	void render(Screen * screen, Level * level, int x, int y);
private:
	bool leadsUp;
};

#endif /* STAIRSTILE_H_ */
