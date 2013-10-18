#ifndef RESOURCEITEM_H_
#define RESOURCEITEM_H_

#include "Item.h"
#include "../entity/ItemEntity.h"
#include "../level/Level.h"
#include "../level/tile/Tile.h"
#include "../screen.h"
#include "../Screen.h"
#include "resource/Resource.h"

class Player;

class ResourceItem : public Item {
public:
	ResourceItem(Resource * resource);
	ResourceItem(Resource * resource, int count);
	virtual ~ResourceItem();
	Resource * resource;
	int count;

	int getColor();
	int getSprite();
	void renderIcon(Screen * screen, int x, int y);
	void renderInventory(Screen * screen, int x, int y);
	string getName();
	void onTake(ItemEntity * itemEntity);
	bool interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir);
	bool isDepleted();
	Type type();

};

#endif /* RESOURCEITEM_H_ */
