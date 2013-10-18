#ifndef WORKBENCH_H_
#define WORKBENCH_H_

#include "Furniture.h"

class Player;

class Workbench : public Furniture {
public:
	Workbench();
	virtual ~Workbench();
	bool use(Player * player, int attackDir);
};

#endif /* WORKBENCH_H_ */
