#ifndef LANTERN_H_
#define LANTERN_H_

#include "Furniture.h"

class Lantern : public Furniture
{
public:
	Lantern();
	virtual ~Lantern();

	int getLightRadius();
};

#endif /* LANTERN_H_ */
