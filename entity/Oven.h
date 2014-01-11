#ifndef OVEN_H_
#define OVEN_H_

#include "Furniture.h"

class Player;

class Oven : public Furniture
{
public:
	Oven();
	virtual ~Oven();
	bool use(Player * player, int attackDir);
};

#endif /* OVEN_H_ */
