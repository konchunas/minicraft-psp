/*
 * Invertory.cpp
 *
 *  Created on: 18 окт. 2013 г.
 *      Author: user
 */

#include "Inventory.h"

#include "../item/resource/Resource.h"
#include "../item/Item.h"

Inventory::Inventory() {
	// TODO Auto-generated constructor stub

}

Inventory::~Inventory() {
	// TODO Auto-generated destructor stub
}

void Inventory::add(Item * item)
{
	add(items.size(), item);
}

void Inventory::add(int slot, Item * item)
{
	deque<Item*>::iterator slotIterator = items.begin() + slot;
	if (item->instanceOf(RESOURCE_ITEM))
	{
		ResourceItem * toTake = (ResourceItem*)item;
		ResourceItem * has = findResource(toTake->resource);
		if (has == NULL)
		{
			items.insert(slotIterator, toTake);
		}
		else
		{
			has->count += toTake->count;
		}
	}
	else
	{
		items.insert(slotIterator, item);
	}
}

ResourceItem * Inventory::findResource(Resource * resource)
{
	for (deque<Item*>::iterator it = items.begin(); it != items.end(); it++ )
	{
		Item * item = *it;
		if (item->instanceOf(RESOURCE_ITEM))
		{
			ResourceItem * has = static_cast<ResourceItem*>(item);
			if (has->resource == resource) return has;
		}
	}
	return NULL;
}

bool Inventory::hasResources(Resource * r, int count)
{
	ResourceItem * ri = findResource(r);
	if (ri == NULL) return false;
	return ri->count >= count;
}

bool Inventory::removeResource(Resource * r, int count)
{
	ResourceItem * ri = findResource(r);
	if (ri == NULL) return false;
	if (ri->count < count) return false;
	ri->count -= count;
	if (ri->count <= 0)
	{
		remove(ri);
	}
	return true;
}

void Inventory::remove(Item * item)
{
	for (deque<Item*>::iterator it = items.begin(); it != items.end(); it++ )
	{
		if (*it == item)
			items.erase(it);
	}
}

Item* Inventory::removeAt(int index)
{
	deque<Item*>::iterator it = items.begin() + index;
	Item * item = *it;
	items.erase(it);
	return item;
}

int Inventory::count(Item * item)
{
	if (item->instanceOf(RESOURCE_ITEM))
	{
		ResourceItem * ri = findResource(static_cast<ResourceItem*>(item)->resource);
		if (ri != NULL) return ri->count;
	}
	else
	{
		int count = 0;
		for (int i=0; i<items.size(); i++) //replace with std::iterating
		{
			if (items.at(i)->matches(item)) count++;
		}
		return count;
	}
	return 0;
}


