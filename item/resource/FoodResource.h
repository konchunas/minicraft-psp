#ifndef FOODRESOURCE_H_
#define FOODRESOURCE_H_

#include "../../level/tile/Tile.h"
#include "../../level/Level.h"
#include "../../entity/Player.h"
#include "Resource.h"

class FoodResource : public Resource{
public:
	FoodResource(string name, int sprite, int color, int heal, int staminaCost);
	virtual ~FoodResource();

	bool interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir);

private:
	int heal;
	int staminaCost;
};

#endif /* FOODRESOURCE_H_ */
