#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <deque>

class Item;
class Resource;

#include "../item/ResourceItem.h"


//using namespace std;

class Inventory {
public:
	Inventory();
	virtual ~Inventory();
	deque<Item *> items;

	void add(Item * item);
	void add(int slot, Item * item);
	bool hasResources(Resource * r, int count);
	bool removeResource(Resource * r, int count);
	void remove(Item * item);
	Item * removeAt(int index);
	int count(Item * item);


private:
	ResourceItem* findResource(Resource* resource);

};

#endif /* INVENTORY_H_ */
