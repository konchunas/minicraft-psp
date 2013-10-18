/*
 * GrassTile.h
 *
 *  Created on: 16 окт. 2013 г.
 *      Author: user
 */

#ifndef GRASSTILE_H_
#define GRASSTILE_H_

#include "Tile.h"

class GrassTile : public Tile {
public:
	GrassTile(int id);
	virtual ~GrassTile();
	virtual void render(Screen * screen, Level * level, int x, int y);
	void tick(Level * level, int xt, int yt);
	bool interact(Level * level, int xt, int yt, Player * player, Item * item, int attackDir);
};

#endif /* GRASSTILE_H_ */
