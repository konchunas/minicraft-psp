/*
 * Invertory.cpp
 *
 *  Created on: 18 ���. 2013 �.
 *      Author: user
 */

#include "Inventory.h"

#include "../item/resource/Resource.h"
#include "../item/Item.h"

#include "../item/FurnitureItem.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{
	for (deque<Item*>::iterator it = items.begin(); it != items.end(); it++ )
	{
		delete *it;
	}
}

void Inventory::add(Item * item)
{
	add(items.size(), item);
}

void Inventory::add(int slot, Item * item)
{
	if (item->instanceOf(RESOURCE_ITEM))
	{
		ResourceItem * toTake = (ResourceItem*)item;
		ResourceItem * has = findResource(toTake->resource);
		if (has)
		{
			has->count += toTake->count;
			return;
		}
	}

	if (slot == 0)
	{
		items.push_front(item);
	}
	else
	{
		deque<Item*>::iterator slotIterator = items.begin() + slot;
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
		{
			items.erase(it);
			return;
		}
	}
}

Item* Inventory::removeAt(int index)
{
	deque<Item*>::iterator it = items.begin() + index;
	Item * item = *it;	//remember item beforehand
	items.erase(it);	//remove item from list
	return item;		//return item
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
		for (unsigned int i=0; i<items.size(); ++i) //replace with std::iterating
		{
			//count items by matching name item is furniture
			if (item->instanceOf(FURNITURE_ITEM))
			{
				if (items.at(i)->instanceOf(FURNITURE_ITEM))
				{
					FurnitureItem * inventoryItem = static_cast<FurnitureItem*>(items.at(i));
					FurnitureItem * currentItem = static_cast<FurnitureItem*>(item);
					if (inventoryItem->getName() == currentItem->getName())
						count++;
				}
			}
			else //count by type matching
			{
				if (items.at(i)->matches(item)) count++;
			}
		}
		return count;
	}
	return 0;
}


