#ifndef CHEST_H_
#define CHEST_H_

#include "Furniture.h"

class Player;
class Inventory;

class Chest : public Furniture
{
public:
	Chest();
	virtual ~Chest();
	Inventory * inventory;

	bool use(Player * player, int attackDir);
};

#endif /* CHEST_H_ */
