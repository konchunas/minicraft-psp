#ifndef ITEM_H_
#define ITEM_H_

#include "../menu/ListItem.h"
#include "../Typeable.h"
#include <string>

class Screen;
class Player;
class Tile;
class Level;
class Entity;
class ItemEntity;

using namespace std;

class Item : public ListItem, public Typeable {
public:
	virtual int getColor();
	virtual int getSprite();
	virtual void onTake(ItemEntity * itemEntity);
	virtual void renderInventory(Screen * screen, int x, int y);
	virtual bool interact(Player * player, Entity * entity, int attackDir);
	virtual void renderIcon(Screen * screen, int x, int y);
	virtual bool interactOn(Tile * tile, Level * level, int xt, int yt, Player * player, int attackDir);
	virtual bool isDepleted();
	virtual bool canAttack();
	virtual int getAttackDamageBonus(Entity * e);
	virtual string getName();
	virtual bool matches(Item * item);
};

#endif /* ITEM_H_ */
