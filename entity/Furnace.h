#ifndef FURNACE_H_
#define FURNACE_H_

#include "Furniture.h"

class Player;

class Furnace : public Furniture {
public:
	Furnace();
	virtual ~Furnace();
	bool use(Player * player, int attackDir);
};

#endif /* FURNACE_H_ */
